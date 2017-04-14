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

int B[100000];
int t;

int bs(int A[], int n, int k, int lo, int hi) {
    if (lo > hi) return t;

    int mid = lo + (hi - lo) / 2;

    long long sum = B[0] = A[0];
    for (int i = 1; i < n; i++) {
        B[i] = A[i] - sum;
        if (B[i] < mid) B[i] = mid;
        if (mid > A[i]) B[i] = A[i];
        sum += B[i];
    }

    if (sum > k) return bs(A, n, k, lo, mid - 1);
    else {t = mid; return bs(A, n, k, mid + 1, hi);}
}

int main() {
	int n, k, A[100000], men;
    long long sum;

	cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(A, A + n);
    sum = men = A[0];
    for (int i = 1; i < n; i++) {
        int ai = A[i] - sum;
        sum += ai;
        if (ai < men) men = ai;
    }
    t = A[0];
    if (n == 1) cout << t;
    else if (k == 1) cout << 0;
    else if (sum >= k) cout << men;
    else cout << bs(A, n, k, 0, A[0]);
	return 0;
}
