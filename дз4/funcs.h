#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "class_t.h"
//#define SIZE 33

void teacher_exp(Teacher* teachers, int ind) {
    int st = 0;
    std::cout << "Введите стаж: ";
    std::cin >> st;
    for(int i = 0; i < ind; i++) {
        if(atoi(teachers[i].getExp()) > st) {
            teachers[i].show();
            std::cout << std::endl;
        }
    }
}

void teacher_sub(Teacher* teachers, int ind) {
    char* sub = new char[30];
    std::cout << "Введите предмет: ";
    std::cin >> sub;
    for(int i = 0; i < ind; i++) {
        if(strcmp(teachers[i].getSub(), sub) == 0) {
            teachers[i].show();
            std::cout << std::endl;
        }
    }
    delete[] sub;
}

void teacher_year(Teacher* teachers, int ind) {
    int year = 0;
    std::cout << "Введите год рождения: ";
    std::cin >> year;
    for(int i = 0; i < ind; i++) {
        if(atoi(teachers[i].getBDate()) == year) {
            teachers[i].show();
            std::cout << std::endl;
        }
    }
}
