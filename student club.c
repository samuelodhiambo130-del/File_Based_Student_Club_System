#include<stdio.h>
#include<string.h>
struct student{
    char fullName[60];
    char admissionNo[30];
    char course[60];
    char yearOfStudy[30];
}; 
void removeNewLine(char *str){
    str[strcspn(str,"\n")]=0;
}
void removeSlash(char *str,char *str2){
    int i=0,j=0;
    while(str[i]!='\0'){
        if(str[i]!='/'){
            str2[j]=str[i];
            j++;
        }
        i++;
    } 
    str2[j]='\0';
}
void captureDetails(){
    struct student student1;
    char studentDetails[600];
    FILE *fptr;
    char fileName[30];
    printf("Enter the full name of the club member: ");
    fgets(student1.fullName,sizeof(student1.fullName),stdin);
    removeNewLine(student1.fullName);
    printf("\nEnter the admission number of the club member: ");
    fgets(student1.admissionNo,sizeof(student1.admissionNo),stdin);
    removeNewLine(student1.admissionNo);
    printf("\nEnter the course that the club member is taking: ");
    fgets(student1.course,sizeof(student1.course),stdin);
    removeNewLine(student1.course);
    printf("\nEnter the year of study of the club member: ");
    fgets(student1.yearOfStudy,sizeof(student1.yearOfStudy),stdin);
    removeNewLine(student1.yearOfStudy);
    sprintf(studentDetails,"RECORDS FOR THE MATHEMATICS STUDENTS CLUB\n\n------------------------------------------\n\nName: %s\n\nAdmission Number: %s\n\nCourse: %s\n\nYear Of Study: %s",student1.fullName,student1.admissionNo,student1.course,student1.yearOfStudy);
    removeSlash(student1.admissionNo,fileName);
    fptr=fopen(fileName,"w");
    if(fptr==NULL){
        printf("Error creating the file");
    }
    fprintf(fptr,studentDetails);
    fclose(fptr);
}
void displayDetails(){
    char studentDetails[600];
    char fileName[30];
    char admNo[30];
    FILE *fptr;
    printf("\nEnter the admission number of the club member who's details you want to view: ");
    fgets(admNo,sizeof(admNo),stdin);
    removeNewLine(admNo);
    removeSlash(admNo,fileName);
    fptr=fopen(fileName,"r");
    if(fptr==NULL){
        printf("Error reading from the file");
    }
    while(fgets(studentDetails,sizeof(studentDetails),fptr)){
        printf("%s",studentDetails);
    }
    fclose(fptr);
}
int main(){
    int choice;
    printf("Welcome aboard........Please choose from the menu below:\nA. Enter 1 to add a new member to the club\nB. Enter 2 to view a club member's details\nC. Enter 3 to exit the program\n");
    while(1){
        printf("\n\nChoice: ");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
            captureDetails();
            break;
            case 2:
            displayDetails();
            break;
            case 3:
            return 0;
            default:
            printf("\nWrong input, please try again");
        }
    }
}
