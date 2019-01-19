#include<bits/stdc++.h>  
using namespace std;
typedef pair<string, int> psi;
vector< psi > g;
string s;

bool cmp(psi x, psi y)
{
    string sx="", sy="";
    for(char c : x.first)if(c<97)sx+=(c+32);else sx+=c;
    for(char c : y.first)if(c<97)sy+=(c+32);else sy+=c;
    if(sx==sy)return x.second<y.second;
    return sx<sy;
}

bool judge(psi x, psi y)
{
    string sx="", sy="";
    for(char c : x.first)if(c<97)sx+=(c+32);else sx+=c;
    for(char c : y.first)if(c<97)sy+=(c+32);else sy+=c;
    return sx==sy;
}

int main()
{
    int cnt=0;
    while(cin>>s)g.push_back(make_pair(s, ++cnt));
    sort(g.begin(),g.end(),cmp);
    cout<<g[0].first;
    for(int i=1;i<g.size();i++)if(!judge(g[i-1],g[i]))cout<<" "<<g[i].first;
    cout<<endl;
    return 0;
}


