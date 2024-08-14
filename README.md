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




