#include<bits/stdc++.h>
using namespace std;

// char* longestCommonPrefix(char** strs, int strsSize) {
//     int min_len = strlen(strs[0]);
//     for(int i=0;i<strsSize;i++){
//         if(strlen(strs[i])<min_len){
//             min_len = strlen(strs[i]);
//         }
//     }
    
//     if(strsSize == 1)return strs[0];
//     if(min_len==0)return "";
    
    
//     char test ;
//     int cnt = 0;
//     bool isTerminal = false;
//     for(int i =0;i<min_len;i++){
//         test = strs[0][i];
//         for(int j=0;j<strsSize;j++){
//             if(strs[j][i] != test){
//                 if(cnt == 0)return "";
// 		isTerminal = true;
//             }
            
//         }
//         if(isTerminal)break;
//         cnt++;
//     }
//     static char* ans = NULL;
//     ans = (char*)malloc(cnt*sizeof(char));
//     for(int i=0;i<cnt;i++){
//         ans[i] = strs[0][i];
//     }
//     return ans;
    
// }

int main(){
    map<string, int> m;
    m["abcd"] = 1;
    string s = "abcdefg";
    cout<<m[s.substr(0, 4)]<<endl;
    return 0;
} 


