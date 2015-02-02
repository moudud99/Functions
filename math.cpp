///  sieve method for generating prime numbers
bool prime_bool[Limit];
vector<int>prime;
void generate_prime()
{
    int i,j,root=sqrt(Limit);
    for(i=4;i<Limit;i+=2)prime_bool[i]=true;
    for(i=3;i<=root;i+=2)if(!prime_bool[i]) for(j=i*i;j<Limit;j+=2*i)prime_bool[j]=true;
    prime.push_back(2);
    for(i=3;i<Limit;i+=2)if(!prime_bool[i])prime.push_back(i);
}

///  ----------------------Euler Phy----------------------
// provided that vector<int>prime exists
int euler_phy(int n)
{
    if(n==1)return 0;
    int i,tem,phy=n;
    for(i=0;prime[i]*prime[i]<=tem;i++)if(n%prime[i]==0)
    {
        phy/=prime[i];
        phy*=(prime[i]-1);
        while(n%prime[i]==0)n/=prime[i];
    }
    if(n>1)
    {
        phy/=n;
        phy*=(n-1);
    }
    return phy;
}


///  Returns reminder of string s mod m. (return s%m)
int rem(int m,char *s)
{
      int r=0;
      for(int i=0;s[i];i++)r=((10*r)+(s[i]-'0'))%m;
      return r;
}

/// -----------------Extended Euclid--------------------
void extended_euclid(long a,long b,long &gcd,long &x,long &y)
{
    if(b==0) {gcd=a; x=1; y=0;}
    else {extended_euclid(b,a%b,gcd,y,x); y-=x*(a/b);}
}

/// Moduler Multiplicative Inverse  package
i64 fac[MAX],inv[MAX],mod=1000000007;

i64 bigmod(i64 b,i64 p,i64 m)
{
    if(p==0) return 1;
    else if(p==1)return b;
    else if(p&1) return  (b*bigmod(b,p-1,m))%m;
    else return bigmod((b*b)%m,p/2,m);
}

void generate_factorial()
{
    fac[0]=1;
    for(int i=1;i<MAX;i++)fac[i]=(fac[i-1]*i)%mod;
}

void generate_invModulus()
{
    inv[MAX-1]=bigmod(fac[MAX-1],mod-2,mod);
    for(int i=MAX-2;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%mod;
}

i64 nCr(int n,int r)
{
    if(!n || !r || n==r)return 1;
    i64 c=(inv[r]*inv[n-r])%mod;
    return (fac[n]*c)%mod;
}

///------------------Geometry---------------------------
struct Point   // Creates normal 2D Point
{
    double x, y;
    Point() {}
    Point( double xx, double yy )
    {
        x = xx, y = yy;
    }
    void init( double xx, double yy )
    {
        x = xx, y = yy;
    }
};
struct line   // Creates a line with equation ax + by + c = 0
{
    double a, b, c;
    line() {}
    line( Point p1,Point p2 )
    {
        a=p1.y-p2.y;
        b=p2.x-p1.x;
        c=p1.x*p2.y-p2.x*p1.y;
    }
    void init( Point p1,Point p2 )
    {
        a=p1.y-p2.y;
        b=p2.x-p1.x;
        c=p1.x*p2.y-p2.x*p1.y;
    }
};
//Distance - Point, Point:
inline double distance( Point a, Point b )
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
//Distance - Point, Line:
inline double distance( Point P, line L )
{
    return fabs( L.a * P.x + L.b * P.y + L.c ) / sqrt( L.a * L.a + L.b * L.b );
}
