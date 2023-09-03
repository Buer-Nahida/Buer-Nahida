#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

void PrintWorkers(const multimap<short, char> &mapName) {
  multimap<short, char>::const_iterator it0 = mapName.begin(),
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

void InitGroups(vector<char> &workers, vector<set<char>> &setGroup) {
  for (char count = 0; count < 10; count++) {
    workers.push_back("ABCDEFGHIJ"[count]);
  }
  for (char count = 0; count < 3; count++) {
    setGroup.push_back(set<char>());
  }
}

void Grouping(vector<set<char>> &setGroup, vector<char> &workers) {
  for (int count = 9; count >= 0; count--) {
    short rando = rand() % (count + 1);
    setGroup[rand() % 3].insert(workers[rando]);
    workers.erase(workers.begin() + rando);
  }
}

void MoveWorker(multimap<short, char> &workerGroup,
                vector<set<char>> &setGroup) {
  for (short count = 0; count < 3; count++) {
    for (auto &var1 : setGroup[count]) {
      workerGroup.emplace(count, var1);
    }
  }
}

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));
  vector<char> workers;
  vector<set<char>> setGroup;
  multimap<short, char> workerGroup;
  InitGroups(workers, setGroup);
  Grouping(setGroup, workers);
  MoveWorker(workerGroup, setGroup);
  PrintWorkers(workerGroup);
  return 0;
}
