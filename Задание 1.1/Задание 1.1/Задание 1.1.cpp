#include <iostream> // Библиотека ввода - вывода
#include <cmath> // Библиотека математических функций для C++
using namespace std;

/**brief Функция для расчета a
*\param x Параметр x
*\param y Параметр y
*\param z параметр z
**/
double GetA(const double x, const double y, const double z);

/**brief Функция для расчета b
*\param x Параметр x
*\param y Параметр y
*\param z параметр z
**/
double GetB(const double x, const double y, const double z);

int main()
{
    const double x = 0.2;
    const double y = 0.004;
    const double z = 1.1;

    auto a = GetA(x, y, z);
    auto b = GetB(x, y, z);

    cout << "x = " << x << "; y = " << y << "; z = " << z << ";\n";
    cout << "a = " << a << "\nb = " << b << endl;

    return 0;
}

double GetA(double x, double y, double z) {

    const auto c = pow(x * x + z, 2); // Расчет промежуточного значения //
    return pow(sin(c), 3) - pow(x / y, 0.5);
}

double GetB(double x, double y, double z) {
    return x * x / z + cos((x + y) * (x + y) * (x + y));
}
