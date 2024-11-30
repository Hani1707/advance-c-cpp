#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;          // Dữ liệu của node (phần tử chứa giá trị kiểu int)
    struct Node *next; // Con trỏ trỏ tới node tiếp theo trong danh sách
} Node_t;

// Hàm tạo node mới
Node_t* createNode(int value) {
    Node_t* node = (Node_t*)malloc(sizeof(Node_t)); // Cấp phát bộ nhớ động cho node
    node->data = value; // Gán giá trị cho node mới
    node->next = NULL;  // Con trỏ của node mới trỏ tới NULL (vì node này là node cuối cùng)
    return node; // Trả về con trỏ tới node mới được tạo
}

// Hàm thêm node vào cuối danh sách
void push_back(Node_t **array, int value) {
    Node_t *new_node = createNode(value); // Tạo node mới chứa giá trị value
    if (*array == NULL) { // Nếu danh sách hiện tại trống, node mới sẽ là node đầu tiên
        *array = new_node;
    } else { // Nếu danh sách không trống, duyệt đến node cuối và thêm node mới vào
        Node_t *temp = *array;
        while (temp->next != NULL) { // Duyệt qua danh sách để tìm node cuối cùng
            temp = temp->next;
        }
        temp->next = new_node; // Gán con trỏ next của node cuối trỏ tới node mới
    }
}

// Hàm thêm node vào đầu danh sách
void push_front(Node_t **array, int value) {
    Node_t *new_node = createNode(value); // Tạo node mới chứa giá trị value
    new_node->next = *array; // Con trỏ next của node mới sẽ trỏ tới node đầu tiên hiện tại
    *array = new_node;       // Cập nhật con trỏ đầu danh sách trỏ tới node mới
}

// Hàm xóa node đầu tiên
void pop_front(Node_t **array) {
    if (*array == NULL) return; // Nếu danh sách trống, không làm gì cả
    Node_t *temp = *array; // Gv nniữ lại con trỏ tới node đầu hiện tại
    *array = (*array)->next; // Cập nhật node đầu tiên thành node tiếp theo
    free(temp); // Giải phóng bộ nhớ của node cũ (node đầu bị xóa)
}

// Lấy giá trị node đầu tiên
int front(Node_t *array) {
    if (array == NULL) return -1; // Trả về -1 nếu danh sách trống
    return array->data; // Trả về giá trị của node đầu tiên
}

// Lấy giá trị node cuối cùng
int back(Node_t *array) {
    if (array == NULL) return -1; // Trả về -1 nếu danh sách trống
    Node_t *temp = array;
    while (temp->next != NULL) { // Duyệt tới node cuối cùng
        temp = temp->next;
    }
    return temp->data; // Trả về giá trị của node cuối cùng
}

// Hàm thêm node vào vị trí bất kỳ
void insert(Node_t **array, int value, int pos) {
    if (pos == 0) { // Nếu pos là 0, chèn node vào đầu danh sách
        push_front(array, value);
        return;
    }

    Node_t *new_node = createNode(value); // Tạo node mới chứa giá trị value
    Node_t *temp = *array;

    for (int i = 0; i < pos - 1 && temp != NULL; i++) { // Duyệt đến vị trí cần chèn
        temp = temp->next;
    }

    if (temp == NULL) { // Nếu vị trí không hợp lệ (vượt quá danh sách)
        free(new_node); // Giải phóng node mới tạo (vì không thể chèn)
        return;
    }

    new_node->next = temp->next; // Chèn node mới vào vị trí pos
    temp->next = new_node;
}

// Xóa node tại vị trí bất kỳ
void delete_list(Node_t **array, int pos) {
    if (*array == NULL) return; // Nếu danh sách trống, không làm gì cả

    Node_t *temp = *array; // Con trỏ tạm trỏ tới node đầu tiên

    if (pos == 0) { // Nếu cần xóa node đầu tiên
        *array = temp->next; // Cập nhật node đầu tiên thành node tiếp theo
        free(temp); // Giải phóng bộ nhớ của node bị xóa
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++) { // Duyệt đến node trước node cần xóa
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return; // Nếu vị trí không hợp lệ

    Node_t *next_node = temp->next->next; // Con trỏ tới node sau node cần xóa
    free(temp->next); // Giải phóng node tại vị trí pos
    temp->next = next_node; // Nối node trước vị trí pos với node sau vị trí pos
}

// Tính kích thước danh sách
int size(Node_t *array) {
    int count = 0; // Biến đếm số lượng node
    Node_t *temp = array;
    while (temp != NULL) { // Duyệt qua danh sách
        count++; // Tăng biến đếm khi gặp một node
        temp = temp->next;
    }
    return count; // Trả về kích thước của danh sách
}

// Lấy giá trị của node tại vị trí bất kỳ
int get(Node_t *array, int pos) {
    int i = 0;
    Node_t *temp = array;
    while (temp != NULL && i < pos) { // Duyệt qua danh sách đến vị trí pos
        temp = temp->next;
        i++;
    }
    if (temp == NULL) return -1; // Trả về -1 nếu vị trí không hợp lệ
    return temp->data; // Trả về giá trị của node tại vị trí pos
}

// Kiểm tra danh sách có rỗng hay không
bool empty(Node_t *array) {
    return (array == NULL); // Trả về true nếu danh sách trống
}

// Hàm main để kiểm tra
int main(int argc, char const *argv[]) {
    Node_t *node = NULL; // Khởi tạo danh sách trống

    // Thêm các phần tử vào cuối danh sách
    push_back(&node, 2);
    push_back(&node, 5);
    push_back(&node, 7);

    // Thêm vào đầu danh sách
    push_front(&node, 1);

    // Kiểm tra phần tử đầu và cuối
    printf("Front: %d\n", front(node)); // In ra giá trị node đầu tiên
    printf("Back: %d\n", back(node));   // In ra giá trị node cuối cùng

    // Thêm phần tử vào vị trí thứ 2
    insert(&node, 3, 2);

    // Xóa phần tử ở vị trí thứ 1
    delete_list(&node, 1);

    // Lấy giá trị tại vị trí bất kỳ
    printf("Value at position 2: %d\n", get(node, 2));

    // In kích thước danh sách
    printf("Size: %d\n", size(node));

    // Kiểm tra danh sách rỗng
    printf("Empty: %s\n", empty(node) ? "Yes" : "No");

    // Xóa phần tử đầu tiên
    pop_front(&node);
    
    return 0;
}
