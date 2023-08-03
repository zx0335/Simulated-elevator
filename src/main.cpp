#include "elevator.h"

Bmp_Event event;   // 屏幕对象
Elevator elevator; // 电梯对象

void *advertise(void *) // 广告
{
    long i = 1;
    while (i++)
    {
        if (i % 2 == 0)
        {
            event.show_bmp(0, 0, "./pic/ad1.bmp");
            sleep(2);
        }
        else
        {
            event.show_bmp(0, 0, "./pic/ad2.bmp");
            sleep(2);
        }
    }
    return nullptr;
}

void *control(void *)//电梯运行状态控制
{
    elevator.running();
    return nullptr;
}
 
int main(int argc, char **argv)
{
    event.show_bmp(0, 0, "./pic/main.bmp"); // 显示加载页面
    sleep(2);
    event.show_bmp(0, 0, "./pic/face.bmp"); // 显示主界面
    event.show_bmp(230, 0, "./pic/1.bmp");
    system("madplay ./mp3/main.mp3");
    pthread_t tid1, tid2;
    pthread_create(&tid1, nullptr, advertise, nullptr);
    pthread_create(&tid2, nullptr, control, nullptr);

    int x, y;
    while (true)
    {
        event.get_xy(x, y);// 获取按下坐标
        if (x >= 600 && x < 700 && y >= 384 && y < 480) // 1
        {
            elevator.press(1);
        }
        else if (x >= 700 && x < 800 && y >= 384 && y < 480) // 2
        {
            elevator.press(2);
        }
        else if (x >= 600 && x < 700 && y >= 288 && y < 384) // 3
        {
            elevator.press(3);
        }
        else if (x >= 700 && x < 800 && y >= 288 && y < 384) // 4
        {
            elevator.press(4);
        }
        else if (x >= 600 && x < 700 && y >= 192 && y < 288) // 5
        {
            elevator.press(5);
        }
        else if (x >= 700 && x < 800 && y >= 192 && y < 288) // 6
        {
            elevator.press(6);
        }
        else if (x >= 600 && x < 700 && y >= 96 && y < 192) // 7
        {
            elevator.press(7);
        }
        else if (x >= 700 && x < 800 && y >= 96 && y < 192) // 8
        {
            elevator.press(8);
        }
        else if (x >= 600 && x < 700 && y > 0 && y < 96) // 9
        {
            elevator.press(9);
        }
        else if (x >= 700 && x < 800 && y > 0 && y < 96) // 10
        {
            elevator.press(10);
        }
    }
}