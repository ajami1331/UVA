#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int sz = 1e6 + 10;

char s[sz];
char m[sz];
int table[sz], lenA, lenB;

void compute_failure() {
        table[ 0 ] = 0;
        int i = 1, j = 0;
        while( i < lenB ) {
                if( m[i] == m[j] ) {
                        j++;
                        table[ i ] = j;
                        i++;
                }
                else {
                        if( j ) {
                                j = table[ j - 1 ];
                        }
                        else {
                                table[ i ] = 0;
                                i++;
                        }
                }
        }
}

int kmp() {
        int i = 0, j = 0;
        while( i < lenA ) {
                while( i < lenA && j < lenB && s[i] == m[j] ) {
                        i++;
                        j++;
                }
                if( j == lenB ) {
                        return j;
                }
                else if( i < lenA && s[i] != m[j] ) {
                        if( j ) {
                                j = table[ j - 1 ];
                        }
                        else {
                                i++;
                        }
                }
        }
        return j;
}

int main() {
        #ifdef CLown1331
                freopen( "in.txt","r",stdin );
        #endif /// CLown1331
        int n, cs = 0, ans;
        while( scanf( "%s", s ) == 1 ) {

                lenA = strlen( s );

                lenB = lenA;

                for( int i=0; i<lenA; i++ ) m[i] = s[i];

                reverse( m, m + lenB );

                compute_failure();

                int len = kmp();

                printf( "%s", s );

                for( int i=len; i<lenB; i++ ) printf( "%c", m[i] ); printf( "\n" );
        }
        return 0;
}
