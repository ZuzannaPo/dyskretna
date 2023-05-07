#include <iostream>
#include <gmpxx.h>
using namespace std;

typedef mpz_class bigInteger;                    // bardziej czytelnie jest poslugiwac sie bigInteger niz mpz_class

// Ponizszy kod obliczy 1000! mod 1234567890987654321

int main()
{
    bigInteger n(1);                              // tworzenie obiektów z intów
    bigInteger modulus("1234567890987654321");    // lub ze stringów

    for (int i=2;i<=1000;++i)
        n=n*i;
    
    cout<<"1000!="<<n<<endl;
    cout<<"1000! mod 1234567890987654321="<<n % modulus<<endl;
    
    return 0;

}