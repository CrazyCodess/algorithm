/**
* @Date 2019/03/05 10:35
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mountain(vector<int>& A,  int idx){
        bool f = false;
        int left = idx;
        int i = idx+1;
        for( ;i < A.size(); i++)
        {
            if(A[i] == A[i-1]){
                break;
            }
            if(f&&A[i]>A[i-1]){
                break;
            }else if(A[i]<A[i-1]) f = true;
        }
        return f?(i-left):0;
    }
    int longestMountain(vector<int>& A) {
        if(A.size()<=2) return 0;
        int maxlen = 0;
        for(int i=0;i<A.size();i++){
            while(i+1<A.size()){
                if(A[i+1]>A[i])break;
                i++;
            }
            maxlen = max(maxlen, mountain(A, i));
            if(A.size()-i<=maxlen)break;    
        }
        return maxlen;
    }    
};
int main(){  
    vector<int> nums = {0,0,1,0,0,1,1,1,1,1};
    Solution solu;
    cout<<solu.longestMountain(nums)<<endl;
    return 0;
}