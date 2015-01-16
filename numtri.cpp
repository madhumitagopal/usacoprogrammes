/*
ID: uniquem1
PROG: numtri
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<array>
#include<stdio.h>
using namespace std;
int main()
{   ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    int n;
    fin>>n;
    array<int,1000> curr,prev;
    fin>>prev[0];
    for(int i=1;i<n;i++)
    {

        for(int j=0;j<=i;j++)
        {   fin>>curr[j];
            if(j==i)
            {
                curr[i]=curr[i]+prev[i-1];
            }
            else if(j==0)
            {
                curr[0]=curr[0]+prev[0];
            }

            else
            {
                curr[j]=max(curr[j]+prev[j-1],curr[j]+prev[j]);
            }
        }
        //for(int j=0;j<=i;i++)
       // cout<<curr[i]<<"\t";
        //cout<<"\n";
        curr.swap(prev);

    }
    int max=prev[0];
    for(int j=1;j<n;j++)
    {if(prev[j]>max) max=prev[j];}
        fout<<max<<"\n";

    return 0;
}
