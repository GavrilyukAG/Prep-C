#include <iostream>
#include <string>
#include "Set.h"

int Set::count() const {
    return size;
}

void Set::insert(std::string st) {
    if(find(st) != -1) {
        return;
    }

    size++;
    std::string* buf = new std::string[size];
    bool inserted = false;
    for(int i = 0, j = 0; i < size; ++i) {
    //    std::cout << (j < size - 1 ? str[j] : "XXX") << j << i << '\n';
        if (!inserted && j < size - 1 && str[j] < st)
            buf[i] = str[j++];
        else {
            buf[i] = st;
            inserted = true;
        }
    }

    delete[] str;
    str = buf;

    //std::cout << "\n\n\n";
}

int Set::find(std::string st) const {
    for(int i = 0; i < size; i++) {
        if(str[i] == st) {
            return i;
        }
    }
    return -1;
}

void Set::erase(std::string st) {
    if(find(st) == -1) {
        return;
    }
    std::string s[size - 1];
    int count = 0;
    for(int i = 0; i < size; ++i) {
        if(str[i] == st) {
            continue;
        } else {
            s[count] = str[i];
            ++count;
        }
    }
    delete[] str;
    --size;

    str = new std::string[size];
    for(int i = 0; i < size; ++i) {
        str[i] = s[i];
    }
}

Set operator +(const Set& a, const Set& b) {
    Set tmp;
    for(int i = 0; i < a.size; ++i) {
        tmp.insert(a.str[i]);
    }
    for(int i = 0; i < b.size; ++i) {
        if(a.find(b.str[i]) == -1) {
            tmp.insert(b.str[i]);
        }
    }
    return tmp;
}

Set operator -(const Set& a, const Set& b) {
    Set tmp;
    for(int i = 0; i < a.size; ++i) {
        if(b.find(a.str[i]) == -1) {
            tmp.insert(a.str[i]);
        }
    }
    return tmp;
}

Set operator *(const Set& a, const Set& b) {
    Set tmp;
    for(int i = 0; i < a.size; ++i) {
        if(b.find(a.str[i]) != -1) {
            tmp.insert(a.str[i]);
        }
    }
    return tmp;
}

Set& Set::operator =(const Set& obj) {
    delete[] str;
    size = obj.size;
    str = new std::string[size];
    for(int i = 0; i < size; ++i) {
        str[i] = obj.str[i];
    }
    return *this;
}

std::ostream& operator <<(std::ostream& os, const Set& s) {
    os << "[ " ;
    for(int i = 0; i < s.size; i++) {
        os << s.str[i] << ' ';
    }
    os << ']' << std::endl;
    return os;
}

std::string Set::operator [](int n) const {
    if(n < 0 || n > size) {
        return NULL; //? invalid inpit
    }
    return this->str[n];
}

Set sym_dif(const Set& a, const Set& b) {
    Set tmp;
    return (tmp = (a + b) - (a * b));
}

int main() {
    Set* s = new Set[6];
    s[0].insert("one");
    s[0].insert("two");
    s[0].insert("three");
    s[0].insert("four");
    s[1].insert("four");
    s[1].insert("five");
    s[1].insert("six");

    std::cout << "s[0]: " << s[0] << "S[1]: " << s[1];
    s[2] = s[0] + s[1];
    std::cout << "s[2]: " << s[2];
    s[3] = s[2] - s[1];
    std::cout << "s[3]: " << s[3];
    s[4] = s[1] * s[0];
    std::cout << "s[4]: " << s[4];
    s[5] = s[4] + s[3] + s[2] + s[1] - s[0];
    std::cout << "s[5]: " << s[5];
    s[5].erase("six");
    std::cout << "s[5]: " << s[5];

    s[5] = sym_dif(s[0], s[1]);
    std::cout << "s[5]: " << s[5];

    delete[] s;

    return 0;
}
