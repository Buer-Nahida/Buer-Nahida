#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
public:
  Player() = default;
  Player(string name, double score) {
    this->m_Name = name;
    this->m_Score = score;
  }
  Player(Player &&) = default;
  Player(const Player &) = default;
  Player &operator=(Player &&) = default;
  Player &operator=(const Player &) = default;
  ~Player() = default;

  string m_Name;
  double m_Score;
};

void InitPlayer(vector<Player> &players) {
  for (short count = 0; count < 5; count++) {
    string playerName = "选手", abc = "ABCDE";
    playerName += abc[count];
    players.push_back(Player(playerName, 0));
  }
}

void SetScore(deque<double> &scores) {
  for (short count = 0; count < 10; count++) {
    scores.push_back(rand() % 41 + 60);
  }
}

void SortScore(deque<double> &scores) {
  sort(scores.begin(), scores.end());
  scores.pop_front();
  scores.pop_back();
}

void SumScore(vector<Player> &players) {
  deque<double> scoreDeque;
  for (auto &player : players) {
    SetScore(scoreDeque);
    SortScore(scoreDeque);
    for (auto &var : scoreDeque) {
      player.m_Score += var;
    }
    player.m_Score /= scoreDeque.size();
  }
}

void PrintPlayer(vector<Player> players) {
  for (auto &players : players) {
    cout << players.m_Name << "：" << players.m_Score << "分" << endl;
  }
}

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));
  vector<Player> playerVector;
  InitPlayer(playerVector);
  SumScore(playerVector);
  PrintPlayer(playerVector);
  return 0;
}
