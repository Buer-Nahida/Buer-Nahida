#include "WorkerManager.h"

WorkerManager::WorkerManager() {
  this->m_fin.open(FILENAME);

  if (this->m_fin.is_open()) {
    char readTemp;
    this->m_fin >> readTemp;
  }
  if (!this->m_fin.is_open() || this->m_fin.eof()) {
    this->m_FileIsEmpty = true;
    this->m_WorkerNum = 0;
    this->m_WorkerArray = NULL;
    this->m_fin.close();
    return;
  }
  this->m_fin.close();

  this->m_FileIsEmpty = false;
  this->m_WorkerNum = this->GetWorkerNum();
  this->m_WorkerArray = new Worker *[this->m_WorkerNum];
  this->InitWorkerArray();
}

long long WorkerManager::GetWorkerNum() {
  this->m_fin.open(FILENAME);

  long long workerID, workerNum = 0;
  short workerDeptID;
  string workerName;

  while (this->m_fin >> workerID >> workerName >> workerDeptID) {
    workerNum++;
  }

  this->m_fin.close();
  return workerNum;
}

void WorkerManager::InitWorkerArray() {
  this->m_fin.open(FILENAME);
  long long workerID, arrayIndex = 0;
  string workerName;
  short workerDeptID;
  while (this->m_fin >> workerID >> workerName >> workerDeptID) {
    if (workerDeptID == 1) {
      this->m_WorkerArray[arrayIndex] =
          new EmployeeWorker(workerID, workerName, 1);
    } else if (workerDeptID == 2) {
      this->m_WorkerArray[arrayIndex] =
          new ManagerWorker(workerID, workerName, 2);
    } else {
      this->m_WorkerArray[arrayIndex] = new BossWorker(workerID, workerName, 3);
    }
    arrayIndex++;
  }
  this->m_fin.close();
}

WorkerManager::~WorkerManager() { this->DeleteWorkerArray(); }
