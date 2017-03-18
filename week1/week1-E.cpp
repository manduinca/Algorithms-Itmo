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

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(7) << (a + b + c) / 6 << endl;
	return 0;
}
