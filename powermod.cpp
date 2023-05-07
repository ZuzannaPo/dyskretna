#include <iostream>
#include <gmpxx.h>
using namespace std;

typedef mpz_class bigInteger;

// Funkcja obliczajaca a^b mod n

bigInteger powerMod(const bigInteger& a, const bigInteger& b, const bigInteger& n)
{
  bigInteger z = a%n;
  bigInteger y = 1;
  bigInteger m = b;

  while(m>0) {

    if(m%2 != 0) y = (y*z)%n;

    m = m/2;
    z = (z*z)%n;
  }
  return y;
}

int main()
{
    bigInteger a("3");
    bigInteger b("5559060566555523");
    bigInteger n("100000000000000000000000000000000000000000000000000"); // 2^2^30 mod 10^50
    cout << powerMod(a, b, n) << endl;

    return 0;
}
