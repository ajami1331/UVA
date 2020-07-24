#include <cstdio>
using namespace std;

int main(){
	int t, x;
	bool fl;
	scanf("%d", &t);
	for(int cs=1; cs<=t; cs++){
		fl = true;
		for(int i=0; i<13; i++){
			scanf("%d", &x);
			if(!x) fl = false;
		}
		printf("Set #%d: ", cs);
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}

