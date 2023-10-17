#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string strEmail = "myemail@gmail.com";
    cout << strEmail.substr(0, strEmail.rfind('@')) << endl;
    return 0;
}
