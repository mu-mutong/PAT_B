/*

1080. MOOC期终成绩 (25)

对于在中国大学MOOC（http://www.icourse163.org/）学习
“数据结构”课程的学生，想要获得一张合格证书，
必须首先获得不少于200分的在线编程作业分，
然后总评获得不少于60分（满分100）。
总评成绩的计算公式为 G = (G期中x 40% + G期末x 60%)，
如果 G期中 > G期末；否则总评 G 就是 G期末。
这里 G期中 和 G期末 分别为学生的期中和期末成绩。 
现在的问题是，每次考试都产生一张独立的成绩单。
本题就请你编写程序，把不同的成绩单合为一张。 
输入格式： 
输入在第一行给出3个整数，
分别是 P（做了在线编程作业的学生数）、
M（参加了期中考试的学生数）、N（参加了期末考试的学生数）。
每个数都不超过10000。 
接下来有三块输入。
第一块包含 P 个在线编程成绩 G编程；
第二块包含 M 个期中考试成绩 G期中；
第三块包含 N 个期末考试成绩 G期末。
每个成绩占一行，格式为：学生学号 分数。
其中学生学号为不超过20个字符的英文字母和数字；
分数是非负整数（编程总分最高为900分，期中和期末的最高分为100分）。
 
输出格式： 
打印出获得合格证书的学生名单。每个学生占一行，格式为： 
学生学号 G编程 G期中 G期末 G 
如果有的成绩不存在（例如某人没参加期中考试），
则在相应的位置输出“-1”。
输出顺序为按照总评分数（四舍五入精确到整数）递减。
若有并列，则按学号递增。题目保证学号没有重复，
且至少存在1个合格的学生。 
输入样例：
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 60
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 61
missing 99
dx86w 81
输出样例：
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84

10 0 0
a 1
f 1
d 1
c 1
e 1
g 1
i 1
b 1
h 1
j 1

*/
#include<iostream>
#include<string>
#include<map>
#include<set>

using namespace std;
struct student{
	string name;
	int score;
}; 
struct Rule{
	bool operator()(const student &s1,const student &s2){
		if(s1.score!=s2.score){
			return s1.score>s2.score;
		}else{
			return s1.name<s2.name;
		}
	}
};
student Stu;
typedef map<string,int> MP;
typedef map<string,int>::iterator IT;
typedef set<student,Rule>::iterator SE;
int main(){
	set<student,Rule> st;
	int p,m,n;
	int i=0;
	IT j;
	SE k;
	MP MP_p,MP_m,MP_n;
	cin>>p>>m>>n;
	for(i=0;i<p;i++){
		cin>>Stu.name>>Stu.score;
		MP_p.insert(make_pair(Stu.name,Stu.score));
	}
	for(i=0;i<m;i++){
		cin>>Stu.name>>Stu.score;
		MP_m.insert(make_pair(Stu.name,Stu.score));
	}
	for(i=0;i<n;i++){
		cin>>Stu.name>>Stu.score;
		MP_n.insert(make_pair(Stu.name,Stu.score));
	}
	for(j=MP_p.begin();j!=MP_p.end();j++){
		if(j->second>=200){
			IT M,N;
			student s;
			M=MP_m.find(j->first);
			N=MP_n.find(j->first);
			if(N!=MP_n.end()){
				if(M->second>N->second&&M!=MP_m.end()){
					int sum=(int)(M->second*0.4+N->second*0.6+0.5);
					s.name=j->first;
					s.score=sum;
				}else{
					s.name=j->first;
					s.score=N->second;
				}	
			}
			if(s.score>=60){
				st.insert(s);
			}
		}else{
			continue;
		}
	}
	for(k=st.begin();k!=st.end();k++){
		IT M,N;
		cout<<k->name<<" ";
		cout<<MP_p[k->name]<<" ";
		M=MP_m.find(k->name);
		if(M!=MP_m.end()){
			cout<<M->second<<" ";
		}else{
			cout<<"-1"<<" ";
		}
		cout<<MP_n[k->name]<<" ";
		cout<<k->score<<endl;
	}
	return 0;
}
