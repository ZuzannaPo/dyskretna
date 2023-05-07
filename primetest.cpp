#include <iostream>
#include <gmpxx.h>

using namespace std;
typedef mpz_class bigInteger;


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

bool isPrime(bigInteger N)
{

	if(powerMod(2,N-1,N)==1) return true;
	else return false;

}




int main()
{     bigInteger num("10000568033");

      if (isPrime(num))
	  cout<<"Liczba jest prawdopodobnie pierwsza\n";
      else
	  cout<<"Liczba jest zlozona\n";

      return 0;
}
