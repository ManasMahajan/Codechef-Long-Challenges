/*
This solution was partially accepted(10 pts). But i thought approach was worth sharing.
I used kadane's algorithm to find maximum subsequence sum

*/
#include<stdio.h>
int main()
{ int q,k,b,c,d,i,j,c1,ans,x=0,y,maxsum,sum,flag;
  scanf("%d %d",&q,&k);
  ans=0;
  int colour[200000];
  int deli[200000];
  int eable[200000];
  for(i=0;i<q;i++)
    { scanf("%d %d",&b,&c);
      if(b==1 || b==2)
       { scanf("%d",&d);
         c1=c^ans;
        // printf("ho %d\n",c1);
         if(b==2)
         {
          colour[x]=c1;
          deli[x]=d;
          x++;
         }
         else if(b==1)
         { y=x;
           while(y>=1)
            {  colour[y]=colour[y-1];
               deli[y]=deli[y-1];
                y--;
            }
           colour[y]=c1;
           deli[y]=d;
           x++;
         }
       }
      else 
        { 
         c1=ans^c;
        // printf("%d\n",c1);
         // printf("ho %d\n",c1);
          y=0;
          for(j=0;j<x;j++)
            { if(colour[j]>=c1-k && colour[j]<=c1+k)
                { eable[y]=deli[j];
                  /*if(eable[y]>=0)
                    { flag=1;
                    }*/
                  y++;    
                }
            }
           //printf("%d\n",y);
          sum=0,maxsum=-1000,j=0;
          if(y==0)
          maxsum=0;
          while(j<y)
            { sum+=eable[j];
              if(sum>maxsum)
               maxsum=sum;
              if(sum<0)
               sum=0;
               j++;
            }
           ans=maxsum;
           if(ans<0)
           ans=0;
           printf("%d\n",ans);
            
        }
      
       //printf("%d\n",x); 
         
    }
    
    
}
