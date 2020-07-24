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
const int mx = 5e5 + 10;
int ar[mx], br[mx], tr[mx], n;

int qr( int x ) {
    int ret = 0;
    for( ; x; x-=(x&-x) ) {
        ret += tr[x];
    }
    return ret;
}

void upd( int x ) {
   for( ; x<=n; x+=(x&-x) ) {
        tr[x]++;
    }
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int ind;
    ll ans;
    while( ~scanf( "%d", &n ) && n ) {
        for( int i=0; i<n; i++ ) {
            tr[i] = 0;
            ar[i] = RI();
            br[i] = ar[i];
        }
        tr[n] = 0;
        sort( br, br+n );
        ans = 0;
        for( int i=n-1; i>=0; i-- ) {
            ind = lower_bound( br, br+n, ar[i] ) - br;
            ans += qr( ind );
            upd( ind+1 );
        }
        printf( "%lld\n", ans );
    }
    return 0;
}

