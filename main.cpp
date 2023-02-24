#include "DoublyLinkedList.h"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"

#include <array>




using namespace ftxui;
int main() {
    auto screen = ScreenInteractive::Fullscreen();

    psv::DoublyLinkedList<int> list_ints;
    psv::DoublyLinkedList<float> list_floats;
    psv::DoublyLinkedList<std::string> list_strings;

    // type select
    std::vector<std::string> types = {"int", "float", "string"};
    int selected_type = 0;
    Component select_type = Radiobox(&types, &selected_type);

    // action select
    std::vector<std::string> actions = {"append", "prepend", "delete"};
    int selected_action = 0;
    Component select_action = Radiobox(&actions, &selected_action);


    // additional settings
    std::vector<std::string> setting_labels = {"Random", "Input"};
    int user_input = 0;
    Component options = Container::Vertical({
            Radiobox(&setting_labels, &user_input),
    });

    // value input
    std::string input_value;
    auto input_option = InputOption();
    Component input = Input(&input_value, "Enter value", &input_option);

    auto append = Button("Append", [&]{
        switch (selected_type) {
            case 0:
                if (user_input)
                    list_ints.append(std::stoi(input_value));
                else
                    list_ints.append(rand() % 100);
                break;
            case 1:
                if (user_input)
                    list_floats.append(std::stof(input_value));
                else
                    list_floats.append(rand() % 100);
                break;
            case 2:
                if (user_input)
                    list_strings.append(input_value);
                else
                    list_strings.append("random");
                break;
        }
    });
    auto prepend = Button("Prepend", [&]{
        switch (selected_type) {
            case 0:
                if (user_input)
                    list_ints.prepend(std::stoi(input_value));
                else
                    list_ints.prepend(rand() % 100);
                break;
            case 1:
                if (user_input)
                    list_floats.prepend(std::stof(input_value));
                else
                    list_floats.prepend(rand() % 100);
                break;
            case 2:
                if (user_input)
                    list_strings.prepend(input_value);
                else
                    list_strings.prepend("random");
                break;
        }
    });
    auto remove = Button("Remove", [&]{
        switch (selected_type) {
            case 0:
                if (user_input)
                    list_ints.remove(std::stoi(input_value));
                else
                    list_ints.remove(rand() % 100);
                break;
            case 1:
                if (user_input)
                    list_floats.remove(std::stof(input_value));
                else
                    list_floats.remove(rand() % 100);
                break;
            case 2:
                if (user_input)
                    list_strings.remove(input_value);
                else
                    list_strings.remove("random");
                break;
        }
    });
    auto clear = Button("Clear", [&]{
        switch (selected_type) {
            case 0:
                list_ints = psv::DoublyLinkedList<int>();
                break;
            case 1:
                list_floats = psv::DoublyLinkedList<float>();
                break;
            case 2:
                list_strings = psv::DoublyLinkedList<std::string>();
                break;
        }
    });

    Component buttons = Container::Horizontal({
                                               append,
                                               prepend,
                                               remove,
                                                  clear
                                       });
    auto list_utils = Container::Horizontal({
            select_type,
            select_action,
            options,
            input,
            buttons
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
        auto type_window = window(text("List Type"), select_type->Render());
        auto action_window = window(text("Action"), select_action->Render());
        auto options_window = window(text("Data Source"), options->Render());
        auto input_window = window(text("Input"),hbox({
            text("Value: "),
            input->Render()
        }));
        auto button_window = window(text("Actions"), buttons->Render());


        Element tools;
        if(user_input){
            tools = hbox({
                         type_window,
                         action_window,
                         options_window,
                         input_window,
                         button_window,
                 }) | center;
        }else{
            tools = hbox({
                     type_window,
                     action_window,
                     options_window,
                     button_window,
             }) | center;
        }

        FlexboxConfig configuration;
        configuration.align_content = FlexboxConfig::AlignContent::SpaceAround;
        configuration.justify_content = FlexboxConfig::JustifyContent::SpaceAround;
        configuration.direction = FlexboxConfig::Direction::Column;
        auto content = flexbox(
                {
                    hflow(render_list()),
                    vbox({
                         tools,
                         hflow(text("by Peter V."))
                    }),
                }, configuration) | borderDouble;

        return content;

       // Pre-Flexbox layout
//        return vbox({
//            hflow(render_list()) | center | flex_grow
//            ,
//            tools,
//
//        }) | flex_shrink | borderHeavy;
    });


    screen.Loop(main_renderer);

    return 0;
};
