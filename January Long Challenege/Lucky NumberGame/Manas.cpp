#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned us;
typedef vector<ull> vull;

void find_mul(ull* arr, us n, us a, us b,us &num_a, us &num_b, us &num_ab)
{
    for(us i=0;i<n;i++)
    {
        if(!(arr[i]%a))
        {
            if(!(arr[i]%b))
            {
                num_ab++;
            }
            else
            {
                num_a++;
            }
        }
        else
        {
            if(!(arr[i]%b))
            {
                num_b++;
            }
        }
    }
}

int main()
{
    us t;
    cin>>t;
    us n,a,b,num_a,num_b,num_ab;
    for(int i=0;i<t;i++)
    {
        num_a=0;
        num_b=0;
        num_ab=0;
        cin>>n>>a>>b;
        ull arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        //cout<<"Checkpoint 1"<<endl;
        find_mul(arr,n,a,b,num_a,num_b,num_ab);
        //cout<<num_a<<" "<<num_b<<" "<<num_ab<<endl;

        //cout<<"Checkpoint 2"<<endl;
        //1
        if((num_a==0)&&(num_ab==0))
        {
            //cout<<"Inside 1"<<endl;
            cout<<"AILCE"<<endl;
            continue;
        }

        //2
        if((num_a==0)&&(num_b==0)&&(num_ab!=0))
        {
            //cout<<"Inside 2"<<endl;
            cout<<"BOB"<<endl;
        }

        //3
        if((num_ab==0)&&(num_b==0)&&(num_a!=0))
        {
            //cout<<"Iside 3"<<endl;
            cout<<"BOB"<<endl;
            continue;
        }

        //4
        if((num_ab==0)&&(num_a!=0)&&(num_b!=0))
        {
            //cout<<"Inside 4"<<endl;
            if(num_a>num_b)
            {
                cout<<"BOB"<<endl;
            }
            else
            {
                cout<<"ALICE"<<endl;
            }
            continue;
        }

        //5
        if((num_a==0)&&(num_b!=0)&&(num_ab!=0))
        {
            //cout<<"Inside 5"<<endl;
            cout<<"ALICE"<<endl;
            continue;
        }

        //6
        if((num_b==0)&&(num_a!=0)&&(num_ab!=0))
        {
            //cout<<"Inside 6"<<endl;
            cout<<"BOB"<<endl;
            continue;
        }

        //7
        if((num_a!=0)&&(num_b!=0)&&(num_ab!=0))
        {
            //cout<<"Inside 7"<<endl;
            if(num_b>num_a)
            {
                cout<<"ALICE"<<endl;
            }
            else
            {
                cout<<"BOB"<<endl;
            }
            continue;
        }
        //cout<<"Didn't enter any if"<<endl;
    }
    return 0;
}

