#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;
char str[13];
int dp[1<<12+1];
int vv[1<<12+1];
int cs, msk, t;


bool check( int mask, int pos ) {
    return mask & ( 1 << pos );
}

int Set( int mask, int pos ) {
    return mask | ( 1 << pos );
}

int reSet( int mask, int pos ) {
    return mask & ~( 1 << pos );
}

int rec( int mask ) {
    if( vv[mask] == cs ) return dp[mask];
    vv[mask] = cs;
    int &ret = dp[mask];
    int h = mask;
    ret = 0;
    for( int i=0; i<12; i++ ) ret += check( mask, i );
    for( int i=0; i<11; i++ ) {
        if( check( mask, i ) and check( mask, i+1 ) ) {
            if( i+2 < 12 and !check( mask, i+2 ) ) {
                mask = Set( mask, i+2 );
                mask = reSet( mask, i+1 );
                mask = reSet( mask, i );
                ret = min( ret, rec( mask ) );
                mask = h;
            }
            if( i-1 >= 0 and !check( mask, i-1 ) ) {
                mask = Set( mask, i-1 );
                mask = reSet( mask, i+1 );
                mask = reSet( mask, i );
                ret = min( ret, rec( mask ) );
                mask = h;
            }
        }
    }
    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        msk = 0;
        scanf( "%s", str );
        for( int i=0; str[i]!='\0'; i++ ) {
            if( str[i] == 'o' ) msk = Set( msk, i );
        }
        printf( "%d\n", rec( msk ) );
    }
    return 0;
}
