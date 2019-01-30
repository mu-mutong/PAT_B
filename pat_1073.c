/*
1073. 多选题常见计分法(20)

批改多选题是比较麻烦的事情，
有很多不同的计分方法。
有一种最常见的计分方法是：
如果考生选择了部分正确选项，
并且没有选择任何错误选项，
则得到50%分数；如果考生选择了任何一个错误的选项，
则不能得分。本题就请你写个程序帮助老师批改多选题，
并且指出哪道题的哪个选项错的人最多。 
输入格式： 
输入在第一行给出两个正整数N（<=1000）和M（<=100），
分别是学生人数和多选题的个数。
随后M行，每行顺次给出一道题的满分值（不超过5的正整数）
、选项个数（不少于2且不超过5的正整数）、
正确选项个数（不超过选项个数的正整数）、
所有正确选项。
注意每题的选项从小写英文字母a开始顺次排列。
各项间以1个空格分隔。最后N行，
每行给出一个学生的答题情况，
其每题答案格式为“(选中的选项个数 选项1 ……)”，
按题目顺序给出。注意：题目保证学生的答题情况是合法的，
即不存在选中的选项数超过实际选项数的情况。 
输出格式： 
按照输入的顺序给出每个学生的得分，每个分数占一行，
输出小数点后1位。最后输出错得最多的题目选项的信息，
格式为：“错误次数 题目编号
（题目按照输入的顺序从1开始编号）-选项号”。
如果有并列，则每行一个选项，
按题目编号递增顺序输出；
再并列则按选项号递增顺序输出。
行首尾不得有多余空格。如果所有题目都没有人错，
则在最后一行输出“Too simple”。 
输入样例1：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
输出样例1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b
输入样例2：
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
输出样例2：
5.0
5.0
Too simple

*/
#include<stdio.h>
int main(){
	int N=0,M=0,i=0,j=0,num1=0,num2=0,k=0,max=0;
	char s1;
	scanf("%d %d",&N,&M);
	double Score[N];
	int Wrong[M][5],stu[5]; 
	int ans[M][8];
	for(i=0;i<N;i++){
		Score[i]=0;
	} 
	for(i=0;i<M;i++){
		for(j=0;j<8;j++){
			ans[i][j]=0;
			if(j<5){
			Wrong[i][j]=0;
			} 
		}
	}
	for(j=0;j<5;j++){
		stu[j]=0;
	}
	for(i=0;i<M;i++){
	// 输入每到选择题的 满分值，选项个数，正确选项个数// 
		scanf("%d %d %d",&ans[i][5],&ans[i][6],&ans[i][7]);
		getchar();
		for(j=0;j<ans[i][7];j++){
			char t;
			scanf("%c",&t);
			getchar();
			ans[i][t-'a']++; 
		}
	}
	for(i=0;i<N;i++){
		
		while(1){
			s1=getchar();
			if(s1=='\n'){
				k=0;
				break;
			}
			if(s1==' '){
				continue;
			}
			if(s1==')'){
				for(j=0;j<5;j++){
					if(stu[j]==1&&ans[k][j]==1){
					
						num1--;
						num2--;
						continue;
					}else if(stu[j]==1&&ans[k][j]==0){
						Wrong[k][j]++;
						
					}else if(stu[j]==0&&ans[k][j]==1){
						Wrong[k][j]++;
					}
					if(Wrong[k][j]>max){
						max=Wrong[k][j];
					} 
				}
				if(num1==0&&num2==0){
					Score[i]+=ans[k][5];
				
				}else if(num1==0&&num2!=0){
					Score[i]+=ans[k][5]/2.0;
				}
				for(j=0;j<5;j++){
					stu[j]=0;
				}
				k++;
				num1=0;
				num2=0;
				continue;
			}
			if(s1>='0'&&s1<='9'){
				num1=s1-'0';
				num2=ans[k][7];
			
				continue;
			}
			if(s1>='a'&&s1<='e'){
				stu[s1-'a']=1;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%0.1lf\n",Score[i]);
	}
	if(max==0){
		printf("Too simple\n");
	}
	else{
		for(i=0;i<M;i++){
			for(j=0;j<5;j++){
				if(Wrong[i][j]==max){
					printf("%d %d-%c\n",max,i+1,j+'a');
				}
			}
		}
	}
	return 0;
}
	 
