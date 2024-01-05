#include<stdio.h>

struct Habits {
    char name[10];
    enum frequencyOfHabits { Never = 1, Often = 2, Sometimes = 3, Very_Often = 4, Extreme = 5 } frequency;
} habit[2];

void main() {
    // struct Habits habit;

    for (int i = 0; i < 2; i++) {
        printf("\nEnter your Habit: ");
        scanf(" %[^\n]s", habit[i].name);

        again:
        printf("\nHow often you do it?? (1-Never, 2-Often, 3-Sometimes, 4-Very_Often, 5-Extreme): ");
        scanf("%d", &habit[i].frequency);
        if(habit[i].frequency < 0 || habit[i].frequency > 5) {
            printf("\nInvalid Habit, Enter it again...");
            goto again;
        }
    }
    

    printf("\nHabit Details: \n");
    for (int i = 0; i < 2; i++) {
        printf("\nHabit Name: %s\tFrequency: ", habit[i].name);
        switch (habit[i].frequency) {
            case Never:
                printf("Never");
                break;

            case Often:
                printf("Often");
                break;

            case Sometimes:
                printf("Sometimes");
                break;

            case Very_Often:
                printf("Very Often");
                break;

            case Extreme:
                printf("Extreme");
                break;

            default:
                printf("Invalid Frequency");
                break;
        }
    }
    
}