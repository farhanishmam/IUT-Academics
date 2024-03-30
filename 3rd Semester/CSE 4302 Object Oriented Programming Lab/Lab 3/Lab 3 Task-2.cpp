#include<iostream>
using namespace std;

class Flight
{
private:
    int flight_number;
    string destination;
    float distance;
    float max_fuel_capacity;
    void cal_fuel(void)
    {
        if(distance<=1000)
        {
            max_fuel_capacity = 500;
        }
        else if(distance<=2000)
        {
            max_fuel_capacity = 1100;
        }
        else
        {
            max_fuel_capacity = 2200;
        }
    }
public:
    void feed_info(int in_fn, string in_des,float in_fuel)
    {
        flight_number = in_fn;
        destination = in_des;
        distance = in_fuel;
        cal_fuel();
    }

    void show_info(void)
    {
        cout<< "The flight number: "<<flight_number<<endl;
        cout<< "The destination: "<<destination<<endl;
        cout<< "The traveling distance: "<<distance<<endl;
        cout<< "The required amount of fuel: "<<max_fuel_capacity<<endl<<endl;
    }
};

int main(void)
{
    Flight f1,f2;
    f1.feed_info(453467,"United States",2300.0);
    f1.show_info();

    f2.feed_info(753324,"Dhaka",1000.0);
    f2.show_info();

    return 0;


}
