#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;
int gcd(int a,int b)
{
   if(b==0)return a;
   return gcd(b,a%b);
}

int main()
{
	int a,b,c,i,j,k,tc,t;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {printf("%d\n",gcd(n,m));}

return 0;
}
