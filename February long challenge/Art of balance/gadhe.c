#include <stdio.h>
#include <math.h>
void mergeself(int l[],int k1[],int low,int high,int mid)
{   int i=low,j=mid+1,k=0;
    int t=high-low+1;
    int a[t];
    int b[t];
    while(i<=mid && j<=high)
     {  if(l[i]<=l[j])
          {a[k]=l[i];
           b[k]=k1[i];
           k++;
           i++;
          }
        else
          { a[k]=l[j];
            b[k]=k1[j];
            k++;
            j++;
          }

    }
    if(i<=mid)
       { while(i<=mid)
           { a[k]=l[i];
             b[k]=k1[i];
             i++;
             k++;
            }
       }
    else if(j<=high)
       { while(j<=high)
           { a[k]=l[j];
             b[k]=k1[j];
              j++;
              k++;
           }

       }
      k=0;
     for(i=low;i<=high;i++)
        { l[i]=a[k];
          k1[i]=b[k];
          k++;
        }

}
void mergesort(int l[],int k1[],int low,int high)
{ if(low<high)
    { int mid=(low+high)/2;
      mergesort(l,k1,low,mid);
      mergesort(l,k1,mid+1,high);
      mergeself(l,k1,low,high,mid);
    }
}
int main() { int t,n,m,i,j,count,k,p,x,ans,count1,count2;
    scanf("%d",&t);
    char str[1000001];
    for(i=0;i<t;i++)
      { //scanf("%d",&n);
        scanf("%s",str);
        count=0;
        int l[26]={0},s[26],t1[26];
        for(j=0;str[j]!='\0';j++)
          {   l[str[j]-65]++; 
              count++;
          }
         ans=1000000;
        for(j=1;j<=26 && j<=count;j++)
          { if(count%j==0 && j<=count)
              { x=count/j;
                for(k=0;k<26;k++)
                  { p=fabs(l[k]-x);
                    t1[k]=l[k]-x;
                    s[k]=p;    
                  }
                mergesort(s,t1,0,25);
              //  for(k=0;k<26;k++)
            //     printf("%d ",s[k]);
              //   printf("\n");
             //   for(k=0;k<26;k++)
             //     printf("%d ",t1[k]);
             //     printf("\n");
             count1=0;
             for(k=0;k<26;k++)
               { if(t1[k]>=0)
                   count1++;  
               }
                count2=0;
                p=0;
                for(k=0;k<26 && p<j-count1;k++)
                 { if(t1[k]<0)
                    {count2+=fabs(t1[k]);
                      p++;
                    
                    }
                 }
              //  printf("%d %d\n",j,count2);
                if(count2<ans)
                 {ans=count2;
               
                 }
              }  
              
          }
        printf("%d\n",ans);
      } 
	return 0;
}
