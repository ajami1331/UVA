#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
vector < int > ar;
int lis[10005];

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int h, cs = 0, ans;
    while( ~scanf( "%d", &h ) ) {
        if( h == -1 ) {
            if( ar.empty() ) break;
            if( cs ) printf( "\n");
            printf( "Test #%d:\n", ++cs );
            ans = 0;
            for( int i=ar.size()-1; i>=0; i-- ) {
                lis[i] = 1;
                for( int j=ar.size()-1; j>i; j-- ) {
                    if( ar[i] > ar[j] && lis[j]+1 > lis[i] ) {
                        lis[i] = lis[j]+1;
                    }
                }
                ans = max( ans, lis[i] );
            }
            printf( "  maximum possible interceptions: %d\n", ans );
            ar.clear();
        } else ar.push_back( h );
    }
    return 0;
}
