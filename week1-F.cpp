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
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int A[127];

int va(int a) {
	if(a < 0)
		return a * -1;
	return a;
}

int _distance(int a, int b) {
	int aj = A[a] % 10000;
	int ai = A[a] / 10000;
	int bj = A[b] % 10000;
	int bi = A[b] / 10000;
	return max(va(aj - bj), va(ai - bi));
}

int main() {
	int w, h;
	char c;
	cin >> w >> h;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			cin >> c;
			A[c] = 10000 * i + j;
			//cout << c;
		}
		//cout << endl;
	}
	string lang, lang_temp, cad, s;
	int sum = 100000000, sum_temp, ant, k;
	for(int ri = 0; ri < 3; ri++) {
		cin >> s;
		//cout << s << endl;
		lang_temp = s;
		cin >> s;
		if(s == "%TEMPLATE-START%") {
			sum_temp = 0;
			k = 0;
			cin >> cad;
			while(cad != "%TEMPLATE-END%") {
				if(k != 0) sum_temp += _distance(cad[0], ant);
				for(int i = 1; i < cad.size(); i++) {
					sum_temp += _distance(cad[i], cad[i - 1]);
				}
				ant = cad[cad.size() - 1];
				cin >> cad;
				k++;
			}
			if(sum_temp < sum) {
				sum = sum_temp;
				lang = lang_temp;
			}
		}
	}
	cout << lang << endl << sum;
	return 0;
}
