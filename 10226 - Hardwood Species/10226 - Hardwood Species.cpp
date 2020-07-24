#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 10;
int tree[mx], ar[mx], tr[mx], n;

inline int RI() {
    int  ret = 0, flag = 1,ip = getchar();
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

struct node {
    bool en;
    int cnt;
    node *next[128];
    node() {
        en = 0;
        cnt = 0;
        for( int i=0; i<128; i++ ) next[i] = NULL;
    }
    void insert( string &str, int p )  {
        int id;
        if( str.size() == p ) {
            cnt++;
            en = 1;
            return;
        }
        id = str[p];
        if( next[id] == NULL ) next[id] = new node();
        next[id]->insert( str, p+1 );
    }
    int koita( string &str, int p )  {
        int id;
        if( str.size() == p ) return cnt;
        id = str[p];
        if( next[id] == NULL ) return 0;
        return next[id]->koita( str, p+1 );
    }
    void del() {
        for( int i=0; i<128; i++ ) {
            if( next[i] != NULL ) next[i]->del();
        }
        delete this;
    }
} *root;

string s;
set < string > st;

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    int t, cs, n;
    double h, tot;
    t = RI();
    getline( cin, s );
    for( cs=1; cs<=t; cs++ ) {
        root = new node();
        tot = 0.0;
        st.clear();
        while( getline( cin, s ) ) {
            if( s.empty() ) break;
            st.insert( s );
            root->insert( s, 0 );
            tot++;
        }
        for( string ss: st ) {
            h = root->koita( ss, 0 );
            h /= tot;
            printf( "%s %.4f\n", ss.c_str(), h * 100.0 );
        }
        if( cs < t ) puts( "" );
        root->del();
    }
    return 0;
}
