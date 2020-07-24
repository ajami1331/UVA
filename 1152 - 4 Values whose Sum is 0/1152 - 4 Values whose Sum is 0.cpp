#include <bits/stdc++.h>
using namespace std;

int ar[4005];
int br[4005];
int cr[4005];
int dr[4005];
unordered_map < int, int > mp;

int main() {
    int t, n, ans;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        ans = 0;
        scanf( "%d", &n );
        for( int i=0; i<n; i++ ) {
            scanf( "%d %d %d %d", &ar[i], &br[i], &cr[i], &dr[i] );
        }
        mp.clear();
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                mp[ cr[i] + dr[j] ]++;
            }
        }
        for( int i=0; i<n; i++ ) {
            for( int j=0; j<n; j++ ) {
                int xx = ar[i] + br[j];
                int yy = 0 - xx;
                if( mp.count( yy ) ) ans += mp[yy];       
            }
        }
        if( cs != 1 ) printf( "\n" );
        printf( "%d\n", ans );
    }
    return 0;
}