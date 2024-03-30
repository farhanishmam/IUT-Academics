#ifndef UNTITLED17_TAKA_H
#define UNTITLED17_TAKA_H

#include <iostream>
using namespace std;

class TAKA{
private:
    int one;
    int two;
    int five;
    int ten;
    int twenty;
public:
    void check(int n)
    {
        if(n<0)
        {
            cout<<"Error"<<endl;
            exit(1);
        }
    }
    TAKA()
    {
        set_one(0);
        set_five(0);
        set_two(0);
        set_ten(0);
        set_twenty(0);
    }
    void set_one(int n)
    {
        check(n);
        one = n;
    }
    void set_two(int n)
    {
        check(n);
        two = n;
    }
    void set_five(int n)
    {
        check(n);
        five = n;
    }
    void set_ten(int n)
    {
        check(n);
        ten = n;
    }
    void set_twenty(int n)
    {
        check(n);
        twenty = n;
    }
    int get_one(void)
    {
        return one;
    }
    int get_two(void)
    {
        return two;
    }
    int get_five(void)
    {
        return five;
    }
    int get_ten(void)
    {
        return ten;
    }
    int get_twenty(void)
    {
        return twenty;
    }
    int get_taka(void)
    {
        int total = get_one()+get_two()*2+get_five()*5+get_ten()+10+get_twenty()*20;
        return total;
    }
    int operator ==(TAKA t1)
    {
        if(get_taka()==t1.get_taka())
            return 1;
        else return 0;
    }
    int operator <(TAKA t1)
    {
        if(get_taka()<t1.get_taka())
            return 1;
        else return 0;
    }
    int operator >(TAKA t1)
    {
        if(get_taka()>t1.get_taka())
            return 1;
        else return 0;
    }
    TAKA operator +(TAKA t1)
    {
        TAKA out;
        out.set_one(t1.get_one()+one);
        out.set_two(t1.get_two()+two);
        out.set_five(t1.get_five()+five);
        out.set_ten(t1.get_ten()+ten);
        out.set_twenty(t1.get_twenty()+twenty);
        return out;
    }
    TAKA operator -(TAKA t1)
    {
        TAKA out;
        check(one - t1.get_one());
        out.set_one(one - t1.get_one());

        check(two-t1.get_two());
        out.set_two(two-t1.get_two());

        check(five-t1.get_five());
        out.set_five(five-t1.get_five());

        check(ten-t1.get_ten());
        out.set_ten(ten-t1.get_ten());

        check(twenty-t1.get_twenty());
        out.set_twenty(twenty-t1.get_twenty());

        return out;
    }

};


#endif //UNTITLED17_TAKA_H
