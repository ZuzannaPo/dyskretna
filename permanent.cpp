#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstring>
#include <math.h>
using namespace std;

void out(int* n, int** tab) {
	for(int i=0; i<*n; i++) {
		for(int j=0; j<*n; j++) {
			cout << tab[i][j];
		}
		cout << endl;
	}
}

void opFile(int* n, string fileName, int** tab){
	ifstream fin(fileName.c_str(), ios::in);

	if (fin){
    string tmp;
    char tab2[*n][*n];
		for (int i = 0; i < *n; i++) {
			getline (fin,tmp);
			strcpy(tab2[i], tmp.c_str());
	  }
    for(int i=0; i<*n; i++) {
      for(int j=0; j<*n; j++) {
        tab[i][j] = (int)tab2[i][j] - 48;
      }
    }
  }
	else {cout <<"File not found\n";}

}


void memClc(int *n, int** tab){
	for (int i = 0; i < *n; i++ ) {
   		delete [] tab[i];
	}
	delete [] tab;
}

void swap(int i,int j, int *tab){
	int tmp=tab[i];
  tab[i]=tab[j];
  tab[j]=tmp;
}


void reverse(int start,int stop, int *tab){
  int i=start;
  int j=stop;

  while (i<j){
    swap(i,j, tab);
    ++i;--j;
  }
}

int silnia(int n){
  return (n == 1 || n == 0) ? 1 : silnia(n - 1) * n;
}

int dwumian(int n, int k){
    double tmp = 1;

    for(int i = 1; i <= k; i++)
        tmp = tmp * ( n - i + 1 ) / i;

    return tmp;
}


void nextPermutation(int * tab, int n){

	int k = n;
	while (k > 1 && tab[k - 1] >= tab[k]) {
			k--;
	}

	int l = n;
	while (tab[l] <= tab[k - 1]) {
			l--;
	}

	swap(k-1, l, tab);
	reverse(k, n, tab);

}

int permanent (int k, int n, int** tab) {

	int s = silnia(n);
	int d = dwumian(n,k);

	int *indeksy = new int[n];
	for(int i = 0; i < n; i++) {
		indeksy[i] = i;
	}

	int **permutacje = new int*[s];
	for(int i = 0; i < s; i++) {
		permutacje[i] = new int[n];
	}

	int **podzialy = new int*[d];
	for(int i = 0; i < d; i++) {
		podzialy[i] = new int[k];
	}

	// funkcja generateSubsets

	int *A = new int[k];
	for(int i = 0; i < k; i++){
		A[i] = i;
	}

	int p = k;
	int zbior_k = 0;
	int suma = 0;

	if(n != k) {
		while( p >= 1) {
			for(int i = 0; i < k; i++) {
				podzialy[zbior_k][i] = A[i];

				for(int l = 0; l < s; l++) {
					for(int j = 0; j < n; j++) {
						permutacje[l][j] = indeksy[j];
					}
					nextPermutation(indeksy,n);
				}


				int iloczyn = 1;

					for(int l = 0; l < s; l++) {
						for(int j = 0; j < n; j++) {
							iloczyn *= tab[j][permutacje[l][j]];
						}
						suma += iloczyn;
						iloczyn = 1;
					}
				zbior_k++;
				if(A[k] == n) p = p-1;
		    else p = k;

		    if(p >= 1) {
		      for(int l = k; l >= p; l--) {
		        A[i] = A[p] + i - p + 1;
		      }
		    }
			}
		}
	}

	else { //k=n

		for(int i = 0; i < n; i++) {
			indeksy[i] = i;
		}

		for(int i = 0; i < s; i++) {
			for(int j = 0; j < n; j++) {
				permutacje[i][j] = indeksy[j];
			}
			nextPermutation(indeksy,n);
		}

		int iloczyn = 1;

			for(int i = 0; i < s; i++) {
				for(int j = 0; j < n; j++) {
					iloczyn *= tab[j][permutacje[i][j]];
				}
				suma += iloczyn;
				iloczyn = 1;
			}

	}


	for(int i = 0; i < s; i++) {
		delete [] permutacje[i];
	}
	delete [] permutacje;
	delete [] indeksy;

	return suma;

}

int main(int argc, char *argv[]){
	int k = stoi(argv[argc - 3]);
  int n = stoi(argv[argc - 2]);
  int** tab = new int *[n];
  for(int i=0; i<n; i++) {
    tab[i] = new int [n];
  }

  opFile(&n,argv[argc-1],tab);

  out(&n,tab);
  int p = permanent(k,n,tab);
  cout << p;
  memClc(&n,tab);
}
