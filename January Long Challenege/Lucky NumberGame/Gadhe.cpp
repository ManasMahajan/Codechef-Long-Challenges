
#include <stdio.h>

int main() {
    int t,n,a,b,i,j;
    scanf("%d",&t);
    int a1[200000];
    for(i=0;i<t;i++)
      { int x=0,y=0,z=0;
        scanf("%d %d %d",&n,&a,&b);
        for(j=0;j<n;j++)
          { scanf("%d",&a1[j]);
             if(a1[j]%a==0 && a1[j]%b!=0)
              { x++;
              }
             else if(a1[j]%b==0 && a1[j]%a!=0)
               y++;
             else if(a1[j]%b==0 && a1[j]%a==0) 
               z++;
               
          }
         if(z==0)
           { if(x>y)
               printf("BOB\n");
             else
               printf("ALICE\n");
           }
         else
           {if(x>=y)
               printf("BOB\n");
             else
               printf("ALICE\n");
               
           }
         
      }
	//code
	return 0;
}
