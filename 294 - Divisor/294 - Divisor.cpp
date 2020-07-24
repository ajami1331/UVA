#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int lim = 1e5 + 10;

int main() {
    int t, l, r, ans, num, hand;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &l, &r );
        ans = 0; num = 0;
        for( int i=l; i<=r; i++ ) {
            hand = 0;
            for( int j=1; j*j<=i; j++ ) {
                if( i % j == 0 ) {
                    hand++;
                    if( j * j != i ) hand++;
                }
            }
            if( ans < hand ) {
                ans = hand;
                num = i;
            }
        }
        printf( "Between %d and %d, %d has a maximum of %d divisors.\n", l, r, num, ans );
    }
    return 0;
}