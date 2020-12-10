#include "Trapeze.h"

template<class Tpoint, class Tside>
Trapeze<Tpoint,Tside>::Trapeze(const Tpoint &x, const Tpoint &y,
                 const Tside &a, const Tside &b, const Tside &c) : A(a), B(b), C(c) { // x and y are left-bottom point of figure
    this->point.first = x;
    this->point.second = y;

    if (A < 0 or B < 0 or C < 0) {
        throw std::invalid_argument("Invalid trapeze parameters!");
    }
    if (B > A) {
        std::swap(A, B);
    }
}

template<class Tpoint, class Tside>
void Trapeze<Tpoint,Tside>::Print(std::ostream& out) {
    out << *this << std::endl;
}

template<class Tpoint, class Tside>
void Trapeze<Tpoint,Tside>::Write(std::ofstream &file) {
    file.write((const char*) &(TRAPEZE_TYPE_ID), sizeof(unsigned));
    file.write((const char*) &(this->point.first), sizeof (Tpoint));
    file.write((const char*) &(this->point.second), sizeof(Tpoint));
    file.write((const char*) &(this->A), sizeof(Tside));
    file.write((const char*) &(this->B), sizeof (Tside));
    file.write((const char*) &(this->C), sizeof (Tside));
}

//для нормального вывода нужно определять операцию +
//тут все вычисления для double
template<class Tpoint, class Tside>
typename std::enable_if<is_double<Tpoint,Tside>::value, std::ostream &>::type
operator<<(std::ostream &out, const Trapeze<Tpoint,Tside> &trapeze) {
    Tside diff = (trapeze.A - trapeze.B) / 2.0;
    double height = std::sqrt(trapeze.C * trapeze.C - diff * diff);
    out << "Trapeze vertices: [";
    out << Cord(trapeze.X, trapeze.Y) << ", ";
    out << Cord(trapeze.X + diff, trapeze.Y + height) << ", ";
    out << Cord(trapeze.X + trapeze.A - diff, trapeze.Y + height) << ", ";
    out << Cord(trapeze.X + trapeze.A, trapeze.Y);
    out << "]";
    return out;
}

template<class Tpoint, class Tside>
typename std::enable_if<is_int<Tpoint,Tside>::value, std::ostream &>::type
operator<<(std::ostream &out, const Trapeze<Tpoint,Tside> &trapeze) {
    out << "I cant calculate coordinates, because the type is int" << std::endl;
    return out;
}