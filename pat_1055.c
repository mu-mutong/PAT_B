/*

1055. ������ (25)

�ļ�����ʱ���κ���Ҫ��
����Ը�����N����K�ŵĶ�������Ŷӹ������£� 
ÿ������ΪN/K������ȡ������
���������ȫ��վ�����һ�ţ� 
���������˵ĸ��Ӷ�����ǰ���κ��˰��� 
ÿ���������վ�м䣨�м�λ��Ϊm/2+1��
����mΪ������������������ȡ������ 
ÿ�����������м���Ϊ�ᣬ����߷�����
���Һ��������վ���м��˵�����
������5�����Ϊ190��188��186��175��170��
�����Ϊ175��188��190��186��170��
�����������������ߣ��������������м��˵��ұߣ��� 
�����������ͬ�������ֵ��ֵ����������С�
���ﱣ֤�������� 
�ָ���һ�������ˣ����д����������ǵĶ��Ρ�
�����ʽ�� 
ÿ���������1������������
ÿ������������1�и�������������N��<=10000����������
��K��<=10���������������N�У�
ÿ�и���һ���˵�����
���������ո񡢳��Ȳ�����8��Ӣ����ĸ��
����ߣ�[30, 300]�����ڵ��������� 
�����ʽ�� 
������յĶ��Ρ���K������������Կո�ָ���
��ĩ�����ж���ո�ע�⣺��������������ߣ�
���ŵ���������Ϸ���ǰ��������·��� 
����������
10 1
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
���������
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John


*/
#include<stdio.h>
#include<string.h>
typedef struct id{
	char name[10];
	int high;
}id;
int cmp ( const void *a , const void *b )
{
	struct id *c = (id *)a;
	struct id *d = (id *)b;
	if(c->high != d->high) 
		return c->high - d->high;
	else 
		return -1*strcmp( c->name ,d->name );

}
int main(){
	int N=0,K=0,i=0,m=0,len=0;
	scanf("%d %d",&N,&K);
	id s[N];
	len=N;
	for(i=0;i<N;i++){
		scanf("%s %d",&s[i].name,&s[i].high);
	}	
	qsort(s,N,sizeof(s[0]),cmp);
	while(K){
		m=N/K+N%K;
		id h[m];
		int j=m-1,l=0;
		int flag=1;
		if(m%2!=0){
			for(i=N-m;i<N;i++){
				if(flag){
					strcpy(h[j].name,s[i].name);
					j--;
					flag=0;
				}
				else{
					strcpy(h[l].name,s[i].name);
					l++;
					flag=1;
				}
			}	
		}
		else{
			flag=0;
			for(i=N-m;i<N;i++){
				if(flag){
					strcpy(h[j].name,s[i].name);
					j--;
					flag=0;
				}
				else{
					strcpy(h[l].name,s[i].name);
					l++;
					flag=1;
				}
			}
		}
		for(i=0;i<m;i++){
			if(i==0){
				printf("%s",h[i].name,h[i].high);
			}
			else{
				printf(" %s",h[i].name,h[i].high);
			}
		}
		printf("\n");
		K--;
		N=N-m;
	}
	return 0;
}
