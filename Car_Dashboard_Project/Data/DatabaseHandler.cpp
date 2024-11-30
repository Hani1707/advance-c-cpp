#include "DatabaseHandler.hpp"

/**
 * @brief Tải dữ liệu từ file CSV vào bộ nhớ.
 * Mở file CSV và đọc từng dòng, phân tách key và value để lưu vào map và vector lưu trữ thứ tự.
 */
void DatabaseHandler::loadData() {
    data.clear();
    keysOrder.clear();
    std::ifstream file(DATABASE_PATH);
    if (!file.is_open()) {
        std::cerr << "Không thể mở file: " << DATABASE_PATH << std::endl;
        return;
    }

    std::string line;
    bool is_header = true;
    // Đọc từng dòng từ file CSV
    while (std::getline(file, line)) {
        if (is_header) {
            is_header = false;
            continue; // Bỏ qua dòng tiêu đề (header)
        }
        std::stringstream line_stream(line);
        std::string key, value;
        // Phân tách key và value bằng dấu phẩy
        if (std::getline(line_stream, key, ',') && std::getline(line_stream, value)) {
            data[key] = value;         // Lưu key và value vào map
            keysOrder.push_back(key);  // Lưu thứ tự của key
        }
    }
    file.close();
}

/**
 * @brief Lưu dữ liệu từ bộ nhớ vào file CSV.
 * Ghi lại dữ liệu vào file CSV theo thứ tự lưu trữ ban đầu để đảm bảo thứ tự không thay đổi.
 */
void DatabaseHandler::saveData() const {
    std::ofstream file_out(DATABASE_PATH, std::ios::trunc); // Mở file ở chế độ ghi đè
    if (!file_out.is_open()) {
        std::cerr << "Không thể mở file để ghi: " << DATABASE_PATH << std::endl;
        return;
    }

    file_out << "key,value\n"; // Ghi header vào file CSV
    // Ghi từng cặp key-value theo thứ tự lưu trữ
    for (const auto& key : keysOrder) {
        auto it = data.find(key);
        if (it != data.end()) {
            file_out << key << "," << it->second << "\n"; // Ghi lại dòng đã cập nhật
        }
    }
    file_out.close();
}

/**
 * @brief Constructor. Tự động tải dữ liệu từ file CSV khi đối tượng được khởi tạo.
 */
DatabaseHandler::DatabaseHandler() {
    loadData();
}

/**
 * @brief Lấy dữ liệu từ enum key và trả về dưới dạng chuỗi.
 * @param key Enum biểu diễn thuộc tính cần lấy dữ liệu.
 * @return Chuỗi chứa giá trị tương ứng.
 */
std::string DatabaseHandler::getDataString(SystemAttribute key) const {
    std::string keyStr = enumToString(key);
    auto it = data.find(keyStr);
    if (it != data.end()) {
        return it->second;
    }
    return "Không tìm thấy key"; // Trả về chuỗi thông báo nếu không tìm thấy key
}

/**
 * @brief Đặt dữ liệu từ enum key với giá trị chuỗi.
 * @param key Enum biểu diễn thuộc tính cần cập nhật.
 * @param value Chuỗi giá trị mới.
 */
void DatabaseHandler::setData(SystemAttribute key, const std::string& value) {
    std::string keyStr = enumToString(key);
    // Kiểm tra xem key có tồn tại không
    if (data.find(keyStr) != data.end()) {
        data[keyStr] = value; // Cập nhật giá trị
        saveData(); // Ghi dữ liệu vào file sau khi cập nhật
    } else {
        std::cerr << "Key không tồn tại: " << keyStr << std::endl;
    }
}

/**
 * @brief Đặt dữ liệu từ enum key với giá trị số nguyên.
 * @param key Enum biểu diễn thuộc tính cần cập nhật.
 * @param value Giá trị số nguyên mới.
 */
void DatabaseHandler::setData(SystemAttribute key, int value) {
    setData(key, std::to_string(value)); // Chuyển số nguyên thành chuỗi và gọi hàm `setData`
}

/**
 * @brief Hàm hiển thị toàn bộ dữ liệu để kiểm tra và debug.
 */
void DatabaseHandler::printData() const {
    for (const auto& [key, value] : data) {
        std::cout << key << ": " << value << std::endl; // In ra từng cặp key-value
    }
}

/**
 * @brief Đặt nhiều cặp key-value cùng một lúc với các kiểu giá trị khác nhau.
 * @tparam T Kiểu dữ liệu của giá trị (có thể là số nguyên, enum, v.v.).
 * @param keyValuePairs Vector chứa các cặp key-value.
 */
void DatabaseHandler::setMultipleData(const std::vector<std::pair<SystemAttribute, DataVariant>>& keyValuePairs) {
    bool updated = false;
    for (const auto& [key, value] : keyValuePairs) {
        std::string keyStr = enumToString(key);
        std::string valueStr;

        // Xử lý từng kiểu giá trị trong std::variant
        std::visit([&valueStr](auto&& val) {
            using T = std::decay_t<decltype(val)>;
            if constexpr (std::is_same_v<T, int>) {
                valueStr = std::to_string(val);
            } else if constexpr (std::is_same_v<T, std::string>) {
                valueStr = val;
            } else {
                valueStr = enumToString(val); // Gọi hàm enumToString cho các enum
            }
        }, value);

        if (data.find(keyStr) != data.end()) {
            data[keyStr] = valueStr;
            updated = true;
        } else {
            std::cerr << "Key không tồn tại: " << keyStr << std::endl;
        }
    }
    if (updated) {
        saveData();
    }
}