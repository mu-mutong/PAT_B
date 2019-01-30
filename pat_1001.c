#include<stdio.h>
int main(){
	int n,num=0;
	scanf("%d",&n);
	while(1){
		if(n==1)    // 若输入n=1为特殊情况，不用计算可以直接输出0； 
			break;
		//偶数情况	
		if(n%2==0){
			n=n/2;
			num++;
		}
		//奇数情况	
		else if(n%2==1){
			n=(3*n+1)/2;
			num++;
		}
	} 
	printf("%d",num);
	return 0;
}
