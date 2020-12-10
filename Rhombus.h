#ifndef OOP_EXERSICE_03_RHOMBUS_H
#define OOP_EXERSICE_03_RHOMBUS_H
#include "Figures.h"

const unsigned int RHOMBUS_TYPE_ID = 2;

template<class T1, class T2>
class Rhombus : public Figures<T1> {
private:
    T2 D1, D2;
public:
    Rhombus(const T1 &x, const T1 &y, const T2 &d1, const T2 &d2);
    void Print(std::ostream& out) override;
    void Write(std::ofstream& file) override;
    friend std::ostream& operator<<(std::ostream& out, const Rhombus<T1,T2>& rhombus);
};

#endif //OOP_EXERSICE_03_RHOMBUS_H
