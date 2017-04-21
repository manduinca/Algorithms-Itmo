#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

using namespace std;

int B[100000];

void merge(int A[], int l, int m, int r) {
    for(int i = l; i <= r; i++)
        B[i] = A[i];
    int i = l, j = m + 1, k = l;
    while(k <= r) {
        if(i > m) {while(j <= r) {A[k] = B[j]; j++; k++;} break;}
        if(j > r) {while(i <= m) {A[k] = B[i]; i++; k++;} break;}
        if(B[i] <= B[j]) {A[k] = B[i]; i++; k++;}
        else {A[k] = B[j]; j++; k++;}
    }
    cout << l + 1 << " " << r + 1  << " " << A[l] << " " << A[r] << endl;
}

void sort(int A[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        sort(A, l, m);
        sort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main() {
	int n, A[100000];
	cin >> n;
    for(int i = 0; i < n; i++)
	    cin >> A[i];
    sort(A, 0, n - 1);
    for(int i = 0; i < n; i++)
	    cout << A[i] << " ";
	return 0;
}
