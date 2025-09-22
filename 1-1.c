#include <stdio.h>
#include <math.h>

/**
* @brief –асчитывает значение выражени€ ј и B
* @param X - значение параметра X
* @param Y - значение параметра Y
* @param Z - значение параметра Z
* @return ¬озвращает значение выражени€ A и B
*/
int main()
{
	double x = 2.0;
	double y = 1.5;
	double z = 0.8;

	double a = x * y * z + abs(z * sin(y));
	double b = y * cos(x * z * sin(y)) + 3;

	printf("a = x * y * z + abs(z * sin(y)) = %.6f\n", a);
	printf("b = y * cos(x * z * sin(y)) + 3 = %.6f\n", b);

	return 0;
}