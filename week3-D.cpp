#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <random>
#include <algorithm>

using namespace std;

const int N = 40000000;

int partition(int V[], int lo, int hi, int ind) {
    int val = V[ind];
    int i = lo;
    int j = hi + 1;
    swap(V[ind], V[lo]);
    while(1) {
        while(V[++i] < val)
            if(i == hi) break;
        while(V[--j] > val)
            if(j == lo) break;
        if(i >= j) break;
        swap(V[i], V[j]);
    }
    swap(V[lo], V[j]);
    return j;
}

int kth(int V[], int lo, int hi, int k) {
    random_device rd;
    mt19937 gen(rd());
    while(hi > lo) {
        uniform_int_distribution<> number(lo, hi);
        int i = number(gen);
        i = partition(V, lo, hi, i);
        if(i > k) hi = i - 1;
        else if(i < k) lo = i + 1;
        else return V[i];
    }
    return V[lo];
}

int main() {
	int n, A, B, C, k1, k2, *V;
    V = new int[N];
	cin >> n >> k1 >> k2;
	cin >> A >> B >> C >> V[0] >> V[1];
    for(int i = 2; i < n; i++)
        V[i] = A * V[i - 2] + B * V[i - 1] + C;

    kth(V, 0, n - 1, k2 - 1);
    kth(V, 0, k2 - 1, k1 - 1);

    sort(V + k1 - 1, V + k2);
    for(int i = k1 - 1; i < k2; i++)
        cout << V[i] << " ";
	return 0;
}
