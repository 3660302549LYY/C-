#include <stdio.h>
#include <string.h>
#include "contactst.c"  
Contact contacts[MAX_CONTACTS];
int count;  

void modifyContact() {
    count = loadContacts(contacts); 
    displayAll();                    
	
    
    if (count == 0) {
        printf("通讯录为空，没有联系人可修改。\n");
        return;
    }

    char targetName[NAME_LEN];
    printf("请输入要修改的联系人姓名: ");
    scanf("%s", targetName);

    int found = 0, i;
    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, targetName) == 0) {
            found = 1;
            break;  
        }
    }

    if (!found) {
        printf("未找到名为 %s 的联系人，无法修改。\n", targetName);
        return;
    }

    
    int ccc;  
    while (1) {  
        printf("\n联系人管理系统【修改菜单】\n");
        printf("1. 修改公司\n");
        printf("2. 修改职位\n");
        printf("3. 修改电话\n");
        printf("4. 修改所有信息\n");
        printf("0. 退出修改\n");
        printf("请输入选择：");
        scanf("%d", &ccc);

        
        switch (ccc) {
            case 1:  
                printf("请输入新的公司名称: ");
                char newCompany[COMPANY_LEN];
                scanf("%s", newCompany);
                strcpy(contacts[i].company, newCompany);
                printf("联系人公司修改成功。\n");
                saveContacts(contacts, count);  
                break;

            case 2:  
                printf("请输入新的职位: ");
                char newTitle[TITLE_LEN];
                scanf("%s", newTitle);
                strcpy(contacts[i].title, newTitle);
                printf("联系人职位修改成功。\n");
                saveContacts(contacts, count);
                break;

            case 3:  
                printf("请输入新的电话号码: ");
                char newPhone[PHONE_LEN];
                scanf("%s", newPhone);
                strcpy(contacts[i].phone, newPhone);
                printf("联系人电话修改成功。\n");
                saveContacts(contacts, count);
                break;

            case 4: 
                printf("请输入新的公司名称: ");
                char newCompanyAll[COMPANY_LEN];
                scanf("%s", newCompanyAll);
                strcpy(contacts[i].company, newCompanyAll);

                printf("请输入新的职位: ");
                char newTitleAll[TITLE_LEN];
                scanf("%s", newTitleAll);
                strcpy(contacts[i].title, newTitleAll);

                printf("请输入新的电话号码: ");
                char newPhoneAll[PHONE_LEN];
                scanf("%s", newPhoneAll);
                strcpy(contacts[i].phone, newPhoneAll);

                printf("联系人信息已全部修改。\n");
                saveContacts(contacts, count);
                break;

            case 0:  
                printf("退出联系人修改流程。\n");
                return;

            default: 
                printf("无效输入，请重新选择（0-4）\n");
                break;
        }
    }
}
