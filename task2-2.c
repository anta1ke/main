#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <float.h>

/**
* @brief Считывает вещественное значение с клавиатуры и проверяет на правильность ввода
* @return Возвращает считанное значение, если оно введено корректно, иначе - ошибка
*/
double getValue();

/**
* @brief Расчитывает первую функцию
* @param x - значение переменной x
* @param a - значение переменной a
* @return Возвращает функцию
*/
double func1();

/**
* @brief Расчитывает вторую функцию
* @param x - значение переменной x
* @param a - значение переменной a
* @return Возвращает функцию
*/
double func2();

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа выполнена корректно
*/
int main(void) {
	setlocale(LC_ALL, "Russian");

	const double a = 0.9;
	printf("Введите значение переменной x: ");
	double x = getValue();
	if (x <= 1 + DBL_EPSILON) {
		printf("y = %.3lf.", func2(a,x));
	}
	else {
		printf("y = %.3lf.", func1(a,x));
	}
	return 0;
}

double getValue() {
	double value = 0;
	if (!scanf_s("%lf", &value)) {
		printf("Error/n");
		abort();
	}
	return value;
}

double func1(const double a, const double x) {
	return  a * log10(x) + sqrt(fabs(x));
}

double func2(const double a, const double x) {
	return 2 * a * cos(x) + 3 * x * x;
}
