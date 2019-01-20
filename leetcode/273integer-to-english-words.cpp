/**
* @Date 2019/1/20 21:19
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string res;
    map<int, string> words;
    void appendWords(int tmp){
        while(tmp){
            if(tmp/100>0){
                res.append(" "+words[tmp/100]);
                res.append(" "+words[100]);
                tmp -= (tmp/100)*100;
            }else if(tmp/20>0){
                res.append(" "+words[(tmp/10)*10]);
                tmp -= (tmp/10)*10;
            }else{
                res.append(" "+words[tmp]);
                tmp = 0;
            }
        }
    }
    string numberToWords(int num) {
        words[1000000000] = "Billion";
        words[1000000] = "Million";
        words[1000] = "Thousand";
        words[100] = "Hundred";

        words[11] = "Eleven";
        words[12] = "Twelve";
        words[13] = "Thirteen";
        words[14] = "Fourteen";
        words[15] = "Fifteen";
        words[16] = "Sixteen";
        words[17] = "Seventeen";
        words[18] = "Eighteen";
        words[19] = "Nineteen";


        words[0] ="Zero";
        words[1] = "One";
        words[2] = "Two";
        words[3] = "Three";
        words[4] = "Four";
        words[5] = "Five";
        words[6] = "Six";
        words[7] = "Seven";
        words[8] = "Eight";
        words[9] = "Nine";
        words[10] = "Ten";
        words[20] = "Twenty";
        words[30] = "Thirty";
        words[40] = "Forty";
        words[50] = "Fifty";
        words[60] = "Sixty";
        words[70] = "Seventy";
        words[80] = "Eighty";
        words[90] = "Ninety";
        int tmp;
        if(num == 0)return words[0];
        while(num){
            if(num/1000000000>0){
                tmp = num/1000000000;
                num -=tmp * 1000000000;
                res.append(words[tmp]);
                res.append(" "+words[1000000000]);
            }else if(num/1000000>0){
                tmp = num/1000000;
                num -=tmp * 1000000;
                appendWords(tmp);
                res.append(" "+words[1000000]);
            }else if(num/1000>0){
                tmp = num/1000;
                num -= tmp * 1000;
                appendWords(tmp);
                res.append(" "+words[1000]);
            }else{
                tmp = num;
                num = 0;
                appendWords(tmp);
            }
        }
        if (res[0]== ' '&&res.length()>0) res.erase(0,1);
        return res;

    }
};