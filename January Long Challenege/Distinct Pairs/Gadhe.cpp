#include <stdio.h>
int a[200000];
int a1[200000];
void mergeself(int l[],int low,int high,int mid,int d[])
{   int i=low,j=mid+1,k=0;
  
    while(i<=mid && j<=high)
     {  if(l[i]<=l[j])
          {a[k]=l[i];
           a1[k]=d[i];
           k++;
           i++;
          }
        else
          { a[k]=l[j];
            a1[k]=d[j];
            k++;
            j++;
          }

    }
    if(i<=mid)
       { while(i<=mid)
           { a[k]=l[i];
             a1[k]=d[i];
             i++;
             k++;
            }
       }
    else if(j<=high)
       { while(j<=high)
           { a[k]=l[j];
             a1[k]=d[j];
              j++;
              k++;
           }

       }
      k=0;
     for(i=low;i<=high;i++)
        { l[i]=a[k];
          d[i]=a1[k];
          k++;
        }

}
void mergesort(int l[],int low,int high,int d[])
{ if(low<high)
    { int mid=(low+high)/2;
      mergesort(l,low,mid,d);
      mergesort(l,mid+1,high,d);
      mergeself(l,low,high,mid,d);
    }
}
int main()
{int n,m,i,j;
 scanf("%d %d",&n,&m);
 int b[n],c[m],d[n],e[m];
 for(i=0;i<n;i++)
   {scanf("%d",&b[i]);
    d[i]=i;
   }
 for(i=0;i<m;i++)
    {scanf("%d",&c[i]);
     e[i]=i;
    }
 mergesort(b,0,n-1,d);
 mergesort(c,0,m-1,e);
 for(i=0;i<m;i++)
  {printf("%d %d\n",d[0],e[i]);
  }
 for(j=1;j<n;j++)
  { printf("%d %d\n",d[j],e[m-1]);
  }
 return 0;
}
