#pragma once
#include "../headers.h"
#include "Worker.h"

class BossWorker : public Worker {
public:
  BossWorker(int id, string name, int deptID);
  virtual void ShowInfo();
  ~BossWorker();

protected:
  virtual string GetDeptName();
};
