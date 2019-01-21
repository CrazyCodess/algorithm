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


int main(){
 std::vector<int> v;
 v.push_back(1);
  v.push_back(-1);
   v.push_back(2);
    v.push_back(-4);
     v.push_back(5);
// Solution solu;
     sort(v.begin(), v.end());
     for(int i=0;i<v.size();i++){
      cout <<v[i]<<"\n";
     }
  std::cout <<" "<< '\n';

  return 0;
}



