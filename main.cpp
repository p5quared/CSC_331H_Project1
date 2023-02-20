#include "DoublyLinkedList.h"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

#include <array>

#include <iostream>



using namespace ftxui;
int main() {
    auto screen = ScreenInteractive::Fullscreen();

    psv::DoublyLinkedList<int> list_ints;
    psv::DoublyLinkedList<float> list_floats;
    psv::DoublyLinkedList<std::string> list_strings;

    // type setting
    std::vector<std::string> types = {"int", "float", "string"};
    int selected_type = 0;
    Component select_type = Radiobox(&types, &selected_type);

    // action setting
    std::vector<std::string> actions = {"append", "prepend"};
    int selected_action = 0;
    Component select_action = Radiobox(&actions, &selected_action);

    // random setting
    std::string random_label = "Random";
    bool random_state = false;
    Component options = Container::Vertical({
            Checkbox(&random_label, &random_state),
    });

    // value input
    std::string input_value;
    auto input_option = InputOption();
    input_option.on_enter = [&]() {
        // TODO: Think of a more elegant approach...
        // given we aren't even handling prepend or delete yet... yikes
        switch (selected_type) {
            case 0:
                if (random_state)
                    list_ints.append(rand() % 100);
                else
                    list_ints.append(std::stoi(input_value));
                break;
            case 1:
                if (random_state)
                    list_floats.append(rand() % 100);
                else
                    list_floats.append(std::stof(input_value));
                break;
            case 2:
                if (random_state)
                    // TODO: random words
                    list_strings.append("random");
                else
                    list_strings.append(input_value);
                break;
            default:
                // TODO: Handle? or not
                throw(std::runtime_error("Invalid type selected"));
                break;
        }
    };
    Component input = Input(&input_value, "Enter value", &input_option);

    auto list_utils = Container::Vertical({
            select_type,
            select_action,
            options,
            input,
    });

    auto render_list = [&] {
        Elements line;

        line.push_back(text("["));
        switch (selected_type) {
            case 0:
                for (auto i: list_ints) {
                    line.push_back(text(std::to_string(i)));
                    line.push_back(text(", "));
                }
                break;
            case 1:
                for (auto i: list_floats) {
                    line.push_back(text(std::to_string(i)));
                    line.push_back(text(", "));
                }
                break;
            case 2:
                for (auto i: list_strings) {
                    line.push_back(text(i));
                    line.push_back(text(", "));
                }
                break;
        }
        if (line.size() > 1){
            line.pop_back();
        }
        line.push_back(text("]"));
        return line;
    };


    auto main_renderer = Renderer(list_utils, [&] {
        auto tool_window = window(text("Tools"), list_utils->Render());

        return hbox({
            tool_window,
            vbox(
                    hflow(render_list()) | center | flex
                    ) | flex,
        }) | border ;
    });


    screen.Loop(main_renderer);
    // need delete button

    return 0;
};
