/**
* @Date 2019/1/20 20:40
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string res;
    map<int, string> roman;

    void appendRoman(int tmp, int w){
        while(tmp){
            if(tmp>=9){
                res.append(roman[9*w]);
                tmp -= 9;
            }else if(tmp >=5){
                res.append(roman[5*w]);
                tmp -= 5;
            }else if(tmp >=4){
                res.append(roman[4*w]);
                tmp -= 4;
            }else{
                for(int i=0;i<tmp;i++){
                    res.append(roman[1*w]);
                    tmp --;
                }
            }
        }
    }
    string intToRoman(int num) {
        roman[1] = "I";
        roman[5] = "V";
        roman[10] = "X";
        roman[50] = "L";
        roman[100] = "C";
        roman[500] = "D";
        roman[1000] = "M";
        roman[4] = "IV";
        roman[9] = "IX";
        roman[40] = "XL";
        roman[90] = "XC";
        roman[400] = "CD";
        roman[900] = "CM";
        res.clear();
        int tmp = 0;
        while(num){
            if(num/1000>0){
                tmp = num/1000;
                num -=tmp * 1000;
                for(int i=0;i<tmp;i++)res.append(roman[1000]);

            }else if(num/100>0){
                tmp = num/100;
                num -=tmp * 100;
                appendRoman(tmp, 100);
            }else if(num/10>0){
                tmp = num/10;
                num -= tmp * 10;
                appendRoman(tmp,10);
            }else{
                tmp = num;
                num = 0;
                appendRoman(tmp,1);
            }
        }
        return res;
    }
};


