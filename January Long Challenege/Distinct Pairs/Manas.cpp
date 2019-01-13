
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef unsigned us;

int main()
{
    us n,m;
    cin>>n>>m;
    ll arr_n[n];
    ll arr_m[m];
    for(us i=0;i<n;i++)
    {
        cin>>arr_n[i];
    }
    for(us i=0;i<m;i++)
    {
        cin>>arr_m[i];
    }
    //cout<<"checkpoint 1"<<endl;
    us index_of_smallesta=min_element(arr_n,arr_n+n)-arr_n;
    //cout<<index_of_smallesta<<endl;
    us index_of_biggestb=max_element(arr_m,arr_m+m)-arr_m;
    //cout<<index_of_biggestb<<endl;

    for(us i=0;i<m;i++)
    {
        cout<<index_of_smallesta<<" "<<i/*arr_n[index_of_smallesta]+arr_m[i]*/<<endl;
    }
    for(us i=0;i<n;i++)
    {
        if(i!=index_of_smallesta)
        {
            cout<<i<<" "<<index_of_biggestb/*arr_m[index_of_biggestb]+arr_n[i]*/<<endl;
        }
    }
    return 0;
}
