#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Функция для расчета y
* \param x Аргумент x
* \return Значение y
*/
double GetY(const double x);

/**
* \brief Ввод значения х в программу
* \return Конечное значение
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    const double stepX = 0.1, limit = 2.01;
    double x = 1;


    while (x <= limit) 
    { 
        cout << " Veriable x: " << x << " |" << " Veriable function: " << GetY(x) << endl; 
        x += stepX; 
    }
}

double GetY(const double x)
{
    return (0.1 * pow (x,2) - (x * log(x)));
} 