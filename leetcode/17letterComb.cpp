//
// Created by dell on 2019/1/19.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letters;
    vector<string> res;
    void combine(vector<int> &nums, int index, vector<char> &temp){
        if(index == nums.size()){
            string tmp;
            for(int i=0;i<temp.size();i++){
                tmp += temp[i];
            }
            res.push_back(tmp);
            return;
        }
        string str = letters[nums[index]];
        for(int i=0;i<str.length();i++){
            cout<<str[i]<<endl;
            temp.push_back(str[i]);
            combine(nums, index+1, temp);
            temp.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.length()<=0)return res;
        letters.clear();
        letters.push_back(string("abc"));
        letters.push_back(string("def"));
        letters.push_back(string("ghi"));
        letters.push_back(string("jkl"));
        letters.push_back(string("mno"));
        letters.push_back(string("pqrs"));
        letters.push_back(string("tuv"));
        letters.push_back(string("wxyz"));
        vector<char> temp;


        vector<int> nums;
        for(int i=0;i<digits.length();i++){
            nums.push_back((int)(digits[i] - '0') - 2);
        }

        combine(nums, 0, temp);

        return res;
    }

};


