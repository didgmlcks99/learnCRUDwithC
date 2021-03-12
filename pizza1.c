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

        printf("메뉴명은? ");
        scanf("%[^\n]%*c", &m->name);

        printf("메뉴종류(P/S/R)? ");
        scanf("%c", &m->type);
        
        printf("가격은? ");
        scanf("%d", &m->price);

        m->flag = 1;

        printf("=> 성공적으로 추가 하였습니다.\n");

        return 1;
    }else{
        printf("=> 이미 한 메뉴가 있습니다.\n");
        return 1;
    }
    return 1;
}

void readMenu(Menu m){
    printf("%d %c %s\n", m.price, m.type, m.name);
}

int updateMenu(Menu *m){
    if(m->flag == 0){
        printf("=> 수정 할 데이터가 없습니다.\n");
        return 1;
    }else{
        int c;
        /* discard all characters up to and including newline */
        while ((c = getchar()) != '\n' && c != EOF); 

        printf("새 메뉴명은? ");
        scanf("%[^\n]%*c", &m->name);

        printf("새 메뉴종류(P/S/R)? ");
        scanf("%c", &m->type);

        printf("새 가격은? ");
        scanf("%d", &m->price);

        m->flag = 1;

        printf("=> 수정성공!\n");
        return 1;
    }
    return 1;
}

int deleteMenu(Menu *m){
    if(m->flag == 0){
        printf("=> 삭제할 데이터가 없습니다.\n");
        return 1;
    }else{
        m->flag = 0;
        for(int i=0; i<sizeof(m->name); i++){
            m->name[i] = ' ';
        }
        m->type = ' ';
        m->price = -1;

        printf("=> 삭제됨!\n");
        
        return 1;
    }
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. 메뉴조회\n");
    printf("2. 메뉴추가\n");
    printf("3. 메뉴수정\n");
    printf("4. 메뉴삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
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
                printf("=> 조회 할 데이터가 없습니다.\n");
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
    printf("종료됨!\n");
    return 0;
}