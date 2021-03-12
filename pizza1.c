#include <stdio.h>

typedef struct{
    char name[20];
    char type;
    int price;
    int flag;
} Menu;
 
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

        printf("=> ���������� �߰� �Ͽ����ϴ�.\n");

        return 1;
    }else{
        printf("=> �̹� �� �޴��� �ֽ��ϴ�.\n");
        return 1;
    }
    return 1;
}

void readMenu(Menu m){
    printf("%d %c %s\n", m.price, m.type, m.name);
}

int updateMenu(Menu *m){
    if(m->flag == 0){
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

        m->flag = 1;

        printf("=> ��������!\n");
        return 1;
    }
    return 1;
}

int deleteMenu(Menu *m){
    if(m->flag == 0){
        printf("=> ������ �����Ͱ� �����ϴ�.\n");
        return 1;
    }else{
        m->flag = 0;
        for(int i=0; i<sizeof(m->name); i++){
            m->name[i] = ' ';
        }
        m->type = ' ';
        m->price = -1;

        printf("=> ������!\n");
        
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

int main(void){
    Menu m;
    m.flag = 0;
    int count = 0, menu;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(m.flag == 0){
                printf("=> ��ȸ �� �����Ͱ� �����ϴ�.\n");
            }else{
                printf("**********************\n%d\t", count);
                readMenu(m);
            }
        }
        else if (menu == 2){
            count = addMenu(&m);
        }
        else if (menu == 3){
            updateMenu(&m);
        }
        else if (menu == 4){
            deleteMenu(&m);
        }
    }
    printf("�����!\n");
    return 0;
}