#include "elevator.h"

Elevator::Elevator()
{
    this->storey = lowest;
    this->is_up = true;
    this->dest = {};

    int temp_graph[10][2] = {
        {600, 384},
        {700, 384},
        {600, 288},
        {700, 288},
        {600, 192},
        {700, 192},
        {600, 96},
        {700, 96},
        {600, 0},
        {700, 0}};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            this->graph[i][j] = temp_graph[i][j];
        }
    }

    this->next = this->storey;
}

Elevator::~Elevator() {}

int Elevator::update(const int &n,Bmp_Event& event) // 更新按下的楼层
{
    char bmp[30]{};
    for (auto it = dest.begin(); it != dest.end();)
    {
        if (n == *it && n != next) // 按下楼层重复且不是正在前往的楼层
        {
            it = dest.erase(it); // 重复按下,删除记录
            cout << "已取消前往" << n << "楼" << endl;

            sprintf(bmp, "./pic/0%d.bmp", n);
            event.show_bmp(graph[n - 1][0], graph[n - 1][1], bmp); // 按键复原
            sort(dest.begin(), dest.end());
            return 1;
        }
        else
        {
            ++it;
        }
    }
    if (n == next)
        return -1;
    dest.push_back(n); // 插入新的目标楼层

    cout << "前往" << n << "楼" << endl;
    sprintf(bmp, "./pic/00%d.bmp", n);
    event.show_bmp(graph[n - 1][0], graph[n - 1][1], bmp); // 按键高亮
    sort(dest.begin(), dest.end());                        // 排序
    return 1;
}

int Elevator::move(Bmp_Event& event) // 电梯移动
{
    char bmp[30]{};
    if (next > storey) // 上升
    {
        ++this->storey;
        event.show_bmp(430, 40, "./pic/up.bmp");
        sleep(2);

        sprintf(bmp, "./pic/%d.bmp", this->storey);
        event.show_bmp(230, 0, bmp);
        return this->storey; // 返回当前楼层
    }
    else if (next < storey) // 下降
    {
        --this->storey;
        event.show_bmp(430, 40, "./pic/down.bmp");
        sleep(2);

        sprintf(bmp, "./pic/%d.bmp", this->storey);
        event.show_bmp(230, 0, bmp);
        return this->storey;
    }
    usleep(100000);
    return -1;
}

void Elevator::update_next() // 更新目标
{
    if (!dest.empty() && dest.back() < storey) // 容器非空,且均低于当前楼层
    {
        is_up = false; // 开始下降
        next = dest.front();
    }
    else if (!dest.empty() && dest.front() > storey) // 容器非空,且均高于当前楼层
    {
        is_up = true; // 开始上升
        next = dest.back();
    }
    else if (is_up && !dest.empty()) // 上升
    {
        if (dest.back() > this->storey)
            next = dest.back();
        else if (dest.back() < this->storey)
            next = dest.back();
    }
    else if (!is_up && !dest.empty()) // 下降
    {
        if (dest.front() < this->storey)
            next = dest.front();
        else if (dest.front() > this->storey)
            next = dest.front();
    }
    cout << "next = " << next << endl;
    for (vector<int>::iterator it = dest.begin(); it != dest.end(); ++it)
    {
        if (is_up && next > *it && this->storey < *it) // 上升阶段
        {
            next = *it;
            break;
        }
        else if (!is_up && next<*it &&this->storey> * it) // 下降阶段
        {
            next = *it;
            break;
        }
    }
}

void Elevator::press(const int &n,Bmp_Event& event) // 按下目标楼层
{
    if (n == this->storey)
    {
        cout << "您已在第" << n << "楼" << endl;
        return;
    }
    update(n,event);
    update_next(); // 更新状态
}

void Elevator::running(Bmp_Event& event)
{
    while (true)
    {
        update_next();
        if (next == move(event))
        {
            update_next();
            remove_dest(dest, this->storey); // 到达目的地,从容器中删除

            event.show_bmp(430, 40, "./pic/again.bmp");
            cout << storey << "楼到了!" << endl;

            char bmp[30]{};
            sprintf(bmp, "./pic/0%d.bmp", this->storey);
            event.show_bmp(graph[storey - 1][0], graph[storey - 1][1], bmp); // 按键复原
            char mp3[30]{};
            sprintf(mp3, "madplay ./mp3/0%d.mp3", this->storey);
            system(mp3);

            sleep(2);
            continue;
        }
        update_next();
    }
}

void Elevator::remove_dest(vector<int> &v, int &n)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        if (*it == n)
        {
            v.erase(it);
            break;
        }
    }
}