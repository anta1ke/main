#include <stdio.h>
#include <locale.h>

/**
 * @brief рассчитывает общее сопротивление последовательного соединения
 * @param r1 - сопротивление первого резистора
 * @param r2 - сопротивление второго резистора
 * @param r3 - сопротивление третьего резистора
 * @return возвращает общее сопротивление цепи
 */
double getTotalResistance(const double r1, const double r2, const double r3);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    // Установка русской локали для корректного отображения
    setlocale(LC_ALL, "Russian");

    double r1 = 0, r2 = 0, r3 = 0;

    printf("Введите сопротивление первого резистора (Ом): ");
    scanf_s("%lf", &r1);

    printf("Введите сопротивление второго резистора (Ом): ");
    scanf_s("%lf", &r2);

    printf("Введите сопротивление третьего резистора (Ом): ");
    scanf_s("%lf", &r3);

    // Проверка на отрицательные значения
    if (r1 < 0 || r2 < 0 || r3 < 0) {
        printf("Ошибка: сопротивление не может быть отрицательным!\n");
        return 1;
    }

    printf("\nРезультаты расчета:\n");
    printf("Сопротивление R1: %.2lf Ом\n", r1);
    printf("Сопротивление R2: %.2lf Ом\n", r2);
    printf("Сопротивление R3: %.2lf Ом\n", r3);
    printf("Общее сопротивление цепи: %.2lf Ом\n", getTotalResistance(r1, r2, r3));

    return 0;
}

double getTotalResistance(const double r1, const double r2, const double r3)
{
    return r1 + r2 + r3;
}
