#include <bits/stdc++.h>
#include<ctime>
using namespace std;

struct date_of_birth
{
    int day;
    int month;
    int year;
};

class Student
{
private:
    string name;
    struct date_of_birth db;
    int ID;
    float CGPA;
public:
    Student(void)
    {
        name = " ";
        db.day = 0;
        db.month = 0;
        db.year = 0;
        ID = 0;
        CGPA = 0.0;
    }
    setName(string a)
    {
        name = a;
    }
    const setDateOfBirth(int a, int b, int c)
    {
        db.day = a;
        db.month = b;
        db.year = c;
    }
    const setID(int a)
    {
        ID = a;
    }
    setCGPA(float a)
    {
        CGPA = a;
    }
    setInfo(string a, int d1,int d2, int d3, int c, float d)
    {
        setName(a);
        setDateOfBirth(d1,d2,d3);
        setID(c);
        setCGPA(d);
    }
    getName(void)
    {
        cout<<"The student name is: "<<name<<endl;
    }
    getDateOfBirth(void)
    {
        cout<<"The date of birth is: "<<db.day<<"-"<<db.month<<"-"<<db.year<<endl;
    }
    getID(void)
    {
        cout<<"The ID is "<<ID<<endl;
    }
    getCGPA(void)
    {
        cout<<"The CGPA is "<<CGPA<<endl;
    }
    getInfo()
    {
        getName();
        getDateOfBirth();
        getID();
        getCGPA();
    }
    void getAge(int a, int b, int c)
    {

        struct date_of_birth today;
        today.day = a;
        today.month = b;
        today.year = c;
        int age = today.year - db.year;
        if(today.month < db.month)
        {
            age--;
        }
        else if(today.month == db.month)
        {
            if(today.day<db.day)
            {
                age--;
            }
        }
        cout<<age<<endl;
    }
    int getAge(void)
    {
        struct date_of_birth today;
        time_t now = time(0);

        tm *ltm = localtime(&now);
        today.year = 1900 + ltm->tm_year;
        today.month = 1 + ltm->tm_mon;
        today.day = ltm->tm_mday;
        int age = today.year - db.year;
        if(today.month < db.month)
        {
            age--;
        }
        else if(today.month == db.month)
        {
            if(today.day<db.day)
            {
                age--;
            }
        }
        cout<<age<<endl;
    }

};
int main(void)
{
    Student s1;
    s1.setInfo("Farhan",22,1,2000,20,4.00);
    s1.getInfo();
    s1.getAge(21,01,2020);
    s1.getAge();
    //https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm


    return 0;

}