/*
ID: uniquem1
PROG: combo
LANG: C++
*/
#include<iostream>
#include<map>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int m[3],f[3],n;
bool check_master(int i,int j,int k)
{
    if(abs(m[0]-i)<=2 || n-abs(m[0]-i)<=2)
      if(abs(m[1]-j)<=2 || n-abs(m[1]-j)<=2)
            if(abs(m[2]-k)<=2 || n-abs(m[2]-k)<=2)
            return true;
            else
            return false;
    else
            return false;
    else
        return false;
}
bool check_farmer(int i,int j,int k)
{
    if(abs(f[0]-i)<=2 || n-abs(f[0]-i)<=2)
       if(abs(f[1]-j)<=2 || n-abs(f[1]-j)<=2)
            if(abs(f[2]-k)<=2 || n-abs(f[2]-k)<=2)
        return true; else return false;
        else return false;
    else
        return false;
}
int main()
{   long long int count=0;
    ofstream fout("combo.out");
    ifstream fin("combo.in");
   fin>>n;
    //scanf("%d",&n);
    //cout<<n;
    fin>>f[0]>>f[1]>>f[2];
    fin>>m[0]>>m[1]>>m[2];
    //scanf("%d %d %d",&f[0],&f[1],&f[2]);
    //scanf("%d %d %d",&m[0],&m[1],&m[2]);
    int i;
    //cout<<n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            if(check_farmer(i,j,k) || check_master(i,j,k))
                count++;
        }
    }
    fout<<count<<"\n";
    //cout<<count<<"\n";
    return 0;
}
