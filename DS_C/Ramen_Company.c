#include <stdio.h>
#include <string.h>

// Define constants for item types
#define RAW_MATERIAL 1
#define FINISHED_PRODUCT 2
#define EQUIPMENT 3

// Structure to represent production date
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Union to hold different attribute types
typedef union {
    float weight;         // Attribute for raw materials
    float price;          // Attribute for finished products
    Date maintenanceDate; // Attribute for equipment
} ItemAttribute;

// Structure to represent an inventory item
typedef struct {
    int itemType;
    int serialNumber;
    Date productionDate;
    ItemAttribute attribute;
} InventoryItem;

// Function to display item information
void displayItem(InventoryItem item) {
    printf("Type: %d\nSerial Number: %d\nProduction Date: %d/%d/%d\n",
           item.itemType, item.serialNumber, item.productionDate.day,
           item.productionDate.month, item.productionDate.year);

    switch (item.itemType) {
        case RAW_MATERIAL:
            printf("Weight: %.2f\n", item.attribute.weight);
            break;
        case FINISHED_PRODUCT:
            printf("Price: $%.2f\n", item.attribute.price);
            break;
        case EQUIPMENT:
            printf("Maintenance Date: %d/%d/%d\n",
                    item.attribute.maintenanceDate.day,
                   item.attribute.maintenanceDate.month,
                   item.attribute.maintenanceDate.year);
            break;
        default:
            printf("Invalid item type.\n");
            break;
    }
}

int main() {
    // Example inventory items
    InventoryItem rawMaterialItem = {RAW_MATERIAL, 1001, {1, 1, 2023}, {150.5}};
    InventoryItem productItem = {FINISHED_PRODUCT, 2001, {15, 6, 2023}, {49.99}};
    InventoryItem equipmentItem = {EQUIPMENT, 3001, {10, 12, 2022}, {15, 4, 2024}};

    // Display information for each item
    printf("Raw Material Item:\n");
    displayItem(rawMaterialItem);
    printf("\nFinished Product Item:\n");
    displayItem(productItem);
    printf("\nEquipment Item:\n");
    displayItem(equipmentItem);

    return 0;
}
