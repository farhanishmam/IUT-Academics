#include <iostream>
#include "TAKA.h"
int main(void) {
    TAKA t1,t2;
    if(t1==t2) cout<<"YES"<<endl;
    t1.set_one(2);
    t2.set_one(4);
    TAKA t3 = t1+t2;
    cout<<t3.get_one();
}