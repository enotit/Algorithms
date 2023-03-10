#include <iostream>
#include <time.h>
#include <fstream>
#include <chrono>
#include <limits>

using namespace std;

class A
{
private:
    int _a;
    char _b;
    float _c;

public:
    friend bool operator>(const A &c1, const A &c2);
    friend bool operator<(const A &c1, const A &c2);
    friend bool operator==(const A &c1, const A &c2);
    A(const int a, const char b, const float c) : _a{a}, _b{b}, _c{c} {};
    A(){};
    friend ostream &operator<<(std::ostream &out, const A &point);
};
bool operator>(const A &c1, const A &c2)
{
    return c1._a > c2._a;
}

bool operator<(const A &c1, const A &c2)
{
    return c1._a < c2._a;
}

bool operator==(const A &c1, const A &c2)
{
    return c1._a == c2._a;
}


ostream &operator<<(ostream &out, const A &a)
{
    cout << "Fields object A(" << a._a << ", " << a._b << ", " << a._c << ')' << endl;
    return out;
}

template <typename T>
void printArr(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
int chaosSearch(T* arr, int size, T key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

template<typename T>
int fibonacciSearch(T arr[], int n, T key) {
    int fib2 = 0; // (n-2)-й элемент Фибоначчи
    int fib1 = 1; // (n-1)-й элемент Фибоначчи
    int fib = fib2 + fib1; // текущий элемент Фибоначчи

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = std::min(offset + fib2, n - 1);

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;
        }
    }

    if (fib1 == 1 && arr[offset+1] == key) {
        return offset+1;
    }

    return -1;
}

template <typename T>
void merge(T arr[], int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;
    T left[nL], right[nR];
    for (int i = 0; i < nL; i++)
    {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < nR; j++)
    {
        right[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < nL && j < nR)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nL)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSortHe(T arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortHe(arr, l, m);
        mergeSortHe(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

double take_now()
{
    clock_t start = clock();
    double seconds = (double)(start);
    return seconds;
}

int main()
{    
    cout << "=== FIRST PART ===" << endl;
    // ----------- PART 1 --------------
    char arr[] = {'q', '1', '*', '2', '3', 'g'};
    int n = sizeof(arr) / sizeof(arr[0]);

    // ПОИСК НЕУПОРЯДОЧН
    cout << "For non-decent: " << chaosSearch(arr, n, '3') << endl;
    // СОРТИРУЕМ
    mergeSortHe(arr, 0, n - 1);
    // ПОИСК УПОРЯДОЧН 
    cout << "For decent: "  << fibonacciSearch(arr, n, '3') << endl;
    
    cout << "=== SECOND PART ===" << endl;
    // ----------- PART 2 --------------
    A custom[] = {A(1, '1', 1.0), A(4, '4', 4.4), A(2, '2', 2.2), A(1, '1', 1.0), A(4, '4', 4.4)};
    int customN = 5;

    // ПОИСК НЕУПОРЯДОЧН
    cout << "For non-decent: " << chaosSearch(custom, customN, A(4, '4', 4.4)) << endl;
    
    // СОРТИРУЕМ
    mergeSortHe(custom, 0, customN - 1);
    // ПОИСК УПОРЯДОЧН 
    cout << "For decent: "  << fibonacciSearch(custom, customN,  A(4, '4', 4.4)) << endl;

    cout << "=== THIRD PART ===" << endl;
    // ----------- PART 3 --------------  SHEET https://docs.google.com/spreadsheets/d/1EvVCcgXyuZWbLZRsnrxJSLxyeDBQ0q699RSG5cqHSuM/edit#gid=1039309473
    long counts[5] = {100000, 200000, 300000, 400000, 450000};
    for (long i = 0; i < 5; i++)
    {
        // Наполняем
        long count = counts[i];
        int *a = new int[count];
        int max = -1;
        for (int k = 0; k < count; k++)
        {
            a[k] = rand();
            if (max < a[k]) {
                max = a[k];
            }
        }
        // Для неупорядчн
        double start = take_now();
        chaosSearch(a, count - 1, max);
        double finish = take_now();
        double diff = (finish - start);
        cout << "For non-decent: " << count << " " << diff << endl;
        
        // Упорядочиваем
        mergeSortHe(a, 0, count - 1);
        // считаем
        double start2 = take_now();
        fibonacciSearch(a, count - 1, max);
        double finish2 = take_now();
        double diff2 = (finish2 - start2);
        cout << "For decent: " << count << " " << diff2 << endl;        
    }
}