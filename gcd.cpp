#include <iostream>
#include <numeric>

class Fraction{
public:
    Fraction() : num(0), den(1) {}
    explicit Fraction(int a) : num(a), den(1) {};
    Fraction(int a, int b) : num(a), den(b) {};
    Fraction(const Fraction& another) {
        this->num = another.num;
        this->den = another.den;
    }
    ~Fraction(){};

    auto get_a() {
        return num;
    }
    auto get_b() {
        return den;
    }

    void get_frac() {
        std::cout << this->get_a() << "/" << this->get_b() << std::endl;
    }

    void set_a(int a) {
        this->num = a;
    }
    void set_b(int b) {
        this->den = b;
    }

    void operator=(Fraction x){
        this->num = x.get_a() / std::gcd(x.get_a(), x.get_b());
        this->den = x.get_b() / std::gcd(x.get_a(), x.get_b());
    }
    void operator=(int x){
        this->num = x;
        this->den = 1;
    }

    void operator+=(Fraction x){
        int n_a = num * x.get_b() + den * x.get_a();
        int n_b = den * x.get_b();
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }
    void operator+=(int x) {
        int n_a = num + x * den;
        int n_b = den;
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }

    void operator-=(Fraction x){
        int n_a = num * x.get_b() - den * x.get_a();
        int n_b = den * x.get_b();
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }
    void operator-=(int x) {
        int n_a = num - x * den;
        int n_b = den;
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }

    void operator*=(Fraction x){
        int n_a = num * x.get_a();
        int n_b = den * x.get_b();
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }
    void operator*=(int x) {
        int n_a = num * x;
        int n_b = den;
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }

    void operator/=(Fraction x){
        int n_a = num * x.get_b();
        int n_b = den * x.get_a();
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }
    void operator/=(int x) {
        int n_a = num;
        int n_b = den * x;
        this->num = n_a / (std::gcd(n_a, n_b));
        this->den = n_b / (std::gcd(n_a, n_b));
    }

    operator double() {
        return static_cast<double>(this->get_a())/static_cast<double>(this->get_b());
    }

private:
    int num;
    int den;

};

Fraction operator+(Fraction& x, Fraction& y) {
    Fraction sum;
    if (x.get_b() == y.get_b()) {
        int s_a = x.get_a() + y.get_a();
        int s_b = x.get_b();
        sum.set_a(s_a/(std::gcd(s_a, s_b)));
        sum.set_b(s_b/(std::gcd(s_a, s_b)));
    } else {
        int s_a = x.get_a()*y.get_b() + x.get_b()*y.get_a();
        int s_b = x.get_b()*y.get_b();
        sum.set_a(s_a/std::gcd(s_a, s_b));
        sum.set_b(s_b/std::gcd(s_a, s_b));
    }
    return sum;
}

Fraction operator-(Fraction& x, Fraction& y) {
    Fraction sum;
    if (x.get_b() == y.get_b()) {
        int s_a = x.get_a() - y.get_a();
        int s_b = x.get_b();
        sum.set_a(s_a/(std::gcd(s_a, s_b)));
        sum.set_b(s_b/(std::gcd(s_a, s_b)));
    } else {
        int s_a = x.get_a()*y.get_b() - x.get_b()*y.get_a();
        int s_b = x.get_b()*y.get_b();
        sum.set_a(s_a/std::gcd(s_a, s_b));
        sum.set_b(s_b/std::gcd(s_a, s_b));
    }
    return sum;
}

Fraction operator*(Fraction& x, Fraction& y) {
    Fraction comp;
    int c_a = x.get_a()*y.get_a();
    int c_b = x.get_b()*y.get_b();
    comp.set_a(c_a/std::gcd(c_a, c_b));
    comp.set_b(c_b/std::gcd(c_a, c_b));
    return comp;
}

Fraction operator/(Fraction& x, Fraction& y) {
    Fraction div;
    int c_a = x.get_a()*y.get_b();
    int c_b = x.get_b()*y.get_a();
    div.set_a(c_a/std::gcd(c_a, c_b));
    div.set_b(c_b/std::gcd(c_a, c_b));
    return div;
}

std::ostream& operator<< (std::ostream &out, Fraction& x) {
    out << x.get_a() << "/" << x.get_b() << std::endl;
    return out;
}




int main() {

    Fraction x(5, 6);
    Fraction y(1, 7);

    Fraction z = x + y;
//    z.get_frac();
    std::cout << z;

    z = x - y;
    std::cout << z;

    z = x*y;
    std::cout << z;
    z = x/y;
    std::cout << z;

    z += 3;
    std::cout << z;
    z += x;
    std::cout << z;
    z -= 3;
    std::cout << z;
    z -= x;
    std::cout << z;

    z *= 5;
    std::cout << z;
    z *= x;
    std::cout << z;
    z /= 5;
    std::cout << z;
    z /= x;
    std::cout << z;

    Fraction p;
    std::cin >> p;
    std::cout << p;

    std::cout << (double)p << std::endl;
    std::cout << static_cast<double>(p);
    return 0;
}