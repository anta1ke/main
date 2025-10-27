#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
 * @brief вычисляет значение функции y = 0.1x^2 - x*ln(x)
 * @param x - аргумент функции
 * @param y - указатель на результат функции
 * @return возвращает 1 при успешном расчете, 0 при ошибке
 */
int calculateFunction(const double x, double* y);

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

    double start = 0, end = 0, step = 0;

    printf("Введите начало интервала x: ");
    start = getValue();

    printf("Введите конец интервала x: ");
    end = getValue();

    printf("Введите шаг табулирования ∆x: ");
    step = getValue();

    // Проверка корректности интервала
    if (start >= end) {
        printf("Ошибка: начало интервала должно быть меньше конца!\n");
        return 1;
    }

    // Проверка корректности шага
    if (step <= 0) {
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

    while (x <= end + 1e-9) { // +1e-9 для учета погрешности вычислений
        double y;
        if (calculateFunction(x, &y)) {
            printf("%.2lf\t\t%.6lf\n", x, y);
        }
        else {
            printf("%.2lf\t\tне определена\n", x);
        }
        x += step;
        point_count++;

        // Защита от бесконечного цикла
        if (point_count > 10000) {
            printf("Превышено максимальное количество точек. Возможно, шаг слишком мал.\n");
            break;
        }
    }

    return 0;
}

int calculateFunction(const double x, double* y)
{
    // Проверка на возможность вычисления ln(x)
    if (x <= 0) {
        return 0;
    }

    // Вычисление функции y = 0.1x^2 - x*ln(x)
    *y = 0.1 * x * x - x * log(x);
    return 1;
}

double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Ошибка ввода!\n");
        // Очистка буфера ввода
        while (getchar() != '\n');
        printf("Пожалуйста, введите числовое значение: ");
        return getValue(); // рекурсивный вызов для повторного ввода
    }
    return value;
}
