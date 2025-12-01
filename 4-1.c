#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define scanf_s scanf

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Считывает введённое с клавиатуры вещественное значение и проверяет на правильность ввода
 * @return введённое значение
 */
double getDouble(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(char* message);

/**
 * @brief Считывает значения элементов массива
 * @param arr массив
 * @param size размер массива
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Выводит массив (его элементы)
 * @param arr массив
 * @param size размер массива
 */
void printArray(const int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами в пределах введённого пользователем диапазона
 * @param arr массив
 * @param size размер массива
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Создаёт копию массива
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Находит сумму элементов, значения которых по модулю меньше 10
 * @param arr массив
 * @param size размер массива
 * @return сумма элементов
 */
int sumModulusLessThanTen(const int* arr, const size_t size);

/**
 * @brief Выводит индексы элементов, значения которых больше значения последующего элемента
 * @param arr массив
 * @param size размер массива
 */
void printIndicesGreaterThanNext(const int* arr, const size_t size);

/**
 * @brief Умножает все элементы массива, кратные 3, на третий элемент массива
 * @param source исходный массив
 * @param destination массив для изменений (копия)
 * @param size размер массива
 */
void multiplyMultiplesOfThree(const int* source, int* destination, const size_t size);

/**
 * @brief Выделяет память для массива заданного размера с обработкой ошибок
 * @param size размер массива
 * @return указатель на выделенную память
 */
int* allocateArray(size_t size);

/**
 * @brief Освобождает память и выводит сообщение об ошибке
 * @param arr массив для освобождения
 * @param message сообщение об ошибке
 */
void handleError(int* arr, char* message);

/**
 * @brief RANDOM - заполнение массива случайными числами в пределах введённого пользователем диапазона
 * @brief MANUAL - заполнение массива вручную
 */
enum { RANDOM = 1, MANUAL };

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1.
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    size_t size = getSize("Введите размер массива: ");
    int* arr = allocateArray(size);

    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами\n"
        "%d - вручную\n", RANDOM, MANUAL);
    int choice = Value();

    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        handleError(arr, "Ошибка выбора!");
    }

    printf("Исходный массив: ");
    printArray(arr, size);

    printf("1. Сумма элементов по модулю меньше 10: %d\n", sumModulusLessThanTen(arr, size));

    printf("2. Индексы элементов, больших следующего: ");
    printIndicesGreaterThanNext(arr, size);

    printf("3. Массив после умножения элементов кратных 3 на третий элемент (%d): ", arr[2]);
    int* modifiedArr = copyArray(arr, size);
    printArray(modifiedArr, size);
    free(modifiedArr);

    printf("Исходный массив (не изменен): ");
    printArray(arr, size);

    free(arr);
    return 0;
}

int Value(void)
{
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        fprintf(stderr, "Ошибка ввода!\n");
        exit(1);
    }
    return value;
}

double getDouble(void)
{
    double value = 0;
    int result = scanf("%lf", &value);
    if (result != 1) {
        fprintf(stderr, "Ошибка ввода!\n");
        exit(1);
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        fprintf(stderr, "Размер должен быть положительным!\n");
        exit(1);
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент %zu: ", i + 1);
        arr[i] = Value();
    }
}

void printArray(const int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fillRandom(int* arr, const size_t size)
{
    int start = Value();
    int end = Value();

    printf("Диапазон заполнения: [-40; 40]\n");
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

int* copyArray(const int* arr, const size_t size)
{
    int* copyArr = allocateArray(size);
    
    for (size_t i = 0; i < size; i++)
    {
        copyArr[i] = arr[i];
    }
    return copyArr;
}

int sumModulusLessThanTen(const int* arr, const size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (abs(arr[i]) < 10)
        {
            result += arr[i];
        }
    }
    return result;
}

void printIndicesGreaterThanNext(const int* arr, const size_t size)
{
    int found = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("%zu ", i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("таких элементов нет");
    }
    printf("\n");
}

void multiplyMultiplesOfThree(const int* source, int* destination, const size_t size)
{
    int thirdElement = source[2];
    
    for (size_t i = 0; i < size; i++)
    {
        destination[i] = source[i];
        if (source[i] % 3 == 0)
        {
            destination[i] *= thirdElement;
        }
    }
}

void handleError(int* arr, char* message)
{
    if (arr != NULL)
    {
        free(arr);
    }
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int* allocateArray(size_t size)
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        handleError(NULL, "Ошибка выделения памяти!");
    }
    return arr;
}
