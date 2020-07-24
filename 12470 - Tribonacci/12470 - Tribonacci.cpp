#include <bits/stdc++.h>
using namespace std;


inline int RI() {
    int ret = 0, flag = 1,ip = getchar();
    for(; ip < 48 || ip > 57; ip = getchar()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

using ll = long long;
const int mat_sz = 3;
const ll mod = 1e9 + 9;

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
    Matrix pw(ll x) {
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

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    ll ans, n;
    while( ~scanf( "%lld", &n ) && n ) {
        fib.a[0][0] = 1 % mod;
        fib.a[0][1] = 1 % mod;
        fib.a[0][2] = 1 % mod;
        fib.a[1][0] = 1 % mod;
        fib.a[1][1] = 0 % mod;
        fib.a[1][2] = 0 % mod;
        fib.a[2][0] = 0 % mod;
        fib.a[2][1] = 1 % mod;
        fib.a[2][2] = 0 % mod;

        if( n == 1 ) ans = 0 % mod;
        else if( n == 2 ) ans = 1 % mod;
        else if( n == 3 ) ans = 2 % mod;
        else {
            fib = fib.pw( n-3 );
            ans = ( ( ( fib.a[0][0] * 2LL ) % mod ) + ( ( fib.a[0][1] * 1LL ) % mod ) + ( ( fib.a[0][2] * 0LL ) % mod ) ) % mod;
        }
        printf( "%lld\n", ans );
    }
    return 0;
}

