#ifndef CRRS_INCLUDE_IDENTITY_ADMINISTRATOR_HPP_
#define CRRS_INCLUDE_IDENTITY_ADMINISTRATOR_HPP_

#include "../HashmapVar.cpp"
#include "../fileNameDefine.h"
#include "../pause.cpp"
#include "../reinput.cpp"
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>
#include <unordered_map>

namespace crrs::identity {
class administrator {
public:
    administrator() = delete;
    administrator(const std::string &name, const std::string &password) noexcept
        : m_name(name), m_password(password) {}
    administrator(administrator &&)                 = delete;
    administrator(const administrator &)            = delete;
    administrator &operator=(administrator &&)      = delete;
    administrator &operator=(const administrator &) = delete;
    ~administrator()                                = default;

    void operMenu() {
        short userSelect;
        while (true) {
            ShowMenu();
        ResetInput:
            std::cout << "\n请选择:";
            std::cin >> userSelect;
            if (!std::cin) {
            InvalidInput:
                crrs::reinput();
                goto ResetInput;
            }
            switch (userSelect) {
                case 1:  addUser(); break;
                case 2:  showUsers(); break;
                case 3:  showComputerRooms(); break;
                case 4:  cleanOrders(); break;
                case 0:  return; break;
                default: goto InvalidInput; break;
            }
        }
    }

    static void addUser() {
        short userSelect;
        std::cout << "1.学生\n2.教师\n3.管理员\n0.返回";
        while (true) {
            std::cout << "\n请选择添加的账号类型:";
            std::cin >> userSelect;
            if (std::cin && (userSelect == 0 || userSelect == 1 ||
                             userSelect == 2 || userSelect == 3)) {
                break;
            }
            std::cerr << "ERROR: 无效，请重新选择\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        const char *FILENAME, *TIP_TEXT, *ERROR_TIP;
        std::unordered_map<unsigned long long,
                           std::pair<std::string, std::string>> *hashmap;
        if (userSelect == 1) {
            FILENAME  = STUDENT_USER_FILENAME;
            TIP_TEXT  = "请输入学号:";
            ERROR_TIP = "ERROR: 学号已存在\n";
            hashmap   = &studentMap;
        } else if (userSelect == 2) {
            FILENAME  = TEACHER_USER_FILENAME;
            TIP_TEXT  = "请输入工号:";
            ERROR_TIP = "ERROR: 工号已存在\n";
            hashmap   = &teacherMap;
        } else if (userSelect == 3) {
            std::string name, password;
            while (std::cin.get() != '\n') {}
            while (true) {
                std::cout << "请输入名称:";
                std::getline(std::cin, name);
                if (name.find(' ') != std::string::npos) {
                    std::cerr << "ERROR: 名称中不能包含空格\n";
                } else if (crrs::administratorMap.count(name)) {
                    std::cerr << "ERROR: 名称已存在\n";
                } else {
                    break;
                }
            }
            while (true) {
                std::cout << "请输入密码:";
                std::getline(std::cin, password);
                if (password.find(' ') == std::string::npos) {
                    break;
                }
                std::cerr << "ERROR: 密码中不能包含空格\n";
            }
            (std::ofstream(ADMIN_USER_FILENAME, std::ios::app)
             << '\n'
             << name << ' ' << password)
                .close();
            crrs::administratorMap.emplace(name, password);
            std::cout << "添加成功\n";
            crrs::pause_and_clear();
            return;
        } else {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            return;
        }
        unsigned long long id;
        std::string        name, password;
        while (true) {
            std::cout << TIP_TEXT;
            std::cin >> id;
            if (!std::cin) {
                std::cerr << "ERROR: 无效输入\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
            } else if (hashmap->count(id)) {
                std::cerr << ERROR_TIP;
            } else {
                break;
            }
        }
        while (std::cin.get() != '\n') {}
        while (true) {
            std::cout << "请输入名称:";
            std::getline(std::cin, name);
            if (name.find(' ') == std::string::npos) {
                break;
            }
            std::cerr << "ERROR: 名称中不能包含空格\n";
        }
        while (true) {
            std::cout << "请输入密码:";
            std::getline(std::cin, password);
            if (password.find(' ') == std::string::npos) {
                break;
            }
            std::cerr << "ERROR: 密码中不能包含空格\n";
        }
        (std::ofstream(FILENAME, std::ios::app)
         << '\n'
         << id << ' ' << name << ' ' << password)
            .close();
        hashmap->emplace(id, std::pair{name, password});
        std::cout << "添加成功\n";
        crrs::pause_and_clear();
    }

    static void showUsers() {
        short userSelect;
        std::cout
            << "1.学生\n2.教师\n3.管理员\n0.返回\n你要查看哪种类型的账号:";
        std::cin >> userSelect;
        while (true) {
            if (std::cin && (userSelect == 0 || userSelect == 1 ||
                             userSelect == 2 || userSelect == 3)) {
                break;
            }
            std::cerr << "ERROR: 无效输入\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        }
        if (userSelect == 1) {
            for (const auto &[id, user] : studentMap) {
                std::cout << "学号: " << id << "\t姓名: " << user.first
                          << "\t密码: " << user.second << '\n';
            }
        } else if (userSelect == 2) {
            for (const auto &[id, user] : teacherMap) {
                std::cout << "工号: " << id << "\t姓名: " << user.first
                          << "\t密码: " << user.second << '\n';
            }
        } else if (userSelect == 3) {
            for (const auto &p : administratorMap) {
                std::cout << "管理员: " << p.first << "\t密码: " << p.second
                          << '\n';
            }
        } else {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
        }
#ifndef _WIN32
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
        crrs::pause_and_clear();
    }

    static void showComputerRooms() {
        std::cout << "机房信息如下:\n";
        for (const auto &[id, capacity] : computerRoomMap) {
            if (capacity == 0) {
                std::cout << "机房编号: " << id << "\t机房已满\n";
            }
            std::cout << "机房编号: " << id << "\t机房容量: " << capacity
                      << '\n';
        }
#ifndef _WIN32
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
        crrs::pause_and_clear();
    }

    static void cleanOrders() {
        std::ofstream(ORDER_FILENAME, std::ios::trunc).close();
        // TODO:
        std::cout << "清空成功\n";
#ifndef _WIN32
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
        crrs::pause_and_clear();
    }

private:
    void ShowMenu() const {
        std::cout << m_name
                  << " 欢迎登录！\n"
                     "╭──────────────────────────╮\n"
                     "│                          │\n"
                     "│        1.添加账号        │\n"
                     "│                          │\n"
                     "│        2.查看账号        │\n"
                     "│                          │\n"
                     "│        3.查看机房        │\n"
                     "│                          │\n"
                     "│        4.清空预约        │\n"
                     "│                          │\n"
                     "│        0.退出登录        │\n"
                     "│                          │\n"
                     "╰──────────────────────────╯\n";
    }

    std::string m_name;
    std::string m_password;
};
} // namespace crrs::identity

#endif
