#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <map>

using namespace std;

int main() {
	int n, tmp;
    map <int, int> m;
    map <int, int>::iterator p;
	cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        if(i == 0 || tmp != 0)
            m[1]++;
        else {
            p = m.begin();
            m[p->first + 1]++;
            m[p->first]--;
            if(m[p->first] == 0) m.erase(p);
        }
    }
    cout << (--m.end())->first << endl;
	return 0;
}
