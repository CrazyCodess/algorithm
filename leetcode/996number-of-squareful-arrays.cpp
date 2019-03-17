/**
* @Date 2019/02/26 10:11
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSquarefulPerms(int num){
        int cnt = (int)sqrt(num);
        return cnt*cnt == num;
    }
    void backtracking(vector<int>& A, vector<bool>& f, int num, int idx, vector<int>& tmp){
        if(path.find(tmp) == path.end()) path.insert(tmp);
        else return;
        if(idx == A.size()){  
            res++; 
            return;
        }
        for(int i=0;i<A.size();i++){
            if(f[i])continue;
            if(!isSquarefulPerms(num+A[i]))continue;
            f[i] = true;
            tmp.push_back(A[i]);
            cout<<A[i]<<" "<<idx<<" ";
            backtracking(A, f, A[i], idx+1, tmp);
            tmp.pop_back();
            f[i] = false;
        }
    }
    int numSquarefulPerms(vector<int>& A) {
        res = 0;
        set<vector<int> > sets;
        vector<int> tmp;
        vector<bool> f(A.size(), false);
        for(int i=0;i<A.size();i++){
            f[i] = true;
            tmp.push_back(A[i]);
            backtracking(A, f, A[i], 1, tmp);
            tmp.pop_back();
            f[i] = false;
        }
        return res;
    }    
    private:
    set<vector<int> > path;
    int res;
};
int main(){
    vector<int> A;
    A.push_back(2);
    A.push_back(2);
    A.push_back(2);
        A.push_back(2);
    A.push_back(2);
    A.push_back(2);
        A.push_back(2);
    A.push_back(2);
    A.push_back(2);
        A.push_back(2);
    A.push_back(2);
    Solution solu;
    cout<<solu.numSquarefulPerms(A);
    return 0;
}