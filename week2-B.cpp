#include <cstdio>

using namespace std;

struct node {
	int val;
	node *next, *prev;
};

class queue {
	node *last, *first, *temp;
public:
	queue() {
		last = NULL;
		first = NULL;
	}
	void push(int x) {
		if(last != NULL) {
			temp = new node;
			temp->val = x;
			temp->next = last;
			temp->prev = NULL;
			last->prev = temp;
			last = temp;
		}
		else {
			last = new node;
			last->val = x;
			last->next = NULL;
			last->prev = NULL;
			first = last;
		}
	}
	int pop() {
		int x = first->val;
		first = first->prev;
		if(first != NULL) first->next = NULL;
		else last = NULL;
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
	queue cola;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%c", &b);
		scanf("%c", &c);
		if(c == '-') {
			x = cola.pop();
			printf("%d\n", x);
		}
		else {
			scanf("%d", &x);
			cola.push(x);
		}
	}
	return 0;
}
