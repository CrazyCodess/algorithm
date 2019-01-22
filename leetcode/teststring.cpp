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
using namespace std;
class Solution {

public:
  int val ;
  Solution(int v){val = v;}
    int numFriendRequests(vector<int>& ages) {
        
        if(ages.size()<=1)return 0;
        sort(ages.begin(), ages.end());
        int tmp = ages[0];
        int num = 0 ;
        for(int i=1;i<ages.size();i++){
            if(ages[i] == tmp&&ages[i]>14){
              num++;
              //cout<<ages[i]<<" "<<ages[i]<<"\n";
            }
            else tmp = ages[i];
        }

        int cnt = 0;


    for(int i=ages.size()-1;i>=0;i--)
        for(int j=i-1;j>=0;j--){
            if(ages[j]<=0.5*ages[i]+7||ages[j]>ages[i])continue;
            cnt++;
            cout<<ages[i]<<" "<<ages[j]<<"\n";

        }

        return cnt+num;
    }
};

int main(){
  bitset<10000> bar (5);
  for(int i=0;i<10;i++){
    cout<<bar[i]<<" ";
  }
  std::cout <<" "<< '\n';

  return 0;
}
