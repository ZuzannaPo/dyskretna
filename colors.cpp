#include <iostream>
#include <list>

using namespace std;

const int N = 8;
list<int> adj_list[N+1];
int colors[N+1];

void add_edge (int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}


void construct_graph()
{
    // graf z zadania pierwszego

    add_edge(1,4);add_edge(1,5);add_edge(1,7);add_edge(1,8);
    add_edge(2,3);add_edge(2,4);add_edge(2,5);add_edge(2,6);add_edge(2,7);
    add_edge(3,8);
    add_edge(4,7);add_edge(4,8);
    add_edge(5,6);add_edge(5,8);
    add_edge(7,8);
}

bool colorGraph(int k, int no_of_cols) {
  if(k == N+1) return true;
  for(int col = 1; col <= no_of_cols; col++) {
    bool is = true;
    for (int i: adj_list[k]) {
      if(colors[i] == col) {
        is = false;
        break;
      }
    }

    if(is) {
      colors[k] = col;
      if(colorGraph(k+1,no_of_cols)) {
        return true;
      }
      colors[k] = 0;
    }
  }
  return false;
}

bool is_colorable(int k,int no_of_cols)
{
  colors[1] = 1;
  for(int i=2; i<=no_of_cols; i++) {
    colors[i] = 0;
  }
  if(colorGraph(2,no_of_cols)) return true;
  else return false;

}


int main()
{
    construct_graph();

    int no_of_colors = 4;

    //inicjalizacja kolorow
    colors[1] = 1;
    for (int i = 2;i <= N;++i)
        colors[i] = 0;

    if (is_colorable(2,no_of_colors))
    {
        for (int i = 1;i <= N;++i)
            cout<<i<<": "<<colors[i]<<endl;
    }
    else
    {
        cout<<"Graf nie jest "<<no_of_colors<<"-kolorowalny"<<endl;
    }

}
