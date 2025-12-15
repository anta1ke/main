#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h> 
#define scanf_s scanf

/**
 * @brief Считывает введённое с клавиатуры целое значение и проверяет на правильность ввода
 * @return введённое значение
 */
int Value(void);

/**
 * @brief Выводит текстовое сообщение о необходимости ввода размера массива, проверяет ввод на правильность, задаёт размер массива
 * @param message текстовое сообщение о необходимости ввода массива
 * @return размер массива (количество его элементов)
 */
size_t getSize(const char* message);

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
 * @brief Создаёт копию массива. Все дальнейшие изменения происходят в этом массиве.
 * @param arr массив
 * @param size размер массива
 * @return полученный массив
 */
int* copyArray(const int* arr, const size_t size);

/**
 * @brief Заменяет минимальный по модулю положительный элемент массива нулем
 * @param source исходный массив
 * @param destination массив для изменений (копия)
 * @param size размер массива
 * @return индекс замененного элемента или -1 если не найден
 */
int replaceMinPositiveWithZero(const int* source, int* destination, const size_t size);

/**
 * @brief Удаляет из массива все элементы, первая и последняя цифра которых четная
 * @param copyArr массив (будет изменен)
 * @param size размер массива
 * @return новый размер массива после удаления или 0 если все элементы удалены
 * @note Элементы не удаляются физически, а заменяются на 0 и перемещаются в конец
 */
size_t removeEvenFirstLastDigits(int* copyArr, const size_t size);

/**
 * @brief Перемещает нулевые элементы в конец массива
 * @param arr массив
 * @param size размер массива
 * @return массив с нулями в конце
 */
void moveZerosToEnd(int* arr, const size_t size);

/**
 * @brief Формирует массив A из массива D по правилу
 * @param copyArr массив (будет изменен)
 * @param size размер массива
 * @return 1 если успешно, 0 если в массиве нет элементов
 */
int formArrayFromD(int* copyArr, const size_t size);

/**
 * @brief Проверяет, является ли первая цифра числа четной
 * @param num число
 * @return true если первая цифра четная, иначе false
 */
bool isFirstDigitEven(const int num);

/**
 * @brief Проверяет, является ли последняя цифра числа четной
 * @param num число
 * @return true если последняя цифра четная, иначе false
 */
bool isLastDigitEven(const int num);

/**
 * @brief Находит минимальный по модулю положительный элемент в массиве
 * @param arr массив
 * @param size размер массива
 * @return индекс минимального по модулю положительного элемента или -1 если не найден
 */
int findMinPositive(const int* arr, const size_t size);

/**
 * @brief Выделяет память для массива заданного размера с обработкой ошибок
 * @param size размер массива
 * @return указатель на выделенную память
 */
int* allocateArray(const size_t size);

/**
 * @brief Освобождает память и выводит сообщение об ошибке
 * @param arr массив для освобождения
 * @param message сообщение об ошибке
 */
void handleError(int* arr, const char* message);

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

    // 1. Замена минимального по модулю положительного элемента нулем
    printf("\n1. Замена минимального по модулю положительного элемента нулем:\n");

    int minPositiveIndex = findMinPositive(arr, size);
    if (minPositiveIndex != -1)
    {
        printf("   Найден минимальный по модулю положительный элемент на индексе %d (значение: %d)\n",
            minPositiveIndex, arr[minPositiveIndex]);
    }
    else
    {
        printf("   Положительные элементы не найдены\n");
    }

    int* copyArr1 = copyArray(arr, size);
    int replacedIndex = replaceMinPositiveWithZero(arr, copyArr1, size);
    if (replacedIndex != -1)
    {
        printf("   Заменен элемент на индексе %d (было %d, стало 0)\n",
            replacedIndex, arr[replacedIndex]);
        printf("   Результат: ");
        printArray(copyArr1, size);
    }
    else
    {
        printf("   Положительные элементы не найдены\n");
    }
    free(copyArr1);

    // 2. Удаление элементов с четными первой и последней цифрами
    printf("\n2. Удаление элементов с четными первой и последней цифрами:\n");
    int* workArr2 = copyArray(arr, size);
    size_t newSize = removeEvenFirstLastDigits(workArr2, size);
    int* copyArr2 = copyArray(workArr2, newSize);
    free(workArr2);

    if (newSize == 0)
    {
        printf("   Все элементы были удалены\n");
    }
    else
    {
        printf("   Размер после удаления: %zu\n", newSize);
        printf("   Результат (ненулевые элементы): ");
        printArray(copyArr2, newSize);
    }
    free(copyArr2);

    // 3. Формирование массива A из массива D
    printf("\n3. Формирование массива A из массива D:\n");
    int* copyArr3 = copyArray(arr, size);
    if (formArrayFromD(copyArr3, size))
    {
        printf("   Массив D (исходный): ");
        printArray(arr, size);
        printf("   Массив A (результат): ");

        bool hasNonZero = false;
        for (size_t i = 0; i < size; i++)
        {
            if (copyArr3[i] != 0)
            {
                printf("%d ", copyArr3[i]);
                hasNonZero = true;
            }
        }
        if (!hasNonZero)
        {
            printf("все элементы нулевые");
        }
        printf("\n");
    }
    else
    {
        printf("   В массиве нет элементов для преобразования\n");
    }
    free(copyArr3);

    printf("\nИсходный массив (не изменен): ");
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

size_t getSize(const char* message)
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
    printf("Введите начало диапазона: ");
    int start = Value();
    printf("Введите конец диапазона: ");
    int end = Value();

    if (start > end) {
        fprintf(stderr, "Ошибка: начало диапазона не может быть больше конца\n");
        exit(1);
    }

    printf("Диапазон заполнения: [%d; %d]\n", start, end);
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

int replaceMinPositiveWithZero(const int* source, int* destination, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }

    int minIndex = findMinPositive(source, size);

    if (minIndex != -1)
    {
        destination[minIndex] = 0;
        return minIndex;
    }

    return -1;
}

bool isFirstDigitEven(const int num)
{
    if (num == 0) return true;

    int temp = abs(num);

    while (temp >= 10)
    {
        temp /= 10;
    }
    return temp % 2 == 0;
}

bool isLastDigitEven(const int num)
{
    if (num == 0) return true;
    return abs(num) % 2 == 0;
}

int findMinPositive(const int* arr, const size_t size)
{
    int minIndex = -1;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            if (minIndex == -1)
            {
                minIndex = (int)i;
            }
            else if (abs(arr[i]) < abs(arr[minIndex]))
            {
                minIndex = (int)i;
            }
        }
    }

    return minIndex;
}

size_t removeEvenFirstLastDigits(int* copyArr, const size_t size)
{
    size_t countRemoved = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (isFirstDigitEven(copyArr[i]) && isLastDigitEven(copyArr[i]))
        {
            copyArr[i] = 0;
            countRemoved++;
        }
    }

    if (countRemoved == 0)
    {
        printf("   Элементы для удаления не найдены\n");
        return size;
    }

    if (countRemoved == size)
    {
        printf("   Все элементы будут удалены\n");
        return 0;
    }
    moveZerosToEnd(copyArr, size);

    return size - countRemoved;
}

void moveZerosToEnd(int* arr, const size_t size)
{
    int nonZeroIndex = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex++;
        }
    }

    for (size_t i = nonZeroIndex; i < size; i++)
    {
        arr[i] = 0;
    }
}

int formArrayFromD(int* copyArr, const size_t size)
{
    bool hasElements = false;

    for (size_t i = 0; i < size; i++)
    {
        if (copyArr[i] != 0)
        {
            hasElements = true;

            if (i >= 2 && i <= 11)
            {
                copyArr[i] = -copyArr[i] * copyArr[i]; // -D_i^2
            }
        }
    }

    return hasElements ? 1 : 0;
}

void handleError(int* arr, const char* message)
{
    if (arr != NULL)
    {
        free(arr);
    }
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int* allocateArray(const size_t size)
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        handleError(NULL, "Ошибка выделения памяти!");
    }
    return arr;
}
