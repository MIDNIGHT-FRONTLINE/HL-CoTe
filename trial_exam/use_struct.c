#include <stdio.h>
#define MAX 5

typedef struct{
    char name[20];
    int score[MAX];
    float average;
} STUDENT;

void findAverage(STUDENT *s){
    int sum = 0;
    for (int i = 0; i < MAX; i++){
        sum += s->score[i];
    }
    s->average = sum / (float)MAX;
}

int main(){
    STUDENT students[MAX];
    int stu_num = 0;

    printf("학생 수 입력: ");
    scanf("%d", &stu_num);

    if (stu_num > MAX){
        stu_num = MAX;
    }

    for (int i = 0; i < stu_num; i++){
        printf("%d ", i + 1);
        printf("name: ");
        scanf("%s", students[i].name);
        printf("\nscore\n");
        for (int j = 0; j < MAX; j++){
            printf("%d / MAX : ", j + 1);
            scanf("%d", &students[i].score[j]);
        }
        findAverage(&students[i]);
    }
    int high = 0;
    for (int i = 0; i < stu_num; i++){
        if(students[i].average > students[high].average){
            high = i;
        }
    }

    printf("\n");
    printf("highest: %s\n", students[high].name);
    for (int i = 0; i < MAX; i++){
        printf("%d score: %d\n", i + 1, students[high].score[i]);
    }
    printf("average: %.2f\n", students[high].average);

    return 0;
}