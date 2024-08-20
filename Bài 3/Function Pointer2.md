# Định nghĩa kiểu dữ liệu `MotorController` và `PIN`
```bash
typedef struct {
   void (*start)(int gpio);
   void (*stop)(int gpio);
   void (*changeSpeed)(int gpio, int speed);
} MotorController;

typedef int PIN;
```
`typedef`: Cho phép tạo một tên mới cho một kiểu dữ liệu. Dùng để định nghĩa một kiểu cấu trúc mới gọi là `MotorController`
`struct`: Chứa các con trỏ hàm (function pointers). Cho phép lưu các hàm điều khiển động cơ (như bắt đầu, dừng, thay đổi tốc độ) trong một đối tượng duy nhất

Cấu trúc `MotorController` gồm 3 thành phần:
`void (*start)(int gpio)`: Là con trỏ hàm trỏ đến một hàm có kiểu trả về là void và nhận một tham số duy nhất là `int gpio` đại diện cho số chân GPIO
`void (*stop)(int gpio)`: Con trỏ hàm này trỏ đến hàm để dừng động cơ với tham số là chân GPIO
`void (*changeSpeed)(int gpio, int speed)`: Là con trỏ hàm trỏ đến một hàm thay đổi tốc độ của động cơ, với hai tham số: `gpio` (chân GPIO) và `speed` (tốc độ)
# Các hàm chung:
```bash
void startMotor(PIN pin) {
    printf("Start motor at PIN %d\n", pin);
}

void stopMotor(PIN pin) {
    printf("Stop motor at PIN %d\n", pin);
}

void changeSpeedMotor(PIN pin, int speed) {
    printf("Change speed at PIN %d: %d\n", pin, speed);
}
```
Các hàm trên cung cấp các thao tác cơ bản với động cơ thông qua các chân GPIO, bao gồm việc khởi động, dừng và thay đổi tốc độ của động cơ.
Mỗi hàm đều nhận vào tham số `PIN` để xác định chân GPIO mà động cơ kết nối, và hàm `changeSpeedMotor` còn nhận thêm tham số `speed` để thiết lập tốc độ mới cho động cơ.
Các hàm này rất rõ ràng, giúp dễ dàng điều khiển động cơ thông qua các chân GPIO cụ thể và in ra trạng thái hiện tại của động cơ.
