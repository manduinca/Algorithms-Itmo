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


struct Three {
    int value, weight, ind;
};

struct Three *VT = new struct Three [100000];
double x;

bool function(struct Three t1, struct Three t2) {
    return (t1.value - x * t1.weight > t2.value - x * t2.weight);
}

int bs(int n, int k, double lo, double hi) {
    for (int i = 0; i < 50; i++) {
        double mid = lo + (hi - lo) / 2;
        x = mid;
        sort(VT, VT + n, function);
        double sum_v = 0, sum_w = 0;
        for (int i = 0; i < k; i++) {
            sum_v += VT[i].value;
            sum_w += VT[i].weight;
        }

        if (sum_v / sum_w >= mid) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main() {
	int n, k;
    double vi, wi, v_max = 0;
	cin >> n >> k;

    struct Three t;
    for (int i = 0; i < n; i++) {
        cin >> vi >> wi;
        t.ind = i + 1; t.value = vi; t.weight = wi;
        v_max += vi;
        VT[i] = t;
    }
    
    bs(n, k, 0.0, v_max);
    for(int i = 0; i < k; i++)
        cout << VT[i].ind << " ";
	return 0;
}
