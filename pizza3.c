#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    char type;
    int price;
} Menu;
 
int addMenu(Menu *m){
    int c;
    /* discard all characters up to and including newline */
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("�޴�����? ");
    scanf("%[^\n]%*c", &m->name);

    printf("�޴�����(P/S/R)? ");
    scanf("%c", &m->type);
    
    printf("������? ");
    scanf("%d", &m->price);

    printf("=> ���������� �߰� �Ͽ����ϴ�.\n");

    return 1;
}

void readMenu(Menu m){
    printf("%d %c %s\n", m.price, m.type, m.name);
}

int updateMenu(Menu *m){
    if(m == NULL){
        printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
        return 1;
    }else{
        int c;
        /* discard all characters up to and including newline */
        while ((c = getchar()) != '\n' && c != EOF); 

        printf("�� �޴�����? ");
        scanf("%[^\n]%*c", &m->name);

        printf("�� �޴�����(P/S/R)? ");
        scanf("%c", &m->type);

        printf("�� ������? ");
        scanf("%d", &m->price);

        printf("=> ��������!\n");
        return 1;
    }
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. �޴���ȸ\n");
    printf("2. �޴��߰�\n");
    printf("3. �޴�����\n");
    printf("4. �޴�����\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

void listMenu(Menu *m[], int index){
    printf("**********************\n");
    for(int i=0; i<index; i++){
        if(m[i] == NULL) continue;
        printf("%d\t", i+1);
        readMenu(*m[i]);
    }
}

int selectDataNo(Menu *m[], int index){
    int no;
    listMenu(m, index);
    printf("��ȣ��(���:0) ");
    scanf("%d", &no);
    return no;
}

int main(void){
    Menu *m[100];
    int index = 0;
    for(int i=0; i<100; i++){
        m[i] = NULL;
    }
    int count = 0, menu;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0){
                listMenu(m, index);
            }else{
                printf("=> ��ȸ �� �����Ͱ� �����ϴ�.\n");
            }
        }
        else if (menu == 2){
            if(count<20){
                m[index] = (Menu*)malloc(sizeof(Menu));
                count += addMenu(m[index++]);
            }else{
                printf("=> 20���� �޴� ������ �־� �� �߰� �� �� �����ϴ�.\n");
            }
        }
        else if (menu == 3){
            if(count > 0){
                int no = selectDataNo(m, index);
                if(no > 0){
                    updateMenu(m[no-1]);
                }else{
                    printf("=> ��� �Ǿ����ϴ�.\n");
                }
            }else{
                printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
            }
        }
        else if (menu == 4){
            if(count > 0){
                int no = selectDataNo(m, index);
                if(no > 0){
                    int delok;
                    printf("������ �����Ͻðڽ��ϱ�?(1:����) ");
                    scanf("%d", &delok);
                    if(delok == 1){
                        m[no-1] = NULL;
                        printf("������!\n");
                        count--;
                    }else{
                        printf("=> ���� ��� �Ǿ����ϴ�.\n");
                    }
                }else{
                    printf("=> ��� �Ǿ����ϴ�\n");
                }
            }else{
                printf("������ �����Ͱ� �����ϴ�.\n");
            }
        }
    }
    printf("�����!\n");
    return 0;
}