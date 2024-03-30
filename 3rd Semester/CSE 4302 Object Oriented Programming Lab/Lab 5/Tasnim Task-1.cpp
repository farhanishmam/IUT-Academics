#include <bits/stdc++.h>
using namespace std;

class DM
{
private:
    int meter;
    double centimeter;
public:
    int Getmeter() { return meter; }
    double Getcentimeter() { return centimeter; }
    void Setcentimeter(double val) { centimeter = val; }
    void Setmeter(int val) { meter= val; }
    DM():meter(0),centimeter(0){}
};

class DB
{
private:
    int feet;
    double inches;
public:
    int Getfeet() { return feet; }
    void Setfeet(int val) { feet = val; }
    double Getinches() { return inches; }
    void Setinches(double val) { inches = val; }
    DB():feet(0),inches(0){}

};

void add(int m, int cm, int ft, int in)
{
    int n,d1;
    double d,d2;
    cout << "Choose:\n\t1. Metric\n\t2. Imperial\nChoice: ";
    cin>>n;
    d=m+cm/100+0.0254*in+0.3048*ft;
    if(n==1)
    {
        d1=d;
        d2=(d-d1)*100;
        cout << "Distance: " << d1 << "m " << d2 << "cm\n";
    }
    else if(n==2)
    {
        d*=3.28024;
        d1=d;
        d2=(d-d1)*12;
        cout << "Distance: " << d1 << "' " << d2 << '"'<<"\n";
    }
}
int main()
{
    DM dm1;
    DB db1;
    int n,val;
    double val1;
    cout << "Choose:\n\t1. Metric\n\t2. Imperial\n\t3. Add\n\t4. Exit\n";
    while (1)
    {
        cout << "Choice: ";
        cin>>n;
        if(n==1)
        {
            cout << "Distance in meters: ";
            cin >> val1;
            val=val1;
            dm1.Setm(val);
            val1-=val;
            val1*=100;
            dm1.Setcm(val1);
        }
        else if(n==2)
        {
            cout<<"Distance in feet: ";
            cin >> val1;
            val=val1;
            db1.Setft(val);
            val1-=val;
            val1*=12;
            db1.Setin(val1);
        }
        else if(n==3)
        {
            adddist(dm1.Getm(),dm1.Getcm(),db1.Getft(),db1.Getin());
        }
        else if(n==4)
            break;
        else
            cout<<"Error\n\n";
    }
    return 0;
}