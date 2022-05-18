/*
	第3周编程作业 -- 学生成绩简单统计。
写一个程序，读入10名学生的成绩。每个学生的数据，包含一个不带空格的名字（不超过19个字符），以及三门课的成绩，每门课的成绩是1到5的整数。程序要输出如下的一个列表，对每个学生输出他的录入时的序号、名字、三门课的成绩和平均成绩（浮点表示），最后输出每门课的平均成绩（浮点表示）和最低最高成绩。
no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
10      J.Jon   5       4       3       4
        average 3.8     3.4     3.6
        min     2       2       1
        max     5       5       5
因为排版的缘故，你看到的表格也许不够整齐，输出时在所有的输出项之间加\t就可以了。输出格式不是评判的内容。
程序本身并不复杂，只是要求采用结构来表达每个学生的数据，并具有以下代码片段（你的代码中必须含有并使用以下部分）：
	typedef struct {
		char name[20];
		int score[3];
	} Student;
 
	//    输入一个学生的数据
	Student* student_input(Student *pStudent);
	//    输出一个学生的数据，包括平均成绩
	void student_print(const Student *pStudent);
	//    计算一个学生的平均成绩
	double student_average(const Student *pStudent);    
	//    获得学生的一个成绩
	int student_get_score(const Student *pStudent, int index);
注意虽然是开放互评的题目，我们并不鼓励对题目要求做任意的扩展，并不会因为做了扩展，比如实现任意的人数或任一的课程或课程名称等而做加分。有关对这道题目的扩展想法可以在讨论区讨论。
*/

/*************************************************************************
    > File Name: stu_score.c
    > Author: xjhznick
    > Mail: xjhznick@gmail.com 
    > Created Time: 2015年03月22日 星期日 13时00分34秒
  > Description:
 ************************************************************************/
 
#include<stdio.h>
 
typedef struct {
    char name[20];
    int score[3];
} Student;
  
//    输入一个学生的数据
Student* student_input(Student *pStudent);
//    输出一个学生的数据，包括平均成绩
void student_print(const Student *pStudent);
//    计算一个学生的平均成绩
double student_average(const Student *pStudent);    
//    获得学生的一个成绩
int student_get_score(const Student *pStudent, int index);
  
int main(int argc, char *argv[])
{
    Student stu_score[10] = {
        {"K.Weng", 5, 5, 5},
        {"T.Dixon", 4, 3, 2},
        {"V.Chu", 3, 4, 5},
        {"L.Tson", 4, 3, 4},
        {"L.Lee", 3, 4, 3},
        {"I.Young", 4, 2, 5},
        {"K.Hiro", 4, 2, 1},
        {"G.Ping", 4, 4, 4},
        {"H.Gu", 2, 3, 4},
        {"J.Jon", 5, 4, 3}
    };
    Student stu_test;
    int i, j, sum[3], min[3], max[3];
    double average[3];
 
    //输出学生的数据
    printf("no\tname\tscore1\tscore2\tscore3\taverage\n");
    for(i=0; i<10; i++){
        printf("%d\t", i+1);
        student_print(stu_score+i);
    }
 
    for(i=0; i<3; i++){
        average[i] = sum[i] = 0;
        min[i] = max[i] = student_get_score(&stu_score[0], i+1);
        for(j=0; j<10; j++){
            sum[i] += stu_score[j].score[i];
            if(min[i] > stu_score[j].score[i]){
                min[i] = stu_score[j].score[i];
            }
            if(max[i] < stu_score[j].score[i]){
                max[i] = stu_score[j].score[i];
            }
        }
        average[i] = sum[i] / 10.0;
    }
 
    printf("\taverage\t%.1f\t%.1f\t%.1f\n", average[0], average[1], average[2]);
    printf("\tmin\t%d\t%d\t%d\n", min[0], min[1], min[2]);
    printf("\tmax\t%d\t%d\t%d\n", max[0], max[0], max[0]);
 
    //Just test the function student_input()
    student_input(&stu_test);
    printf("\n"
           "\tTest the student_input function\n"
           "no\tname\tscore1\tscore2\tscore3\taverage\n"
          );
    printf("?\t");
    student_print(&stu_test);
     
    return 0;
}
 
void student_print(const Student *pStudent)
{
    printf("%s\t%d\t%d\t%d\t%f\n", pStudent->name, pStudent->score[0],
            pStudent->score[1], pStudent->score[2], student_average(pStudent));
}
double student_average(const Student *pStudent)
{
    return ((double)pStudent->score[0] + pStudent->score[1] + pStudent->score[2])/3.0;
}
int student_get_score(const Student *pStudent, int index)
{
    return pStudent->score[index-1];
}
Student* student_input(Student *pStudent)
{
    printf("Input a student info(name score1 score2 score3):\n");
    scanf("%s %d %d %d", pStudent->name, &pStudent->score[0], &pStudent->score[1], &pStudent->score[2]);
    return pStudent;
}
