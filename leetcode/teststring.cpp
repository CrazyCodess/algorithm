//
// Created by dell on 2019/1/19.
//

//
// Created by dell on 2018/12/22.
//
#include<bits/stdc++.h>
#include <bitset>
#include <string> 
using namespace std;

    int hammingWeight(uint32_t n) {
        bitset<32> res(string(n));
        return res.count();
    }
int main ()
{
  
//hammingWeight(00000000000000000000000010000000)
  std::cout <<string(456454564)<< '\n';

  return 0;
}