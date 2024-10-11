# Định nghĩa một cấu trúc 'SinhVien'
 ```bash
typedef struct {
   char ten[50];
   float diemTrungBinh;
   int id;
} SinhVien;
 ```
`struct` là một kiểu dữ liệu tự định nghĩa bởi người dùng. Nó cho phép nhóm các biến có kiểu dữ liệu khác nhau lại với nhau dưới một tên chung. Trong trường hợp này, cấu trúc SinhVien được định nghĩa để lưu trữ thông tin của một sinh viên.

Cấu trúc SinhVien đã gồm ba thành phần:

`char ten[50]`: Một mảng ký tự (chuỗi) để lưu tên của sinh viên có thể dài tối đa 49 ký tự.

`float diemTrungBinh`: Một biến kiểu float lưu trữ một giá trị thập phân đại diện cho điểm trung bình.

`int id`: Một biến kiểu int để lưu mã số sinh viên (ID) là một số nguyên dùng để phân biệt các sinh viên với nhau.

`typedef`: là từ khóa cho phép người dùng thêm tên mới cho kiểu có sẵn. Nhờ typedef, không cần phải viết từ khóa struct mỗi khi khai báo một biến kiểu SinhVien.

# Khởi tạo mảng SinhVien danhSachSV[]:
```bash
SinhVien danhSachSV[] = {
    {
        .ten = "Nhan",
        .diemTrungBinh = 10,
        .id = 100
    },
    {
        .ten = "Han",
        .diemTrungBinh = 9,
        .id = 101
    },
    {
        .ten = "Hoang",
        .diemTrungBinh = 8,
        .id = 102
    },
    {
        .ten = "Ngan",
        .diemTrungBinh = 5.6,
        .id = 99
    }
};
```
Mảng danhSachSV[] là một mảng chứa các phần tử có kiểu dữ liệu là SinhVien.

Kiểu dữ liệu SinhVien là một cấu trúc (struct) bao gồm :

`ten` (kiểu chuỗi ký tự)

`diemTrungBinh` (kiểu số thực)

`id` (kiểu số nguyên).

Mỗi phần tử trong mảng danhSachSV là một biến cấu trúc kiểu SinhVien, tức là mỗi phần tử trong mảng sẽ bao gồm ba thành phần: ten, diemTrungBinh, và id.

Gán các giá trị cho các thành phần của phần tử:

Trong đoạn mã trên, mảng danhSachSV được khởi tạo với bốn phần tử, mỗi phần tử đại diện cho một sinh viên với các thông tin như tên, điểm trung bình, và ID.

Ví dụ:
```bash
{
        .ten = "Nhan",
        .diemTrungBinh = 10,
        .id = 100
    },
```
ten: "Nhan"

diemTrungBinh: 10

id: 100
Đây là phần tử đầu tiên trong mảng danhSachSV.
# Tính số lượng phần tử trong mảng danhSachSV
```bash 
size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]);
```
 `sizeof(danhSachSV)`:  là phép tính kích thước toàn bộ mảng `danhSachSV` tính bằng byte.

  `sizeof(danhSachSV)`: trả về số byte chiếm bởi toàn bộ mảng `danhSachSV`

  Vì `danhSachSV` là một mảng của các phần tử kiểu `SinhVien`, nên kích thước này sẽ bằng kích thước của tất cả các phần tử trong mảng cộng lại.

  `sizeof(danhSachSV[0])`: là phép tính kích thước của một phần tử trong mảng `danhSachSV`.

  `danhSachSV[0]` là phần tử đầu tiên trong mảng, có kiểu `SinhVien`

  `sizeof(danhSachSV[0])` trả về số byte chiếm bởi một phần tử duy nhất trong mảng, tức là một cấu trúc `SinhVien`

  # Hàm so sánh theo tên:
  ```bash
int compareByName(const void *a, const void *b) {
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    return stringCompare(sv1->ten, sv2->ten);
}
```
Hàm `compareByName` nhận hai tham số truyền vào:

`*const void a`: Con trỏ kiểu `void` có thể trỏ tới một sinh viên.
`*const void b`: Tương tự, đây là con trỏ kiểu `void` trỏ tới sinh viên khác


```bash
int stringCompare(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}
```
Hàm `stringCompare` này dùng để so sánh hai chuỗi ký tự theo thứ tự từ điển

Vòng lặp ` while (*str1 && (*str1 == *str2)) {`  so sánh từng ký tự một cho đến khi tìm thấy sự khác biệt hoặc cho đến khi một trong hai chuỗi kết thúc

Nếu giống nhau: Nếu hai ký tự hiện tại của `str1` và `str2` giống nhau, con trỏ `str1` và `str2` sẽ được tăng lên để tiếp tục so sánh ký tự tiếp theo

Nếu khác nhau: Nếu có sự khác nhau ở bất kỳ ký tự nào, vòng lặp sẽ dừng lại

Phép trừ giữa hai ký tự: 
```bash
return *(const unsigned char*)str1 - *(const unsigned char*)str2;
```
Sau khi vòng lặp dừng, hàm sẽ trả về hiệu số giữa hai ký tự đầu tiên không giống nhau

Hai ký tự tại vị trí mà sự khác biệt được tìm thấy sẽ được lấy giá trị ASCII của chúng.

Để đảm bảo tính chính xác, các ký tự được ép kiểu về `const unsigned char*` trước khi trừ, điều này giúp tránh sai sót khi so sánh các ký tự có dấu hoặc ký tự không phải chữ cái.

# Hàm so sánh điểm trung bình
```bash
int compareByDiemTrungBinh(const void *a, const void *b) {
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    if (sv1->diemTrungBinh > sv2->diemTrungBinh) {
        return 1;
    }
    return 0;
}
```
Hàm `compareByDiemTrungBinh` dùng để so sánh điểm trung bình của hai `SinhVien`. Hàm này sẽ được sử dụng trong các thuật toán sắp xếp để sắp xếp danh sách sinh viên theo thứ tự tăng dần của điểm trung bình
# Hàm so sánh ID:
```bash
int compareByID(const void *a, const void *b) {
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    return sv1->id - sv2->id;
}
```
Hàm `compareByID` dùng để so sánh ID của hai `SinhVien`. Hàm này sẽ được sử dụng trong các thuật toán sắp xếp để sắp xếp danh sách sinh viên theo thứ tự tăng dần của ID.

# Hàm sắp xếp chung:
```bash
void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *)) {
   int i, j;
   SinhVien temp;
   for (i = 0; i < size-1; i++)    
       for (j = i+1; j < size; j++)
           if (compareFunc(array+i, array+j)>0) {
               temp = array[i];
               array[i] = array[j];
               array[j] = temp;
           }
}
```
Hàm `sort` nhận ba tham số truyền vào:
1. `SinhVien array[]`: Mảng chứa các phần tử là kiểu dữ liệu `SinhVien`
   
2. `size_t size`: Kích thước của mảng, biểu diễn số lượng phần tử trong mảng

3. `int (*compareFunc)(const void *, const void *)`: Một con trỏ tới hàm so sánh được dùng để xác định thứ tự sắp xếp.

Hàm `sort` sử dụng thuật toán Bubble Sort sắp xếp các phần tử trong mảng để so sánh được truyền vào sẽ được sử dụng để xác định thứ tự của hai phần tử trong mảng. Nếu hàm so sánh trả về giá trị lớn hơn 0, hai phần tử sẽ được hoán đổi vị trí

# Hàm hiển thị:
```bash
void display(SinhVien *array, size_t size) {
   for (size_t i = 0; i < size; i++) {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
   }
   printf("\n");
}
```
Hàm `display` nhận hai tham số truyền vào:
1. `*SinhVien array`: Mảng chứa các sinh viên cần hiển thị

2. `size_t size`: Kích thước của mảng, biểu diễn số lượng sinh viên

Hàm `display` duyệt qua mảng và hiển thị thông tin của từng sinh viên sử dụng vòng lặp để duyệt qua từng phần tử trong mảng array, in ra thông tin `ID`, `ten`, và `diemTrungBinh` của từng sinh viên 

# Tối ưu đoạn code:
Hàm `compareByDiemTrungBinh` không trả về kết quả đúng nếu điểm trung bình của hai sinh viên bằng nhau `sv1->diemTrungBinh < sv2->diemTrungBinh`:

Nếu `sv1->diemTrungBinh` lớn hơn `sv2->diemTrungBinh`, hàm trả về 1. Nếu không, hàm luôn trả về 0, nghĩa là không thể sắp xếp chính xác trong trường hợp `sv1->diemTrungBinh < sv2->diemTrungBinh`.
Giải pháp: Hàm `compareByDiemTrungBinh` nên trả về -1 nếu `sv1->diemTrungBinh < sv2->diemTrungBinh`, và 0 nếu hai giá trị bằng nhau.

Sửa đổi:
```bash
int compareByDiemTrungBinh(const void *a, const void *b) {
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    if (sv1->diemTrungBinh > sv2->diemTrungBinh)
        return 1;
    else if (sv1->diemTrungBinh < sv2->diemTrungBinh)
        return -1;
    else
        return 0;
}
```



