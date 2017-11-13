class Set {
 public:
     Set() :
     size(0)
      {
         //size = 0;
         str = new std::string[size];
     }
     Set(const Set& other) {
         size = other.size;
         str = new std::string[size];
         for(int i = 0; i < size; ++i) {
             str[i] = other.str[i];
         }
     }
     ~Set() {
         delete[] str;
     }

     void insert(std::string);
     void erase(std::string);
     int find(std::string) const;
     int count() const;
     friend Set operator +(const Set&, const Set&);
     friend Set operator -(const Set&, const Set&);
     friend Set operator *(const Set&, const Set&);
     Set& operator =(const Set&);
     std::string operator [](int) const;
     friend std::ostream& operator <<(std::ostream&, const Set&);

 private:
     int size;
     std::string* str;
};
