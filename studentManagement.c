#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct studentInfor{
    char studentName[100];
    int studentAge;
    char studentId[100];
};

void displayMenu(int total, struct studentInfor studentsList[]){
    for(int i = 0; i < total; i++){
        printf("Name: %s | Age: %d | ID: %s\n",
           studentsList[i].studentName,
           studentsList[i].studentAge,
           studentsList[i].studentId);
    }
}

void addStudent(int *total, struct studentInfor studentsList[]){
    int num;
    printf("Enter the number of student: ");
    scanf("%d", &num);
    while(num < 0){
        printf("AGAIN\n");
        printf("Enter the number of student: ");
        scanf("%d", &num);
    }
    getchar();
    if(num == 0){
        printf("Cancelled adding student. Returning to menu.\n");
        return; //Exit
    }
    if(num > 0){
        for(int i = 0; i < num; i++){
            
            printf("Enter the name of #%d student: ",i+1);
            fgets(studentsList[*total].studentName, sizeof(studentsList[*total].studentName), stdin);
            studentsList[*total].studentName[strcspn(studentsList[*total].studentName, "\n")] = '\0';

            printf("Enter the age of #%d student: ",i+1); 
            scanf("%d", &studentsList[*total].studentAge);
            getchar();

            printf("Enter the id of #%d student: ",i+1); 
            fgets(studentsList[*total].studentId, sizeof(studentsList[*total].studentId), stdin);
            studentsList[*total].studentId[strcspn(studentsList[*total].studentId, "\n")] = '\0';
            (*total) ++;
        }
    }
    
}

void searching(struct studentInfor studentsList[], int total){
    char id[100];
    int isFound = 0;
    printf("Enter id: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    while(strlen(id) <= 0){
        printf("AGAIN\n");
        printf("Enter id: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
    }
    for(int i = 0; i < total; i++){
        if(strcmp(id, studentsList[i].studentId) == 0){
            printf("Its found\n");
            printf("%s  |   %s  |   %d\n", 
                studentsList[i].studentId, 
                studentsList[i].studentName, 
                studentsList[i].studentAge);
                isFound = 1;
            break;
        }
    }
    if(isFound ==0){
        printf("Not found the id: %s\n", id);
    }
}

void editing(struct studentInfor studentsList[], int total){
    char id[100]; char name[100];
    int searchingMethod;
    printf("SEARCH METHOD\n");
    printf("1. Searching by id\n");
    printf("2. Searching by Name\n");
    printf("Enter your choice(1-2): ");
    scanf("%d", &searchingMethod);
    getchar();
    if(searchingMethod == 1){
        int option;
        printf("Enter the searching id: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';
        printf("1. Id\n");
        printf("2. Name\n");
        printf("3. Age\n");
        printf("Enter the editing option: ");
        scanf("%d", &option);
        getchar();
        if(option == 1){
            char newId[100];
            printf("Enter the new id: ");
            fgets(newId, sizeof(newId), stdin);
            newId[strcspn(newId, "\n")] = '\0';
            for(int i = 0; i < total; i++){
                if(strcmp(id, studentsList[i].studentId) == 0){
                    strcpy(studentsList[i].studentId, newId);
                    break;
                }
            }
        }
        else if(option == 2){
            char newName[100];
            printf("Enter the new name: ");
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = '\0';
            for(int i = 0; i < total; i++){
                if(strcmp(studentsList[i].studentId, id) == 0){
                   strcpy(studentsList[i].studentName, newName);
                   break; 
                }
            }
        }
        else if(option == 3){
            int newAge;
            printf("Enter the new age: ");
            scanf("%d", &newAge);
            getchar();
            for(int i = 0; i < total; i++){
                if(strcmp(studentsList[i].studentId, id) == 0){
                    studentsList[i].studentAge = newAge;
                    break;
                }
            }
        }
    }
    if(searchingMethod == 2){
        int option;
        printf("Enter the searching name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        printf("1. Id\n");
        printf("2. Name\n");
        printf("3. Age\n");
        printf("Enter the editing option: ");
        scanf("%d", &option);
        getchar();
        if(option == 1){
            char newId[100];
            printf("Enter the new id: ");
            fgets(newId, sizeof(newId), stdin);
            newId[strcspn(newId, "\n")] = '\0';
            for(int i = 0; i < total; i++){
                if(strcmp(name, studentsList[i].studentName) == 0){
                    strcpy(studentsList[i].studentId, newId);
                    break;
                }
            }
        }
        else if(option == 2){
            char newName[100];
            printf("Enter the new name: ");
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = '\0';
            for(int i = 0; i < total; i++){
                if(strcmp(name, studentsList[i].studentName) == 0){
                   strcpy(studentsList[i].studentName, newName);
                   break; 
                }
            }
        }
        else if(option == 3){
            int newAge;
            printf("Enter the new age: ");
            scanf("%d", &newAge);
            getchar();
            for(int i = 0; i < total; i++){
                if(strcmp(name, studentsList[i].studentName) == 0){
                    studentsList[i].studentAge = newAge;
                    break;
                }
            }
        }
    }
}

void removing(struct studentInfor studentsList[], int*total){
    char removeId[100];
    int size = *total;
    int isFound = 0;
    printf("Enter the id: ");
    fgets(removeId, sizeof(removeId), stdin);
    removeId[strcspn(removeId, "\n")] = '\0';
    
    for(int i = 0; i < size; i++){
        if(strcmp(removeId, studentsList[i].studentId) == 0){
            for(int j = i; j < size-1; j++){
                studentsList[j] = studentsList[j+1];
            }
        (*total) -- ;
        isFound = 1;
        printf("SUCCESFULLY\n");
        return;
        }
    }
    if(isFound == 0){
        printf("NOT FOUNd\n");
    }
}

void CreatingFile(struct studentInfor studentsList[], int total){
    FILE * fptr;
    fptr = fopen("Project1.txt", "w");
    if (!fptr) {
    printf("Cannot create file.\n");
    return;
}
    for(int i = 0; i < total; i ++){
        fprintf(fptr, "%s              %s             %d\n", studentsList[i].studentId, studentsList[i].studentName, studentsList[i].studentAge);
    }
    fclose(fptr);
}

void myMenu(int choice, int *total, struct studentInfor studentsList[]){
    while(choice != 7){
        if(choice == 1){
            addStudent(total, studentsList);
        }
        else if(choice == 2){
            displayMenu(*total, studentsList);
        }
        else if(choice == 3){
            searching(studentsList, *total);
        }
        else if(choice == 4){
            editing(studentsList, *total);
        }
        else if(choice == 5){
            removing(studentsList, total);
        }
        else if(choice == 6){
            CreatingFile(studentsList,* total);
        }
        printf("\n**********STUDENT MANAGEMENT**********\n");
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Search by ID\n");
        printf("4. Edit student\n");
        printf("5. Delete student\n");
        printf("6. Export file\n");
        printf("7. Exit\n");
        printf("Enter your choice: "); 
        scanf("%d", &choice);
        getchar();
    }
}


int main (){
    struct studentInfor studentsList[100];
    int total = 0;
    int choice;
    printf("\n**********STUDENT MANAGEMENT**********\n");
    printf("1. Add student\n");
    printf("2. Display students\n");
    printf("3. Search by ID\n");
    printf("4. Edit student\n");
    printf("5. Delete student\n");
    printf("6. Export file\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice); 
    getchar();
    myMenu(choice, &total, studentsList);


    return 0;
}
