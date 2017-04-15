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


long long B[100005];

long long bs(long long A[], int n, long long k, long long lo, long long hi) {
    while (hi - lo > 1) {
        long long mid = lo + (hi - lo) / 2;

        long long sum = B[0] = A[0];
        for (int i = 1; i < n; i++) {
            B[i] = A[i] - sum;
            if (B[i] < mid) B[i] = mid;
            if (mid > A[i]) B[i] = A[i];
            sum += B[i];
        }

        if (sum <= k) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main() {
	int n;
    long long sum, A[100005], men, k;

	cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort(A, A + n);
    sum = men = A[0];
    for (int i = 1; i < n; i++) {
        long long ai = A[i] - sum;
        sum += ai;
        if (ai < men) men = ai;
    }
    if (n == 1) cout << A[0];
    else if (k == 1) cout << 0;
    else cout << bs(A, n, k, 0, A[0] + 1);
	return 0;
}
