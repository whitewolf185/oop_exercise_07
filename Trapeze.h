#ifndef OOP_EXERSICE_03_TRAPEZE_H
#define OOP_EXERSICE_03_TRAPEZE_H
#include "Figures.h"

const unsigned int TRAPEZE_TYPE_ID = 1;

template<class T1, class T2>
class Trapeze : public Figures<T1>{
private:
    T2 A, B, C;
public:
    Trapeze(const T1 &x, const T1 &y, const T2 &a, const T2 &b, const T2 &c);
    void Print(std::ostream& out) override;
    void Write(std::ofstream& file) override;
    friend std::ostream & operator << (std::ostream & out, const Trapeze<T1,T2> & trapeze);
};
#endif //OOP_EXERSICE_03_TRAPEZE_H
