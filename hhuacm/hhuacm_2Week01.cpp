/*分解质因数*/ 

#include<iostream>
#include <math.h>
using namespace std;
int IsPrime(int n)
{
    int i;
    for (i=2; i<=sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int sumOfNum(int n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int SumOfPrimerFactor(int n){
	int sum=0;
	int i=2;
	while(true){
		if(n%i==0){
			sum+=sumOfNum(i);
			if(IsPrime(n/=i)){
				break;
			}
		}
		else i++; 
		
	}
	return sum+=sumOfNum(n);
}
int main(){
	int n,i;
	while(cin>>n&&n){
		int flag=1;
		i=n+1;
			while(flag){
				if(!IsPrime(i)){
					
					if(SumOfPrimerFactor(i)==sumOfNum(i)){
						cout<<i<<endl;
						flag=0;
					}
					
				}
				 i++;
			}
		
		}
	}
