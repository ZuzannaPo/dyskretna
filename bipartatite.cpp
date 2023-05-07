#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 8;                // liczba wierzcholkow
list <int> adj_list[N+1];       // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1
int label[N+1];                 // numer klasy danego wierzcholka.


void add_edge (int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void construct_graph()
{
       add_edge(1,2); add_edge(2,3);add_edge(3,4);add_edge(4,1);
       add_edge(7,8); add_edge(8,5);add_edge(5,6);add_edge(6,7);
       add_edge(4,8); add_edge(1,5);add_edge(2,6);add_edge(3,7);
}


void show_labels()
{
    for (int i=1;i<=N;++i)
        if (label[i] == 1)
            cout<<i<<" ";
    cout<<endl;
    for (int i=1;i<=N;++i)
        if (label[i] == 2)
            cout<<i<<" ";
}

bool is_bipartite()
{
  queue <int> Q;
  int v = 1;
  int u;
  for(int i = 1; i <= N; i++) {
    label[i] = 0;
  }
  label[v] = 1;
  Q.push(v);

  while(!Q.empty()) {
    u = Q.front();
    Q.pop();

    for(int i : adj_list[u]) {
      if(label[u] == label[i]) return false;
      if(label[i] == 0) {
        label[i] = 1+!(label[u]-1);
        Q.push(i);
      }
    }
  }
  return true;
}


int main()
{
    construct_graph();

    if (is_bipartite())
    {
        cout<<"Graf jest dwudzielny. Podzial na klasy: " << endl;
        show_labels();
    }
    else
        cout<<"Nie jest dwudzielny!";

    return 0;
}
