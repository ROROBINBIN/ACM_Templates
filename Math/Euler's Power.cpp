#include<bits/stdc++.h>
 
using namespace std;
 
const int maxm=1e5+10;
 
int n,m,q,bj;
int v[maxm+10];
vector<int> M;
 
inline int work(int a,int b,int m)
{
    if(1ll*a*b>=m)bj=1;
    return 1ll*a*b%m;
}
 
int qpow(int a,int b,int m)
{
    int re;
    for(re=1;b;b>>=1,a=work(a,a,m))
        if(b&1)re=work(re,a,m);
    return re;
}
 
int getphi(int t)
{
    int re=t;
    for(int i=2;i*i<=t;i++)
    {
        if(t%i!=0)continue;
        re/=i,re*=(i-1);
        while(t%i==0)t/=i;
    }
    if(t!=1)re/=t,re*=(t-1);
    return re;
}
 
int euler(int v[],int l,int r)
{
    bj=0;
    int mx=min(r-l+1,(int)M.size());
    int now=work(v[l+mx-1],1,M[mx-1]);
    for(int i=mx-2;i>=0;i--)
    {
        if(bj)now+=M[i+1];
        bj=0;
        now=qpow(v[l+i],now,M[i]);
    }
    return now;
}
 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    
    int tmp=m;
    for(M.push_back(tmp);tmp!=1;tmp=getphi(tmp),M.push_back(tmp));
 
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",euler(v,l,r));
    }
 
    return 0;
}