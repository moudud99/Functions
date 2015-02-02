#include<stdio.h>
#include<string.h>
#include<math.h>
#define FRO freopen("in.txt","r",stdin);
//function sieve begin:

#define Max 20000000
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

//function sieve end
int main()
{
  //  FRO
    int tc,t,i,c=0,a,b;
    printf("Give a number of input\n");
    scanf("%d",&tc);
     prime_num();
    for(t=0;t<tc;t++)
    {
        printf("Give 2 number of prime num limit\n");

        scanf("%d%d",&a,&b);
        for(i=a;i<=b;i++){
           printf("%d ",prime_int[i]);
        }
        printf("\n");
    }
return 0;
}
