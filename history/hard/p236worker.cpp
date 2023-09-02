#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

void PrintWorkers(const multimap<short, string> &mapName) {
  multimap<short, string>::const_iterator it0 = mapName.begin(),
                                          it1 = ++mapName.begin();
  for (short count = 0; count < 10; count++) {
    if (it0->first == 0) {
      cout << "策划 " << it0->second << endl;
    } else if (it0->first == 1) {
      cout << "美术 " << it0->second << endl;
    } else {
      cout << "研发 " << it0->second << endl;
    }
    if (it0->first != it1->first) {
      if (it1 != mapName.end()) {
        cout << endl;
      }
    }
    it0++;
    it1++;
  }
}

void InitGroups(vector<string> &workers, vector<set<string>> &setGroup) {
  for (char count = 0; count < 10; count++) {
    workers.push_back((string) "员工" += count ^ 48);
  }
  for (char count = 0; count < 3; count++) {
    setGroup.push_back(set<string>());
  }
}

void Grouping(vector<set<string>> &setGroup, vector<string> &workers) {
  for (int count = 9; count >= 0; count--) {
    short rando = rand() % (count + 1);
    setGroup[rand() % 3].insert(workers[rando]);
    workers.erase(workers.begin() + rando);
  }
}

void MoveWorker(multimap<short, string> &workerGroup,
                vector<set<string>> &setGroup) {
  for (short count = 0; count < 3; count++) {
    for (auto &var1 : setGroup[count]) {
      workerGroup.emplace(count, var1);
    }
  }
}

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));
  vector<string> workers;
  vector<set<string>> setGroup;
  multimap<short, string> workerGroup;
  InitGroups(workers, setGroup);
  Grouping(setGroup, workers);
  MoveWorker(workerGroup, setGroup);
  PrintWorkers(workerGroup);
  return 0;
}
