#pragma once
#include "../headers.h"
#include "Worker.h"

class ManagerWorker : public Worker {
public:
  ManagerWorker(int id, string name, int deptID);
  virtual void ShowInfo();
  ~ManagerWorker();

protected:
  virtual string GetDeptName();
};
