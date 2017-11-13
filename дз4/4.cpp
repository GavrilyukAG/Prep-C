#include "funcs.h"

int main(int argc, char* argv[]) {

    if(argc < 1) {
        std::cout << "Not enough arguments\n";
        return -1;
    }

    std::ifstream f(argv[1]);
    if(!f.is_open()) { //istream while(f >> buf)  std::ios::operator bool
        std::cout << "File errror" << std::endl;
        return -1;
    }
    int teach_count = 0;
    f >> teach_count;

    Teacher* teachers = new Teacher[teach_count + 1];

    int iter = 0, ind = 0;
    while(!f.eof()) {
        if(ind > teach_count) {
            break;
        }
        char* buf = new char[33];
        f >> buf;
        switch(iter) {
            case 0:
                teachers[ind].setLName(buf);
                break;
            case 1:
                teachers[ind].setFName(buf);
                break;
            case 2:
                teachers[ind].setMName(buf);
                break;
            case 3:
                teachers[ind].setSex(buf);
                break;
            case 4:
                teachers[ind].setExp(buf);
                break;
            case 5:
                teachers[ind].setSub(buf);
                break;
            case 6:
                teachers[ind].setProf(buf);
                break;
            case 7:
                teachers[ind].setBDate(buf);
                break;
            default:
                break;
        }
        iter++;
        if(f.peek() == '\n') {
            iter = 0;
            ind++;
        }
    delete[] buf;
    }
    f.close();

    for(int i = 0; i < ind; i++) {
        teachers[i].show();
        std::cout << std::endl;
    }

    teacher_exp(teachers, ind);
    teacher_sub(teachers, ind);
    teacher_year(teachers, ind);

    delete[] teachers;

    return 0;
}
