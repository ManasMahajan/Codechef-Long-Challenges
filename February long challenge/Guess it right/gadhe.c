#include <stdio.h>
#define li 1000000007
/*long long int gcd(long long int x,long long int y)
{ if(x>y)
   { if(x%y==0)
      { return y;
      }
     else
       return gcd(x%y,y);
       
   }
  else
   { if(y%x==0)
       return x;
     else
     return gcd(x,y%x);
       
   }
}*/
long long int inverse(long long int x,long long int n)
{ long long int pro=x,expo=1;
  while(n)
    { if(n%2!=0)
        { expo=(expo*pro)%li;
           
        }
      pro=(pro*pro)%li;
      n/=2;
    }
   return expo; 
}
int main() {
    long long int t,n,k,m,i,j,ans,count,numb,multnum,multden,expo,num,den,ans1;
    int p;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
      { scanf("%lld %lld %lld",&n,&k,&m);
       if(m<=100)
        {
        count=1;
     //   long long int num[m],den[m];
      //   p=0;
         numb=n,multnum=1,multden=1;
         ans=0;
        while( count<=m)
          { if(count==m || numb<=k)
              { num=(multnum*1)%li;
                den=(multden*numb)%li;
             //  printf("%lld %lld\n",num,den);
                expo=inverse(den,1000000005);
                ans=(ans+((num%li)*(expo%li))%li)%li;
               // printf("%lld %lld\n",num[p],den[p]);
               
                multnum=((multnum)*(numb-1))%li;
                multden=(multden*numb)%li;
                numb+=k;
                if(count!=m)
                 count--;
              } 
             else
              { if(numb%k==0)
                 { numb=k;
                 }
                else 
                  { numb=numb%k;
                  }
               num=(multnum*1)%li;
               den=(multden*numb)%li;
             //   printf("%lld %lld\n",num,den);
                expo=inverse(den,1000000005);
                ans=(ans+((num%li)*(expo%li))%li)%li;
                //printf("%lld %lld\n",num[p],den[p]);
               
                multnum=((multnum)*(numb-1))%li;
                multden=((multden*numb))%li;
                numb+=k;
                  
              }
            count+=2;  
          }
        }
       else
         { 
          if(m%2==0)
            { if(n>k)
               { if(n%k==0)
                  { numb=k;
                  }
                 else
                   numb=n%k;
                // printf("%lld\n",numb);
                 count=m/2;
                 expo=inverse(numb,count);
                // printf("%lld\n",expo);
                 ans=inverse(expo,1000000005);
                 expo=expo-(inverse(numb-1,count));
               //  printf("%lld\n",expo);
                 if(expo<0)
                  expo=li+expo;
                 ans=(ans*expo)%li;
               
               }
              else
               { numb=n;
                 count=m/2;
                 expo=inverse(numb,count);
                 //printf("%lld\n",expo);
                 ans=inverse(expo,1000000005);
                 ans1=ans;
                // printf("%lld\n",ans);
                 expo=expo-(inverse(numb-1,count));
                 if(expo<0)
                  expo=li+expo;
               //  printf("%lld\n",expo);
                 ans=(ans*expo)%li;
                 ans1=(inverse(numb-1,count)*ans1)%li;
                ans1=(ans1*inverse(numb+k,1000000005))%li;
                ans=(ans+ans1)%li;
                   
               }
            }
          else
            {  if(n>k)
                { if(n%k==0)
                  { numb=k;
                  }
                 else
                   numb=n%k;
                 count=m/2;
                  expo=inverse(numb,count);
                 ans=inverse(expo,1000000005);
                 ans1=ans;
                 expo=expo-(inverse(numb-1,count));
                 if(expo<0)
                  expo=li+expo;
                 ans=(ans*expo)%li;
                 ans1=(inverse(numb-1,count)*ans1)%li;
                ans1=(ans1*inverse(numb+k,1000000005))%li;
                ans=(ans+ans1)%li;
                    
                }
               else
                { numb=n;
                 count=m/2+1;
               //  printf("%lld\n",count);
                 expo=inverse(numb,count);
                 ans=inverse(expo,1000000005);
                 expo=expo-(inverse(numb-1,count));
                 if(expo<0)
                  expo=li+expo;
                 ans=(ans*expo)%li; 
                    
                }
            }
            
            
       } 
        
      if(ans>0)
      printf("%lld\n",ans);
      else
        { ans=li+ans;
          printf("%lld\n",ans);
        }
      
      }
	return 0;
}
