#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    string contact_no;
    char* password;
public:
    Person()
    {
        set_name("");
        set_contactno("");
        password = new char[8];
    }
    Person(string val_name, string val_cont)
    {
        set_name(val_name);
        set_contactno(val_cont);
        password = new char[8];
    }
    void set_name(string val)
    {
        name = val;
    }
    void set_contactno(string val)
    {
        contact_no = val;
    }
    void set_password(char* val)
    {
        password = val;
    }
    string get_name(void)
    {
        return name;
    }
    string get_contactno(void)
    {
        return contact_no;
    }
    char* get_password(void)
    {
        return password;
    }
    ~Person()
    {
        delete password;
    }
    virtual void display_info() = 0;
};

class Student:virtual public Person
{
protected:
    string student_id;
    string program;
public:
    Student()
    {
        set_id("0");
        set_program("");
        generate_set_password();
    }
    Student(string name_val, string contact_val,string id_val, string program_val):Person(name_val,contact_val)
    {
        set_id(id_val);
        set_program(program_val);
        generate_set_password();
    }
    void set_id(string val)
    {
        student_id = val;
    }
    void set_program(string val)
    {
        program = val;
    }
    string get_id()
    {
        return student_id;
    }
    string get_program()
    {
        return program;
    }
    virtual void display_info()
    {
        cout<<"____________________________"<<endl;
        cout<<"The person is a student"<<endl;
        cout<<"Name: "<<get_name()<<endl;
        cout<<"Contact number: "<<get_contactno()<<endl;
        cout<<"Student ID: "<<get_id()<<endl;
        cout<<"Program: "<<get_program()<<endl;
        cout<<"Password: "<<get_password()<<endl;
        cout<<"____________________________"<<endl;
    }
    void generate_set_password()
    {
        char* pass = new char[8];
        int idx = 0;
        for(int i=0;i<4;i++)
        {
            pass[idx] = ('A' + rand()%26);
            idx++;
        }
        for(int i=0;i<3;i++)
        {
            pass[idx] = ('a' + rand()%26);
            idx++;
        }
        pass[idx] = ('0'+rand()%10);
        idx++;
        char punctuation[10] = {';',',','.','!','@','#','?','-','_','~'};
        pass[idx] = punctuation[rand()%10];
        idx++;
        pass[idx] = punctuation[rand()%10];
        idx++;
        pass[idx] = '\0';
        set_password(pass);
    }
};

class Staff:virtual public Person
{
protected:
    string designation;
    string office;
public:
    Staff()
    {
        set_designation("");
        set_office("");
        generate_set_password();
    }
    Staff(string name_val, string contact_val,string val_desig, string val_office):Person(name_val,contact_val)
    {
        set_designation(val_desig);
        set_office(val_office);
        generate_set_password();
    }
    void set_designation(string val)
    {
        designation = val;
    };
    void set_office(string val)
    {
        office  = val;
    }
    string get_designation()
    {
        return designation;
    }
    string get_office()
    {
        return office;
    }
    virtual void display_info(void)
    {
        cout<<"____________________________"<<endl;
        cout<<"The person is a staff"<<endl;
        cout<<"Name: "<<get_name()<<endl;
        cout<<"Contact number: "<<get_contactno()<<endl;
        cout<<"Designation: "<<get_designation()<<endl;
        cout<<"Office: "<<get_office()<<endl;
        cout<<"Password: "<<get_password()<<endl;
        cout<<"____________________________"<<endl;
    }
    void generate_set_password()
    {
        char* pass = new char[8];
        int idx = 0;
        for(int i=0;i<3;i++)
        {
            pass[idx] = ('A' + rand()%26);
            idx++;
        }
        for(int i=0;i<4;i++)
        {
            pass[idx] = ('a' + rand()%26);
            idx++;
        }
        pass[idx] = ('0'+rand()%10);
        idx++;
        pass[idx] = ('0'+rand()%10);
        idx++;
        char punc[10] = {';',',','.','!','@','#','?','-','_','~'};
        pass[idx] = punc[rand()%10];
        idx++;
        pass[idx] = '\0';
        set_password(pass);
    }
};


class Staff_student:public Staff, public Student
{
protected:
    int credit_no;
public:

    Staff_student()
    {
        Staff::generate_set_password();
        set_credit(0);
    }
    Staff_student(string name_val, string contact_val, string id_val, string prog_val,
            string desig_val, string office_val, int cred_val)
    {
        set_name(name_val);
        set_contactno(contact_val);
        set_id(id_val);
        set_program(prog_val);
        set_designation(desig_val);
        set_office(office_val);
        Staff::generate_set_password();
        set_credit(cred_val);
    }
    void set_credit(int val)
    {
        credit_no = val;
    }
    int get_credit(void)
    {
        return  credit_no;
    }
    void display_info(void)
    {
        cout<<"____________________________"<<endl;
        cout<<"The person is a staff student"<<endl;
        cout<<"Name: "<<get_name()<<endl;
        cout<<"Contact number: "<<get_contactno()<<endl;
        cout<<"Student ID: "<<get_id()<<endl;
        cout<<"Program: "<<get_program()<<endl;
        cout<<"Designation: "<<get_designation()<<endl;
        cout<<"Office: "<<get_office()<<endl;
        cout<<"Total Credits: "<<get_credit()<<endl;
        cout<<"Password: "<<get_password()<<endl;
        cout<<"____________________________"<<endl;
    }
};

void addContactPrefix(Person* person)
{
    person->set_contactno("+88" + person->get_contactno());
}

int main()
{
    Student* student[5];
    Staff* staff[5];
    Staff_student* staff_student[5];

    cout<<"List of students: "<<endl;
    student[0] = new Student("Mohammad Farhan","01714886932","180041120","CSE");
    student[1] = new Student("Adnan Abdullah","01624886933","180041121","EEE");
    student[2] = new Student("Ashraful Islam","01734886932","180041122","MCE");
    student[3] = new Student("Atiqur Rahman","01824886932","180041123","SWE");
    student[4] = new Student("Farhan Saif","01912386932","180041124","CSE");

    cout<<"List of staff: "<<endl;
    staff[0] = new Staff("Farhan Ishmam","01893566369","Professor","1st Building");
    staff[1] = new Staff("Rifat Ryan","01963566369","Associate Professor","3rd Building");
    staff[2] = new Staff("Nahian Ibn Asad","01723566369","Assistant Professor","1st Building");
    staff[3] = new Staff("Jawad Kabir","01633566369","Lecturer","1st Building");
    staff[4] = new Staff("Tasnim Ferdous Anan","01533566369","Professor","2nd Building");

    cout<<"List of staff students: "<<endl;
    staff_student[0] = new Staff_student("Adib Abrar","01963566369","18005220","CSE","Teaching Assistant","1st Building",140);
    staff_student[1] = new Staff_student("Jawad Sami","01733566369","18005220","MCE","Teaching Assistant","1st Building",130);
    staff_student[2] = new Staff_student("Mushfiqul Haque","01973566369","18005220","CSE","Teaching Assistant","EEE",125);
    staff_student[3] = new Staff_student("Nafis Faiyaz","01823566369","18005220","EEE","Teaching Assistant","CSE",135);
    staff_student[4] = new Staff_student("Rahman Nibir","01313566369","18005220","EEE","Teaching Assistant","SWE",130);

    /**
        display all the information of each people
        display the type of people (student, staff, staff_student)
    */
    for(int i=0;i<5;i++)
    {
        student[i]->display_info();
    }
    for(int i=0;i<5;i++)
    {
        staff[i]->display_info();
    }
    for(int i=0;i<5;i++)
    {
        staff_student[i]->display_info();
    }

    //after updating
    //one for each class 
    addContactPrefix(student[0]);
    student[0]->display_info();

    addContactPrefix(staff[0]);
    staff[0]->display_info();

    addContactPrefix(staff_student[0]);
    staff_student[0]->display_info();
}