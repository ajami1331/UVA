#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, m, ans, fl;
    vector < int > ar;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        ans = 0;
        ar.clear();
        scanf( "%d %d", &n, &m );
        queue < pair < int, int > > Q;
        for( int i=0,x; i<n; i++ ) {
            scanf( "%d", &x );
            ar.push_back( x );
            Q.push( { x, i } );
        }
        sort( ar.begin(), ar.end() );
        fl = 1;
        while( fl && Q.size() ) {
            ans++;
            while( 1 && Q.size() ) {
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                if( x != ar.back() ) {
                    Q.push( { x, y } );
                    continue;
                }
                else {
                    if( y == m ) fl = 0;
                    ar.pop_back();
                    break;
                }
            }
        }
        printf( "%d\n", ans );
    }
    return 0;
}