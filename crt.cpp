#include <iostream>
#include <gmpxx.h>

using namespace std;

typedef mpz_class bigInteger;


class triple
{
    public:
        bigInteger d,x,y;
};



triple extendedGCD(bigInteger a,bigInteger b)
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


// Funkcja rozwiazuje uklad kongruencji x=a1 mod n1, x=a2 mod n2,...,x=ak mod nk
// przy zalozeniu, ze NWD(ni,nj)=1.

bigInteger crt (bigInteger a[],bigInteger n[],int k)
{
  bigInteger N = 1;

	for(int i = 0; i < k; i++) {
		N*=n[i];
	}
	bigInteger b[k];
	bigInteger x = 0;
	for(int i =0; i<k; i++) {
		b[i] = extendedGCD(n[i],(N/n[i])).y;
		x = x + a[i] * b[i] * (N/n[i]);
	}
	while(x<0) x = x + N;
  //cout << N << endl;
	return x;

}


int main()
{

   const int k=5;
   bigInteger a[k];
   bigInteger n[k];

  // Dane z zadania:

  a[0]=bigInteger("17");a[1]=bigInteger("15");a[2]=bigInteger("7");a[3]=bigInteger("5");a[4]=bigInteger("45");
  n[0]=bigInteger("13111");n[1]=bigInteger("225");n[2]=bigInteger("13");n[3]=bigInteger("19");n[4]=bigInteger("9999991");



   cout<<crt(a,n,k);

   return 0;

}
