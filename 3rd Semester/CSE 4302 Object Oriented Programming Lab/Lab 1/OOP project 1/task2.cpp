#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string name;
    string date_of_birth;
    int ID;
    float CGPA;
public:
    Student(void)
    {
        name = " ";
        date_of_birth = " ";
        ID = 0;
        CGPA = 0.0;
    }
    setName(string a)
    {
        name = a;
    }
    setDateOfBirth(string a)
    {
        date_of_birth = a;
    }
    setID(int a)
    {
        ID = a;
    }
    setCGPA(float a)
    {
        CGPA = a;
    }
    setInfo(string a, string b, int c, float d)
    {
        setName(a);
        setDateOfBirth(b);
        setID(c);
        setCGPA(d);
    }
    getName(void)
    {
        cout<<"The student name is: "<<name<<endl;
    }
    getDateOfBirth(void)
    {
        cout<<"The date of birth is: "<<date_of_birth<<endl;
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
};
int main(void)
{

}