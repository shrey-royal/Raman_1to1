#include<stdio.h>

struct Employee {
    int id;
    char name[10];
    float salary;
};

struct Employee scanData(struct Employee e) {
    printf("\nEnter id: ");
    scanf("%d", &e.id);
    printf("\nEnter name: ");
    scanf(" %[^\n]s", e.name);
    printf("\nEnter salary: ");
    scanf("%f", &e.salary);

    return e;
}

void printData(struct Employee e) {
    printf("\nId: %d\nName: %s\nSalary: %.4f", e.id, e.name, e.salary);
}

void main() {
    struct Employee e;

    // e = scanData(e);
    // printData(e);

    printf("\n%d", sizeof(struct Employee));
}