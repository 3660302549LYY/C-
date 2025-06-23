#include <stdio.h>
#include <stdlib.h>
#include "contactst.c"
/*
void saveContacts(Contact contacts[], int count) {
    FILE *fp = fopen(CONTACTS_FILE, "wb");
    if (fp == NULL) {
        perror("无法打开文件保存联系人");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(contacts, sizeof(Contact), count, fp);
    fclose(fp);
}


int loadContacts(Contact contacts[]) {
    FILE *fp = fopen(CONTACTS_FILE, "rb");
    if (fp == NULL) {
        return 0;
    }
    int count;
    fread(&count, sizeof(int), 1, fp);
    fread(contacts, sizeof(Contact), count, fp);
    fclose(fp);
    return count;
}
*/

// 保存联系人到文本文件
void saveContacts(Contact contacts[], int count) {
    FILE *fp = fopen(CONTACTS_FILE, "w");
    if (fp == NULL) {
        perror("无法打开文件保存联系人");
        return;
    }
    int i;
    // 写入联系人数量
    fprintf(fp, "%d\n", count);
    
    // 循环写入每个联系人信息
    for (i = 0; i < count; i++) {
        // 使用逗号分隔字段，换行分隔记录
        fprintf(fp, "%s,%s,%s,%s\n", 
                contacts[i].name, 
                contacts[i].company, 
                contacts[i].title, 
                contacts[i].phone);
    }
    
    fclose(fp);
}

// 从文本文件加载联系人
int loadContacts(Contact contacts[]) {
	int ii;
    FILE *fp = fopen(CONTACTS_FILE, "r");
    if (fp == NULL) {
        // 文件不存在，返回0个联系人
        return 0;
    }
    
    int count;
    // 读取联系人数量
    fscanf(fp, "%d\n", &count);
    
    // 确保不超过最大容量
    if (count > MAX_CONTACTS) {
        count = MAX_CONTACTS;
    }
    
    // 循环读取每个联系人信息
    for (ii = 0; ii < count; ii++) {
        // 读取一行数据，格式为 "name,company,title,phone"
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", 
               contacts[ii].name, 
               contacts[ii].company, 
               contacts[ii].title, 
               contacts[ii].phone);
    }
    
    fclose(fp);
    return count;
}    
