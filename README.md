# Bài 1: Compiler - Macro
<details><summary>Chi tiết</summary>
<p>

## Compiler

<details><summary>Chi tiết</summary>
<p>

    
#### Trình biên dịch (compiler) trong C/C++ là công cụ chuyển đổi mã nguồn từ ngôn ngữ lập trình cấp cao (C hoặc C++) sang mã máy hoặc mã thực thi để máy tính có thể hiểu và thực hiện.

</p>
</details>

### 1. Preprocessor

<details><summary>Chi tiết</summary>
<p>

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
</p>
</details>


##### 1.1 Marco Function

<details><summary>Chi tiết</summary>
<p>

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

</p>
</details>

### 2. Compiler

<details><summary>Chi tiết</summary>
<p>

#### Sau khi Preprocessor sẽ tới compiler. Quá trình này được gọi là assembly code sẽ tạo file main.i thành file main.s
#####  gcc main.i -S -o main.s
##### Ví dụ:
![image](https://github.com/user-attachments/assets/62d3ec86-296a-4671-adda-c8dc088ef51b)
##### Sau khi gcc bai1_3.i -S -o bai1_3.s
![image](https://github.com/user-attachments/assets/04053350-1d78-47f7-8afb-82b63027e28b)

</p>
</details>

### 3. Assembler

<details><summary>Chi tiết</summary>
<p>

#### Assembly code qua quá trình Assembler sẽ tạo ra Object file ( mã để nạp vào trong máy )
#### gcc main.s -o main.o

</p>
</details>

### 4. Linker

<details><summary>Chi tiết</summary>
<p>

#### Linker là gộp những file object lại thành file cuối cùng sẽ tạo ra executable file
#### gcc test1.o test2.o -o main
./main

</p>
</details>


</p>
</details>

# Bài 2: STDARG - ASSERT 

<details><summary>Chi tiết</summary>
<p>


## 1.Thư viện Stdarg :

<details><summary>Chi tiết</summary>
<p>

Thư viện Stdarg (stdarg.h) trong C cung cấp các macro để xử lý các hàm có số lượng đối số không xác định. Nó cho phép bạn viết các hàm có thể nhận bất kỳ số lượng đối số nào, chẳng hạn như printf.
### Va_list: được sử dụng để khai báo một biến mà có thể lưu trữ và truy cập các đối số không cố định của một hàm
### Va_start: dùng để khởi tạo một biến kiểu va_list trước khi truy cập các đối số không cố định của một hàm. Nó cần tham số là đối số cố định cuối cùng của hàm để xác định vị trí bắt đầu của các đối số không cố định. 
### Va_arg: Lấy đối số tiếp theo trong danh sách 
### Va_end: được sử dụng để kết thúc việc truy cập các đối số không cố định của một hàm. Nó cần được gọi trước khi kết thúc hàm

</p>
</details>

## 2. Thư viện assert:

<details><summary>Chi tiết</summary>
<p>

### Thư viện assert cung cấp macro assert để kiểm tra các điều kiện tại thời điểm chạy chương trình. Nếu điều kiện kiểm tra là sai, chương trình sẽ dừng thực thi và hiển thị thông báo lỗi với thông tin về tệp tin và dòng mã nơi xảy ra lỗi. assert chủ yếu được sử dụng trong quá trình gỡ lỗi để đảm bảo các điều kiện tiên quyết được đáp ứng.

</p>
</details>

</p>
</details>

# Bài 3: Pointer

<details><summary>Chi tiết</summary>
<p>

##  Pointer:

<details><summary>Chi tiết</summary>
<p>

Pointer là một biến lưu trữ địa chỉ của một biến khác. Pointer không lưu giá trị trực tiếp mà lưu trữ địa chỉ của vùng nhớ nơi giá trị đó được lưu trữ. Điều này cho phép thao tác trực tiếp với vùng nhớ, truy cập và thay đổi giá trị của biến thông qua địa chỉ mà pointer trỏ tới.
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

</p>
</details>

## Các loại con trỏ:

<details><summary>Chi tiết</summary>
<p>

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
### 6. Pointer to Pointer: Pointer to Pointer (con trỏ trỏ tới con trỏ) là một con trỏ lưu trữ địa chỉ của một con trỏ khác. Nó cho phép bạn gián tiếp truy cập và thao tác với dữ liệu mà con trỏ ban đầu trỏ tới. Trong C/C++, pointer to pointer được khai báo bằng cách sử dụng hai dấu *.
#### Cú pháp:
```bash
int **pp;
```

</p>
</details>

</p>
</details>

# Bài 4: Extern - Static - Volatile

<details><summary>Chi tiết</summary>
<p>

## 1. Extern:

<details><summary>Chi tiết</summary>
<p>

Extern: Có thể lấy được những biến toàn cục và những hàm toàn cục của những file.c khác kết nối đến file muốn sử dụng

Ở file bai4.c
```bash
#include <stdio.h>

extern int cout;    // External integer variable
extern void display();  // External function

int main(int argc, char const *argv[])
{
    display();
    cout = 50;
    printf("Test: %d\n", cout);
    display();
    return 0;
}
```

Ở file bai4_1.c
```bash
#include <stdio.h>

int cout = 10;  // Definition of the variable cout with an initial value of 10

void display() {
    printf("test.c : %d\n", cout);
}
```

Sử dụng câu lệnh:
```bash
gcc -c bai4.c -o bai4.o
gcc -c bai4_1.c -o bai4_1.o
gcc bai4.o bai4_1.o -o bai4
./bai4
```

Kết quả:
```bash
test.c : 10
Test: 50
test.c : 50
```
</p>
</details>


## 2. Static:

<details><summary>Chi tiết</summary>
<p>

2.1: Static local variables:

`Static local variables` (biến cục bộ tĩnh) là một biến được khai báo bên trong một hàm với từ khóa `static`. Biến chỉ được khởi tạo một lần duy nhất khi chương trình chạy, và giá trị của nó được giữ nguyên giữa các lần gọi hàm, thay vì bị hủy và khởi tạo lại mỗi khi hàm được gọi như biến cục bộ thông thường. Phạm vi của biến cục bộ tĩnh vẫn bị giới hạn trong hàm mà nó được khai báo, nhưng thời gian sống của nó kéo dài suốt quá trình thực thi của chương trình

Ví dụ:
```bash
#include <stdio.h>

void demLanGoiHam() {
    static int dem = 0; // Biến cục bộ tĩnh
    dem++;
    printf("Hàm đã được gọi %d lần\n", dem);
}

int main() {
    demLanGoiHam(); // Kết quả: Hàm đã được gọi 1 lần
    demLanGoiHam(); // Kết quả: Hàm đã được gọi 2 lần
    demLanGoiHam(); // Kết quả: Hàm đã được gọi 3 lần

    return 0;
}
```

Kết quả:
```
Hàm đã được gọi 1 lần
Hàm đã được gọi 2 lần
Hàm đã được gọi 3 lần
```
2.2: Static global variables:

 `Static global variables` (biến toàn cục tĩnh) là biến được khai báo ở phạm vi toàn cục (ngoài các hàm) với từ khóa `static`. Khác với biến toàn cục thông thường, biến toàn cục tĩnh có phạm vi chỉ giới hạn trong tệp tin (file) mà nó được khai báo, nghĩa là nó không thể được truy cập từ các tệp tin khác trong chương trình (ngay cả khi sử dụng từ khóa `extern`)

- Phạm vi: Biến toàn cục tĩnh chỉ có phạm vi trong tệp tin mà nó được khai báo, giúp tránh việc bị truy cập hoặc sửa đổi ngoài ý muốn từ các tệp tin khác trong chương trình

- Thời gian tồn tại: Biến toàn cục tĩnh có thời gian sống kéo dài suốt thời gian chạy của chương trình, từ khi chương trình bắt đầu cho đến khi kết thúc, giống như các biến toàn cục thông thường

- Khả năng truy cập: Do chỉ có phạm vi trong tệp tin, biến toàn cục tĩnh không thể bị truy cập trực tiếp từ các tệp tin khác, giúp tăng tính bảo mật và ổn định của chương trình

 Ví dụ:
 ```bash
#include <stdio.h>

static int soDem = 0; // Biến toàn cục tĩnh

void tangDem() {
    soDem++;
    printf("So dem: %d\n", soDem);
}

int main() {
    tangDem(); // Kết quả: So dem: 1
    tangDem(); // Kết quả: So dem: 2
    tangDem(); // Kết quả: So dem: 3

    return 0;
}
```

Kết quả:
```bash
So dem: 1
So dem: 2
So dem: 3
```

</p>
</details>

## 3. Volatile

<details><summary>Chi tiết</summary>
<p>

`Volatile` được sử dụng để khai báo một biến mà giá trị của nó có thể thay đổi mà không cần thông qua chương trình hiện tại. Điều này thường xảy ra trong các trường hợp khi biến có thể bị thay đổi bởi phần cứng, bởi một tín hiệu ngắt, hoặc bởi một luồng khác trong một chương trình đa luồng

Ví dụ có một hệ thống nhúng với một nút nhấn kết nối với một chân GPIO của vi điều khiển. Khi nút được nhấn, một biến sẽ được cập nhật để báo hiệu cho chương trình chính rằng có một sự kiện xảy ra:
```bash
#include <stdio.h>

// Biến để theo dõi trạng thái của nút nhấn
volatile int buttonPressed = 0;

// Hàm giả lập ngắt từ GPIO khi nút nhấn được bấm
void gpio_interrupt_handler() {
    // Ngắt xảy ra khi nút nhấn được bấm, cập nhật biến buttonPressed
    buttonPressed = 1;
}

int main() {
    // Cấu hình ngắt GPIO và các thiết lập khác

    // Chờ cho đến khi nút nhấn được bấm
    while (buttonPressed == 0) {
        // Vòng lặp liên tục kiểm tra biến buttonPressed
        // Do buttonPressed là volatile, giá trị sẽ luôn được đọc từ bộ nhớ
        // và không bị trình biên dịch tối ưu hóa
    }

    // Khi nút nhấn được bấm (buttonPressed == 1), tiếp tục thực hiện công việc
    printf("Button pressed!\n");

    // Sau khi xử lý, có thể reset lại buttonPressed để chờ lần nhấn tiếp theo
    buttonPressed = 0;

    return 0;
}
```

Nếu không có từ khóa `volatile`, trình biên dịch có thể tối ưu hóa vòng lặp này bằng cách giữ giá trị của `buttonPressed` trong một thanh ghi và vòng lặp có thể không bao giờ thoát ra, ngay cả khi nút đã được nhấn

</p>
</details>

## 4. Register:

<details><summary>Chi tiết</summary>
<p>

`Register` được sử dụng để khai báo một biến với gợi ý cho trình biên dịch rằng biến này sẽ được truy cập rất nhiều và nên được lưu trữ trong thanh ghi (register) của CPU thay vì trong bộ nhớ chính. Việc này có thể làm tăng hiệu suất chương trình bởi vì truy cập vào các thanh ghi nhanh hơn nhiều so với truy cập vào bộ nhớ

- Tốc độ truy cập nhanh: Biến `register` có khả năng được lưu trữ trong các thanh ghi của CPU, giúp tăng tốc độ truy cập và thao tác với biến

- Không có địa chỉ: Biến được khai báo với từ khóa `register` không có địa chỉ bộ nhớ như các biến thông thường, vì vậy bạn không thể lấy địa chỉ của nó bằng toán tử `&`

- Phạm vi: Biến `register` chỉ có thể là biến cục bộ hoặc tham số của hàm, không thể là biến toàn cục

  Ví dụ:
  ```bash
  #include <stdio.h>
  void demTu0Den9() {
    for (register int i = 0; i < 10; i++) {
        printf("%d ", i);
    }
    printf("\n");
  }
  int main() {
    demTu0Den9(); // In ra các số từ 0 đến 9
    return 0;
  }

Kết quả:
```
  0 1 2 3 4 5 6 7 8 9
```
</p>
</details>

</p>
</details>


# Bài 5: Goto - setjmp.h

<details><summary>Chi tiết</summary>
<p>

## 1: Goto:

<details><summary>Chi tiết</summary>
<p>

`goto` là một từ khóa được sử dụng để nhảy đến một phần khác trong chương trình, được xác định bởi một nhãn. Câu lệnh `goto` có thể được dùng để điều hướng chương trình đến vị trí cụ thể, không phụ thuộc vào cấu trúc điều khiển thông thường như vòng lặp hoặc điều kiện

Cú pháp:
```bash
label: // Nhãn
    // Mã lệnh
    goto label; // Nhảy đến nhãn
```

Ví dụ:
```bash
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i = 0;

    // đặt label start
start:
    if (i >= 5) {
        goto end;  // chuyển control đến label "end"
    }
    printf("%d\n", i);
    i++;
    goto start;

    // đặt label end
end:
    printf("The end\n"); // chuyển control đến label "start"

    return 0;
}
```
Kết quả:
```
0
1
2
3
4
The end
```
Ở đoạn code trên sử dụng lệnh `goto` để lặp qua các giá trị từ 0 đến 4, in từng giá trị ra màn hình. Khi giá trị đạt 5, chương trình nhảy đến phần kết thúc và in "The end" trước khi kết thúc chương trình

Chúng ta có thể sử dụng `goto` để thay thế cho `break` hoặc các phương pháp khác khi cần thoát ra khỏi một số lượng lớn các vòng lặp lồng nhau

Ví dụ:
```bash
#include <stdio.h>

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2) {
                goto end_loop;  // Thay thế `break` bằng `goto`
            }
            printf("i = %d, j = %d\n", i, j);
        }
    end_loop:;  // Đặt label để tiếp tục vòng lặp chính
    }

    return 0;
}
```

</p>
</details>

## 2. setjump.h

<details><summary>Chi tiết</summary>
<p>

`<setjmp.h>` cung cấp cơ chế để thực hiện "non-local jumps," cho phép chương trình nhảy ra khỏi một hàm từ sâu bên trong một chuỗi gọi hàm mà không cần quay trở lại từng hàm một

Thư viện `<setjmp.h>` định nghĩa hai hàm chính: `setjmp` và `longjmp` có cú pháp như sau:

- Trước tiên, cần khai báo một biến kiểu `jmp_buf`:
```bash
jmp_buf buffer;  // Tên biến là `buffer`, kiểu dữ liệu là `jmp_buf` (kiểu này được định nghĩa sẵn bởi thư viện).
```

- Sử dụng `setjmp` để lưu trữ trạng thái của môi trường tại điểm mà nó được gọi, `setjmp` sẽ trả về 0 nếu nó được gọi lần đầu tiên:

```bash
int val = setjmp(buffer);  // val = 0
```

- Sử dụng `longjmp`, chương trình sẽ quay trở lại điểm mà `setjmp` đã được gọi, và setjmp sẽ trả về giá trị là một số nguyên (không bao giờ là 0, vì giá trị 0 đặc biệt để nhận diện việc gọi `setjmp` lần đầu tiên)

```bash
longjmp(buffer, 1);  // Nhảy trở lại điểm trước đó với giá trị trả về val = 1
```

Ví dụ:
```bash
#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer; // Khai báo một biến kiểu jmp_buf để lưu trữ trạng thái chương trình

void functionA() {
    printf("Đang trong functionA\n");
    longjmp(buffer, 1); // Nhảy trở lại điểm setjmp với giá trị trả về là 1
    printf("Điều này sẽ không bao giờ được in ra\n"); // Dòng này sẽ không được thực hiện
}

int main() {
    int val = setjmp(buffer); // Lưu trữ trạng thái của chương trình tại đây

    if (val == 0) {
        printf("Lần đầu gọi setjmp, val = %d\n", val);
        functionA(); // Gọi hàm functionA, hàm này sẽ sử dụng longjmp
    } else {
        printf("Quay lại từ longjmp, val = %d\n", val);
    }

    return 0;
}
```

Kết quả:
```
Lần đầu gọi setjmp, val = 0
Đang trong functionA
Quay lại từ longjmp, val = 1
```

Như vậy, ví dụ cho thấy cách `setjmp` và `longjmp` có thể được sử dụng để kiểm soát luồng chương trình một cách đặc biệt, thường phục vụ cho mục đích xử lý ngoại lệ hoặc khôi phục trạng thái trong các ứng dụng phức tạp

Hai hàm `setjmp/longjmp` thường được sử dụng để thực hiện xử lý ngoại lệ

Ví dụ xử lý ngoại lệ khi chia cho 0:

```bash
#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer; // Biến jmp_buf để lưu trữ trạng thái chương trình

void divide(int a, int b) {
    if (b == 0) {
        printf("Lỗi: Chia cho 0!\n");
        longjmp(buffer, 1); // Nhảy trở lại điểm setjmp với giá trị trả về là 1
    } else {
        printf("Kết quả của %d / %d = %d\n", a, b, a / b);
    }
}

int main() {
    int val = setjmp(buffer); // Lưu trạng thái của chương trình tại đây

    if (val == 0) { // Thực hiện khi không có lỗi xảy ra
        divide(10, 2); // Chia bình thường
        divide(10, 0); // Chia cho 0 sẽ kích hoạt longjmp
        printf("Điều này sẽ không bao giờ được in ra sau lỗi chia cho 0\n");
    } else { // Thực hiện khi longjmp được gọi (khi có lỗi chia cho 0)
        printf("Đã xử lý ngoại lệ chia cho 0, tiếp tục chương trình.\n");
    }

    printf("Kết thúc chương trình.\n");

    return 0;
}
```

Kết quả:
```
Kết quả của 10 / 2 = 5
Lỗi: Chia cho 0!
Đã xử lý ngoại lệ chia cho 0, tiếp tục chương trình.
Kết thúc chương trình.
```

Trong ví dụ này, `setjmp` và `longjmp` được sử dụng để xử lý tình huống chia cho 0 như một ngoại lệ.
Khi phát hiện chia cho 0, chương trình không bị dừng đột ngột mà thay vào đó sẽ nhảy đến phần xử lý ngoại lệ, tiếp tục thực thi phần còn lại của chương trình một cách an toàn


</p>
</details>

</p>
</details>


# Bài 6: Bitmask

<details><summary>Chi tiết</summary>
<p>


`Bitmask` là một kỹ thuật sử dụng các phép toán bitwise để thao tác trên các bit của một số nguyên. Cho phép thiết lập, xóa, kiểm tra, hoặc đảo ngược các bit cụ thể trong một biến. `Bitmask` thường được sử dụng để quản lý các cờ (flags) hoặc trạng thái, giúp tối ưu hóa việc sử dụng bộ nhớ và thực hiện các phép toán logic hiệu quả trên các bit

## NOT bitwise

<details><summary>Chi tiết</summary>
<p>


`NOT bitwise` được biểu diễn bằng ký hiệu `~`.Được sử dụng để đảo ngược tất cả các bit trong một số nguyên (hoặc bất kỳ kiểu dữ liệu nào hỗ trợ các phép toán bitwise)

Ví dụ:
```bash
uint8_t value = 0b00001101;
uint8_t not_value = ~value;  // Sử dụng toán tử NOT bitwise
```

Kết quả:
```
00001101
```

</p>
</details>

## OR bitwise

<details><summary>Chi tiết</summary>
<p>


`OR bitwise` được biểu diễn bằng ký hiệu |. `OR bitwise` thực hiện phép OR trên từng cặp bit tương ứng của hai số nguyên.
- Nếu ít nhất một trong các bit là 1, bit kết quả sẽ là 1
- Nếu cả hai bit đều là 0, bit kết quả sẽ là 0.

Cách hoạt động:
- 0 | 0 = 0
- 0 | 1 = 1
- 1 | 0 = 1
- 1 | 1 = 1

Ví dụ:
```bash
uint8_t a = 0b11001010;  // Số thứ nhất
uint8_t b = 0b10110110;  // Số thứ hai
uint8_t result = a | b;  // Áp dụng OR bitwise
```

Kết quả:
```
11001010
10110110
--------
11111110
```

</p>
</details>

## XOR bitwise:

<details><summary>Chi tiết</summary>
<p>


`XOR bitwise` được biểu diễn bằng ký hiệu `^`.Thực hiện phép XOR trên từng cặp bit tương ứng của hai số nguyên

`XOR` trả về 1 khi hai bit khác nhau và trả về 0 khi hai bit giống nhau

Cách hoạt động:
- 0 ^ 0 = 0
- 0 ^ 1 = 1
- 1 ^ 0 = 1
- 1 ^ 1 = 0

Ví dụ:
```bash
uint8_t a = 0b11001010;  // Số thứ nhất
uint8_t b = 0b10110110;  // Số thứ hai
uint8_t result = a ^ b;  // Áp dụng XOR bitwise
```

Kết quả:
```
  11001010
^ 10110110
----------
  01111100
```

</p>
</details>

## Shift left bitwise:

<details><summary>Chi tiết</summary>
<p>


`Shift left bitwise` trong C được biểu diễn bằng ký hiệu `<<`. `Shift left bitwise`  dịch chuyển các bit của một số về phía trái một số vị trí xác định, điền vào các vị trí bên phải bằng các bit 0. Mỗi lần dịch chuyển về trái một vị trí, giá trị của số sẽ được nhân đôi

Cú pháp:
```bash
result = value << n;
```

Ví dụ:
```bash
uint8_t value = 0b00001101;   // Giá trị ban đầu: 13 (00001101)
uint8_t shifted_value = value << 2;  // Dịch trái 2 bit
```

Kết quả:
```
00001101 << 2
----------
00110100
```

</p>
</details>

## Shift right bitwise:

<details><summary>Chi tiết</summary>
<p>



`Shift right bitwise` được biểu diễn bằng ký hiệu `>>`. Shift right bitwise dịch chuyển các bit của một số về phía phải một số vị trí xác định, điền vào các vị trí bên trái bằng các bit 0 (nếu là số không dấu) hoặc sao chép bit dấu (nếu là số có dấu)

Cú pháp:
```bash
result = value >> n;
```

Ví dụ:
```bash
uint8_t value = 0b00101100;   // Giá trị ban đầu: 44 (00101100)
uint8_t shifted_value = value >> 2;  // Dịch phải 2 bit
```

Kết quả:
```
00101100 >> 2
----------
00001011
```

</p>
</details>

</p>
</details>


# Bài 7: Struct - Union

<details><summary>Chi tiết</summary>
<p>

## 1: Struct

<details><summary>Chi tiết</summary>
<p>

`struct` là một kiểu dữ liệu do người dùng định nghĩa, cho phép nhóm nhiều biến thuộc các kiểu dữ liệu khác nhau lại với nhau dưới một tên chung

Cách khai báo:
```bash
struct TenCauTruc {
    kieu_du_lieu1 ten_bien1;
    kieu_du_lieu2 ten_bien2;
};
```

Ví dụ:
```bash
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t  arr1[8];  
    uint64_t arr4[7]; 
    uint16_t arr2[6]; 
    uint32_t arr3[5];  
} frame;

int main(int argc, char const *argv[])
{
    printf("kich thuoc: %lu byte\n", sizeof(frame));
    return 0;
}
```

Kết quả:
```
kich thuoc: 96 byte
```

Ở ví dụ trên ta có:

Cấu trúc `frame`:

- `arr1[8]`: Mảng `uint8_t` có 8 phần tử. Mỗi phần tử `uint8_t` chiếm 1 byte, nên tổng cộng `arr1` chiếm 8 byte.

  
- `arr4[7]`: Mảng `uint64_t` có 7 phần tử. Mỗi phần tử `uint64_t` chiếm 8 byte, nên tổng cộng `arr4` chiếm 56 byte.
  
- `arr2[6]`: Mảng `uint16_t` có 6 phần tử. Mỗi phần tử `uint16_t` chiếm 2 byte, nên tổng cộng `arr2` chiếm 12 byte.
  
- `arr3[5]`: Mảng `uint32_t` có 5 phần tử. Mỗi phần tử `uint32_t` chiếm 4 byte, nên tổng cộng arr3 chiếm 20 byte

Kích thước `struct frame`:

Tổng kích thước sẽ là 8 byte `arr1` + 56 byte `arr4` + 12 byte `arr2` + 20 byte `arr3` = 96 byte.

</p>
</details>

## 2. Union

<details><summary>Chi tiết</summary>
<p>

`union` là một kiểu dữ liệu do người dùng định nghĩa tương tự như `struct`, nhưng với một điểm khác biệt : tất cả các thành viên của `union` chia sẻ cùng một vị trí bộ nhớ. Chỉ có một trong các thành viên có thể lưu trữ giá trị tại một thời điểm, và kích thước của union sẽ bằng kích thước của thành viên lớn nhất

Cách khai báo:
```bash
union TenUnion {
    kieu_du_lieu1 ten_bien1;
    kieu_du_lieu2 ten_bien2;
};
```

Ví dụ:
```bash
#include <stdio.h>
#include <stdint.h>

typedef union {
    uint8_t  arr1;      // 1 byte
    uint32_t arr2;      // 4 byte
    uint16_t arr3;      // 2 byte
} frame;

int main(int argc, char const *argv[])
{
    printf("Size = %lu\n", sizeof(frame));  // In kích thước của union

    frame data;

    printf("Dia chi: %p\n", (void*)&data);                // Địa chỉ của toàn bộ union
    printf("Dia chi data.arr1: %p\n", (void*)&data.arr1); // Địa chỉ của arr1
    printf("Dia chi data.arr2: %p\n", (void*)&data.arr2); // Địa chỉ của arr2
    printf("Dia chi data.arr3: %p\n", (void*)&data.arr3); // Địa chỉ của arr3

    // Gán giá trị cho các thành viên của union
    data.arr1 = 1;
    printf("arr1 = %d\n", data.arr1);  // In giá trị của arr1

    data.arr2 = 2;
    printf("arr2 = %d\n", data.arr2);  // In giá trị của arr2

    data.arr3 = 3;
    printf("arr3 = %d\n", data.arr3);  // In giá trị của arr3

    return 0;
}
```

Kết quả:
```
Size = 4
Dia chi: 00000083821FF89C
Dia chi data.arr1: 00000083821FF89C
Dia chi data.arr2: 00000083821FF89C
Dia chi data.arr3: 00000083821FF89C
arr1 = 1
arr2 = 2
arr3 = 3
```

Ở ví dụ trên ta có:

Kích thước union:

Khai báo một union có tên là `frame`. union này chứa ba thành viên:

- `arr1`: Biến kiểu uint8_t (1 byte).

- `arr2`: Biến kiểu uint32_t (4 byte).
  
- `arr3`: Biến kiểu uint16_t (2 byte).

  
Kích thước của union được xác định bởi thành viên có kích thước lớn nhất. Như vậy `arr2` có kích thước lớn nhất (4 byte), nên kích thước của `frame` sẽ là 4 byte.

Gán giá trị:

Lần lượt gán các giá trị cho từng thành viên của union:

- `data.arr1 = 1`: Gán giá trị 1 cho `arr1`

- `data.arr2 = 2`: Gán giá trị 2 cho `arr2`, ghi đè giá trị trong arr1.

- `data.arr3 = 3`: Gán giá trị 3 cho `arr3`, ghi đè giá trị trong arr2.

Sau mỗi lần gán, chương trình in ra giá trị của thành viên đó. Do chia sẻ cùng một vùng nhớ, mỗi lần gán mới sẽ ghi đè lên giá trị trước đó.

</p>
</details>

## Ứng dụng kết hợp struct và union:

<details><summary>Chi tiết</summary>
<p>


Kết hợp struct và union rất hữu ích trong các hệ thống nhúng, giao thức truyền thông, hoặc bất kỳ ứng dụng nào cần tiết kiệm bộ nhớ mà vẫn duy trì tính linh hoạt trong việc xử lý nhiều loại dữ liệu. Cho phép  tạo ra các cấu trúc dữ liệu phức tạp mà không tiêu tốn nhiều bộ nhớ hơn mức cần thiết

Ví dụ:
```bash
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_STRING_SIZE 20

// Định nghĩa gói dữ liệu bằng struct và union
typedef struct {
    uint8_t type;  // Loại dữ liệu: 1 = integer, 2 = float, 3 = string
    union {
        int i;
        float f;
        char str[MAX_STRING_SIZE];
    } data;
} DataPacket;

void printDataPacket(const DataPacket* packet) {
    printf("Data type: %u\n", packet->type);
    switch (packet->type) {
        case 1:
            printf("Integer: %d\n", packet->data.i);
            break;
        case 2:
            printf("Float: %f\n", packet->data.f);
            break;
        case 3:
            printf("String: %s\n", packet->data.str);
            break;
        default:
            printf("Unknown type\n");
    }
}

int main() {
    DataPacket packet;

    // Gói dữ liệu chứa số nguyên
    packet.type = 1;
    packet.data.i = 42;
    printDataPacket(&packet);

    // Gói dữ liệu chứa số thực
    packet.type = 2;
    packet.data.f = 3.14f;
    printDataPacket(&packet);

    // Gói dữ liệu chứa chuỗi ký tự
    packet.type = 3;
    strncpy(packet.data.str, "Hello, World!", MAX_STRING_SIZE);
    printDataPacket(&packet);

    return 0;
}
```

Kết quả:
```
Data type: 1
Integer: 42
Data type: 2
Float: 3.140000
Data type: 3
String: Hello, World!
```

Ở ví dụ trên ta có:

- `union` giúp tiết kiệm bộ nhớ vì nó chỉ chiếm một lượng bộ nhớ đủ lớn để chứa thành viên lớn nhất. Nếu `MAX_STRING_SIZE` là giá trị lớn nhất, kích thước của `union` sẽ bằng kích thước của `char[MAX_STRING_SIZE]`

- `struct DataPacket` cho phép bạn tạo ra một gói dữ liệu (data packet) mà có thể chứa một số nguyên, một số thực, hoặc một chuỗi ký tự, nhưng chỉ một trong ba loại dữ liệu này tại một thời điểm.

- Sử dụng `type` để xác định loại dữ liệu hiện tại trong gói, bạn có thể biết được cách đọc hoặc xử lý giá trị trong `union`

</p>
</details>

</p>
</details>

# Bài 8: Memory layout

<details><summary>Chi tiết</summary>
<p>

Chương trình main.exe (trên window), main.hex (nạp vào vi điều khiển) được lưu ở bộ nhớ SSD (ROM) hoặc FLASH. Khi nhấn run chương trình trên window (cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi

## 1. Text segment

Bao gồm:

- Mã máy tập hợp các lệnh thực thi
- Hằng số (const), con trỏ kiểu char

Quyền truy cập thường chỉ có quyền đọc và thực thi, nhưng không có quyền ghi

Tất cả các biến lưu ở phần vùng Text đều không thể thay đổi giá trị mà chỉ được đọc

```c

#include <stdio.h>

const int a = 10;			//Hằng số
char *arr1 = "Hello";			//Con trỏ kiểu char

int main() {
    //a=10;             		//Không được phép thay đổi->Bị lỗi
    //arr1[3] = 'E';

    printf("a: %d\n", a);
    printf("arr1: %s", arr1);

    return 0;
}
```
## 2. Data segment

Hay còn gọi là phân vùng Initialized Data Segment (Dữ liệu Đã Khởi Tạo), bao gồm:

- Biến toàn cục được khởi tạo với giá trị khác 0
- Biến static được khởi tạo với giá trị khác 0

Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến

Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc

```c

#include <stdio.h>

int a = 10;			//Biến toàn cục khởi tạo khác 0
double d = 20.5;		//Biến toàn cục khởi tạo khác 0

static int var = 5;		//Biến static toàn cục khởi tạo khác 0

void test(){
    static int local = 10;	//Biến static cục bộ khởi tạo khác 0
}

int main(int argc, char const *argv[]){  
    a = 15;			//Có thể đọc và thay đổi giá trị của biến
    d = 25.7;
    var = 12;
    printf("a: %d\n", a);
    printf("d: %f\n", d);
    printf("var: %d\n", var);
    
    return 0;
}
```
## 3. Bss segment
Hay còn gọi là phân vùng Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo) gồm:
- Biến toàn cục khởi tạo với giá trị bằng 0 hoặc không gán giá trị
- Biến static với giá trị khởi tạo bằng 0 hoặc không gán giá trị

Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến

Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc

```c

#include <stdio.h>

typedef struct 			//Lưu ý: Đây là kiểu dữ liệu,
{				//nó không nằm bất kì trong phân vùng nào!	
    int x;
    int y;
} Point_Data;

int a = 0;			//Biến toàn cục khởi tạo bằng 0
int b;				//Biến toàn cục ko khởi tạo

static int global = 0;		//Biến static toàn cục khởi tạo bằng 0
static int global_2;		//Biến static toàn cục ko khởi tạo

static Point_Data p1 = {5,7};	//Lưu ý: biến p1 này đã khởi tạo có giá trị nên nằm ở DS

void test(){
    static int local = 0;	//Biến static cục bộ khởi tạo bằng 0
    static int local_2;		//Biến static cục bộ ko khởi tạo
}

int main() {
    global = 0;			//Lưu ý: dù thay đổi giá trị nó vẫn nằm ở BSS

    printf("a: %d\n", a);
    printf("global: %d\n", global);

    return 0;
}
```
## 4. Stack 

Phân vùng Stack chứa:
- Các biến cục bộ, tham số truyền vào

Quyền truy cập là đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy

Sau khi ra khỏi hàm, sẽ thu hồi vùng nhớ

Hoạt động theo kiểu LIFO(Last In Fist Out)

```c
#include <stdio.h>

void test(){
    int test = 0;
    test = 5;
    printf("test: %d\n",test);
}

int sum(int a, int b){
    int c = a + b;
    printf("sum: %d\n",c);
    return c;
}

int main() {
    sum(3,5);
    /*
        0x01
        0x02
        0x03
    */
   test();
   /*
    int test = 0; // 0x01
   */
  
    return 0;
}
```
## 5. Heap

Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình

Heap có quyền đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy

Nếu liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow)

Nếu khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại

Ví dụ:
```c
int *A = (int *)malloc(18446744073709551615);
```

Các hàm như `malloc()`, `calloc()`, `realloc()`, và `free()` được sử dụng để cấp phát và giải phóng bộ nhớ trên heap

### Hàm `malloc()`
Cấp phát một vùng nhớ có kích thước được xác định bằng số byte và trả về một con trỏ đến vùng nhớ này. 

Vùng nhớ được cấp phát nhưng không được khởi tạo (nội dung là ngẫu nhiên).

Tại sao gọi là ngẫu nhiên vì nó có thể chứa các giá trị rác từ trước đó, lập trình viên cần tự khởi tạo giá trị cho vùng nhớ sau khi cấp phát.

**Đây là điểm khác biệt so với calloc!**

**Ví dụ:**
```c
#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free
#include <stdint.h>

int main(int argc, char const *argv[]) {
    uint16_t *ptr = NULL;
    ptr = (uint16_t*)malloc(sizeof(uint16_t)*4); 	//0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08
    
    for (int i=0; i<4; i++) {
        ptr[i] = 2*i;
    }

    for (int i=0; i<8; i++) {
        printf("Địa chỉ: %p, giá trị: %d\n", (uint8_t*)ptr+i, *((uint8_t*)ptr+i));
    }

    free(ptr);

    return 0;
}
```
 - Sử dụng hàm `malloc` để cấp phát một vùng nhớ đủ để chứa 4 phần tử uint16_t (tổng cộng là 8 byte). Con trỏ ptr sẽ trỏ đến vùng nhớ được cấp phát.
 - Vòng lặp `for`: Gán giá trị cho các phần tử tiếp theo của mảng.
 - Vòng lặp `for` thứ hai duyệt qua từng byte của vùng nhớ đã cấp phát (tổng cộng là 8 byte vì mỗi uint16_t chiếm 2 byte và có 4 phần tử).

**Output từ Terminal:**
```c
> Địa chỉ: 000002353F1A8990, giá trị: 0
> Địa chỉ: 000002353F1A8991, giá trị: 0
> Địa chỉ: 000002353F1A8992, giá trị: 2
> Địa chỉ: 000002353F1A8993, giá trị: 0
> Địa chỉ: 000002353F1A8994, giá trị: 4
> Địa chỉ: 000002353F1A8995, giá trị: 0
> Địa chỉ: 000002353F1A8996, giá trị: 6
> Địa chỉ: 000002353F1A8997, giá trị: 0
```
Giải thích tại sao lại có kết quả như vậy, lấy phần tử `ptr[1]` đại diện:
 - `ptr[1] = 2` (dạng nhị phân: 0b 00000000 00000010).
 - Byte 3: 0b00000010 (2).
 - Byte 4: 0b00000000 (0).

### Hàm `calloc()`
Cấp phát bộ nhớ cho một mảng gồm nhiều phần tử, **khởi tạo tất cả các phần tử của mảng với giá trị 0**, và trả về một con trỏ đến vùng nhớ này.

**Ví dụ:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // Cấp phát bộ nhớ cho 6 phần tử kiểu uint16_t bằng hàm calloc
    uint16_t *ptr = NULL;
    ptr = (uint16_t*)calloc(6, sizeof(uint16_t));

    // In địa chỉ và giá trị của từng phần tử trong mảng
    for (int i = 0; i < 6; i++) {
        printf("Địa chỉ: %p, giá trị: %d\n", (void*)(ptr + i), ptr[i]);
    }

    // Giải phóng bộ nhớ đã cấp phát
    free(ptr);

    return 0;
}
```
**Output từ Terminal:**
```c
> Địa chỉ: 00000241654EE9D0, giá trị: 0
> Địa chỉ: 00000241654EE9D2, giá trị: 0
> Địa chỉ: 00000241654EE9D4, giá trị: 0
> Địa chỉ: 00000241654EE9D6, giá trị: 0
> Địa chỉ: 00000241654EE9D8, giá trị: 0
> Địa chỉ: 00000241654EE9DA, giá trị: 0
```
### Hàm `realloc()`
Thay đổi kích thước của vùng nhớ đã được cấp phát trước đó bằng malloc hoặc calloc, và trả về một con trỏ đến vùng nhớ mới (nội dung của vùng nhớ có thể thay đổi).

```c
uint16_t *ptr = NULL;
ptr = (uint16_t*)malloc(sizeof(uint16_t)*4); 		//0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08

//Cấp phát thêm 4 byte nữa
ptr = (uint16_t*)realloc(ptr, sizeof(uint16_t)*6); 	//0x01 0x02 0x03 0x04 0x05 0x06 0x07 0x08 0x09 0x0A 0x0B 0x0C
```

### Hàm `free()`
Giải phóng bộ nhớ đã được cấp phát trước đó bằng `malloc`, `calloc`, hoặc `realloc`.
```c
free(ptr);
```


</p>
</details>


# Bài 9: LINKED LIST

<details><summary>Chi tiết</summary>
<p>

## 1. Khái niệm
<details><summary>Chi tiết</summary>
<p>
	
Linked List là một cấu trúc dữ liệu bao gồm một chuỗi các node (nút), mỗi nút chứa hai thành phần chính:
- Dữ liệu (data): Đây là giá trị được lưu trữ trong nút.
- Con trỏ (pointer): Đây là tham chiếu (địa chỉ) đến nút tiếp theo trong danh sách.
 <p align="center">
  <img src="https://github.com/user-attachments/assets/8b38af8e-24fa-41f4-a6e6-01f6c683b6db" width="600">	
</p>

Trong C, ta thường dùng cấu trúc (struct) để định nghĩa một node. Cấu trúc này bao gồm:
- Một thành viên lưu dữ liệu.
- Một thành viên là con trỏ trỏ đến node tiếp theo cùng kiểu dữ liệu.
```c
typedef struct Node {
    int data;           // Giá trị (dữ liệu) của node
    struct Node* next;  // Con trỏ trỏ đến node tiếp theo
} Node_t;
```
</p>
</details>

## 2. Thao tác trên danh sách liên kết

<details><summary>Chi tiết</summary>
<p>

Khởi tạo một node mới

```c
// Hàm tạo một node mới
struct Node* createNode(int value) {
    // Cấp phát bộ nhớ cho node mới
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Gán giá trị dữ liệu
    newNode->data = value;

    // Ban đầu node mới sẽ không trỏ đến node nào
    newNode->next = NULL;

    return newNode;
}
```
Thêm một node vào vị trí cuối cùng
```c
// Hàm khởi tạo một node mới
Node* create_node(int value) {...}

// Hàm thêm một node vào cuối danh sách
void push_back(node** array, int value) {
    // Tạo một node mới
    node* new_node = create_node(value);

    // Nếu danh sách trống, node mới sẽ là node đầu tiên
    if (*array == NULL) {
        *array = new_node;
        return;
    }

    // Duyệt đến node cuối cùng
    node* temp = *array;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Gán node mới vào cuối danh sách
    temp->next = new_node;
}
```
Thêm một node vào đầu danh sách:
```c
void push_front(node** array, int value) {
    node* newNode = createNode(value);
    newNode->next = *array;
    *array = newNode;
}
```
Xóa node cuối cùng của danh sách:
```c
void pop_back(node** array) {
    if (*array == NULL) return;

    if ((*array)->next == NULL) {
        free(*array);
        *array = NULL;
    } else {
        node* temp = *array;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

```
Xóa node đầu tiên của danh sách
```c
void pop_front(node** array) {
    if (*array == NULL) return;

    node* temp = *array;
    *array = (*array)->next;
    free(temp);
}
```
Trả về giá trị của node đầu tiên
```c
int front(node* array) {
    if (array == NULL) return -1; // Hoặc giá trị lỗi khác
    return array->data;
}
```
Trả về giá trị của node cuối cùng
```c
int back(node* array) {
    if (array == NULL) return -1; // Hoặc giá trị lỗi khác
    node* temp = array;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp->data;
}
```
Thêm một node tại vị trí bất kì
```c
void insert(node** array, int value, int pos) {
    node* newNode = createNode(value);
    if (pos == 0 || *array == NULL) {
        push_front(array, value);
        return;
    }
    
    node* temp = *array;
    for (int i = 0; i < pos - 1 && temp->next != NULL; ++i) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
```
Xóa node tại vị trí bất kì
```c
void delete_list(node** array, int pos) {
    if (*array == NULL) return;

    if (pos == 0) {
        pop_front(array);
        return;
    }

    node* temp = *array;
    for (int i = 0; i < pos - 1 && temp->next != NULL; ++i) {
        temp = temp->next;
    }
    
    if (temp->next != NULL) {
        node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}
```
Trả về kích thước của danh sách:
```c
int size(node* array) {
    int count = 0;
    node* temp = array;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
```
Trả về giá trị của node tại vị trí bất kì
```c
int get(node* array, int pos) {
    node* temp = array;
    for (int i = 0; i < pos && temp != NULL; ++i) {
        temp = temp->next;
    }
    return (temp != NULL) ? temp->data : -1; // Hoặc giá trị lỗi khác
}
```
Kiểm tra xem danh sách có rỗng hay không.
```c
bool empty(node* array) {
    return array == NULL;
}
```

</p>
</details>

</p>
</details>

# Bài 10: STACK-QUEUE

<details><summary>Chi tiết</summary>
<p>


## 1. STACK

<details><summary>Chi tiết</summary>
<p>


stack (ngăn xếp) là một cấu trúc dữ liệu có thứ tự, hoạt động theo nguyên tắc LIFO (Last In, First Out), nghĩa là phần tử được thêm vào sau cùng sẽ được lấy ra đầu tiên

### Các đặc điểm chính của stack:
#### Push

Push trong stack dùng để thêm một phần tử mới vào đỉnh của stack.

Stack đầy khi chỉ số của phần tử đỉnh top bằng kích thước của stack trừ đi 1 (top == size - 1).

Nếu stack đã đầy mà cố tình thêm một phần tử nữa bằng cách push, thì quá trình này sẽ không thành công và sẽ gặp phải tình trạng "stack overflow"

Ví dụ:
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_full( Stack stack) {
    return stack.top == stack.size - 1;
}

void push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
        printf("Pushed %d to stack\n", value);  // Hiển thị giá trị đã được push vào stack
    } else {
        printf("Stack overflow\n");
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);

    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);  // Thử nghiệm khi stack đầy

    return 0;
}
```
#### Pop

Pop trong stack dùng để xóa một phần tử ở đỉnh của stack.

Khi stack không có phần tử nào thì không thể dùng pop.

Nếu cố tình pop khi stack rỗng, sẽ gặp phải tình trạng gọi là "stack underflow".

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize(Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty(Stack stack) {
    return stack.top == -1;
}

int pop(Stack *stack) {
    if (!is_empty(*stack)) {
        printf("Popped %d from stack\n", stack->items[stack->top]);
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);

    // Push các phần tử vào stack
    stack1.items[++stack1.top] = 10;
    stack1.items[++stack1.top] = 20;
    stack1.items[++stack1.top] = 30;

    // Pop các phần tử từ stack đến khi stack rỗng
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);  // Thử nghiệm khi stack rỗng

    return 0;
}
```

#### Top
Top trong stack dùng để lấy giá trị của phần tử ở đỉnh.

Khi stack không có phần tử nào (tức là stack rỗng), giá trị của top thường sẽ là -1.

Cứ mỗi lần push hoặc pop, giá trị top sẽ cộng lên hoặc trừ xuống 1.

Khi stack đầy, giá trị top là size - 1
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize(Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty(Stack stack) {
    return stack.top == -1;
}

int top(Stack stack) {
    if (!is_empty(stack)) {
        printf("Top element: %d\n", stack.items[stack.top]);
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);

    // Push các phần tử vào stack
    stack1.items[++stack1.top] = 10;
    stack1.items[++stack1.top] = 20;
    stack1.items[++stack1.top] = 30;

    // Lấy giá trị phần tử ở đỉnh stack mà không xóa nó
    top(stack1);

    // Thử nghiệm khi stack rỗng
    stack1.top = -1;  // Xóa các phần tử trong stack bằng cách đặt top về -1
    top(stack1);      // Gọi top khi stack rỗng

    return 0;
}
```

</p>
</details>

## Queue

<details><summary>Chi tiết</summary>
<p>


Queue (hàng đợi) là một cấu trúc dữ liệu hoạt động theo nguyên tắc FIFO (First In, First Out), nghĩa là phần tử được thêm vào trước sẽ được lấy ra trước. Điều này tương tự như một hàng đợi trong thực tế, nơi người đầu tiên vào hàng sẽ là người đầu tiên được phục vụ

Chỉ để cập tới Circular queue, ta có hai từ khóa front và rear:

front đại diện cho vị trí của phần tử đầu tiên trong hàng đợi. Đây là phần tử sẽ được lấy ra đầu tiên khi thực hiện thao tác dequeue (lấy phần tử ra).
rear đại diện cho vị trí của phần tử cuối cùng trong hàng đợi. Đây là phần tử cuối cùng được thêm vào khi thực hiện thao tác enqueue (thêm phần tử vào).
Khi queue rỗng, front và rear bằng -1.

Khi queue đầy, (rear + 1) % size == front.

Khi thực hiện dequeue, chỉ số front sẽ được tăng lên để trỏ tới phần tử tiếp theo trong hàng đợi.

Khi thực hiện enqueue, rear sẽ được tăng lên để trỏ tới vị trí mới cho phần tử vừa được thêm vào hàng đợi.

Nếu hàng đợi đầy, rear sẽ quay vòng theo cơ chế vòng tròn (circular queue), điều này có nghĩa là khi rear đạt tới giới hạn của mảng, nó sẽ quay về 0 để sử dụng lại vị trí cũ chỉ khi có phần tử được dequeue.

### Đặc điểm chính của queue:
#### Enqueue
Enqueue trong hàng chờ queue được sử dụng để thêm một phần tử vào cuối hàng chờ.

Chỉ có thể thực hiện enqueue khi hàng đợi không đầy.

Khi hàng đợi đã đầy, việc gọi enqueue sẽ không thêm phần tử mới và chương trình sẽ báo lỗi "Queue overflow".
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
        printf("Enqueued %d\n", value);
    } else {
        printf("Queue overflow\n");
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    enqueue(&queue, 40);  // Hàng đợi đầy, sẽ in ra "Queue overflow"

    return 0;
}
```
#### Dequeue
Dequeue trong hàng chờ queue dùng để lấy phần tử từ đầu hàng chờ ra.

Chỉ có thể sử dụng dequeue khi hàng đợi không rỗng.

Khi hàng đợi rỗng, việc gọi dequeue sẽ không có phần tử nào để lấy ra và chương trình sẽ báo lỗi "Queue underflow".
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        printf("Dequeued %d\n", dequeued_value);
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    // Giả lập việc thêm phần tử vào hàng đợi trước
    queue.items[++queue.rear] = 10;
    queue.items[++queue.rear] = 20;
    queue.items[++queue.rear] = 30;
    queue.front = 0;

    // Dequeue các phần tử
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    // Thử nghiệm dequeue khi hàng đợi rỗng
    dequeue(&queue);

    return 0;
}
```
#### Front
Front để lấy giá trị phần tử ở đầu hàng đợi mà không xóa nó
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int) * size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int front(Queue queue) {
    if (!is_empty(queue)) {
        printf("Front element: %d\n", queue.items[queue.front]);
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    // Giả lập việc thêm phần tử vào hàng đợi
    queue.items[++queue.rear] = 10;
    queue.items[++queue.rear] = 20;
    queue.items[++queue.rear] = 30;
    queue.front = 0;

    // Lấy phần tử ở đầu hàng đợi mà không xóa nó
    front(queue);

    // Giả lập hàng đợi rỗng và kiểm tra lại
    queue.front = queue.rear = -1;
    front(queue);  // Hàng đợi rỗng, sẽ in "Queue is empty"

    return 0;
}
```
</p>
</details>
</p>
</details>



# Bài 11: JSON

# BÀI 12: BINARY SEARCH-FILE OPERATIONS-CODE STANDARDS

<details><summary>Chi tiết</summary>
<p>


## 1.Binary search

<details><summary>Chi tiết</summary>
<p>


Tìm kiếm nhị phân là một thuật toán dùng để tìm kiếm vị trí của một phần tử trong một mảng đã được sắp xếp (tăng dần hoặc giảm dần).

Ví dụ:
```c
// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int left, int right, int target)
{
    if (right >= left)
    {
        int mid = (right + left) / 2;

        if (arr[mid] == target) return mid;

        if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}
```
Nguyên lý hoạt động:

**1. Xác định điểm giữa (mid) của mảng:**
- mid = (right + left) / 2, với left là chỉ số bắt đầu và right là chỉ số kết thúc của mảng.

**2. So sánh phần tử tại vị trí giữa với giá trị cần tìm (target):**
- Nếu arr[mid] == x: Phần tử cần tìm được tìm thấy tại chỉ số mid.

- Nếu arr[mid] > x: Giới hạn phạm vi tìm kiếm chỉ còn nửa bên trái mảng, do x chỉ có thể nằm trong khoảng từ left đến mid - 1.

- Nếu arr[mid] < x: Giới hạn phạm vi tìm kiếm chỉ còn nửa bên phải mảng, do x chỉ có thể nằm trong khoảng từ mid + 1 đến right.

**3. Lặp lại quá trình:**
- Liên tục lặp lại bước 1 và 2 với phạm vi tìm kiếm mới cho đến khi tìm thấy phần tử hoặc phạm vi tìm kiếm trở nên rỗng (khi left > right) là không tìm thấy phần tử.

</p>
</details>

## 2. File operations

<details><summary>Chi tiết</summary>
<p>


Ngôn ngữ lập trình C cung cấp một số thư viện và hàm tiêu biểu để thực hiện các thao tác với file (.txt, .csv, v.v).

CSV (Comma-Separated Values) là một định dạng file văn bản đơn giản dùng để lưu trữ dữ liệu bảng.

Dữ liệu trong file CSV được phân tách bằng dấu phẩy (,) hoặc dấu phân tách khác như dấu chấm phẩy (;) hoặc tab.

Dữ liệu trong file CSV được phân tách bằng dấu phẩy (,) hoặc (;) hoặc ký tự tab (\t).


### Mở file

Hàm `fopen()` trả về một con trỏ FILE, và cần được kiểm tra để đảm bảo file đã mở thành công hay chưa.
```c
FILE *file = fopen(const char *file_name, const char *access_mode);
```
Tham số truyền vào `access_mod` là quyền sử dụng file:
- `r` : Mở file với chế độ chỉ đọc file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- `rb` : Mở file với chế độ chỉ đọc file theo định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- `w` : Mở file với chế độ ghi vào file. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- `wb` : Mở file với chế độ ghi vào file theo định dạng binary. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- `a` : Mở file với chế độ nối. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- `ab` : Mở file với chế độ nối dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- `r+` : Mở file với chế độ đọc và ghi file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- `rb+` : Mở file với chế độ đọc và ghi file dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.

</p>
</details>


### Đọc file


### Ghi file

### Một số hàm khác
## 3. Code standards
</p>
</details>
</p>
</details>


# Bài 13: Class

<details><summary>Chi tiết</summary>
<p>
Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan


## Các khái niệm:

<details><summary>Chi tiết</summary>
<p>

### Access specifier (Phạm vi truy cập)

Phạm vi truy cập (Access Specifiers) trong một class xác định cách các thành viên (thuộc tính và phương thức) của class có thể được truy cập từ bên ngoài. Có ba phạm vi truy cập chính:

1. `private` (Riêng tư): Các thành viên được khai báo với phạm vi truy cập `private` chỉ có thể được truy cập từ bên trong chính class đó. Đây là phạm vi truy cập mặc định nếu bạn không chỉ định phạm vi khác

2. `protected` (Bảo vệ): Các thành viên `protected` có thể được truy cập từ chính class và từ các class dẫn xuất (các class kế thừa class hiện tại). Không thể truy cập trực tiếp từ bên ngoài class, chỉ thông qua kế thừa hoặc từ bên trong class

3. `public` (Công khai): Các thành viên `public` có thể được truy cập từ bất kỳ đâu, cả từ bên ngoài class lẫn bên trong class. Đây là phạm vi truy cập thoáng nhất, cho phép truy cập mà không có giới hạn nào

### Object (Đối tượng)
Được tạo ra từ một class và có đầy đủ các thuộc tính và phương thức mà class đó đã định nghĩa
```c
#include <iostream>
using namespace std;

class HinhChuNhat {
    // Do something ...
};

int main()
{
    // Declar object
    HinhChuNhat hinh;

    return 0;
}
```
### Property (Thuộc tính)
Là các biến thành viên
```c
#include <iostream>
using namespace std;

class HinhChuNhat {
public:
    // Properties
    double chieuDai;  
    double chieuRong; 
};

int main() {
    HinhChuNhat hinh;
    
    // Assign values to properties
    hinh.chieuDai = 20;
    hinh.chieuRong = 10;
}
``` 
### Method (Phương thức)
Là các hàm thành viên.
```c
#include <iostream>
using namespace std;

class HinhChuNhat {
public:
    // Properties
    double chieuDai;  
    double chieuRong; 

    // Method
    double DienTich() { 
        return chieuDai * chieuRong;
    }

    // Method
    void display();
};

// Implementation of the display method
void HinhChuNhat::display() {
    cout << "Dien tich: " << DienTich() << endl;
}

int main() {
    HinhChuNhat hinh;
    
    // Assign values to properties
    hinh.chieuDai = 20;
    hinh.chieuRong = 10;

    hinh.display();

    return 0;
}
```
### Constructor
Là method đặc biệt của class.

Được gọi tự động khi một object của class được tạo ra nhằm khởi tạo giá trị mặc định cho properties.

Tên của constructor phải trùng với tên class

Các dạng Constructor
- Constructor không có tham số truyền vào
```c
#include <iostream>
using namespace std;

class HinhChuNhat {
public:
    // Properties
    double chieuDai;  
    double chieuRong; 

    // Method
    double DienTich() { 
        return chieuDai * chieuRong;
    }

    // Method
    void display();

    // Constructor to assign default values to properties
    HinhChuNhat() {
        chieuDai = 20;
        chieuRong = 30;
    }
    /* viết cách khác
    // Constructor using initializer list
    HinhChuNhat() : chieuDai(10.5), chieuRong(20) {}
    */
};

// Implementation of the display method
void HinhChuNhat::display() {
    cout << "Dien tich: " << DienTich() << endl;
}

int main() {
    // Create a object
    HinhChuNhat hinh;
    
    hinh.display();

    return 0;
}
```
- Constructor có tham số truyền vào
```c
#include <iostream>
using namespace std;

class HinhChuNhat {
public:
    double chieuDai;  // property
    double chieuRong; // property

    // Constructor with parameters
    HinhChuNhat(int a, int b) {
        chieuDai = a;
        chieuRong = b;
    }

    // Method to calculate area
    double DienTich() { 
        return chieuDai * chieuRong;
    }

    // Method to display area
    void display();
};

// Implementation of the display method
void HinhChuNhat::display() {
    cout << "Dien tich: " << DienTich() << endl;
}

int main() {
    // Create a object but pass parameters.
    HinhChuNhat hinh(15, 25);

    hinh.display();

    return 0;
}
```
Viết cách khác
```c
#include <iostream>
using namespace std;

class HinhChuNhat {
public:
    double chieuDai;  
    double chieuRong; 

    // Constructor with default parameters
    HinhChuNhat(int a = 3, int b = 5) {
        chieuDai = a;
        chieuRong = b;
    }
    // Do something ...
};

int main() {
    // This will use the default values: chieuDai = 3, chieuRong = 5
    HinhChuNhat hinh1;

     // This will use the provided values: chieuDai = 10, chieuRong = 20
    HinhChuNhat hinh2(10, 20);
    return 0;
}
```

</p>
</details>

</p>
</details>

# Bài 14: OOP

<details><summary>Chi tiết</summary>
<p>

## 1. Tính đóng gói (Encapsulation)

<details><summary>Chi tiết</summary>
<p>


Tính đóng gói là ẩn đi các property “mật” khỏi người dùng.

Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private (tức là không thể truy cập trực tiếp tới các property này)
```c
class SinhVien{
    private:
        // Tính đóng gói-ẩn đi các property
        string name;
        int id;
};
```
Trong trường hợp muốn đọc hoặc ghi các property này, thì ta truy cập gián tiếp bằng các method ở quyền truy cập public.

Bài trước đã học method đặc biệt để làm việc với property là Contructor và Destructor, bài này có thêm method đặc biệt Setter và Getter
- Getter: Được sử dụng để lấy giá trị của một thuộc tính property
- Setter: Được sử dụng để đặt, thay đổi giá trị và kiểm tra tính hợp lệ của property

Ví dụ:
```c
#include <iostream>
using namespace std;

class SinhVien {
private:
    string ten;
    int tuoi;

public:
    // Constructor
    SinhVien(string ten, int tuoi) {
        this->ten = ten;
        this->tuoi = tuoi;
    }

    // Setter cho thuộc tính `ten`
    void setTen(string ten) {
        this->ten = ten;
    }

    // Getter cho thuộc tính `ten`
    string getTen() {
        return ten;
    }

    // Setter cho thuộc tính `tuoi`
    void setTuoi(int tuoi) {
        if (tuoi > 0) {
            this->tuoi = tuoi;
        }
    }

    // Getter cho thuộc tính `tuoi`
    int getTuoi() {
        return tuoi;
    }
};

int main() {
    SinhVien sv("Lan", 20);
    cout << "Ten: " << sv.getTen() << ", Tuoi: " << sv.getTuoi() << endl;

    sv.setTen("Mai");
    sv.setTuoi(21);

    cout << "Ten moi: " << sv.getTen() << ", Tuoi moi: " << sv.getTuoi() << endl;

    return 0;
}
```
Trong ví dụ trên:
- Biến `ten` và `tuoi` là các thành viên `private` của lớp `SinhVien`, nghĩa là chúng không thể truy cập trực tiếp từ bên ngoài lớp
- Các phương thức `setTen`, `getTen`, `setTuoi`, và `getTuoi` được định nghĩa để truy cập và cập nhật giá trị của `ten` và `tuoi`. Điều này giúp kiểm soát cách dữ liệu của lớp được sử dụng và thay đổi

</p>
</details>

## 2. Tính kế thừa (Inheritance)

<details><summary>Chi tiết</summary>
<p>


Tính kế thừa là một đặc trưng quan trọng của lập trình hướng đối tượng (OOP). 

Cho phép một lớp (class) mới được tạo ra dựa trên lớp đã tồn tại, kế thừa lại các thuộc tính (biến thành viên) và hành vi (phương thức) của lớp đó. 

Lớp mới được gọi là lớp dẫn xuất (derived class) hoặc lớp con (child class), còn lớp đã tồn tại được gọi là lớp cơ sở (base class) hoặc lớp cha (parent class)

### Các loại kế thừa
#### 1. Kế thừa công khai (public inheritance)
Tất cả các thành viên `public` của lớp cơ sở vẫn giữ nguyên mức truy cập `public` trong lớp dẫn xuất. 

Các thành viên `protected` của lớp cơ sở sẽ trở thành `protected` trong lớp dẫn xuất. Các thành viên `private` của lớp cơ sở không thể truy cập trực tiếp trong lớp dẫn xuất

Ví dụ:
```c
#include <iostream>
using namespace std;

class DongVat {
public:
    void an() {
        cout << "Dong vat dang an." << endl;
    }
protected:
    void ngu() {
        cout << "Dong vat dang ngu." << endl;
    }
};

class Meo : public DongVat {
public:
    void keu() {
        cout << "Meo keu: Meo meo!" << endl;
    }
    void hanhDong() {
        an(); // Có thể truy cập `an()` vì nó là `public`
        ngu(); // Có thể truy cập `ngu()` vì nó là `protected`
    }
};

int main() {
    Meo conMeo;
    conMeo.an(); // Gọi được vì `an()` là `public`
    conMeo.keu(); // Gọi được vì `keu()` là `public`
    // conMeo.ngu(); // Không gọi được vì `ngu()` là `protected`

    conMeo.hanhDong(); // Gọi được vì `hanhDong()` là `public` và có thể truy cập `an()` và `ngu()`

    return 0;
}
```
Kết quả:
```c
Dong vat dang an.
Meo keu: Meo meo!
Dong vat dang an.
Dong vat dang ngu.
```
Trong ví dụ trên:
- `Meo` kế thừa `public` từ `DongVat`, nên `an()` và `ngu()` giữ nguyên quyền truy cập của chúng (`public` và `protected`)
- `conMeo` có thể gọi trực tiếp `an()` và `keu()` nhưng không thể gọi trực tiếp `ngu()`

#### 2. Kế thừa bảo vệ (protected inheritance)
Tất cả các thành viên `public` và `protected` của lớp cơ sở đều trở thành `protected` trong lớp dẫn xuất.
 
 Điều này có nghĩa là chúng chỉ có thể được truy cập từ bên trong lớp dẫn xuất và các lớp kế thừa tiếp theo

Ví dụ:
```c
class DongVat {
public:
    void an() {
        cout << "Dong vat dang an." << endl;
    }
protected:
    void ngu() {
        cout << "Dong vat dang ngu." << endl;
    }
};

class Cho : protected DongVat {
public:
    void sua() {
        cout << "Cho sua: Gau gau!" << endl;
    }
    void hanhDong() {
        an(); // Có thể truy cập `an()` vì nó trở thành `protected`
        ngu(); // Có thể truy cập `ngu()` vì nó là `protected`
    }
};

int main() {
    Cho conCho;
    // conCho.an(); // Không gọi được vì `an()` là `protected`
    conCho.sua(); // Gọi được vì `sua()` là `public`
    conCho.hanhDong(); // Gọi được vì `hanhDong()` là `public`

    return 0;
}
```
Kết quả:
```c
Cho sua: Gau gau!
Dong vat dang an.
Dong vat dang ngu.
```
Trong ví dụ trên:
- `Cho` kế thừa `protected` từ `DongVat`, nên cả `an()` và `ngu()` đều trở thành `protected`
- `conCho` không thể gọi `an()` trực tiếp vì nó là `protected`, nhưng có thể gọi `hanhDong()` vì phương thức này là `public` trong Cho

#### 3. Kế thừa riêng tư (private inheritance)
Tất cả các thành viên `public` và `protected` của lớp cơ sở đều trở thành `private` trong lớp dẫn xuất. 

Điều này có nghĩa là chúng chỉ có thể được truy cập từ bên trong lớp dẫn xuất, và không thể được truy cập từ bất kỳ lớp nào khác, kể cả lớp kế thừa tiếp theo

```c
class DongVat {
public:
    void an() {
        cout << "Dong vat dang an." << endl;
    }
protected:
    void ngu() {
        cout << "Dong vat dang ngu." << endl;
    }
};

class Chim : private DongVat {
public:
    void hot() {
        cout << "Chim hot: Chip chip!" << endl;
    }
    void hanhDong() {
        an(); // Có thể truy cập `an()` vì nó trở thành `private`
        ngu(); // Có thể truy cập `ngu()` vì nó là `private`
    }
};

int main() {
    Chim conChim;
    // conChim.an(); // Không gọi được vì `an()` là `private`
    conChim.hot(); // Gọi được vì `hot()` là `public`
    conChim.hanhDong(); // Gọi được vì `hanhDong()` là `public`

    return 0;
}
```
Kết quả:
```c
Chim hot: Chip chip!
Dong vat dang an.
Dong vat dang ngu.
```
Trong ví dụ trên:
- `Chim` kế thừa `private` từ `DongVat`, nên `an()` và `ngu()` đều trở thành `private`
- `conChim` không thể gọi `an()` hoặc `ngu()` trực tiếp, nhưng có thể gọi `hanhDong()`, vì phương thức này là `public` trong `Chim` và có thể truy cập `an()` và `ngu()` bên trong


</p>
</details>

## 3. Tính đa hình (polymorphism) 

<details><summary>Chi tiết</summary>
<p>

 Cho phép một đối tượng hoặc phương thức có thể biểu hiện theo nhiều cách khác nhau

 Giúp tăng tính linh hoạt và khả năng mở rộng của chương trình, đồng thời cho phép các đối tượng của các lớp khác nhau xử lý chung qua cùng một giao diện

### Có 2 loại đa hình:
#### 1. Đa hình tĩnh (Compile-time polymorphism):
- Được xác định trong quá trình biên dịch
- Có thể đạt được thông qua nạp chồng hàm (function overloading) và nạp chồng toán tử (operator overloading)

**Nạp chồng hàm (Function Overloading):**

Cho phép nhiều hàm có cùng tên nhưng khác nhau về kiểu tham số hoặc số lượng tham số. 

Trình biên dịch sẽ quyết định hàm nào được gọi dựa trên các tham số truyền vào

Ví dụ:
```c
#include <iostream>
using namespace std;

class TinhToan {
public:
    // Hàm cộng hai số nguyên
    int cong(int a, int b) {
        return a + b;
    }

    // Hàm cộng ba số nguyên
    int cong(int a, int b, int c) {
        return a + b + c;
    }

    // Hàm cộng hai số thực
    double cong(double a, double b) {
        return a + b;
    }
};

int main() {
    TinhToan tt;
    cout << "Cong 2 so nguyen: " << tt.cong(3, 4) << endl; // Gọi hàm cộng 2 số nguyên
    cout << "Cong 3 so nguyen: " << tt.cong(3, 4, 5) << endl; // Gọi hàm cộng 3 số nguyên
    cout << "Cong 2 so thuc: " << tt.cong(3.5, 4.5) << endl; // Gọi hàm cộng 2 số thực
    return 0;
}
```
Kết quả:
```
Cong 2 so nguyen: 7
Cong 3 so nguyen: 12
Cong 2 so thuc: 8
```

**Nạp chồng toán tử (Operator Overloading):**
Là bạn định nghĩa lại toán tử đã có trên kiểu dữ liệu người dùng tự định nghĩa để dể dàng thể hiện các câu lệnh trong chương trình

Ví dụ:
```C
#include <iostream>
using namespace std;

class Diem {
    private:
        int x, y;
    public:
        // Hàm khởi tạo
        Diem(int a = 0, int b = 0) : x(a), y(b) {}

        // Nạp chồng toán tử ==
        bool operator == (const Diem& khac) {
            return (this->x == khac.x && this->y == khac.y);
        }

        // Phương thức hiển thị tọa độ
        void hienThi() {
            cout << "(" << x << ", " << y << ")" << endl;
        }
};

int main() {
    Diem d1(3, 4), d2(3, 4), d3(1, 2);

    if (d1 == d2) {
        cout << "d1 và d2 có tọa độ giống nhau." << endl;
    } else {
        cout << "d1 và d2 có tọa độ khác nhau." << endl;
    }

    if (d1 == d3) {
        cout << "d1 và d3 có tọa độ giống nhau." << endl;
    } else {
        cout << "d1 và d3 có tọa độ khác nhau." << endl;
    }

    return 0;
}
```

#### 2. Đa hình động (Runtime polymorphism)


 #### Tính trừu tượng (Abstract Class)

Lớp chứa ít nhất một hàm thuần ảo (pure virtual function)

Cú pháp `virtual void ham() = 0;`

Lớp trừu tượng không thể tạo đối tượng trực tiếp mà chỉ có thể làm lớp cơ sở cho các lớp dẫn xuất
```c++
#include <iostream>
using namespace std;

class Hinh {
public:
    virtual void ve() = 0; // Hàm thuần ảo, làm cho `Hinh` trở thành lớp trừu tượng
};

class HinhTron : public Hinh {
public:
    void ve() override {
        cout << "Ve hinh tron." << endl;
    }
};

class HinhChuNhat : public Hinh {
public:
    void ve() override {
        cout << "Ve hinh chu nhat." << endl;
    }
};

int main() {
    Hinh* hinh1 = new HinhTron();
    Hinh* hinh2 = new HinhChuNhat();

    hinh1->ve(); // Gọi `ve()` của `HinhTron`
    hinh2->ve(); // Gọi `ve()` của `HinhChuNhat`

    delete hinh1;
    delete hinh2;

    return 0;
}
```
Kết quả:
```
Ve hinh tron.
Ve hinh chu nhat.
```
Trong ví dụ trên:
- `Hinh` là lớp trừu tượng vì có hàm thuần ảo `ve()`
- `HinhTron` và `HinhChuNhat` kế thừa từ `Hinh` và định nghĩa lại phương thức `ve()`
- Có thể sử dụng con trỏ `Hinh` để gọi các phương thức `ve()` của các đối tượng `HinhTron` và `HinhChuNhat`

</p>
</details>


</p>
</details>

# BÀI 15: VIRTUAL FUNCTION

<details><summary>Chi tiết</summary>
<p>

## 1. Đa hình tại thời điểm chạy (Run-time Polymorphism)

<details><summary>Chi tiết</summary>
<p>

Đa hình tại thời điểm chạy xảy ra khi việc quyết định method nào (phiên bản của class cha hay của class con) sẽ được gọi ra ngay tại thời điểm chạy chương trình.

Ưu điểm là giúp chương trình linh hoạt hơn, cho phép việc mở rộng chức năng mà không cần sửa đổi mã nguồn hiện tại.

Tính đa hình này thực hiện bằng cách sử dụng hàm ảo (virtual function) ở class cha và ghi đè lên hàm ảo ở class con
### Đặc điểm của đa hình tại thời điểm chạy (Run-time Polymorphism)
#### 1.Hàm ảo (Virtual function) và ghi đè hàm ảo (Override)
**Hàm ảo (Virtual Functions):**

Cho phép gọi hàm được ghi đè (override) trong lớp dẫn xuất thông qua con trỏ hoặc tham chiếu của lớp cơ sở

Giúp đối tượng lớp dẫn xuất có thể thể hiện hành vi riêng của nó ngay cả khi được gọi thông qua lớp cơ sở

Ví dụ:
```c
#include <iostream>
using namespace std;

class DongVat {
public:
    virtual void keu() { // Hàm ảo
        cout << "Dong vat keu." << endl;
    }
};

class Cho : public DongVat {
public:
    void keu() override {
        cout << "Cho keu: Gau gau!" << endl;
    }
};

class Meo : public DongVat {
public:
    void keu() override {
        cout << "Meo keu: Meo meo!" << endl;
    }
};

int main() {
    DongVat *dongVat1 = new Cho();
    DongVat *dongVat2 = new Meo();

    dongVat1->keu(); // Gọi hàm `keu()` của lớp `Cho`
    dongVat2->keu(); // Gọi hàm `keu()` của lớp `Meo`

    delete dongVat1;
    delete dongVat2;

    return 0;
}
```
Kết quả:
```
Cho keu: Gau gau!
Meo keu: Meo meo!
```

Trong ví dụ trên :
- `keu()` trong DongVat là hàm ảo (`virtual`), cho phép ghi đè trong các lớp dẫn xuất như `Cho` và `Meo`
- Khi gọi `keu()` thông qua con trỏ `DongVat`, hàm `keu()` tương ứng của lớp dẫn xuất (`Cho` hoặc `Meo`) sẽ được gọi nhờ tính đa hình động

**Ghi đè hàm ảo (Override)**

Là việc cung cấp một phương thức trong class con với cùng tên, cùng kiểu trả về, và cùng danh sách tham số như một phương thức đã được định nghĩa trong class cha

Khi một phương thức được ghi đè, phương thức của class con sẽ được gọi thay vì phương thức của class cha khi đối tượng thuộc lớp con được sử dụng
```c
#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {  // Hàm ảo
        cout << "Hiển thị từ lớp cơ sở" << endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Ghi đè phương thức display() của class cha
        cout << "Hiển thị từ lớp dẫn xuất" << endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->display(); // Kết quả: "Hiển thị từ lớp dẫn xuất"

    delete obj;
    return 0;
}
```

Như vậy `override` sẽ:
- Cung cấp một cách triển khai khác của một phương thức trong class con, phù hợp hơn với nhu cầu của class con
- Cho phép hành vi khác nhau giữa các lớp kế thừa, mặc dù sử dụng cùng một tên phương thức
#### 2.Hàm ảo thuần túy (Pure Virtual Function)
Hàm ảo thuần túy là một hàm ảo không có phần định nghĩa trong class cha, được khai báo với cú pháp = 0

Ví dụ:
```c
#include <iostream>
using namespace std;

// Lớp trừu tượng Animal với hàm ảo thuần túy sound()
class Animal {
public:
    // Hàm ảo thuần túy
    virtual void sound() = 0;
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Gâu gâu" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meo meo" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
    animal1->sound(); // Kết quả: "Gâu gâu"
    animal2->sound(); // Kết quả: "Meo meo"

    delete animal1;
    delete animal2;

    return 0;
}
```
- Lớp `Animal` là một lớp trừu tượng vì nó chứa hàm ảo thuần túy `sound()`. Điều này có nghĩa là không thể tạo đối tượng trực tiếp từ lớp `Animal`
- Các lớp `Dog` và `Cat` kế thừa từ `Animal` và buộc phải ghi đè phương thức `sound()`, vì `sound()` là hàm ảo thuần túy trong class cha
- Trong hàm `main()`, sử dụng con trỏ kiểu `Animal*` để trỏ đến các đối tượng `Dog` và `Cat`
- Khi gọi `sound()` trên các con trỏ `animal1` và `animal2`, phương thức `sound()` của `Dog` và `Cat` được gọi đúng với âm thanh đặc trưng của từng loại động vật

</p>
</details>

## 2. Đa kế thừa:

<details><summary>Chi tiết</summary>
<p>

Cho phép một class kế thừa từ nhiều class khác

Thường dùng để kết hợp các chức năng từ nhiều class

Ví dụ:
```c
#include <iostream>
using namespace std;

// Lớp cơ bản Animal
class Animal {
public:
    void eat() {
        cout << "Động vật ăn." << endl;
    }
};

// Lớp CanSwim
class CanSwim {
public:
    void swim() {
        cout << "Động vật bơi." << endl;
    }
};

// Lớp CanFly
class CanFly {
public:
    void fly() {
        cout << "Động vật bay." << endl;
    }
};

// Lớp Duck kế thừa từ Animal, CanSwim và CanFly
class Duck : public Animal, public CanSwim, public CanFly {
public:
    void sound() {
        cout << "Vịt kêu cạp cạp." << endl;
    }
};

int main() {
    Duck duck;
    duck.eat();   // Kết quả: "Động vật ăn."
    duck.swim();  // Kết quả: "Động vật bơi."
    duck.fly();   // Kết quả: "Động vật bay."
    duck.sound(); // Kết quả: "Vịt kêu cạp cạp."

    return 0;
}
```
Trong ví dụ trên:
- Lớp `Animal` cung cấp phương thức `eat()` (ăn).
- Lớp `CanSwim` cung cấp phương thức `swim()` (bơi).
- Lớp `CanFly` cung cấp phương thức `fly()` (bay).
- Lớp `Duck` kế thừa từ cả `Animal`, `CanSwim`, và `CanFly`, nghĩa là `Duck` có thể sử dụng tất cả các phương thức `eat()`, `swim()`, và `fly()`, ngoài ra còn có phương thức riêng `sound()` để thể hiện tiếng kêu của vịt.
- Khi gọi các phương thức `eat()`, `swim()`, `fly()`, và `sound()` trên đối tượng `duck`, chương trình sẽ thực thi các hành vi tương ứng

### Diamond problem
Diamond problem xảy ra khi một lớp con kế thừa từ hai lớp cha, và cả hai lớp cha này đều kế thừa từ một lớp cha chung. Điều này dẫn đến tình huống lớp con có thể chứa các thuộc tính hoặc phương thức trùng tên từ lớp cha chung, gây ra xung đột trong việc xác định nên sử dụng thành phần nào

Kế thừa ảo giúp xử lý diamond problem trong đa kế thừa

### Kế thừa ảo:
Chỉ có một bản sao duy nhất của lớp cơ sở chung được kế thừa sử dụng từ khóa `virtual`
Ví dụ: 
```c
class A {
public:
    void show() { 
        cout << "Class A" << endl; 
    }
};

// Kế thừa ảo từ A dùng từ khóa "virtual"
class B : public virtual A { };
class C : public virtual A { };

// Class D kế thừa cả B và C
class D : public B, public C { };

int main() {
    D d;
    d.show(); // Kết quả: "Class A"
    return 0;
}
```

</p>
</details>

</p>
</details>

# Bài 16: GENERIC PROGRAMMING-TEMPLATE


<details><summary>Chi tiết</summary>
<p>

 Template (mẫu) là một công cụ giúp bạn tạo ra các hàm và lớp có thể làm việc với nhiều kiểu dữ liệu khác nhau mà không cần viết lại mã cho từng kiểu cụ thể



## Các loại Template:

<details><summary>Chi tiết</summary>
<p>


### 1. Function Template (Hàm mẫu)
Hàm mẫu cho phép bạn tạo ra một hàm tổng quát, có thể hoạt động với nhiều kiểu dữ liệu khác nhau

Ví dụ:
```c
#include <iostream>
using namespace std;

// Định nghĩa template với hai kiểu dữ liệu tổng quát T1 và T2
template <typename T1, typename T2>
T1 multiply(T1 a, T2 b) {
    return a * b; // Trả về tích của hai tham số với kiểu trả về là T1
}

int main() {
    // Gọi hàm multiply với các kiểu dữ liệu khác nhau
    cout << "Multiply: " << multiply(2, 3) << endl;        // Kiểu int
    cout << "Multiply: " << multiply(2.5, 4.2) << endl;    // Kiểu double
    cout << "Multiply: " << multiply(3, 5.7) << endl;      // Kết hợp int và double

    return 0;
}
```
- `template <typename T1, typename T2>`: Khai báo template với hai kiểu dữ liệu tổng quát `T1` và `T2`
- `T1 multiply(T1 a, T2 b)`: Định nghĩa hàm `multiply` nhận hai tham số với kiểu dữ liệu `T1` và `T2`, và trả về kiểu `T1`.
- Hàm `multiply` có thể được sử dụng với các kiểu dữ liệu khác nhau (như `int` và `double`).

#### Từ khóa auto
Từ khóa auto được sử dụng để tự động suy luận kiểu dữ liệu của biến hoặc kiểu trả về của hàm dựa trên giá trị mà gán cho nó

Ở ví dụ trên Kiểu trả về của hàm `multiply` ở ví dụ trên khá là thụ động vì kiểu trả về phụ thuộc vào `T1` làm cho kết quả bị sai trong trường hợp này
```c
cout << "Multiply: " << multiply(3, 5.7) << endl; //Kết quả là 17
```
Để giải quyết vấn đề này ta tử dụng từ khóa `auto`:
```c
template <typename T1, typename T2>
auto multiply(T1 a, T2 b) {
    return a * b; // Trả về tích của hai tham số, kiểu trả về sẽ được tự động suy diễn
}
// Kết quả trả về là 17.1
```
### 2. Class template
Class template tương tự như function template, nhưng nó được áp dụng cho class

Class template, giúp tạo ra một class có thể làm việc với nhiều kiểu dữ liệu khác nhau
#### Sử dụng cho kiểu dữ liệu đơn giản
Với trường hợp này là sử dụng template cho các kiểu dữ liệu đơn giản như int, float, double, char, ...

Ví dụ:
```c
#include <iostream>
using namespace std;

// Định nghĩa class template với một kiểu dữ liệu tổng quát T
template <typename T>
class Container {
private:
    T value; // Biến thành viên của kiểu dữ liệu T
public:
    // Constructor để khởi tạo giá trị
    Container(T val) : value(val) {}

    // Phương thức để lấy giá trị
    T getValue() const {
        return value;
    }

    // Phương thức để thiết lập giá trị mới
    void setValue(T val) {
        value = val;
    }

    // Phương thức để hiển thị giá trị
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    // Tạo đối tượng Container với kiểu dữ liệu int
    Container<int> intContainer(10);
    intContainer.display();
    intContainer.setValue(20);
    cout << "New int value: " << intContainer.getValue() << endl;

    // Tạo đối tượng Container với kiểu dữ liệu double
    Container<double> doubleContainer(3.14);
    doubleContainer.display();
    doubleContainer.setValue(2.718);
    cout << "New double value: " << doubleContainer.getValue() << endl;

    // Tạo đối tượng Container với kiểu dữ liệu string
    Container<string> stringContainer("Generic Programming");
    stringContainer.display();
    stringContainer.setValue("C++ Templates");
    cout << "New string value: " << stringContainer.getValue() << endl;

    return 0;
}
```

Output:
```
Value: 10
New int value: 20
Value: 3.14
New double value: 2.718
Value: Generic Programming
New string value: C++ Templates
```
**Khai báo Template**: `template <typename T>` khai báo một mẫu (`template`) cho lớp `Container`, với `T` là một kiểu dữ liệu tổng quát

**Class Container**:
- `value`: Một biến thành viên kiểu `T` để lưu trữ giá trị.
- `Container(T val)`: Constructor nhận một giá trị `val` kiểu `T` và gán giá trị này cho `value`
- `getValue()`: Trả về giá trị hiện tại của `value`
- `setValue(T val)`: Thiết lập lại giá trị của `value` với `val`
- `display()`: Hiển thị giá trị hiện tại của `value` trên màn hình

**Sử dụng Lớp Template**:
- `Container<int> intContainer(10)`;: Tạo một đối tượng `Container` kiểu `int` với giá trị khởi tạo là `10`
- `Container<double> doubleContainer(3.14);`: Tạo một đối tượng `Container` kiểu `double` với giá trị khởi tạo là `3.14`
- `Container<string> stringContainer("Generic Programming");`: Tạo một đối tượng `Container` kiểu `string` với giá trị khởi tạo là chuỗi `"Generic Programming"`
#### Sử dụng cho kiểu dữ liệu phức tạp
Với trường hợp này là sử dụng template cho các kiểu dữ liệu phức tạp như struct, class, ...

Lưu ý: Từ khóa mới-const, phương thức có từ khóa này không thể thay đổi bất kỳ thành viên dữ liệu nào của đối tượng!

Ví dụ:
```c
#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở
class Shape {
public:
    virtual void draw() const = 0; // Phương thức thuần ảo
};

// Một lớp cụ thể kế thừa từ Shape
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a circle" << endl;
    }
};

// Một lớp khác kế thừa từ Shape
class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a square" << endl;
    }
};

// Khai báo class template với T là một kiểu class kế thừa từ Shape
template <typename T>
class ShapeContainer {
private:
    T shape;
public:
    ShapeContainer(T s) : shape(s) {}
    
    void displayShape() const {      // Từ khóa const
        shape.draw();
    }
};

int main() {
    Circle c;

    // Khởi tạo đối tượng kiểu class template
    ShapeContainer<Circle> circleContainer(c);
    circleContainer.displayShape();                  // Kết quả: Drawing a circle

    Square s;

    // Khởi tạo đối tượng kiểu class template
    ShapeContainer squareContainer(s);              // Không cần truyền vào template argument <Square> cũng được!!
    squareContainer.displayShape();                 // Kết quả: Drawing a square

    return 0;
}
```

</p>
</details>

## 3. Operator overloading

<details><summary>Chi tiết</summary>
<p>


Nạp chồng toán tử là định nghĩa lại cách hoạt động của một số toán tử (toán tử có sẵn trong C++) đối với các object của class tự định nghĩa (các object đó không thể tính toán như các biến thông thường)

</p>
</details>

</p>
</details>


# Bài 17: NAMESPACE

<details><summary>Chi tiết</summary>
<p>

`namespace` là một tính năng được sử dụng để tổ chức và phân nhóm các tên (biến, hàm, lớp, v.v.) nhằm tránh xung đột tên khi chương trình phát triển lớn hoặc khi sử dụng các thư viện khác nhau có thể có các định danh trùng lặp
```C
#include <iostream>

// Khai báo namespace đầu tiên với biến và hàm trùng tên
namespace NamespaceA {
    int value = 10;

    void display() {
        std::cout << "NamespaceA::value = " << value << std::endl;
    }
}

// Khai báo namespace thứ hai với biến và hàm trùng tên
namespace NamespaceB {
    int value = 20;

    void display() {
        std::cout << "NamespaceB::value = " << value << std::endl;
    }
}

int main() {
    // Gọi hàm và biến từ NamespaceA
    NamespaceA::display();  // Xuất ra: NamespaceA::value = 10

    // Gọi hàm và biến từ NamespaceB
    NamespaceB::display();  // Xuất ra: NamespaceB::value = 20

    return 0;
}
```


## Anonymous namespace (Namespace ẩn danh)

<details><summary>Chi tiết</summary>
<p>

`Anonymous namespace` là một `namespace` không có tên

Sử dụng để giới hạn phạm vi của các hàm, biến, hoặc lớp trong một file cụ thể (tức là các file khác không thể sử dụng được dù có từ khóa `extern`)


Nó tương đương vơi việc sử dụng từ khóa `static` khai báo toán cục

Giúp tránh xung đột tên khi làm việc với các chương trình lớn hoặc nhiều file

Ví dụ:
```c
namespace {
    int hiddenVar = 42;  // Chỉ có thể truy cập trong file này
}
```
</p>
</details>

## Sử dụng `using` để đơn giản hóa cú pháp:

<details><summary>Chi tiết</summary>
<p>

Thay vì mỗi lần đều phải viết `TênNamespace::`, bạn có thể sử dụng từ khóa `using` để đơn giản hóa:
```c 
using namespace MyNamespace;

int main() {
    std::cout << var << std::endl;  // Không cần MyNamespace:: nữa
    myFunction();
    return 0;
}
```
*Lưu ý:* Khi sử dụng `using namespace`, nếu có nhiều namespace có tên thành phần trùng nhau, có thể gây ra lỗi xung đột tên

</p>
</details>


## Nested namespace (namespace lồng nhau):

<details><summary>Chi tiết</summary>
<p>

Một namespace có thể được lồng bên trong một namespace khác:
```c 
namespace OuterNamespace {
    namespace InnerNamespace {
        void innerFunction() {
            std::cout << "Hello from InnerNamespace!" << std::endl;
        }
    }
}

int main() {
    OuterNamespace::InnerNamespace::innerFunction();
    return 0;
}
```

</p>
</details>


## Namespace mở rộng

<details><summary>Chi tiết</summary>
<p>

Là một khái niệm cho phép bạn thêm các thành phần mới vào một `namespace` đã tồn tại, bằng cách định nghĩa lại `namespace` đó trong một phần khác của chương trình

Điều này rất hữu ích khi bạn cần tách biệt mã nguồn thành nhiều phần nhưng vẫn muốn các thành phần đó nằm trong cùng một `namespace`
```c 
#include <iostream>

// Định nghĩa ban đầu của namespace MyNamespace
namespace MyNamespace {
    int value = 10;

    void display() {
        std::cout << "Value in MyNamespace: " << value << std::endl;
    }
}

// Mở rộng namespace MyNamespace ở một phần khác của chương trình
namespace MyNamespace {
    void setValue(int newValue) {
        value = newValue;
    }
}

int main() {
    // Gọi hàm trong MyNamespace để hiển thị giá trị ban đầu
    MyNamespace::display();  // Xuất ra: Value in MyNamespace: 10

    // Gọi hàm setValue để thay đổi giá trị
    MyNamespace::setValue(25);

    // Gọi lại hàm display để hiển thị giá trị mới
    MyNamespace::display();  // Xuất ra: Value in MyNamespace: 25

    return 0;
}
```

</p>
</details>


## Namespace tiêu chuẩn (std) trong C++

<details><summary>Chi tiết</summary>
<p>

namespace `std` cung câp tất cả các thành phần của thư viện chuẩn C++ (như cout, cin, vector, string)
```c 
#include <iostream>
using std::cout;
using std::endl;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```
Một số thành phần nâng cao hơn sẽ được nói ở bài STL

</p>
</details>

</p>
</details>

# Bài 18: STANDARD TEMPLATE LIBRARY


<details><summary>Chi tiết</summary>
<p>

Standard Template Library ( STL) là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến



# Các thành phần chính của STL:

<details><summary>Chi tiết</summary>
<p>


## 1. Container
Container là cách gọi chung cho các cấu trúc dữ liệu tổng quát dùng để lưu trữ và quản lý các đối tượng (hoặc dữ liệu) theo một cách thức nhất định
### Các container được học:
#### Vector
Là một mảng động, có khả năng thay đổi kích thước linh hoạt khi thêm hoặc xóa phần tử

*Đặc điểm vector:*
- **Mảng động:** Kích thước của `vector` có thể thay đổi tự động khi bạn thêm hoặc xóa phần tử. Khác với mảng tĩnh (array), bạn không cần xác định kích thước cố định trước
- **Truy cập ngẫu nhiên:** `vector` hỗ trợ truy cập trực tiếp đến các phần tử thông qua chỉ số, với thời gian truy cập O(1), tương tự như mảng thông thường
- **Thêm/xóa phần tử:** Thao tác thêm hoặc xóa phần tử ở cuối vector có thời gian O(1) trong trường hợp trung bình. Tuy nhiên, thêm phần tử ở giữa hoặc đầu sẽ có độ phức tạp O(n) do cần phải di chuyển các phần tử

Ví dụ:
```C
#include <iostream>
#include <vector>

int main() {
    // Khởi tạo một vector rỗng để lưu điểm số học sinh
    std::vector<int> scores;

    // Thêm điểm vào vector
    scores.push_back(85);  // Thêm 85 vào cuối vector
    scores.push_back(90);  // Thêm 90
    scores.push_back(78);  // Thêm 78

    // In ra các phần tử trong vector
    std::cout << "Danh sách điểm số: ";
    for (int i = 0; i < scores.size(); i++) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;

    // Truy cập và in ra điểm số đầu tiên và cuối cùng
    std::cout << "Điểm số đầu tiên: " << scores.front() << std::endl;   // scores[0]
    std::cout << "Điểm số cuối cùng: " << scores.back() << std::endl;   // scores[scores.size() - 1]

    // Xóa phần tử cuối cùng
    scores.pop_back();  // Xóa điểm 78
    std::cout << "Sau khi xóa phần tử cuối: ";
    for (int score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    // Chèn điểm 88 vào đầu vector
    scores.insert(scores.begin(), 88);
    std::cout << "Sau khi chèn 88 vào đầu: ";
    for (int score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    // Xóa phần tử đầu tiên
    scores.erase(scores.begin());
    std::cout << "Sau khi xóa phần tử đầu: ";
    for (int score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    // Kiểm tra kích thước và dung lượng của vector
    std::cout << "Kích thước hiện tại của vector: " << scores.size() << std::endl;
    std::cout << "Dung lượng hiện tại của vector: " << scores.capacity() << std::endl;

    return 0;
}
```
Kết quả:
```C
Danh sách điểm số: 85 90 78 
Điểm số đầu tiên: 85
Điểm số cuối cùng: 78
Sau khi xóa phần tử cuối: 85 90 
Sau khi chèn 88 vào đầu: 88 85 90 
Sau khi xóa phần tử đầu: 85 90 
Kích thước hiện tại của vector: 2
Dung lượng hiện tại của vector: 4
```
   *Một số method của vector:*
- `at()`: Truy cập vào phần tử của vector
- `size()`: Trả về kích thước của vector
- `resize()`: Thay đổi kích thước của vector
- `begin()`: Địa chỉ của phần tử đầu tiên của vector
- `end()`: Địa chỉ của phần tử cuối cùng của vector
- `push_back()`: Thêm phần tử vào vị trí cuối của vector
#### List 
Là một container trong STL của C++, được triển khai dưới dạng danh sách liên kết đôi. Một số đặc điểm quan trọng của list gồm:

- **Truy cập tuần tự:** Các phần tử trong list chỉ có thể được truy cập theo thứ tự liên tiếp, không hỗ trợ truy cập ngẫu nhiên.
- **Hiệu suất chèn và xoá:** Việc chèn và xoá phần tử tại bất kỳ vị trí nào trong list có hiệu suất tốt hơn so với vector, đặc biệt là khi thao tác ở giữa danh sách

*Một số method của list:*
- push_back():
- pop_back():
- insert(): Chèn một node vào list
- erase(): Xóa một node của list
- size(): Trả về kích thước của list

Ví dụ:
```c 
#include <iostream>
#include <list>

int main() {
    // Khai báo một list chứa các số nguyên
    std::list<int> myList;

    // Thêm phần tử vào cuối danh sách
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // Thêm phần tử vào đầu danh sách
    myList.push_front(5);

    // Duyệt qua các phần tử trong danh sách và in ra
    std::cout << "Danh sách ban đầu: ";
    for (int value : myList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Xóa phần tử đầu tiên và cuối cùng
    myList.pop_front();
    myList.pop_back();

    // In lại danh sách sau khi xóa
    std::cout << "Danh sách sau khi xóa phần tử đầu và cuối: ";
    for (int value : myList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Chèn phần tử tại một vị trí cụ thể
    auto it = myList.begin();
    std::advance(it, 1);  // Dịch iterator đến vị trí thứ 2
    myList.insert(it, 15);

    // In danh sách sau khi chèn phần tử
    std::cout << "Danh sách sau khi chèn 15 vào vị trí thứ 2: ";
    for (int value : myList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
Kết quả:
```c 
Danh sách ban đầu: 5 10 20 30 
Danh sách sau khi xóa phần tử đầu và cuối: 10 20 
Danh sách sau khi chèn 15 vào vị trí thứ 2: 10 15 20 
```
#### Iterator
Là một đối tượng được sử dụng để duyệt qua các phần tử trong một container như `std::vector`, `std::list`, `std::map`, v.v. 

Cho phép truy cập tuần tự các phần tử trong một container mà không cần biết chi tiết về cách các phần tử đó được lưu trữ. 

Iterator hoạt động giống như một con trỏ, nhưng cung cấp nhiều tính năng linh hoạt và an toàn hơn

**Cách hoạt động:**
- Iterator cung cấp các phép toán như tăng (`++`), giảm (`--`), truy cập giá trị (`*`), và so sánh (`!=`, `==`) để duyệt và thao tác với các phần tử trong container.
- Với `std::list`, iterator được sử dụng để duyệt qua danh sách liên kết đôi


Ví dụ về cách sử dụng iterator với `std::list`
```c 
#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {10, 20, 30, 40, 50};

    // Khai báo một iterator cho list
    std::list<int>::iterator it;

    // Duyệt qua các phần tử trong list bằng iterator
    std::cout << "Các phần tử trong danh sách: ";
    for (it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";  // Sử dụng toán tử * để lấy giá trị phần tử mà iterator đang trỏ tới
    }
    std::cout << std::endl;

    return 0;
}
```

Ví dụ về cách chèn và xoá phần tử trong `std::list` bằng iterator:
```c 
#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {10, 20, 30, 40, 50};

    // Khai báo iterator
    std::list<int>::iterator it = myList.begin();

    // Dịch iterator đến vị trí thứ 2
    std::advance(it, 2);

    // Chèn giá trị 25 vào vị trí thứ 2
    myList.insert(it, 25);

    // In ra danh sách sau khi chèn
    std::cout << "Danh sách sau khi chèn 25: ";
    for (it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Xóa phần tử thứ 2
    it = myList.begin();
    std::advance(it, 2);
    myList.erase(it);

    // In ra danh sách sau khi xoá
    std::cout << "Danh sách sau khi xoá phần tử thứ 2: ";
    for (it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
Kết quả:
```c 
Danh sách sau khi chèn 25: 10 20 25 30 40 50 
Danh sách sau khi xoá phần tử thứ 2: 10 20 30 40 50 
```
#### Map 
Là một container trong STL của C++, cung cấp cấu trúc dữ liệu ánh xạ giữa các cặp key-value.
- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất.
- Bạn có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
- Ta có thể sử dụng iterator để duyệt qua các phần tử trong map

Ví dụ:
```c 
#include <iostream>
#include <map>

int main() {
    // Khai báo một map với key là kiểu int và value là kiểu string
    std::map<int, std::string> myMap;

    // Thêm phần tử vào map bằng operator []
    myMap[1] = "Apple";
    myMap[2] = "Banana";
    myMap[3] = "Cherry";

    // Thêm phần tử vào map bằng hàm insert()
    myMap.insert(std::make_pair(4, "Grapes"));

    // Duyệt qua map và in ra các phần tử
    std::cout << "Danh sách các phần tử trong map:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    // Tìm kiếm phần tử với key là 2
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Tìm thấy Key 2 với giá trị: " << it->second << std::endl;
    } else {
        std::cout << "Không tìm thấy Key 2" << std::endl;
    }

    // Xóa phần tử với key là 3
    myMap.erase(3);

    // In lại map sau khi xóa
    std::cout << "Map sau khi xóa phần tử có Key 3:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
```
Kết quả:
```C
Danh sách các phần tử trong map:
Key: 1, Value: Apple
Key: 2, Value: Banana
Key: 3, Value: Cherry
Key: 4, Value: Grapes
Tìm thấy Key 2 với giá trị: Banana
Map sau khi xóa phần tử có Key 3:
Key: 1, Value: Apple
Key: 2, Value: Banana
Key: 4, Value: Grapes
```
Ví dụ với `struct`:
```c 
#include <iostream>
#include <map>
#include <string>

struct SinhVien {
    std::string ten;
    std::string lop;
    int id;
};

int main(int argc, char const *argv[]) {
    // Khai báo map với key là kiểu int và value là struct SinhVien
    std::map<int, SinhVien> arr = {
        {0, {"Trung", "HTN", 100}},
        {1, {"Tuan", "HTN", 101}},
        {2, {"Anh", "HTN", 102}}
    };

    // Duyệt qua các phần tử trong map và in ra
    for (const auto& index : arr) {
        std::cout << "key: " << index.first
                  << ", ten: " << index.second.ten
                  << ", lop: " << index.second.lop
                  << ", ID: " << index.second.id << std::endl;
    }

    return 0;
}
```
Kết quả:
```c
key: 0, ten: Trung, lop: HTN, ID: 100
key: 1, ten: Tuan, lop: HTN, ID: 101
key: 2, ten: Anh, lop: HTN, ID: 102
```
</p>
</details>

</p>
</details>

# Bài 19: Design Patterns
Là các giải pháp có thể tái sử dụng cho những vấn đề thường gặp trong thiết kế phần mềm. Chúng cung cấp một cách tiếp cận có cấu trúc để giải quyết các vấn đề phát sinh trong quá trình phát triển phần mềm

## Các loại Design Patterns
### Creational Patterns (Mẫu khởi tạo): 
Quản lý việc khởi tạo đối tượng 
**Singleton**:

Mục đích chính của Singleton là kiểm soát việc tạo đối tượng, đảm bảo rằng chỉ có duy nhất một thể hiện (instance) của lớp và cung cấp một cách để truy cập đối tượng đó từ bất kỳ đâu trong chương trình

Đặc điểm chính:
- **Chỉ có một thể hiện duy nhất**: Lớp Singleton đảm bảo rằng chỉ có duy nhất một đối tượng của lớp được tạo ra.
- **Quyền truy cập toàn cục**: Đối tượng Singleton được cung cấp thông qua một phương thức tĩnh, giúp bạn có thể truy cập từ bất kỳ đâu trong chương trình.
- **Tạo đối tượng khi cần thiết (Lazy Initialization)**: Đối tượng Singleton thường được tạo ra khi nó được yêu cầu lần đầu tiên, giúp tiết kiệm tài nguyên

```c++
#include <iostream>
using namespace std;

class Sensor {
private:
    // Biến tĩnh để lưu trữ đối tượng duy nhất
    static Sensor* instance;

    // Hàm khởi tạo private để ngăn tạo thêm đối tượng
    Sensor() {
        cout << "Cảm biến đã được khởi tạo." << endl;
    }

public:
    // Phương thức tĩnh để lấy đối tượng duy nhất
    static Sensor* getInstance() {
        if (instance == nullptr) {
            instance = new Sensor();
        }
        return instance;
    }

    void readData() {
        cout << "Đọc dữ liệu từ cảm biến..." << endl;
    }
};

// Khởi tạo biến tĩnh ban đầu là nullptr
Sensor* Sensor::instance = nullptr;

int main() {
    // Gọi phương thức tĩnh để lấy đối tượng Singleton
    Sensor* sensor1 = Sensor::getInstance();
    sensor1->readData();

    // Gọi lại sẽ vẫn lấy cùng một đối tượng
    Sensor* sensor2 = Sensor::getInstance();
    sensor2->readData();

    return 0;
}
```
**Factory Pattern**:

Đặc điểm:

- **Tính trừu tượng:** Factory Pattern giúp ẩn đi quá trình tạo ra đối tượng, người dùng chỉ cần biết cách sử dụng đối tượng mà không cần quan tâm đến việc khởi tạo chúng.

- **Khả năng mở rộng:** Mẫu thiết kế này cho phép dễ dàng thêm các lớp đối tượng mới mà không ảnh hưởng đến mã nguồn đã có, giúp mở rộng hệ thống mà không gây gián đoạn.

- **Tính linh hoạt:** Khi cần thay đổi hoặc thêm các loại đối tượng mới, bạn chỉ cần điều chỉnh hoặc bổ sung trong Factory mà không cần sửa đổi các phần khác của hệ thống.

- **Giảm sự phụ thuộc:** Factory Pattern giảm thiểu sự phụ thuộc của mã nguồn vào các lớp cụ thể, từ đó giúp hệ thống dễ bảo trì và tăng khả năng tái sử dụng
```c++
#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở Sensor (Cảm biến)
class Sensor {
public:
    virtual void readData() = 0;  // Phương thức ảo thuần túy để các lớp con phải thực hiện
    virtual ~Sensor() {}  // Đảm bảo có hàm hủy ảo để giải phóng tài nguyên
};

// Lớp cụ thể TemperatureSensor (Cảm biến nhiệt độ)
class TemperatureSensor : public Sensor {
public:
    void readData() override {
        cout << "Đọc dữ liệu từ cảm biến nhiệt độ..." << endl;
    }
};

// Lớp cụ thể HumiditySensor (Cảm biến độ ẩm)
class HumiditySensor : public Sensor {
public:
    void readData() override {
        cout << "Đọc dữ liệu từ cảm biến độ ẩm..." << endl;
    }
};

// Lớp Factory để tạo các đối tượng cảm biến
class SensorFactory {
public:
    // Phương thức tạo cảm biến dựa trên loại cảm biến
    static Sensor* createSensor(const string& type) {
        if (type == "Temperature") {
            return new TemperatureSensor();
        } else if (type == "Humidity") {
            return new HumiditySensor();
        } else {
            cout << "Loại cảm biến không hợp lệ!" << endl;
            return nullptr;
        }
    }
};

int main() {
    // Sử dụng Factory để tạo cảm biến nhiệt độ
    Sensor* tempSensor = SensorFactory::createSensor("Temperature");
    if (tempSensor != nullptr) {
        tempSensor->readData();  // Kết quả: Đọc dữ liệu từ cảm biến nhiệt độ...
    }

    // Sử dụng Factory để tạo cảm biến độ ẩm
    Sensor* humiditySensor = SensorFactory::createSensor("Humidity");
    if (humiditySensor != nullptr) {
        humiditySensor->readData();  // Kết quả: Đọc dữ liệu từ cảm biến độ ẩm...
    }

    // Giải phóng bộ nhớ
    delete tempSensor;
    delete humiditySensor;

    return 0;
}

```

**Singleton factory:**

Cách hoạt động:
- Singleton đảm bảo chỉ có một thể hiện của lớp Factory.
- Factory cung cấp phương thức để tạo ra các đối tượng, nhưng các đối tượng này được tạo ra thông qua một điểm truy cập duy nhất là thể hiện của Singleton Factory
```c++
#include <iostream>
#include <string>

using namespace std;

// Lớp cơ sở Sensor
class Sensor {
public:
    virtual void readData() = 0;
};

// Lớp kế thừa cụ thể - Sensor Nhiệt độ
class TemperatureSensor : public Sensor {
public:
    void readData() override {
        cout << "Đọc dữ liệu từ cảm biến nhiệt độ..." << endl;
    }
};

// Lớp kế thừa cụ thể - Sensor Ánh sáng
class LightSensor : public Sensor {
public:
    void readData() override {
        cout << "Đọc dữ liệu từ cảm biến ánh sáng..." << endl;
    }
};

// Lớp Singleton Factory để tạo cảm biến
class SensorFactory {
private:
    // Biến tĩnh để lưu trữ đối tượng duy nhất
    static SensorFactory* instance;

    // Hàm khởi tạo private để ngăn tạo thêm đối tượng
    SensorFactory() {
        cout << "SensorFactory đã được khởi tạo." << endl;
    }

public:
    // Phương thức tĩnh để lấy đối tượng duy nhất của SensorFactory
    static SensorFactory* getInstance() {
        if (instance == nullptr) {
            instance = new SensorFactory();
        }
        return instance;
    }

    // Phương thức Factory để tạo cảm biến
    Sensor* createSensor(const string& type) {
        if (type == "Temperature") {
            return new TemperatureSensor();
        } else if (type == "Light") {
            return new LightSensor();
        } else {
            cout << "Loại cảm biến không hợp lệ." << endl;
            return nullptr;
        }
    }
};

// Khởi tạo biến tĩnh ban đầu là nullptr
SensorFactory* SensorFactory::instance = nullptr;

int main() {
    // Lấy đối tượng Singleton của SensorFactory
    SensorFactory* factory = SensorFactory::getInstance();

    // Sử dụng SensorFactory để tạo các cảm biến
    Sensor* tempSensor = factory->createSensor("Temperature");
    if (tempSensor != nullptr) {
        tempSensor->readData();
    }

    Sensor* lightSensor = factory->createSensor("Light");
    if (lightSensor != nullptr) {
        lightSensor->readData();
    }

    // Hủy các đối tượng cảm biến đã tạo ra
    delete tempSensor;
    delete lightSensor;

    return 0;
}
```


## Structural Patterns (Mẫu cấu trúc): 
Tổ chức cấu trúc của các lớp và đối tượng 
### Decorator Pattern:
**Đặc điểm:**
- **Tính linh hoạt:** Decorator Pattern cho phép thêm hành vi mới cho đối tượng một cách linh hoạt mà không cần thay đổi các đối tượng khác trong hệ thống.

- **Tính mở rộng:** Cho phép mở rộng tính năng mà không làm thay đổi mã nguồn gốc, giúp chương trình dễ mở rộng và bảo trì.

- **Dễ bảo trì:** Bạn có thể dễ dàng thêm hoặc thay thế các tính năng thông qua các lớp decorator mà không làm ảnh hưởng đến cấu trúc lớp hiện có.

- **Giảm sự phức tạp của kế thừa:** Thay vì tạo ra nhiều lớp con để mở rộng chức năng, bạn có thể sử dụng Decorator Pattern để xếp chồng các decorator, giảm bớt sự phức tạp trong cấu trúc kế thừa.

```c++
