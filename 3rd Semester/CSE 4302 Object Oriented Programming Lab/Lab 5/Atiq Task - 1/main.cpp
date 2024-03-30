#include <iostream>
#include"DB.h"
#include"DM.h"

using namespace std;
int add_dist(int f,DM b,DB a)
{
    if(f==1)
    {
        double w,x,y,z;
        w = a.Getfeet();
        x = a.Getinches();
        y = b.Getmeter();
        z = b.Getcenti();
        w = w+(x/12);
        w = w/3;
        z = z+(w*100);
        z = z+(y*100);
        return (z);
    }
    else if(f==2)
    {
        double w,x,y,z;
        w = a.Getfeet();
        x = a.Getinches();
        y = b.Getmeter();
        z = b.Getcenti();
        y = y+(z/100);
        y = y*3;
        y = y*12;
        x = y+x;
        x = x+(w*12);
        return x;
    }
}
int main()
{
    DB a;
    double w=5,x=35,y=6,z=111;

    a.Setfeet(w);
    a.Setinches(x);
    DM b;
    b.Setmeter(y);
    b.Setcenti(z);
    cout<<"input 1 for DM and 2 for DB:"<<endl;
    int f;
    cin>>f;
    if(f==1)
    {
        b.Setmeter(add_dist(f,b,a)/100);
        b.Setcenti(add_dist(f,b,a)%100);
        cout<<b.Getmeter()<<endl;
        cout<<b.Getcenti()<<endl;
    }
    else if(f==2)
    {
        a.Setfeet(add_dist(f,b,a)/12);
        a.Setinches(add_dist(f,b,a)%12);
        cout<<a.Getfeet()<<endl;
        cout<<a.Getinches()<<endl;
    }
    return 0;
}
