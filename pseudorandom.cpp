#include <iostream>
#include <fstream>
using namespace std;

// Funkcja ma generowac ciag liczb pseudolosowych o dlugosci seqLength
// wg. algorytmu podanego na zajeciach.

void pseudorandomSeq(long a, long c, long modulus, long seed, int seqLength, int *tab)
{

  int x = seed;
  for(int i = 1; i < seqLength; i++) {
    x = ((a*x) + c)%modulus;
    tab[i] = x;
    cout << x << endl;

  }
}

int main()
{
    //pseudorandomSeq(7, 0, 10, 4, 20); //dla x0 = 1 wygląda na nielosowy, bo już 5-ta liczba się powtarza
    //dla roznych x0 sytuacja się nie zmienia
    //pseudorandomSeq(13, 0, 1024, 2, 20); //ciąg wygląda na losowy, ale wszystkie liczby są nieparzyste,
    //zmiana x0 powoduje zmianę liczb na parzyste, wszystko to wygląda nienaturalnie
    long seqLength = 100;
    int *tab = new int [seqLength+1];
    pseudorandomSeq(22695477, 1, 4294967296, 1, 100,tab);
    fstream plik;
    plik.open("pseudo.txt", ios::out);

    for(int i = 1; i <= seqLength; i++) {
      plik << tab[i] << endl;
    }

    plik.close();
    return 0;
}
