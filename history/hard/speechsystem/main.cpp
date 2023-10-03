#include "headers/SpeechSystem.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  SpeechSystem speechSystem;
  short userInput;
  while (1) {
    speechSystem.Menu();
    std::cin >> userInput;
    switch (userInput) {
    case 1:
      speechSystem.Start();
      break;
    case 2:
      speechSystem.ShowHistory();
      break;
    case 3:
      speechSystem.ClearHistory();
      break;
    case 0:
      exit(0);
      break;
    default:
      break;
    }
  }
  return 0;
}
