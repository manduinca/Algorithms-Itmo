#include <cstdio>
#include <map>

using namespace std;

struct node {
	long long val;
	node *next, *prev;
};

map <long long, long long> m;

class queue {
	node *last, *first, *temp;
    long long sum, n;
    double mean;
    map <long long, long long>::iterator it;
public:
	queue() {
		last = NULL;
		first = NULL;
        mean = 0; sum = 0; n = 0;
	}
	void push(long long x) {
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
        mean = (double) (sum + x) / (n + 1);
        sum += x; n++;
        it = m.find(x);
        if (it != m.end())
            it->second++;
        else m[x] = 1;
	}
	long long pop() {
		long long x = first->val;
		first = first->prev;
		if(first != NULL) first->next = NULL;
		else last = NULL;
        mean = (double) (sum - x) / (n - 1);
        sum -= x; n--;
        it = m.find(x);
        if (it != m.end())
            if (it->second == 0) m.erase(it);
            else it->second--;
		return x;
	}
    long long query() {
        long long mea = mean;
        if (mean - (double) mea >= 0.00000001) return 0;
        it = m.find(mean);
        if (it != m.end()) {
            //printf("%lld %lld %lf\n", it->first, it->second, mean);
            return it->second;
        }
        return 0;
    }
};

int main() {
	#ifdef JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	#endif
	int n;
    long long x;
	char c, b;
	queue cola;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c", &b);
		scanf("%c", &c);
		if (c == '-') {
			x = cola.pop();
			//printf("%lld\n", x);
		}
        else if (c == '?') {
            x = cola.query();
            printf("%lld\n", x);
        }
		else {
			scanf("%lld", &x);
			cola.push(x);
		}
	}
	return 0;
}
