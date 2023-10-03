#pragma once
#include "Player.h"
#include <algorithm>
#include <array>
#include <cstdlib>
#include <experimental/random>
#include <fstream>
#include <ios>
#include <iostream>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>

class SpeechSystem {
public:
  void Menu() {
    std::cout <<
        R"(********************
***1.开始演讲比赛***
***2.查看往届记录***
***3.清空比赛记录***
***0.退出比赛程序***
********************

请选择：)";
  }
  void Start() {
    std::array<Player, 12> players0{
        10001, 10002, 10003, 10004, 10005, 10006,
        10007, 10008, 10009, 10010, 10011, 10012,
    };
#ifdef DEBUG
    std::cout << "原始数组\n";
    for (Player &var : players0) {
      std::cout << var.ID << ' ';
    }
    std::cout << '\n';
#endif // PASSED: Init array
    std::shuffle(players0.begin(), players0.end(),
                 std::mt19937{std::random_device{}()});
#ifdef DEBUG
    std::cout << "打乱后\n";
    for (Player &var : players0) {
      std::cout << var.ID << ' ';
    }
    std::cout << '\n';
#endif // PASSED: Random shuffle
    std::array<Player, 6> players00[2];
    for (char i = 0; i < 6; ++i) {
      players00[0][i] = players0[i];
    }
    for (char i = 6; i < 12; ++i) {
      players00[1][i - 6] = players0[i];
    }
    // PASSED:BEGIN Grouping
    std::cout << "\n分组结果：\n-----------------------------------------------"
                 "----------\n";
    for (char i = 0; i < 2; ++i) {
      std::cout << "第" << (short)i + 1 << "组：\n";
      for (auto &var0 : players00[i]) {
        std::cout << var0.ID << ' ';
      }
      std::cout << '\n';
    }
    std::cout << "---------------------------------------------------------"
                 "\n请按Enter键继续";
    std::cin.get();
    std::cin.get();
    // PASSED:END Grouping
    // PASSED:BEGIN Get avgScore
    std::cout << "\n第1轮比赛结果：\n------------------------------------------"
                 "---------------\n";
    for (char i = 0; i < 2; ++i) {
      this->Scoreing(players00[i]);
      std::cout << "第" << (short)i + 1 << "组：\n";
      for (auto &var0 : players00[i]) {
        std::cout << var0.ID << " 分数" << var0.avgScore << '\n';
      }
    }
    std::cout << "---------------------------------------------------------"
                 "\n请按Enter键继续";
    std::cin.get();
    // PASSED:END Get avgScore
#ifdef DEBUG
    std::cout << "\n排序后\n";
#endif
    for (auto &var : players00) {
      std::sort(var.begin(), var.end(),
                [&](Player &player1, Player &player2) -> bool {
                  return player1.avgScore > player2.avgScore;
                });
#ifdef DEBUG
      for (const auto &var1 : var) {
        std::cout << var1.ID << ' ' << var1.avgScore << '\n';
      }
      std::cout << '\n';
#endif // PASSED: Sort players00 array
    }
#ifdef DEBUG
    std::cout << "留下来的\n";
#endif
    std::array<Player, 6> players000;
    std::cout << "晋级选手：\n-------------------------------------------------"
                 "--------\n";
    for (char i = 0; i < 2; ++i) {
      std::cout << "第" << (short)i + 1 << "组：\n";
      for (char j = 0; j < 3; ++j) {
        if (i == 1) {
          players000[j + 3] = players00[i][j];
          // PASSED:BEGIN Keep the top three
          std::cout << players000[j + 3].ID << ' ' << players000[j + 3].avgScore
                    << '\n';
          // PASSED:END Keep the top three
        } else {
          players000[j] = players00[i][j];
          // PASSED:BEGIN Keep the top three
          std::cout << players000[j].ID << ' ' << players000[j].avgScore
                    << '\n';
          // PASSED:END Keep the top three
        }
      }
#ifdef DEBUG
      std::cout << '\n';
#endif
    }
    std::cout << "---------------------------------------------------------"
                 "\n请按Enter键继续";
    std::cin.get();

    std::cout << "\n第2轮比赛结果：\n------------------------------------------"
                 "---------------\n";
    for (auto &var0 : players000) {
      std::cout << var0.ID << " 分数" << var0.avgScore << '\n';
    }
    std::cout << "---------------------------------------------------------"
                 "\n请按Enter键继续";
    std::cin.get();

    this->Scoreing(players000);
    std::sort(players000.begin(), players000.end(),
              [&](Player &player1, Player &player2) -> bool {
                return player1.avgScore > player2.avgScore;
              });
    std::cout << "最终结果：\n冠军：" << players000[0].ID << " 分数："
              << players000[0].avgScore << "\n亚军：" << players000[1].ID
              << " 分数：" << players000[1].avgScore << "\n季军："
              << players000[2].ID << " 分数：" << players000[2].avgScore
              << '\n';
    this->fout.open(".seepchhistory.csv", std::ios::app);
    fout << players000[0].ID << ',' << players000[0].avgScore << '\n'
         << players000[1].ID << ',' << players000[1].avgScore << '\n'
         << players000[2].ID << ',' << players000[2].avgScore << "\n\n";
    fout.close();
    this->PauseClear();
  }

  void ShowHistory() {
    this->fin.open(".seepchhistory.csv");
    if (!fin.is_open()) {
      std::cout << "木有文件啊\n";
      std::cin.get();
      this->PauseClear();
      return;
    }
    std::string str;
    std::cout << "---------------------------------------------------------"
                 "\n第1届：\n";
    unsigned long long i = 1, j = 0;
    std::string str_line;
    while (getline(fin, str_line, ',')) {
      std::string str_tmp;
      std::stringstream ss(str_line);
      while (ss >> str_tmp) {
        std::cout << str_tmp;
        std::regex str_reg("(1000[1-9])|(1001[0-2])");
        std::smatch result;
        ++j;
        if (j == 6) {
          j = 0;
          ++i;
          std::cout << "\n\n第" << i << "届：";
        }
        if (std::regex_match(str_tmp, result, str_reg)) {
          std::cout << ' ';
        } else {
          std::cout << '\n';
        }
      }
    }
    this->fin.close();
    std::cout << "待开始...\n--------------------------------------------------"
                 "-------\n";
    std::cin.get();
    this->PauseClear();
  }

  void ClearHistory() {
    std::cout << "确认吗?(y/N)";
    char ch;
    std::cin >> ch;
    if (ch == 'y' || ch == 'Y') {
      this->fout.open(".seepchhistory.csv", std::ios::trunc);
      this->fout.close();
      std::cout << "清除完毕\n";
      std::cin.get();
      this->PauseClear();
    }
  }

private:
  /*  HACK:
   * 如果你是windows系统，请将
   * system("clear");
   * 改为
   * system("cls");
   */
  void PauseClear() {
    std::cout << "请按Enter键继续";
    std::cin.get();
    system("clear");
  }
  // PASSED: Scoreing
  template <typename T> void Scoreing(T &players) {
    std::uniform_int_distribution<> dist(100, 10000);
    std::mt19937 randomValue(std::random_device{}());
    for (Player &player : players) {
      std::multiset<float> scores;
      for (char j = 0; j < 10; ++j) {
        float fl = dist(randomValue);
        scores.insert(fl / 100);
      }
      scores.insert(scores.begin(), 0);
      scores.insert(--scores.end(), 0);
      for (const float &var : scores) {
#ifdef DEBUG
        std::cout << var << ' ';
#endif
        player.avgScore += var;
      }
      player.avgScore /= 8;
#ifdef DEBUG
      std::cout << '\n';
#endif
    }
  }
  std::ifstream fin;
  std::ofstream fout;
};
