#include <iostream>
#include <cmath>
#include <gmpxx.h>
typedef mpz_class bigInteger;
using namespace std;

bigInteger powerMod(bigInteger a,bigInteger b,bigInteger n)
{

    bigInteger z=a%n,y=1,m=b;
    while (m!=0)
    {
        if ((m%2)==1)
            y=(y*z)%n;
        m=m/2;
        z=(z*z) %n;
    }
    return y;
}

int main() {

	bigInteger N("1125907426181141");
  bigInteger e("65537");
  bigInteger fN("1125906351390732");
	bigInteger d("725584856660933");
	bigInteger M1("870765555271285");
  bigInteger M2("66136005702361");


	bigInteger y = powerMod(M1,d,N);

	cout << y << endl;

  bigInteger x = powerMod(M2,d,N);

  cout << x;
//wiadomość: goldbach
}
