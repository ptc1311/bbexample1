#include <nlohmann/json.hpp>
#include <sdbusplus/bus.hpp>

inline void function2() {
    std::cout << "Function 2" << std::endl;
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
    std::cout << jsonString << std::endl << std::endl;

    auto b = sdbusplus::bus::new_default_system();

    /*
    terminate called after throwing an instance of 'sdbusplus::exception::SdBusError'
  what():  sd_bus_call: org.freedesktop.DBus.Error.ServiceUnknown: The name is not activatable
Aborted (core dumped)
    auto service = "org.freedesktop.login1";
    auto obj_path = "/org/freedesktop/login1";
    auto ifs = "org.freedesktop.login1.Manager";
    
    */
    auto service = "xyz.openbmc_project.User.Manager";
    auto obj_path = "/xyz/openbmc_project/user";
    auto ifs = "org.freedesktop.DBus.ObjectManager";
    auto method = "GetManagedObjects";
    auto m = b.new_method_call(service,
                               obj_path,
                               ifs, method);


    auto reply = b.call(m);

    using return_type =
        std::vector<std::tuple<uint32_t, std::string, sdbusplus::message::object_path>>;
    auto users = reply.unpack<return_type>();

    for (auto& user : users)
    {
        std::cout << std::get<std::string>(user) << "\n";
    }
}

