#include <nlohmann/json.hpp>


bool mycompare(int a, int b) {
    return a > b; // 降序排列
}

struct myclass {
    bool operator() (int a, int b) { return a > b; }  // 降序排列
} myobject;

inline void function1() {
    //nlohman json: 
    std::cout << "========json dump========" << std::endl;
    nlohmann::json jsonExample = {
        {"name", "John"},
        {"age", 30},
        {"city", "New York"}
    };
  
    std::cout << jsonExample.dump(2) << std::endl << std::endl;

    std::cout << "========sort========" << std::endl;
    //sort
    int arr[] = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};
    //std::sort(arr, arr+10);
    
    //below is better for human read
    //std::sort(std::begin(arr), std::end(arr));

    //decreasing
    std::sort(std::begin(arr), std::end(arr), std::greater<int>());

    std::cout << "sort array by default (increasing):" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "========sort vecotr by function (decreasing)========" << std::endl;
    int arr2[] = {5, 4, 1, 7, 3, 8, 9, 10, 6, 2};
    std::vector<int> v(arr2, arr2+10);
    std::sort(v.begin(), v.end(), mycompare);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "========sort vecotr by lambda function (increasing):========" << std::endl;
    std::vector<int> vlambda = {5, 4, 1, 7, 3, 8, 9, 10, 6, 2};
    std::sort(vlambda.begin(), vlambda.end(), [](int a, int b){
        return a < b; // 升序排列
    });
    for (int i : vlambda) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "========sort vecotr by object (decreasing):========" << std::endl;
    std::vector<int> vobj = {5, 4, 1, 7, 3, 8, 9, 10, 6, 2};
    std::sort(vobj.begin(), vobj.end(), myobject);
    for (int i : vobj) {
        std::cout << i << " ";
    }
    std::cout << std::endl << std::endl;

    std::string s11 = "eacdb";
    std::sort(s11.begin(), s11.end(), std::less<char>());
    std::cout << "========sort string (increasing):========" << std::endl;
    for (char c : s11) {
        std::cout << c << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "========range-based for loop (string):========" << std::endl;
    std::string str = "hello world";
    for (auto &c : str) {
        std::cout << c << '\n';
    }
    std::cout << std::endl << std::endl;

    std::string s1;
    std::cout << "size=" << s1.size() << ", capacity=" << s1.capacity() << "\n";
    s1 += "abcdefghij";
    std::cout << "size=" << s1.size() << ", capacity=" << s1.capacity() << "\n";
    s1 += "abcdefghij";
    std::cout << "size=" << s1.size() << ", capacity=" << s1.capacity() << "\n";
    s1 += "abcdefghij";
    std::cout << "size=" << s1.size() << ", capacity=" << s1.capacity() << "\n";
    s1 += "abcdefghij";
    std::cout << "size=" << s1.size() << ", capacity=" << s1.capacity() << "\n";
    s1 += "abcdefghij";
    std::cout << "size=" << s1.size() << ", capacity=" << s1.capacity() << "\n";
    s1 += "abcdefghij";
    s1 += "abcdefghij";
    s1 += "abcdefghij";
    s1 += "abcdefghij";
    s1 += "abcdefghij";
    std::cout << "size=" << s1.size() << ", capacity=" << s1.capacity() << "\n";

    std::cout << std::endl << std::endl;

}

