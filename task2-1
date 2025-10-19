#include <stdio.h>
#include <locale.h>

/**
 * @brief рассчитывает объем параллелепипеда
 * @param length - длина параллелепипеда
 * @param width - ширина параллелепипеда
 * @param height - высота параллелепипеда
 * @return возвращает объем параллелепипеда
 */
double getVolume(const double length, const double width, const double height);

/**
 * @brief рассчитывает площадь поверхности параллелепипеда
 * @param length - длина параллелепипеда
 * @param width - ширина параллелепипеда
 * @param height - высота параллелепипеда
 * @return возвращает площадь поверхности параллелепипеда
 */
double getSurfaceArea(const double length, const double width, const double height);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");

    printf("Введите длину параллелепипеда: ");
    double length = getValue();
    checkValue(length);

    printf("Введите ширину параллелепипеда: ");
    double width = getValue();
    checkValue(width);

    printf("Введите высоту параллелепипеда: ");
    double height = getValue();
    checkValue(height);

    printf("Объем параллелепипеда равен %.2lf\n", getVolume(length, width, height));
    printf("Площадь параллелепипеда равна %.2lf\n", getSurfaceArea(length, width, height));

    return 0;
}

double getVolume(const double length, const double width, const double height)
{
    return length * width * height;
}

double getSurfaceArea(const double length, const double width, const double height)
{
    return 2 * (length * width + width * height + height * length);
}

double getValue()
{
    double value = 0;
    if (!scanf_s("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0)
    {
        printf("Value have to be positive\n");
        abort();
    }
}
