#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int recur(int i,int j,string &s,string &r) {
    if( i == s.size() || j == r.size() ) return 0;
    if( dp[i][j] != -1 ) return  dp[i][j];
    int &ret = dp[i][j];
    if( s[i] == r[j] ) return ret = 1 + recur( i+1, j+1, s, r );
    else return ret = max( recur( i+1, j, s, r ), recur(  i, j+1, s, r ) );
}

int main() {
    string s, r;
    int t;
    cin >> t;
    cin.ignore();
    while(t-- && getline( cin, s )) {
        r = string( s.rbegin(), s.rend() );
        memset( dp, -1, sizeof dp );
        cout << recur( 0, 0, s, r ) << "\n";
    }
    return 0;
}
