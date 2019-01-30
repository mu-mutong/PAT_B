/*
1028. 人口普查(20)

某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，
找出镇上最年长和最年轻的人。 
这里确保每个输入的日期都是合法的，
但不一定是合理的——假设已知镇上没有超过200岁的老人，
而今天是2014年9月6日，
所以超过200岁的生日和未出生的生日都是不合理的，
应该被过滤掉。 
输入格式： 
输入在第一行给出正整数N，取值在(0, 105]；随后N行，
每行给出1个人的姓名（由不超过5个英文字母组成的字符串）、
以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。
题目保证最年长和最年轻的人没有并列。 
输出格式： 
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，
其间以空格分隔。 
输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
输出样例：
3 Tom John
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char name[6];
	int y,m,d;
}node;

int cmp(const void *a,const void *b){
	const struct node *p=a;
	const struct node *q=b;
	
	if(p->y!=q->y){
		return (p->y-q->y);
	}
	else if(p->m!=q->m){
		return (p->m-q->m);
	}
	else{
		return (p->d-q->d);
	}
}


int main(){
	int N=0,Len=0;
	int i=0;
	char ch1,ch2;
	scanf("%d",&N);
	node a[N],b;
	while(N--){
		scanf("%s",&b.name);
		getchar();
		scanf("%d%c%d%c%d",&b.y,&ch1,&b.m,&ch2,&b.d);
		if(b.y>2014||b.y<1814){
			continue;
		}	
		else if(b.y==2014){
			if(b.m>9){
				continue;
			}
			else if(b.m==9){
				if(b.d>6){
					continue;
				}
				else{
					a[i++]=b;
					continue;
				}
			}
			else{
				a[i++]=b;
				continue;
			}
		}
		else if(b.y==1814){
			if(b.m<9){
				continue;
			}
			else if(b.m==9){
				if(b.d<6){
					continue;
				}
				else{
					a[i++]=b;
					continue;
				}
				
			}
			else{
				a[i++]=b;
				continue;
			}
		}
		else{
			a[i++]=b;
			continue;
		}
		
	}
	if(i==0){
		printf("0");
	}
	else{
		qsort(a,i,sizeof(a[0]),cmp);
		printf("%d ",i);
		printf("%s ",a[0].name);
		printf("%s\n",a[i-1].name);
	}

	return 0;
}
