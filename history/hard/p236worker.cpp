#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Worker {
public:
  Worker(const string name, const short salary) {
    this->m_Name = name;
    this->m_Salary = salary;
  }
  string m_Name;
  short m_Salary;
  bool operator<(Worker worker) const { return this->m_Name < worker.m_Name; }
};

void PrintWorkers(const multimap<short, Worker> &mapName) {
  multimap<short, Worker>::const_iterator it0 = mapName.begin(),
                                          it1 = ++mapName.begin();
  cout << "策划部门：" << endl
       << "姓名\t工资" << endl
       << "-----------------------------------------" << endl;
  for (short count = 0; count < 10; count++) {
    if (it0->first != it1->first) {
      if (it0->first == 1) {
        cout << endl
             << "美术部门：" << endl
             << "姓名\t工资" << endl
             << "-----------------------------------------" << endl;
      } else if (it0->first == 2) {
        cout << endl
             << "研发部门：" << endl
             << "姓名\t工资" << endl
             << "-----------------------------------------" << endl;
      }
    }
    cout << it0->second.m_Name << "\t" << it0->second.m_Salary << endl;
    it0++;
    it1++;
  }
}

void InitGroups(vector<Worker> &workers) {
  const char *nameSeed = "ABCDEFGHIJ";
  for (char count = 0; count < 10; count++) {
    workers.push_back(
        Worker((string) "员工" += nameSeed[count], rand() % 3501 + 3000));
  }
}

void Grouping(multimap<short, Worker> &workerGroup, vector<Worker> &workers) {
  for (int count = 9; count >= 0; count--) {
    short deptID = rand() % (count + 1);
    workerGroup.emplace(rand() % 3, workers[deptID]);
    workers.erase(workers.begin() + deptID);
  }
}

int main(int argc, char *argv[]) {
  srand((unsigned long)time(NULL));
  vector<Worker> workers;
  workers.reserve(10);
  multimap<short, Worker> workerGroup;
  InitGroups(workers);
  Grouping(workerGroup, workers);
  PrintWorkers(workerGroup);
  return 0;
}
