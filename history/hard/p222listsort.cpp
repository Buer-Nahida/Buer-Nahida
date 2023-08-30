#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <ostream>
#include <string>
using namespace std;

class Person {
public:
  Person(string name, int age, int height) {
    this->m_Name = name;
    this->m_Age = age;
    this->m_Height = height;
  }

  string m_Name;
  short m_Age, m_Height;
};

void PrintList(const list<Person> &persons) {
  for (auto &person : persons) {
    cout << person.m_Name << "\t" << person.m_Age << "\t" << person.m_Height
         << endl;
  }
}

void InitPerson(list<Person> &persons, string name = "人", short num = 5) {
  for (short i = 0; i < num; i++) {
    char a = i;
    string temp = name;
    name += a ^ 48;
    persons.push_back(Person(name, rand() % 61 + 10, rand() % 41 + 160));
    name = temp;
  }
}

bool SortPerson(Person person0, Person person1) {
  if (person0.m_Age == person1.m_Age) {
    return person0.m_Height > person1.m_Height;
  }
  return person0.m_Age < person1.m_Age;
}

int main(int argc, char *argv[]) {
  srand((unsigned long)time(NULL));
  list<Person> personList;
  InitPerson(personList, "Jack");
  cout << "排序前：" << endl << "姓名\t年龄\t身高" << endl;
  PrintList(personList);
  cout << endl;
  cout << "排序后：" << endl << "姓名\t年龄\t身高" << endl;
  personList.sort(SortPerson);
  PrintList(personList);
  return 0;
}
