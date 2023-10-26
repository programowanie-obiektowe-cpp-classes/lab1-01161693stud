#include <iostream>
#include <math.h>


class Wektor2D {
private:
    double x;
    double y;
    static int num_wek;  

public:
    Wektor2D() : x(0.0), y(0.0) {
        num_wek++;
    }

    Wektor2D(double x, double y) : x(x), y(y) {
        num_wek++;
    }

    ~Wektor2D() {
    num_wek--;
    }

    static Wektor2D kart(double x, double y) {
        return Wektor2D(x, y);
    }

    static Wektor2D bieg(double r, double theta) {
        double x = r * std::cos(theta);
        double y = r * std::sin(theta);
        return Wektor2D(x, y);
    }

    static int populacja() {
        return num_wek;
    }

    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& wektor) {
        os << "Wsp x: " << wektor.x << " Wsp y: " << wektor.y;
        return os;
    }

    Wektor2D operator+(const Wektor2D& other){
        return Wektor2D(x + other.x, y + other.y);
    }

    double operator*(const Wektor2D& other){
        return x * other.x + y * other.y;
    }

    double norm() const {
        return std::sqrt(x * x + y * y);
    }

    void print() const {
        std::cout << "Wsp x: " << x << " Wsp y: " << y << "\n";
    }

    void setX(double x_) {
        x = x_;
    }

    void setY(double y_) {
        y = y_;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }
};

int Wektor2D::num_wek = 0;
