#include <iostream>
using namespace std;

int const n=6;
int const lw = n*n;
bool DOP[lw+1];
int X[lw+1];


bool ruch(int x, int y, int n, int s, int &zx,  int &zy) {

	switch(s) {
		case 0: {
			zx = x-1;
			zy = y-2;
			break;
		}
		case 1: {
			zx = x-2;
			zy = y-1;
			break;
		}
		case 2: {
			zx = x-2;
			zy = y+1;
			break;
		}
		case 3: {
			zx = x-1;
			zy = y+2;
			break;
		}
		case 4: {
			zx = x+1;
			zy = y+2;
			break;
		}
		case 5: {
			zx = x+2;
			zy = y+1;
			break;
		}
		case 6: {
			zx = x+2;
			zy = y-1;
			break;
		}
		case 7: {
			zx = x+1;
			zy = y-2;
			break;
		}
	}

	if(zx>=0 && zx<n && zy>=0 && zy<n) return true;
	return false;

}

void macierz(int tab[n][n], int sasiad[lw+1][lw+1], int n) {


	for(int i=0; i<lw +1 ; i++) {
		for(int j =0; j<lw+1 ; j++) {
			sasiad[i][j] = 0;

		}
	}



	int c=1;

	for( int i=0; i < n; i++){
		for(int j = 0;j < n; j++) {
			tab[i][j] = c;
			c++;
			cout << tab[i][j] << " ";

		}cout << endl;
	}

	int zx, zy;

	for(int s = 0; s < 8; s++) {
		for(int x = 0; x < n; x++) {
			for(int y = 0; y < n; y++) {
				if(ruch(x,y,n,s,zx,zy)) {
					sasiad[tab[x][y]][tab[zx][zy]] = 1;
					//sasiad[tab[x][y]][tab[zy][zx]] = 1;
					//sasiad[tab[x][zx]][tab[y][zy]] = 1;
					//sasiad[tab[x][zx]][tab[zy][y]] = 1;
					//sasiad[tab[x][zy]][tab[y][zx]] = 1;
					//sasiad[tab[x][zy]][tab[zx][y]] = 1;
					//sasiad[tab[y][x]][tab[zx][zy]] = 1;
					//sasiad[tab[y][x]][tab[zy][zx]] = 1;
					//sasiad[tab[y][zx]][tab[x][zy]] = 1;
					//sasiad[tab[y][zx]][tab[zy][x]] = 1;
					//sasiad[tab[y][zy]][tab[x][zx]] = 1;
					//sasiad[tab[y][zy]][tab[zx][x]] = 1;
					//sasiad[tab[zx][x]][tab[zy][y]] = 1;
					//sasiad[tab[zx][x]][tab[y][zy]] = 1;
					//sasiad[tab[zx][y]][tab[x][zy]] = 1;
					//sasiad[tab[zx][y]][tab[zy][x]] = 1;
					sasiad[tab[zx][zy]][tab[x][y]] = 1;
					//sasiad[tab[zx][zy]][tab[y][x]] = 1;
					//sasiad[tab[zy][x]][tab[y][zx]] = 1;
					//sasiad[tab[zy][x]][tab[zx][y]] = 1;
					//sasiad[tab[zy][y]][tab[x][zx]] = 1;
					//sasiad[tab[zy][y]][tab[zx][x]] = 1;
					//sasiad[tab[zy][zx]][tab[x][y]] = 1;
					//sasiad[tab[zy][zx]][tab[y][x]] = 1;

				}
			}
		}
	}


		for(int i=0; i<lw+1; i++) {
		for(int j =0; j<lw+1; j++) {
			cout << sasiad[i][j];
		}
		cout << endl;
	}


}

bool f = true; //do wypisywania tylko jednej drogi
int a = 0;
int b = 0;


void Hamilton(int k,int sasiad[lw+1][lw+1], int tab[n][n])
{
	//cout << "w hamiltonie" << endl;

	int wP = X[k-1];

	for(int u = 1; u <=lw; u++) {
		if(sasiad[wP][u] && f) {
			//cout << " sasiad " << endl << lw << endl;
			if(k == lw+1 && f && u==X[1] ) {
				cout << "koniec" << endl;
				for(int i = 1; i < lw+1; i++) {
					cout << X[i] << ", ";
				}
				cout << endl;
				f = false;
				break;

			}

			else {
				if(DOP[u]) {
					X[k] = u;
					DOP[u] = false;
					Hamilton(k+1,sasiad,tab);
					DOP[u] = true;
				}
			}
		}
	}
}


int main() {



	int tab[n][n];
	int sasiad[lw+1][lw+1];


	macierz(tab,sasiad,n);



	for(int i = 0; i <= lw; i++) {
		DOP[i] = true;
		X[i] = 0;
	}


	X[1] = tab[n-1][0];
	DOP[X[1]] = false;
	//cout << "przed hamiltonem" << endl;

	Hamilton(2,sasiad,tab);

	//cout << "po hamiltonie " <<  endl;

	int x=1;
	int rozwiazanie[n][n];
	for(int i=0; i<n; i++) {
		for( int j=0; j<n; j++) {
			rozwiazanie[i][j] = x;
			x++;
		}
	}
	x=1;
	while(x<lw+1){
	for(int i=0; i<n; i++) {
		for( int j=0; j<n; j++) {
			if(tab[i][j] == X[x]) {
				//cout << X[x] << " "  << x << " "  << tab[i][j] << " ";
			rozwiazanie[i][j] = x;
			x++;
			i=0;
			j=0;
		}
	}
	} }
	for(int i=0; i<n; i++) {
		for( int j=0; j<n; j++) {
			cout << rozwiazanie[i][j] << " ";
		} cout << endl;
	}


}
