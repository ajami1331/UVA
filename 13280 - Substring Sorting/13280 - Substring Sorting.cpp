#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 1e5 + 10;
const int N = int(1e5)+10;

int cmp(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N];
int rnk[N],height[N];

void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;height[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}

int sa[N],data[N],n;
char str[N];

void deal() {
        DA( data, sa, n + 1, 128 );
        calheight( data, sa, n );
}

int t, q;
int ans[sz];
vector < int > L[sz], R[sz];
vector < pair < int, int > > Q[sz];

int tr[sz];

void upd( int x, int v ) {
        for( ; x<sz; x+=(x&-x) ) tr[x] += v;
}

int qu( int x ) {
        int ret = 0;
        for( ; x>0; x-=(x&-x) ) ret += tr[x];
        return ret;
}

int srch( int k ) {
        int lo = 1, hi = n, mid;
        while( hi - lo > 4 ) {
                mid = ( lo + hi ) / 2;
                if( qu( mid ) >= k ) {
                        hi = mid;
                }
                else {
                        lo = mid;
                }
        }
        for( ; lo<=hi; lo++ ) {
                if( qu( lo ) >= k ) break;
        }
        return lo;
}

int main() {
        #ifdef CLown1331
            freopen("in.txt","r",stdin);
        #endif /// CLown1331

        scanf( "%d", &t );

        for( int cs=1; cs<=t; cs++ ) {

                scanf( "%s", str );

                n = strlen( str );

                str[n++] = (char)125;

                str[n] = '\0';

                for( int i=0; i<n; i++ ) data[i] = str[i];

                deal();

                scanf( "%d", &q );

                for( int i=0; i<=n; i++ ) R[i].clear(), L[i].clear(), Q[i].clear();

                for( int i=0; i<q; i++ ) {

                        int x, y;

                        scanf( "%d %d", &x, &y );

                        Q[x].push_back( { y, i } );
                }

                memset( ans, -1, sizeof ans );

                memset( tr, 0, sizeof tr );

                for( int i=1; i<=n; i++ ) {
                        if( height[i] ) R[ height[i] ].push_back( i );
                        L[  n - sa[i] - 1 ].push_back( i );
                }

                for( int i=n; i>0; i-- ) {
                        for( const int& v: L[i] ) {
                                upd( v, 1 );
                        }
                        for( const int& v: R[i] ) {
                                upd( v, -1 );
                        }
                        for( const auto& it: Q[i] ) {
                                if( qu( n ) >= it.first ) {
                                        ans[ it.second ] = sa[ srch( it.first ) ];
                                }
                        }
                }

                for( int i=0; i<q; i++ ) {
                        if( ans[i] == -1 ) puts( "Not found" );
                        else printf( "%d\n", ans[i] );
                }

        }

        return 0;
}
