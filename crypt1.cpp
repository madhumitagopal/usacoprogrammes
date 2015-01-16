/*
ID: uniquem1
PROG: crypt1
LANG: C++11
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
using namespace std;
int n,a[10];
bool is(int num)
{int d,i;
while(num)
{   d=num%10;

for(i=0;i<n;i++)
{
    if(a[i]==d) break;
}
if(i==n)
    return false;
num=num/10;
}
return true;
}

int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    //scanf("%d",&n);
    fin>>n;
    int i=0;
    long int count=0;
    int temp=n;
    while(temp--)
    {  fin>>a[i];
        i++;
    }

    for(int b=100;b<=999;b++)
    {   if(is(b))
        for(int a1=10;a1<=99;a1++)
        {
            if(is(a1))
                {
                int d1=a1%10,d2=(a1/10)%10;
                int ans;
                ans=a1*b;
                int pp1=b*d1,pp2=b*d2;
                if(pp1<1000 && pp2<1000)
                if(is(ans) && is(pp2) && is(pp1))
                 count++;
              }
        }
    }
   // cout<<count;
    fout<<count<<"\n";
    return 0;
}
