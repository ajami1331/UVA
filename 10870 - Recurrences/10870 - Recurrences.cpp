#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mat_sz = 20;
int mod;

struct Matrix {
    int a[mat_sz][mat_sz];
    void clear() {
        memset(a, 0, sizeof(a));
    }
    void one() {
        for( int i=0; i<mat_sz; i++ ) {
            for( int j=0; j<mat_sz; j++ ) {
                a[i][j] = i == j;
            }
        }
    }
    Matrix operator + (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i <  mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                tmp.a[i][j] = a[i][j] + b.a[i][j];
                if (tmp.a[i][j] >= mod) {
                    tmp.a[i][j] -= mod;
                }
            }
        }
        return tmp;
    }
    Matrix operator * (const Matrix &b) const {
        Matrix tmp;
        tmp.clear();
        for (int i = 0; i < mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                for (int k = 0; k < mat_sz; k++) {
                    tmp.a[i][k] += (long long)a[i][j] * b.a[j][k] % mod;
                    if (tmp.a[i][k] >= mod) {
                        tmp.a[i][k] -= mod;
                    }
                }
            }
        }
        return tmp;
    }
    Matrix pw(int x) {
        Matrix ans, num = *this;
        ans.one();
        while (x > 0) {
            if (x & 1) {
                ans = ans * num;
            }
            num = num * num;
            x >>= 1;
        }
        return ans;
    }
} fib;

int ar[25], f[25];
int n, m, ans, d;

int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif // CLown1331
    while( ~scanf( "%d %d %d", &d, &n, &m ) && ( d + n + m ) ) {
        mod = m;

        for( int i=0; i<d; i++ ) scanf( "%d", &ar[i] );
        for( int i=0; i<d; i++ ) scanf( "%d", &f[i] );

        if( n > d ) {
            fib.clear();
            for( int i=0; i<d; i++ ) fib.a[0][i] = ar[i];
            for( int i=1,j=0; i<d; i++, j++ ) fib.a[i][j] = 1;
            fib = fib.pw( n - d );
            ans = 0;
            for( int i=0,j=d-1; i<d; i++, j-- ) ans = ( ans + ( ( fib.a[0][i] % mod ) * ( f[j] % mod ) ) ) % mod;
        } else {
            ans = f[ n - 1 ] % mod;
        }

        printf( "%d\n", ans );
    }
    return 0;
}
