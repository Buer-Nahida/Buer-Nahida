#include "EmployeeWorker.h"

EmployeeWorker::EmployeeWorker(int id, string name, int deptID) {
  this->m_ID = id;
  this->m_Name = name;
  this->m_DeptID = deptID;
}
void EmployeeWorker::ShowInfo() {
  cout << this->m_ID << "\t\t" << this->m_Name << "\t\t" << this->GetDeptName()
       << "\t\t完成经理交给的任务" << endl;
}
string EmployeeWorker::GetDeptName() { return "员工"; }
EmployeeWorker::~EmployeeWorker() {}
