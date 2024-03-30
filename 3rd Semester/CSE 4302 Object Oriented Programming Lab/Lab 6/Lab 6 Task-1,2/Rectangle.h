//
// Created by Farhan Ishmam on 10-Feb-20.
//
#include <iostream>
#include <math.h>
#ifndef UNTITLED16_RECTANGLE_H
#define UNTITLED16_RECTANGLE_H
using namespace std;


class Rectangle{

private:
    int length;
    int width;
public:
    void check(int n)
    {
        if(n<0)
        {
            cout<<"Error"<<endl;
            exit(1);
        }

    }
    Rectangle(void)
    {
        set_length(0);
        set_width(0);
    }
    Rectangle(int l, int w)
    {
        set_length(l);
        set_width(w);
    }
    void set_length(int l)
    {
        check(l);
        length = l;
    }
    void set_width(int w)
    {
        check(w);
        width = w;
    }
    int get_length()
    {
        return length;
    }
    int get_width()
    {
        return width;
    }
    int calc_perimeter(void)
    {
        return 2*(length+width);
    }
    double diagonal_length(void)
    {
        double dl = sqrt(static_cast<double>(length*length)+ static_cast<double>(width,width));
        return dl;
    }
    int calc_area(void)
    {
        return length*width;
    }
    Rectangle operator ++ ()
    {
        length = length+1;
        width = width+1;
        Rectangle r1(length,width);
        return r1;
    }
    Rectangle operator ++ (int)
    {
        Rectangle r1(length,width);
        length = length+1;
        width = width+1;
        return r1;
    }
    Rectangle operator -- ()
    {
        length = length-1;
        width = width-1;
        Rectangle r1(length,width);
        return r1;
    }
    Rectangle operator -- (int)
    {
        Rectangle r1(length,width);
        length = length-1;
        width = width-1;
        return r1;
    }
    Rectangle operator + (Rectangle rec1)
    {
        Rectangle r_out(rec1.length+length,rec1.width+width);
        return r_out;
    }
    int operator ==(Rectangle rec1)
    {
        if(rec1.calc_area()==calc_area()) return 1;
        else return 0;
    }
    int operator >(Rectangle rec1)
    {
        if(rec1.calc_area()<calc_area()) return 1;
        else return 0;
    }
    int operator <(Rectangle rec1)
    {
        if(rec1.calc_area()>calc_area()) return 1;
        else return 0;
    }

};


#endif //UNTITLED16_RECTANGLE_H
