#ifndef DB_H
#define DB_H


class DB
{
    public:
        DB();
        ~DB();

        int Getfeet() { return feet; }
        void Setfeet(int val) { feet = val; }
        int Getinches() { return inches; }
        void Setinches(int val) { inches = val; }

    protected:

    private:
        int feet;
        int inches;
};

#endif // DB_H
