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
