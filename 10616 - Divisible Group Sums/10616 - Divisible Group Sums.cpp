#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, q, d, m, cs, t, qr;
int ar[205];
ll dp[205][11][22];

ll rec( int ii, int cnt, int sum ) {
        if( ii < 0 ) {
        if( !cnt && !sum ) return 1LL;
                return 0;
        }
        if( cnt < 0 ) return 0LL;
        ll &ret = dp[ii][cnt][sum];
        if( ~ret ) return ret;
        ret = ( rec( ii - 1, cnt - 1, ( ( ( sum + ar[ii] ) % d ) + d ) % d ) + rec( ii - 1 , cnt, sum ) );
        return ret;
}

int main() {
        #ifdef CLown1331
                freopen("in.txt", "r", stdin);
        #endif /// CLown1331

        while( scanf( "%d %d", &n, &q ) == 2 && n + q ) {

                for( int i=0; i<n; i++ ) scanf( "%d", &ar[i] );

                printf( "SET %d:\n", ++cs );

                qr = 0;

                while( q-- ) {

                        scanf( "%d %d", &d, &m );

                        memset( dp, -1, sizeof dp );

                        printf( "QUERY %d: %lld\n", ++qr, rec( n-1, m, 0 ) );

                }

        }

        return 0;
}
