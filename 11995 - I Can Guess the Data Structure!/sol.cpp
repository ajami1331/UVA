#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e4;

int main(){
	int t, cs = 0, n, ti, no, a, b, c, hst, hpq, hq;
	while(cin >> n) {
        stack < int > ST;
        priority_queue < int > PQ;
        queue < int > Q;
        a = 1; b = 1; c = 1;
        while(n--) {
			cin >> ti >> no;
			if(ti == 1) {
				ST.push(no);
				Q.push(no);
				PQ.push(no);
			} else {
				if(!ST.empty()) {
					hst = ST.top();
					ST.pop();
				} else a = 0;
				if(!PQ.empty()) {
					hpq = PQ.top();
					PQ.pop();
				} else b = 0;
				if(!Q.empty()) {
					hq = Q.front();
					Q.pop();
				} else c = 0;
				if(hst != no) {
					a = 0;
				}
				if(hpq != no) {
					b = 0;
				}
				if(hq != no) {
					c = 0;
				}
			}
        }
        if(a+b+c > 1) puts("not sure");
        else if(a+b+c == 0) puts("impossible");
        else {
            if(a) {
				puts("stack");
            } else if(b) {
				puts("priority queue");
            } else {
				puts("queue");
            }
        }
	}
	return 0;
}

