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

    string GetName(){return name;}
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

    string GetID(){return ID;}

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

//    string

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
    Student s[3];
    Teacher t[3];

    s[0] = Student("Nafis", 55, 21, "180041101", "CSE", 3.41);
    s[1] = Student("Faiyaz", 60, 20, "180031102", "EEE", 3.56);
    s[2] = Student("Mohammad", 55, 20, "170021234", "CEE", 3.77);

    t[0] = Teacher("Faisal", 65, 26, "CSE", "412", "01812345678");

    int type, flag;
    cout << "Enter Search Type\n1. Student    2. Teacher\n";
    cin >> type;

    if(type == 1)
    {
        system ("CLS");
        cout << "---Searching Student---" << endl;
        cout << "1. ID    2.Name\n";
        cin >> type;
        if(type == 1)
        {
            string I;
            flag = 0;
            cout << "Enter ID: ";
            cin >> I;
            for(int i = 0; i < 3; i++)
            {
                if(I == s[i].GetID())
                {
                    flag = 1;
                    cout << endl << "Match Found" << endl << endl;
                    s[i].display();
                    break;
                }
            }

            if(!flag)
                cout << "No Match\n";
        }
        else if(type == 2)
        {
            string n;
            flag = 0;
            cout << "Enter Name: ";
            cin >> n;
            for(int i = 0; i < 3; i++)
            {
                if(n == s[i].GetName())
                {
                    cout << endl << "Match Found" << endl << endl;
                    s[i].display();
                    break;
                }
            }

            if(!flag)
                cout << "No Match\n";
        }
        else
            cout << "Invalid" << endl;

    }//search student ends

    else if(type == 2)
    {
        system("CLS");
        cout << "---Searching Teacher---" << endl;
        string n;
        flag = 0;
        cout << "Enter Name: ";
        cin >> n;
        for(int i = 0; i < 3; i++)
        {
            if(n == t[i].GetName())
            {
                cout << endl << "Match Found" << endl << endl;
                t[i].display();
                break;
            }
        }

        if(!flag)
            cout << "No Match\n";
    }//searching teacher ends

    else
        cout << "Invalid";
}
