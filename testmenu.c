#include <stdio.h>

typedef void (*menufunctionptr)();

void menu1();
void menu2();
void menu3();

typedef struct menuitem {
    const char* label;
    menufunctionptr functionptr;
} menuitem;

menuitem menuitems[] = {
    {"menu1", menu1},
    {"menu2", menu2},
    {"menu3", menu3},
};

typedef void (*schedulerfunctionptr)(int);

void simplescheduler(schedulerfunctionptr functionptr, int delay) {
    while (1) {
        functionptr(delay);
    }
}

void menu1() {
    printf("menu1\n");
}

void menu2() {
    printf("menu2\n");
}

void menu3() {
    printf("menu3\n");
}

int main() 
{
    printf("make a selection:\n");
    for (int i = 0; i < sizeof(menuitems) / sizeof(menuitems[0]); i++) {
        printf("%d. %s\n", i + 1, menuitems[i].label);
    }

    int userinput = 0;
    scanf("%d", &userinput);

    if (userinput >= 1 && userinput <= sizeof(menuItems) / sizeof(menuitems[0])) {
        menuitem item = menuitems[userinput - 1];
        item.functionptr();
    } else {
        printf("invalid input\n");
    }

    simplescheduler(menu1, 100);
    simplescheduler(menu2, 200);
    simplescheduler(menu3, 300);

    return 0;
}
