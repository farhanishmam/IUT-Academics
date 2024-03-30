#include <iostream>
#include <string>

using namespace std;
enum class Material {Wood,Board,Steel};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string product_name;
public:
    Furniture()
    {
        setProductName("");
        setPrice(0);
        setDiscount(0);
        setMadeof(Material::Wood);
    }

    Furniture(string n, double p,double d,Material m)
    {
        setProductName(n);
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setProductName(string val)
    {
        product_name = val;
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getProductName(void)
    {
        return product_name;
    }
    double getPrice()
    {
        return price;
    }
    double getDiscount()
    {
        return discount;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()=0;
};
enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize b_size;
public:
    Bed()
    {
        setBedSize(BedSize::Single);
    }
    Bed(string n, double p,double d,Material m, BedSize b):Furniture(n, p,d,m)
    {
        setBedSize(b);
    }
    void setBedSize(BedSize val)
    {
        b_size = val;
    }
    string getBedSize()
    {
        if (b_size == BedSize::Single)
            return string("Single");
        else if (b_size == BedSize::SemiDouble)
            return string("SemiDouble");
        else if (b_size == BedSize::Double)
            return string("Double");
        else return string("");
    }
    void productDetails()
    {
        cout<<"---------------------"<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getPrice()-getDiscount()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"BedSize: "<<getBedSize()<<endl;
        cout<<"########################################"<<endl;
    }
};

enum class SeatNumber{One, Two, Three, Four, Five};
class Sofa:public Furniture
{
private:
    SeatNumber seat;
public:
    Sofa()
    {
        setSeatNumber(SeatNumber::One);
    }
    Sofa(string n,double p,double d,Material m, SeatNumber s):Furniture(n,p,d,m)
    {
        setSeatNumber(s);
    }
    void setSeatNumber(SeatNumber val)
    {
        seat = val;
    }
    string getSeatNumber()
    {
        if (seat == SeatNumber ::One)
            return string("One");
        else if (seat == SeatNumber ::Two)
            return string("Two");
        else if (seat == SeatNumber ::Three)
            return string("Three");
        else if (seat == SeatNumber ::Four)
            return string("Four");
        else if (seat == SeatNumber ::Five)
            return string("Five");
        else
            return string("");
    }
    void productDetails()
    {
        cout<<"---------------------"<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getPrice()-getDiscount()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"SeatNumber: "<<getSeatNumber()<<endl;
        cout<<"########################################"<<endl;
    }
};

enum class ChairCount{Two,Four,Six};
class DiningTable:public Furniture
{
private:
    ChairCount chair;
public:
    DiningTable()
    {
        setChairCount(ChairCount::Two);
    }
    DiningTable(string n,double p,double d,Material m, ChairCount s):Furniture(n,p,d,m)
    {
        setChairCount(s);
    }
    void setChairCount(ChairCount val)
    {
        chair = val;
    }
    string getChairCount()
    {
        if(chair == ChairCount::Two)
            return string("Two");
        else if(chair == ChairCount::Four)
            return string("Four");
        else if(chair == ChairCount::Six)
            return string("Six");
        else return string("");
    }
    void productDetails()
    {
        cout<<"---------------------"<<endl;
        cout<<"Product Name: "<<getProductName()<<endl;
        cout<<"Regular Price: "<<getPrice()<<endl;
        cout<<"Discounted Price: "<<getPrice()-getDiscount()<<endl;
        cout<<"Material: "<<getMadeof()<<endl;
        cout<<"ChairCount: "<<getChairCount()<<endl;
        cout<<"########################################"<<endl;
    }
};
/**task 4
sort_furniture_price will sort the array in descending order based on
their discounted price. You may need to add some member functions
**/
//Furniture sort using bubble sort
void sort_furniture_price(Furniture *furnitures[], int no_of_furnitures)
{
    int i, j;
    for (i = 0; i < no_of_furnitures-1; i++)
        for (j = 0; j < no_of_furnitures-i-1; j++)
            if (furnitures[j]->getPrice()-furnitures[j]->getDiscount() < furnitures[j+1]->getPrice()-furnitures[j+1]->getDiscount())
                swap(furnitures[j], furnitures[j+1]);
}
int main()
{
    Furniture* f_list[100];
    /**
    task 1
    So that following lines can be executed without error
    */
    f_list[0] = new Bed("Farhan's First Bed",10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa("Farhan's Sofa",11000,234,Material::Steel,SeatNumber ::Five);
    f_list[2] = new DiningTable("Farhan's Table",13000,345,Material::Wood,ChairCount::Four);
    f_list[3] = new Bed("Farhan's Second Bed",10090,123,Material::Wood,BedSize::Single);
    /**task 1 ends here*/
    /**
    task 2
    So that following lines can be executed without error
    task 3 (Modify productDetails)
    */
    for(int i=0; i<1; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 2 ends here*/
    /**task 3 ends here*/
    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_price(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/
}