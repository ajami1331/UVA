#include <bits/stdc++.h>
using namespace std;

bool pal_check(string s) {
	return s.empty() ? false : s == string(s.rbegin(), s.rend());
}

int main(){
	string s;
	set <string> ans;
	while( cin >> s ) {
		ans.clear();
		for(int i=0; i<s.size(); i++) {
			for(int j=i; j<=s.size(); j++) {
				if ( pal_check( s.substr(i, j) ) ) ans.insert(s.substr(i, j));
			}
		}
		printf("The string '%s' contains %d palindromes.\n", s.c_str(), ans.size());
	}
    return 0;
}

