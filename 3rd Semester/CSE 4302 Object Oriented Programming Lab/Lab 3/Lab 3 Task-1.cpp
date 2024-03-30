#include<iostream>
using namespace std;

class Calculator
{
private:
    int x;
public:
    Calculator(void):x(0)
    {
    }
    Calculator(int value):x(value)
    {
    }
    int getValue(void)
    {
        return x;
    }
    void setValue(int value)
    {
        x = value;
    }
    void add(int value)
    {
        x = x+value;
    }
    void subtract(int value)
    {
        x = x-value;
    }
    void multiply(int value)
    {
        x = x*value;
    }
    void divide(int value)
    {
        x = x/value;
    }
    clear()
    {
        x=0;
    }
};


int main(void)
{
    Calculator my_calc(0);
    my_calc.add(10);
    cout<<my_calc.getValue()<<endl;
    my_calc.add(7);
    cout<<my_calc.getValue()<<endl;
    my_calc.multiply(31);
    cout<<my_calc.getValue()<<endl;
    my_calc.subtract(42);
    cout<<my_calc.getValue()<<endl;
    my_calc.divide(7);
    cout<<my_calc.getValue()<<endl;
    my_calc.add(3);
    cout<<my_calc.getValue()<<endl;
    my_calc.subtract(1);
    cout<<my_calc.getValue()<<endl;
    my_calc.clear();
    cout<<my_calc.getValue()<<endl;

    return 0;
}
