#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Triangle {
private:
    double a, b, c;

    double toDegrees(double radians) {
        return radians * 180.0 / 3.141592653589793;
    }

public:
    Triangle() {
        a = b = c = 1;
    }

    bool setSides(double sideA, double sideB, double sideC) {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0) {
            cout << "Ошибка: стороны треугольника должны быть больше нуля." << endl;
            return false;
        }

        if (sideA + sideB <= sideC || sideA + sideC <= sideB || sideB + sideC <= sideA) {
            cout << "Ошибка: треугольник с такими сторонами не существует." << endl;
            return false;
        }

        a = sideA;
        b = sideB;
        c = sideC;
        return true;
    }

    double getA() {
        return a;
    }
    
    double getB() {
        return b;
    }

    double getC() {
        return c;
    }

    void printSides() {
        cout << "Сторона a = " << a << endl;
        cout << "Сторона b = " << b << endl;
        cout << "Сторона c = " << c << endl;
    }

    bool changeSize(double percent) {
        double k = 1 + percent / 100.0;

        if (k <= 0) {
            cout << "Ошибка: после изменения стороны должны оставаться положительными." << endl;
            return false;
        }

        a *= k;
        b *= k;
        c *= k;

        return true;
    }

    double middleline(char side) {
        if (side == 'a' || side == 'A') {
            return a / 2.0;
        }
        else if (side == 'b' || side == 'B') {
            return b / 2.0;
        }
        else if (side == 'c' || side == 'C') {
            return c / 2.0;
        }
        else {
            cout << "Ошибка: такой стороны нет." << endl;
            return 0;
        }
    }

    double angleA() {
        return toDegrees(acos((b * b + c * c - a * a) / (2 * b * c)));
    }

    double angleB() {
        return toDegrees(acos((a * a + c * c - b * b) / (2 * a * c)));
    }

    double angleC() {
        return toDegrees(acos((a * a + b * b - c * c) / (2 * a * b)));
    }

    void printAngles() {
        cout << "Угол A = " << angleA() << " градусов" << endl;
        cout << "Угол B = " << angleB() << " градусов" << endl;
        cout << "Угол C = " << angleC() << " градусов" << endl;
    }

    string triangleTypeByAngles() {
        double A = angleA();
        double B = angleB();
        double C = angleC();

        const double EPS = 0.0001;

        if (abs(A - 90) < EPS || abs(B - 90) < EPS || abs(C - 90) < EPS) {
            return "Прямоугольный";
        }
        else if (a > 90 || B > 90 || C > 90) {
            return "Тупоугольный";
        }
        else {
            return "Остроугольный";
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle triangle;

    cout << "Создание треугольника" << endl;

    if (!triangle.setSides(3, 4, 5)) {
        return 0;
    }

    cout << endl << "Исходные стороны:" << endl;
    triangle.printSides();

    cout << endl << "Углы треугольника:" << endl;
    triangle.printAngles();

    cout << endl << "Вид треугольника на углам: ";
    cout << triangle.triangleTypeByAngles() << endl;

    cout << endl << "Средняя линия к стороне a: ";
    cout << triangle.middleline('a') << endl;

    cout << endl << "Увеличение сторон на 20%" << endl;
    triangle.changeSize(20);

    cout << endl << "Стороны после увеличения:" << endl;
    triangle.printSides();

    cout << endl << "Уменьшение сторон на 10%" << endl;
    triangle.changeSize(-10);

    cout << endl << "Стороны после уменьшения:" << endl;
    triangle.printSides();

    cout << endl << "Проверка ошибки:" << endl;
    triangle.setSides(1, 2, 10);

    cin.get();

    return 0;
}