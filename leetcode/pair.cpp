#include<bits/stdc++.h>
using namespace std;
typedef pair<string, int> psi;
vector< psi > g;
string s1,s2,s3;

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


//    int cnt=0;
//    cin>>s1;
//    cin>>s2;
//    cin>>s3;
//    while(cin>>s){
//      cout<<s;
//      g.push_back(make_pair(s1, ++cnt));
//      g.push_back(make_pair(s2, ++cnt));
//      g.push_back(make_pair(s3, ++cnt));
//      cout<<g[0].first<<g[0].second<<endl;
//    }
//     sort(g.begin(),g.end(),cmp);
//     cout<<g[0].first;
//     for(int i=1;i<g.size();i++)if(!judge(g[i-1],g[i]))cout<<" "<<g[i].first;
//     cout<<endl;
g.push_back(make_pair(0,2))
g[0].first += 3;
        g[0].second += 5;
        cout<<g[0]<<endl;
    return 0;
}
