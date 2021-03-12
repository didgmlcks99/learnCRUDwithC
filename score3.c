#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int score[3];
    int sum;
    float avg;
} Score;
 
int addScore(Score *s){
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

    printf("=> ���������� �߰� �Ͽ����ϴ�.\n");

    return 1;
}

void readScore(Score s){
    printf("%s\t%d\t%d\t%d\t%d\t%.1f\n", s.name, s.score[0], s.score[1], s.score[2], s.sum, s.avg);
}

int updateScore(Score *s){
    if(s == NULL){
        printf("=> �� ��ȣ�� �л� ����� �ȵǾ� �ֽ��ϴ�.\n");
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

        printf("=> ��������!\n");
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

void listScore(Score *s[], int index){
    printf("no\tName\tKor\tEng\tMath\tSum\tAvg\n");
    printf("===============================================================\n");
    for(int i=0; i<index; i++){
        if(s[i] == NULL) continue;
        printf("%d\t", i+1);
        readScore(*s[i]);
    }
}

int selectDataNo(Score *s[], int index){
    int no;
    listScore(s, index);
    printf("��ȣ��(���:0) ");
    scanf("%d", &no);
    return no;
}

int main(void){
    Score *s[100];
    for(int i=0; i<100; i++){
        s[i] = NULL;
    }
    int index = 0;
    int count = 0, menu;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0){
                listScore(s, index);
            }else{
                printf("=> ��ȸ �� �����Ͱ� �����ϴ�.\n");
            }
        }
        else if (menu == 2){
            if(count<20){
                s[index] = (Score*)malloc(sizeof(Score));
                count += addScore(s[index++]);
            }else{
                printf("=> 20���� �л� ������ �־� �� �߰� ���մϴ�.\n");
            }
        }
        else if (menu == 3){
            if(count > 0){
                int no = selectDataNo(s, index);
                if(no > 0){
                    updateScore(s[no-1]);
                }else{
                    printf("=> ��� �Ǿ����ϴ�.\n");
                }
            }else{
                printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
            }
        }
        else if (menu == 4){
            if(count > 0){
                int no = selectDataNo(s, index);
                if(no > 0){
                    int delok;
                    printf("������ �����Ͻðڽ��ϱ�?(1: ����) ");
                    scanf("%d", &delok);
                    if(delok == 1){
                        s[no-1] = NULL;
                        printf("������!\n");
                        count--;
                    }else{
                        printf("=> ���� ��� �Ǿ����ϴ�.\n");
                    }
                }else{
                    printf("=> ��� �Ǿ����ϴ�.\n");
                }
            }else{
                printf("=> ������ �����Ͱ� �����ϴ�.\n");
            }
        }
    }
    printf("�����!\n");
    return 0;
}