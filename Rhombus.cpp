
#include "Rhombus.h"

template<class T1, class T2>
Rhombus<T1,T2>::Rhombus(const T1 &x, const T1 &y, const T2 &d1, const T2 &d2) : D1(d1), D2(d2) {
    //point of left edge
    this->point.first = x;
    this->point.second = y;

    if (D1 < 0 || D2 < 0) {
        throw std::invalid_argument("Invalid Rhombus parameters!");
    }
}

template<class T1, class T2>
void Rhombus<T1,T2>::Print(std::ostream& out) {
    out << *this << std::endl;
}

template<class T1, class T2>
void Rhombus<T1,T2>::Write(std::ofstream& file){
    file.write((const char*) &(RHOMBUS_TYPE_ID), sizeof(unsigned));
    file.write((const char*) &(this->point.first), sizeof (T1));
    file.write((const char*) &(this->point.second), sizeof(T1));
    file.write((const char*) &(this->D1), sizeof(T2));
    file.write((const char*) &(this->D2), sizeof (T2));
}

//для нормального вывода нужно определять операцию +
template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const Rhombus<T1,T2> &rhombus) {
    out << "Rhombus vertices: [ " << Cord(rhombus.X, rhombus.Y) << ", "
        << Cord(rhombus.X + rhombus.D1 / 2, rhombus.Y + rhombus.D2 / 2) << ", "
        << Cord(rhombus.X + rhombus.D1, rhombus.Y) << ", "
        << Cord(rhombus.X - rhombus.D1 / 2, rhombus.Y - rhombus.D2 / 2) << " ]" << std::endl;

    return out;
}



