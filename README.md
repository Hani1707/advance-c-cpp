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

Nạp chồng hàm (Function Overloading): 

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

Nạp chồng toán tử (Operator Overloading):


#### 2. Đa hình động (Runtime polymorphism)


 #### Tính trừu tượng (Abstract Class)

Lớp chứa ít nhất một hàm thuần ảo (pure virtual function)

Cú pháp `virtual void ham() = 0;`

Lớp trừu tượng không thể tạo đối tượng trực tiếp mà chỉ có thể làm lớp cơ sở cho các lớp dẫn xuất
```c
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










