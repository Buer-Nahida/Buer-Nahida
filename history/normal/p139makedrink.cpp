#include <iostream>
using namespace std;

class MakeJuice {
public:
  virtual void Boil() = 0;
  virtual void Brew() = 0;
  virtual void PourInCup() = 0;
  virtual void PutSomeInJuice() = 0;
};
class Cofe : public MakeJuice {
public:
  virtual void Boil() { cout << "煮水" << endl; }
  virtual void Brew() { cout << "冲咖啡" << endl; }
  virtual void PourInCup() { cout << "到入杯中" << endl; }
  virtual void PutSomeInJuice() { cout << "加糖和牛奶" << endl; };
};
class Tea : public MakeJuice {
public:
  virtual void Boil() { cout << "煮水" << endl; }
  virtual void Brew() { cout << "冲茶叶" << endl; }
  virtual void PourInCup() { cout << "到入杯中" << endl; }
  virtual void PutSomeInJuice() { cout << "加柠檬" << endl; };
};

void Make(MakeJuice *JuiceName) {
  JuiceName->Boil();
  JuiceName->Brew();
  JuiceName->PourInCup();
  JuiceName->PutSomeInJuice();
  delete JuiceName;
  JuiceName = NULL;
}

int main(int argc, char *argv[]) {
  Make(new Tea);
  return 0;
}
