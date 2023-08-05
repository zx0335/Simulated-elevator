#ifndef lcd_h
#define lcd_h

extern "C"
{
#include <pthread.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <linux/input.h> //输入事件头文件
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <csignal>
using namespace std;
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

/*bmp图片的文件头信息定义*/
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#pragma pack(1) // 取消字节对齐
typedef struct
{ // bmp图片文件头信息封装
	// 位图文件头
	u8 bit_file_type[2]; 	// 位图文件类型:'BM'->0x4d42
	u32 file_size;		// 整个文件大小
	u16 reserved1;		// 保留
	u16 reserved2;		// 保留
	u32 offset;		// 文件头到位图数据之间的偏移量

	// 位图信息头
	u32 head_size;		// 位图信息头长度
	u32 width;		// 位图宽度
	u32 height;		// 位图高度
	u16 bit_planes;		// 位图位面数
	u16 bits_per_pixel; 	// 每个像素的位数
	u32 compression;	// 压缩说明
	u32 image_size;		// 位图数据大小
	u32 h_res;		// 水平分辨率
	u32 v_res;		// 垂直分辨率
	u32 color_palette;	// 位图使用的颜色索引数
	u32 vip_color;		// 重要的颜色索引数目
} bmp_head;
#pragma pack() // 恢复字节对齐

class Bmp_Event
{
public:
	Bmp_Event(const Bmp_Event &other) = delete;
	Bmp_Event &operator=(const Bmp_Event &other) = delete;
	~Bmp_Event();
	
	void show_bmp(int offset_x, int offset_y, const char *bmp_name);// 显示bmp图片
	int get_xy(int &x, int &y);					// 获取按下的坐标
	static Bmp_Event &getInstance();				// 创建单例对象
private:
	int *p;
	int lcd_fd; // 显示屏文件描述符
	int ts_fd;	// 触摸屏文件描述符

	Bmp_Event();
	static Bmp_Event event;
};

#endif
