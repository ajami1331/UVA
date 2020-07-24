#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[1005][1005];
int rec( int i, int j ) {
    if( i == a.size() || b.size() == j ) return 0;
    int &ret = dp[i][j];
    if( ~ret )  return ret;
    ret = 0;
    ret = max( { ret, rec( i + 1, j ), rec( i, j + 1 ), a[i] == b[j] ? 1 + rec( i + 1, j + 1 ) : 0 } );
    return ret;
}
int main() {
    while( getline( cin, a ) ) {
        getline( cin, b );
        memset( dp, -1, sizeof dp );
        cout << rec( 0, 0 ) << "\n";
    }
    return 0;
}