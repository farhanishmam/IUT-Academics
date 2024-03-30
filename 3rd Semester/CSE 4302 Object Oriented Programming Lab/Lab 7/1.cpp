#include<bits/stdc++.h>
using namespace std;

class People
{
protected:
    string name;
    double weight, age;
public:
    People(){}
    People(string n, double w, double a)
    {
        name = n;
        weight = w;
        age = a;
    }

    UpdateName(string n){name = n;}
    UpdateWeight(double w){weight = w;}
    Updateage(double a) {age = a;}
};

class Student : public People
{
    string ID, dept;
    double CGPA;
public:
    Student(){}

    Student(string n, double w, double a, string I, string d, double C) : People (n, w, a)
    {
        ID = I;
        dept = d;
        CGPA = C;
    }

    void UpdateID(string I) {ID = I;}
    void UpdateDept(string d) {dept = d;}
    void UpdateCGPA(double C) {CGPA = C;}

    void display()
    {
        cout << "Student Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Department: " << dept << endl;
        cout << "Weight: " << weight << endl;
        cout << "Age: " << age << endl << endl;
    }
};

class Teacher : public People
{
    string dept, RoomNo, PhoneNo;

public:
    Teacher(){}

    Teacher(string n, double w, double a, string d, string R, string P) : People(n, w, a)
    {
        dept = d;
        RoomNo = R;
        PhoneNo = P;
    }

    void UpdateDept(string d) {dept = d;}
    void UpdateRoom(string R) {RoomNo = R;}
    void UpdatePhone(string P) {PhoneNo = P;}

    void display()
    {
        cout << "Teacher Name: " << name << endl;
        cout << "Department Name: " << dept << endl;
        cout << "Room No: " << RoomNo << endl;
        cout << "Phone No: " << PhoneNo << endl;
        cout << "Weight: " << weight << endl;
        cout << "Age: " << age << endl << endl;
    }
};

int main()
{
    Student a("Nafis", 55, 21, "180041101", "CSE", 3.41);
    a.display();
    Teacher b("Faisal", 65, 26, "CSE", "412", "01812345678");
    b.display();

    b.UpdateRoom("322");
    b.display();
}
