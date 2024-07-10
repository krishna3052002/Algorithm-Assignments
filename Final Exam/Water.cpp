#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll max=-1;
        ll max_index;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>max)
            {
                max=a[i];
                max_index=i;
            }
        }
        ll max2=-1;
        ll max2_index;
        for(ll i=0;i<n;i++)
        {
           
            if(a[i]!=max && i!=max_index && a[i]>max2)
            {
              max2=a[i];
              max2_index=i;

            }
            
        }
        if(max_index<max2_index)
        {
            cout<<max_index<<" "<<max2_index<<endl;
        }
        else{
            cout<<max2_index<<" "<<max_index<<endl;
        }

    }
}