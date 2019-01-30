/*给定区间[-231, 231]内的3个整数A、B和C，请判断A+B是否大于C。 
输入格式： 
输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，
每组占一行，顺序给出A、B和C。整数间以空格分隔。
输出格式： 
对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，
否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。
输入样例：
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
输出样例：
Case #1: false
Case #2: true
Case #3: true
Case #4: false*/
#include<stdio.h>
int main(){
	double A,B,C;
	int n,i=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%lf %lf %lf",&A,&B,&C);
		if(A+B>C){
			a[i]=1;
		}
		else{
			a[i]=0;
		}
	}
	for(i=0;i<n;i++){
		if(a[i]){
			printf("Case #%d: true\n",i+1);
			
		}
		else{
			printf("Case #%d: false\n",i+1);
		}
	}
	return 0;
} 
