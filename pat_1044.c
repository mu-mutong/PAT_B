/*

1044. ��������(20)

����������13���Ƽ����ģ�
�����˵�0�������˳�Ϊtret�� 
����������1��12�Ļ����ķֱ�Ϊ��
jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec�� 
�����˽���λ�Ժ��12����λ���ֱַ��Ϊ��tam, hel, maa, huh,
 tou, kes, hei, elo, syy, lok, mer, jou�� 
��������˵����֡�29������ɻ����ľ��ǡ�hel mar����
�������ġ�elo nov����Ӧ�������֡�115����
Ϊ�˷��㽻���������д����ʵ�ֵ���ͻ�������֮��Ļ��롣 
�����ʽ�� 
�����һ�и���һ��������N��<100�������N�У�
ÿ�и���һ��[0, 169)�����ڵ����� ���� �����ǵ����ģ�
�����ǻ����ġ� 
�����ʽ�� 
��Ӧ�����ÿһ�У���һ���������������һ�����Ե����֡�
����������
4
29
5
elo nov
tam
���������
hel mar
may
115
13
strlen(s1)<=3
*/

#include<stdio.h>
#include<string.h>
int main(){
	char a[13][5]={"tret","jan","feb","mar","apr","may","jun"
	,"jly","aug","sep","oct","nov","dec"};
	char b[12][5]={"tam","hel","maa","huh","tou","kes"
	,"hei","elo","syy","lok","mer","jou"};
	char s1[10];
	int num=0,n=0,i=0,j=0,c[3]={0};
	scanf("%d",&n);
	getchar();
	for(j=0;j<n;j++){
		gets(s1);
		for(i=0;i<3;i++){
				c[i]=0;
			}
		num=0;
		i=0;
		if(s1[0]>='0'&&s1[0]<='9'){
			while(s1[i]){
				num=s1[i]-'0'+num*10;
				i++;
			}
			i=0;
			while(num){
				c[i++]=num%13;
				num/=13;
			}
			i-=1;
			if(i>0){
				printf("%s",b[c[i]-1]);
				i--;
				if(c[i]){
					printf(" %s",a[c[i]]);
				}
			}
			else{
				if(c[i])
					printf("%s",a[c[i]]);
				else
					printf("tret");
			}
			printf("\n");
			continue;
		}
		else{
			if(strlen(s1)==4){
				printf("0");
			}
			else if(strlen(s1)==3){
				for(i=1;i<13;i++){
					if(strcmp(s1,a[i])==0){
						printf("%d",i);
					}
				}
				for(i=0;i<12;i++){
					if(strcmp(s1,b[i])==0){
						printf("%d",(i+1)*13);
					}
				}
			}
			else{
				char s2[5];
				int k=4;
				while(s1[k]){
					s2[k-4]=s1[k];
					k++;
				}
				k=k-4;
				s1[3]='\0';
				s2[k]='\0';
				for(i=0;i<12;i++){
					if(strcmp(s1,b[i])==0){
						num=(i+1)*13;
					}
				}
				for(i=0;i<13;i++){
					if(strcmp(s2,a[i])==0){
						num+=i;
					}
				}
				printf("%d",num);
			}
			printf("\n");
		}
	}
	return 0;
}
