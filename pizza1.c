#include <stdio.h>
typedef struct{
    char name[20];
    char type;
    int price;
    int flag;
} Menu;
 
int addMenu(Menu *m);
void readMenu(Menu m);
int updateMenu(Menu *m);
int deleteMenu(Menu *m);

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

int main(void){
    Menu m;
    m.flag = 0;
    int count = 0, menu;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            readMenu(m);
        }
        else if (menu == 2){
            if(addMenu(&m) == 1){
                printf("=> ���������� �߰� �Ͽ����ϴ�.\n");
            }else{
                printf("=> �̹� �� �޴��� �ֽ��ϴ�.\n");
            }
        }
        else if (menu == 3){
            if(updateMenu(&m) == 2){
                printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
            }else{
                printf("=> ��������!\n");
            }
        }
        else if (menu == 4){
            if(deleteMenu(&m) == 2){
                printf("=> ������ �����Ͱ� �����ϴ�.\n");
            }else{
                printf("=> ������!\n");
            }
        }
    }
    printf("�����!\n");
    return 0;
}

int addMenu(Menu *m){
    if(m->flag == 0){
        int c;
        /* discard all characters up to and including newline */
        while ((c = getchar()) != '\n' && c != EOF); 

        printf("�޴�����? ");
        scanf("%[^\n]%*c", &m->name);

        printf("�޴�����(P/S/R)? ");
        scanf("%c", &m->type);
        
        printf("������? ");
        scanf("%d", &m->price);

        m->flag = 1;

        return 1;
    }else{
        return 2;
    }
    return 1;
}

void readMenu(Menu m){
    if(m.flag == 0){
        printf("=> ��ȸ �� �����Ͱ� �����ϴ�.\n");
    }else{
        printf("1\t%d %c %s\n", m.price, m.type, m.name);
    }
}

int updateMenu(Menu *m){
    if(m->flag == 0){
        return 2;
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

        m->flag = 1;
    }
}

int deleteMenu(Menu *m){
    if(m->flag == 0){
        return 2;
    }else{
        m->flag = 0;
        for(int i=0; i<sizeof(m->name); i++){
            m->name[i] = ' ';
        }
        m->type = ' ';
        m->price = -1;
        return 1;
    }
    return 1;
}