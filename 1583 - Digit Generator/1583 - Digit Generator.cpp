#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int sz = 1e6 + 100;

int t, n, ans;

int sod( int x ) {
        int ret = x;
        while( x ) {
                ret += x % 10;
                x /= 10;
        }
        return ret;
}

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        while( t-- && scanf( "%d", &n ) == 1 ) {

                ans = 0;

                for( int i=max(n-100,0); i<=n; i++ ) {
                        if( sod( i ) == n ) {
                                ans = i;
                                break;
                        }
                }

                printf( "%d\n", ans );

        }

        return 0;
}
