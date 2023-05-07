#include <iostream>
using namespace std;

const int N=3;   // rozmiar tablicy do permutowania
int tab[N+1];	 // permutujemy tablice t[1..N] (dla wygody indeksujemy od 1)

/* Pomocnicze funkcje:
 * initTab()     -> tab={1,2,...,N}
 * printTab()    -> wyswietla tablice
 * swap(i,j)     -> tab[i] <-> tab[j]
 * reverse (...) -> odwraca podtablice tab[start...stop]
 */

/* *************************** FUNKCJE POMOCNICZE **********************/

void initTab()
{
  for (int i=1;i<=N;++i)
    tab[i]=i;
}


void printTab()
{
  for (int i=1;i<=N;++i)
    cout<<tab[i]<<" ";
  cout<<endl;
}

void swap(int i,int j)
{
   int tmp=tab[i];
   tab[i]=tab[j];
   tab[j]=tmp;
}


void reverse(int start,int stop)
{
  int i=start;
  int j=stop;

  while (i<j)
  {
   swap(i,j);
    ++i;--j;
  }
}

/* *************************** FUNKCJE POMOCNICZE *********************/



/* ****************************  TODO *********************************/
int nextPermutation()
{
  int k = N;
  while (k > 1 && tab[k - 1] >= tab[k]) {
      k--;
  }

  int l = N;
  while (tab[l] <= tab[k - 1]) {
      l--;
  }

  swap(k-1, l);
  reverse(k, N);

}







/* Funkcja fun to funkcja, ktora ma byc wykonywana na kazdej permutacji.
 * w funkcji main przyjeto akurat, ze bedzie to po prostu wypisywanie
 * permutacji
*/

bool a(){

	for(int i = 1; i < N; i++){
		if(tab[i] < tab[i+1]) return false;
	}
	return true;
}

int generateAllPermutations(void (fun)())
{
  fun();
	while(!a()){

		nextPermutation();
		fun();
	}

}
/* ****************************  TODO ******************************* */




int main()
{
  initTab();
  generateAllPermutations(printTab);

}
