#include <iostream>
#include <cmath>
#include <gmpxx.h>

using namespace std;
typedef mpz_class bigInteger;

// Funkcja powerMod z zajec

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

// Funkcja extendedGCD

class triple
{
public:
    bigInteger d, x, y;
};

triple extendedGCD(const bigInteger& a, const bigInteger& b)
{
    triple result;
    if (b == 0)
    {
        result.d = a;
        result.x = 1;
        result.y = 0;

        return result;
    }
    else
    {
        triple temporary = extendedGCD(b, a % b);

        result.d = temporary.d;
        result.x = temporary.y;
        result.y = temporary.x - (a / b) * temporary.y;

        return result;
    }
}

// ponizsza funkcja zwraca true jesli liczba N>=2 jest pierwsza
// oraz false w przeciwnym przypadku.

bool isPrime(int N)
{
    if (N == 2)
        return true;

    for (int i = 3; i <= sqrt(N); i +=2)
    {
        if ((N % i) == 0)
            return false;
    }
    return true;
}

bool isCarmichael(int N)
{
  if(isPrime(N)) return false;
  for(int i=2;i<N;i++) {
    if(extendedGCD(i,N).d == 1 && powerMod(i,N-1,N) != 1)
     return false;
  }

  return true;
}

void generateCarmichaels(int start, int stop)
{
    int counter = 1;
    for (int i = start; i <= stop; ++i)
        if (isCarmichael(i))
        {
            cout << counter << ": " << i << endl;
            ++counter;
        }
}

int main()
{
    generateCarmichaels(2, 100000);
    return 0;
}
