/**
* @Date 2019/03/09 20:20
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int pre, p;
    char temp;
    while(cin>>s){
        p = s.size();
        pre = s.size()-1;
        while(pre>=0){
            for(;pre>=0;pre--){
                if(s[pre]>='A'&&s[pre]<='Z')break;
            }
            if(pre>=0&&p>pre){
                p--;
                temp = s[pre];
                for(int i=pre+1;i<=p;i++){
                    s[i-1] = s[i];
                }
                s[p] = temp;
            }
            pre--;

        }
        cout<<s<<endl;
    }
    return 0;
}