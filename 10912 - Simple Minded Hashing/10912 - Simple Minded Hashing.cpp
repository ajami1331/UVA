#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int l, s, cs;
int dp[27][27][350];

int rec( int pos, int ch, int sum ) {
    if( l > 26 || s > 351 ) return 0;
    if( pos == l ) return sum == s;
    int &ret = dp[pos][ch][sum];
    if( ~ret ) return ret;
    ret = 0;
    for( int i=ch+1; i<=26; i++ ) {
        ret += rec( pos+1, i, sum+i );
    }
    return ret;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr ); cout.tie( nullptr );
    while( cin >> l >> s && l+s ) {
        memset( dp, -1, sizeof dp );
        cout << "Case " << ++cs << ": " << rec( 0, 0, 0 ) << "\n";
    }
    return 0;
}
