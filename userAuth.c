/* 
1. ฟังก์ชัน Login user จะใช้ pointer ส่งค่ามาเพื่อที่จะเอาไปเช้คว่าเป้น admin ไหม = Login
2. ฟังก์ชั่น Register pointer เหมือน login = Register
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.route.h"
#define FILENAME_SIZE 1024
#define MAX_LINE 2048


void Login(int *loginOrNot, User *currentUser){

    User user;
    FILE *fp;

    char userName[50];
    char password[50];
    printf("\n----------------------------------------------\n");
    purple();
    printf("       Please Fill UserName And Password\n");
    reset();
    printf("----------------------------------------------\n\n");
    // printf("\n------------- Please Fill UserName And Password ---------------\n\n");

    printf("UserName\t:\t");
    fflush(stdin);
    yellow();
    fgets(userName, 50, stdin);
    reset();
    userName[strlen(userName)-1] = '\0';

    printf("Password\t:\t");
    yellow();
    fgets(password, 50, stdin);
    reset();
    password[strlen(password)-1] = '\0';

    // printf("UserName %s\n",userName);
    // printf("Password %s\n",password);

    fp = fopen("database/User.csv","r");
    char line[1000];
    char *sp;


    while (fgets(line, 1000, fp) != NULL){

        sp = strtok(line, ",");
        strcpy(user.userName, sp);
        
        sp = strtok(NULL, ",");
        strcpy(user.password, sp);
        //Email
        sp = strtok(NULL, ",");
        strcpy(user.email, sp);
        //Phone
        sp = strtok(NULL, ",");
        strcpy(user.phone, sp);
        //Role
        sp = strtok(NULL, ",");
        strcpy(user.role, sp);
        // printf("ThIS IS USER ROLE => %s\n",user.role);
        user.role[strlen(user.role)-1] = 0;

        if(strcmp(user.userName, userName) == 0 && strcmp(user.password, password) == 0){
            // printf("\n----------------------------------------------\n");
            green();
            printf("\n\n\n                 Login SuccessFully\n\n\n");
            reset();
            // printf("----------------------------------------------\n\n");

            strcpy(currentUser->userName, user.userName);
            strcpy(currentUser->email, user.email);
            strcpy(currentUser->phone, user.phone);
            strcpy(currentUser->role, user.role);

            if(strcmp(user.role, "admin") == 0){
                // printf("Role Admin \n");
                *loginOrNot = 2;
                break;
            }
            else if(strcmp(user.role, "user") == 0){
                // printf("Role User \n");
                *loginOrNot = 1;
                break;
            }
        }
        else continue;

    }
    
    return;
    

}

void Register(int *loginOrNot, User *currentUser){
    User user;
    int checkRole;
    FILE *fp;

    fp = fopen("database/User.csv", "a+");
 
    if (fp == NULL){
        printf("Error Opening User.csv\n");
        return;
    }

    // system("cls");
    green();
    printf("\n-------------------\tRegister Page\t-------------------\n");
    reset();

    printf("\nPlease enter your userName:\t");
    yellow();
    fflush(stdin);
    fgets(user.userName,50,stdin);
    reset();
    user.userName[strlen(user.userName)-1] = 0;
    
    printf("\nPlease Enter Your Password:\t");
    yellow();
    fgets(user.password,50,stdin);
    reset();
    user.password[strlen(user.password)-1] = 0;
    
    printf("\nPlease Enter Your Email:\t");
    yellow();
    fgets(user.email,50,stdin);
    reset();
    user.email[strlen(user.email)-1] = 0;

    
    printf("\nPlease Enter Your Phone:\t");
    yellow();
    fgets(user.phone,50,stdin);
    reset();
    user.phone[strlen(user.phone)-1] = 0;

    
    printf("\nPlease Enter Your Role [1 = admin, 0 = user]:\t");
    yellow();
    scanf("%d",&checkRole);
    reset();
    
    if(checkRole == 1){
      strcpy(user.role,"admin");
    }
    else{
      strcpy(user.role,"user");
    }


    printf("\n------------- User Detail ---------------\n");
    printf("UserName  :\t\033[0;33m%s\n",user.userName);
    reset();
    printf("Password  :\t\033[0;33m%s\n",user.password);
    reset();
    printf("Email     :\t\033[0;33m%s\n",user.email);
    reset();
    printf("Phone     :\t\033[0;33m%s\n",user.phone);
    reset();
    printf("Role      :\t\033[0;33m%s\n",user.role);
    reset();
    printf("------------------------------------------\n\n");
    printf("\nDo you want to save the invoice [y/n]:\t");
    char saveBill;
    fflush(stdin);
    yellow();
    scanf("%s",&saveBill);
    reset();

    if(saveBill == 'y'){
        fprintf(fp,
            "%s,%s,%s,%s,%s\n",
            user.userName,
            user.password,
            user.email,
            user.phone,
            user.role
        );

    strcpy(currentUser->userName, user.userName);
    strcpy(currentUser->email, user.email);
    strcpy(currentUser->phone, user.phone);
    strcpy(currentUser->role, user.role);

    if(fwrite != 0){
        printf("\nSuccessfully saved");
    }
    else{
        printf("\nError saving");
    } 
    
    if (ferror(fp)){
      printf("Error writing to file.\n");
      return;
    }
    fclose(fp);

    if(strcmp(user.role, "admin") == 0){
        *loginOrNot = 2;
        return;
    }
    else if(strcmp(user.role, "user") == 0){
        *loginOrNot = 1;
        return;
    }
    else {
        Register(loginOrNot,currentUser);
        return;
    }
    }
    return;

}