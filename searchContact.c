#include <stdio.h>
#include <string.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];
int count;


void searchContact() {
    if (count == 0) {
        printf("通讯录为空，无联系人可查找。\n");
        return;
    }

    char targetName[NAME_LEN];
    printf("请输入要查找的联系人姓名: ");
    scanf("%s", targetName);

    int found = 0,i;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, targetName) == 0) {
            found = 1;
            printf("------------------------\n");
            printf("姓名: %s\n", contacts[i].name);
            printf("公司: %s\n", contacts[i].company);
            printf("职位: %s\n", contacts[i].title);
            printf("电话: %s\n", contacts[i].phone);
            printf("------------------------\n");
        }
    }

    if (!found) {
        printf("未找到名为 %s 的联系人。\n", targetName);
    }
}

