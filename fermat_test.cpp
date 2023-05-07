#include <iostream>
#include <random>
#include <gmpxx.h>

using namespace std;
typedef mpz_class bigInteger;

bigInteger powerMod(const bigInteger& a, const bigInteger& b, const bigInteger& n)
{

    bigInteger z = a % n, y = 1, m = b;
    while (m != 0)
    {
        if ((m % 2) == 1)
            y = (y * z) % n;
        m = m / 2;
        z = (z * z) % n;
    }

    return y;
}

bool primeTest(long N, int k)
{
    random_device rd;
    mt19937 random_gen(rd());
    uniform_int_distribution<long> distrib(2, N - 1);

    for (int i = 1; i <= k; ++i)
    {
        //long a = distrib(random_gen);
        int a = 3;
        cout << "Wylosowano=" << a << endl;
        bigInteger res = powerMod(a, N - 1, N);
        cout << "a^(N-1)=" << res << " (mod " << N << ")" << endl;
        if (powerMod(a, N - 1, N) != 1)
            return false;
    }
    return true;
}

int main()
{
    if (primeTest(225898512559, 3)) //624423990187 jest złozona, 225898512559 jest prawdopodobnie pierwsza
        cout << "Testowana liczba jest (prawdopodobnie) pierwsza" << endl;
    else
        cout << "Testowana liczba jest zlozona" << endl;
}
