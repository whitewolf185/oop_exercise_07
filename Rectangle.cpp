#include "Rectangle.h"

template<class T1,class T2>
Rectangle<T1,T2>::Rectangle(const T1 &x, const T1 &y,
                     const T2 &a, const T2 &b) : A(a), B(b) { // x and y are left-bottom point of figure
    this->point.first = x;
    this->point.second = y;

    if (A < 0 or B < 0) {
        throw std::invalid_argument("Invalid rectangle parameters!");
    }
}

template<class T1, class T2>
void Rectangle<T1,T2>::Print(std::ostream& out) {
    out << *this << std::endl;
}

template<class T1, class T2>
void Rectangle<T1,T2>::Write(std::ofstream& file){
    file.write((const char*) &(RECTANGLE_TYPE_ID), sizeof(unsigned));
    file.write((const char*) &(this->point.first), sizeof (T1));
    file.write((const char*) &(this->point.second), sizeof(T1));
    file.write((const char*) &(this->A), sizeof(T2));
    file.write((const char*) &(this->B), sizeof (T2));
}

//для нормального вывода нужно определять операцию +
template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const Rectangle<T1, T2> &rectangle) {
    out << "Rectangle vertices: [";
    out << Cord(rectangle.X, rectangle.Y) << ", ";
    out << Cord(rectangle.X, rectangle.Y + rectangle.B) << ", ";
    out << Cord(rectangle.X + rectangle.A, rectangle.Y + rectangle.B) << ", ";
    out << Cord(rectangle.X + rectangle.A, rectangle.Y);
    out << "]";
    return out;
}