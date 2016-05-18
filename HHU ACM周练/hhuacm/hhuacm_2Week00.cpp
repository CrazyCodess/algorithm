#include<iostream>
#include<cmath>
using namespace std; 
bool isPrimer(int n){
    int m=sqrt(n);
    int i;
    for(i=2;i<=m;i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    long int n,i,num;
    while(cin>>n&&n){
        num=0;
        for(i=2;i<n/2;i++){
            if(isPrimer(i)&&isPrimer(n-i))
            num++;
        }
        
        cout<<num<<endl; 
    } 
} 