#include <iostream>
using namespace std;

class Counter {
private:
    int count;
public:
    Counter(int initialCount = 0) : count(initialCount) {}

    // 前綴遞增運算符
    Counter& operator++() {
        ++count;
        return *this;
    }

    // 後綴遞增運算符
    Counter operator++(int) {
        Counter temp(*this);  // 創建一個副本用於後綴運算
        ++count;
        return temp;  // 返回之前的值
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter c(5);

    // 前綴遞增：首先遞增，然後返回遞增後的值
    std::cout << "前綴遞增：" << ++c.getCount() << std::endl;  // 輸出 6
    std::cout << "當前計數：" << c.getCount() << std::endl;  // 輸出 6

    // 後綴遞增：首先返回當前值，然後遞增
    std::cout << "後綴遞增：" << c.getCount()++ << std::endl;  // 輸出 6，但計數器的值已經遞增
    std::cout << "當前計數：" << c.getCount() << std::endl;  // 輸出 7

    return 0;
}

