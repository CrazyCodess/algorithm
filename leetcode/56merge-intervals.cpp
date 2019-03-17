/**
* @Date 2019/2/24 17:27
* @Created by dmyan
*/
#include<bits/stdc++.h>

using namespace std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(struct Interval &inter1, struct Interval &inter2){
    return inter1.start<inter2.start;
}
class Solution {
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 1)return intervals;
        vector<Interval> res;
        if(intervals.size() == 0)return res;
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0].start, end = intervals[0].end;
        int cnt = 1;
        while(cnt < intervals.size()){
            if(end>intervals[cnt].end){
                if(cnt == intervals.size() - 1){
                    Interval tmp(start, end);
                    res.push_back(tmp);
                }
                cnt++;
                continue;
            }
            if(end>=intervals[cnt].start){
                end = intervals[cnt].end;
                if(cnt == intervals.size() - 1){
                    Interval tmp(start, end);
                    res.push_back(tmp);
                }
                cnt ++;
            }else{
                Interval tmp(start, end);
                res.push_back(tmp);
                start = intervals[cnt].start;
                end = intervals[cnt].end;
                if(cnt == intervals.size() - 1){
                    Interval tmp(intervals[cnt].start, intervals[cnt].end);
                    res.push_back(tmp);
                }
                cnt++;
            }
        }
        return res;
    }
};


