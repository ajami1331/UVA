#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, cs = 0;
    long long ar[22], ans, hand;
    while( scanf( "%d", &n ) == 1 ) {
        ans = 0;
        for( int i=0; i<n; i++ ) scanf( "%lld", &ar[i] );
        for( int i=0; i<n; i++ ) {
            hand = 1;
            for( int j=i; j<n; j++ ) {
                hand *= ar[j];
                ans = max( ans, hand );
            }
        }
        printf( "Case #%d: The maximum product is %lld.\n\n", ++cs, ans );
    }
    return 0;
}