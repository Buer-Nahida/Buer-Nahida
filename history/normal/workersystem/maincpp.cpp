#include "headers/WorkerManager.h"

int main(int argc, char *argv[]) {
  long long userSelect;
  WorkerManager workerManager;
  while (1) {
    workerManager.ShowMenu();
    cin >> userSelect;
    switch (userSelect) {
    case 0:
      workerManager.ExitSystem();
      break;
    case 1:
      workerManager.AddSomeWorker();
      break;
    case 2:
      workerManager.ShowWorker();
      break;
    case 3:
      workerManager.DeleteWorker();
      break;
    case 4:
      workerManager.ChangeWorker();
      break;
    case 5:
      workerManager.FindWorker();
      break;
    case 6:
      workerManager.SortWorker();
      break;
    case 7:
      workerManager.ClearFile();
      break;
    default:
      cout << "暂无此功能，请重新输入" << endl;
      system("vifm-pause");
      system("clear");
      break;
    }
  }
  return 0;
}
