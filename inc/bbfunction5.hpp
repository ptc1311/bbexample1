#include <nlohmann/json.hpp>

inline void function5() {
    std::cout << "Function 5" << std::endl;
    // 創建一個複雜的 JSON 對象
    nlohmann::json complexJson= {
        {"name", "John Doe"},
        {"age", 30},
        {"is_student", false},
        {"address", {
            {"street", "123 Main St"},
            {"city", "Anytown"},
            {"zip", "12345"}
        }},
        {"scores", {95, 88, 76, 92}},
        {"grades", {
            {"math", "A"},
            {"english", "B"},
            {"history", "A"}
        }}
    };

    // 將 JSON 對象轉換為字串
    std::string jsonString = complexJson.dump(4); // 第二個參數是縮進空格的數量

    // 顯示 JSON 字串
    std::cout << jsonString << std::endl;
}

