#include <cstdio>
#include <algorithm>
using namespace std;

#define gc			getchar
#define pc			putchar

using ll = long long;
const int sz = 9e6 + 10;
int x[3005], y[3005], calc[sz], cn;
int dist( int i, int j ) {
    return ( x[i] - x[j] ) * ( x[i] - x[j] ) + ( y[i] - y[j] ) * ( y[i] - y[j] ) ;
}

inline void get_num(int& num)
{
    num = 0;
    char c = gc();
    int flag = 0;
    while(!((c>='0' & c<='9') || c == '-'))
        c=gc();
    if(c == '-')
    {
        flag = 1;
        c=gc();
    }
    while(c>='0' && c<='9')
    {
        num = (num<<1)+(num<<3)+c-'0';
        c=gc();
    }
    if(flag==1)
        num=0-num;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
    #endif // LU_SERIOUS
    int n, q, r;
    double ans = 0;
    while( 1 ) {
        get_num( n );
        get_num( q );
        if( n+q == 0 ) break;
        cn = 0;
        for( int i=0; i<n; i++ ) get_num( x[i] ), get_num( y[i] );
        for( int i=0; i<n; i++ ) {
            calc[cn++] = 0;
            for( int j=i+1; j<n; j++ ) {
                calc[ cn++ ] = dist( i, j );
                calc[ cn ] = calc[ cn-1 ];
                cn++;
            }
        }
        sort( calc, calc+cn );
        for( int i=0; i<q; i++ ) {
            get_num( r );
            r *= r;
            ans = ( upper_bound(calc, calc+cn, r ) - calc );
            ans /= n;
            printf( "%.2f\n", ans );
        }
        pc( '\n' );
    }
    return 0;
}
