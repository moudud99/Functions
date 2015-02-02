#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#define FRO freopen("in.txt","r",stdin)
#define max 10005
#define pb push_back
using namespace std;
int prime_int[max];
bool prime_bool[max];
vector<int>vec;
void prime_num()
{
    int i,j,root=sqrt(max);
    for(i=4; i<max; i+=2)prime_bool[i]=true;
    for(i=3; i<=root; i+=2)if(!prime_bool[i])
        {
            for(j=i*i; j<max; j+=2*i)prime_bool[j]=true;
        }
    prime_int[0]=2;
    for(i=3,j=1; i<max; i+=2)if(!prime_bool[i])prime_int[j++]=i;

}
int phy(int num)
{
    if(num==1)return 0;
    int ph=num,p;
    for(int i=0;i<vec.size();i++)
    {   //p=;
        //ph=(ph/vec[i])*(vec[i]-1);
        ph/=vec[i];
        ph*=(vec[i]-1);
        //p=ph;
    }

    return ph;
}



int main()
{
//FRO;
    int tc,t,i,j,k,num,n,root;

    prime_num();
    while(scanf("%d",&num)!=EOF)
    {
        vec.clear();
        int tmp=num;
        root=sqrt(num)+1;
        for(i=0; i<root; i++)
        {

            if(num%prime_int[i]==0)
            {
                vec.pb(prime_int[i]);

                while(num%prime_int[i]==0)
                {
                    num/=prime_int[i];
                }
                if(num>1)vec.pb(num);
                printf("%d ",vec[i]);
            }
        }
        if(num>1)vec.pb(num);
        printf("%d\n",phy(tmp));
    }

    return 0;
}
