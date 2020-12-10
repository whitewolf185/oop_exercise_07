#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Figures.h"

const unsigned int RECTANGLE_TYPE_ID = 1;

template<class T1, class T2>
class Rectangle : public Figures<T1> {
private:
    T2 A, B;
public:
    Rectangle(const T1 &x, const T1 &y, const T2 &a, const T2 &b);
    void Print(std::ostream& out) override;
    void Write(std::ofstream& file) override;
    friend std::ostream & operator << (std::ostream & out, const Rectangle & rect);
};

#endif /* RECTANGLE_HPP */
