#ifndef DM_H
#define DM_H


class DM
{
    public:
        DM();
        ~DM();

        int Getmeter() { return meter; }
        void Setmeter(int val) { meter = val; }
        int Getcenti() { return centi; }
        void Setcenti(int val) { centi = val; }

    protected:

    private:
        int meter;
        int centi;
};

#endif // DM_H
