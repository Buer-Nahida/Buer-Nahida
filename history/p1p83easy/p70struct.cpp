#include <bits/stdc++.h>
using namespace std;

struct Student {
  string Name;
  int Scores;
};

struct Teacher {
  string Name;
  Student Stu[5];
};

void test(Teacher *Ptr, int Width) {
  string Str = "ABCDE";
  for (int J = 0; J < Width; J++) {
    Ptr[J].Name = "Teacher_";
    Ptr[J].Name += Str[J];
    for (int I = 0; I < 5; I++) {
      Ptr[J].Stu[I].Name = "Student_";
      Ptr[J].Stu[I].Name += Str[I];
      srand(time(NULL));
      Ptr[J].Stu[I].Scores = rand() % 61 + 40;
    }
  }
}

int main(int argc, char *argv[]) {
  Teacher Test[3];
  test(Test, 3);
  for (int J = 0; J < 3; J++) {
    cout << endl
         << endl
         << "老师" << J + 1 << "的姓名是：" << Test[J].Name << endl
         << endl;
    for (int I = 0; I < 5; I++) {
      cout << "学生" << I + 1 << "的姓名是：" << Test[J].Stu[I].Name << endl;
      cout << "学生" << I + 1 << "的成绩是：" << Test[J].Stu[I].Scores;
      cout << endl;
    }
  }
  return 0;
}
