#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

vector < int > w, s;
int dp[1001], par[1001];

int rec( int pos ) {
    if( ~dp[pos] ) return dp[pos];
    int &ret = dp[pos];
    ret = 0;
    int h;
    for( int i=0; i<w.size(); i++ ) {
        if( i != pos && w[i] > w[pos] && s[i] < s[pos] ) {
            h = rec( i );
            if( h > ret ) {
                ret = h;
                par[pos] = i;
            }
        }
    }
    return ++ret;
}

void print( int i ) {
    cout << i+1 << "\n";
    if( par[i] != -1 ) {
        print( par[i] );
    }
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int x, y;
    memset( dp, -1, sizeof dp );
    memset( par, -1, sizeof par );
    while( cin >> x >> y ) {
        w.push_back( x );
        s.push_back( y );
    }
    int ans = 0;
    for( int i=0; i<w.size(); i++ ) {
        ans = max( ans, rec( i ) );
    }
    cout << ans << "\n";
    for( int i=0; i<w.size(); i++ ) {
        if( dp[i] == ans ) {
            print( i );
            break;
        }
    }
    return 0;
}
