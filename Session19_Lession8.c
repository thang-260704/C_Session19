#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudent(int studentId, Student students[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == studentId) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--; 
            break;
        }
    }
    if (!found) {
        printf("Sinh vien voi ID %d khong ton tai trong mang.\n", studentId);
    }
}

void sortStudentsByName(Student students[], int currentLength) {
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(const Student students[], int currentLength) {
    if (currentLength == 0) {
        printf("Mang sinh vien hien dang trong.\n");
        return;
    }
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
  #define MAX_SIZE 5
    Student students[MAX_SIZE] = {
        {1, " Nguyen Quyet Thang", 20, "0782154417"},
        {2, "Nguyen Sy Trung", 18, "0987654321"},
        {3, "Nguyen Manh Hung", 18, "0112233445"},
        {4, "Nguyen Tuan Dung", 18, "0998877665"},
        {5, "Tran Anh Dung", 18, "0901122334"}
    };
    int currentLength = 5;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);
    sortStudentsByName(students, currentLength);
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printStudents(students, currentLength);

    return 0;
}
