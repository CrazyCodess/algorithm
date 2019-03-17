#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> need(n), price(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> need[i] >> price[i];
    }
     
    for (int i = 0; i < n; i++) {
        if (mp[need[i]] < price[i]) {
            mp[need[i]] = price[i];
        }
    }
     
    vector<int> ability(m);
    for (int i = 0; i < m; i++) {
        cin >> ability[i];
        if (mp.count(ability[i]) == 0) {
            mp[ability[i]] = 0;
        }
    }
     
    auto pre = mp.begin();
    auto tmp = mp.begin();
    tmp++;
    for (; tmp != mp.end(); tmp++, pre++) {
        if (tmp->second < pre->second) {
            tmp->second = pre->second;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << mp[ability[i]] << endl;
    }
    return 0;
}