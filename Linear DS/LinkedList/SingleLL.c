#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    Node* next;
} Node;

void printList(Node* head) {
    printf("\nList ==> \t");
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}


int main() {
    int choice, data, position, key;
    struct Node* head = NULL;
    
    while (1) {
        // system("pause");
        system("cls");
        printList(head);

        printf("\n\n\n1. Insert at beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Search By Value");
        printf("\n5. Length of the list");
        printf("\n6. Reverse the List");
        printf("\n7. Delete at beginning");
        printf("\n8. Delete at end");
        printf("\n9. Delete at Position");
        printf("\n10. Print list from beginning");
        printf("\n11. Print list from end");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // system("cls");
                printf("\nEnter the data: ");
                scanf("%d", &data);
                InsertAtBeginning(&head, data);
                break;

            // case 2:
            //     // system("cls");
            //     printf("\nEnter the data: ");
            //     scanf("%d", &data);
            //     InsertAtEnd(&head, data);
            //     break;
            
            // case 3:
            //     printf("\nEnter the position: ");
            //     scanf("%d", &position);
            //     printf("\nEnter the data: ");
            //     scanf("%d", &data);
            //     InsertAtPos(&head, data, position);
            //     break;

            // case 4:
            //     printf("\nEnter the key to search from the list: ");
            //     scanf("%d", &key);
            //     // if(searchByValue(&head, key)) {
            //     //     printf("%d present in the list...", key);
            //     // } else {
            //     //     printf("%d is not present in the list...", key);
            //     // }
            //     searchByValue(head, key) ? printf("\n%d present in the list...", key) : printf("\n%d is not present in the list...", key);
            //     system("pause");
            //     break;

            // case 5:
            //     printf("\nLength of the list: %d\n", getLength(head));
            //     system("pause");
            //     break;

            // case 6:
            //     reverseList(&head);
            //     break;

            // case 7:
            //     deleteAtBeginning(&head);
            //     break;

            // case 8:
            //     deleteAtEnd(&head);
            //     break;

            // case 9:
            //     printf("\nEnter the position to delete the node: ");
            //     scanf("%d", &position);
            //     deleteAtPosition(&head, position);
            //     break;
            
            case 10:
                // system("cls");
                printf("\nList from beginning: ");
                printList(head);
                system("pause");
                break;

            // case 11:
            //     printf("\nList from End: ");
            //     PrintFromEnd(head);
            //     system("pause");
            //     break;

            case 0:
                printf("\nExiting...\n");
                // system("pause");
                exit(0);
                break;
            
            default:
                break;
        }
    }
}