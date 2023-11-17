#pragma once
#include "Player.h"
#include <algorithm>
#include <array>
#include <cstdlib>
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
            R"(****************
*1.开始演讲比赛*
*2.查看往届记录*
*3.清空比赛记录*
*0.退出比赛程序*
****************

请选择：)";
    }

    void Start() {
        this->Init();
        this->RandomShuffle();
        this->Grouping();
        this->GetAvgScore();
        this->KeepPromotionPlayers();
        this->ShowSecondResults();
        this->Scoreing(this->playersThirdGroup);
        std::sort(this->playersThirdGroup.begin(), this->playersThirdGroup.end(),
                  [&](Player &player1, Player &player2) -> bool {
                      return player1.avgScore > player2.avgScore;
                  });
        this->ShowAndWritingResultsToFile();
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
    // HACK: 如果你是windows系统，请将 system("clear"); 改为 system("cls");
    void PauseClear() {
        std::cout << "请按Enter键继续";
        std::cin.get();
        system("clear");
    }

    void Init() {
        playersFirstGroup = {
            10001, 10002, 10003, 10004, 10005, 10006, 10007, 10008, 10009, 10010, 10011, 10012,
        };
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
                player.avgScore += var;
            }
            player.avgScore /= 8;
        }
    }

    void RandomShuffle() {
        std::shuffle(this->playersFirstGroup.begin(), this->playersFirstGroup.end(),
                     std::mt19937{std::random_device{}()});
        for (char i = 0; i < 6; ++i) {
            this->playersSecondGroup[0][i] = this->playersFirstGroup[i];
        }
        for (char i = 6; i < 12; ++i) {
            this->playersSecondGroup[1][i - 6] = this->playersFirstGroup[i];
        }
    }

    void Grouping() {
        std::cout << "\n分组结果：\n-----------------------------------------------"
                     "----------\n";
        for (char i = 0; i < 2; ++i) {
            std::cout << "第" << (short)i + 1 << "组：\n";
            for (auto &var0 : this->playersSecondGroup[i]) {
                std::cout << var0.ID << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "---------------------------------------------------------"
                     "\n请按Enter键继续";
        std::cin.get();
        std::cin.get();
    }

    void GetAvgScore() {
        std::cout << "\n第1轮比赛结果：\n------------------------------------------"
                     "---------------\n";
        for (char i = 0; i < 2; ++i) {
            this->Scoreing(this->playersSecondGroup[i]);
            std::cout << "第" << (short)i + 1 << "组：\n";
            for (auto &var0 : this->playersSecondGroup[i]) {
                std::cout << var0.ID << " 分数" << var0.avgScore << '\n';
            }
        }
        std::cout << "---------------------------------------------------------"
                     "\n请按Enter键继续";
        std::cin.get();
    }

    void SortArray() {
        for (auto &var : this->playersSecondGroup) {
            std::sort(var.begin(), var.end(), [&](Player &player1, Player &player2) -> bool {
                return player1.avgScore > player2.avgScore;
            });
        }
    }

    void KeepPromotionPlayers() {
        std::cout << "晋级选手：\n-------------------------------------------------"
                     "--------\n";
        for (char i = 0; i < 2; ++i) {
            std::cout << "第" << (short)i + 1 << "组：\n";
            for (char j = 0; j < 3; ++j) {
                if (i == 1) {
                    this->playersThirdGroup[j + 3] = this->playersSecondGroup[i][j];
                    std::cout << this->playersThirdGroup[j + 3].ID << ' '
                              << this->playersThirdGroup[j + 3].avgScore << '\n';
                } else {
                    this->playersThirdGroup[j] = this->playersSecondGroup[i][j];
                    std::cout << this->playersThirdGroup[j].ID << ' '
                              << this->playersThirdGroup[j].avgScore << '\n';
                }
            }
        }
        std::cout << "---------------------------------------------------------"
                     "\n请按Enter键继续";
        std::cin.get();
    }

    void ShowSecondResults() {
        std::cout << "\n第2轮比赛结果：\n------------------------------------------"
                     "---------------\n";
        for (auto &var0 : this->playersThirdGroup) {
            std::cout << var0.ID << " 分数" << var0.avgScore << '\n';
        }
        std::cout << "---------------------------------------------------------"
                     "\n请按Enter键继续";
        std::cin.get();
    }

    void ShowAndWritingResultsToFile() {
        std::cout << "最终结果：\n冠军：" << this->playersThirdGroup[0].ID << " 分数："
                  << this->playersThirdGroup[0].avgScore << "\n亚军："
                  << this->playersThirdGroup[1].ID << " 分数："
                  << this->playersThirdGroup[1].avgScore << "\n季军："
                  << this->playersThirdGroup[2].ID << " 分数："
                  << this->playersThirdGroup[2].avgScore << '\n';
        this->fout.open(".seepchhistory.csv", std::ios::app);
        fout << this->playersThirdGroup[0].ID << ',' << this->playersThirdGroup[0].avgScore << ",\n"
             << this->playersThirdGroup[1].ID << ',' << this->playersThirdGroup[1].avgScore << ",\n"
             << this->playersThirdGroup[2].ID << ',' << this->playersThirdGroup[2].avgScore
             << ",\n\n";
        fout.close();
    }

    std::ifstream fin;
    std::ofstream fout;
    std::array<Player, 12> playersFirstGroup;
    std::array<std::array<Player, 6>, 2> playersSecondGroup;
    std::array<Player, 6> playersThirdGroup;
};
