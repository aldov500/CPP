#include <iostream>
using namespace std;
int main()
{
    string s[200],x[200],ct,dt;
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {

            if(s[i]>s[j])
            {

                ct=s[i];
                s[i]=s[j];
                s[j]=ct;

            }

        }

    }
    cout<<"Sorted Name in Dictionary Order"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;


}
