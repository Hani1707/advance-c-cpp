#include <stdio.h>          // Thư viện hỗ trợ các hàm nhập/xuất chuẩn
#include <string.h>         // Thư viện hỗ trợ các hàm xử lý chuỗi
#include <stdlib.h>         // Thư viện hỗ trợ cấp phát và giải phóng bộ nhớ động
#include <stddef.h>         // Thư viện hỗ trợ các hàm và kiểu dữ liệu chuẩn
#include <ctype.h>          // Thư viện hỗ trợ kiểm tra và chuyển đổi ký tự
#include <stdbool.h>        // Thư viện hỗ trợ kiểu boolean (true/false)


// Định nghĩa kiểu dữ liệu cho JSON với các kiểu khác nhau
typedef enum {
    JSON_NULL,              // Giá trị null
    JSON_BOOLEAN,           // Giá trị boolean (true/false)
    JSON_NUMBER,            // Giá trị số
    JSON_STRING,            // Chuỗi ký tự
    JSON_ARRAY,             // Mảng
    JSON_OBJECT             // Đối tượng (object)
} JsonType;


// Định nghĩa cấu trúc JsonValue để lưu trữ giá trị JSON
typedef struct JsonValue {
    JsonType type;          // Kiểu của JSON
    union {                 // Sử dụng union để lưu trữ một trong các kiểu giá trị
        int boolean;        // Giá trị boolean
        double number;      // Giá trị số
        char *string;       // Giá trị chuỗi ký tự
        struct {            // Cấu trúc cho mảng
            struct JsonValue *values; // Các phần tử của mảng
            size_t count;             // Số lượng phần tử
        } array;
        struct {            // Cấu trúc cho đối tượng
            char **keys;               // Danh sách khóa (key)
            struct JsonValue *values;  // Danh sách giá trị tương ứng
            size_t count;              // Số lượng cặp key-value
        } object;
    } value;
} JsonValue;


// Khai báo hàm parse_json để phân tích chuỗi JSON
JsonValue *parse_json(const char **json);

// Khai báo hàm free_json_value để giải phóng bộ nhớ đã cấp phát cho JsonValue
void free_json_value(JsonValue *json_value);

// Hàm bỏ qua khoảng trắng trong chuỗi JSON
static void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

// Hàm phân tích cú pháp giá trị null trong JSON
JsonValue *parse_null(const char **json) {
    skip_whitespace(json);                          // Bỏ qua khoảng trắng
    if (strncmp(*json, "null", 4) == 0) {           // Kiểm tra chuỗi "null"
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));  // Cấp phát bộ nhớ cho JsonValue
        value->type = JSON_NULL;                    // Gán kiểu là JSON_NULL
        *json += 4;                                 // Di chuyển con trỏ chuỗi qua "null"
        return value;                               // Trả về JsonValue đã tạo
    }
    return NULL;
}

// Hàm phân tích cú pháp giá trị boolean trong JSON (true/false)
JsonValue *parse_boolean(const char **json) {
    skip_whitespace(json);                          // Bỏ qua khoảng trắng
    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));  // Cấp phát bộ nhớ cho JsonValue
    if (strncmp(*json, "true", 4) == 0) {           // Kiểm tra chuỗi "true"
        value->type = JSON_BOOLEAN;                 // Gán kiểu là JSON_BOOLEAN
        value->value.boolean = true;                // Gán giá trị true
        *json += 4;                                 // Di chuyển con trỏ chuỗi qua "true"
    } else if (strncmp(*json, "false", 5) == 0) {   // Kiểm tra chuỗi "false"
        value->type = JSON_BOOLEAN;                 // Gán kiểu là JSON_BOOLEAN
        value->value.boolean = false;               // Gán giá trị false
        *json += 5;                                 // Di chuyển con trỏ chuỗi qua "false"
    } else {
        free(value);                                // Giải phóng bộ nhớ nếu không tìm thấy true/false
        return NULL;
    }
    return value;
}

// Hàm phân tích cú pháp giá trị số trong JSON
JsonValue *parse_number(const char **json) {
    skip_whitespace(json);                          // Bỏ qua khoảng trắng
    char *end;

    double num = strtod(*json, &end);               // Chuyển chuỗi sang số thực
    if (end != *json) {                             // Nếu chuyển đổi thành công
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));  // Cấp phát bộ nhớ cho JsonValue
        value->type = JSON_NUMBER;                  // Gán kiểu là JSON_NUMBER
        value->value.number = num;                  // Gán giá trị số
        *json = end;                                // Di chuyển con trỏ chuỗi qua phần số đã đọc
        return value;
    }
    return NULL;
}

// Hàm phân tích cú pháp chuỗi trong JSON
JsonValue *parse_string(const char **json) {
    skip_whitespace(json);                          // Bỏ qua khoảng trắng

    if (**json == '\"') {                           // Nếu ký tự đầu tiên là dấu "
        (*json)++;                                  // Bỏ qua dấu "
        const char *start = *json;                  // Lưu vị trí bắt đầu của chuỗi
        while (**json != '\"' && **json != '\0') {  // Tìm dấu " kết thúc hoặc ký tự null
            (*json)++;
        }
        if (**json == '\"') {                       // Nếu tìm thấy dấu " kết thúc
            size_t length = *json - start;          // Tính độ dài chuỗi
            char *str = (char *) malloc((length + 1) * sizeof(char));  // Cấp phát bộ nhớ cho chuỗi
            strncpy(str, start, length);            // Sao chép chuỗi vào bộ nhớ
            str[length] = '\0';                     // Thêm ký tự null kết thúc chuỗi

            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));  // Cấp phát bộ nhớ cho JsonValue
            value->type = JSON_STRING;              // Gán kiểu là JSON_STRING
            value->value.string = str;              // Gán chuỗi vừa đọc
            (*json)++;                              // Di chuyển con trỏ chuỗi qua dấu "
            return value;
        }
    }
    return NULL;
}

// Hàm phân tích cú pháp mảng trong JSON
JsonValue *parse_array(const char **json) {
    skip_whitespace(json);                          // Bỏ qua khoảng trắng
    if (**json == '[') {                            // Nếu ký tự đầu là dấu [
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));  // Cấp phát bộ nhớ cho JsonValue
        array_value->type = JSON_ARRAY;             // Gán kiểu là JSON_ARRAY
        array_value->value.array.count = 0;         // Đặt số phần tử mảng bằng 0
        array_value->value.array.values = NULL;     // Gán con trỏ mảng bằng NULL

        while (**json != ']' && **json != '\0') {   // Lặp cho đến khi tìm thấy dấu ]
            JsonValue *element = parse_json(json);  // Gọi hàm parse_json để phân tích các phần tử
            if (element) {
                array_value->value.array.count++;   // Tăng số phần tử của mảng
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));  // Cấp phát thêm bộ nhớ cho mảng
                array_value->value.array.values[array_value->value.array.count - 1] = *element;  // Thêm phần tử vào mảng
                free(element);                      // Giải phóng bộ nhớ tạm thời của phần tử
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == ']') {                        // Nếu gặp dấu ]
            (*json)++;
            return array_value;                     // Trả về JsonValue đã tạo
        } else {
            free_json_value(array_value);           // Giải phóng bộ nhớ nếu có lỗi
            return NULL;
        }
    }
    return NULL;
}

// Hàm phân tích cú pháp đối tượng (object) trong JSON
JsonValue *parse_object(const char **json) {
    skip_whitespace(json);                          // Bỏ qua khoảng trắng
    if (**json == '{') {                            // Nếu ký tự đầu là dấu {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));  // Cấp phát bộ nhớ cho JsonValue
        object_value->type = JSON_OBJECT;           // Gán kiểu là JSON_OBJECT
        object_value->value.object.count = 0;       // Đặt số cặp key-value bằng 0
        object_value->value.object.keys = NULL;     // Gán con trỏ keys bằng NULL
        object_value->value.object.values = NULL;   // Gán con trỏ values bằng NULL

        while (**json != '}' && **json != '\0') {   // Lặp cho đến khi gặp dấu }
            JsonValue *key = parse_string(json);    // Phân tích khóa (key) dưới dạng chuỗi
            if (key) {
                skip_whitespace(json);
                if (**json == ':') {                // Nếu có dấu :
                    (*json)++;
                    JsonValue *value = parse_json(json);  // Phân tích giá trị của key
                    if (value) {
                        object_value->value.object.count++;  // Tăng số cặp key-value
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));  // Cấp phát thêm bộ nhớ cho danh sách keys
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));  // Cấp phát thêm bộ nhớ cho danh sách values
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);                // Giải phóng bộ nhớ tạm thời của value
                    } else {
                        free_json_value(key);       // Giải phóng bộ nhớ nếu có lỗi
                        break;
                    }
                } else {
                    free_json_value(key);           // Giải phóng bộ nhớ nếu không có dấu :
                    break;
                }
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == '}') {                        // Nếu gặp dấu }
            (*json)++;
            return object_value;                    // Trả về JsonValue đã tạo
        } else {
            free_json_value(object_value);          // Giải phóng bộ nhớ nếu có lỗi
            return NULL;
        }
    }
    return NULL;
}

// Hàm tổng quát để phân tích cú pháp JSON, gọi các hàm phụ thuộc vào loại giá trị
JsonValue *parse_json(const char **json) { 
    while (isspace(**json)) {
        (*json)++;
    }

    switch (**json) {                               // Dựa vào ký tự đầu tiên để phân tích
        case 'n':
            return parse_null(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case '\"':
            return parse_string(json);
        case '[':
            return parse_array(json);
        case '{':
            return parse_object(json);
        default:
            if (isdigit(**json) || **json == '-') {
                return parse_number(json);          // Nếu là số
            } else {
                // Lỗi phân tích cú pháp
                return NULL;
            }
    }
}

// Hàm giải phóng bộ nhớ của JsonValue
void free_json_value(JsonValue *json_value) {
    if (json_value == NULL) {
        return;
    }

    switch (json_value->type) {
        case JSON_STRING:
            free(json_value->value.string);         // Giải phóng chuỗi
            break;

        case JSON_ARRAY:                            // Giải phóng các phần tử trong mảng
            for (size_t i = 0; i < json_value->value.array.count; i++) {
                free_json_value(&json_value->value.array.values[i]);
            }
            free(json_value->value.array.values);
            break;

        case JSON_OBJECT:                           // Giải phóng các cặp key-value trong đối tượng
            for (size_t i = 0; i < json_value->value.object.count; i++) {
                free(json_value->value.object.keys[i]);
                free_json_value(&json_value->value.object.values[i]);
            }
            free(json_value->value.object.keys);
            free(json_value->value.object.values);
            break;

        default:
            break;
    }
}

// Hàm test để hiển thị giá trị JSON
void test(JsonValue* json_value){
    if (json_value != NULL && json_value->type == JSON_OBJECT) {
        size_t num_fields = json_value->value.object.count;  // Lấy số lượng trường trong đối tượng
        for (size_t i = 0; i < num_fields; ++i) {
            char* key = json_value->value.object.keys[i];   // Lấy khóa (key)
            JsonValue* value = &json_value->value.object.values[i];  // Lấy giá trị
            JsonType type = json_value->value.object.values[i].type;  // Lấy kiểu của giá trị

            if(type == JSON_STRING){
                printf("%s: %s\n", key, value->value.string);  // In ra chuỗi
            }
            if(type == JSON_NUMBER){
                printf("%s: %f\n", key, value->value.number);  // In ra số
            }
            if(type == JSON_BOOLEAN){
                printf("%s: %s\n", key, value->value.boolean ? "True":"False");  // In ra boolean
            }
            if(type == JSON_OBJECT){
                printf("%s: \n", key);                         // Đệ quy nếu giá trị là đối tượng
                test(value);
            }
            if(type == JSON_ARRAY){
                printf("%s: ", key);                           // Đệ quy nếu giá trị là mảng
                for (int i = 0; i < value->value.array.count; i++) {
                   test(value->value.array.values + i);
                } 
                printf("\n");
            }
        }
    }
    else {
        // Kiểm tra và in giá trị của các loại dữ liệu khác (chuỗi, số, boolean)
        if(json_value->type == JSON_STRING){
            printf("%s ", json_value->value.string);
        }
        if(json_value->type == JSON_NUMBER){
            printf("%f ", json_value->value.number);
        }
        if(json_value->type == JSON_BOOLEAN){
            printf("%s ", json_value->value.boolean ? "True":"False");
        }
        if(json_value->type == JSON_OBJECT){
            printf("%s: \n", json_value->value.object.keys);
            test(json_value->value.object.values);
        }
    }
}

// Hàm main để chạy chương trình
int main(int argc, char const *argv[]) {
    const char* json_str = "{...}";  // Chuỗi JSON đầu vào

    JsonValue* json_value = parse_json(&json_str);  // Phân tích cú pháp chuỗi JSON

    test(json_value);  // Hiển thị kết quả phân tích cú pháp

    free_json_value(json_value);  // Giải phóng bộ nhớ

    return 0;
}
