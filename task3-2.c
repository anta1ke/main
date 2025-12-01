#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

/**
* @brief Считывает целое значение с клавиатуры с проверкой ввода
* @return Возвращает считанное значение
*/
int getValue();

/**
* @brief Считывает вещественное значение с клавиатуры с проверкой ввода
* @return Возвращает считанное значение
*/
double getDouble();

/**
 * @brief Рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return Возвращает рассчитанное значение
 */
double getSumN(const int n);

/**
 * @brief Рассчитывает сумму членов последовательности с точностью e
 * @param e - заданная точность
 * @return Возвращает рассчитанное значение
 */
double getSumE(const double e);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Рассчитывает коэффициент рекуррентного выражения
 * @param i - текущий индекс
 * @return Возвращает рассчитанное значение коэффициента
 */
double getRecurent(const int i);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main(void) {
    setlocale(LC_ALL, "Russian");

    printf("Введите значение n: ");
    int n = getValue();
    checkPositive(n);
    printf("Сумма %d членов последовательности равна %.6lf\n", n, getSumN(n));

    printf("Введите значение e: ");
    double e = getDouble();
    checkPositive(e);
    printf("Сумма с точностью %.6lf равна %.6lf\n", e, getSumE(e));

    return 0;
}

int getValue() {
    int value = 0;
    if (scanf_s("%d", &value) != 1) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    return value;
}

double getDouble() {
    double value = 0;
    if (scanf_s("%lf", &value) != 1) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    return value;
}

void checkPositive(const double value) {
    if (value <= 0) {
        printf("Ошибка: значение должно быть положительным!\n");
        exit(1);
    }
}

double getSumN(const int n) {
    double result = 0.0;
    double current = 1.0;
    for (int k = 1; k < n; k++) {
        result += current;
        if (k < n) {
            current *= getRecurent(k);
        }
    }
    return result;
}

double getRecurent(const int k) {
    return -1.0 / ((2.0 * k) * (2.0 * k + 1));
}

double getSumE(const double e) {
    double result = 0.0;
    double current = 1.0;
    int k = 1;

    while (fabs(current) >= e) {
        result += current;
        current *= getRecurent(k);
        k++;
    }

    return result;
}
