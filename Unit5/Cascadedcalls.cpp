#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;

public:
    Time(int h, int m) : hour(h), minute(m) {}

    Time& setHour(int h) {
        hour = h;
        return *this;
    }

    Time& setMinute(int m) {
        minute = m;
        return *this;
    }

    void display() const {
        std::cout << "Time: " << hour << ":" << minute << std::endl;
    }
};

int main() {
    Time t(0, 0); // 創建一個 Time 對象

    // 使用鏈式調用一次性設置小時和分鐘
    t.setHour(18).setMinute(30);

    // 顯示設置後的時間
    t.display(); // 輸出: Time: 18:30

    return 0;
}
