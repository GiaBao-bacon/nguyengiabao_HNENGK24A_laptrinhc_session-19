#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[12];
};

void sortStudentsByName(struct Student students[], int size) {
    struct Student temp;
    int i; 
    for (i = 0; i < size - 1; i++) {
    	int j; 
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void printStudents(struct Student students[], int size) {
    printf("Danh sach sinh vien:\n");
    int i; 
    for (i = 0; i < size; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5];
    int size = 5;
    
    students[0].id = 1;
    strcpy(students[0].name, "Nguyen Van A");
    students[0].age = 20;
    strcpy(students[0].phoneNumber, "0123456789");
    
    students[1].id = 2;
    strcpy(students[1].name, "Tran Thi B");
    students[1].age = 21;
    strcpy(students[1].phoneNumber, "0987654321");
    
    students[2].id = 3;
    strcpy(students[2].name, "Le Van C");
    students[2].age = 19;
    strcpy(students[2].phoneNumber, "0912345678");
    
    students[3].id = 4;
    strcpy(students[3].name, "Pham Thi D");
    students[3].age = 22;
    strcpy(students[3].phoneNumber, "0932145678");
    
    students[4].id = 5;
    strcpy(students[4].name, "Hoang Van E");
    students[4].age = 20;
    strcpy(students[4].phoneNumber, "0971234567");
    
    printf("Truoc khi sap xep:\n");
    printStudents(students, size);
    
    sortStudentsByName(students, size);
    
    printf("\nSau khi sap xep theo ten:\n");
    printStudents(students, size);
    
    return 0;
}
