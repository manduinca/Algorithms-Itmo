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
	int n;
    vector <int> v(2);
    v[0] = 1; v[1] = 2;
	cin >> n;
    if(n == 1) cout << "1";
    if(n == 2) cout << "1 2";
    if(n > 2) {
        for(int i = 3; i <= n; i++) {
            v.push_back(i);
            swap(v[(i + 1) / 2 - 1], v[i - 1]);
        }
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
    }
	return 0;
}
