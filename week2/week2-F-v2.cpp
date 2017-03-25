#include <cstdio>
#include <vector>

using namespace std;

struct node {
    long long last, sum, prev;
};

int main() {
    
    #ifdef JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    
    int n, ind;
    long long m, sum = 0;
    vector <node> A(1000001);
    scanf("%d", &n);

    A[0].last = 0;
    A[0].sum = 0;
    A[0].prev = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d %lld", &ind, &m);
        if(m == 0) {
            A[i].sum = A[ind].sum - A[ind].last;
            A[i].last = A[A[ind].prev].last;
            A[i].prev = A[A[ind].prev].prev;
        }
        else {
            A[i].sum = A[ind].sum + m;
            A[i].prev = ind;
            A[i].last = m;
        }
        sum += A[i].sum;
    }
    printf("%lld", sum);
    return 0;
}
