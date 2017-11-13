#include <iostream>
#include "classes.h"

int main() {
    Sphere s(1.7), s1;
    Parallelepiped p;
    Figure** f = new Figure*[3];
    f[0] = &s;
    f[1] = &s1;
    f[2] = &p;

    f[0]->info();
    std::cout << "f[0]: S = " << f[0]->S() << " V = " << f[0]->V() << std::endl;
    f[1]->info();
    std::cout << "f[1]: S = " << f[1]->S() << " V = " << f[1]->V() << std::endl;
    f[2]->info();
    std::cout << "f[2]: S = " << f[2]->S() << " V = " << f[2]->V() << std::endl;

    std::cout << std::endl;
    s.setR(2);
    f[0]->info();
    std::cout << "f[0]: S = " << f[0]->S() << " V = " << f[0]->V() << std::endl;

    delete[] f;

    return 0;
}
