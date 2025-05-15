#pragma once

// ������ � ����̲����� ������̲����� �������� � �++

#include <iostream>
#include <windows.h>  // SetConsoleOutputCP
#include <stdexcept>  // ��� ������ � ���������
#include <cstdlib>
#include <ctime>

using namespace std;

// ��������� ������� � �������� 1d_array.cpp
// https://gist.github.com/sunmeat/220a03a64a8b2ff4a33fc28c7b03c77e
int* allocateArray(int size);
void fillArrayWithRandomValues(int* ar, int size);
void printArray(int* ar, int size);
int* addElementAtEnd(int* ar, int& size, int value);
int* addElementAtStart(int* ar, int& size, int value);
int* removeElementAtEnd(int* ar, int& size);

// ������ �������� � ���������� ����� 6 ������� �� 17
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
// const int* ar, ���� �� return newArray


// ������� ��� �������� ���'�� �� �����
int* allocateArray(int size)
{
    if (size > 0 && size < 1000000)
        return new int[size];
    else
        throw invalid_argument("Invalid size");
}


// ������� ��� ������ ���������� ������� � �����
void fillArrayWithRandomValues(int* ar, int size)
{
    for (int i = 0; i < size; ++i) {
        ar[i] = rand() % 100;
    }
}


// ������� ��� ������ ������
void printArray(int* ar, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << ar[i] << ", ";
    }
    cout << "\n\n";
}


// ������� ��� ��������� ������ �������� � ����� ������
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


// ������� ��� ��������� �������� �� ������� ������
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


// ������� ��� ��������� ���������� �������� ������
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


// 14 �����

// 1. ������� ��� ��������� ������� �������� ������
int* removeFirstElement(const int* ar, int& size)
{
    if (size <= 0 || (size > 0 && ar == nullptr))
        throw invalid_argument("����������� ����� ��� �����");
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


// 2. ������� ��� ��������� �������� � ������� � �������� 
// � ������� ������
int* removeElementAtIndex(const int* ar, int& size, const int index)
{
    if (size <= 0 || index < 0 || index >= size || (size > 0 && ar == nullptr))
        throw invalid_argument("����������� �����, ������ ��� �����");
    if (size == 1) {
        delete[] ar;
        size = 0;
        return nullptr;
    }  // ��������� ����� ��� �������� ������ ���. � main()
    int* newArray = new int[size - 1];
    int j = 0;
    for (int i = 0; i < size && j < size - 1; ++i) {
        if (i != index) {
            newArray[j] = ar[i];  // ������� C6386, && j < size - 1
            ++j;
        }
    }
    delete[] ar;
    --size;
    return newArray;
}


// 3. ������� ��� ��������� ��� �������� ������
int* clearArray(const int* ar, int& size)
{
    if (size < 0) throw invalid_argument("����������� �����");
    delete[] ar;
    size = 0;
    return nullptr;
}


// 5. ������� ��� ��������� ��� �������� ������, 
// �� ����� �������� �����
int* removeElementsGreaterThan(int* ar, int& size, const int number)
{
    if (size <= 0 || (size > 0 && ar == nullptr))
        throw invalid_argument("����������� ����� ��� �����");

    if (size == 1 && ar[0] >= number) {
        delete[] ar;
        size = 0;
        return nullptr;
    }

    // ���������� ������ ������ ������ �� ������ ��������� ��������
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] <= number)
            ++newSize;
    }

    if (newSize == size) return ar;  // ���� �� �������� ����������

    if (newSize == 0) {
        delete[] ar;
        size = 0;
        return nullptr;
    }

    // ��������� �� ���������� ������ ������ ����������
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


// 6. ������� ��� ������� �������� �� ������� � �������� 
// � ������� ������
int* insertElementAtIndex(const int* ar, int& size, const int value,
    const int index)
{
    if (size < 0 || index < 0 || index > size || (size > 0 && ar == nullptr))
        throw invalid_argument("����������� �����, ������ ��� �����");
    int* newArray = new int[size + 1];
    newArray[index] = value;
    for (int i = 0; i < index && i < size; ++i) {
        newArray[i] = ar[i];  // ��� ���� C6386
    }
    // �������� �������� ������� �������� ������������ C6386
    // https://learn.microsoft.com/ru-ru/cpp/code-quality/c6386?view=msvc-170
    for (int i = index; i < size && (i + 1 < size + 1); ++i) {
        newArray[i + 1] = ar[i];
    }
    delete[] ar;
    ++size;
    return newArray;
}


// 7. ������� ��� ���������� ������ ����������� ������� �� 1 �� N
int* fillNaturalSequence(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");
    for (int i = 0; i < size; ++i) {
        ar[i] = i + 1;
    }
    return ar;
}


// 8. ������� ��� ���������� ������ �������, ��������� � ���������
int* userFillArray(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");
    cout << "\n������ " << size << " �����(�����):\n";
    for (int i = 0; i < size; ++i) {
        if (!(cin >> ar[i])) throw runtime_error("������ ���� �����");
    }
    cout << "\n";
    return ar;
}


// 9. ������� ��� ���������� ������ �� ����������
int* sortAscending(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");

    // ���������� ������� �����
    // https://www.guru99.com/uk/shell-sort-algorithm.html
    // ������� ������ �� ���� "����� �� ����������"

    // ������� ���� ������� ����� ��������� ��� ���������� ��������
    for (int interval = size / 2; interval > 0; interval /= 2) {
        // �������� � ��������� size/2 (�������� ������) � �������� 
        // ���� ����� �� ����� ��������, ���� �������� �� ����� 0

        // ������� ���� ��������� �� ���������, ��������� � ������� 
        // interval i ����� �� �������� �������, ���� ���� 
        // ������������ ��, �������, ���������. 
        for (int i = interval; i < size; ++i) {
            // �������� � i = interval, ��� ���������� �������� 
            // � �������� interval

            // �������� �������� ������� ar[i] � ��������� �����
            int temp = ar[i];
            // ���������� j �� �������� ������ i ��� ����� ��������
            int j = i;

            // �������� ���� ������ ���������� ��������� ��� 
            // �������� �� ������ interval
            for (; j >= interval && ar[j - interval] > temp; j -= interval) {
                // ���� j >= interval (�� �������� �� ��� ������ ����)
                // � ������� �� ������� j - interval ������ �� temp,
                // ������� ������ ������� �� ������� j
                ar[j] = ar[j - interval];
                // �������� j �� interval, ��� ��������� ��������� 
                // ������� � ����
            }
            // ϳ��� ���������� ����������� ����� ���������� temp 
            // � ��������� �������
            ar[j] = temp;
            // j ����� �� ����, �� temp �� ���� ����������, 
            // ��� �������� �������
        }
    }
    return ar;
}


// 10. ������� ��� ���������� ������ �� ���������
int* sortDescending(int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");
    // ���������� ������� ��������� � �����������
    bool swapped;  // ��������� ��� ��������, �� ���� �����
    // https://gist.github.com/sunmeat/4c2ad4c8d735647e00a57ba5d6eba9a9
    // �������� �� ������������ "����� �� ����������"
    for (int pr = 0; pr < size - 1; pr++) {  // �� size-1 �������!
        swapped = false;  // ������� ��������� ����� ������ ��������
        for (int k = size - 1; k > 0; k--) {
            if (ar[k - 1] < ar[k]) {   // ���� ��������� ������,
                int temp = ar[k];      // ���� ��������
                ar[k] = ar[k - 1];
                ar[k - 1] = temp;
                swapped = true;  // �������, �� ���� �������
            }
        }
        // ���� ����� �� ����, ����� ������������
        if (!swapped)
            break;  // ���������� ������� ���� ��� ����������
    }
    return ar;
}


// 11. ������� ��� ��������� ������
int* rotateArray(int* ar, const int size, int rotation)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");

    if (size == 1) return ar; // ��������� �� �������

    // ����������� rotation: �������� �� �������� [0, size)
    rotation = rotation % size;  // ����� ����� ���������
    if (rotation < 0) {  // ��������� ������
        rotation += size;          // ���������� � ��������� ����
    }
    if (rotation == 0) return ar; // ������� ������������

    /*
    int* newArray = new int[size];
    for (int i = 0; i < size; ++i) {
        int j = (i + rotation) % size;
        newArray[j] = ar[i];
    }
    delete[] ar;
    return newArray;
    */

    // �������� ��������� ����� ������������:
    // 1. ��������� ����� rotation ��������
    // 2. ��������� ����� ��������
    // 3. ��������� ���� �����
    reverseArray(ar, 0, rotation - 1);
    reverseArray(ar, rotation, size - 1);
    reverseArray(ar, 0, size - 1);
    // ��������� ��� ����� �����, ������� ��������� �� ����
    return ar;
}


// �������� ������� ��� ������������ ������� ������ �� start �� end
void reverseArray(int* ar, int start, int end)
{
    if (start >= end) return;  // ������ �� ����������� ���
    while (start < end) {
        int temp = ar[start];
        ar[start] = ar[end];
        ar[end] = temp;
        start++;
        end--;
    }
}


// 13. ������� ��� ��������� ���������� ������������� ��� ��������
double arrayArithmeticMean(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += ar[i];
    }
    return (double)(sum) / size;
}


// 14. ������� ��� ��������� ������� ������ �������� ������
int countEvenNumbers(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] % 2 == 0) count++;
    }
    return count;
}


// 16. ������� ��� ��������� ������� ��� �������� ������
long long multiplyAllElements(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");
    long long product = 1;
    for (int i = 0; i < size; ++i) {
        product *= ar[i];
    }
    return product;
}


// 17. ������� ��� ������ ������������� �������� ������
int findMaxElement(const int* ar, const int size)
{
    if (size <= 0 || ar == nullptr)
        throw invalid_argument("����������� ����� ��� �����");
    int max = ar[0];
    for (int i = 1; i < size; ++i) {
        if (ar[i] > max) max = ar[i];
    }
    return max;
}