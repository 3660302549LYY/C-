#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contactst.c"

Contact contacts[MAX_CONTACTS];  // ͨѶ¼����
int count = 0;                   // ��ǰ��ϵ������

// ��������
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
    // ������ϵ��
    count = loadContacts(contacts);

    int choice;
    system("cls");  // ����
    printf("\n========== ��ӭʹ��ͨѶ¼����ϵͳ ==========\n");

    while (1) {
        printMenu();
        printf("\n������ѡ��(1-6): ");
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
                // ������ϵ��
                saveContacts(contacts, count);
                printf("\n��лʹ�ã��ټ�\n");
                return 0;
            default:
                printf("��Ч���룬������ѡ��\n");
        }
        printf("\n�����������...");
        getchar();
        getchar();
        system("cls");
    }
    return 0;
}

