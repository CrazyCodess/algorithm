/**
* @Date 2019/03/15 16:22
* @Created by dmyan
*/
#include<bits/stdc++.h>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        int i=0,j=0;
        vector<Interval> res;
        Interval tmp;
        while(i<n&& intervals[i].end<newInterval.start){
            res.push_back(intervals[i]);
            i++;
        }
        if(i==n){
            tmp.start = newInterval.start;
            tmp.end = newInterval.end;
            res.push_back(tmp);
        }else{
            tmp.start = min(newInterval.start, intervals[i].start);
            while(i<n&&intervals[i].end<newInterval.end)i++;
            if(i==n){
                tmp.end = newInterval.end;
                res.push_back(tmp);
            }
            else {
                if(newInterval.end>=intervals[i].start) {
                    tmp.end = intervals[i].end;
                    i++;
                }
                else tmp.end = newInterval.end;
                res.push_back(tmp);
                while(i<n){
                    res.push_back(intervals[i]);
                    i++;
                }
            }
        }
        return res;
    }
};