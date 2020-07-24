#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, mp = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	while( getline(cin, s) ) {
		for(char &c: s) {
			c  = tolower(c);
			if(c == ' ') putchar(c);
			else {
				cout << mp [ ( mp.find( c ) - 2 ) ] ;
			}
		}
		putchar('\n');
	}
    return 0;
}

