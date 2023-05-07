#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void odczyt(int &n) {

	fstream plik;
	plik.open("egzm2.txt" , ios::in);
	if(plik.good() == true) {
		plik >> n;

		plik.close();
	}

}


void odczyt2(int &n, int **macierz) {

	fstream plik;
	plik.open("egzm2.txt", ios::in);
	if(plik.good() == true) {

		int a,b,c;
		plik >> c;

		while(!plik.eof()) {
			plik >> a;
			plik >> b;
			cout << a << " " << b<< endl;
			macierz[a-1][b-1] = 0;
			macierz[b-1][a-1] = 0;
		}
	}

}


bool colorGraph(int **macierz, int pos, int k, int colors[], int n)
{



	if(pos == n) return true;
	else {
		for(int col = 1; col <= k; col++) {
			bool czy = true;
			for(int i = 0; i < pos; ++i) {
				if(macierz[pos][i]) {
					if(colors[i] == col) {
						czy = false;
						break;
					}
				}
			}
			if(czy) {
				colors[pos] = col;
				if(colorGraph(macierz, pos+1, k, colors,n)) return true;
			}
		}
		return false;
	}

}

// Funkcja zwraca true, jesli graf mozna pokolorowac za pomoca k kolorow;
// w takim przypadku wypisuje tez przykladowe kolorowanie.
// false w przeciwnym przypadku.






bool isColorable(int **macierz, int k, int n)
{
    int *colors = new int[n];
    for(int i=0; i<n; i++) {
		colors[i] = 0;
	}
   // bool f=false;
  //  for (int col = 1; col <= k; ++col)
    //{
		int col=1;
        colors[0] = col;
        if (colorGraph(macierz, 1, k, colors,n))
        {
			for(int j=1; j<=k; j++) {
				cout << "dzien " << j << ": ";
			for (int i=0;i<n;++i){
				if(colors[i]==j) cout <<i+1 << " ";

			}
			cout << endl;

   			}
			//f=true;
			cout<<endl;
               return true;
     //   }
    }
	delete []colors;
    return false;
}


void zachlanny(int **macierz, int n)
{

	int *colors = new int[n];
	for(int i=0; i<n; i++){
		colors[i] = 0;
	}

	colors[0] = 1;

	int k =1;
	for(int v=1; v<n; v++) {

		for(int u=0; u<n; u++) {

			if(macierz[v][u]) {
				if(colors[u]==k) {
					k++;
					u=0; // <- tu poprawione
				}

			}
		}
		colors[v] = k;
		k =1;
	}



	for(int j=1; j<=n; j++) {
				cout << "dzien " << j << ": ";
			for (int i=0;i<n;++i){
				if(colors[i]==j) cout <<i+1 << " ";

			}
			cout << endl;

   			}


	delete []colors;
}


int main() {

	int  n;
	odczyt(n);

	int **macierz = new int*[n];
		for(int i=0; i<n; i++) {
			macierz[i] = new int[n];
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				macierz[i][j] = 1;
				macierz[i][i] = 0;
				macierz[j][j] = 0;
			}
		}

	//cout << n << " " ;

	odczyt2(n,macierz);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << macierz[i][j];
		} cout << endl;
	}

	

	for (int col=1;col<=n;++col)
        if (isColorable(macierz,col,n))
        {
            break;
        }

        else
        {
            cout<<"Cannot be coloured with "<<col<<" color(s)."<<endl;
        }

        zachlanny(macierz,n);


        for(int i=0; i<n; i++) {
			delete [] macierz[i];
		}
		delete []macierz;

    return 0;
}
