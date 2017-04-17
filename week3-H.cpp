#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <algorithm>

using namespace std;


int main() {
	int n, k, A[100000], B[100000];
	cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    if (k == 1) {cout << "YES"; return 0;}
    for (int i = 0; i < k; i++) {
        int j = i, t = 0;
        while (j < n) {
            B[t] = A[j];
            j += k;
            t++;
        }
        sort(B, B + t);
        j = i; t = 0;
        while (j < n) {
            A[j] = B[t];
            j += k;
            t++;
        }
    }
    bool ban = 1;
    for (int i = 1; i < n; i++)
        if(A[i] < A[i - 1]) ban = 0;
    if (ban) cout << "YES";
    else cout << "NO";
	return 0;
}
