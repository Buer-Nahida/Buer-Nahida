#include "WorkerManager.h"

void WorkerManager::ShowMenu() {
  cout << "************************" << endl
       << "****** 0.退出管理 ******" << endl
       << "****** 1.新增职工 ******" << endl
       << "****** 2.所有职工 ******" << endl
       << "****** 3.删除职工 ******" << endl
       << "****** 4.修改职工 ******" << endl
       << "****** 5.查找职工 ******" << endl
       << "****** 6.排序职工 ******" << endl
       << "****** 7.清空职工 ******" << endl
       << "************************" << endl
       << endl
       << "请选择：";
}

void WorkerManager::ExitSystem() {
  cout << "欢迎下次使用" << endl;
  this->PauseClear();
  exit(0);
}
