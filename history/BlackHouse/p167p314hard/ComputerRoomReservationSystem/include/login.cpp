#include "HashmapVar.cpp"
#include "identity/administrator.hpp"
#include "identity/student.hpp"
#include "identity/teacher.hpp"
#include "pause.cpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

namespace crrs {
class {
public:
    template <typename Identity> void login() {
        unsigned long long id;
        std::string        name, password;
        if (typeid(Identity) == typeid(crrs::identity::student)) {
            StudentLogin();
        } else if (typeid(Identity) == typeid(crrs::identity::teacher)) {
            TeacherLogin();
        } else {
            AdministratorLogin();
        }
        crrs::pause_and_clear();
    }

private:
    void InputId(unsigned long long &id, const char *const TIP_TEXT) {
        while (true) {
            std::cout << TIP_TEXT;
            std::cin >> id;
            if (std::cin) {
                break;
            }
            std::cerr << "ERROR: 无效，请重新输入数字\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void InputUsernameAndPassword(std::string &name, std::string &password) {
        while (true)
            if (std::cin.get() == '\n') break;
        std::cout << "请输入用户名:";
        std::getline(std::cin, name);
        std::cout << "请输入密码:";
        std::getline(std::cin, password);
    }

    void StudentLogin() {
        unsigned long long id;
        std::string        name, password;
        InputId(id, "请输入您的学号:");
        if (crrs::studentMap.count(id) == 0) {
            std::cerr << "ERROR: 学号不存在\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        InputUsernameAndPassword(name, password);
        const auto &[NAME, PASSWORD]{crrs::studentMap[id]};
        if (NAME == name && PASSWORD == password) {
            std::cout << "登录成功\n";
            crrs::pause_and_clear();
            crrs::identity::student{id, name, password}.operMenu();
            return;
        }
        std::cerr << "ERROR: 用户名或密码错误\n";
    }

    void TeacherLogin() {
        unsigned long long id;
        std::string        name, password;
        InputId(id, "请输入您的职工号:");
        if (crrs::teacherMap.count(id) == 0) {
            std::cerr << "ERROR: 职工号不存在\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        InputUsernameAndPassword(name, password);
        const auto &[NAME, PASSWORD]{crrs::teacherMap[id]};
        if (NAME == name && PASSWORD == password) {
            std::cout << "登录成功\n";
            crrs::pause_and_clear();
            crrs::identity::teacher{id, name, password}.oper_menu();
            return;
        }
        std::cerr << "ERROR: 用户名或密码错误\n";
    }

    void AdministratorLogin() {
        std::string name, password;
        InputUsernameAndPassword(name, password);
        if (crrs::administratorMap.count(name) == 0) {
            std::cerr << "ERROR: 用户不存在\n";
            return;
        }
        if (crrs::administratorMap[name] != password) {
            std::cerr << "ERROR: 密码错误\n";
            return;
        }
        std::cout << "登录成功\n";
        crrs::pause_and_clear();
        crrs::identity::administrator admin{name, password};
        admin.operMenu();
    }
} login;
} // namespace crrs
