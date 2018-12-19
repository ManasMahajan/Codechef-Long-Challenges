/*
Approach: here ^ represents xor gate
suppose we have 4 nos
 then let
 x1=a1^a2^a3
 x2=a2^a3^a4
 x3=a3^a4^a1
 x4=a4^a1^a2
 as we can see ,a3=x1^x2^x3
                a2=x1^x2^x4,using these we can find all 4 terms
 
Suppose we have 5 terms
 then let
 x1=a1^a2^a3
 x2=a2^a3^a4
 x3=a3^a4^a5
 x4=a4^a5^a1
 x5=a5^a1^a2
 as we can see  x1^x2^x3^x4^x5=a1^a2^a3^a4^a5=X(say)
                X^x2^x5=a2
                X^x3^x1=a3
                
 In similar fashion we can solve it we have 7 terms.
 
 Now we can can break any no of terms in  combination of multiple 4terms ,5 terms and 7 terms.
 for example=if we have 9 terms we can do for first 4 terms and then remaining 5 terms
             if we have 10 terms we can do first 5 terms and next 5 terms
             if we 11 terms,we can solve for first 4 then remaining 7 terms
             for 17,first four,next four,then next four,then remaining five
             

*/
#include <stdio.h>
int main() {
    int t,n,i,j,k,p,a1,a2,a3,a4,a5,a6,a7,flag;
    scanf("%d",&t);
    for(i=0;i<t;i++)
      {  scanf("%d",&n);
         int b[n],ans[7];
         p=0;
         k=n;
         flag=0;
         while(k>=4)
           { if(k==5 || k==10)
              { //cout<<"this loop runs1";
                a1=4*p+1;
                if(flag==1)
                 a1++;
                a2=a1+1;
                a3=a2+1;
                a4=a3+1;
                a5=a4+1;
                printf("1 %d %d %d\n",a1,a2,a3);
                fflush(stdout);
                scanf("%d",&ans[0]);
                printf("1 %d %d %d\n",a2,a3,a4);
                fflush(stdout);
                scanf("%d",&ans[1]);
                printf("1 %d %d %d\n",a3,a4,a5);
                fflush(stdout);
                scanf("%d",&ans[2]);
                printf("1 %d %d %d\n",a4,a5,a1);
                fflush(stdout);
                scanf("%d",&ans[3]);
                printf("1 %d %d %d\n",a5,a1,a2);
                fflush(stdout);
                scanf("%d",&ans[4]);
                b[a5-1]=ans[0]^ans[1]^ans[3];
                b[a2-1]=b[a5-1]^ans[1]^ans[2];
                b[a3-1]=b[a5-1]^ans[0]^ans[4];
                b[a1-1]=ans[0]^b[a2-1]^b[a3-1];
                b[a4-1]=ans[1]^b[a2-1]^b[a3-1];
                flag=1;
                k-=5;  
              }
              else if(k==7)
               {//cout<<"this loop runs2";
                a1=4*p+1;
                a2=a1+1;
                a3=a2+1;
                a4=a3+1;
                a5=a4+1;
                a6=a5+1;
                a7=a6+1;
                printf("1 %d %d %d\n",a1,a2,a3);
                fflush(stdout);
                scanf("%d",&ans[0]);
                printf("1 %d %d %d\n",a2,a3,a4);
                fflush(stdout);
                scanf("%d",&ans[1]);
                printf("1 %d %d %d\n",a3,a4,a5);
                fflush(stdout);
                scanf("%d",&ans[2]);
                printf("1 %d %d %d\n",a4,a5,a6);
                fflush(stdout);
                scanf("%d",&ans[3]);
                printf("1 %d %d %d\n",a5,a6,a7);
                fflush(stdout);
                scanf("%d",&ans[4]);
                printf("1 %d %d %d\n",a6,a7,a1);
                fflush(stdout);
                scanf("%d",&ans[5]);
                printf("1 %d %d %d\n",a7,a1,a2);
                fflush(stdout);
                scanf("%d",&ans[6]);
                b[a2-1]=(ans[0]^ans[1]^ans[2])^(ans[2]^ans[3]^ans[4])^ans[6];
                b[a3-1]=(ans[1]^ans[2]^ans[3])^(ans[3]^ans[4]^ans[5])^ans[0];
                b[a1-1]=b[a2-1]^b[a3-1]^ans[0];
                b[a4-1]=b[a2-1]^b[a3-1]^ans[1];
                b[a5-1]=b[a3-1]^b[a4-1]^ans[2];
                b[a6-1]=b[a4-1]^b[a5-1]^ans[3];
                b[a7-1]=b[a5-1]^b[a6-1]^ans[4];
                 k-=7;
               }
             else if(k>=4)
              {// cout<<"this loop runs3";
                a1=4*p+1;
                a2=a1+1;
                a3=a2+1;
                a4=a3+1;  
                printf("1 %d %d %d\n",a1,a2,a3);
                fflush(stdout);
                scanf("%d",&ans[0]);
                printf("1 %d %d %d\n",a2,a3,a4);
                fflush(stdout);
                scanf("%d",&ans[1]);
                printf("1 %d %d %d\n",a3,a4,a1);
                fflush(stdout);
                scanf("%d",&ans[2]);
                printf("1 %d %d %d\n",a4,a1,a2);
                fflush(stdout);
                scanf("%d",&ans[3]);
                b[a3-1]=ans[0]^ans[1]^ans[2];
                b[a2-1]=ans[2]^ans[3]^b[a3-1];
                b[a1-1]=b[a2-1]^b[a3-1]^ans[0];
                b[a4-1]=b[a2-1]^b[a3-1]^ans[1];
                k-=4;
               // cout<<"2 "<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<" ";
                //fflush(stdout);
              }
                p++; 
           }
          printf("2 ");
          fflush(stdout);
         for(k=0;k<n;k++)
          { printf("%d ",b[k]);
            fflush(stdout);
          }
          scanf("%d",&k);
          
      }
	return 0;
}

