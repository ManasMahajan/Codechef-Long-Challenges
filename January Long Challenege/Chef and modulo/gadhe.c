/*
longest possible value=n/2(if no is odd)
                       =n/2(if no is even)
No of solutions can be found using permutations and combinations

PS- In constraint it is given p>=n however i didn't read them and i also had conditions like If p<=n. 
                 
*/
#include<stdio.h>
int main()
{  long long int t,n,p,i,j,k,max,count;
   long long int n1,n2,ans;
   scanf("%lld",&t);
   for(i=0;i<t;i++)
    { scanf("%lld %lld",&n,&p);
       if(((n/2)+1)<=p)
        { k=(n%((n/2)+1));
          if(p<=n)
          {n1=p-k;
           ans=n1+(2*(n1*(n1-1))/2);
          }
          else 
          { n1=n-k;
            n2=p-n;
            ans=n1+(2*(n1*(n1-1))/2);
            ans=ans+(3*n2);
            ans=ans+(6*((n2*(n2-1))/2));
            ans=ans+(3*n1*n2);
          }
         if(k==0)
         ans=p*p*p;
        //  printf("%d ",k);
        }
      else 
        { max=n%p;
          k=p-1;
          while(k>=1 && max<k)
            { if((n%k)>max)
               max=n%k;
             // printf("%d\n",(n%k));
               k--; 
            }
          count=0;
           k=p;
           while(k>=1 && max<k)
             {   if(n%k==max)
                  count++;
                 k--;
             }
           n1=p-max;
           ans=n1+(2*((n1*(n1-1))/2));
           ans=ans*count;
           if(max==0)
           ans=p*p*p;
          //printf("%d ",max);
        }
       printf("%lld\n",ans);
    }
   return 0;
}
