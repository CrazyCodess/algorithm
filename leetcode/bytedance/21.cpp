/**
* @Date 2019/03/16 10:04
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi  first
#define se second
typedef pair<long, long> pii;
pii s[2];
int main(){
    int n,m;
    scanf("%d", &n);
    string s;
    vector<char> res;
    
    while(n--){
        cin>>s;
        m =  s.size();
        if(m<=2){
            cout<<s<<endl;
        }else{
            res.push_back(s[0]);
            res.push_back(s[1]);
            for(int i=2;i<m;i++){
                if(s[i] == res[res.size()-1] && s[i] == res[res.size()-2])continue;
                if(s[i] == res[res.size()-1] && res[res.size()-2] == res[res.size() - 3])continue;
                res.push_back(s[i]);
            }
            s.clear();
            for(int i=0;i<res.size();i++)s.push_back(res[i]);
            res.clear();
            cout<<s<<endl;
        }
    }
    return 0;
}