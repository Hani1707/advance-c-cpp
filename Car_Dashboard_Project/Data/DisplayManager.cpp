#ifndef DISPLAYMANAGER_HPP
#define DISPLAYMANAGER_HPP

#include <iostream>  // Để sử dụng std::cout cho việc mô phỏng hiển thị
#include "Observer.hpp" // Kế thừa từ lớp Observer
#include "DashboardController.hpp" // Để lấy dữ liệu từ DashboardController

// Lớp DisplayManager chịu trách nhiệm hiển thị thông tin lên giao diện
class DisplayManager : public Observer {
public:
    // Constructor và Destructor
    DisplayManager(DashboardController* dashboardController);
    ~DisplayManager();

    // Phương thức cập nhật giao diện tổng quát
    void updateDisplay();  // Nhận dữ liệu từ DashboardController và cập nhật giao diện

    // Phương thức hiển thị cụ thể cho từng thông số
    void showSpeed(int speed);               // Hiển thị tốc độ
    void showBatteryStatus(int batteryLevel); // Hiển thị mức pin còn lại
    void showClimateStatus(int climateTemp);  // Hiển thị nhiệt độ điều hòa

    // Phương thức từ Observer - được gọi khi có thay đổi dữ liệu
    void update() override;

private:
    // Con trỏ tới DashboardController để lấy dữ liệu
    DashboardController* dashboardController;
};

#endif // DISPLAYMANAGER_HPP