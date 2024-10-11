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

# Macro khởi tạo GPIO và `MotorController`
```bash
#define INIT_MOTOR(motorName, pinNumber) \
   PIN PIN_##motorName = pinNumber; \
   MotorController motorName = {startMotor, stopMotor, changeSpeedMotor};
```

Macro `INIT_MOTOR` được sử dụng để khởi tạo một đối tượng `MotorController` cùng với số chân GPIO (`PIN`) tương ứng giúp đơn giản hóa việc khởi tạo và sử dụng các động cơ trong mã nguồn

Macro `INIT_MOTOR` nhận hai tham số:
`motorName`: Tên của đối tượng `MotorController`
`pinNumber`: Số hiệu của chân GPIO mà động cơ sẽ sử dụng

Thành phần trong Macro:
1. `PIN PIN_##motorName = pinNumber`:

    `PIN`: Đây là kiểu dữ liệu đã được định nghĩa đại diện cho số chân GPIO

   `PIN_##motorName`: Tạo một biến mới với tên được nối từ `PIN_ `và `motorName` được nối bởi toán tử nối chuỗi `##` , giúp kết hợp hai thành phần lại với nhau để tạo thành một tên biến duy nhất.

   `= pinNumber`: Gán giá trị của pinNumber cho biến PIN_motorName, đại diện cho số chân GPIO mà động cơ này sẽ kết nối

3. `MotorController motorName = {startMotor, stopMotor, changeSpeedMotor}`:
 
   `MotorController motorName`: Khai báo một biến mới `motorName` thuộc kiểu `MotorController`

   `= {startMotor, stopMotor, changeSpeedMotor}`: Khởi tạo biến motorName với các con trỏ hàm tương ứng với các chức năng `startMotor, stopMotor, và changeSpeedMotor`. Những hàm này đã được định nghĩa trước đó và sẽ thực hiện các hành động tương ứng cho động cơ

   # Sử dụng macro để khởi tạo motor A và motor B và motor C:
   ```bash
   INIT_MOTOR(motorA, 1);
   INIT_MOTOR(motorB, 2);
   INIT_MOTOR(motorC, 3);
   ```

# Sử dụng motor:
 ```bash
 // Sử dụng motorA
motorA.start(PIN_motorA);
   motorA.changeSpeed(PIN_motorA, 50);
   motorA.stop(PIN_motorA);
// Sử dụng motor B
motorB.start(PIN_motorB);
   motorB.changeSpeed(PIN_motorB, 75);
   motorB.stop(PIN_motorB);
 // Sử dụng motorC
   motorC.start(PIN_motorC);
   motorC.changeSpeed(PIN_motorC, 100);
   motorC.stop(PIN_motorC);
```

`motorA.start(PIN_motorA)`: Gọi hàm `startMotor` thông qua con trỏ hàm `start` đã được gán trong đối tượng `motorA`, Hàm `startMotor` sẽ nhận tham số là `PIN_motorA`, và khởi động động cơ gắn với chân GPIO 

`motorA.changeSpeed(PIN_motorA, 50)`: Tương tự, lệnh này sử dụng con trỏ hàm `changeSpeed` để gọi hàm `changeSpeedMotor`, thay đổi tốc độ của động cơ motorA thành 50

`motorA.stop(PIN_motorA)`: Hàm `stopMotor` được gọi thông qua con trỏ hàm `stop`, để dừng động cơ `motorA`

Các hàm ở phía sau tương tự
   
