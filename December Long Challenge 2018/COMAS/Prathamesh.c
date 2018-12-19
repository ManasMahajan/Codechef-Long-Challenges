/*
Approach 
if we are given 6 meatballs then we can find meatiest meatball in 5 qustions(worst case).So i broke the entire problem so that in end 
only 6 meatballs remains.then i find meatiest of these 6 meatballs.
here findthemeatiest function calculates meatiest meatball among 6 meatballs 
*/
#include<stdio.h>
void findthemeatiest(int ans[])
{  int x,y,z,i,j,flag,x1,y1,l[2],m;
   int a[6],b[6]; 
   printf("? %d %d %d %d %d\n",ans[0],ans[1],ans[2],ans[3],ans[4]);
   fflush(stdout);
   scanf("%d %d",&x,&y);    
   a[0]=x;
   a[1]=y;
   j=0;
   for(i=0;i<5;i++)
     { if(ans[i]!=x && ans[i]!=y)
         {b[j]=ans[i];
            j++; 
         }
     }
   printf("? %d %d %d %d %d\n",b[0],b[1],b[2],y,ans[5]);
   fflush(stdout);
   scanf("%d %d",&x,&y);
   if(x==ans[5] || y==ans[5])
      {  if(x==ans[5])
           {  
             a[2]=a[1];
             a[1]=x;
             
           }
          else if(y==ans[5])
            { a[2]=ans[5];
            }
       printf("? %d %d %d %d %d\n",b[1],b[2],a[0],a[1],a[2]);
       fflush(stdout);
       scanf("%d %d",&x,&y);
       flag=0;
       if(y!=a[2])
          { flag=1;
            printf("! %d\n",b[0]); 
            fflush(stdout);
          }
       else
          { printf("? %d %d %d %d %d\n",b[0],b[2],a[0],a[1],a[2]);
            fflush(stdout);
            scanf("%d %d",&x,&y);
             if(y!=a[2])
              { flag=1;
                printf("! %d\n",b[1]);
                fflush(stdout);
              }  
             else 
               {printf("! %d\n",b[2]);
                 fflush(stdout);
               }
          }
          
          
      } 
     else 
       {  if(x==a[1])
            { //printf("%d %d\n",x,a[1]);
              printf("! %d\n",ans[5]);
              fflush(stdout);
            }
          else 
            {
              m=0;
              for(i=0;i<3;i++)
                { if(b[i]!=x)
                    { l[m]=b[i];
                        m++;  
                    }
                }
               a[2]=a[1];
               a[1]=x;
              flag=0;
              printf("? %d %d %d %d %d\n",l[0],a[0],a[1],a[2],ans[5]);
              fflush(stdout);
              scanf("%d %d",&x,&y);
              //printf("%d %d\n",a[1],a[2]);
              if(y==a[2])
                {  flag=1;
                   printf("! %d\n",l[0]);
                   fflush(stdout);
                }
              else
                {   printf("! %d\n",l[1]); 
                    fflush(stdout);
                }
               
            }
           
        }
}
    



int main()
{   int n,t,i,j,x,k,p,y,x1;
    scanf("%d",&t);
    for(i=0;i<t;i++)
       { scanf("%d",&n);
         int ans[6],b[5],c[5];
          if(n==6)
            { for(j=0;j<6;j++)
                ans[j]=j+1; 
            }
          printf("? 1 2 3 4 5\n");
          fflush(stdout);
          scanf("%d %d",&x,&y);
          c[0]=x,c[1]=y;
          k=0;
          for(j=1;j<=5;j++)
            { if(j!=x && j!=y)
                 { b[k]=j;
                   k++;
                 }
            }
          k=n-5,p=6;
           while(k>0)
             {  if(k==1)
                  {  for(x1=0;x1<=2;x1++)
                        ans[x1]=b[x1];   
                      ans[x1]=c[0];
                      ans[x1+1]=c[1];
                      ans[x1+2]=p;
                      k-=1;
                      p++;
                  }
               else if(k==2)
                  { /*printf("%d %d %d %d %d\n",b[0],b[1],b[2],p,p+1);
                    fflush(stdout);*/
                    for(x=0;x<=2;x++)
                        ans[x]=b[x]; 
                    ans[3]=p;
                    ans[4]=p+1;
                    ans[5]=c[1];
                     p+=2;
                     k-=2;
                 }
               else
                 {  printf("? %d %d %d %d %d\n",b[0],b[1],b[2],p,p+1);
                    fflush(stdout);
                    scanf("%d %d",&x,&y);
                   // printf("%d %d\n",x,y);
                    x1=0;
                    if(b[0]!=x && b[0]!=y)
                      { b[x1]=b[0];
                         x1++;  
                      }
                    if(b[1]!=x && b[1]!=y)
                      { b[x1]=b[1];
                         x1++;  
                      }
                    if(b[2]!=x && b[2]!=y)
                      { b[x1]=b[2];
                         x1++;  
                      }
                    if(x1!=3)
                      {  if(p!=x && p!=y)
                           {  b[x1]=p;
                              x1++;
                           }
                         if(x1!=3)
                           { b[x1]=p+1;
                              x1++; 
                           }
                      }
                   // printf("%d %d %d\n",b[0],b[1],b[2]);
                    p+=2;  
                    k-=2;
                 }
             }
             
           findthemeatiest(ans);
       }
    return 0;
}
        

