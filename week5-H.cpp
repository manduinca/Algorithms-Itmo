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

using namespace std;

int main() {
	int n, A[100];
    vector < pair <int, int> > v;
	cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++) {
        while (A[i] != i + 1) {
            for (int j = i + 1; j < n; j++)
                if (A[i] - A[j] == 1) {
                    v.push_back(make_pair(i + 1, j + 1));
                    swap(A[i], A[j]);
                }
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << endl;
	return 0;
}
