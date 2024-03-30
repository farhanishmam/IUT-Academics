#ifndef COORD_H
#define COORD_H


class Coord
{
    public:
        /** Default constructor */
        Coord();

        /** Access x
         * \return The current value of x
         */
        double Getx() { return x; }
        /** Set x
         * \param val New value to set
         */
        void Setx(double val) { x = val; }
        /** Access y
         * \return The current value of y
         */
        double Gety() { return y; }
        /** Set y
         * \param val New value to set
         */
        void Sety(double val) { y = val; }
        /** Access angleInDegree
         * \return The current value of angleInDegree
         */
        double GetangleInDegree() { return angleInDegree; }
        /** Set angleInDegree
         * \param val New value to set
         */
        void SetangleInDegree(double val) { angleInDegree = val; }
        /** Access distance
         * \return The current value of distance
         */
        double Getdistance() { return distance; }
        /** Set distance
         * \param val New value to set
         */
        void Setdistance(double val) { distance = val; }

    protected:

    private:
        double x; //!< Member variable "x"
        double y; //!< Member variable "y"
        double angleInDegree; //!< Member variable "angleInDegree"
        double distance; //!< Member variable "distance"
};

#endif // COORD_H
