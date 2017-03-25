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

struct node {
	long long int val;
	node *first;
};

class stack {
	node *p, *t;
	long long int x;
public:
	stack() {p = NULL;}
	void push(long long int x) {
		if(p != NULL) {
			t = new node;
			t->val = x;
			t->first = p;
			p = t;
		}
		else {
			p = new node;
			p->val = x;
			p->first = NULL;
		}
	}
	int pop() {
		x = p->val;
		p = p->first;
		return x;
	}
};

int main() {
	int n;
    long long int tmp;
	char c;
	stack pila;
    cin >> n;
	for(int i = 0; i < n; i++) {
        cin >> c;
        if(c >= '0' && c <= '9')
            pila.push(c - '0');
		else if(c == '-') {
            tmp = pila.pop();
			pila.push(pila.pop() - tmp);
        }
		else if(c == '+') 
			pila.push(pila.pop() + pila.pop());
		else if(c == '*') 
			pila.push(pila.pop() * pila.pop());
	}
    cout << pila.pop();
	return 0;
}
