#include "headers/all.h"

int main(int argc, char *argv[]) {
  system("clear");
  Addressbooks Ars;
  Ars.Size = 0;

  while (1) {
    short Select;
    showMenu();
    cin >> Select;

    switch (Select) {
    case 1:
      addPerson(&Ars);
      break;

    case 2:
      showPerson(&Ars);
      break;

    case 3:
      deletePerson(&Ars);
      break;

    case 4:
      findPerson(&Ars);
      break;

    case 5:
      modifyPerson(&Ars);
      break;

    case 6:
      ClearAll(&Ars);
      break;

    default:
      exit(0);
      break;
    }
  }
  return 0;
}
