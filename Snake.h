#pragma once
#include<windows.h>
#include<vector>
#include<string>

using namespace std;

//标记界面和菜单项的ID
enum ID_ { ID_1 = 1, ID_2, ID_3, ID_4, ID_5, ID_6, ID_7 };

//标记初级，中级，高级三种游戏等级150  100  50
enum Rank_ { first = 150, middle = 100, high = 50 };


//贪吃蛇结构   http://www.cnblogs.com/sosoft/
struct Snake_data
{
	bool state;                    //标记蛇状态
	size_t Snake_size;             //蛇的长度
	vector<COORD> Snake_coord; //蛇的当前坐标
	COORD food_coord;   //CORRD是windows API定义的一种结构，表示字符在控制台屏幕上的坐标（食物坐标）
	size_t rank;                     //标记等级
	size_t mark;                      //分数
	size_t key;                       //记录按键方向
	ID_ ID_interface;               //标记当前停留界面ID
	short ID_option;               //标记被选中菜单的ID
	bool Flag;                      //标记刷新
};

//贪吃蛇类
class Snake_class{
public:
	Snake_class(){}
	Snake_class(Snake_data *data) : pSnake(data){}
	void ShowMenu();            //显示菜单
	void StartGame();           //开始游戏
	void ShowPause();           //显示暂停界面
	void SaveRecord();          //保存记录
	void ShowRank();            //显示等级
	void ShowRecord();          //显示存档记录列表
	bool Read(size_t);          //读取记录
	void ShowArmory();          //显示英雄榜
	void Die();                 //死亡界面
	size_t Create_file();       //存储文件
private:
	void JudgeDie();            //判断死亡
	bool Jesus();               //上榜判断
	void ShowSnake(COORD&);   //显示蛇
	void JudgeChoice(COORD& cd, short incre);
	void ShowPointer(COORD, std::string); //显示指针
	void Show_not();            //显示无数据
private:
	Snake_data *pSnake;
};
