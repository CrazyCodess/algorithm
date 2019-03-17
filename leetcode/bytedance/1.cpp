#include <bits/stdc++.h>
using namespace std;
void backtracking(string &A, string &B, int idx1, int idx2, int left, int right, long long &cnt){
    if(right>left)return;
    if(idx1>=A.size() && idx2>=B.size()){
        cnt++;
        return;
    }
    if(idx1<A.size()){
        if(A[idx1] == '('){
            backtracking(A, B, idx1+1, idx2, left+1, right, cnt);
        }else if(A[idx1] == ')'){
            backtracking(A, B, idx1+1, idx2, left, right+1, cnt);
        }
    }
    if(idx2<B.size()){
        if(B[idx2] == '('){
            backtracking(A, B, idx1, idx2+1, left+1, right, cnt);
        }else if(B[idx2] == ')'){
            backtracking(A, B, idx1, idx2+1, left, right+1, cnt);
        }
    }

}
int main(){
    string A, B;
    cin>>A>>B;
    
    int left=0, right=0;
    for(int i=0;i<A.size();i++){
        if(A[i] == '(')left++;
        else if (A[i] == ')')right++;
    }
    for(int i=0;i<B.size();i++){
        if(B[i] == '(')left++;
        else if (B[i] == ')')right++;
    }
    long long cnt = 0;
    if(left != right)cout<<cnt<<endl;
    else{
        backtracking(A, B, 0, 0, 0, 0, cnt);
        cout<<cnt%((long long)pow(10,9)+7)<<endl;
    }
   
}