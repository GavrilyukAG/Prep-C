//проверка strcpy

class Teacher {
public:
    Teacher() {
        last_name = new char[33];
        strcpy(last_name, "None");
        first_name = new char[33];
        strcpy(first_name, "None");
        middle_name = new char[33];
        strcpy(middle_name, "None");
        sex = new char[33];
        strcpy(sex, "?");
        expir = new char[33];
        strcpy(expir, "0");
        subject = new char[33];
        strcpy(subject, "None");
        prof = new char[33];
        strcpy(prof, "?");
        birth_date = new char[33];
        strcpy(birth_date, "0");
    }
    //asprintf
    Teacher(const char* ln, const char* fn, const char* mn, const char* s,
    const char* ex, const char* sub, const char* pr, const char* bday){
        last_name = new char[33];
        strcpy(last_name, ln);
        first_name = new char[33];
        strcpy(first_name, fn);
        middle_name = new char[33];
        strcpy(middle_name, mn);
        sex = new char[33];
        strcpy(sex, s);
        expir = new char[33];
        strcpy(expir, ex);
        subject = new char[33];
        strcpy(subject, sub);
        prof = new char[33];
        strcpy(prof, pr);
        birth_date = new char[33];
        strcpy(birth_date, bday);
    }
    Teacher(const Teacher& other) {
        last_name = new char[33];
        strcpy(last_name, other.last_name);
        first_name = new char[33];
        strcpy(first_name, other.first_name);
        middle_name = new char[33];
        strcpy(middle_name, other.middle_name);
        sex = new char[33];
        strcpy(sex, other.sex);
        expir = new char[33];
        strcpy(expir, other.expir);
        subject = new char[33];
        strcpy(subject, other.subject);
        prof = new char[33];
        strcpy(prof, other.prof);
        birth_date = new char[33];
        strcpy(birth_date, other.birth_date);
    }
    ~Teacher() {
         delete[] last_name;
         delete[] first_name;
         delete[] middle_name;
         delete[] sex;
         delete[] expir;
         delete[] subject;
         delete[] prof;
         delete[] birth_date;
    }

    void show() {
        std::cout << "FIO: " << last_name << ' '
        << first_name << ' '
        << middle_name << std::endl
        << "Sex: " << sex << std::endl
        << "Experience: " << expir << std::endl
        << "Subject: " << subject << std::endl
        << "Profession: " << prof << std::endl
        << "Year of birth: " << birth_date << std::endl;
    }

    const char* getLName() {
        return last_name;
    }
    const char* getFName() {
        return first_name;
    }
    const char* getMName() {
        return middle_name;
    }
    const char* getSex() {
        return sex;
    }
    const char* getExp() {
        return expir;
    }
    const char* getSub() {
        return subject;
    }
    const char* getProf() {
        return prof;
    }
    const char* getBDate() {
        return birth_date;
    }

    void setLName(const char* ln) {
        //if(!sizeof(last_name) < sizeof(ln)) {
            strcpy(last_name, ln);
        //}
    }
    void setFName(const char* fn) {
        strcpy(first_name, fn);
    }
    void setMName(const char* mn) {
        strcpy(middle_name, mn);
    }
    void setSex(const char* s) {
        strcpy(sex, s);
    }
    void setExp(const char* ex) {
        strcpy(expir, ex);
    }
    void setSub(const char* sub) {
        strcpy(subject, sub);
    }
    void setProf(const char* profession) {
        strcpy(prof, profession);
    }
    void setBDate(const char* bd) {
        strcpy(birth_date, bd);
    }

private:
    char* last_name;
    char* first_name;
    char* middle_name;
    char* sex;
    char* expir;
    char* subject;
    char* prof;
    char* birth_date;
};
