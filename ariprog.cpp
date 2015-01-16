/*
ID: uniquem1
PROG: ariprog
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int n,m;
    //scanf("%d",&n);
    //scanf("%d",&m);
    fin>>n;
    fin>>m;
    bool check[2*m*m+1];
    memset(check,false,sizeof(check));
    check[0]=true;
    for(int i=1;i<=m;i++)
    {   check[i*i]=true;
        for(int j=i;j<=m;j++)
        {
            check[i*i+j*j]=true;
        }
    }
    for(int i=0;i<=2*m*m;i++)
    if(check[i]) cout<<i<<"\n";
    int flag=0;
    for(long int i=1;i<=(2*m*m)/(n-1);i++)// possible differences
       {
        for(long int j=0;j<=2*m*m-i*(n-1);j++) //starting number
        {
            if(check[j])
            {
            long int  count=1;int k;
            for(k=1;k<n;k++)
            {
                if(!check[j+k*i])
                break;
            }
            if(k==n)
                {fout<<j<<" "<<i<<"\n";
                    flag=1;}
            }
            }
        }

    if(flag==0) fout<<"NONE\n";
    return 0;
}
