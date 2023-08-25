#include "WorkerManager.h"

void WorkerManager::AddSomeWorker() {
  this->m_fout.open(FILENAME, ios::app);

  long long addQuantity;
  cout << "添加员工个数:";
  cin >> addQuantity;

  if (addQuantity > 0) {
    long long newSize = this->m_WorkerNum + addQuantity;
    Worker **newSpace = new Worker *[newSize];

    if (this->m_WorkerArray != NULL) {
      for (long long index = 0; index < this->m_WorkerNum; index++) {
        newSpace[index] = this->m_WorkerArray[index];
      }
    }

    for (long long index = this->m_WorkerNum, count = 1; index < newSize;
         index++, count++) {
      AddWorker(index, newSpace, count);
    }

    if (this->m_WorkerArray != NULL) {
      delete[] this->m_WorkerArray;
    }

    this->m_WorkerArray = newSpace;
    this->m_WorkerNum = newSize;
    this->m_FileIsEmpty = false;

    cout << "成功添加" << addQuantity << "名新员工!" << endl;
  } else {
    cout << "输入有误" << endl;
  }

  this->m_fout.close();
  this->PauseClear();
}

void WorkerManager::ShowWorker() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或为空" << endl;
    this->PauseClear();
    return;
  }
  cout << "员工编号\t"
       << "员工姓名\t"
       << "员工职位\t"
       << "员工任务" << endl
       << "------------------------------------------------------------------"
          "------------------------------------------------------------------"
       << endl;
  for (long long index = 0; index < this->m_WorkerNum; index++) {
    this->m_WorkerArray[index]->ShowInfo();
  }
  this->PauseClear();
}

void WorkerManager::DeleteWorker() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或为空" << endl;
    this->PauseClear();
    return;
  }

  long long userSelectID;
  cout << "请输入员工的编号:";
  cin >> userSelectID;
  long long arrayIndex = this->IsExist(userSelectID);

  if (arrayIndex == -1) {
    cout << "此员工不存在" << endl;
    this->PauseClear();
    return;
  }

  cout << "员工编号\t"
       << "员工姓名\t"
       << "员工职位\t"
       << "员工任务" << endl
       << "----------------------------------------------------------------"
          "--"
          "----------------------------------------------------------------"
          "--"
       << endl;
  this->m_WorkerArray[arrayIndex]->ShowInfo();
  cout << "你确定要删除此员工吗?(y/N)";
  char isDelete;
  cin >> isDelete;

  if (isDelete == 'y' || isDelete == 'Y') {
    free(this->m_WorkerArray[arrayIndex]);
    for (; arrayIndex < this->m_WorkerNum - 1; arrayIndex++) {
      this->m_WorkerArray[arrayIndex]->m_ID =
          this->m_WorkerArray[arrayIndex + 1]->m_ID;
      this->m_WorkerArray[arrayIndex]->m_Name =
          this->m_WorkerArray[arrayIndex + 1]->m_Name;
      this->m_WorkerArray[arrayIndex]->m_DeptID =
          this->m_WorkerArray[arrayIndex + 1]->m_DeptID;
    }

    this->m_WorkerNum--;
    SaveFile();

    if (this->m_WorkerNum <= 0) {
      this->m_FileIsEmpty = true;
    }

    cout << "删除成功" << endl;
  } else {
    cout << "取消删除" << endl;
  }
  this->PauseClear();
}

void WorkerManager::ChangeWorker() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或为空" << endl;
    this->PauseClear();
    return;
  }

  long long userSelectID;
  cout << "请输入员工的编号:";
  cin >> userSelectID;
  long long arrayIndex = this->IsExist(userSelectID);

  if (arrayIndex == -1) {
    cout << "此员工不存在" << endl;
    this->PauseClear();
    return;
  }

  cout << "员工编号\t"
       << "员工姓名\t"
       << "员工职位\t"
       << "员工任务" << endl
       << "----------------------------------------------------------------"
          "--"
          "----------------------------------------------------------------"
          "--"
       << endl;

  this->m_WorkerArray[arrayIndex]->ShowInfo();
  cout << "你确定要修改此员工的信息吗?(y/N)";
  char isChange;
  cin >> isChange;

  if (isChange == 'y' || isChange == 'Y') {
    while (1) {
      cout << "请输入你要修改的属性(1.ID 2.名字 3.职位):";
      long long select;
      cin >> select;

      if (select == 1) {
        cout << "新的ID:";
        while (1) {
          long long newID;
          cin >> newID;
          if (this->IsExist(newID) == -1) {
            this->m_WorkerArray[arrayIndex]->m_ID = newID;
            cout << "修改成功" << endl;
            break;
          } else {
            cout << "已有重复ID,请重新输入:";
          }
        }
        break;

      } else if (select == 2) {
        cout << "新的名字:";
        cin >> this->m_WorkerArray[arrayIndex]->m_Name;
        cout << "修改成功" << endl;
        break;

      } else if (select == 3) {
        Worker *newWorker;

        while (1) {
          long long userSelect;

          cout << endl
               << "1.员工" << endl
               << "2.经理" << endl
               << "3.老板" << endl
               << "新的职位:";
          cin >> userSelect;

          if (userSelect == 1) {
            newWorker =
                new EmployeeWorker(this->m_WorkerArray[arrayIndex]->m_ID,
                                   this->m_WorkerArray[arrayIndex]->m_Name, 1);
            break;
          } else if (userSelect == 2) {
            newWorker =
                new ManagerWorker(this->m_WorkerArray[arrayIndex]->m_ID,
                                  this->m_WorkerArray[arrayIndex]->m_Name, 2);
            break;
          } else if (userSelect == 3) {
            newWorker =
                new BossWorker(this->m_WorkerArray[arrayIndex]->m_ID,
                               this->m_WorkerArray[arrayIndex]->m_Name, 3);
            break;
          } else {
            cout << "暂无此职位,请重新输入" << endl << endl;
          }
        }
        free(this->m_WorkerArray[arrayIndex]);
        this->m_WorkerArray[arrayIndex] = newWorker;
        cout << "修改成功" << endl;
        break;
      }
    }
  } else {
    cout << "取消修改" << endl;
  }
  SaveFile();
  this->PauseClear();
}

void WorkerManager::FindWorker() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或为空" << endl;
    this->PauseClear();
    return;
  }

  long long select;
  cout << "查找方式(1.编号(默认) 2.名字):";
  cin >> select;
  if (select == 2) {
    string userSelectName;
    cout << "请输入员工的名字:";
    cin >> userSelectName;
    this->IsExistName(userSelectName);

  } else {
    long long userSelectID;
    cout << "请输入员工的编号:";
    cin >> userSelectID;
    long long arrayIndex = this->IsExist(userSelectID);

    if (arrayIndex == -1) {
      cout << "此员工不存在" << endl;
      this->PauseClear();
      return;
    } else {
      cout << "员工编号\t"
           << "员工姓名\t"
           << "员工职位\t"
           << "员工任务" << endl
           << "----------------------------------------------------------------"
              "--"
              "----------------------------------------------------------------"
              "--"
           << endl;
      this->m_WorkerArray[arrayIndex]->ShowInfo();
    }
  }
  this->PauseClear();
}

void WorkerManager::SortWorker() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或为空" << endl;
    this->PauseClear();
    return;
  }
  cout << "是否升序排列(y/N):";
  string userSelect;
  cin >> userSelect;
  if (userSelect == "y" || userSelect == "Y") {
    this->SelectSort(true);
    this->SaveFile();
  } else {
    this->SelectSort(false);
    this->SaveFile();
  }
  cout << "排序成功" << endl;
  this->PauseClear();
  return;
}

void WorkerManager::ClearFile() {
  cout << "你正在执行危险操作，是否继续(yes/No):";
  string userYesOrNo;
  cin >> userYesOrNo;
  if (userYesOrNo == "yes") {
    this->m_fout.open(FILENAME, ios::trunc);
    this->m_fout.close();
    this->DeleteWorkerArray();
    this->m_FileIsEmpty = true;
    this->m_WorkerNum = 0;
    cout << "已完成" << endl;
  } else {
    cout << "取消清空" << endl;
  }
  this->PauseClear();
}
