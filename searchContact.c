#include <stdio.h>
#include <string.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];
int count;


void searchContact() {
    if (count == 0) {
        printf("ͨѶ¼Ϊ�գ�����ϵ�˿ɲ��ҡ�\n");
        return;
    }

    char targetName[NAME_LEN];
    printf("������Ҫ���ҵ���ϵ������: ");
    scanf("%s", targetName);

    int found = 0,i;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, targetName) == 0) {
            found = 1;
            printf("------------------------\n");
            printf("����: %s\n", contacts[i].name);
            printf("��˾: %s\n", contacts[i].company);
            printf("ְλ: %s\n", contacts[i].title);
            printf("�绰: %s\n", contacts[i].phone);
            printf("------------------------\n");
        }
    }

    if (!found) {
        printf("δ�ҵ���Ϊ %s ����ϵ�ˡ�\n", targetName);
    }
}

