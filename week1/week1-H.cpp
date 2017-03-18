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
	int n, A[15], time = 18000, con = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	sort(A, A + n);
	for(int i = 0; i < n; i++)
		if(A[i] <= time) {time -= A[i]; con++;}
		else break;
	cout << con << endl;
	return 0;
}
