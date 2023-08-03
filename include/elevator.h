#ifndef elevator_h
#define elevator_h
#include "lcd.h"
#define lowest 1   // 最低1楼

extern Bmp_Event event; // 屏幕对象,外部声明

class Elevator
{
public:
    Elevator(); // 初始化状态
    ~Elevator();

    int update(const int &n); // 更新记录楼层
    void update_next();       // 更新目标
    void press(const int &n); // 按下楼层
    int move();               // 电梯移动
    void running();           // 流程控制
    void remove_dest(vector<int> &v, int &n);

private:
    int storey;       // 当前楼层
    bool is_up;       // 是否上升
    vector<int> dest; // 记录按下的楼层
    int graph[10][2]; // 对应楼层图像坐标
    int next;         // 即将前往楼层
};

#endif