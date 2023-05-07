#include <iostream>
#include <gmpxx.h>
#include <time.h>

using namespace std;
typedef mpz_class bigInteger;

// Funkcje dotyczace generowania wielkich liczb losowych

gmp_randclass rr(gmp_randinit_default);

void initalize_random()
{
    rr.seed(time(NULL));
}

// Ponizsza funkcja zwraca losowa liczbe z przedzialu [0,...upper_bound)
bigInteger randomInt(bigInteger upper_bound)
{
    return rr.get_z_range(upper_bound);
}

// Funkcja powerMod z zajec

bigInteger powerMod(const bigInteger &a, const bigInteger &b, const bigInteger &n)
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


bool miller_rabin(bigInteger N, int trials){

  for(int t=0; t<trials; t++) {
    bigInteger a = randomInt(N-1);
    bigInteger s("55");
    int r = 2;
    bigInteger x = powerMod(a,s,N);

    if((x-1)%N == 0 || (x+1)%N == 0) return true;

    for(int i=1; i<=r-1; i++) {
      x = powerMod(x,2,N);
      if((x+1)%N == 0) return true;
    }
    return false;
  }
  return false;

}

int main()
{
    initalize_random();
    bigInteger N("221"); // liczba, ktora testujemy

    if (miller_rabin(N, 10))
        cout << "Pierwsza";
    else
        cout << "Zlozona";
}
