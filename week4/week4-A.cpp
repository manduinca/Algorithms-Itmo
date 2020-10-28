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
vector <int> res;
int fin;

bool HasCycleUtil(int v, bool *visited, bool *recursion) {
    if(visited[v] == 0) {
        visited[v] = recursion[v] = 1;
        res.push_back(v + 1);

        vector <int>::iterator it = ladj[v].begin();
        for (; it != ladj[v].end(); it++)
            if (!visited[*it] && HasCycleUtil(*it, visited, recursion))
                return 1;
            else 
                if (recursion[*it]) {
                    fin = *it + 1;
                    return 1;
                }
    }
    recursion[v] = 0;
    if (res.size() > 0) res.pop_back();
    return 0;
}

bool HasCycle(int n) {
    bool *visited = new bool[n];
    bool *recursion = new bool[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recursion[i] = 0;
    }

    for (int i = 0; i < n; i++)
        if(HasCycleUtil(i, visited, recursion))
            return 1;
    return 0;
}

int main() {
    int n, m, vi, vj;
	cin >> n >> m;

    ladj = new vector <int>[n];
    for (int i = 0; i < m; i++) {
	    cin >> vi >> vj;
        ladj[vi - 1].push_back(vj - 1);
    }
    if (HasCycle(n)) {
	    cout << "YES\n";
        int ind;
        for (int i = 0; i < res.size(); i++)
            if (fin == res[i]) ind = i;
        for (int i = ind; i < res.size(); i++)
            cout << res[i] << " ";
    }
    else 
        cout << "NO";
	return 0;
}
