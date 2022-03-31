#include <iostream>
#include <cmath>

/*
 * przykladowe parametry
 * A    68909602460261  1099087573  742938285   397204094   69069   2^2 * 23^7+1
 * M    2^48            2^32        2^31-1      2^31-1      2^32    2^35
 * C    0               0           0           0           1       0
 *
 * */
#define C 0
#define N 100000
#define A 397204094

using namespace std;

// dlugosc naszej tablicy
const int liczba = 10;
const long long M = pow(2, 31) - 1;

long long random(long long prev) {
    // Xn+1 = (aXn + c) mod M
    return (A * prev + C) % M;
}

bool XOR(bool a, bool b) {
    if (a == 1 && b == 0 || a == 0 && b == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

long long toLongLong(bool value[31]) {
    long long out = 0;
    for (int i = 0; i < 31; i++)
        if (value[i] == 1)
            out += pow(2, 30 - i);
    return out;
}

int main()
{
    cout << "2.2" << endl;

    long long value = 12458978;

    long long probability_array[liczba];
    for (int i = 0; i < liczba; i++)
    {
        probability_array[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        value = random(value);
        int index = liczba * value / M;
        probability_array[index]++;
    }

    int sum = 0;
    for (int i = 0; i < liczba; i++)
    {
        sum += probability_array[i];
        cout << i << ". " << probability_array[i] << endl;
    }
    cout << "Razem: " << sum << endl;

    cout << "2.6" << endl;

    /*
    * przykladowe parametry
    * p     2   10  29  607  44497  132049
    * q     1   3   2   273  8575   33912
    *
    * */
    const int p = 607;
    const int q = 273;

    long long probability_array2[liczba];
    for (int i = 0; i < liczba; i++)
    {
        probability_array2[i] = 0;
    }

    bool value2[32] = {0, 0, 0, 1, 0,
                       1, 0, 0, 0, 1,
                       0, 0, 0, 0, 0,
                       0, 1, 0, 0, 0,
                       0, 0, 1, 1, 1,
                       1, 0, 0, 1, 0,
                       0, 0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            value2[j] = XOR(value2[abs((j - p) % 32)], value2[abs((j - q) % 32)]);
        }

        long long tmp = toLongLong(value2);

        int index = liczba * tmp / M;
        probability_array2[index]++;
    }

    sum = 0;
    for (int i = 0; i < liczba; i++)
    {
        sum += probability_array2[i];
        cout << i << " " << probability_array2[i] << endl;
    }
    cout << "Razem: " << sum << endl;
    return 0;
}
