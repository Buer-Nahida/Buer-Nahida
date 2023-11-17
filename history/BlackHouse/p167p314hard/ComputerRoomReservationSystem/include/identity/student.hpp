#ifndef CRRS_INCLUDE_IDENTITY_STUDENT_HPP_
#define CRRS_INCLUDE_IDENTITY_STUDENT_HPP_
#include <unordered_map>
#define unused_var_ unused_var_

#include "../HashmapVar.cpp"
#include "../fileNameDefine.h"
#include "../pause.cpp"
#include "../reinput.cpp"
#include <climits>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <uuid/uuid.h>

namespace crrs::identity {
class student {
public:
    student() = delete;
    student(const unsigned long long &id, const std::string &name,
            const std::string &password) noexcept
        : m_password(password)
        , m_name(name)
        , m_id(id) {}
    student(student &&)                 = delete;
    student(const student &)            = delete;
    student &operator=(student &&)      = delete;
    student &operator=(const student &) = delete;
    ~student()                          = default;

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
                case 1:  applyOrder(); break;
                case 2:  showMyOrder(); break;
                case 3:  showAllOrder(); break;
                case 4:  cancelOrder(); break;
                case 0:  return; break;
                default: goto InvalidInput; break;
            }
        }
    }

    void applyOrder() {
        short day;
        std::cout << "1.周一\n"
                     "2.周二\n"
                     "3.周三\n"
                     "4.周四\n"
                     "5.周五\n"
                     "请输入申请预约的时间:";
        while (true) {
            std::cin >> day;
            if (!std::cin) {
                std::cerr << "输入错误, 请重新输入:";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
            } else if (day < 1 || day > 5) {
                std::cerr << "输入错误, 请重新输入:";
            } else {
                break;
            }
        }
        short intervak;
        std::cout << "1.上午\n"
                     "2.下午\n"
                     "请输入申请预约的时段:";
        while (true) {
            std::cin >> intervak;
            if (!std::cin) {
                std::cerr << "输入错误, 请重新输入:";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
            } else if (intervak < 1 || intervak > 2) {
                std::cerr << "输入错误, 请重新输入:";
            } else {
                break;
            }
        }
        for (const auto &[id, capacity] : crrs::computerRoomMap) {
            if (capacity == 0) {
                std::cout << id << "号机房已满\n";
            } else {
                std::cout << id << "号机房容量: " << capacity << '\n';
            }
        }
        unsigned long long roomID;
        std::cout << "按0返回到上个界面\n请选择机房:";
        while (true) {
            std::cin >> roomID;
            if (!std::cin) {
                std::cerr << "输入错误, 请重新输入:";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
            } else if (roomID == 0) {
                return;
            } else if (crrs::computerRoomMap.count(roomID) == 0) {
                std::cerr << "机房不存在, 请重新输入:";
            } else if (crrs::computerRoomMap[roomID] == 0) {
                std::cerr << roomID << "号机房已满, 请重新输入:";
            } else {
                break;
            }
        }
        --crrs::computerRoomMap[roomID];
    summonUUID:
        uuid_t uu;
        char   uuid[37];
        uuid_generate(uu);
        uuid_unparse_lower(uu, uuid);
        if (crrs::orderMap.count(uuid) != 0) {
            goto summonUUID;
        }
        (std::ofstream(ORDER_FILENAME, std::ios::app)
         << '\n'
         << uuid << ' ' << day << ' ' << intervak << ' ' << m_id << ' '
         << m_name << ' ' << roomID << ' ' << 1)
            .close();
        crrs::orderMap.emplace(
            uuid, crrs::order{day, intervak, m_id, m_name, roomID, 1});
        std::cout << "预约成功, 请等待审核!\n";
#ifndef _WIN32
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
        crrs::pause_and_clear();
    }

    void showMyOrder() {
        for (const auto &[unused_var_, order] : crrs::orderMap) {
            if (order.studentID == m_id) {
                std::cout << "预约日期: "
                          << (order.day == 1   ? "周一"
                              : order.day == 2 ? "周二"
                              : order.day == 3 ? "周三"
                              : order.day == 4 ? "周四"
                                               : "周五")
                          << "\t时段: "
                          << (order.intervak == 1 ? "上午" : "下午")
                          << "\t机房: " << order.roomID << "号\t状态: "
                          << (order.status == 1   ? "审核中"
                              : order.status == 2 ? "预约成功"
                              : order.status == -1 ? "预约失败，审核不通过"
                                                   : "预约已取消")
                          << '\n';
            }
        }
#ifndef _WIN32
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#endif
        crrs::pause_and_clear();
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

    void cancelOrder() {
        unsigned long long                                  count = 0;
        std::unordered_map<unsigned long long, std::string> uuidMap;
        for (const auto &[uuid, order] : crrs::orderMap) {
            if (order.studentID == m_id
                && (order.status == 1 || order.status == 2)) {
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
            std::cout << "请选择要取消的记录，0代表返回:";
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
        crrs::orderMap.erase(uuidMap[userSelect]);
        std::ofstream fout(ORDER_FILENAME);
        for (auto &[uuid, order] : crrs::orderMap) {
            fout << '\n'
                 << uuid << ' ' << order.day << ' ' << order.intervak << ' '
                 << order.studentID << ' ' << order.studentName << ' '
                 << order.roomID << ' ' << order.status;
        }
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
                     "│      1.申 请  预 约      │\n"
                     "│                          │\n"
                     "│      2.查看我的预约      │\n"
                     "│                          │\n"
                     "│      3.查看所有预约      │\n"
                     "│                          │\n"
                     "│      4.取 消  预 约      │\n"
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
