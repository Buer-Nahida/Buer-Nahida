#include "person.h"

void ClearSceen() {
    cout << "按 Enter 键继续";
    cin.get();
    cin.get();
    system("clear");
}

void addPerson(Addressbooks *AddressbooksName) {
    if (AddressbooksName->Size == MAX)
        cout << "通讯录已满" << endl;
    else {

        cout << "名字：";
        cin >> AddressbooksName->personArr[AddressbooksName->Size].Name;
        cout << endl;

    Sex:
        cout << "性别（1=男，0=女）：";
        cin >> AddressbooksName->personArr[AddressbooksName->Size].Sex;
        if (AddressbooksName->personArr[AddressbooksName->Size].Sex != 0 &&
            AddressbooksName->personArr[AddressbooksName->Size].Sex != 1) {
            cout << "你这性别太假了，请重新输入" << endl;
            goto Sex;
        }
        cout << endl;

    Age:
        cout << "年龄：";
        cin >> AddressbooksName->personArr[AddressbooksName->Size].Age;
        if (AddressbooksName->personArr[AddressbooksName->Size].Age < 1 ||
            AddressbooksName->personArr[AddressbooksName->Size].Age > 150) {
            cout << "你这年龄太假了，请重新输入" << endl;
            goto Age;
        }
        cout << endl;

        cout << "电话：";
        cin >> AddressbooksName->personArr[AddressbooksName->Size].PhoneNum;
        cout << endl;

        cout << "住址：";
        cin >> AddressbooksName->personArr[AddressbooksName->Size].Addr;
        cout << endl;

        cout << "添加完成" << endl;

        AddressbooksName->Size++;
    }
    ClearSceen();
}

void showPerson(Addressbooks *AddressbooksName) {
    cout << "姓名\t\t\t性别\t\t\t年龄\t\t\t电话\t\t\t住址" << endl
         << "------------------------------------------------------------------"
            "--"
            "------------------------------------------------------------------"
            "--"
         << endl;
    if (AddressbooksName->Size == 0) {
        cout << "空" << endl;
        ClearSceen();
    } else {
        for (short i = 0; i < AddressbooksName->Size; i++) {
            cout << AddressbooksName->personArr[i].Name << "\t\t\t"
                 << (AddressbooksName->personArr[i].Sex == 1 ? "男" : "女")
                 << "\t\t\t" << AddressbooksName->personArr[i].Age << "\t\t\t"
                 << AddressbooksName->personArr[i].PhoneNum << "\t\t\t"
                 << AddressbooksName->personArr[i].Addr << endl;
        }
    }
    ClearSceen();
}

int isExist(Addressbooks *AddressbooksName, string i_Name) {
    for (int i = 0; i < AddressbooksName->Size; i++) {
        if (AddressbooksName->personArr[i].Name == i_Name)
            return i;
    }
    return -1;
}

void deletePerson(Addressbooks *AddressbooksName) {
    string d_Name;
    cout << "请输入姓名：";
    cin >> d_Name;
    int d_Ret = isExist(AddressbooksName, d_Name);
    if (d_Ret == -1)
        cout << "查无此人" << endl;
    else if (AddressbooksName->Size == 1000 &&
             AddressbooksName->Size - 1 == d_Ret + 1) {
        AddressbooksName->Size--;
    } else {
        for (int i = d_Ret; i < AddressbooksName->Size; i++) {
            AddressbooksName->personArr[i].Age =
                AddressbooksName->personArr[i + 1].Age;
            AddressbooksName->personArr[i].Sex =
                AddressbooksName->personArr[i + 1].Sex;
            AddressbooksName->personArr[i].Name =
                AddressbooksName->personArr[i + 1].Name;
            AddressbooksName->personArr[i].Addr =
                AddressbooksName->personArr[i + 1].Addr;
            AddressbooksName->personArr[i].PhoneNum =
                AddressbooksName->personArr[i + 1].PhoneNum;
        }
    }
    AddressbooksName->Size--;
    ClearSceen();
}

void findPerson(Addressbooks *AddressbooksName) {
    cout << "请输入姓名：";
    string f_Name;
    cin >> f_Name;
    int f_Ret = isExist(AddressbooksName, f_Name);
    if (f_Ret == -1)
        cout << "查无此人" << endl;
    else {
        cout << "姓名\t\t\t性别\t\t\t年龄\t\t\t电话\t\t\t住址" << endl
             << "--------------------------------------------------------------"
                "----"
                "--"
                "--------------------------------------------------------------"
                "----"
                "--"
             << endl;
        cout << AddressbooksName->personArr[f_Ret].Name << "\t\t\t"
             << (AddressbooksName->personArr[f_Ret].Sex == 1 ? "男" : "女")
             << "\t\t\t" << AddressbooksName->personArr[f_Ret].Age << "\t\t\t"
             << AddressbooksName->personArr[f_Ret].PhoneNum << "\t\t\t"
             << AddressbooksName->personArr[f_Ret].Addr << endl;
    }
    ClearSceen();
}

void modifyPerson(Addressbooks *AddressbooksName) {
    cout << "请输入姓名：";
    string m_Name;
    cin >> m_Name;
    int m_Ret = isExist(AddressbooksName, m_Name);
    if (m_Ret == -1)
        cout << "查无此人" << endl;
    else {

    Select:
        cout << "你要修改什么（A=姓名，B=性别，C=年龄、D=电话号、E="
                "住址）（不区分大小写）：";
        string m_Select;
        cin >> m_Select;
        if (m_Select == "A" || m_Select == "a") {
            cout << "名字：";
            cin >> AddressbooksName->personArr[m_Ret].Name;
            cout << "修改完成" << endl;
        } else if (m_Select == "B" || m_Select == "b") {

        Sex:
            cout << "性别（1=男，0=女）：";
            cin >> AddressbooksName->personArr[m_Ret].Sex;
            if (AddressbooksName->personArr[m_Ret].Sex != 0 &&
                AddressbooksName->personArr[m_Ret].Sex != 1) {
                cout << "你这性别太假了，请重新输入" << endl;
                goto Sex;
            }
            cout << "修改完成" << endl;
        } else if (m_Select == "C" || m_Select == "c") {

        Age:
            cout << "年龄：";
            cin >> AddressbooksName->personArr[m_Ret].Age;
            if (AddressbooksName->personArr[m_Ret].Age < 1 ||
                AddressbooksName->personArr[m_Ret].Age > 150) {
                cout << "你这年龄太假了，请重新输入" << endl;
                goto Age;
            }
            cout << "修改完成" << endl;
        } else if (m_Select == "D" || m_Select == "d") {
            cout << "电话：";
            cin >> AddressbooksName->personArr[m_Ret].PhoneNum;
            cout << "修改完成" << endl;
        } else if (m_Select == "E" || m_Select == "e") {
            cout << "住址：";
            cin >> AddressbooksName->personArr[m_Ret].Addr;
            cout << "修改完成" << endl;
        } else {
            cout << "你输入的啥也不是，请重新输入" << endl;
            goto Select;
        }
    }
    ClearSceen();
}

void ClearAll(Addressbooks *AddressbooksName) {
    AddressbooksName->Size = 0;
    cout << "你真的想清空所有人吗？（y/N）" << endl;
    string c_Temp;
    cin >> c_Temp;
    if (c_Temp == "y" || c_Temp == "Y") {
        cout << "所有人已经无了" << endl;
    } else {
        cout << "已取消" << endl;
    }
    ClearSceen();
}
