# Khai báo các macro:
```bash
// Màu sắc
#define COLOR_RED 0	        //00
#define COLOR_BLUE 1        //01
#define COLOR_BLACK 2       //10
#define COLOR_WHITE 3       //11

// Công suất động cơ
#define POWER_100HP 0
#define POWER_150HP 1
#define POWER_200HP 2

// Dung tích động cơ
#define ENGINE_1_5L 0
#define ENGINE_2_0L 1

// Tùy chọn thêm
#define SUNROOF_MASK 1 << 0     // 0001
#define PREMIUM_AUDIO_MASK 1 << 1 // 0010
#define SPORTS_PACKAGE_MASK 1 << 2 // 0100
```
`color` được lưu trữ trong 2 bits, nên các giá trị số nguyên từ 0 đến 3 sẽ được biểu diễn như sau trong hệ nhị phân:
- COLOR_RED = 0 = 00 (2-bit)
- COLOR_BLUE = 1 = 01 (2-bit)
- COLOR_BLACK = 2 = 10 (2-bit)
- COLOR_WHITE = 3 = 11 (2-bit)
  
Các thuộc tính khác tương tự

# Định nghĩa kiểu dữ liệu:

```bash
typedef uint8_t CarColor;
typedef uint8_t CarPower;
typedef uint8_t CarEngine;
```

`typedef uint8_t CarColor;`: `CarColor` được định nghĩa như là một kiểu `uint8_t`, tức là một số nguyên không dấu 8 bit. Tương tự, `CarPower` và `CarEngine` cũng được định nghĩa như vậy.

Mỗi thuộc tính `CarColor`, `CarPower`, và `CarEngine` sẽ sử dụng 8 bits trong bộ nhớ
```bash
typedef struct {
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung
    CarColor color : 2;
    CarPower power : 2;
    CarEngine engine : 1;
} CarOptions;
```

`typedef struct`: Định nghĩa một cấu trúc `CarOptions` để lưu trữ các thuộc tính của một chiếc xe

Trong cấu trúc `CarOptions`, các bits được phân bố từ phải qua trái với thứ tự:

- `additionalOptions`: Sử dụng 3 bits đầu tiên để lưu trữ các tùy chọn thêm.
- `color`: Sử dụng 2 bits tiếp theo để lưu trữ màu sắc của xe.
- `power`: Sử dụng 2 bits tiếp theo để lưu trữ công suất của động cơ.
- `engine`: Sử dụng 1 bit cuối cùng để lưu trữ loại động cơ

# Hàm `configureCar`
```bash
void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options) {
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}
```
Hàm `configureCar` được sử dụng để cấu hình một đối tượng `CarOptions, giúp thiết lập các thuộc tính của chiếc xe, bao gồm màu sắc, công suất động cơ, dung tích động cơ, và các tùy chọn bổ sung

Các tham số của hàm `configureCar`:
-`CarOptions *car`: Là con trỏ tới đối tượng `CarOptions`. Thông qua con trỏ này, hàm có thể truy cập và thay đổi các thuộc tính của đối tượng mà nó trỏ tới.
- `CarColor color`: Là giá trị màu sắc của xe. Kiểu `CarColor` là một `typedef` của `uint8_t`, và giá trị này được lấy từ các hằng số như `COLOR_RED, COLOR_BLUE`
- `CarPower power`: Là giá trị công suất của động cơ xe. Kiểu `CarPower` cũng là một `typedef` của `uint8_t`, và giá trị này được lấy từ các hằng số như `POWER_100HP, POWER_150HP`
- `CarEngine engine`: Là giá trị dung tích động cơ của xe. Kiểu `CarEngine` cũng là một `typedef` của `uint8_t`, và giá trị này được lấy từ các hằng số như `ENGINE_1_5L, ENGINE_2_0L`
- `uint8_t options`: Là giá trị chứa các tùy chọn bổ sung cho xe. Mỗi bit trong giá trị này đại diện cho một tùy chọn thêm như `SUNROOF_MASK, PREMIUM_AUDIO_MASK, SPORTS_PACKAGE_MASK`

Hàm này sẽ gán giá trị cho thuộc tính, ví dụ với `color`:
```c
car->color = color;
```
Giá trị `color` được truyền vào hàm sẽ được gán cho thuộc tính `color` trong đối tượng `CarOptions` mà `car` trỏ tới.

# Hàm `setOption` và `unsetOption`
```c
void setOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions |= optionMask;
}
```

```c
void unsetOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions &= ~optionMask;
}
```

Hai hàm `setOption` và `unsetOption` được sử dụng để thao tác các tùy chọn bổ sung trong thuộc tính `additionalOptions` của đối tượng `CarOptions`

Hàm `setOption` nhận vào hai tham số:

-`CarOptions *car`: Là con trỏ tới đối tượng `CarOptions` mà bạn muốn cấu hình
-`uint8_t optionMask`: Là một `bitmask` đại diện cho một hoặc nhiều tùy chọn mà người dùng muốn bật

Hàm sử dụng toán tử OR (`|=`) để bật các tùy chọn bổ sung được chỉ định bởi `optionMask`

Tương tự như hàm `setOption`, hàm `unsetOption` cũng nhận vào hai tham số 

Hàm sử dụng toán tử AND với phủ định (`&= ~`) để tắt các tùy chọn bổ sung được chỉ định bởi `optionMask`






