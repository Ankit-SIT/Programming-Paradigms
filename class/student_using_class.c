#include<stdio.h>

#define MAX_STUDENTS 3

struct Address {                             // address structure definition
    char *main[30];
    char *secondary[30];
    char *city[20];
    unsigned int pin;
};

struct Student {                             // student structure definition
char *name[20];
long long unsigned int prn; 
char *branch[10];
float marks;

struct Address address;                      // each student has a child address structure
};


int main(){
    enum bool { False, True };
    struct Student Students[MAX_STUDENTS];
    int i = 0,choice = 0;
    enum bool run = True;

    while(run){
        printf("\n\n--MENU--\n");           
        printf("1. INSERT\n");
        printf("2. DISPLAY\n");
        printf("3. EXIT\n");
        printf("ENTER YOUR CHOICE: \n");
        
        scanf("%d",&choice);

        switch(choice)
        { 
            case 1:                                                      // input student details
            i = MAX_STUDENTS; 
            while(i--){
                   printf("\n\nENTER NAME:");
                   scanf("%s",&Students[i].name);
                   printf("ENTER PRN:");
                   scanf("%lld",&Students[i].prn);       
                   printf("ENTER BRANCH:");
                   scanf("%s",&Students[i].branch);       
                   printf("ENTER MARKS:");
                   scanf("%f",&Students[i].marks);
                   printf("ENTER ADDRESS LINE 1:");
                   scanf("%s",&Students[i].address.main);
                   printf("ENTER ADDRESS LINE 2:");
                   scanf("%s",&Students[i].address.secondary);
                   printf("ENTER CITY:");
                   scanf("%s",&Students[i].address.city);
                   printf("ENTER PIN CODE:");
                   scanf("%d",&Students[i].address.pin);
                 }
                 break;
 
            case 2:                                               // print details of all students
            i = MAX_STUDENTS;
            while(i--){
                printf("\n\nNAME: %s",Students[i].name);
                printf("\n PRN: %lld",Students[i].prn);    
                printf("\n BRANCH: %s",Students[i].branch);       
                printf("\n MARKS: %0.2f",Students[i].marks);
                printf("\n Address Line 1: %s",Students[i].address.main);
                printf("\n Address Line 2: %s",Students[i].address.secondary);
                printf("\n City: %s",Students[i].address.city);
                printf("\n PIN: %d",Students[i].address.pin);
                }
                break;     
            
            case 3:
                  run = False;
                  break;
        }
     }
    return 0;
}
