#include<stdio.h>
#include<string.h>
typedef struct{
	char name[11];
	char number[11];
	int point;
}list;
int main(){
	int n,i;
	list min,max;
	scanf("%d",&n);
	list cla[n];
	for(i=0;i<n;i++){
		scanf("%s",&cla[i].name);
		scanf("%s",&cla[i].number);
		scanf("%d",&cla[i].point);
	}
	// 把记录最大和最小的结构体初始化为两个不可能出现的值(假设输入没有问题 
	min.point=101;
	max.point=-1;
	// 从头开始遍历，找出最大和最小的数。 
	for(i=0;i<n;i++){
		if(cla[i].point<min.point){
			strcpy(min.name,cla[i].name);
			strcpy(min.number,cla[i].number);
			min.point=cla[i].point;
		}
		if(cla[i].point>max.point){
			strcpy(max.name,cla[i].name);
			strcpy(max.number,cla[i].number);
			max.point=cla[i].point;
		}
	}
	printf("%s",max.name);
	printf(" ");
	printf("%s\n",max.number);
	 
	printf("%s",min.name);
	printf(" ");
	printf("%s\n",min.number);
	return 0;
} 
