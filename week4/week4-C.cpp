#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <vector>
#include <climits>

using namespace std;


long long dist[2000];
bool negatives[2000];
const long long MIN = -9 * 1e18;

struct Edge {
    int src, dest;
    long long weight;
};

void BellmanFord(struct Edge *edge, int n, int m, int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = LLONG_MAX;
        negatives[i] = 0;
    }
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            long long weight = edge[j].weight;
            if (dist[u] != LLONG_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (dist[v] < MIN) dist[v] = MIN;
            }
        }
    for (int i = 0; i < m; i++) {
        int u = edge[i].src;
        int v = edge[i].dest;
        long long weight = edge[i].weight;
        if (dist[u] != LLONG_MAX && dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight;
            if (dist[v] < MIN) dist[v] = MIN;
            negatives[v] = 1;
            for (int j = 0; j < m; j++)
                if (edge[j].src == v)
                    negatives[edge[j].dest] = 1;
        }
    }
}

int main() {
    int n, m, s, vi, vj;
    long long w;
	cin >> n >> m >> s;

    struct Edge *edge = new struct Edge [m];
    for (int i = 0; i < m; i++) {
	    cin >> vi >> vj >> w;
        edge[i].src = vi - 1;
        edge[i].dest = vj - 1;
        edge[i].weight = w;
    }
    BellmanFord(edge, n, m, s - 1);
    for (int i = 0; i < n; i++)
        if (dist[i] == LLONG_MAX) cout << "*" << endl;
        else if (negatives[i]) cout << "-" << endl;
        else cout << dist[i] << endl;
	return 0;
}
