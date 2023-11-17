#ifndef CRRS_INCLUDE_IDENTITY_TEACHER_HPP_
#define CRRS_INCLUDE_IDENTITY_TEACHER_HPP_

#include "../HashmapVar.cpp"
#include "../fileNameDefine.h"
#include "../pause.cpp"
#include "../reinput.cpp"
#include <fstream>
#include <iostream>
#include <string>

namespace crrs::identity {
class teacher {
public:
    teacher() = delete;
    teacher(const unsigned long long &id, const std::string &name,
            const std::string &password) noexcept
        : m_name(name)
        , m_password(password)
        , m_id(id) {}
    teacher(teacher &&)                 = delete;
    teacher(const teacher &)            = delete;
    teacher &operator=(teacher &&)      = delete;
    teacher &operator=(const teacher &) = delete;
    ~teacher()                          = default;

    void oper_menu() {
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
                case 1:  showAllOrder(); break;
                case 2:  vaildOrder(); break;
                case 0:  return; break;
                default: goto InvalidInput; break;
            }
        }
    }

    void showAllOrder() {
        for (const auto &[unused_var_, order] : crrs::orderMap) {
            std::cout << "预约日期: "
                      << (order.day == 1   ? "周一"
                          : order.day == 2 ? "周二"
                          : order.day == 3 ? "周三"
                          : order.day == 4 ? "周四"
                                           : "周五")
                      << "\t时段: " << (order.intervak == 1 ? "上午" : "下午")
                      << "\t学号: " << order.studentID
                      << "\t姓名: " << order.studentName
                      << "\t机房: " << order.roomID << "号\t状态: "
                      << (order.status == 1   ? "审核中"
                          : order.status == 2 ? "预约成功"
                          : order.status == -1 ? "预约失败，审核不通过"
                                               : "UNKNOWN")
                      << '\n';
        }
#ifndef _WIN32
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
        crrs::pause_and_clear();
    }

    void vaildOrder() {
        unsigned long long                                  count = 0;
        std::unordered_map<unsigned long long, std::string> uuidMap;
        for (const auto &[uuid, order] : crrs::orderMap) {
            if (order.status == 1) {
                uuidMap.emplace(++count, uuid);
                std::cout << count << ". "
                          << "预约日期: "
                          << (order.day == 1   ? "周一"
                              : order.day == 2 ? "周二"
                              : order.day == 3 ? "周三"
                              : order.day == 4 ? "周四"
                                               : "周五")
                          << "\t时段: "
                          << (order.intervak == 1 ? "上午" : "下午")
                          << "\t机房: " << order.roomID << "号\t状态: "
                          << (order.status == 1 ? "审核中" : "预约成功")
                          << '\n';
            }
        }
        short userSelect;
        while (true) {
            std::cout << "请选择要审核的记录，0代表返回:";
            std::cin >> userSelect;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
            } else if (userSelect >= 0 && userSelect <= count) {
                break;
            }
            std::cout << "输入有误,请重新输入!\n";
        }
        if (userSelect == 0) return;
        std::cout << "1.通过\n"
                     "2.不通过\n"
                     "请输入审核结果:";
        short userSelect0;
        while (true) {
            std::cin >> userSelect0;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
            } else if (userSelect0 == 1 || userSelect0 == 2) {
                crrs::orderMap[uuidMap[userSelect]].status =
                    userSelect0 == 1 ? 2 : -1;
                break;
            }
            std::cout << "输入有误,请重新输入:";
        }
        std::ofstream fout(ORDER_FILENAME);
        for (auto &[uuid, order] : crrs::orderMap) {
            fout << '\n'
                 << uuid << ' ' << order.day << ' ' << order.intervak << ' '
                 << order.studentID << ' ' << order.studentName << ' '
                 << order.roomID << ' ' << order.status;
        }
        std::cout << "审核完成!\n";
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
                     "│      1.查看所有预约      │\n"
                     "│                          │\n"
                     "│      2.审 核  预 约      │\n"
                     "│                          │\n"
                     "│      0.退 出  登 录      │\n"
                     "│                          │\n"
                     "╰──────────────────────────╯\n";
    }

    std::string        m_name, m_password;
    unsigned long long m_id;
};
} // namespace crrs::identity

#endif
