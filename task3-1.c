#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <float.h>

/**
 * @brief вычисляет значение функции y = 0.1x^2 - x*ln(x)
 * @param x - аргумент функции
 * @return возвращает значение функции или NAN при ошибке
 */
double calculateFunction(const double x);

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");

    printf("Введите начало интервала x: ");
    double start = getValue();

    printf("Введите конец интервала x: ");
    double end = getValue();

    printf("Введите шаг табулирования ∆x: ");
    double step = getValue();

    // Проверка корректности интервала
    if (start >= end - DBL_EPSILON) {
        printf("Ошибка: начало интервала должно быть меньше конца!\n");
        return 1;
    }

    // Проверка корректности шага
    if (step <= DBL_EPSILON) {
        printf("Ошибка: шаг должен быть положительным!\n");
        return 1;
    }

    printf("\nТабулирование функции y = 0.1x^2 - x*ln(x)\n");
    printf("Интервал: [%.2lf, %.2lf]\n", start, end);
    printf("Шаг: %.2lf\n\n", step);
    printf("x\t\ty\n");
    printf("-----------------------\n");

    double x = start;
    int point_count = 0;

    while (x <= end + DBL_EPSILON) {
        double y = calculateFunction(x);

        if (!isnan(y)) {
            printf("%.2lf\t\t%.6lf\n", x, y);
        }
        else {
            printf("%.2lf\t\tне определена\n", x);
        }

        x += step;
        }
    }

    return 0;
}

double calculateFunction(double x)
{
    // Проверка на возможность вычисления ln(x)
    if (x <= DBL_EPSILON) {
        return NAN;
    }

    // Вычисление функции y = 0.1x^2 - x*ln(x)
    return 0.1 * x * x - x * log(x);
}

double getValue()
{
    double value = 0;
    if (scanf_s("%lf", &value) != 1)
    {
        printf("Ошибка ввода!\n");
    }
    return value;
}
