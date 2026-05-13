#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Triangle {
protected:
    double a;
    double b;
    double c;

public:
    Triangle();
    Triangle(double sideA, double sideB, double sideC);
    Triangle(const Triangle& other);
    virtual ~Triangle();

    bool exists() const;
    virtual double perimeter() const;
    virtual double area() const;
    double angleA() const;
    double angleB() const;
    double angleC() const;
    virtual void print() const;
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle();
    EquilateralTriangle(double side);
    EquilateralTriangle(const EquilateralTriangle& other);
    ~EquilateralTriangle();

    bool isEquilateral() const;
    void print() const override;
};

double toDegrees(double radians) {
    return radians * 180.0 / 3.141592653589793;
}

Triangle::Triangle() {
    cout << "Вызван конструктор Triangle без параметров" << endl;
    a = 1;
    b = 1;
    c = 1;
}

Triangle::Triangle(double sideA, double sideB, double sideC) {
    cout << "Вызван конструктор Triangle c параметрами" << endl;
    a = sideA;
    b = sideB;
    c = sideC;
}

Triangle::Triangle(const Triangle& other) {
    cout << "Вызван конструктор копирования Triangle" << endl;
    a = other.a;
    b = other.b;
    c = other.c;
}

Triangle::~Triangle() {
    cout << "Вызван деструктор Triangle" << endl;
}

bool Triangle::exists() const {
    return a > 0 && b > 0 && c > 0 &&
           a + b > c && a + c > b && b + c > a;
}

double Triangle::perimeter() const {
    if (!exists()) {
        return 0;
    }

    return a + b + c;
}

double Triangle::area() const {
    if (!exists()) {
        return 0;
    }

    double p = perimeter() / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::angleA() const {
    if (!exists()) {
        return 0;
    }

    return toDegrees(acos((b * b + c * c - a * a) / (2 * b * c)));
}

double Triangle::angleB() const {
    if (!exists()) {
        return 0;
    }

    return toDegrees(acos((a * a + c * c - b * b) / (2 * a * c)));
}

double Triangle::angleC() const {
    if (!exists()) {
        return 0;
    }

    return toDegrees(acos((a * a + b * b - c * c) / (2 * a * b)));
}

void Triangle::print() const {
    cout << "Треугольник" << endl;
    cout << "Стороны: a = " << a << ", b = " << b << ", c = " << c << endl;

    if (!exists()) {
        cout << "Треугольник не существует" << endl;
        return;
    }

    cout << "Угол A = " << angleA() << endl;
    cout << "Угол B = " << angleB() << endl;
    cout << "Угол C = " << angleC() << endl;
    cout << "Периметр = " << perimeter() << endl;
    cout << "Площадь = " << area() << endl;
}

EquilateralTriangle::EquilateralTriangle() : Triangle(1, 1, 1) {
    cout << "Вызван конструктор EquilateralTriangle без параметров" << endl;
}

EquilateralTriangle::EquilateralTriangle(double side) : Triangle(side, side, side) {
    cout << "Вызван конструктор EquilateralTriangle с параметрами" << endl;
}

EquilateralTriangle::EquilateralTriangle(const EquilateralTriangle& other) : Triangle(other) {
    cout << "Вызван конструктор копирования EquilateralTriangle" << endl;
}

EquilateralTriangle::~EquilateralTriangle() {
    cout << "Вызван деструктор EquilateralTriangle" << endl;
}

bool EquilateralTriangle::isEquilateral() const {
    return exists() && a == b && b == c;
}

void EquilateralTriangle::print() const {
    cout << "Равносторонний треугольник" << endl;
    cout << "Сторона = " << a << endl;

    if (!isEquilateral()) {
        cout << "Фигура не является равносторонним треугольником" << endl;
        return;
    }

    cout << "Углы: 60, 60, 60" << endl;
    cout << "Периметр = " << perimeter() << endl;
    cout << "Площадь = " << area() << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << fixed << setprecision(2);

    const int K = 3;
    const int L = 3;

    Triangle triangles[K] = {
        Triangle(3, 4, 5),
        Triangle(6, 7, 8),
        Triangle(5, 5, 6)
    };

    EquilateralTriangle equilateralTriangles[L] = {
        EquilateralTriangle(4),
        EquilateralTriangle(7),
        EquilateralTriangle(5)
    };

    cout << endl << "Сведения о треугольниках" << endl;

    double sumArea = 0;

    for (int i = 0; i < K; i++) {
        cout << endl << "Треугольник №" << i + 1 << endl;
        triangles[i].print();
        sumArea += triangles[i].area();
    }

    double averageArea = sumArea / K;

    cout << endl << "Средняя площадь треугольников = " << averageArea << endl;

    cout << endl << "Сведения о равносторонних треугольниках" << endl;

    int maxIndex = 0;

    for (int i = 0; i < L; i++) {
        cout << endl << "Равносторонний треугольник №" << i + 1 << endl;
        equilateralTriangles[i].print();

        if (equilateralTriangles[i].area() > equilateralTriangles[maxIndex].area()) {
            maxIndex = i;
        }
    }

    cout << endl << "Наибольший равносторонний треугольник:" << endl;
    equilateralTriangles[maxIndex].print();

    cin.get();

    return 0;
}