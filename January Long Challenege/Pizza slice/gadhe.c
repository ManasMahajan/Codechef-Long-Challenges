/* please visit the photo before understanding the code

*/

#include <stdio.h>
long long int gcd(long long int x,long long int y)
{ if(x>=y)
    { if(x%y==0)
       return y;
      else
       return gcd(x%y,y);
    }  
  else
    { if(y%x==0)
        return x;
      else 
      return gcd(x,y%x);
    }
}
int main()
{int i,T,t;
 long long int n,x,y,z,num,denom,fac;
 scanf("%d",&T);
 for(i=0;i<T;i++)
   { scanf("%lld %d %lld %lld %lld",&n,&t,&x,&y,&z);
     denom=2*n+1;
     if(t==1)  
      {if(y<x && z>y)
         { num=(y+1);
         } 
       else if(y<x && z<y) 
         {  num=2*n+2-y;
         }
       else if(y>x && z>y)  
         { num=2*n-y;
         }
       else if(y>x && z<y)
         { num=y-1;
         }
      }
     else if(t==2)
      { num=(2*n)+1-(2*y);
      }
     else if(t==3)
      { if(y<x && z>y)
         { num=(y+1);
         } 
        else if(y<x && z<y)  
         { num=2*n-y;
         }
        else if(y>x && z>y)  
         {  num=2*n+2-y;
         }
        else if(y>x && z<y)
         {  num=y-1;
         }  
      }
     else if(t==4)
      { num=(2*n)+1-(2*y);
      }
     fac=gcd(num,denom);
     num=num/fac;
     denom=denom/fac;
     printf("%lld %lld\n",num,denom);
       
   }
  return 0;  
}

