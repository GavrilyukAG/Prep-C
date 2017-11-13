#ifndef MMap
#define MMap

#include <iostream>

template <typename K, typename V>
class Multimap {
public:
    typedef std::pair <K, V> pair_def;

    Multimap (): size(0), cap(5) {
        arr = new pair_def[cap];
    }
    Multimap (const Multimap& other) {
        size = other.size;
        cap = other.cap;
        arr = new pair_def[cap];
        for (int i = 0; i < cap; ++i) {
            arr[i] = other.arr[i];
        }
    }
    ~Multimap () {
        delete[] arr;
    }

    void insert(const pair_def& p) {
        if (size == cap) {
            expand();
        }
        for (int i = 0; i < size; ++i) {
            if (arr[i].first > p.first) {
                int ind = i;
                pair_def* temp = new pair_def[size - i];
                for (int j = 0; j < size - i; ++j, ++ind) {
                    temp[j] = arr[ind];
                }
                ind = i;
                arr[i] = p;
                for (int j = 0; j < size - ind; ++j) {
                    arr[i + 1] = temp[j];
                    ++i;
                }
                delete[] temp;
                ++size;
                return;
            }
        }
        arr[size] = p;
        ++size;
    }
    void erase(const K& key) {
        if (!find(key).first) {
            return;
        } else {
            pair_def* temp = new pair_def[size];
            int count = 0;
            for (int i = 0; i < size; ++i) {
                if (arr[i].first == key) {
                    ++count;
                    continue;
                }
                temp[i - count] = arr[i];
            }
            delete[] arr;
            size -= count;
            arr = new pair_def[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = temp[i];
            }
            delete[] temp;
        }
    }
    pair_def find(const K& key) const {
        for (int i = 0; i < size; ++i) {
            if (arr[i].first == key) {
                return arr[i];
            }
        }
        return pair_def(0,0);
    }
    void show() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i].first << '(' << arr[i].second << ")\n";
        }
    }
    int msize() const {
        return size;
    }

    Multimap operator +(const Multimap& a) {
        Multimap<K, V> temp;
        for (int i = 0; i < this->size; ++i) {
            temp.insert(this->arr[i]);
        }
        for (int i = 0; i < a.size; ++i) {
            if (!this->find(a.arr[i].first).first) {
                temp.insert(a.arr[i]);
            }
        }
        return temp;
    }
    Multimap operator -(const Multimap& a) {
        Multimap<K, V> temp;
        for (int i = 0; i < this->size; ++i) {
            if (this->find(a.arr[i].first).first != 0) {
                continue;
            }
            temp.insert(this->arr[i]);
        }
        return temp;
    }
    Multimap operator *(const Multimap& a) {
        Multimap<K, V> temp;
        for (int i = 0; i < this->size; ++i) {
            if (this->find(a.arr[i].first).first) {
                temp.insert(this->arr[i]);
            }
        }
        return temp;
    }
    Multimap& operator =(const Multimap& obj) {
        delete[] arr;
        size = obj.size;
        arr = new pair_def[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = obj.arr[i];
        }
        return *this;
    }
    pair_def operator [](const int n) const {
        try {
            return arr[n];
            throw n;
        }
        catch (int n) {
            std::cout << "No element with index " << n <<'\n';
        }
    }

private:
    pair_def* arr;
    int size;
    int cap;

    void expand() {
        pair_def* temp = new pair_def[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        delete[] arr;

        cap += 10;
        arr = new pair_def[cap];
        for (int i = 0; i < size; ++i) {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
};

#endif
