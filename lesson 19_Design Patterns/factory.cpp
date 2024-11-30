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