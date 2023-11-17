#include "include/HashmapVar.cpp"
#include "include/fileNameDefine.h"
#include "include/identity/administrator.hpp"
#include "include/identity/student.hpp"
#include "include/identity/teacher.hpp"
#include "include/login.cpp"
#include "include/menu.cpp"
#include "include/reinput.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

void initHashmaps() {
    std::ifstream      fin(STUDENT_USER_FILENAME);
    unsigned long long id;
    std::string        name, password;
    while (fin >> id >> name >> password) {
        crrs::studentMap.emplace(id, std::pair{name, password});
    }
    fin.close();
    fin.open(TEACHER_USER_FILENAME);
    while (fin >> id >> name >> password) {
        crrs::teacherMap.emplace(id, std::pair{name, password});
    }
    fin.close();
    fin.open(ADMIN_USER_FILENAME);
    while (fin >> name >> password) {
        crrs::administratorMap.emplace(name, password);
    }
    fin.close();
    fin.open(COMPUTER_ROOM_FILENAME);
    unsigned long long capacity;
    while (fin >> id >> capacity) {
        crrs::computerRoomMap.emplace(id, capacity);
    }
    fin.close();
    fin.open(ORDER_FILENAME);
    short              day, intervak, status;
    unsigned long long studentID, roomID;
    std::string        studentName, uuid;
    while (fin >> uuid >> day >> intervak >> studentID >> studentName >> roomID
           >> status) {
        crrs::orderMap.emplace(uuid, crrs::order{day, intervak, studentID,
                                                 studentName, roomID, status});
    }
}

int main(int argc, char *argv[]) {
    initHashmaps();
    short userSelect;
    while (true) {
        crrs::show_menu();
    Reinput:
        std::cout << "\n请选择登录身份:";
        std::cin >> userSelect;
        if (!std::cin) {
        InvalidInput:
            crrs::reinput();
            goto Reinput;
        }
        switch (userSelect) {
            case 1:  crrs::login.login<crrs::identity::student>(); break;
            case 2:  crrs::login.login<crrs::identity::teacher>(); break;
            case 3:  crrs::login.login<crrs::identity::administrator>(); break;
            case 0:  return 0; break;
            default: goto InvalidInput; break;
        }
    }
    return 0;
}
