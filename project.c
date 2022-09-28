#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>


void entry();
void list();
void search();
void update();
void deleteentry ();

struct employee
{
    char first_name[50];
    char last_name[50];
    //char address[50];
    char gender[15];
    int code;
    char designation[20];
    int exp_year;
    int age;
};

int main()
{
    printf("Helloooo");
    int choice;
    while (choice != 6)
    {

        printf("_________________EMPLOYEE MANAGEMENT SYSTEM________________");
        printf("\n\n\n\n 1.ADD ENTRY\n");
        printf("\n\n\n\n 2.SHOW ENTRY LIST\n");
        printf("\n\n\n\n 3.SEARCH ENTRY\n");
        printf("\n\n\n\n 4.UPDATE ENTRY\n");
        printf("\n\n\n\n 5.DELETE ENTRY\n");
        printf("\n\n\n\n 6.EXIT\n");
        printf("choose any number from 1 to 6 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
           system("cls");
            entry();
      system("cls");
            break;

        case 2:
           system("cls");

            list();
            printf("\t\t\t\t  press any key to exit..... \n");
            getch();
         system("cls");

            break;

        case 3:
            system("cls");
            search();
            printf("\n\t\t\t\t  Press any key to exit.......\n");
            getch();
            system("cls");

            break;
        case 4:
            system("cls");
            update();
            printf("\n\t\t\t\tPress any key to exit.......\n");
            getch();
            system("cls");
            break;

        case 5:
            system("cls");
            deleteentry ();
            printf("\n\t\t\t\tPress any key to exit.......\n");
            getch();
           system("cls");
            break;

        case 6:
           system("cls");
            printf("\n\t\t\t\tThank you!\n\n");
            exit(0);
            break;

        default:
         system("cls");
            //getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
           system("cls");
            //break;
        }
    }

    getch();
}

void entry()
{

    char another;
    FILE *fp;
    int n, i;
    struct employee info;
    do
    {
        system("cls");
        printf("\t\t\t\t=======Add Entry=======\n\n\n");
        fp = fopen("information.txt", "a"); //a

        printf("\n\t\t\tENTER FIRST NAME: ");
        //scanf("%s", info.first_name);
        getchar();
        gets(info.first_name);
        printf("\n\t\t\tENTER LAST NAME: ");
        //scanf("%s", info.last_name);
        gets(info.last_name);
        //printf("\n\t\t\tENTER ADDRESS: ");
        //getchar();
        //gets(info.address);
        printf("\n\t\t\tENTER GENDER: ");
        scanf("%s", &info.gender);
        //gets(info.gender);
        printf("\n\t\t\tENTER CODE: ");
        scanf("%d", &info.code);
        printf("\n\t\t\tENTER DESIGNATION: ");
        //scanf("%s", &info.designation);
        getchar();
        gets(info.designation);
        printf("\n\t\t\tENTER EXPERIENCE YEAR: ");
        scanf("%d", &info.exp_year);
        printf("\n\t\t\tENTER AGE: ");
        scanf("%d", &info.age);
        printf("\n\t\t\t_____________________________________________________\n\n");

        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        }
        else
        {
            printf("\t\t\tEntry stored successfuly\n");
        }

        fwrite(&info, sizeof(info), 1, fp);
        fclose(fp);

        printf("\t\t\tYou want to add another record?(y/n) : ");

        scanf("%s", &another);

    } while (another == 'y' || another == 'Y');
}

void list()
{

    FILE *fp;
    fp = fopen("information.txt", "r");
    struct employee info;

    printf("\t\t\t\t=======EMPLOYEE LIST=======\n\n\n");

    if (fp == NULL)
    {

        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }

    while (fread(&info, sizeof(info), 1, fp)>0)
    {
        printf("\n\t\t\t\t Employee name  : %s %s", info.first_name,info.last_name);
        printf("\n\t\t\t\t Employee gender : %s", info.gender);
        //printf("\n\t\t\t\t Employee address : %s",info.address);
        printf("\n\t\t\t\t Employee code : %d",info.code);
        printf("\n\t\t\t\t Employee designation : %s", info.designation);
        printf("\n\t\t\t\t Employee experience year : %d", info.exp_year);
        printf("\n\t\t\t\t Employee age : %d",info.age);
        printf("\n\t\t\t\t ________________________________\n");
    }
    fclose(fp);
    getch();
}

void search()
{
    struct employee info;
    FILE *fp;
    int yourchoice;

        printf("___________________SEARCH___________________");
        printf("\n\t\t1.Search by name");
        printf("\n\t\t2.search by code");
        printf("\n\t\t Enter between 1 or 2\n");
        scanf("%d",&yourchoice);
        system("cls");
        if(yourchoice==1){
        char firstname[50];
        int found=0;
        fp=fopen("information.txt","r");
        printf("\t\t\t\t=======SEARCH EMPLOYEE=======\n\n\n");
        printf("Enter the first name: ");
        getchar();
        gets(firstname);
         while (fread(&info, sizeof(info), 1, fp) > 0)
         {
             if(strcmp(info.first_name,firstname)==0)
             {
                 found=1;
                 printf("\n\t\t\t\t Employee name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Employee gender : %s", info.gender);
       // printf("\n\t\t\t\t Employee address : %s",info.address);
        printf("\n\t\t\t\t Employee code : %d",info.code);
        printf("\n\t\t\t\t Employee designation : %s", info.designation);
        printf("\n\t\t\t\t Employee experience year : %d", info.exp_year);
        printf("\n\t\t\t\t Employee age : %d",info.age);
        printf("\n\t\t\t\t ________________________________\n");

             }
         }
         if(!found)
         {
             printf("\n\t\t\tRecord not found\n");
         }
         fclose(fp);
    getch();
    system("cls");}



    else if(yourchoice==2){
        system("cls");

    int code, found2 = 0;

    fp = fopen("information.txt", "r");
    printf("\t\t\t\t=======SEARCH EMPLOYEE=======\n\n\n");
    printf("\t\t\tEnter the code : ");

    scanf("%d", &code);

    while (fread(&info, sizeof(info), 1, fp) > 0)
    {

        if (info.code == code)
        {

            found2 = 1;
            printf("\n\t\t\t\t Employee name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Employee gender : %s", info.gender);
       // printf("\n\t\t\t\t Employee address : %s",info.address);
        printf("\n\t\t\t\t Employee code : %d",info.code);
        printf("\n\t\t\t\t Employee designation : %s", info.designation);
        printf("\n\t\t\t\t Employee experience year : %d", info.exp_year);
        printf("\n\t\t\t\t Employee age : %d",info.age);
        printf("\n\t\t\t\t ________________________________\n");
        }
    }

    if (!found2)
    {
        printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
    getch();
    system("cls");
    }

   else{
        system("cls");
        printf("Enter between 1 or 2!");
        printf("\t\t\t\tPress any key to continue.......");
            getch();
        system("cls");
}


}



void update()
{

    struct employee info;
    FILE *fp,*fp1;
    int yourChoice;
        printf("\n\n____________Search for update____________\n\n");
        printf("\n\t\t1.Search by code\n\n");
        printf("\n\t\t2.search by name\n\n");
        printf("\n\t\t Enter between 1 or 2\n");
        scanf("%d",&yourChoice);
        if (yourChoice==1){
        system("cls");
    int code, found = 0;
    fp = fopen("information.txt", "r");
    fp1= fopen("temp.txt","w");
    printf("\t\t\t\t=======UPDATE ENTRY=======\n\n\n");
    printf("\t\t\tEnter the code to update : ");

    scanf("%d", &code);

    while (fread(&info, sizeof(info), 1, fp) > 0)
    {

        if (info.code == code)
        {
            found = 1;

            //showing entry
            printf("\n\t\t\t\t Employee name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Employee gender : %s", info.gender);
        //printf("\n\t\t\t\t Employee address : %s",info.address);
        printf("\n\t\t\t\t Employee code : %d",info.code);
        printf("\n\t\t\t\t Employee designation : %s", info.designation);
        printf("\n\t\t\t\t Employee experience year : %d", info.exp_year);
        printf("\n\t\t\t\t Employee age : %d",info.age);
        printf("\n\t\t\t\t ________________________________\n");

        //updating entries
        printf("\n\t\t\tNEW UPDATE:\n");
            printf("\n\t\t\tENTER NEW FIRST NAME: ");
        //scanf("%s", info.first_name);
        getchar();
        gets(info.first_name);
        printf("\n\t\t\tENTER NEW LAST NAME: ");
        //scanf("%s", info.last_name);
        gets(info.last_name);


        printf("\n\t\t\tENTER NEW GENDER: ");
        scanf("%s", &info.gender);
        printf("\n\t\t\tENTER NEW CODE: ");
        scanf("%d", &info.code);
        printf("\n\t\t\tENTER NEW DESIGNATION: ");
        //scanf("%s", &info.designation);
        getchar();
        gets(info.designation);
        printf("\n\t\t\tENTER NEW EXPERIENCE YEAR: ");
        scanf("%d", &info.exp_year);
        printf("\n\t\t\tENTER NEW AGE: ");
        scanf("%d", &info.age);
        printf("\n\t\t\t_____________________________________________________\n\n");

    }
    fwrite(&info,sizeof(info),1,fp1);
    }
    fclose(fp);
    fclose(fp1);

    if (found)
    {
        fp1=fopen("temp.txt","r");
        fp=fopen("information.txt","w");

        while(fread(&info,sizeof(info),1,fp1))
        {
            fwrite(&info,sizeof(info),1,fp);
        }
        fclose(fp);
        fclose(fp1);
        }
        else
    {
        printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
    getch();
    system("cls");
        }


      else if(yourChoice==2){
        system("cls");
        char first[50];
        int found2=0;
        fp = fopen("information.txt", "r");
    fp1= fopen("temp.txt","w");
    printf("\t\t\t\t=======UPDATE ENTRY=======\n\n\n");
    printf("\t\t\tEnter the first name to update : ");
    //getchar();
    getchar();
    gets(first);
    while (fread(&info, sizeof(info), 1, fp) > 0)
         {
             if(strcmp(info.first_name,first)==0)
             {
                 found2=1;
                 printf("\n\t\t\t\t Employee name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Employee gender : %s", info.gender);
        //printf("\n\t\t\t\t Employee address : %s",info.address);
        printf("\n\t\t\t\t Employee code : %d",info.code);
        printf("\n\t\t\t\t Employee designation : %s", info.designation);
        printf("\n\t\t\t\t Employee experience year : %d", info.exp_year);
        printf("\n\t\t\t\t Employee age : %d",info.age);
        printf("\n\t\t\t\t ________________________________\n");

        //updating entries
        printf("\n\t\t\tNEW UPDATE:\n");
            printf("\n\t\t\tENTER NEW FIRST NAME: ");
        //scanf("%s", info.first_name);

        //getchar();
        gets(info.first_name);
        getchar();
        printf("\n\t\t\tENTER NEW LAST NAME: ");
        //scanf("%s", info.last_name);
        gets(info.last_name);

       // printf("\n\t\t\tENTER NEW ADDRESS: ");
        //getchar();
        //gets(info.address);
        printf("\n\t\t\tENTER NEW GENDER: ");
        scanf("%s", &info.gender);
        printf("\n\t\t\tENTER NEW CODE: ");
        scanf("%d", &info.code);
        printf("\n\t\t\tENTER NEW DESIGNATION: ");
        //scanf("%s", &info.designation);
        getchar();
        gets(info.designation);
        printf("\n\t\t\tENTER NEW EXPERIENCE YEAR: ");
        scanf("%d", &info.exp_year);
        printf("\n\t\t\tENTER NEW AGE: ");
        scanf("%d", &info.age);
        printf("\n\t\t\t_____________________________________________________\n\n");

    }
    fwrite(&info,sizeof(info),1,fp1);
    }
    fclose(fp);
    fclose(fp1);

    if (found2)
    {
        fp1=fopen("temp.txt","r");
        fp=fopen("information.txt","w");

        while(fread(&info,sizeof(info),1,fp1))
        {
            fwrite(&info,sizeof(info),1,fp);
        }
        fclose(fp);
        fclose(fp1);
        }
        else
    {
        printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
    getch();
    system("cls");
      }
else{
        system("cls");
        printf("Enter between 1 or 2!");
        printf("\t\t\t\tPress any key to continue.......");
            getch();
        system("cls");
}

}

void deleteentry ()
{
    struct employee info;
    FILE *fp, *fp1;

    int code, found = 0;

    printf("\t\t\t\t=======DELETE EMPLOYEE RECORD=======\n\n\n");
    fp = fopen("information.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\t\t\t\tEnter the code : ");
    scanf("%d", &code);
    if (fp == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    }

    while (fread(&info, sizeof(info), 1, fp))
    {
        if (info.code == code)
        {

            found = 1;
        }
        else
        {
            fwrite(&info, sizeof(info), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (!found)
    {
        printf("\n\t\t\t\tRecord not found\n");
    }
    if (found)
    {
        remove("information.txt");
        rename("temp.txt", "information.txt");

        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }

    getch();
}




