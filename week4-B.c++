#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <list>
#include <vector>

using namespace std;


vector <int> *ladj;
bool ban = 1;

void IsBipartiteUtil(int v, int *visited, int color) {
    visited[v] = color;

    vector <int>::iterator it = ladj[v].begin();
    for (; it != ladj[v].end(); it++)
        if (visited[*it] == 0) IsBipartiteUtil(*it, visited, color * -1);
        else if (color == visited[*it]) ban = 0;
}

bool IsBipartite(int n) {
    int *visited = new int[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (visited[i] == 0) IsBipartiteUtil(i, visited, 1);

    return ban;
}

int main() {
    int n, m, vi, vj;
	cin >> n >> m;

    ladj = new vector <int>[n];
    for (int i = 0; i < m; i++) {
	    cin >> vi >> vj;
        ladj[vi - 1].push_back(vj - 1);
        ladj[vj - 1].push_back(vi - 1);
    }
    if (IsBipartite(n))
	    cout << "YES";
    else 
        cout << "NO";
	return 0;
}
