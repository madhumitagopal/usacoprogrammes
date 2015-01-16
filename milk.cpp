/*
ID: uniquem1
PROG: milk
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<map>
#include<utility>
#include<algorithm>
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.first < right.first;
    }
};
struct sort_pred1 {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second >right.second;
    }
};

using namespace std;
int main()
{
    long int n;int m;
    ofstream fout("milk.out");
    ifstream fin("milk.in");
    //scanf("%ld %d",&n,&m);
    fin>>n>>m;
    pair<int,long int> pa[m];
    int i=0;
    int temp=m;
    while(temp--)
    {
        int p;long int a;
        //scanf("%d %ld",&p,&a);
        fin>>p>>a;
        pa[i++]=make_pair(p,a);
    }
    sort(pa,pa+m,sort_pred());
   //   for(int i=0;i<m;i++)
    //cout<<pa[i].first<<pa[i].second<<"\n";
    int key=pa[0].first;
    int beg=0;int end=0;
   //sort(pa+1,pa+3,sort_pred1());
    for(int i=1;i<m;i++)
    {   if(pa[i].first==key) end=i;

        else
        {   if(beg!=end)
                {//cout<<beg<<"\t"<<end<<"\n";
                sort(pa+beg,pa+end+1,sort_pred1());
                }
            beg=i;end=i;key=pa[i].first;
        }
    }
    //for(int i=0;i<m;i++)
    //cout<<pa[i].first<<pa[i].second<<"\n";
    long int ans=0;
    for(int i=0;i<m;i++)
    {
        if(n-pa[i].second>=0)
            {ans+= pa[i].first*pa[i].second;n=n-pa[i].second;}
        else
            {
                ans+=pa[i].first*n;break;
            }
    }
    //printf("%ld",ans);
    fout<<ans<<"\n";
    return 0;

}
