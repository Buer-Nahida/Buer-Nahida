#ifndef CRRS_INCLUDE_MENU_CPP_
#define CRRS_INCLUDE_MENU_CPP_

#include <cstring>
#include <iostream>

namespace crrs {
static void show_menu() {
    std::cout << "╭──────────────────────────╮\n"
                 "│                          │\n"
                 "│         1.学  生         │\n"
                 "│                          │\n"
                 "│         2.老  师         │\n"
                 "│                          │\n"
                 "│         3.管理员         │\n"
                 "│                          │\n"
                 "│         0.退  出         │\n"
                 "│                          │\n"
                 "╰──────────────────────────╯\n";
}
} // namespace crrs

#endif
