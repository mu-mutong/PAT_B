/*����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������
�����ʽ�������������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ�����
�ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣�
��ɵ��ַ�����
����֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�
�����ʽ��ÿ���������������ռһ�У���������ľ��ӡ�
����������
Hello World Here I Come
���������
Come I Here World Hello*/
#include<stdio.h>
#include<stdlib.h>
typedef struct word{
	char data[80];
	struct word *next;
}word,*words;
int main(){
	char ch;
	words L,q;
	L=(words)malloc(sizeof(word));
	L->next=NULL;
	while(ch!='\n'){
		words p;
		p=(words)malloc(sizeof(word));
		scanf("%s",&p->data);
		p->next=L->next;
		L->next=p;
		scanf("%c",&ch);
	}
	q=L->next;
	while(q->next){
		printf("%s",q->data);
		printf(" ");
		q=q->next;
	}
		printf("%s\n",q->data);
	return 0;
}
