#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long s[maxn];
int in[maxn]; 
long prize[maxn];
long res;
int main(){
    int n,m;
    scanf("%d", &n);
    queue<int> que;
    int left, right,y;
    while(n--){
        res = 0;
        que = queue<int>();
        scanf("%d", &m);
        vector<long> ans(m ,0);
        vector<vector<int>> edges(m, vector<int>());
        for(int i=0;i<m;i++){
            scanf("%ld", &s[i]);
            in[i] = 0;
        }
        for(int i=0;i<m;i++){
            left = (i-1+m)%m;
            right = (i+1)%m;
            if(s[i]<s[left]){
                edges[i].push_back(left);
                in[left]++;
            }
            if(s[i]<s[right]){
                edges[i].push_back(right);
                in[right]++;
            }
        }
        for(int i=0;i<m;i++)if(in[i] == 0){
            que.push(i);
            prize[i] = 1;
        }
        int node;
        while(!que.empty()){
            node = que.front();
            que.pop();
            res += prize[node];
            ans[node] = prize[node];
            for(int i=0;i<edges[node].size();i++){
                y = edges[node][i];
                in[y]--;
                if(in[y] == 0){
                    que.push(y);
                    prize[y] = prize[node] + 1;
                }
            }
        }
        printf("prize: ");
        for(int i=0;i<m;i++)printf("%d ", ans[i]);
        printf("\n%ld\n", res);
    }
    return 0;
}