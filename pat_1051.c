/*
1051. 复数乘法 (15)

复数可以写成(A + Bi)的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i2 = -1；也可以写成极坐标下的指数形式(R*e(Pi))，其中R是复数模，P是辐角，i是虚数单位，其等价于三角形式 R(cos(P) + isin(P))。
现给定两个复数的R和P，要求输出两数乘积的常规形式。
输入格式： 
输入在一行中依次给出两个复数的R1, P1, R2, P2，数字间以空格分隔。 
输出格式： 
在一行中按照“A+Bi”的格式输出两数乘积的常规形式，实部和虚部均保留2位小数。注意：如果B是负数，则应该写成“A-|B|i”的形式。 
输入样例：
2.3 3.5 5.2 0.4
输出样例：
-8.68-8.23i
*/
#include<stdio.h>
#include<math.h>
int main(){
	double R1=0.0,P1=0.0,R2=0.0,P2=0.0;
	scanf("%lf %lf %lf %lf",&R1,&P1,&R2,&P2);
	double A,B;
	A = R1 * R2 * cos(P1) * cos(P2) - R1 * R2 * sin(P1) * sin(P2);
    B = R1 * R2 * cos(P1) * sin(P2) + R1 * R2 * sin(P1) * cos(P2);

	if(A+0.005>=0&&A<0){
		A=0;
	}
	else if(A==-0){
		A=0;
	}
	printf("%.2lf",A);
	if(B>=0){
		printf("+%.2lfi",B);
	}
	else if(B+0.01>=0&&B<0){
		printf("+0.00i");
	}
	else{
		printf("%.2lfi",B);
	}
	
	return 0;
}
