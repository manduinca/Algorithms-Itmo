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

int main() {
	long long int a, b;
	cin >> a >> b;
	cout << a + b * b << endl;
	return 0;
}
