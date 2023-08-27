#include "my/star.h"

int main(int argc, char *argv[]) {
  string strEmail = "myemail@gmail.com";
  cout << strEmail.substr(0, strEmail.find('@')) << endl;
  return 0;
}
