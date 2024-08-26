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


