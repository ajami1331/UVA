#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 1e5 + 10;

ll ar[sz], tr[sz];

struct nd {
    ll x, y;
    bool operator < ( const nd &ot ) const {
        if( x == ot.x ) return y < ot.y;
        return x < ot.x;
    }
} hand;

int main() {
    #ifdef CLown1331
        freopen("in.txt","r",stdin);
    #endif /// CLown1331
    int t, n, m;
    ll ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &m );
        multiset < nd > pq;
        for( int i=0; i<n; i++ ) {
            scanf( "%lld", &ar[i] );
        }
        sort( ar, ar+n, greater < ll >()  );
        for( int i=0; i<m; i++ ) {
            scanf( "%lld", &tr[i] );
            pq.insert( { 0, tr[i] } );
        }
        ans = 0;
        for( int i=0; i<n; i++ ) {
            hand = *pq.begin();
            pq.erase( pq.begin() );
            ans = max( ans, hand.x + ar[i] );
            pq.insert( { hand.x + hand.y, hand.y } );
        }
        printf( "Case %d: %lld\n", cs, ans );
    }
    return 0;
}
