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

const int N = 10000001;
int F[] = {0, 1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260,
         1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360,
         50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960,
         554400, 665280, 720720, 1081080, 1441440, 2162160, 2882880, 3603600,
         4324320, 6486480, 7207200, 8648640, 10000001};

/***

int divisors(int n) {
    int con = 0, i;
    for(i = 1; i * i < n; i++)
        if(n % i == 0) con += 2;
    if(i * i == n) con++;
    return con;
}

void max_divisors() {
    int div, k = 2, max_div = 1;
    F[1] = 1;
    for(int i = 2; i < N; i++) {
        div = divisors(i);
        if(div > max_div) {F[k] = i; max_div = div; k++;}
    }
}

***/

int main() {
    int n, i = 1;
    cin >> n;
    while(n >= F[i]) {
        i++;
    }
    cout << n - F[i - 1] + 1 << endl;
    return 0;
}
