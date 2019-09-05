#include<bits/stdc++.h>
using namespace std;
int arr[100010];
int sum[100010];
int m,n;
//vector<int> path;
void backtracking(int &time, int tmp, int start, int step){
    if(step == 0){
        tmp = max(tmp, sum[n-1] - sum[start - 1]);
        time = min(time, tmp);
        // for(int i=0;i<path.size();i++)cout<<path[i]<<" ";
        // cout<<tmp<<endl;
        return;
    }
    for(int i=start+1;i<n;i++){
        if(step == m) tmp = max(tmp, sum[i-1] );
        else tmp = max(tmp, sum[i-1] - sum[start - 1]);

        backtracking(time, tmp, i, step-1);

    }
}
int main(){

    scanf("%d%d", &m, &n);
    for(int i=0;i<n;i++)scanf("%d", &arr[i]);
    sum[0] = arr[0];
    for(int i=1;i<n;i++)sum[i] = sum[i-1] + arr[i];
    int time = INT_MAX;
    backtracking(time, 0, 0, m-1);
    printf("%d\n", time);
    return 0;
}