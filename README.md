# Bài 1: Compiler - Macro
## Compiler
####
Trình biên dịch (compiler) trong C/C++ là công cụ chuyển đổi mã nguồn từ ngôn ngữ lập trình cấp cao (C hoặc C++) sang mã máy hoặc mã thực thi để máy tính có thể hiểu và thực hiện.
### 1. Preprocessor
##### Preprocessor trong C/C++ là một công cụ xử lý mã nguồn trước khi quá trình biên dịch bắt đầu. Chuyển file main.c thành file main.i
##### gcc -E main.c -o main.i
#### Macro: là từ dùng để chỉ những thông tin được xử lý ở quá trình tiền xử lý (Preprocessor)
#### Bao gồm:
##### 
- include : #include để chèn nội dung từ các file khác vào mã nguồn. 
- #define, #undef: là một chỉ thị của preprocessor dùng để định nghĩa/hủy định nghĩa macro
- #if: Kiểm tra điều kiện; nếu đúng, mã bên trong sẽ được biên dịch.
- #elif: Kiểm tra điều kiện khác nếu #if hoặc #elif trước đó sai.
- #else: Biên dịch mã nếu tất cả điều kiện trước đó (#if, #elif) đều sai.
- #ifdef: Biên dịch mã nếu một macro đã được định nghĩa.
- #ifndef: Kiểm tra xem một đoạn mã hoặc 1 biến đã được định nghĩa chưa, nếu đã được định nghĩa thì sẽ không lặp lại nội dung
##### Nếu có include thì sẽ copy các source của include vào
##### Sử dụng macro sẽ copy nội dung được định nghĩa vào
##### Nếu có comment thì sẽ xóa bỏ comment
#### Tóm lại tiền xử lý (Preprocessor) copy tất cả source lại để tạo thành file.i
##### 1.1 Marco Function
###### CREATE 1 FUNC
![bai1](https://github.com/user-attachments/assets/0ff94a34-be05-4af4-b5b0-88d266976fbb)
![bai1i](https://github.com/user-attachments/assets/de962ab0-2cf7-49e2-b8c8-44a12d022100)

###### từ CREATE_FUNC đã tạo ra 1 hàm thay thế đoạn code vào
###### Tạo nhiều biến khác nhau 
![image](https://github.com/user-attachments/assets/2cb5ddc0-b98a-43ab-b564-276ac51b29c7)
![image](https://github.com/user-attachments/assets/0be42d81-2bbe-46ab-bd03-5a33ea52881b)
###### Như vậy chúng ta đã tạo ra 3 biến khác nhau
##### 1.2 Variadic Macro
###### Variadic Macro là một macro có thể nhận số lượng tham số tùy ý, được định nghĩa bằng dấu "..." Các tham số này được truy cập bằng toán tử __VA_ARGS__.







![image](https://github.com/user-attachments/assets/a930012a-b379-47ef-be89-674fd60d8b33)
![image](https://github.com/user-attachments/assets/47c6db11-aa44-480f-a050-77fa75c98eac)
###### Như vậy chúng ta nhập bao nhiêu số sẽ tính tổng các số
##### Viết 1 chương trình để nạp cho nhiều vi điều khiển 
![image](https://github.com/user-attachments/assets/4c962e44-af43-4121-84bf-a3e644094f24)
![image](https://github.com/user-attachments/assets/fc2bdb04-2484-4ab0-9122-4e621ffd7a12)

###### Chương trình cho STM32
###### Nếu chúng ta muốn sử dụng ATMEGA thì sửa tại dòng #define MCU STM32 thành #define MCU ATMEGA
###### Và đây là kết quả:
![image](https://github.com/user-attachments/assets/a144ef79-2cc4-415f-8b36-8c9114615070)
![image](https://github.com/user-attachments/assets/01598cc9-3d8a-44a5-ae6a-e4f96828b85e)

### 2. Compiler
#### Sau khi Preprocessor sẽ tới compiler. Quá trình này được gọi là assembly code sẽ tạo file main.i thành file main.s
#####  gcc main.i -S -o main.s
##### Ví dụ:
![image](https://github.com/user-attachments/assets/62d3ec86-296a-4671-adda-c8dc088ef51b)
##### Sau khi gcc bai1_3.i -S -o bai1_3.s
![image](https://github.com/user-attachments/assets/04053350-1d78-47f7-8afb-82b63027e28b)

### 3. Assembler
#### Assembly code qua quá trình Assembler sẽ tạo ra Object file ( mã để nạp vào trong máy )
#### gcc main.s -o main.o
### 4. Linker
#### Linker là gộp những file object lại thành file cuối cùng sẽ tạo ra executable file
#### gcc test1.o test2.o -o main
./main
# Bài 2: STDARG - ASSERT 
## 1.	Stdarg Thư viện stdarg.h trong C cung cấp các macro để xử lý các hàm có số lượng đối số không xác định. Nó cho phép bạn viết các hàm có thể nhận bất kỳ số lượng đối số nào, chẳng hạn như printf.
### Va_list: được sử dụng để khai báo một biến mà có thể lưu trữ và truy cập các đối số không cố định của một hàm
### Va_start: dùng để khởi tạo một biến kiểu va_list trước khi truy cập các đối số không cố định của một hàm. Nó cần tham số là đối số cố định cuối cùng của hàm để xác định vị trí bắt đầu của các đối số không cố định. 
### Va_arg: Lấy đối số tiếp theo trong danh sách 
### Va_end: được sử dụng để kết thúc việc truy cập các đối số không cố định của một hàm. Nó cần được gọi trước khi kết thúc hàm
## 2. Thư viện assert:
### Thư viện assert cung cấp macro assert để kiểm tra các điều kiện tại thời điểm chạy chương trình. Nếu điều kiện kiểm tra là sai, chương trình sẽ dừng thực thi và hiển thị thông báo lỗi với thông tin về tệp tin và dòng mã nơi xảy ra lỗi. assert chủ yếu được sử dụng trong quá trình gỡ lỗi để đảm bảo các điều kiện tiên quyết được đáp ứng.
# Bài 3: Pointer
##  Pointer là một biến lưu trữ địa chỉ của một biến khác. Pointer không lưu giá trị trực tiếp mà lưu trữ địa chỉ của vùng nhớ nơi giá trị đó được lưu trữ. Điều này cho phép thao tác trực tiếp với vùng nhớ, truy cập và thay đổi giá trị của biến thông qua địa chỉ mà pointer trỏ tới.
## Cách khai báo:
```bash
int *ptr;  // con trỏ đến kiểu int
char *ptr_char;  // con trỏ đến kiểu char
float *ptr_float;  // con trỏ đến kiểu float
```
## ví dụ:
```bash
#include <stdio.h>

int a = 20;

int *ptr = &a;

int main(int argc, char const *argv[]){
    printf("dia chi a: %p\n", &a);
    printf("gia tri ptr: %p\n", ptr);
    return 0;
}
```
Output:
```bash
dia chi a: 00007FF68E0D3000
gia tri ptr: 00007FF68E0D3000
```
## Các loại con trỏ:
### 1. Function pointer: Function pointer (con trỏ hàm) là một biến lưu trữ địa chỉ của một hàm. Nó cho phép gọi hàm thông qua con trỏ, tức là có thể gọi hàm mà không cần biết tên cụ thể của hàm đó, chỉ cần biết địa chỉ của nó. Con trỏ hàm rất hữu ích khi cần linh hoạt trong việc gọi các hàm khác nhau tại runtime.
#### Ví dụ:
```bash
#include <stdio.h>
#include <assert.h>

void tong(int a, int b){
    printf("Tong %d va %d: %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a-b);
}

void tich(int a, int b){
    printf("Tich %d va %d: %d\n", a, b, a*b);
}

void thuong(int a, int b){
    assert(b != 0);
    printf("Thuong %d va %d: %f\n", a, b, (double)a/b);
}

int main(int argc, char const *argv[])
{
    void (*ptr)(int, int);

    ptr = &tong;

    ptr(7, 7);

    return 0;
}
```
Output:
```bash
Tong 7 va 7: 14
```

#### Con trỏ kiểu trả về như thế nào thì sẽ trỏ đến hàm đó
#### Ví dụ:
```bash
#include <stdio.h>
#include <assert.h>

void tong(int a, int b){
    printf("Tong %d va %d: %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a-b);
}

int tich(int a, int b){
    return a*b;
}

void thuong(int a, int b){
    assert(b != 0);
    printf("Thuong %d va %d: %f\n", a, b, (double)a/b);
}

int main(int argc, char const *argv[])
{
    void (*ptr)(int, int);

    

    int (*test)(int, int);

    test = &tich;

    printf("Tich: %d\n", test(7, 7));

    return 0;
}
```
Output:
```bash
Tich: 49
```
Con trỏ ở bài này kiểu trả về là int nên sẽ trỏ đến hàm int
#### Có thể tạo ra một mảng để lưu các địa chỉ của các Function pointer (con trỏ hàm) 
#### Ví dụ:
```bash
#include <stdio.h>
#include <assert.h>

void tong(int a, int b){  // 0xc1 - 0xc9
    printf("Tong %d va %d: %d\n", a, b, a + b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a - b);
}

void tich(int a, int b){
    printf("Tich %d va %d: %d\n", a, b, a * b);
}

void thuong(int a, int b){
    assert(b != 0);
    printf("Thuong %d va %d: %f\n", a, b, (double)a / b);
}
int main(int argc, char const *argv[])
{
    void (*array[4])(int, int) = {&tong, &hieu, &tich, &thuong};

    array[0](5, 5);
    array[2](7, 7);

    return 0;
}
```
Output:
```bash
Tong 5 va 5: 10
Tich 7 va 7: 49
```
#### Ứng dụng Function pointer (con trỏ hàm) khi tham số truyền vào là một hàm:
#### Ví dụ:
```bash
#include <stdio.h>
#include <assert.h>

void tong(int a, int b){  
    printf("Tong %d va %d: %d\n", a, b, a + b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a - b);
}

void tich(int a, int b){
    printf("Tich %d va %d: %d\n", a, b, a * b);
}

void thuong(int a, int b){
    assert(b != 0);
    printf("Thuong %d va %d: %f\n", a, b, (double)a / b);
}
void tinhToan(void (*ptr)(int, int), int a, int b){
    printf("Thuc hien phep toan duoi:\n");
    ptr(a, b);
}

int main(int argc, char const *argv[])
{
    tinhToan(&tich, 5, 5);
    tinhToan(&thuong, 7, 7);

    return 0;
}
```
Output:
```bash
Thuc hien phep toan duoi:
Tich 5 va 5: 25
Thuc hien phep toan duoi:
Thuong 7 va 7: 1.000000
```
### 2. Void pointer: Void pointer (con trỏ void) là một loại con trỏ có thể trỏ đến bất kỳ kiểu dữ liệu nào. Vì nó không có kiểu dữ liệu cụ thể, bạn không thể truy xuất hoặc thao tác trực tiếp với giá trị mà nó trỏ đến mà không cần phải ép kiểu (type-casting) sang con trỏ của kiểu dữ liệu cụ thể trước. Con trỏ void rất linh hoạt và thường được sử dụng trong các hàm mà loại dữ liệu cụ thể của tham số chưa được biết trước
#### Cách khai báo:
```bash
void *ptr_void;
```
#### Ví dụ:
```bash
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a = 10;
    char c = 'A';
    double d = 10.3;
    void *ptr = &a;

    printf("Gia tri: %p\n", ptr);

    ptr = &c;

    printf("Gia tri: %p\n", ptr);

    ptr = &d;

    printf("Gia tri: %p\n", ptr);

    return 0;
}
```
Output:
```bash
Gia tri: 00000053235FFE24
Gia tri: 00000053235FFE23
Gia tri: 00000053235FFE18
```
#### Void pointer (con trỏ void) có thể trỏ đến địa chỉ nhưng không thể in ra giá trị của địa chỉ vì không xác định được kiểu dữ liệu của giá trị địa chỉ nên nếu muốn in giá trị địa chỉ thì phải thêm kiểu giá trị 
#### Ví dụ:
```bash
#include <stdio.h>
#include <assert.h>

void tong(int a, int b){  
    printf("Tong %d va %d: %d\n", a, b, a + b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a - b);
}

void tich(int a, int b){
    printf("Tich %d va %d: %d\n", a, b, a * b);
}

void thuong(int a, int b){
    assert(b != 0);
    printf("Thuong %d va %d: %f\n", a, b, (double)a / b);
}
void tinhToan(void (*ptr)(int, int), int a, int b){
    printf("Thuc hien phep toan duoi:\n");
    ptr(a, b);
}

int main(int argc, char const *argv[])
{
    int a = 20;
    char c = 'H';
    double d = 20.5;

    void *ptr = &a;

    printf("Gia tri: %p\n", ptr);
    printf("Gia tri a: %d\n", *(int *)ptr);

    ptr = &c;

    printf("Gia tri: %p\n", ptr);
    printf("Gia tri c: %c\n", *(char *)ptr);

    ptr = &d;

    printf("Gia tri: %p\n", ptr);
    printf("Gia tri d: %f\n", *(double *)ptr);

    ptr = &tich;

    printf("Gia tri: %p\n", ptr);
    ((void(*)(int, int))ptr)(7, 7);

    return 0;
}


```
Output:
```bash
Gia tri: 00000001001FFD24
Gia tri a: 20
Gia tri: 00000001001FFD23
Gia tri c: H
Gia tri: 00000001001FFD18
Gia tri d: 20.500000
Gia tri: 00007FF6106E14C5
Tich 7 va 7: 49
```
### 3. NULL pointer: NULL pointer là một con trỏ không trỏ đến bất kỳ địa chỉ bộ nhớ hợp lệ nào, thường được gán giá trị NULL để biểu thị rằng nó không trỏ đến đâu cả. NULL pointer (con trỏ NULL) có địa chỉ = 0 và tại địa chỉ có giá trị = 0
### 4. Pointer to Constant: Pointer to Constant (Con trỏ tới hằng số) là một loại con trỏ mà giá trị của dữ liệu mà nó trỏ tới không thể bị thay đổi thông qua con trỏ đó. Nói cách khác, con trỏ có thể trỏ tới một địa chỉ khác, nhưng không thể thay đổi giá trị của dữ liệu tại địa chỉ mà nó đang trỏ tới.
#### Cú pháp:
```bash
const int *ptr;
```
### 5. Constant Pointer: Constant Pointer (Con trỏ hằng) là một loại con trỏ mà địa chỉ mà nó trỏ tới không thể thay đổi sau khi đã được gán. Nói cách khác, con trỏ phải luôn trỏ tới cùng một địa chỉ trong suốt thời gian tồn tại của nó, nhưng giá trị của dữ liệu tại địa chỉ đó có thể thay đổi.
#### Cú pháp:
```bash
int *const ptr;
```
#### 6. 








