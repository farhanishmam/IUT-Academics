#include <bits/stdc++.h>
using namespace std;

class SavingsAccount
{
private:
    static float annualInterestRate;
    float savingsBalance;


public:
    static int count_created;
    static int count_destroyed;
    SavingsAccount(float n)
    {
        savingsBalance = n;
        count_created++;
    }
    void calculateMonthlyInterest(void)
    {
        savingsBalance += (savingsBalance*annualInterestRate)/12;
    }
    static void modifyInterestRate(float f)
    {
        annualInterestRate = f/100;
    }
    void display(void)
    {
        cout<<"Savings Balance is "<<savingsBalance<<endl;
    }
    ~SavingsAccount()
    {
        count_destroyed++;
        cout<<"The number of objects destroyed is "<<count_destroyed<<endl;
    }
};
float SavingsAccount::annualInterestRate = 0.0;
int SavingsAccount::count_created = 0;
int SavingsAccount::count_destroyed = 0;
int main(void)
{
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);
    SavingsAccount::modifyInterestRate(3.0);
    saver1.calculateMonthlyInterest();
    saver1.display();
    saver2.calculateMonthlyInterest();
    saver2.display();

    SavingsAccount::modifyInterestRate(4.0);
    saver1.calculateMonthlyInterest();
    saver1.display();
    saver2.calculateMonthlyInterest();
    saver2.display();

    cout<<"The number of objects created is "<<SavingsAccount::count_created<<endl;

    return 0;
}