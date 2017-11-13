#include "Multimap.h"
#include <iostream>

template <typename K, typename V>
Multimap <K, V> sym_dif(Multimap<K, V>& a, Multimap<K, V>& b) {
    Multimap<K, V> temp;
    return (temp = (a + b) - (a * b));
}

int main() {
    Multimap<int,int> m[5];

    std::cout << "m[0]:" << '\n';
    m[0].insert(std::make_pair(4,3));
    m[0].insert(std::make_pair(1,3));
    m[0].insert(std::make_pair(3,3));
    m[0].insert(std::make_pair(2,3));
    m[0].insert(std::make_pair(5,3));
    m[0].show();

    std::cout << "\nm[1]:" << '\n';
    m[1] = m[0];
    m[1].erase(2);
    m[1].insert(std::make_pair(3, 12));
    m[1].show();

    std::cout << "\nm[2]:" << '\n';
    m[2] = m[1] + m[0];
    m[2].show();

    std::cout << "\nm[3]:" << '\n';
    m[3] = m[1] * m[0];
    m[3].show();

    std::cout << "\nm[4]:" << '\n';
    m[4] = sym_dif(m[0], m[3]);
    m[4].show();


    return 0;
}
