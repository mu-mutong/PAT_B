/*
1028. �˿��ղ�(20)

ĳ��������˿��ղ飬�õ���ȫ���������ա�������д������
�ҳ��������곤����������ˡ� 
����ȷ��ÿ����������ڶ��ǺϷ��ģ�
����һ���Ǻ���ġ���������֪����û�г���200������ˣ�
��������2014��9��6�գ�
���Գ���200������պ�δ���������ն��ǲ�����ģ�
Ӧ�ñ����˵��� 
�����ʽ�� 
�����ڵ�һ�и���������N��ȡֵ��(0, 105]�����N�У�
ÿ�и���1���˵��������ɲ�����5��Ӣ����ĸ��ɵ��ַ�������
�Լ�����yyyy/mm/dd��������/��/�գ���ʽ���������ա�
��Ŀ��֤���곤�����������û�в��С� 
�����ʽ�� 
��һ����˳�������Ч���յĸ��������곤�˺��������˵�������
����Կո�ָ��� 
����������
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20
���������
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
