#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<vector>
#define Max 1000000
using namespace std;
#define FRO freopen("in.txt","r",stdin);

int prime_int[Max];
bool prime_bool[Max];

void prime_num()
{
    int i,j,root=sqrt(Max);
    for(i=4;i<=Max;i+=2)prime_bool[i]=true;
    for(i=3;i<=root;i+=2)if(!prime_bool[i])
    {
        for(j=i*i;j<=Max;j+=2*i)prime_bool[j]=true;
    }
    prime_int[0]=2;
    for(i=3,j=1;i<Max;i+=2)if(!prime_bool[i])prime_int[j++]=i;
}

vector<int> div(int num)
{
    vector<int>divisor;
    int i,root=sqrt(num),pr;
    for(i=1;i<=root;i++)
    {
        if(num%i==0&& num/i!=num)
        {
            pr=i;
            divisor.push_back(pr);
            if(num/i!=i)divisor.push_back(num/i);
        }
    }
    return divisor;
}

int main()
{
    //FRO
	int b,c,i,j,k,tc,t,n,size;
    prime_num();

	while(scanf("%d",&n)!=EOF)
	{
        vector<int> divisor=div(n);
        size=divisor.size();
        printf("Divisor(s) of %d:\n",n);
        for(i=0;i<size;i++)printf("%d ",divisor[i]);
        printf("\nGive another number:");
	}
return 0;
}
