#include<stdio.h>
#include<string.h>

struct Employee {
    int id;
    char name[20];
    int age;
    float salary;
};

union PaymentMethod {
    float hourlyRate;
    float monthlySalary;
};

void main() {
    struct Employee e;
    e.id = 420;
    strcpy(e.name, "Raman");
    e.age = 30;
    e.salary = 50000.0;

    union PaymentMethod pay;
    pay.hourlyRate = 20;

    printf("\nId: %d", e.id);
    printf("\nName: %s", e.name);
    printf("\nAge: %d", e.age);
    printf("\nSalary: %d", e.salary);

    printf("\nHourly Rate: %.2f", pay.hourlyRate);

}