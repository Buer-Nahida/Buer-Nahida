#include "ManagerWorker.h"

ManagerWorker::ManagerWorker(int id, string name, int deptID) {
  this->m_ID = id;
  this->m_Name = name;
  this->m_DeptID = deptID;
}
void ManagerWorker::ShowInfo() {
  cout << this->m_ID << "\t\t" << this->m_Name << "\t\t" << this->GetDeptName()
       << "\t\t完成老板交给的任务，并下发任务给员工" << endl;
}
string ManagerWorker::GetDeptName() { return "经理"; }
ManagerWorker::~ManagerWorker() {}
