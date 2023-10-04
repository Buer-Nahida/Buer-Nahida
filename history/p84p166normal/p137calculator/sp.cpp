#include <cmath>
#include <iostream>
using namespace std;

class Calc {
public:
    double c_Number0, c_Number1;
    virtual double getResult() { return 0; }
};

class Add : public Calc {
public:
    virtual double getResult() { return c_Number0 + c_Number1; }
};

class Sub : public Calc {
public:
    virtual double getResult() { return c_Number0 - c_Number1; }
};

class Mul : public Calc {
public:
    virtual double getResult() { return c_Number0 - c_Number1; }
};

double calc(double Num0, double Num1, Calc *Type) {
    Type->c_Number0 = Num0;
    Type->c_Number1 = Num1;
    return Type->getResult();
}

int main(int argc, char *argv[]) {
    calc(10, 10, new Add);
    return 0;
}
