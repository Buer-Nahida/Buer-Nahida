#include "WorkerManager.h"

void WorkerManager::PauseClear() {
  system("~/test/history/normal/workersystem/headers/pause");
  system("clear");
}

void WorkerManager::SaveFile() {
  this->m_fout.open(FILENAME);
  for (long long arrayIndex = 0; arrayIndex < this->m_WorkerNum; arrayIndex++) {
    this->m_fout << this->m_WorkerArray[arrayIndex]->m_ID << " "
                 << this->m_WorkerArray[arrayIndex]->m_Name << " "
                 << this->m_WorkerArray[arrayIndex]->m_DeptID << endl;
  }
  this->m_fout.close();
}

void WorkerManager::AddWorker(long long arrayIndex, Worker **workerArray,
                              long long count) {

  cout << "请输入第" << count << "个员工的编号:";
  long long workerID;
  while (1) {
    cin >> workerID;
    if (this->IsExist(workerID) == -1) {
      break;
    } else {
      cout << "已有重复ID,请重新输入:";
    }
  }

  cout << "请输入第" << count << "个员工的名称:";
  string workerName;
  cin >> workerName;

  cout << "请选择第" << count << "个员工的职位";
  while (1) {
    long long userSelect;

    cout << endl
         << "1.员工" << endl
         << "2.经理" << endl
         << "3.老板" << endl
         << "请输入:";
    cin >> userSelect;

    if (userSelect == 1) {
      workerArray[arrayIndex] = new EmployeeWorker(workerID, workerName, 1);
      break;
    } else if (userSelect == 2) {
      workerArray[arrayIndex] = new ManagerWorker(workerID, workerName, 2);
      break;
    } else if (userSelect == 3) {
      workerArray[arrayIndex] = new BossWorker(workerID, workerName, 3);
      break;
    } else {
      cout << "暂无此职位,请重新输入" << endl << endl;
    }
  }
  this->m_fout << workerArray[arrayIndex]->m_ID << " "
               << workerArray[arrayIndex]->m_Name << " "
               << workerArray[arrayIndex]->m_DeptID << endl;
}

long long WorkerManager::IsExist(long long ID) {
  for (long long i = 0; i < this->m_WorkerNum; i++) {
    if (this->m_WorkerArray[i]->m_ID == ID) {
      return i;
    }
  }
  return -1;
}

void WorkerManager::IsExistName(string name) {
  cout << "员工编号\t"
       << "员工姓名\t"
       << "员工职位\t"
       << "员工任务" << endl
       << "----------------------------------------------------------------"
          "--"
          "----------------------------------------------------------------"
          "--"
       << endl;
  bool findFlag = false;
  for (long long i = 0; i < this->m_WorkerNum; i++) {
    if (this->m_WorkerArray[i]->m_Name == name) {
      this->m_WorkerArray[i]->ShowInfo();
      findFlag = true;
    }
  }
  if (!findFlag) {
    cout << "此员工不存在" << endl;
  }
}

void WorkerManager::SelectSort(bool AscendingSort) {
  long long Index = 0;
  for (long long Count0 = 0; Count0 < this->m_WorkerNum; Count0++) {
    long long minOrMax = Count0;
    for (long long Count1 = Index; Count1 < this->m_WorkerNum; Count1++) {
      if (AscendingSort) {
        minOrMax = (this->m_WorkerArray[minOrMax]->m_ID >
                    this->m_WorkerArray[Count1]->m_ID)
                       ? Count1
                       : minOrMax;
      } else {
        minOrMax = (this->m_WorkerArray[minOrMax]->m_ID <
                    this->m_WorkerArray[Count1]->m_ID)
                       ? Count1
                       : minOrMax;
      }
    }
    if (Count0 != minOrMax) {
      swap(this->m_WorkerArray[minOrMax], this->m_WorkerArray[Count0]);
    }
    Index++;
  }
}
