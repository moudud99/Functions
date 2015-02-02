#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#define FRO freopen("in.txt","r",stdin)
int rev_int(int num)
{
    int count=0,tem;
    if(num==0)return 0;
    while(num>0)
    {
        if(count!=0){tem=tem*10;tem+=num%10;num/=10;count++;}
        else
        {tem=num%10;num/=10;count++;}

    }
    return tem;
}

int main()///http://ideone.com/zbjdXW
{
//FRO;
	int tc,t,i,j,k;
	int num,tem=0,count;
	while(scanf("%d",&num)!=EOF)printf("%d\n",rev_int(num));
return 0;
}
