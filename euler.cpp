#include <iostream>
#include <list>
#include <stack>

using namespace std;

const int N = 6;              // liczba wierzcholkow
list <int> adj_list[N+1];     // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1

/* Funkcje sluzace do konstrukcji list sasiedztwa grafu */

void add_edge (int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void construct_graph()
{
        add_edge(1,2);add_edge(1,3);add_edge(1,4);add_edge(1,5);
        add_edge(2,3);add_edge(2,4);add_edge(2,6);
        add_edge(3,5);add_edge(3,6);
        add_edge(4,5);add_edge(4,6);
        add_edge(5,6);
}


void euler_circuit(int start_vertex)
{
  int v;
  stack <int> STOS;
  stack <int> OUT;
  STOS.push(start_vertex);

  while(!STOS.empty()) {
    bool b = false;
    v = STOS.top();
    while(!adj_list[v].empty()) {
      int i = adj_list[v].front();
      STOS.push(i);
      adj_list[v].remove(i);
      adj_list[i].remove(v);
      b = true;
      break;
    }

    if(!b) {
        STOS.pop();
        OUT.push(v);
      }
    }
    while(!OUT.empty()) {
      v = OUT.top();
      cout << v << endl;
      OUT.pop();
    }
}


int main()
{
    construct_graph();
    euler_circuit(1);
    return 0;
}
