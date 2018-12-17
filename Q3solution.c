/*
approach=Here we first check at 1000,then 2000, upto n or until it breaks.Then we repair it.Just consider it breaks at 4000
then we know answer exists from 3001 to 4000,then we check at 3500 .If it breaks then we first repair it,and we know that answer exists from 3100 
to 31500,we check it one by one.If it doen not break at 3500 then we know that it answer exists from 3501 to 4000,we check it one by one.
*/
#include <iostream>
using namespace std;
int main() {
    int n,c,flag,isbroken,i;
    cin>>n>>c;
    flag=0;
    int low,high,mid;
    
    
    if(n<=1000)
       {   i=1;
           while(flag==0)
            { cout<<"1 "<<i;
              fflush(stdout); 
              cout<<"\n";
              cin>>isbroken;
              if(isbroken==1)
                {flag=1;
                 mid=i-1;
                }
               i++; 
            }
           
           
       }
      else
       {  low=0,high=1000; 
          while(flag==0)
            { cout<<"1 "<<high;
              fflush(stdout); 
              cout<<"\n"; 
              cin>>isbroken;
              if(isbroken==1)
                {  cout<<"2";
                   fflush(stdout);
                   cout<<"\n";
                   mid=(low+high)/2;
                  // printf("f%d %d %d\n",low,high,mid);
                   cout<<"1 "<<mid;
                   fflush(stdout);
                   cout<<"\n";
                   cin>>isbroken;
                  if(isbroken==1)
                    {  cout<<"2";
                       fflush(stdout);
                       cout<<"\n";
                      i=low+1;
                      while(i<=mid && flag==0)
                         { cout<<"1 "<<i;
                           fflush(stdout);
                           cout<<"\n";
                           cin>>isbroken;
                           if(isbroken==1)
                             { flag=1;
                               mid=i-1;                                 
                             }
                           i++;
                           
                         }
                        
                    }
                  else
                    { i=mid+1;
                       while(i<=high && flag==0)
                         { cout<<"1 "<<i;
                           fflush(stdout);
                           cout<<"\n";
                           cin>>isbroken;
                           if(isbroken==1)
                             { flag=1;
                               mid=i-1;                                 
                             }
                           i++;
                           
                         }
                        
                        
                        
                        
                    }
                  
                }
              else
                { low=high;
                  high+=1000;
                  if(high>n)
                   high=n;
                }
            }
           
           
           
           
       }
    
    
    
      cout<<"3 "<<mid+1;
      fflush(stdout);
    return 0;
}
