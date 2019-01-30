/*

输入样例：
6 50
42 0 0 0 0 0
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29
输出样例：
42
33
41
31
37
39

*/


#include<stdio.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	float a=0,t=0;
	int j=0,i=0;
	for(j=0;j<n;j++){
		float min=m,max=0;
		float sum=0;
		int num=n-3;
		for(i=0;i<n;i++){
			scanf("%f",&a);
			if(i==0){
				t=a;
				continue;
			}
			if(a<0||a>m){
				num--;
				continue;
			}
			if(a<min){
				min=a;
			}
			if(a>max){
				max=a;
			}
			if(i>0){
				sum+=a;
			}
		}
	
		sum=(sum-min-max)/(num);
		int ans=(t+sum)/2+0.5;
		printf("%d\n",ans);
	}
	
	return 0;
} 
