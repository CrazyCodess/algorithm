//
// Created by dell on 2019/1/19.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
#include <bitset>
#include <string> 
#include <math.h>   
#include<map>
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> nums(s.size()+1, 0);
        nums[0] = 1;
        nums[1] = 1;
        for(int i = 1;i<s.size();i++){
            nums[i+1] = nums[i];
            if(((s[i-1] - 'A' + 1)*10+(s[i] - 'A' + 1)) <= 26)nums[i+1] += nums[i-1]; 
        }
        return nums[s.size()];
    }
};
int main(){
   Solution solu;
  // vector<int> cand;
  // cand.push_back(2);
  // cand.push_back(3);
  // cand.push_back(6);
  // cand.push_back(7);
  // solu.combinationSum(cand, 7);
    int* a;
    a = 0;
    cout<<INT_MIN;


  return 0;
}
