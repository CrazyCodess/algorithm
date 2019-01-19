#include<bits/stdc++.h>
using namespace std;
typedef pair<char,int> psi;

int romanToInt(string s) {
		map<char,int> g;
		g.insert(make_pair('I',1));
		g.insert(make_pair('V',5));
		g.insert(make_pair('X',10));
		g.insert(make_pair('L',50));
		g.insert(make_pair('C',100));
		g.insert(make_pair('D',500));
		g.insert(make_pair('M',1000));
		int ans = 0;
		for(int i=s.size() - 1;i>=0;i--){
			if(s[i]=='V'||s[i]=='X'){
				 if((i-1)>=0&&s[i-1] == 'I'){
					 ans += g[s[i]] - 1;
					 i--;
					 continue;
				 }
				 ans += g[s[i]];
			}else if(s[i]=='L'||s[i]=='C'){
				if((i-1)>=0&&s[i-1] == 'X'){
					ans += g[s[i]] - 10;
					i--;
					continue;
				}
				ans += g[s[i]];

			}else if(s[i]=='D'||s[i]=='M'){
				if((i-1)>=0&&s[i-1] == 'C'){
					ans += g[s[i]] - 100;
					i--;
					continue;
				}
				ans += g[s[i]];
			}else{
				ans += g[s[i]];
			}

		}
		return ans;


}
int main(){

	cout<<romanToInt("IX")<<endl;
	return 0;
}
