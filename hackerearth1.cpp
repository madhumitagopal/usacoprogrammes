#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long int l;
    scanf("%lld",&l);
    long long int a[l];
    long long int temp=l,i=0;
    long long int n;
    while(temp--)
    {
        scanf("%lld",&a[i++]);
    }
    sort(a,a+l);

    long long int count=0;
    for(long long int i=0;i<l;i++)
    {
        cout<<a[i]-i;
        if(i!=l-1) cout<<" ";
    }

    return 0;

}
