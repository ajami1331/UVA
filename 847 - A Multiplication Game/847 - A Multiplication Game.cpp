#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map < ll, bool > mp, dp;
ll n;

bool rec( ll h ) {
    if( h >= n ) return 0;
    bool ret = 0;
    if( mp[h] ) return dp[h];
    mp[h] = 1;
    for( int i=2; i<10; i++ ) {
        ret |= !rec( h * i );
    }
    dp[h] = ret;
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    while( cin >> n ) {
        mp.clear();
        dp.clear();
        printf( "%s wins.\n", rec( 1 ) ? "Stan" : "Ollie" );
    }
    return 0;
}
