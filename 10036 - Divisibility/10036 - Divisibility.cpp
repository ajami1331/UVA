#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, k, t, cs;
int ar[10005];
int vv[10005][105];
bool dp[10005][105];

bool rec( int pos, int rem ) {
    if( pos == n ) return !rem;
    if( vv[pos][rem] == cs ) return dp[pos][rem];
    bool &ret = dp[pos][rem];
    ret = 0;
    vv[pos][rem] = cs;
    ret |= rec( pos+1, ( ( rem + ar[pos] ) % k + k ) % k );
    ret |= rec( pos+1, ( ( rem - ar[pos] ) % k + k ) % k );
    return ret;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &k );
        for( int i=0; i<n; i++ ) scanf( "%d", &ar[i] );
        if( rec( 0, 0 ) ) printf( "Divisible\n" );
        else printf( "Not divisible\n" );
    }
    return 0;
}
