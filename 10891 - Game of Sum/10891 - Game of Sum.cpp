#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int n, ar[105];
int dp[105][105][2];
int vis[105][105][2];

int rec( int left, int right, int player ) {
    if( left > right ) return 0;
    int &ret = dp[left][right][player];
    if( vis[left][right][player] ) return ret;
    ret = -1e9;
    vis[left][right][player] = 1;
    int h = 0;
    for( int i=left; i<=right; i++ ) {
        h += ar[i];
        ret = max( ret, h - rec( i+1, right, player^1 ) );
    }
    h = 0;
    for( int i=right; i>=left; i-- ) {
        h += ar[i];
        ret = max( ret, h - rec( left, i-1, player^1 ) );
    }
    return ret;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr ); cout.tie( nullptr );
    while( cin >> n && n ) {
        for( int i=0; i<n; i++ ) cin >> ar[i];
        memset( vis, 0, sizeof vis );
        cout << rec( 0, n-1, 0 ) << "\n";
    }
    return 0;
}
