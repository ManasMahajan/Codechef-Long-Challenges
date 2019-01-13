#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool is_fancy(string input_string)
{
    stringstream sstr(input_string);
    string word;
    while(sstr>>word)
    {
        if(word=="not")
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    string input_line;
    cin.ignore(1,'/n');
    for(int i=0;i<t;i++)
    {
        getline(cin,input_line);
        if(is_fancy(input_line))
        {
            cout<<"Real Fancy"<<endl;
        }
        else
        {
            cout<<"regularly fancy"<<endl;
        }
    }
    return 0;
}

