#include <nlohmann/json.hpp>

inline void function1() {
    std::cout << "Function 1" << std::endl;
    nlohmann::json jsonExample = {
        {"name", "John"},
        {"age", 30},
        {"city", "New York"}
    };
  
    std::cout << jsonExample.dump(2) << std::endl;
}

