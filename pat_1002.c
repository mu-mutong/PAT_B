#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	int num=0,b[10],i=0;
	scanf("%s",a);
	// ��a��Ϊһ���ַ������룬��֤��������������ȷ 
	while(a[i]){
	// ��Ϊint�ͽ��мӷ� 
		num+=a[i]-'0';
		i++;
	}
	i=0;
	// �ٰ���ͽ��ÿλ�ֽ���� 
	while(num){
		b[i]=num%10;
		num=num/10;
		i++;
	}
	while(i){
		i--;
	// ������ĿҪ�����ÿһλƴ�� 
		switch(b[i]){
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break;
			case 3:
				printf("san");
				break;
			case 4:
				printf("si");
				break;
			case 5:
				printf("wu");
				break;
			case 6:
				printf("liu");
				break;
			case 7:
				printf("qi");
				break;
			case 8:
				printf("ba");
				break;
			case 9:
				printf("jiu");
				break;
			case 0:
				printf("ling");
				break;
		}
		if(i>0){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
	return 0;
} 
