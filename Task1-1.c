#include <stdio.h>
#include <math.h>

/**
* @brief Расчитывает значение выражения А
* @param X - значение параметра X
* @param Y - значение параметра Y
* @param Z - значение параметра Z
* @return Возвращает значение
*/
double defA(const double X, const double Y, const double Z);

/**
* @brief Расчитывает значение выражения B
* @param X - значение параметра X
* @param Y - значение параметра Y
* @param Z - значение параметра Z
* @return Возвращает значение
*/
double defB(const double X, const double Y, const double Z);

/**
* @brief Точка входа в программу
* @return Возращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	const double X = 2.0;
	const double Y = 0.7;
	const double Z = -1;

	printf("A = %.6f\nB = %.6f", defA(X, Y, Z), defB(X, Y, Z));

	return 0;
}
double defA(const double X, const double Y, const double Z)
{
	return(cbrt(X * Y * Z + fabs(Z * sin(Y))));
}
double defB(const double X, const double Y, const double Z)
{
	return(Y * cos(X * Z * sin(Y)) + 3);
}
