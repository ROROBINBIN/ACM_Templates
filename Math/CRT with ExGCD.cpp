int exgcd(int a,int b,int &x,int &y)
{
    if(!b)return x=1,y=0,a;
    int d=exgcd(b,a%b,x,y),t=x;
    return x=y,y=t-a/b*y,d;
}

pair<int,int> CRT(int a[],int r[],int n)
{
    int R=0,M=1;
    for(int i=1;i<=n;i++)M*=a[i];
    for(int i=1;i<=n;i++)
    {
        int t=M/a[i],x,y;
        exgcd(t,a[i],x,y);
        R=(r[i]*t%M*x%M+R)%M;
    } 
return make_pair(M,(R+M)%M);
//解的形式：ans ＝ R (mod M)
//return (M, R)
}
