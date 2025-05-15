#include "1DArrays.h"

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


int main()
{
    SetConsoleOutputCP(1251);
    srand(time(0));

    int size = 0;  // розмір масиву, ініціалізований 0 для безпеки
    int index;     // індекс елемента
    int number;    // поріг входження в масив
    int value;     // новий елемент масиву
    int rotation;  // обертання масиву вправо від'ємне, вліво додатнє
    int* arr = nullptr;  // вказівник на масив,
    // ініціалізований nullptr для уникнення невизначеної поведінки

    try {
        // Перевірка вводу size
        cout << "Будь ласка, визначте розмір масиву: ";
        if (!(cin >> size))
            throw runtime_error("Введіть ціле число");
        if (size <= 0)
            throw runtime_error("Розмір має бути додатнім");

        // Виділяємо пам'ять під масив
        arr = allocateArray(size);  // без повторного оголошення

        // Заповнюємо масив випадковими значеннями
        fillArrayWithRandomValues(arr, size);
        cout << "\nЗаповнюємо масив випадковими цілими числами...\n";
        printArray(arr, size);

        // Додаємо елемент в кінець
        arr = addElementAtEnd(arr, size, 999);
        cout << "Приклад масиву пiсля додавання елемента в кiнець:\n";
        printArray(arr, size);

        // Додаємо елемент на початок
        arr = addElementAtStart(arr, size, 777);
        cout << "Приклад масиву пiсля додавання елемента на початок:\n";
        printArray(arr, size);

        // Видаляємо елемент з кінця
        arr = removeElementAtEnd(arr, size);
        cout << "Приклад масиву пiсля видалення елемента з кiнця:\n";
        printArray(arr, size);

        // 1. Видаляємо елемент з початку
        arr = removeFirstElement(arr, size);
        cout << "Масив пiсля видалення першого елемента:\n";
        printArray(arr, size);

        // 2. Видаляємо елемент за індексом
        cout << "Введіть індекс елемента, який бажаєте видалити: ";
        if (!(cin >> index))
            throw runtime_error("Введіть ціле число");
        if (index < 0 || index >= size)
            throw runtime_error("Некоректний індекс");
        cout << "\nМасив пiсля видалення елемента з переданим індексом:\n";
        if (index == 0) arr = removeFirstElement(arr, size);
        else if (index == size - 1) arr = removeElementAtEnd(arr, size);
        else arr = removeElementAtIndex(arr, size, index);
        printArray(arr, size);

        // 3. Видаляємо всі елементи масиву
        cout << "Тепер знищимо масив.\n";
        arr = clearArray(arr, size);
        if (arr == nullptr) cout << "Порожній вказівник!\n";
        cout << "Розмір масиву після очищення дорівнює " << size << "\n";

        // Створюємо масив заново
        cout << "\nБудь ласка, зазначте розмір масиву: ";
        if (!(cin >> size))
            throw runtime_error("Введіть ціле число");
        if (size <= 0)
            throw runtime_error("Розмір має бути додатнім");
        arr = allocateArray(size);
        fillArrayWithRandomValues(arr, size);
        cout << "\nМасив пiсля заповнення випадковими значеннями:\n";
        printArray(arr, size);

        // 5. Видаляємо всі елементи масиву, більші за задане число
        cout << "Введіть ціле число, щоб видалити всі елементи, які більше: ";
        if (!(cin >> number))
            throw runtime_error("Має бути ціле число");
        cout << "\nМасив пiсля видалення всіх елементів згідно з цією умовою:\n";
        arr = removeElementsGreaterThan(arr, size, number);
        printArray(arr, size);

        // 6. Додаємо елемент на задану позицію
        cout << "Введіть індекс нового елемента: ";
        if (!(cin >> index))
            throw runtime_error("Введіть ціле число");
        if (index < 0 || index > size)
            throw runtime_error("Некоректний індекс");
        cout << "Як новий елемент, введіть ціле число: ";
        if (!(cin >> value)) throw runtime_error("Має бути ціле число");
        cout << "\nМасив пiсля вставлення елемента на задану позицію:\n";
        arr = insertElementAtIndex(arr, size, value, index);
        printArray(arr, size);

        // 7. Заповнюємо натуральними числами
        cout << "Масив, заповнений послідовними числами від 1 до N:\n";
        arr = fillNaturalSequence(arr, size);
        printArray(arr, size);

        // 8. Користувач обережно та уважно заповнює масив з клавіатури
        arr = userFillArray(arr, size);
        printArray(arr, size);

        // 9. Сортуємо масив від найменшого до найбільшого значень
        cout << "Масив, відсортований за зростанням:\n";
        arr = sortAscending(arr, size);
        printArray(arr, size);

        // 10. Сортуємо масив за найбільшого до найменшого значень
        cout << "Масив, відсортований за спаданням:\n";
        arr = sortDescending(arr, size);
        printArray(arr, size);

        // 11. Обертаємо масив, а не реверсуємо!!!
        cout << "Введіть кількість позицій для обертання ";
        cout << "(додатнє — вліво, від’ємне — вправо): ";
        if (!(cin >> rotation))
            throw runtime_error("Має бути ціле число");
        cout << "\nМасив після обертання:\n";
        arr = rotateArray(arr, size, rotation);
        printArray(arr, size);

        // 13. Аналог агрегатної функції AVG у T-SQL
        cout << "\nСереднє арифметичне елементів масиву: ";
        cout << arrayArithmeticMean(arr, size) << "\n\n";

        // 14. Аналог агрегатної функції COUNT з умовою
        cout << "Кількість парних елементів: ";
        cout << countEvenNumbers(arr, size) << "\n\n";

        // 16.
        cout << "Добуток всіх елементів масиву: ";
        cout << multiplyAllElements(arr, size) << "\n\n";

        // 17. Аналог агрегатної функції MAX з T-SQL
        cout << "Максимальний елемент масиву: ";
        cout << findMaxElement(arr, size) << "\n\n";

        delete[] arr;
        arr = nullptr;
    }

    // https://learn.microsoft.com/ru-ru/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170

    catch (const invalid_argument& e) { // некоректні аргументи функцій
        cerr << "\nFUNCTIONAL ERROR: " << e.what() << "\n";
        delete[] arr;
        return -1;
    }
    catch (const runtime_error& e) { // помилки вводу в main()
        cerr << "\nRUNTIME ERROR: " << e.what() << "\n";
        delete[] arr;
        return -1;
    }
    catch (...) { // неохоплені винятки, наприклад, bad_alloc
        cerr << "\nUNKNOWN ERROR" << "\n";
        delete[] arr;
        return -1;
    }

    return 0;
}