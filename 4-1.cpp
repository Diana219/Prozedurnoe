#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

using namespace std;

/**
* \brief Заполнение массива случайными числами
* \param array Массив
* \param size Размер массива
* \param min Минимально возможное число
* \param max Максимально возможное число
**/
void RandomArray(int* array, const size_t size, const int min, const int max);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void UserArray(int* array, const size_t size);

/**
* \brief Сумма элементов, по модулю меньших 10
* \param array Массив
* \param size Размер массива
**/
int SumNumbers(int* array, const size_t size);

/**
* \brief Количество элементов(значения которых больше значения последующего)
* \param array Массив
* \param size Размер массива
* \param A значение по условию
**/
void NumberElements(int* array, const size_t size);

/**
* \brief Новый массив(все элементы, кратные 3, умножаются на 3 элемент массива)
* \param array Массив
* \param second_array Обработанный массив
* \param size Размер массива
**/
void SecondArray(int* array, int* second_array, const size_t size);

enum class ArrayType
{
	RandomNumber,
	UserNumber
};

int main()
{
	setlocale(LC_ALL, "ru");

	cout.precision(3);
	cout << fixed;

	const int MIN = -40, MAX = 40;
	int sum;

	cout << "Please input array length: ";
	size_t size;
	cin >> size;
        const size_t size_array = size;
	
	int* array = new int[size_array];
	int* second_array = new int[size_array];

	cout << "\nChoose array:\n" << "1) Array with random number\n" << "2) Array with user number\n" << "1 or 2: ";
	int choice;
	cin >> choice;

	const auto arraytype = static_cast<ArrayType>(choice);

	switch (arraytype)
	{
	case ArrayType::RandomNumber:
	{
		RandomArray(array, size, MIN, MAX);
		break;
	}
	case ArrayType::UserNumber:
	{
		UserArray(array, size);
		break;
	}
	default:
		break;
	}

	cout << "Сумма элементов, значения по модулю которых меньше 10: " << SumNumbers(array, size) << endl;

	cout << "Индексы элементов, значения которых больше значения последующего:\n";

	NumberElements(array, size);
	cout << endl;
	cout << "Новый массив, в котором элементы, не кратные 3, умножаются на третий элемент: " << endl; SecondArray(array, second_array, size);

	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}
	if (second_array != nullptr)
	{
		delete[] second_array;
		second_array = nullptr;
	}
}

void RandomArray(int* array, const size_t size, const int min, const int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	const uniform_int_distribution<> uniformIntDistribution(min, max);

	for (size_t i = 0; i < size; ++i)
		array[i] = uniformIntDistribution(gen);
	for (size_t i = 0; i < size; ++i)
	{
		cout << "array[" << i << "] = " << array[i] << endl;
	}
}

void UserArray(int* array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
	}
}

int SumNumbers(int* array, const size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (abs(array[i]) < 10)
		{
			sum += array[i];
		}
	}
	return sum;
}

void NumberElements(int* array, const size_t size)
{
	bool k = false;
	for (size_t i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) {
			cout << "Номер элемента: " << i << endl;
			k = true;
		}
	}
	if (k == false) {
		cout << "Таких элементов нет ";
	}
}

void SecondArray(int* array, int* second_array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] % 3)
		{
			second_array[i] = array[i] * array[2];
		}
		else {
			second_array[i] = array[i];
		}
	}
	for (size_t i = 0; i < size; i++)
		cout << second_array[i] << " ";
}
