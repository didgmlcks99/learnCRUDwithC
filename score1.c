#include <stdio.h>

typedef struct{
    char name[20];
    int score[3];
    int sum;
    float avg;
    int flag;
} Score;
 
int addScore(Score *s){
    if(s->flag == 0){
        printf("이름은? ");
        scanf("%s", s->name);

        printf("국어는? ");
        scanf("%d", &s->score[0]);

        printf("영어는? ");
        scanf("%d", &s->score[1]);

        printf("수학은? ");
        scanf("%d", &s->score[2]);

        s->sum = s->score[0] + s->score[1] + s->score[2];
        s->avg = ((float)s->sum/3);
        s->flag = 1;

        printf("=> 성공적으로 추가 하였습니다.\n");

        return 1;
    }else{
        printf("=> 이미 한 학생의 성적이 있습니다.\n");
        return 1;
    }
    return 1;
}

void readScore(Score s){
    printf("%s\t%d\t%d\t%d\t%d\t%.1f\n", s.name, s.score[0], s.score[1], s.score[2], s.sum, s.avg);
}

int updateScore(Score *s){
    if(s->flag == 0){
        printf("=> 수정 할 데이터가 없습니다.\n");
        return 1;
    }else{
        printf("이름은? ");
        scanf("%s", s->name);

        printf("국어는? ");
        scanf("%d", &s->score[0]);

        printf("영어는? ");
        scanf("%d", &s->score[1]);

        printf("수학은? ");
        scanf("%d", &s->score[2]);

        s->sum = s->score[0] + s->score[1] + s->score[2];
        s->avg = ((float)s->sum/3);
        s->flag = 1;

        printf("=> 수정성공!\n");
        return 1;
    }
    return 1;
}

int deleteScore(Score *s){
    if(s->flag == 0){
        printf("=> 삭제할 데이터가 없습니다.\n");
        return 1;
    }else{
        s->flag = 0;
        for(int i=0; i<sizeof(s->name); i++){
            s->name[i] = ' ';
        }
        for(int i=0; i<sizeof(s->score)/sizeof(int); i++){
            s->score[i] = -1;
        }
        s->sum = -1;
        s->avg = -1.0;

        printf("=> 삭제됨!\n");
        
        return 1;
    }
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Score s;
    s.flag = 0;
    int count = 0, menu;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(s.flag == 0){
                printf("=> 조회 할 데이터가 없습니다.\n");
            }else{
                printf("Name\tKor\tEng\tMath\tSum\tAvg\n");
                readScore(s);
            }
        }
        else if (menu == 2){
            count = addScore(&s);
        }
        else if (menu == 3){
            updateScore(&s);
        }
        else if (menu == 4){
            deleteScore(&s);
        }
    }
    printf("종료됨!\n");
    return 0;
}