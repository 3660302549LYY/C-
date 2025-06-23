#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];  // 通讯录数组
int count = 0;                   // 当前联系人数量

// 函数声明
void printMenu();
void addContact();
void displayAll();
void deleteContact();
void searchContact();
void ph();
void modifyContact();
int loadContacts();
void saveContacts();

int main() {
    // 加载联系人
    count = loadContacts(contacts);

    int choice;
    system("cls");  // 清屏
    printf("\n========== 欢迎使用通讯录管理系统 ==========\n");

    while (1) {
        printMenu();
        printf("\n请输入选择(1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                deleteContact();
                break;
            case 4:
                searchContact();
                break;
            case 5:
                modifyContact();
                break;
            case 6:
                // 保存联系人
                saveContacts(contacts, count);
                printf("\n感谢使用，再见\n");
                return 0;
            default:
                printf("无效输入，请重新选择\n");
        }
        printf("\n按任意键继续...");
        getchar();
        getchar();
        system("cls");
    }
    return 0;
}

