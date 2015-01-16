/*
ID: uniquem1
PROG: barn1
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{   ofstream fout("barn1.out");
    ifstream fin("barn1.in");
    int m,s,c;

    fin>>m>>s>>c;
    scanf("%d %d %d",&m,&s,&c);
    bool check[s];
    memset(check,false,sizeof(check));
    int temp=c;
    while(temp--)
    {
        int x;
        //scanf("%d",&x);
        fin>>x;
        check[x-1]=true;

    }
    int covered=s;
    int i=0;
    while(check[i]==false && i<s)
    {
        covered--;i++;
    }
    int beg,end;
    beg=i;
    i=s-1;
    while(check[i]==false && i<s)
    {   covered--;i--;}
    end=i;
    int gap=0;
    int gaps[end-beg];
    fill(gaps,gaps+end-beg,0);
    int j=0;
    for(int i=beg;i<=end;i++)
    {
        if(check[i]==false)
        gap++;
        else
        {
            gaps[j++]=gap;gap=0;
        }
    }
    sort(gaps,gaps+j);
   /* cout<<"\n";
    for(int i=0;i<j;i++)
    {
        cout<<gaps[i];
    } */
    j=j-1;
   // cout<<"A"<<covered<<"A";
    while(m>1 && j>=0)
    {
        covered-=gaps[j--];m--;
    }

    printf("%d\n",covered);
    fout<<covered<<"\n";
    return 0;
}























