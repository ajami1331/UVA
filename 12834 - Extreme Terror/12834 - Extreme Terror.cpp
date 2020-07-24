#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 1e6 + 10;

ll ar[sz];

int main() {
    #ifdef CLown1331
        freopen("in.txt","r",stdin);
    #endif /// CLown1331
    int t, n, k;
    ll ans, x;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &k );
        for( int i=0; i<n; i++ ) {
            scanf( "%lld", &ar[i] ) ;
        }
        ans = 0;
        for( int i=0; i<n; i++ ) {
            scanf( "%lld", &x ) ;
            ar[i] = x - ar[i];
        }
        sort( ar, ar+n );
        for( int i=0; i<k; i++ ) {
            if( ar[i] < 0 ) continue;
            ans += ar[i];
        }
        for( int i=k; i<n; i++ ) ans += ar[i];
        if( ans < 0 ) printf( "Case %d: No Profit\n", cs );
        else printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
