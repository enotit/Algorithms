#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <chrono>
#include <time.h>
#include <limits>

using namespace std;

template <typename T>
T max_t(T *A, int n)
{
    T max = A[0];
    for (int i = 0; i < n; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}
template <typename T>
T min_t(T *A, int n)
{
    T min = A[0];
    for (int i = 0; i < n; i++)
        if (A[i] < min)
            min = A[i];
    return min;
}

template <typename T>
T med_t(T *A, int n)
{
    return A[n / 2];
}

double take_now()
{
    clock_t start = clock();
    double seconds = (double)(start);
    return seconds;
}

int main()
{
    // Sheet is here: https://docs.google.com/spreadsheets/d/1EvVCcgXyuZWbLZRsnrxJSLxyeDBQ0q699RSG5cqHSuM/edit#gid=0
    typedef std::numeric_limits<double> dbl;

    long counts[11]{1000000, 3000000, 6000000, 9000000, 12000000, 15000000, 18000000, 30000000, 100000000, 500000000, 900000000};
    for (long i = 0; i < 11; i++)
    {
        double *a = new double[counts[i]];
        for (int k = 0; k < counts[i]; k++)
        {
            a[k] = 1.145678987654;
        }
        double start = take_now();
        min_t(a, counts[i]);
        double finish = take_now();
        double diff = (finish - start);
        cout << counts[i] << " " << diff  << endl;
    }
}