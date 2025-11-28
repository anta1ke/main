#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/**
 * @return Ввод данных типа int
 * @return Введенное значение
 */
int Value();

size_t getSize(char* message);

void fillArray(int* arr, const size_t size);
void fillRandom(int* arr, const size_t size);
void printArray(int* arr, const size_t size);
int sumLessThanTen(int* arr, const size_t size);
void printIndicesGreaterThanNext(int* arr, const size_t size);
void multiplyMultiplesOfThree(int* arr, const size_t size);

enum { RANDOM = 1, MANUAL };

int main()
{
    setlocale(LC_ALL, "Russian");

    srand(time(NULL));
    size_t size = getSize("Введите размер массива: ");

    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }

    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
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
        printf("error");
        free(arr);
        exit(1);
    }

    printf("Исходный массив: ");
    printArray(arr, size);

    printf("Сумма элементов по модулю меньше 10: %d\n", sumLessThanTen(arr, size));

    printf("Индексы элементов, больших следующего: ");
    printIndicesGreaterThanNext(arr, size);

    multiplyMultiplesOfThree(arr, size);
    printf("Массив после умножения элементов кратных 3 на третий элемент: ");
    printArray(arr, size);

    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент %zu: ", i);
        arr[i] = Value();
    }
}

void fillRandom(int* arr, const size_t size)
{
    printf("Диапазон от: ");
    int start = Value();
    printf("Диапазон до: ");
    int end = Value();

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (end - start + 1) + start;
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumLessThanTen(int* arr, const size_t size)
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

void printIndicesGreaterThanNext(int* arr, const size_t size)
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

void multiplyMultiplesOfThree(int* arr, const size_t size)
{
    if (size < 3)
    {
        printf("ERROR: массив должен содержать минимум 3 элемента\n");
        return;
    }

    int thirdElement = arr[2];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 3 == 0)
        {
            arr[i] *= thirdElement;
        }
    }
}
