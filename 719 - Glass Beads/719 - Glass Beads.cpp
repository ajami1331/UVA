#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
const int sz = 1e5 + 10;
int f[sz];

int calc( const string& s ) {
    int n = s.size();
    string t = s + s;
    memset( f, -1, sizeof f );
    int k = 0;
    for( int j = 1; j < 2 * n; ++j ) {
        int i = f[j - k - 1];
        while( i != -1 && t[j] != t[k + i + 1] ) {
            if( t[j] < t[k + i + 1] ) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if( i == -1 && t[j] != t[k + i + 1] ) {
            if( t[j] < t[k + i + 1] ) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr ); cout.tie( nullptr );
    int t;
    cin >> t;
    string s;
    while( t-- && cin >> s ) {
        cout << calc( s ) + 1 << "\n";
    }
    return 0;
}
