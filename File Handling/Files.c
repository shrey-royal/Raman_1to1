#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");

    if(file != NULL) {
        printf("File '%s' created successfully.\n", filename);
        fclose(file);
    } else {
        fprintf(stderr, "\nError: Unable to c create file.");
    }
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");

    if(file != NULL) {
        printf("Content of '%s':\n", filename);
        char line[100];
        while(fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        fprintf(stderr, "File '%s' not found.\n", filename);
    }
}

void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");

    if(file != NULL) {
        fprintf(file, "%s\n", data);
        printf("Data written to '%s' successfully.\n", filename);
        fclose(file);
    } else {
        fprintf(stderr, "Error: Unable to write to file.\n");
    }
}

void appendToFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");

    if(file != NULL) {
        fprintf(file, "\n%s", data);
        printf("Data appended to '%s' successfully.\n", filename);
        fclose(file);
    } else {
        fprintf(stderr, "Error: Unable to append to file.\n");
    }
}

void deleteFile(const char *filename) {
    if(remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        fprintf(stderr, "File '%s' not found.\n", filename);
    }
}


void main() {
    while(1) {
        printf("\nMenu:\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Write to a file\n");
        printf("4. Append to a file\n");
        printf("5. Delete a file\n");
        printf("6. Exit\n");

        int choice;
        printf("Enter your choice (1/2/3/4/5/6): ");
        scanf("%d", &choice);

        char filename[50], data[100];

        switch(choice) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                createFile(filename);
                break;

            case 2:
                printf("Enter the filename to read: ");
                scanf("%s", filename);
                readFile(filename);
                break;

            case 3:
                printf("Enter the filename to write to: ");
                scanf("%s", filename);
                printf("Enter the data to write: ");
                getchar(); // Consume newline
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0'; // Remove newline character
                writeFile(filename, data);
                break;

            case 4:
                printf("Enter the filename to append to: ");
                scanf("%s", filename);
                printf("Enter the data to append: ");
                getchar(); // Consume newline
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0'; // Remove newline character
                appendToFile(filename, data);
                break;

            case 5:
                printf("Enter the filename to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;

            case 6:
                printf("Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please enter a valid option (1/2/3/4/5/6).\n");
        }
    }
}