#include <cstdio>

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
};

int main() {
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif
	int n, x;
	char c, b;
	stack pila;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%c", &b);
		scanf("%c", &c);
		if(c == '-') {
			x = pila.pop();
			printf("%d\n", x);
		}
		else {
			scanf("%d", &x);
			pila.push(x);
		}
	}
	return 0;
}
