#pragma once

// РОБОТА З ДИНАМІЧНИМИ ОДНОВИМІРНИМИ МАСИВАМИ в С++

#include <iostream>
#include <windows.h>  // SetConsoleOutputCP
#include <stdexcept>  // для роботи з винятками
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи функцій з прикладу 1d_array.cpp
// https://gist.github.com/sunmeat/220a03a64a8b2ff4a33fc28c7b03c77e
int* allocateArray(int size);
void fillArrayWithRandomValues(int* ar, int size);
void printArray(int* ar, int size);
int* addElementAtEnd(int* ar, int& size, int value);
int* addElementAtStart(int* ar, int& size, int value);
int* removeElementAtEnd(int* ar, int& size);

// Домашнє завдання – реалізувати мінімум 6 функцій із 17
int* removeFirstElement(const int* ar, int& size);
int* removeElementAtIndex(const int* ar, int& size, const int index);
int* clearArray(const int* ar, int& size);
int* removeElementsGreaterThan(int* ar, int& size, const int number);
int* insertElementAtIndex(const int* ar, int& size, const int value,
    const int index);
int* fillNaturalSequence(int* ar, const int size);
int* userFillArray(int* ar, const int size);
int* sortAscending(int* ar, const int size);
int* sortDescending(int* ar, const int size);
void reverseArray(int* ar, const int start, const int end);
int* rotateArray(int* ar, const int size, int rotation);
double arrayArithmeticMean(const int* ar, const int size);
int countEvenNumbers(const int* ar, const int size);
long long multiplyAllElements(const int* ar, const int size);
int findMaxElement(const int* ar, const int size);
// const int* ar, тому що return newArray


// Функція для виділення пам'яті під масив
int* allocateArray(int size)
{
    if (size > 0 && size < 1000000)
        return new int[size];
    else
        throw invalid_argument("Invalid size");
}


// Функція для запису випадкових значень в масив
void fillArrayWithRandomValues(int* ar, int size)
{
    for (int i = 0; i < size; ++i) {
        ar[i] = rand() % 100;
    }
}


// Функція для показу масиву
void printArray(int* ar, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << ar[i] << ", ";
    }
    cout << "\n\n";
}


// Функція для додавання одного елемента в кінець масиву
int* addElementAtEnd(int* ar, int& size, int value)
{
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = ar[i];
    }
    newArray[size] = value;
    delete[] ar;
    ++size;
    return newArray;
}


// Функція для додавання елемента на початок масиву
int* addElementAtStart(int* ar, int& size, int value)
{
    int* newArray = new int[size + 1];
    newArray[0] = value;
    for (int i = 0; i < size; ++i) {
        newArray[i + 1] = ar[i];
    }
    delete[] ar;
    ++size;
    return newArray;
}


// Функція для видалення останнього елемента масиву
int* removeElementAtEnd(int* ar, int& size)
{
    if (size <= 0) return ar;
    int* newArray = new int[size - 1];
    for (int i = 0; i < size - 1; ++i) {
        newArray[i] = ar[i];
    }
    delete[] ar;
    --size;
    return newArray;
}


// 14 вправ

// 1. Функція для видалення першого елемента масиву
int* removeFirstElement(const int* ar, int& size)
{
    if (size <= 0 || (size > 0 && ar == nullptr))
        throw invalid_argument("Некоректний розмір або масив");
    if (size == 1) {
        delete[] ar;
        size = 0;
        return nullptr;
    }
    int* newArray = new int[size - 1];
    for (int i = 0; i < size - 1; ++i) {
        newArray[i] = ar[i + 1];
    }
    delete[] ar;
    --size;
    return newArray;
}


// 2. Функція для видалення елемента з позиції з індексом 
// в середині масиву
int* removeElementAtIndex(const int* ar, int& size, const int index)
{
    if (size <= 0 || index < 0 || index >= size || (size > 0 && ar == nullptr))
        throw invalid_argument("Некоректний розмір, індекс або масив");
    if (size == 1) {
        delete[] ar;
        size = 0;
        return nullptr;
    }  // реалізацію умови про середину масиву див. в main()
    int* newArray = new int[size - 1];
    int j = 0;
    for (int i = 0; i < size && j < size - 1; ++i) {
        if (i != index) {
            newArray[j] = ar[i];  // виникло C6386, && j < size - 1
            ++j;
        }
    }
    delete[] ar;
    --size;
    return newArray;
}


// 3. Функція для видалення всіх елементів масиву
int* clearArray(const int* ar, int& size)
{
    if (size < 0) throw invalid_argument("Некоректний розмір");
    delete[] ar;
    size = 0;
    return nullptr;
}


// 5. Функція для видалення всіх елементів масиву, 
// які більше заданого числа
int* removeElementsGreaterThan(int* ar, int& size, const int number)
{
    if (size <= 0 || (size > 0 && ar == nullptr))
        throw invalid_argument("Некоректний розмір або масив");

    if (size == 1 && ar[0] >= number) {
        delete[] ar;
        size = 0;
        return nullptr;
    }

    // Визначення розміру нового масиву за умовою входження елементів
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] <= number)
            ++newSize;
    }

    if (newSize == size) return ar;  // якщо всі елементи збереглися

    if (newSize == 0) {
        delete[] ar;
        size = 0;
        return nullptr;
    }

    // Створення та заповнення нового масиву елементами
    int* newArray = new int[newSize];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] <= number)
            newArray[j++] = ar[i];
    }

    delete[] ar;
    size = newSize;
    return newArray;
}


// 6. Функція для вставки елемента на позицію з індексом 
// в середині масиву
int* insertElementAtIndex(const int* ar, int& size, const int value,
    const int index)
{
    if (size < 0 || index < 0 || index > size || (size > 0 && ar == nullptr))
        throw invalid_argument("Некоректний розмір, індекс або масив");
    int* newArray = new int[size + 1];
    newArray[index] = value;
    for (int i = 0; i < index && i < size; ++i) {
        newArray[i] = ar[i];  // тут було C6386
    }
    // Додаткові перевірки начебто усувають попередження C6386
    // https://learn.microsoft.com/ru-ru/cpp/code-quality/c6386?view=msvc-170
    for (int i = index; i < size && (i + 1 < size + 1); ++i) {
        newArray[i + 1] = ar[i];
    }
    delete[] ar;
    ++size;
    return newArray;
}


// 7. Функція для заповнення масиву послідовними числами від 1 до N
int* fillNaturalSequence(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");
    for (int i = 0; i < size; ++i) {
        ar[i] = i + 1;
    }
    return ar;
}


// 8. Функція для заповнення масиву числами, введеними з клавіатури
int* userFillArray(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");
    cout << "\nВведіть " << size << " чисел(числа):\n";
    for (int i = 0; i < size; ++i) {
        if (!(cin >> ar[i])) throw runtime_error("Введіть ціле число");
    }
    cout << "\n";
    return ar;
}


// 9. Функція для сортування масиву за зростанням
int* sortAscending(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");

    // Сортування методом Шелла
    // https://www.guru99.com/uk/shell-sort-algorithm.html
    // Домашня робота на тему "Пошук та сортування"

    // Зовнішній цикл визначає розмір інтервалу для групування елементів
    for (int interval = size / 2; interval > 0; interval /= 2) {
        // Починаємо з інтервалу size/2 (половина масиву) і зменшуємо 
        // його вдвічі на кожній ітерації, доки інтервал не стане 0

        // Середній цикл проходить по елементах, починаючи з позиції 
        // interval i вказує на поточний елемент, який буде 
        // порівнюватися та, можливо, зсуватися. 
        for (int i = interval; i < size; ++i) {
            // Починаємо з i = interval, щоб порівнювати елементи 
            // з відстанню interval

            // Зберігаємо поточний елемент ar[i] у тимчасовій змінній
            int temp = ar[i];
            // Ініціалізуємо j як поточний індекс i для зсуву елементів
            int j = i;

            // Внутрішній цикл виконує сортування вставками для 
            // елементів із кроком interval
            for (; j >= interval && ar[j - interval] > temp; j -= interval) {
                // Поки j >= interval (не виходимо за межі масиву зліва)
                // і елемент на позиції j - interval більший за temp,
                // зсуваємо більший елемент на позицію j
                ar[j] = ar[j - interval];
                // Зменшуємо j на interval, щоб перевірити попередній 
                // елемент у групі
            }
            // Після завершення внутрішнього циклу вставляємо temp 
            // у правильну позицію
            ar[j] = temp;
            // j вказує на місце, де temp має бути вставлений, 
            // щоб зберегти порядок
        }
    }
    return ar;
}


// 10. Функція для сортування масиву за спаданням
int* sortDescending(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");
    // Сортування методом бульбашки з оптимізацією
    bool swapped;  // прапорець для перевірки, чи були обміни
    // https://gist.github.com/sunmeat/4c2ad4c8d735647e00a57ba5d6eba9a9
    // Практика за презентацією "Пошук та сортування"
    for (int pr = 0; pr < size - 1; pr++) {  // до size-1 проходів!
        swapped = false;  // скидаємо прапорець перед кожним проходом
        for (int k = size - 1; k > 0; k--) {
            if (ar[k - 1] < ar[k]) {   // якщо попередній менший,
                int temp = ar[k];      // обмін елементів
                ar[k] = ar[k - 1];
                ar[k - 1] = temp;
                swapped = true;  // вказуємо, що обмін відбувся
            }
        }
        // Якщо обмінів не було, масив відсортований
        if (!swapped)
            break;  // перериваємо зовнішній цикл для оптимізації
    }
    return ar;
}


// 11. Функція для обертання масиву
int* rotateArray(int* ar, const int size, int rotation)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");

    if (size == 1) return ar; // обертання не потрібне

    // Нормалізація rotation: зменшуємо до діапазону [0, size)
    rotation = rotation % size;  // усуває кратні обертання
    if (rotation < 0) {  // обертання вправо
        rotation += size;          // конвертуємо в обертання вліво
    }
    if (rotation == 0) return ar; // уникаємо реверсування

    /*
    int* newArray = new int[size];
    for (int i = 0; i < size; ++i) {
        int j = (i + rotation) % size;
        newArray[j] = ar[i];
    }
    delete[] ar;
    return newArray;
    */

    // Алгоритм обертання через реверсування:
    // 1. Реверсуємо перші rotation елементів
    // 2. Реверсуємо решту елементів
    // 3. Реверсуємо весь масив
    reverseArray(ar, 0, rotation - 1);
    reverseArray(ar, rotation, size - 1);
    reverseArray(ar, 0, size - 1);
    // Повертаємо той самий масив, оскільки обертання на місці
    return ar;
}


// Допоміжна функція для реверсування частини масиву від start до end
void reverseArray(int* ar, int start, int end)
{
    if (start >= end) return;  // захист від некоректних меж
    while (start < end) {
        int temp = ar[start];
        ar[start] = ar[end];
        ar[end] = temp;
        start++;
        end--;
    }
}


// 13. Функція для підрахунку середнього арифметичного всіх елементів
double arrayArithmeticMean(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ar[i];
    }
    return (double)(sum) / size;
}


// 14. Функція для підрахунку кількості парних елементів масиву
int countEvenNumbers(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] % 2 == 0) count++;
    }
    return count;
}


// 16. Функція для підрахунку добутку всіх елементів масиву
long long multiplyAllElements(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");
    long long product = 1;
    for (int i = 0; i < size; ++i) {
        product *= ar[i];
    }
    return product;
}


// 17. Функція для пошуку максимального елемента масиву
int findMaxElement(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("Некоректний розмір або масив");
    int max = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] > max) max = ar[i];
    }
    return max;
}