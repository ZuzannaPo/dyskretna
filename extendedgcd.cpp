#include <iostream>
#include <gmpxx.h>
using namespace std;

typedef mpz_class bigInteger;

// Klasa reprezentująca trójkę

class triple
{
public:
    bigInteger d, x, y;
};

triple extendedGCD(const bigInteger& a, const bigInteger& b)
{
  triple z;
  if(b == 0) {
   z.d = a;
   z.x = 1;
   z.y = 0;
   return z;
  }
  else z = extendedGCD(b, a%b);

  triple t;
  t.d = z.d;
  t.x = z.y;
  t.y = z.x - (a/b)*z.y;
  return t;
}

int main()
{
    bigInteger a("67299999999999999999551333333333109");
    bigInteger b("1570333333333319873333333333109");

    triple resoult = extendedGCD(a, b);
    cout << "NWD(" << a << "," << b << ")=" << resoult.d << endl;
    cout << "x=" << resoult.x << endl;
    cout << "y=" << resoult.y << endl;

    return 0;
}
