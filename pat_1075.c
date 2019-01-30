/*
1075. 链表元素分类(25)

给定一个单链表，请编写程序将链表元素进行分类排列，
使得所有负值元素都排在非负值元素的前面，
而[0, K]区间内的元素都排在大于K的元素前面。
但每一类内部元素的顺序是不能改变的。
例如：给定链表为 18→7→-4→0→5→-6→10→11→-2，
K为10，则输出应该为 -4→-6→-2→7→0→5→10→18→11。
输入格式： 
每个输入包含1个测试用例。
每个测试用例第1行给出：第1个结点的地址；
结点总个数，即正整数N (<= 105)；
以及正整数K (<=1000)。
结点的地址是5位非负整数，NULL地址用-1表示。
接下来有N行，每行格式为：
Address Data Next
其中Address是结点地址；
Data是该结点保存的数据，为[-105, 105]区间内的整数；
Next是下一结点的地址。题目保证给出的链表不为空。
输出格式： 
对每个测试用例，
按链表从头到尾的顺序输出重排后的结果链表，
其上每个结点占一行，格式与输入相同。
输入样例：
00100 9 10
23333 -10 27777
00000 -1 99999
00100 -18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 -5 68237
27777 -11 48652
12309 -7 33218
输出样例：
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1

*/

#include<stdio.h>
int main(){
	int a1[100000],next_add[100000],a2[100000],a3[100000];
	int first=0,N=0,K=0,i=0,flag=0;
	//int add1=-1,add2=-1,add3=-1;
	int begin=0;
	for(i=0;i<100000;i++){
		a1[i]=0;
		next_add[i]=0;
		a2[i]=0;
		a3[i]=0;
	}
	scanf("%d %d %d",&begin,&N,&K);
	for(i=0;i<N;i++){
		int key=0;
		scanf("%d",&key);
		scanf("%d %d",&a1[key],&next_add[key]);
	}
	first=begin; 
	while(first!=-1){
		if(a1[first]<0){
			if(flag==0){
				printf("%05d %d ",first,a1[first]);
				flag++;
			} 
			else{
				printf("%05d\n%05d %d ",first,first,a1[first]);
			}
		}
		first=next_add[first];
	}
	first=begin;
	while(first!=-1){
		if(a1[first]>=0&&a1[first]<=K){
			if(flag==0){
				printf("%05d %d ",first,a1[first]);
				flag++;
			} 
			else{
				printf("%05d\n%05d %d ",first,first,a1[first]);
			}
			
		}
		first=next_add[first];
	}
	first=begin;
	while(first!=-1){
		if(a1[first]>K){
			if(flag==0){
				printf("%05d %d ",first,a1[first]);
				flag++;
			} 
			else{
				printf("%05d\n%05d %d ",first,first,a1[first]);
			}
			
		}
		first=next_add[first];
	}
/*	for(i=0;i<100000&&flag<N;i++){
		/*if(a2[i]){
			if(flag==0){
				printf("%05d %d ",i,a2[i]);
				flag++;
			} 
			else if(flag<N){
				printf("%05d\n%05d %d ",i,i,a2[i]);
				flag++;
			}
		
		}
		if(a1[first]<=K){
			
			a3[first]=a1[first];
			a1[first]=0;
	}
	for(i=0;i<100000&&flag<N;i++){
		if(a3[i]){
			if(flag==0){
				printf("%05d %d ",i,a3[i]);
				flag++;
			} 
			else if(flag<N){
				printf("%05d\n%05d %d ",i,i,a3[i]);
				flag++;
			}
		
		}
	}
	for(i=0;i<100000&&flag<N;i++){
		if(a1[i]){
			if(flag==0){
				printf("%05d %d ",i,a1[i]);
				flag++;
			} 
			else if(flag<N){
				printf("%05d\n%05d %d ",i,i,a1[i]);
				flag++;
			}
		
		}
	}*/
	printf("-1");
	return 0;
}
