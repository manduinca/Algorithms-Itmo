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

int bs(int A[], int n, int k, int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        long long con = 0;
        for (int i = n - 1; i >= 0; i--) {
            int val = A[i] - mid;
            if(val <= 0) break;
            con += 1 + (val - 1) / (k - 1);
        }
        if (con > mid) lo = mid + 1;
        else hi = mid;
    }
    return hi;
}

int main() {
	int n, k, A[100000];
	cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    cin >> k;
    sort(A, A + n);
    if(k == 1) cout << A[n - 1];
    else cout << bs(A, n, k, 1, A[n - 1]);
	return 0;
}
