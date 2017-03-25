#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <vector>

using namespace std;


struct node {
	long long int val;
	node *first;
};


class stack {
	node *p, *t;
	long long int x, total;
public:
	stack() {p = NULL;}
	void push(long long int x) {
		if(p != NULL) {
			t = new node;
			t->val = x;
			t->first = p;
			p = t;
            total += x;
		}
		else {
			p = new node;
			p->val = x;
			p->first = NULL;
            total = x;
		}
	}
	int pop() {
		x = p->val;
		p = p->first;
        total -= x;
		return x;
	}
    int get_total() {
        return total;
    }
    void print() {
        t = p;
        while(t != NULL) {
            cout << t->val << " ";
            t = t->first;
        }
        cout << endl;
    }
};


int main() {
	int n, ind, val;
    vector <stack> vs;
    stack tmp;
    vs.push_back(tmp);
	cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> ind >> val;
        stack tmp(vs[ind]);
        if(val != 0) tmp.push(val);
        else tmp.pop();
        vs.push_back(tmp);
    }
    long long int sum = 0;
    for(int i = 1; i <= n; i++) {
        //vs[i].print();
        //cout << vs[i].get_total() << endl;
        sum += vs[i].get_total();
    }
    cout << sum;
	return 0;
}
