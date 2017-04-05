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

const int N = 40000000;

void kth(int V[], int left, int right, int k) {
    int i = left;
    int j = right - 1;
    int key = V[right];
    while(i <= j) {
        while(V[i] < key) i++;
        while(V[j] > key) j--;
        if(i <= j) {
            swap(V[i], V[j]);
            i++; j--;
        }
    }
    swap(V[i], V[right]);
    if(i < k && i + 1 < right) kth(V, i + 1, right, k);
    if(i > k && i - 1 > left) kth(V, left, i - 1, k);
}

int main() {
	int n, A, B, C, k1, k2, *V;
    V = new int[N];
	cin >> n >> k1 >> k2;
	cin >> A >> B >> C >> V[0] >> V[1];
    for(int i = 2; i < n; i++)
        V[i] = A * V[i - 2] + B * V[i - 1] + C;
    for(int i = 0; i < n; i++)
        cout << V[i] << " ";
    cout << endl;
    kth(V, 0, n - 1, k2 - 1);
    for(int i = 0; i < n; i++)
        cout << V[i] << " ";
    cout << endl;
    return 0;
    kth(V, 0, k2 - 1, k1 - 1);
    for(int i = 0; i < n; i++)
        cout << V[i] << " ";
    cout << endl;
    sort(V + k1 - 1, V + k2);
    for(int i = k1 - 1; i < k2; i++)
        cout << V[i] << " ";
	return 0;
}
