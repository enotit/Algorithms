#include <iostream>
#include <time.h>
#include <fstream>
#include <Windows.h>
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

ostream &operator<<(ostream &out, const A &a)
{
    cout << "Поля А(" << a._a << ", " << a._b << ", " << a._c << ')' << endl;
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
    // Sheet on this task https://docs.google.com/spreadsheets/d/1EvVCcgXyuZWbLZRsnrxJSLxyeDBQ0q699RSG5cqHSuM/edit#gid=484089615
    // ----------- PART 1 --------------
    char arr[] = {'q', '1', '*', '2', '3', 'g'};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSortHe(arr, 0, n - 1);
    printArr(arr, n);
    // ----------- PART 2 --------------
    A custom[] = {A(1, '1', 1.0), A(4, '4', 4.4), A(2, '2', 2.2), A(1, '1', 1.0), A(4, '4', 4.4)};
    int customN = 5;
    mergeSortHe(custom, 0, customN - 1);
    printArr(custom, customN);
    // ----------- PART 3 --------------
    long counts[5] = {100000, 200000, 300000, 400000, 500000};
    for (long i = 0; i < 5; i++)
    {
        long count = counts[i];
        int *a = new int[count];
        for (int k = 0; k < count; k++)
        {
            a[k] = 1;
        }
        double start = take_now();
        mergeSortHe(a, 0, count - 1);
        double finish = take_now();
        double diff = (finish - start);
        cout << count << " " << diff << endl;
    }
}