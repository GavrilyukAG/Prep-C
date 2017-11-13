class Figure {
public:
    //Figure() {}
    virtual ~Figure() {std::cout << "Figure deleted" << std::endl;}

    virtual void info() = 0;
    virtual double V() = 0;
    virtual double S() = 0;
};

class Sphere : public Figure {
public:
    Sphere():
        R(1) {}
    Sphere(double r):
        R(r) {}
    ~Sphere() {}

    void info() {
        std::cout << "Hello, I'm a Sphere with R = " << R << " :)" << std::endl;
    }
    double V() {
        return (4/3 * 3.1415926 * R * R * R);
    }
    double S() {
        return (4 * 3.1415926 * R * R);
    }
    void setR(const double& r) {
        R = r;
    }

private:
    double R;
};

class Parallelepiped: public Figure {
public:
    Parallelepiped():
        a(1), b(2), c(3) {}
    Parallelepiped(double a0, double b0, double c0):
        a(a0), b(b0), c(c0) {}
    ~Parallelepiped() {}

    void info() {
        std::cout << "Hello, I'm a Parallelepiped with a = " << a << ", b = " <<
        b << ", c = " << c << " :)" << std::endl;
    }
    double V() {
        return (a * b * c);
    }
    double S() {
        return 2*(a*b + b*c + a*c);
    }
    void setPar(const double& a1, const double& b1, const double& c1) {
        a = a1;
        b = b1;
        c = c1;
    }

private:
    double a;
    double b;
    double c;
};
