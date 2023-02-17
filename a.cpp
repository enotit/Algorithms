#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

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

int main()
{
    // TEST data bottom
    int a[4]{4, 3, 2, 6};
    cout << max_t(a, 4) << endl;

    float b[5]{4.4, 3.2, -2.3, 6.0, -8.2};
    cout << min_t(b, 5) << endl;
    //           0    1    2    3      4    5    6    7     8
    double c[9]{4.4, 3.2, -2.3, 6.0, -8.2, 3.2, -2.3, 6.0, -8.2};
    cout << med_t(b, 9) << endl;

    char d[5]{'0', 'Q', 'a', 'z', '-'};
    cout << med_t(d, 5) << endl;

    cout << min_t(d, 5);
}
