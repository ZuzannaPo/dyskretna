#include <iostream>
#include <list>
#include <stack>

using namespace std;

const int N = 10;              // liczba wierzcholkow
list <int> adj_list[N+1];     // listy sasiedztwa. Wierzcholki NUMERUJEMY OD 1

/* Funkcje sluzace konstrukcji list sasiedztwa grafu */

void add_edge (int u,int v)
{
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}


void construct_graph()
{
    add_edge(1,2); add_edge(2,3); add_edge(3,4);add_edge(4,1);
    add_edge(3,7); add_edge(7,6); add_edge(6,5);add_edge(5,3);
    add_edge(8,5); add_edge(5,10); add_edge(10,9); add_edge(9,8);
}


void euler_circuit(int v)
{
    while (!adj_list[v].empty())
    {
            int u=adj_list[v].front();
            adj_list[v].pop_front();
            adj_list[u].remove(v);
            euler_circuit(u);
    }
    cout << v << " ";


}


int main()
{
    construct_graph();
    euler_circuit(1);
}
