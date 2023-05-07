#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 9;              // liczba wierzcholkow
list <int> adj_list[N+1];     // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1
vector <int> L1;
vector <int> L2;
/* Funkcje sluzace konstrukcji list sasiedztwa grafu */

void add_edge (int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void init(int n) {

  for(int i = 1; i <= n; i++) {
    L1.push_back(i);
  }
  srand(time(NULL));
  int o = 0;
  cout << "kod prufera: ";
  //for(int i = 1; i <= n-2; i++) {
    L2.push_back(1);
    o = L2.back();
    cout << o << ", ";
    L2.push_back(7);
    o = L2.back();
    cout << o << ", ";
    L2.push_back(1);
    o = L2.back();
    cout << o << ", ";
    L2.push_back(4);
    o = L2.back();
    cout << o << ", ";
    L2.push_back(5);
    o = L2.back();
    cout << o << ", ";
    L2.push_back(6);
    o = L2.back();
    cout << o << ", ";
    L2.push_back(6);
    o = L2.back();
    cout << o << ", ";
  //}
  cout << endl;
}


int find(vector <int> l1, vector <int> l2) {
  bool is;
  for(int i = 0; i < l1.size(); i++) {
    is = true;
    for(int j = 0; j < l2.size(); j++) {
      if(l2[j] == l1[i]) {
        is = false;
        break;
      }
    }
    if(is) return l1[i];
  }
  return -1;
}

void del(vector<int> &l, int x) {
  for(int i = 0; i < l.size(); i++) {
    if(l[i] == x) {
      l.erase(l.begin() + i);
      return;
    }
  }
}

void prufer () {
  init(N);

  while(L2.size() >= 1) {
    int i = find(L1,L2);
    int j = L2.front();
    del(L1,i);
    del(L2,j);
    add_edge(i,j);
  }

  add_edge(L1[0],L1[1]);
}

void out() {
  for(int i = 1; i <= N; i++) {
    cout << i << ": ";
    int x = adj_list[i].size();
    for(int j = 0; j < x; j++) {
      cout << adj_list[i].front() << ", ";
      adj_list[i].pop_front();
    }
    cout << endl;
  }
}

int main() {
  prufer();
  out();
}
