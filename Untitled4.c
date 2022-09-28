#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

 void entry();   // for taking info
void list();    // for showing the info list
void search();  // searching by someone's code
void delete (); // delete entry


struct employee
{
    char first_name[50];
    char last_name[50];
    char gender[15];
    int code;
    char designation[100];
    int exp_year;
    int age;
};


void main()
{
    int choice;
    while (choice != 5)
    {

        printf("_________________EMPLOYEE MANAGEMENT SYSTEM________________");
        printf("\n\n\n\n 1.ADD ENTRY\n");
        printf("\n\n\n\n 2.SHOW ENTRY LIST\n");
        printf("\n\n\n\n 3.SEARCH ENTRY\n");
        printf("\n\n\n\n 4.DELETE ENTRY\n");
        printf("\n\n\n\n 5.EXIT\n");
        printf("choose any number from 1 to 5 : ");
        scanf("%d", &choice);

        switch(choice)
        {


       case 1:
            system("cls");
            entry();
            system("cls");
            break;

      case 2:
            system("cls");
            list();
            printf("\t\t\t\t press any key to exit_______ \n");
            getch();
            system("cls");
            break;

     case 3:
            system("cls");
            search();
            printf("\t\t\t\t press any key to exit_______ \n");
            getch();
            system("cls");
            break;

     case 4:
            system("cls");
            delete ();
            printf("\t\t\t\t press any key to exit_______ \n");
            getch();
            system("cls");
            break;

      case 5:
            system("cls");
            printf("\t\t\tThank You for using!\n");
            exit(0);
            break;

       default:
            system("cls");
            getch();
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
            system("cls");
            break;
        }

        getch();
    }
}
void entry()
{
    char another;
    FILE *fp1;
    int n,i;
    struct employee info;
    while (another == 'y' || another == 'Y')
    {
        system("cls");
        printf("\t\t\t\t______enter ENTRY______\n\n");
        fp1 = fopen("info.txt", "a");

        printf("\n\t\t\tENTER FIRST NAME: ");
        scanf("%s", &info.first_name);
        printf("\n\t\t\tENTER LAST NAME: ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\tENTER GENDER: ");
        scanf("%s", &info.gender);
        printf("\n\t\t\tENTER CODE: ");
        scanf("%d", &info.code);
        printf("\n\t\t\tENTER DESIGNATION: ");
        scanf("%s", &info.designation);
        printf("\n\t\t\tENTER EXPERIENCE YEAR: ");
        scanf("%d", &info.exp_year);
        printf("\n\t\t\tENTER AGE: ");
        scanf("%d", &info.age);
        printf("\n\t\t\t_____________________________________________________\n\n");

        if (fp1 == NULL)
        {
            fprintf(stderr, "file couldn't copen");
        }
        else
        {
            printf("\t\t\trecord stored successfully\n");
        }

        fwrite(&info, sizeof(struct employee), 1, fp1);
        fclose(fp1);
        printf("\t\t\tdo you want to store another entry? y/n : ");
    scanf("%s", &another);
    }
}

void list()
{
    FILE *fp1;
    struct employee info;
    fp1 = fopen("info.txt", "r");
    printf("\t\t\t ENTRY LIST \n\n");

    if (fp1 == NULL)
    {
        fprintf(stderr, "file couldn't open");
    }
    else
    {
        printf("\t\t\tLIST\n\n");
        printf("\t\t\t_________\n");
    }
    while (fread(&info, sizeof(struct employee), 1, fp1))
    {
        printf("\n\t\t\t\t Employee name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\t Employee gender : %s", &info.gender);
        printf("\n\t\t\t\t Employee code : %d", &info.code);
        printf("\n\t\t\t\t Employee designation : %s", &info.designation);
        printf("\n\t\t\t\t Employee experience year : %d", &info.exp_year);
        printf("\n\t\t\t\t Employee age : %d", &info.age);
        printf("\n\t\t\t\t ________________________________\n");
    }
    fclose(fp1);
    getch();
}
void search()
{
    struct employee info;
    int found = 0, code;
    FILE *fp1;
    fp1 = fopen("info.txt", "r");
    printf("\t\t\t_____SEARCH EMPLOYEE ENTRY_____\n\n");
    printf("\tEnter the code: ");
    scanf("%d", &code);
    while (fread(&info, sizeof(struct employee), 1, fp1) > 0)
    {
        if (info.code == code)
        {
            found = 1;
            printf("\n\t\t\t\t Employee name  : %s %s", info.first_name, info.last_name);
            printf("\n\t\t\t\t Employee gender : %s", &info.gender);
            printf("\n\t\t\t\t Employee code : %d", &info.code);
            printf("\n\t\t\t\t Employee designation : %s", &info.designation);
            printf("\n\t\t\t\t Employee experience year : %d", &info.exp_year);
            printf("\n\t\t\t\t Employee age : %d", &info.age);
            printf("\n\t\t\t\t ________________________________\n");
        }
    }
    if (!found)
    {
        printf("\n\t\t\tEntry not found\n");
    }
    fclose(fp1);
    getch();
}

void delete ()
{
    struct employee info;
    FILE *fp1, *fp2;
    int code, found = 0;
    printf("\n\t\t\t DELETE ENTRY\n\n");
    printf("\t\tEnter the code: ");
    scanf("%d", &code);
    fp1 = fopen("info.txt", "r");
    fp2 = fopen("temp.txt", "w");
    if (fp1 == NULL)
    {
        fprintf(stderr, "can't open");
        exit(0);
    }
    while (fread(&info, sizeof(struct employee), 1, fp1))
    {
        if (info.code == code)
        {
            found = 1;
        }
        else
        {
            fwrite(&info, sizeof(struct employee), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if (!found)
    {
        printf("\n\t\t\t\tEntry not found\n");
    }
    else
    {
        remove("info.txt");
        rename("temp.txt", "info.txt");

        printf("\n\t\t\t\tEntry deleted succesfully\n");
    }
    getch();
}

