#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

#define N 2
#define M N*50
#define MAX 300
#define UPDATETIME 30

//创建循环队列
typedef struct 
{
	int XList[MAX];
	int YList[MAX];
	int front,rear; 
}Que;
 
//方向数组：上，右，下，左 
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

//枚举类型(标记地域) 
enum state{
	wall,
	empty,
	self,
	end,
	testFlag
}; 

//图形数组
char info[][3] = {
	"■",//墙壁
	"  ",//空地
	"⊙",//玩家
	"☆",//终点
	"◇",//测试图案1
	"○",//测试图案2
};

//定义全局变量
int level = 0;//游戏难度 
int map[M+1][M+1] = {0}; 
int count;//地图大小 
int isHaveFind = 0; 
int my_x,my_y;

//定义函数
void InitMap(int num);
void Creat1(int x,int y);
void Creat2(int my_x,int my_y);
int Judge(int x,int y);
void print(int x,int y);
int Operat();
int Update(int id);
void menu();
void pos(int x, int y);
int Resort(int x,int y);
int IsHaveNeighbor(int x,int y);
void create2(int x,int y);

//判断越界函数 
int Judge(int x,int y)
{
	if(x > 0 && x < count-1 && y > 0 && y < count-1)
		return 1;
	return 0;
} 
//电脑探索函数(最短路径) 
int Resort(int x,int y)
{
	int i,r = 0;
	for(i = 0;i < 4;++i)//依次探索4个方向
	{
		if(isHaveFind == 1)//如果已经找到路了，我就不再继续回溯了，直接返回
		{
			return 1;
		}
		if(!Judge(x + dir[i][0],y + dir[i][1]) || map[x+dir[i][0]][y+ dir[i][1]] == 7)
		{
			continue;
		}
		if(map[x+dir[i][0]][y+ dir[i][1]] == empty)
		{
			map[x + dir[i][0]][y + dir[i][1]] = testFlag;
			print(x,y);
			Sleep(UPDATETIME);
			if(isHaveFind = Resort(x+dir[i][0],y+dir[i][1]))
			{
				return 1;
			}	
			map[x + dir[i][0]][y + dir[i][1]] = 7;//标记为已探索区域
			print(x,y);
		}
		else if(map[x+dir[i][0]][y+dir[i][1]] == end)
		{
			return 1;
		}	
	}
	return 0;
}
//深度搜索
void Creat1(int x,int y)
{
	int i;
	while(IsHaveNeighbor(x,y))
	{
		i = rand()%4;//随机取i 
		if(Judge(x + 2*dir[i][0], y + 2*dir[i][1] && map[x + 2*dir[i][0]][y + 2*dir[i][1]] == empty))//判断邻居是否越界，以及邻居是否为空
		{
			map[x + dir[i][0]][y + dir[i][1]] = testFlag;//中间区域 
			map[x + 2*dir[i][0]][y + 2*dir[i][1]] = testFlag;//断点区域 
			print(x + dir[i][0],y + dir[i][1]);
			Sleep(UPDATETIME);//延缓函数
			Creat1(x + 2*dir[i][0], y + 2*dir[i][1]);//递归实现 
		} 
	}
}
void create2(int x,int y){
	int i;
	int xList[MAX]={0};
	int yList[MAX]={0};
	int top = -1;
	++top;
	xList[top]=x;
	yList[top]=y;
	while(top!=-1){
		x = xList[top];
		y = yList[top];
		--top;
		while(IsHaveNeighbor(x,y)){
			for(i=0;i<4;++i){
				i = rand()%4;//随机取i 
				if(Judge(x + 2*dir[i][0], y + 2*dir[i][1] && map[x + 2*dir[i][0]][y + 2*dir[i][1]] == empty))//判断邻居是否越界，以及邻居是否为空
				{
					map[x + dir[i][0]][y + dir[i][1]] = testFlag;//中间区域 
					map[x + 2*dir[i][0]][y + 2*dir[i][1]] = testFlag;//断点区域 
					print(x + dir[i][0],y + dir[i][1]);
					Sleep(UPDATETIME);//延缓函数
					++top;
					xList[top]=x+2 * dir[i][0];
					yList[top]=y+2 * dir[i][1];
				}
			}
		}
	
	}
} 
//广度搜索
void Creat2(int x, int y)
{
	int i = 0;
	Que list;//循环队列 
	list.front = list.rear = 0;
	list.XList[list.rear] = x;
	list.YList[list.rear] = y;
	list.rear = (list.rear + 1)%MAX;
	map[x][y] = testFlag;
	while(list.front != list.rear)
	{
		//队列不为空时，我们随机从队首或队尾选取一个元素出来。
		if(rand()%2 == 0)//从队首出一个元素
		{   
			
			x = list.XList[list.front];
			y = list.YList[list.front];
			list.front = (list.front + 1)%MAX;
			
		}
		else
		{
			list.rear = (list.rear + MAX - 1 )%MAX ;//从队尾出元素 
			x = list.XList[list.rear];
			y = list.YList[list.rear];
		}
		for(i = 0;i < 4;++i)
			if(Judge(x + 2 * dir[i][0],y + 2 * dir[i][1]) && map[x+2 * dir[i][0]][y+2 * dir[i][1]] == empty)
			{
				//如果这个方向是可以走的，把它加入到队列中
				map[x + dir[i][0]][y + dir[i][1]] = testFlag;
				map[x + 2 * dir[i][0]][y + 2 * dir[i][1]] = testFlag;
				print(x + dir[i][0],y + dir[i][1]);
				Sleep(UPDATETIME);
				if(rand()%2 == 0)
				{
					list.XList[list.rear] = x + 2 * dir[i][0];
					list.YList[list.rear] = y + 2 * dir[i][1];
					list.rear = (list.rear + 1)%MAX;
				}
				else
				{
					list.front = (list.front + MAX -1 )%MAX;
					list.XList[list.front] = x + 2 * dir[i][0];
					list.YList[list.front] = y + 2 * dir[i][1];
				}
			}
	}
} 
//邻居函数
int IsHaveNeighbor(int x,int y)
{
	int i = 0,flag = 0;
	for(i = 0;i < 4;++i)
		if(Judge(x + 2 * dir[i][0],y + 2 * dir[i][1]) && map[x + 2 * dir[i][0]][y + 2 * dir[i][1]] == empty)//如果有一个邻居为1，即未访问
		{
			flag = 1;
			break;
		}
	return flag;
} 
//初始化地图
void InitMap(int num)
{
	int i, j;
	my_x = my_y = 1;
	if(num % 2 == 0)//保证最外围的围墙存在 
	{
		count++;
	}
	for(i = 0;i < count;i++)//初始化1 
	{
		for(j = 0;j < count;j++)
		{
			map[i][j] = wall;
		}
	}
	for(i = 1;i < count-1;i++)//初始化2 
	{
		for(j = 1;j <count-1;j++)
		{
			if(i%2 != 0 && j%2 == 1)
			{
				map[i][j] = empty;
			}
		}
	}
	for(i = 0;i < count;i++)//打印初始化地图 
	{
		for(j = 0;j <count;j++)
		{
			print(i,j);
		}
	}
	
	//难度判定
	if(level == 0)
	{
		create2(my_x,my_y);//深度搜索 
	} 
	else
	{
		create2(my_x,my_y);//广度搜索 
	} 
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			if(map[i][j] == testFlag)
			{
				map[i][j] = empty;
			}
		}
	 } 
	 map[my_x][my_y] = self;
	 map[count-2][count-2] = end;
	 for(i = 0;i < count;i++)
	 {
	 	for(j = 0;j < count;j++)
	 	{
	 		print(i,j);
		 }
	 }
} 
//光标函数 
void pos(int x,int y)
{
	HANDLE hOutput;//声明句柄 
	COORD pos;//COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//返回标准的输入、输出或错误的设备的句柄，也就是获得输入、输出/错误的屏幕缓冲区的句柄
	SetConsoleCursorPosition(hOutput, pos);
	//参考：https://blog.csdn.net/weixin_54880923/article/details 
}
//方向函数
int Update(int id) 
{
	//先判断那个方向是否是空地  或者是终点
	if(map[my_x + dir[id][0]][my_y + dir[id][1]] == empty)//如果是空地，更新即可
	{
		map[my_x][my_y] = empty;//自己原来的地方变成空地
		map[my_x + dir[id][0]][my_y + dir[id][1]] = self;//自己去的那个地方变成自己
		my_x += dir[id][0];
		my_y += dir[id][1];
		return 2;
	}
	else if(map[my_x + dir[id][0]][my_y + dir[id][1]] == end)//终点了 
	{
		return 1;
	}
	return 0;//这个方向不能走
}
//运行函数 
int Operat()
{
	int id = 1;//电脑来玩还是我自己玩
	int flag = 0;//用于接收移动后的状态
	if(id == 0)//电脑 
	{
		Resort(1,1);
	}	
	while (id)//这里是1  就表示玩家自己来玩
	{
		flag = 0;
		switch (getch())//接收按键输入
		{
			case 'd':flag = Update(0);
			break;
			case 's':flag = Update(1);
			break;
			case 'a':flag = Update(2);
			break;
			case 'w':flag = Update(3);
			break;
			case 27:return -1;
		}
		if (flag == 2)//行走成功了，更新我目前的位置和周围四个方块
			print(my_x,my_y);
		else if (flag == 1)
		{
			//通过了
			if (level == N - 1)
			{
				MessageBox(0, "通关成功","恭喜", 0);//模态框 
				return 1;
			}
			else
			{
				MessageBox(0, "下一关", "恭喜", 0);
				level++;
				InitMap(count);
			}
		}

	}
	return 0;
}
//打印函数
void print(int x,int y)
{
	int i = 0;
	pos(y*2,x);
	printf("%s",info[map[x][y]]);
	for(i = 0;i <4;i++)
	{
		if(Judge(x+ dir[i][0],y+dir[i][1]))
		{
			pos(2*(y+dir[i][1]),x+ dir[i][0]);
			if(map[x+dir[i][0]][y+dir[i][1]]<6)
			{
				printf("%s",info[map[x + dir[i][0]][y + dir[i][1]]]);
			}
			else if(map[x + dir[i][0]][y + dir[i][1]] == 7)//用于求解迷宫算法，如果为7，当成空地处理即可
			{
				printf("%s",info[1]);
			}	
		}
	}
} 
//菜单选项
void menu()
{
	printf("\n");
	printf("\n-------------------------------------------------------------------------------欢迎进入游戏---------------------------------------------------------------------------------------------\n");
	printf("友情提示，请使用 w,d,a,s 控制游戏\n");
	printf("请输入地图大小(0 ~ 100):");
	scanf("%d",&count);
	printf("请输入游戏难度(1,2):");
	char select[10];
	int cs = 0;
	while(1)
	{
		scanf("%s",select);
		if(strlen(select)>1)
		{
			cs++;
			if(cs>3)
			{
				printf("	(ノへ~、)	呜呜呜，又错了，我想玩游戏\n"); 
				printf("重新输入:");
				printf("\n");
			}else
			{
				printf("	o(TヘTo)	呜呜呜,输入错误\n"); 
				printf("重新输入:");
				printf("\n");	
			}
			
		}
		else
		{
			if('1' == select[0])
			{
				level = 0;
				break;
			}
			if('2' == select[0])
			{
				level = 1;
				break;
			}
		}
		
	}
} 

//主函数
int main()
{
	int i;
	double start,finish;
	start=(double) clock(); 
	int flag = 0;
	srand((unsigned)time(NULL));
	system("mode con cols=100 lines=100");
	system("color 09");
	menu();
	InitMap(count);
	finish=(double)clock();
	 printf("%.4f ms",finish-start);
	return 0;
} 























 

