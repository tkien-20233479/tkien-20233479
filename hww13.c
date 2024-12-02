#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cấu trúc Node
typedef struct Node {
    char customerName[50]; // Tên khách hàng
    int itemCount;         // Số lượng hàng hóa
    char itemName[50];     // Tên sản phẩm
    int itemPrice;         // Giá mỗi sản phẩm
    int totalAmount;       // Tổng số tiền giỏ hàng
    struct Node* next;     // Con trỏ tới Node tiếp theo
} Node;

// Hàm tạo một Node mới
Node* createNode(const char* customerName, int itemCount, const char* itemName, int itemPrice) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->customerName, customerName);
    newNode->itemCount = itemCount;
    strcpy(newNode->itemName, itemName);
    newNode->itemPrice = itemPrice;
    newNode->totalAmount = itemCount * itemPrice;
    newNode->next = NULL;
    return newNode;
}

// Thêm (push) một khách hàng vào stack
void push(Node** top, const char* customerName, int itemCount, const char* itemName, int itemPrice) {
    Node* newNode = createNode(customerName, itemCount, itemName, itemPrice);
    newNode->next = *top;
    *top = newNode;
    printf("Đã thêm khách hàng: %s\n", customerName);
}

// Loại bỏ (pop) một khách hàng khỏi stack
void pop(Node** top) {
    if (*top == NULL) {
        printf("Stack rỗng, không thể thực hiện pop.\n");
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    printf("Đã xóa khách hàng: %s\n", temp->customerName);
    free(temp);
}

// Tính tổng số tiền thu được tại quầy thu ngân
int calculateTotal(Node* top) {
    int total = 0;
    Node* current = top;
    while (current != NULL) {
        total += current->totalAmount;
        current = current->next;
    }
    return total;
}

// Đếm số lượng một sản phẩm đã bán
int countItemSold(Node* top, const char* itemName) {
    int count = 0;
    Node* current = top;
    while (current != NULL) {
        if (strcmp(current->itemName, itemName) == 0) {
            count += current->itemCount;
        }
        current = current->next;
    }
    return count;
}

// In danh sách khách hàng trong stack
void printStack(Node* top) {
    if (top == NULL) {
        printf("Stack rỗng.\n");
        return;
    }
    Node* current = top;
    printf("Danh sách khách hàng:\n");
    while (current != NULL) {
        printf("Khách hàng: %s, Số lượng: %d, Sản phẩm: %s, Tổng tiền: %d\n",
               current->customerName, current->itemCount, current->itemName, current->totalAmount);
        current = current->next;
    }
}

// Hàm chính
int main() {
    Node* top = NULL; // Đỉnh của stack (ban đầu rỗng)

    // Thêm một số khách hàng
    push(&top, "Nguyen Van A", 3, "Apple", 5000);
    push(&top, "Le Thi B", 2, "Banana", 3000);
    push(&top, "Tran Van C", 5, "Apple", 5000);

    // In danh sách khách hàng
    printStack(top);

    // Loại bỏ khách hàng khỏi stack
    pop(&top);

    // Tính tổng tiền thu được
    int total = calculateTotal(top);
    printf("Tổng số tiền thu được: %d\n", total);

    // Đếm số lượng sản phẩm Apple đã bán
    int appleCount = countItemSold(top, "Apple");
    printf("Số lượng Apple đã bán: %d\n", appleCount);

    return 0;
}