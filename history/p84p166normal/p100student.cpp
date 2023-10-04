#include <iostream>
#include <string>
using namespace std;
#define PI 3.14

class Student {
public:
    string s_Name;
    unsigned long long s_ID;
    void showStudent() {
        cout << "Name:" << s_Name << endl;
        cout << "ID:" << s_ID << endl;
    }
};

int main(int argc, char *argv[]) {
    Student Student1;
    Student1.s_Name = "野兽先辈";
    Student1.s_ID = 1145141919810;
    Student1.showStudent();
    return 0;
}
