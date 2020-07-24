/* UVa 10038 Jolly Jumper */
#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
using namespace std;
int main()
{
        //ios_base :: sync_with_stdio(0);
        //cin.tie(0);
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
        int n,l,a,ins;
        bool flag;
        set <int> s;
        while(cin>>n)
        {
                s.clear();
                l=0;
                flag=false;
                for(int i=0;i<n;i++)
                {
                        a=l;
                        cin>>l;
                        if(flag==false)
                        {
				flag=true;
                        }else
                        {
				ins=abs(a-l);
				if(ins>0 && ins<n)
				{
					s.insert(ins);
				}
			}
                }if(s.size()==(n-1))
                {
                        cout<<"Jolly"<<endl;
                }else cout<<"Not jolly"<<endl;
        }
        return 0;
}
