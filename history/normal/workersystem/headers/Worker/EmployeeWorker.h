#pragma once
#include "../headers.h"
#include "Worker.h"

class EmployeeWorker : public Worker {
public:
  EmployeeWorker(int id, string name, int deptID);
  virtual void ShowInfo();
  ~EmployeeWorker();

protected:
  virtual string GetDeptName();
};
