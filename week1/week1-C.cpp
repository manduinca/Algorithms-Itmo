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
	int n, A[100], B[100], sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	for(int i = 0; i < n; i++)
		cin >> B[i];
	int cona = 0, conb = 0, dif = 1000;
	for(int i = 0; i < n; i++) {
		if(A[i] > B[i]) {
			dif = min(dif, A[i] - B[i]);
			sum += A[i];
			cona++;
		}
		else {
			dif = min(dif, B[i] - A[i]);
			sum += B[i];
			conb++;
		}
	}
	if(cona == n || conb == n)
		cout << sum - dif << endl;
	else
		cout << sum << endl;
	return 0;
}
