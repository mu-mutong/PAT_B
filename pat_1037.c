/*
1037. 在霍格沃茨找零钱（20）

如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统
 —— 就如海格告诉哈利的：
 “十七个银西可(Sickle)兑一个加隆(Galleon)，
 二十九个纳特(Knut)兑一个西可，很容易。”现在，
 给定哈利应付的价钱P和他实付的钱A，
 你的任务是写一个程序来计算他应该被找的零钱。 
输入格式： 
输入在1行中分别给出P和A，格式为“Galleon.Sickle.Knut”，
其间用1个空格分隔。这里Galleon是[0, 107]区间内的整数，
Sickle是[0, 17)区间内的整数，Knut是[0, 29)区间内的整数。 
输出格式： 
在一行中用与输入同样的格式输出哈利应该被找的零钱。
如果他没带够钱，那么输出的应该是负数。
输入样例1：
10.16.27 14.1.28
输出样例1：
3.2.1
输入样例2：
14.1.28 10.16.27
输出样例2：
-3.2.1
*/
#include<stdio.h>
int main(){
	int galleon_p=0,sickle_p=0,knut_p=0;
	int galleon_a=0,sickle_a=0,knut_a=0;
	char ch;
	scanf("%d%c%d%c%d",&galleon_p,&ch,&sickle_p,&ch,&knut_p);
	scanf("%d%c%d%c%d",&galleon_a,&ch,&sickle_a,&ch,&knut_a);
	
	
	if(galleon_p*10000+sickle_p*100+knut_p>
	galleon_a*10000+sickle_a*100+knut_a){
		printf("-");
		if(knut_p-knut_a>=0){
			knut_a=knut_p-knut_a;
		}	
		else{
			if(sickle_p>0){
				knut_a=29-knut_a+knut_p;
				sickle_p--;
			}
			else{
				knut_a=29-knut_a+knut_p;
				sickle_p=16; 
				galleon_p--;
			}
		}
		if(sickle_p-sickle_a>=0){
			sickle_a=sickle_p-sickle_a;
		}
		else{
			sickle_a=17-sickle_a+sickle_p;
			galleon_p--;
		}
		galleon_a=galleon_p-galleon_a;
		printf("%d%c%d%c%d",galleon_a,ch,sickle_a,ch,knut_a);
	}
	
	
	else{
		if(knut_a-knut_p>=0){
			knut_a=knut_a-knut_p;
		}	
		else{
			if(sickle_a>0){
				knut_a=29-knut_p+knut_a;
				sickle_a--;
			}
			else{
				knut_a=29-knut_p+knut_a;
				sickle_a=16; 
				galleon_a--;
			}
		}
		if(sickle_a-sickle_p>=0){
			sickle_a=sickle_a-sickle_p;
		}
		else{
			sickle_a=17-sickle_p+sickle_a;
			galleon_a--;
		}
		galleon_a=galleon_a-galleon_p;
		printf("%d%c%d%c%d",galleon_a,ch,sickle_a,ch,knut_a);
	}
	return 0;
}
