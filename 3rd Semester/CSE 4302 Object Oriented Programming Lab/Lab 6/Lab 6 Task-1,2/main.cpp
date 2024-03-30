#include <iostream>
#include "Rectangle.h"
int main() {
    Rectangle r1(2,3);
    cout<<r1.get_length()<<" "<<r1.get_width()<<endl;

    cout<<r1.calc_area()<<endl;
    cout<<r1.diagonal_length()<<endl;
    cout<<r1.calc_perimeter()<<endl;

    Rectangle s1,s2(5,3);
    Rectangle s3 = ++s1;
    Rectangle s4 = s1++;

    s3 = --s2;
    s4 = s2--;
    s4 = s1+s2;
    if(s4 == s1+s2)
        cout<<"Area is same";
    else if(s4 > s1+s2)
        cout<<"LHS has bigger area";
    else if(s4 < s1+s2)
        cout<<"RHS has bigger area";
    return 0;

}