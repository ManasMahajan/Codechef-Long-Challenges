/*highest no required is 4
  however can be  be 1,2 or 3  when n<=3 or m<=3
  I wrote backtracking algorithm for matrix of 50 columns and 50 rows
*/


#include <stdio.h>
#include<stdlib.h>
int issafe(int **a,int i,int j,int k,int n,int m)
{  if(j-2>=0 && a[i][j-2]==k)
      return -1;
   if(i-1>=0 && j-1>=0 && a[i-1][j-1]==k)
      return -1;
   if(i-1>=0 && j+1<m && a[i-1][j+1]==k)
      return -1;
   if(i-2>=0 && a[i-2][j]==k)
      return -1;
   
    return 1; 
}
int solve_puzzle(int n,int m,int **a,int r)
{  int i,j,k,temp,flag=0,i1,j1;
   for(i=0;i<n && flag==0;i++)
      { for(j=0;j<m && flag==0;j++)
          { if(a[i][j]==0)
              { flag=1;
                i1=i;
                j1=j;
              }
              
          }
      }
    for(k=1;k<=r;k++)
      { if(issafe(a,i1,j1,k,n,m)==1)
          { a[i1][j1]=k;
            if(i1==n-1 && j1==m-1)
              return 1;
            else if(solve_puzzle(n,m,a,r)==1)  
             {return 1;
             }
            else
             { a[i1][j1]=0;
             }
          }
      }
    return -1;
    
}
int main() {
    int t,n,m,i,j,k,max,l,l1,count;
    scanf("%d",&t);
    int **b=(int**)calloc(50,sizeof(int*));
        for(j=0;j<50;j++)
          b[j]=(int*)calloc(50,sizeof(int));
        l1=solve_puzzle(50,50,b,4);
    for(i=0;i<t;i++)
      { scanf("%d %d",&n,&m);
        int **a=(int**)calloc(n,sizeof(int*));
        for(j=0;j<n;j++)
          a[j]=(int*)calloc(m,sizeof(int));

        if(n>=3 && m>=3)
          {
           printf("4\n");
           for(j=0;j<n;j++)
             { for(k=0;k<m;k++)
                printf("%d ",b[j][k]);
                printf("\n");
             }
          }
        /*
        else 
          { for(k=1;k<=3;k++)
              { l=solve_puzzle(n,m,a,k);
                if(l==1) 
                 break;
              }
             max=0;
             for(j=0;j<n;j++)
               { for(k=0;k<m;k++)
                   { if(a[j][k]>max)
                       max=a[j][k];
                   }
               }
             printf("%d\n",max); 
              for(j=0;j<n;j++)
               { for(k=0;k<m;k++)
                 printf("%d ",a[j][k]);
                 printf("\n");
               } 
          }*/
         
          else if(n==1 && m==1)
            { printf("1\n1\n");
            }   
          else if(n==2 && m==2)
            { printf("2\n1 1\n2 2\n");
            }
          else if(n==1 && m>1)
            { count=0;
              if(m==2)
               printf("1\n");
              else 
               printf("2\n");
              while(count<m)
                { printf("1 ");
                  count+=1;
                  if(count<m)
                  printf("1 ");
                  count+=1;
                  if(count<m)
                  printf("2 ");
                  count+=1;
                  if(count<m)
                  printf("2 ");
                  count+=1;

                }
              printf("\n");
            }
            else if(n>1 && m==1)
              {  count=0;
              if(n==2)
               printf("1\n");
              else 
               printf("2\n");
              while(count<n)
                { printf("1\n");
                  count+=1;
                  if(count<n)
                  printf("1\n");
                  count+=1;
                  if(count<n)
                  printf("2\n");
                  count+=1;
                  if(count<n)
                  printf("2\n");
                  count+=1;

                }


              }
             else if(n==2 && m>2)
              { printf("3\n");
                count=0;
                while(count<m)
                 { printf("1 ");
                   count+=1;
                   if(count<m)
                   printf("1 ");
                   count+=1;
                   if(count<m)
                   printf("2 ");
                   count+=1;
                   if(count<m)
                   printf("2 ");
                   count+=1;
                   if(count<m)
                   printf("3 ");
                   count+=1;
                   if(count<m)
                   printf("3 ");
                   count+=1;

                 }
                printf("\n");
                printf("2 3 3 ");
                count=3;
                 while(count<m)
                 { printf("1 ");
                   count+=1;
                   if(count<m)
                   printf("1 ");
                   count+=1;
                   if(count<m)
                   printf("2 ");
                   count+=1;
                   if(count<m)
                   printf("2 ");
                   count+=1;
                   if(count<m)
                   printf("3 ");
                   count+=1;
                   if(count<m)
                   printf("3 ");
                   count+=1;
                 }
                 printf("\n");
              }
            else if(n>2 && m==2)
              { printf("3\n");
                count=0;
                while(count<n)
                 { printf("1 1\n");
                   count+=1;
                   if(count<n)
                   printf("2 2\n");
                   count+=1;
                   if(count<n)
                   printf("3 3\n");
                   count+=1;
                 }
              }
            
         
      }
    return 0;
}

