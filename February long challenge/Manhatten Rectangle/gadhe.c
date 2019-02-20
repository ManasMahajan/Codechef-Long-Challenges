#include <stdio.h>

int main() {int t,i,j,k;
            long long int t1,t2,t3,t4,t5,x,ans1,ans2,ans3,ans4;
    scanf("%d",&t);
    for(i=0;i<t;i++)
      { printf("Q 0 0\n");
        fflush(stdout);
        scanf("%lld",&t1);
        printf("Q 1000000000 0\n");
         fflush(stdout);
         scanf("%lld",&t2);
        printf("Q 1000000000 1000000000\n");
         fflush(stdout);
         scanf("%lld",&t3);
        printf("Q 0 1000000000\n"); 
          fflush(stdout);
          scanf("%lld",&t4);
        x=1000000000+t1-t2;
        x/=2;
        printf("Q %lld 0\n",x); 
          fflush(stdout);
        scanf("%lld",&t5);
        ans2=t5;
        ans1=t1-ans2;
        ans3=1000000000-t2+ans2;
        ans4=1000000000+ans1-t4;
        printf("A %lld %lld %lld %lld\n",ans1,ans2,ans3,ans4);
        fflush(stdout);
        scanf("%lld",&x);
        
      }
	return 0;
}
