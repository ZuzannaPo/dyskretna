#include <iostream>
#include <gmpxx.h>

typedef mpz_class bigInteger;

using namespace std;



class triple
{
    public:
        bigInteger d,x,y;
};



triple extendedGCD(bigInteger a, bigInteger b)
{
     triple result;
     if (b==0)
     {
         result.d=a;
         result.x=1;
         result.y=0;

         return result;
     }
     else
     {
         triple temporary=extendedGCD(b,a%b);

         result.d=temporary.d;
         result.x=temporary.y;
         result.y=temporary.x-(a/b)*temporary.y;

         return result;
     }
}





//Funckja obliczajaca odwrotnosc, prosze zalozyc, ze
// a bedzie zawsze wzglednie pierwsze z N

bigInteger inverse(bigInteger a,bigInteger N)
{
    triple d = extendedGCD(a,N);
    while(d.x <  0) d.x += N;
    return d.x;

}



// Procedura wypisujaca na standardowe wyjscie wszystkie rozwiazania rownania ax=b mod n

void linsolve(bigInteger a,bigInteger b,bigInteger n)
{
  triple d = extendedGCD(a,n);
  if(b % d.d != 0) cout << "równanie sprzeczne";

  else{
    bigInteger a1 = a/d.d;
    bigInteger b1 = b/d.d;
    bigInteger n1 = n/d.d;
    bigInteger m = inverse(a1,n1);
    bigInteger x = m * (b1%n);
    while(x<0) x = x+(n/d.d);
    for(int i=0; i<d.d; i++) {
      cout << x%n << endl;
      x = x+(n/d.d);
    }
  }

}


int main()
{

  linsolve(10,18,26);
  return 0;
}
