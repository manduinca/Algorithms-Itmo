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
#include <cmath>
#include <iomanip>

using namespace std;

double p(int a, int b, int c) {
	return sqrt(a * a + b * b + c * c);
}

double mayor6(double a, double b, double c, double d, double e, double f) {
	return max(max(a, max(b, c)), max(d, max(e, f)));
}

int main() {
	int A[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> A[i][j];
	cout << fixed << setprecision(7) << mayor6(
		p(A[0][0], A[1][1], A[2][2]), p(A[0][0], A[1][2], A[2][1]),
		p(A[0][1], A[1][0], A[2][2]), p(A[0][1], A[1][2], A[2][0]),
		p(A[0][2], A[1][0], A[2][1]), p(A[0][2], A[1][1], A[2][0])
	) << endl;
	return 0;
}
