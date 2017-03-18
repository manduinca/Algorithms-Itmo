#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif

#include <string>

using namespace std;

struct node {
	int val;
	node *first;
};

class stack {
	node *p, *t;
	int x;
public:
	stack() {p = NULL;}
	void push(int x) {
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
    int front() {
        return p->val;
    }
    bool is_empty() {
        return p == NULL;
    }
};

int main() {
    int n;
    string s;

	cin >> n;
    while(n) {
        cin >> s;
        stack pila;
        bool ban = 0;
        int m = s.size();
        for(int i = 0; i < m; i++) {
            if(s[i] == '(') pila.push(1);
            else if(s[i] == '[') pila.push(2);
            else if(s[i] == ')') {
                if(pila.is_empty()) {cout << "NO\n"; ban = 1; break;}
                if(pila.front() == 1) pila.pop();
                else {cout << "NO\n"; ban = 1; break;}
            }
            else if(s[i] == ']') {
                if(pila.is_empty()) {cout << "NO\n"; ban = 1; break;}
                if(pila.front() == 2) pila.pop();
                else {cout << "NO\n"; ban = 1; break;}
            }
        }
        if(!ban)
            if(pila.is_empty()) cout << "YES\n";
            else cout << "NO\n";
        n--;
    }
	return 0;
}
