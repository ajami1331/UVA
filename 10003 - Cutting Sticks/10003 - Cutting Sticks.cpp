#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int ar[55];

int rec( int l, int r ) {
    if( l + 1 >= r ) return 0;
    int &ret = dp[l][r];
    if( ~ret ) return ret;
    ret = 1e9;
    for( int i=l+1; i<r; i++ ) {
        ret = min( ret, ar[r] - ar[l] + rec( l, i ) + rec( i, r ) );
    }
    return ret;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    int l, n;
    while( cin >> l && l ) {
        cin >> n;
        for( int i=1; i<=n; i++ ) {
            cin >> ar[i];
        }
        ar[0] = 0;
        ar[n+1] = l;
        memset( dp, -1, sizeof dp );
        printf( "The minimum cutting is %d.\n", rec( 0, n+1 ) );
    }
    return 0;
}
