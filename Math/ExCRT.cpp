pair<int,int> solve(int a[],int r[],int n)
{
    int M=a[1],R=r[1];
    for(int i=2;i<=n;i++)
    {
        int x,y;
        int g=exgcd(M,a[i],x,y);
        if((r[i]-R)%g)return make_pair(-1,-1);
        int t=a[i]/g;
        x=(((r[i]-R)/g*x)%t+t)%t;
        R+=x*M;
        M=M*a[i]/g;
    }
    return make_pair(M,R);
    //解的形式：ans ＝ R (mod M)
    //return (M, R)
}