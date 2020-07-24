#include <bits/stdc++.h>
using namespace std;

bool palcheck(string s) {
	for (int i=0,j=s.size()-1; i<j; i++,j--) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

string process(string s) {
	string ret = "";
	for (char c: s) {
		if (!isalpha(c)) continue;
		ret += tolower(c);
	}
	return ret;
}

int main(){
	string line;
	while (getline(cin,line) && line != "DONE") {
		puts ( palcheck(process(line)) ? "You won't be eaten!" : "Uh oh.." ) ;
	}
    return 0;
}

