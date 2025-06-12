#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[12];
};

void displayStudents(struct Student students[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien trong!\n");
        return;
    }
    printf("Danh sach sinh vien:\n");
    int i; 
    for (i = 0; i < currentLength; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

void addStudent(struct Student students[], int *currentLength) {
    if (*currentLength >= 100) {
        printf("Danh sach da day, khong the them!\n");
        return;
    }
    struct Student newStudent;
    printf("Nhap ID: ");
    scanf("%d", &newStudent.id);
    getchar();
    int i; 
    for (i = 0; i < *currentLength; i++) {
        if (students[i].id == newStudent.id) {
            printf("ID da ton tai!\n");
            return;
        }
    }
    printf("Nhap ten: ");
    fgets(newStudent.name, 50, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;
    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Nhap so dien thoai: ");
    fgets(newStudent.phoneNumber, 12, stdin);
    newStudent.phoneNumber[strcspn(newStudent.phoneNumber, "\n")] = 0;
    
    students[*currentLength] = newStudent;
    (*currentLength)++;
    printf("Them sinh vien thanh cong!\n");
}

void editStudent(struct Student students[], int currentLength) {
    int id, found = 0, index = -1;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    getchar();
    int i; 
    for (i = 0; i < currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d!\n", id);
        return;
    }
    
    printf("Nhap ten moi: ");
    fgets(students[index].name, 50, stdin);
    students[index].name[strcspn(students[index].name, "\n")] = 0;
    printf("Nhap tuoi moi: ");
    scanf("%d", &students[index].age);
    getchar();
    printf("Nhap so dien thoai moi: ");
    fgets(students[index].phoneNumber, 12, stdin);
    students[index].phoneNumber[strcspn(students[index].phoneNumber, "\n")] = 0;
    
    printf("Sua thong tin sinh vien thanh cong!\n");
}

void deleteStudent(struct Student students[], int *currentLength) {
    int id, found = 0, index = -1;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    int i; 
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

void searchStudent(struct Student students[], int currentLength) {
    int id, found = 0;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);
    int i; 
    for (i = 0; i < currentLength; i++) {
        if (students[i].id == id) {
            printf("Sinh vien tim thay:\n");
            printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", 
                   students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d!\n", id);
    }
}

void sortStudentsByName(struct Student students[], int currentLength) {
    struct Student temp;
    int i; 
    for (i = 0; i < currentLength - 1; i++) {
    	int j; 
        for ( j = 0; j < currentLength - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien theo ten!\n");
}

void displayMenu() {
    printf("\nMENU\n");
    printf("1. Hien thi danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Tim kiem sinh vien\n");
    printf("6. Sap xep danh sach sinh vien\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
}

int main() {
    struct Student students[100];
    int currentLength = 5;
    int choice;
    
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
    
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                displayStudents(students, currentLength);
                break;
            case 2:
                addStudent(students, &currentLength);
                break;
            case 3:
                editStudent(students, currentLength);
                break;
            case 4:
                deleteStudent(students, &currentLength);
                break;
            case 5:
                searchStudent(students, currentLength);
                break;
            case 6:
                sortStudentsByName(students, currentLength);
                break;
            case 7:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);
    
    return 0;
}
