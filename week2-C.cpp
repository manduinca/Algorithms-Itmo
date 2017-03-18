#include <cstdio>
#include <algorithm>

using namespace std;


struct node {
	int val;
	node *next, *prev;
};


struct doublenode {
	int val, valtwo;
	doublenode *first;
};


class doubleStack {

    doublenode *p, *t;
	int x;

public:

	doubleStack() {p = NULL;}

	void push(int x) {
		if(p != NULL) {
			t = new doublenode;
			t->val = x;
			t->first = p;
            if(p->val < x) t->valtwo = p->val;
            else t->valtwo = x;
			p = t;
		}
		else {
			p = new doublenode;
			p->val = x;
			p->valtwo = x;
			p->first = NULL;
		}
	}

	int pop() {
		x = p->val;
		p = p->first;
		return x;
	}

    int query() {
        return p->valtwo;
    }

    int is_empty() {
        if(p == NULL) return 1;
        return 0;
    }
};


class minQueue {

    int m;
	node *last, *first, *temp;
    doubleStack pila;

public:

	minQueue() {
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
            m = min(m, x);
		}
		else {
			last = new node;
			last->val = x;
			last->next = NULL;
			last->prev = NULL;
			first = last;
            m = x;
		}
	}

	int pop() {
        if(pila.is_empty()) {
            temp = last;
            while(temp != NULL) {
                pila.push(temp->val);
                temp = temp->next;
            }
            first = NULL;
            last = NULL;
        }
        return pila.pop();
	}

    int query() {
        if(pila.is_empty()) return m;
        else if(first == NULL) return pila.query();
        return min(m, pila.query());
    }
};


int main() {
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif
	int n, x;
	char c, b;
	minQueue cola;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%c", &b);
		scanf("%c", &c);
		if(c == '-') {
			x = cola.pop();
			//printf("%d\n", x);
		}
        else if (c == '?') {
			x = cola.query();
			printf("%d\n", x);
        }
		else {
			scanf("%d", &x);
			cola.push(x);
		}
	}
	return 0;
}
