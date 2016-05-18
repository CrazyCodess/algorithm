#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int year,month,day,sum;
	int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d%d%d%d",&year,&month,&day,&sum);
	while(sum>0){
		
		if(month==2&&(year%4==0&&year%100!=0||year%400==0)){
			
			
				if(sum>=29){
					day=day+days[month]+1;
					sum=sum-days[month]-1;
					if(day>days[month]+1){
						day=day-days[month]-1;
						month++;
					}					
				}else{
					day+=sum;
					sum=0;
					if(day>days[month]+1){
						day=day-days[month]-1;
						month++;
					}					
				}
				
		
			//printf("*\n");

		}
		else{
			
			
			if(sum>=days[month]){
				day+=days[month];
				sum-=days[month];
				//printf("#\n");				
			}
			else{
				day+=sum;
				sum=0;
			}

		}
		
		if(day>days[month]){
			day-=days[month];
			month++;
		}
		if(month>12){
			month-=12;
			year++;
		}
	}
	printf("%d-%d-%d\n",year,month,day);
	return 0;
}
