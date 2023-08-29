#include <algorithm>
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

int main(int argc, char *argv[]) {
  vector<Player> playerVector;
  playerVector.resize(5);
  for (auto &var : playerVector) {
    string name;
    double score;
    cout << "请输入选手的姓名和分数（用空格分割）：";
    cin >> name >> score;
    var = Player(name, score);
  }
  deque<double> scoreDeque;
  for (auto &var : playerVector)
    scoreDeque.push_back(var.m_Score);
  sort(scoreDeque.begin(), scoreDeque.end());
  scoreDeque.pop_front();
  scoreDeque.pop_back();
  double playerScore = 0;
  for (auto &var : scoreDeque) {
    playerScore += var;
  }
  playerScore /= 3;
  cout << "平均分：" << setprecision(3) << playerScore << "分" << endl;
  return 0;
}
