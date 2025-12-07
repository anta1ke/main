#include <stdio.h>
#include <locale.h>

/**
 * @brief рассчитывает количество Мегабайт
 * @param bytes - количество байт
 * @return возвращает количество Мегабайт
 */
double getMegabyte(const double bytes);

/**
 * @brief рассчитывает количество Гигабайт
 * @param bytes - количество байт
 * @return возвращает количество Гигабайт
 */
double getGigabyte(const double bytes);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программа выполнена корректно
 */
int main(void)
{
    // Установка русской локали для корректного отображения
    setlocale(LC_ALL, "Russian");

    double bytes = 0;

    printf("Введите объем информации в байтах: ");
    scanf_s("%lf", &bytes);

    // Проверка на отрицательное значение
    if (bytes < 0) {
        printf("Ошибка: объем не может быть отрицательным!\n");
        return 1;
    }

    printf("\nРезультаты конвертации:\n");
    printf("Количество байт: %.2lf\n", bytes);
    printf("Количество мегабайт: %.6lf\n", getMegabyte(bytes));
    printf("Количество гигабайт: %.6lf\n", getGigabyte(bytes));

    return 0;
}

double getMegabyte(const double bytes)
{
    return bytes / 1024.0 / 1024.0;
}

double getGigabyte(const double bytes)
{
    return bytes / 1024.0 / 1024.0 / 1024.0;
}
