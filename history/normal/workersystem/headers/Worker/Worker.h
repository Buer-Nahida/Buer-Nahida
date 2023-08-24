#pragma once
#include "../headers.h"

class Worker {
public:
  virtual void ShowInfo() = 0;

  unsigned long long m_ID;
  short m_DeptID;
  string m_Name;

protected:
  virtual string GetDeptName() = 0;
};
