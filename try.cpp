#include <iostream>
using namespace std;
int main ()
{
    string name[10];
    int ctr=0;
    string input;
    string temp="";
    cin>>input;
    for(int i=0;i<input.length();i++)
    {
         temp+=input[i];
        if(input[i]==';' || input[i]==',' || input[i]=='.')
        {
            name[ctr]=temp;
            ctr++;
            temp="";
        }
    }
    for(int i=0;i<ctr;i++)
    {
        for(int j=0;j<name[i].length();j++)
        {
            if(name[i][0]>=97 && name[i][0]<=122)
            {
                name[i][0]-=32;
            }
            else if (name[i][j]>=65 && name[i][j]<=90)
            {
                name[i][j]+=32;
            }
        }
    }
    for(int i=0;i<ctr;i++)
    {
        cout<<name[i];
        cout<<endl;
    }
}