#include <iostream>
using namespace std;

template <typename T> void SelectSort(T &arrName) {
  unsigned long long arrLenger = (sizeof arrName / sizeof arrName[0]);
  for (unsigned long long count0 = 0; count0 < arrLenger; count0++) {
    unsigned long long min = count0;
    for (unsigned long long count1 = count0; count1 < arrLenger; count1++) {
      min = (arrName[min] < arrName[count1]) ? count1 : min;
    }
    swap(arrName[min], arrName[count0]);
  }
}

int main(int argc, char *argv[]) {
  char c_A[] = "abcaeb";
  int i_B[] = {1, 1, 4, 5, 1, 4};
  SelectSort(c_A);
  SelectSort(i_B);
  cout << c_A << endl;
  for (int i = 0; i < 6; i++) {
    cout << i_B[i] << " ";
  }
  cout << endl;
  return 0;
}
