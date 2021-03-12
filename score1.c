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
        printf("�̸���? ");
        scanf("%s", s->name);

        printf("�����? ");
        scanf("%d", &s->score[0]);

        printf("�����? ");
        scanf("%d", &s->score[1]);

        printf("������? ");
        scanf("%d", &s->score[2]);

        s->sum = s->score[0] + s->score[1] + s->score[2];
        s->avg = ((float)s->sum/3);
        s->flag = 1;

        printf("=> ���������� �߰� �Ͽ����ϴ�.\n");

        return 1;
    }else{
        printf("=> �̹� �� �л��� ������ �ֽ��ϴ�.\n");
        return 1;
    }
    return 1;
}

void readScore(Score s){
    printf("%s\t%d\t%d\t%d\t%d\t%.1f\n", s.name, s.score[0], s.score[1], s.score[2], s.sum, s.avg);
}

int updateScore(Score *s){
    if(s->flag == 0){
        printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
        return 1;
    }else{
        printf("�̸���? ");
        scanf("%s", s->name);

        printf("�����? ");
        scanf("%d", &s->score[0]);

        printf("�����? ");
        scanf("%d", &s->score[1]);

        printf("������? ");
        scanf("%d", &s->score[2]);

        s->sum = s->score[0] + s->score[1] + s->score[2];
        s->avg = ((float)s->sum/3);
        s->flag = 1;

        printf("=> ��������!\n");
        return 1;
    }
    return 1;
}

int deleteScore(Score *s){
    if(s->flag == 0){
        printf("=> ������ �����Ͱ� �����ϴ�.\n");
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

        printf("=> ������!\n");
        
        return 1;
    }
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
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
                printf("=> ��ȸ �� �����Ͱ� �����ϴ�.\n");
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
    printf("�����!\n");
    return 0;
}