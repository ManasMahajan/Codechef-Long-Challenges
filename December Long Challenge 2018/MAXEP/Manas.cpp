#include<iostream>

using namespace std;

int rec_panel(int low, int high)
{
    static int t=0;
    bool response;
    int mid;
    if(t<4)
    {
        mid=(int)(low+high)/2;
        cout<<"1 "<<mid<<endl;
        cin>>response;
        if(response)
        {
            cout<<"2"<<endl;
            t++;
            if((mid==high)&&(mid==low))
            return mid;
            high=mid;
            rec_panel(low,high);
        }
        else
        {
            low=mid+1;
            rec_panel(low,high);
        }
    }
    else
    {
        mid=low;
        cout<<"1 "<<mid<<endl;
        cin>>response;
        if(response)
        {
            return mid;
        }
        else
        {
            mid++;
            rec_panel(mid,high);
        }
    }
}

int rec_paneltrial(int low, int high)
{
    static int t=0;
    bool response;
    int mid;
    if(t<19)
    {
        mid=(int)(low+high)/2;
        cout<<"1 "<<mid<<endl;
        cin>>response;
        if(response)
        {
            cout<<"2"<<endl;
            t++;
            if((mid==high)&&(mid==low))
            return mid;
            high=mid;
            rec_paneltrial(low,high);
        }
        else
        {
            low=mid+1;
            rec_paneltrial(low,high);
        }
    }
    else
    {
        mid=low;
        cout<<"1 "<<mid<<endl;
        cin>>response;
        if(response)
        {
            return mid;
        }
        else
        {
            mid++;
            rec_panel(mid,high);
        }
    }
}

/*int rec_paneltwo(int low , int high)
{
    bool response;
    int mid;
    mid=(int)(low + high) / 2;
    cout<<"1 "<<mid<<endl;
    cin>>response;
    if(response)
    {
        cout<<"2"<<endl;
        if((mid==high)&&(mid==low))
        {
            return mid;
        }
        rec_paneltwo(low,mid);
    }
    else
    {
        rec_paneltwo(mid+1,high);
    }
}*/

int rec_panelthree(int low , int high , int n)
{
    bool response;
    if(high>n)
    {
        high=n;
    }
    cout<<"1 "<<high<<endl;
    cin>>response;
    if(response)
    {
        cout<<"2"<<endl;
        return rec_panel(low , high);
    }
    low=low + 1000;
    high=high + 1000;
    rec_panelthree(low, high, n);
}


int main()
{
    int n,c;
    cin>>n>>c;
    if((n<1)||(n>150,000)||(c>150)||(c<1))
    return 0;
    int x;
    if(c<=50)
    {
        x=rec_paneltrial(1,n);
        cout<<"3 "<<x<<endl;
        return 0;
    }
    if(n<=1000)
    {
        x=rec_panel(1,n);
        cout<<"3 "<<x<<endl;
        return 0;
    }
    x=rec_panelthree(1 , 1000 , n);
    cout<<"3 "<<x<<endl;
    return 0;
}

