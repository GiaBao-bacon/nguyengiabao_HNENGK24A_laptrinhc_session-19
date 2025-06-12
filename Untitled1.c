#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[12];
};

void deleteStudent(int id, struct Student students[], int *currentLength) {
    int i, found = 0, index = -1;
    
    for (i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if (!found || index < 0 || index >= *currentLength) {
        printf("Khong tim thay sinh vien voi ID %d hoac ID khong hop le!\n", id);
        return;
    }
    
    for (i = index; i < *currentLength - 1; i++) {
        students[i] = students[i + 1];
    }
    (*currentLength)--;
    
    printf("Da xoa sinh vien voi ID %d\n", id);
}

void printStudents(struct Student students[], int currentLength) {
    printf("Danh sach sinh vien:\n");
    int i; 
    for (i = 0; i < currentLength; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5];
    int currentLength = 5;
    
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
    
    printf("Truoc khi xoa:\n");
    printStudents(students, currentLength);
    
    deleteStudent(3, students, &currentLength);
    
    printf("\nSau khi xoa:\n");
    printStudents(students, currentLength);
    
    deleteStudent(6, students, &currentLength);
    
    return 0;
}
