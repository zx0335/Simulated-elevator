#include "lcd.h"

// 显示bmp图片
void Bmp_Event::show_bmp(int offset_x, int offset_y, const char *bmp_name)
{
    // 打开bmp图片
    int bmp_fd = open(bmp_name, O_RDWR);
    if (bmp_fd < 0)
    {
        perror("open bmp failed");
        exit(errno);
    }

    // 读取头信息,读完光标偏移56字节
    bmp_head info;
    read(bmp_fd, &info, sizeof(info));

    // 读取图片数据
    unsigned char bmp_buf[info.width * info.height * 3];
    read(bmp_fd, bmp_buf, sizeof(bmp_buf));

    int x, y;
    unsigned char r, g, b;
    int color;
    int i = 0;
    for (y = 0; y < info.height; y++)
    {
        for (x = 0; x < info.width; x++)
        {
            b = bmp_buf[i++];
            g = bmp_buf[i++];
            r = bmp_buf[i++];
            color = b | g << 8 | r << 16; // 每个像素点的颜色
            *(p + 800 * (info.height - 1 - y + offset_y) + (x + offset_x)) = color;
        }
    }
}

// 获取按下的坐标
int Bmp_Event::get_xy(int &x, int &y)
{
    struct input_event buf;
    int x1, y1;       // 保存第一次的坐标
    int x2, y2;       // 保存最后一次的坐标
    int tmp_x, tmp_y; // 保存临时坐标
    x1 = y1 = x2 = y2 = -1;
    while (1)
    {
        read(ts_fd, &buf, sizeof(buf)); // 读取触摸屏数据
        if (buf.type == EV_ABS)         // 触摸屏事件
        {
            if (buf.code == ABS_X) // X轴
            {
                tmp_x = buf.value;
            }
            else if (buf.code == ABS_Y) // Y轴
            {
                tmp_y = buf.value;
            }
        }
        // 判断手指松开
        if (buf.type == EV_KEY && buf.code == BTN_TOUCH)
        {
            if (buf.value == 1) // 按下
            {
                x1 = tmp_x;
                y1 = tmp_y;
            }
            else if (buf.value == 0) // 松开,保存最后一次坐标
            {
                x2 = tmp_x;
                y2 = tmp_y;
                break;
            }
        }
    }
    int var_x = abs(x2 - x1); // x轴变化量
    int var_y = abs(y2 - y1); // y轴变化量
    // 判断是滑动还是点击
    if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) >= 60 * 60) // 滑动
    {
        if (y1 > y2 && var_y > var_x) // 上划
        {
            return UP;
        }
        else if (y1 < y2 && var_y > var_x) // 下划
        {
            return DOWN;
        }
        else if (x1 > x2 && var_x > var_y) // 左
        {
            return LEFT;
        }
        else if (x1 < x2 && var_x > var_y) // 右
        {
            return RIGHT;
        }
    }
    else // 点击
    {
        x = x2 * 800 / 1024; //*800/1024
        y = y2 * 480 / 600;  //*480/600
    }
    return 0;
}

Bmp_Event::Bmp_Event()
{
    // 打开显示屏
    this->lcd_fd = open("/dev/fb0", O_RDWR);
    if (this->lcd_fd < 0) // 打开失败
    {
        perror("open lcd failed");
        exit(errno);
    }
    cout << "显示屏打开成功!" << endl;

    //  打开触摸屏
    ts_fd = open("/dev/input/event0", O_RDWR);
    if (ts_fd < 0)
    {
        perror("open ts failed");
        exit(errno);
    }
    cout << "触摸屏打开成功!" << endl;

    // 进行内存映射
    this->p = (int *)mmap(nullptr, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (p == nullptr)
    {
        perror("mmap() failed");
        exit(errno);
    }
    cout << "内存映射成功!" << endl;
}

Bmp_Event::~Bmp_Event()
{
    // 解除映射
    munmap(p, 800 * 480 * 4);
    p = nullptr;
    cout << "解除内存映射!" << endl;
    // 关闭触摸屏
    close(ts_fd);
    cout << "触摸屏已关闭!" << endl;
    // 关闭lcd
    close(lcd_fd);
    cout << "显示屏已关闭!" << endl;
}