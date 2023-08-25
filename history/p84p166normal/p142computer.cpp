#include <iostream>
using namespace std;

class CPU {
public:
  virtual void calc() = 0;
};
class Memory {
public:
  virtual void cache() = 0;
};
class Disk {
public:
  virtual void storage() = 0;
};
class GPU {
public:
  virtual void show() = 0;
};

class IntelCPU : public CPU {
public:
  virtual void calc() { cout << "Intel CPU working.." << endl; }
};
class IntelGPU : public GPU {
public:
  virtual void show() { cout << "Intel GPU working.." << endl; }
};
class IntelDisk : public Disk {
public:
  virtual void storage() { cout << "Intel Disk working.." << endl; }
};
class IntelMemory : public Memory {
public:
  virtual void cache() { cout << "Intel Memory working.." << endl; }
};

class AMDCPU : public CPU {
public:
  virtual void calc() { cout << "AMD CPU working.." << endl; }
};
class AMDGPU : public GPU {
public:
  virtual void show() { cout << "AMD GPU working.." << endl; }
};

class NvidiaGPU : public GPU {
public:
  virtual void show() { cout << "Nvidia GPU working.." << endl; }
};

class Computer {
public:
  Computer(CPU *CPU, GPU *GPU, Disk *Disk, Memory *Memory) {
    computerCPU = CPU;
    computerGPU = GPU;
    computerDisk = Disk;
    computerMemory = Memory;
  }
  void ComputerWork() {
    computerCPU->calc();
    computerGPU->show();
    computerDisk->storage();
    computerMemory->cache();
  }
  CPU *computerCPU;
  GPU *computerGPU;
  Disk *computerDisk;
  Memory *computerMemory;
  ~Computer() {
    if (computerCPU != NULL) {
      free(computerCPU);
      computerCPU = NULL;
    }
    if (computerGPU != NULL) {
      free(computerGPU);
      computerGPU = NULL;
    }
    if (computerDisk != NULL) {
      free(computerDisk);
      computerDisk = NULL;
    }
    if (computerMemory != NULL) {
      free(computerMemory);
      computerMemory = NULL;
    }
  }
};

int main(int argc, char *argv[]) {
  Computer A(new IntelCPU, new NvidiaGPU, new IntelDisk, new IntelMemory);
  A.ComputerWork();
  Computer B(new IntelCPU, new IntelGPU, new IntelDisk, new IntelMemory);
  B.ComputerWork();
  Computer C(new IntelCPU, new NvidiaGPU, new IntelDisk, new IntelMemory);
  C.ComputerWork();
  return 0;
}
