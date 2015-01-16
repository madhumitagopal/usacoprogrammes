/*
ID: uniquem1
PROG: milk2
LANG: C++11
*/
#include<iostream>
#include<map>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main()
{
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int n;
   fin>>n;
   //cin>>n;
    map<long int,long int> m1;
    map<long int,long int>::iterator it1,it2;
    long int a,b;
    int ouch=0;
    for(int i=0;i<n;i++)
    {
        fin>>a>>b;
        //cin>>a>>b;
        //m1[a]=b;
        if(m1.find(a)==m1.end())
        ouch++;
        else
        m1.insert(pair<long int,long int>(a,b));
    }
    cout<<ouch;
    for(it1=m1.begin();it1!=m1.end();++it1)
    fout<<it1->first<<" "<<it1->second<<'\n';
    it1=m1.begin();
    long int upper=it1->second;
    long int lower=it1->first;
    long long int ans1=0;
    for(it1=m1.begin();it1!=m1.end();++it1)
    { if(it1->first<=upper && it1->second>=upper)
        {upper=it1->second;if(ans1<upper-lower)
            ans1=upper-lower;}
      else if(it1->first>upper)
      {

        if(ans1<upper-lower)
            ans1=upper-lower;
        upper=it1->second;
        lower=it1->first;
      }



    }

    //cout<<ans1;
    long long int ans2=0;
    for(it1=m1.begin();it1!=m1.end();it1=it2)
    {   int upper=it1->second;
        for(it2=it1;it2->first<upper && it2!=m1.end();it2++) if(it2->second>upper) upper=it2->second;
        if(it2!=m1.end())
            if(it2->first-upper>ans2)
                ans2=it2->first-upper;

    }
    fout<<ans1<<" "<<ans2<<"\n";
    //cout<<ans1<<" "<<ans2<<"\n";
    return 0;

}
