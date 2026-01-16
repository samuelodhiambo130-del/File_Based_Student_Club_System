#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char name[50];
    char admNo[30];
    char course[40];
    char YOS[20];
} member;

void removeslash(char *s)
{
    int i, j = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != '/' && s[i] != '\\')
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void add()
{
    member mem;
    FILE *fp;
    char filename[40];

    printf("Enter the member name:\n");
    scanf(" %[^\n]", mem.name);

    printf("Enter member admission number:\n");
    scanf(" %[^\n]", mem.admNo);
    removeslash(mem.admNo);

    strcpy(filename, mem.admNo);
    strcat(filename, ".txt");

    printf("Enter the member course:\n");
    scanf(" %[^\n]", mem.course);

    printf("Enter the member year of study:\n");
    scanf(" %[^\n]", mem.YOS);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error creating file!\n");
        return;
    }

    fprintf(fp,
        "Member name: %s\nAdmission Number: %s\nCourse: %s\nYear Of Study: %s\n",
        mem.name, mem.admNo, mem.course, mem.YOS);

    fclose(fp);
    printf("Details written to the file successfully\n");
}

void view()
{
    char filename[40];
    FILE *fp;
    int ch;

    printf("Enter the admission number of the member:\n");
    scanf(" %[^\n]", filename);
    removeslash(filename);

    strcat(filename, ".txt");

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error reading from file\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
}

int main()
{
    int choice;

    do
    {
        printf("===== STUDENT CLUB RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add a new member\n");
        printf("2. View a club member's details\n");
        printf("3. Exit the program\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: add(); break;
            case 2: view(); break;
            case 3: printf("Exiting the program...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 3);

    return 0;
}
