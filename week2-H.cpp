#include <cstdio>
#include <cstring>

using namespace std;

struct node {
	int val;
	node *next, *prev;
};

class stack {
	node *first, *last, *middle, *tmp;
	int x, size;
public:
	stack() {first = last = middle = NULL; size = 0;}
	void push(int x) {
		if(last != NULL) {
            if(size == 1) middle = first;
			tmp = new node;
			tmp->val = x;
            tmp->prev = NULL;
			tmp->next = last;
            last->prev = tmp;
			last = tmp;
            if(size > 1 && size % 2 != 0)
                middle = middle->prev;
		}
		else {
			last = new node;
			last->val = x;
			last->next = NULL;
            last->prev = NULL;
            first = last;
		}
        size++;
	}
	int pop() {
        if(size % 2 == 0)
            middle = middle->next;
		x = last->val;
        last->prev = NULL;
		last = last->next;
        if(last == NULL) first = last;
        size--;
		return x;
	}
    void mum() {
        if(size > 1) {
            first->next = last;
            last->prev = first;
            if(size % 2 == 0) tmp = last;
            else tmp = last->next;
            last = middle;
            first = middle->prev;
            first->next = NULL;
            last->prev = NULL;
            middle = tmp;
        }
    }
    void print() {
        printf("%d\n", size);
        tmp = first;
        while(tmp != NULL) {
            printf("%d ", tmp->val);
            tmp = tmp->prev;
        }
    }
};

int main() {
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif
	int n, x;
	char s[10];
	stack pila;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", s);
		if(strcmp(s, "add") == 0) {
            scanf("%d", &x);
			pila.push(x);
		}
		else if(strcmp(s, "take") == 0) pila.pop();
		else pila.mum();
	}
    pila.print();
	return 0;
}
