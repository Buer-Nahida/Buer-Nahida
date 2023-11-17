#include "BossWorker.h"

BossWorker::BossWorker(int id, string name, int deptID) {
  this->m_ID = id;
  this->m_Name = name;
  this->m_DeptID = deptID;
}
void BossWorker::ShowInfo() {
  cout << this->m_ID << "\t\t" << this->m_Name << "\t\t" << this->GetDeptName()
       << "\t\t管理公司所有事务" << endl;
}
string BossWorker::GetDeptName() { return "老板"; }
BossWorker::~BossWorker() {}
