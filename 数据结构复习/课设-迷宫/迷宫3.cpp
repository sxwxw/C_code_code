#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

#define N 2
#define M N*50
#define MAX 300
#define UPDATETIME 30

//����ѭ������
typedef struct 
{
	int XList[MAX];
	int YList[MAX];
	int front,rear; 
}Que;
 
//�������飺�ϣ��ң��£��� 
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

//ö������(��ǵ���) 
enum state{
	wall,
	empty,
	self,
	end,
	testFlag
}; 

//ͼ������
char info[][3] = {
	"��",//ǽ��
	"  ",//�յ�
	"��",//���
	"��",//�յ�
	"��",//����ͼ��1
	"��",//����ͼ��2
};

//����ȫ�ֱ���
int level = 0;//��Ϸ�Ѷ� 
int map[M+1][M+1] = {0}; 
int count;//��ͼ��С 
int isHaveFind = 0; 
int my_x,my_y;

//���庯��
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

//�ж�Խ�纯�� 
int Judge(int x,int y)
{
	if(x > 0 && x < count-1 && y > 0 && y < count-1)
		return 1;
	return 0;
} 
//����̽������(���·��) 
int Resort(int x,int y)
{
	int i,r = 0;
	for(i = 0;i < 4;++i)//����̽��4������
	{
		if(isHaveFind == 1)//����Ѿ��ҵ�·�ˣ��ҾͲ��ټ��������ˣ�ֱ�ӷ���
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
			map[x + dir[i][0]][y + dir[i][1]] = 7;//���Ϊ��̽������
			print(x,y);
		}
		else if(map[x+dir[i][0]][y+dir[i][1]] == end)
		{
			return 1;
		}	
	}
	return 0;
}
//�������
void Creat1(int x,int y)
{
	int i;
	while(IsHaveNeighbor(x,y))
	{
		i = rand()%4;//���ȡi 
		if(Judge(x + 2*dir[i][0], y + 2*dir[i][1] && map[x + 2*dir[i][0]][y + 2*dir[i][1]] == empty))//�ж��ھ��Ƿ�Խ�磬�Լ��ھ��Ƿ�Ϊ��
		{
			map[x + dir[i][0]][y + dir[i][1]] = testFlag;//�м����� 
			map[x + 2*dir[i][0]][y + 2*dir[i][1]] = testFlag;//�ϵ����� 
			print(x + dir[i][0],y + dir[i][1]);
			Sleep(UPDATETIME);//�ӻ�����
			Creat1(x + 2*dir[i][0], y + 2*dir[i][1]);//�ݹ�ʵ�� 
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
				i = rand()%4;//���ȡi 
				if(Judge(x + 2*dir[i][0], y + 2*dir[i][1] && map[x + 2*dir[i][0]][y + 2*dir[i][1]] == empty))//�ж��ھ��Ƿ�Խ�磬�Լ��ھ��Ƿ�Ϊ��
				{
					map[x + dir[i][0]][y + dir[i][1]] = testFlag;//�м����� 
					map[x + 2*dir[i][0]][y + 2*dir[i][1]] = testFlag;//�ϵ����� 
					print(x + dir[i][0],y + dir[i][1]);
					Sleep(UPDATETIME);//�ӻ�����
					++top;
					xList[top]=x+2 * dir[i][0];
					yList[top]=y+2 * dir[i][1];
				}
			}
		}
	
	}
} 
//�������
void Creat2(int x, int y)
{
	int i = 0;
	Que list;//ѭ������ 
	list.front = list.rear = 0;
	list.XList[list.rear] = x;
	list.YList[list.rear] = y;
	list.rear = (list.rear + 1)%MAX;
	map[x][y] = testFlag;
	while(list.front != list.rear)
	{
		//���в�Ϊ��ʱ����������Ӷ��׻��βѡȡһ��Ԫ�س�����
		if(rand()%2 == 0)//�Ӷ��׳�һ��Ԫ��
		{   
			
			x = list.XList[list.front];
			y = list.YList[list.front];
			list.front = (list.front + 1)%MAX;
			
		}
		else
		{
			list.rear = (list.rear + MAX - 1 )%MAX ;//�Ӷ�β��Ԫ�� 
			x = list.XList[list.rear];
			y = list.YList[list.rear];
		}
		for(i = 0;i < 4;++i)
			if(Judge(x + 2 * dir[i][0],y + 2 * dir[i][1]) && map[x+2 * dir[i][0]][y+2 * dir[i][1]] == empty)
			{
				//�����������ǿ����ߵģ��������뵽������
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
//�ھӺ���
int IsHaveNeighbor(int x,int y)
{
	int i = 0,flag = 0;
	for(i = 0;i < 4;++i)
		if(Judge(x + 2 * dir[i][0],y + 2 * dir[i][1]) && map[x + 2 * dir[i][0]][y + 2 * dir[i][1]] == empty)//�����һ���ھ�Ϊ1����δ����
		{
			flag = 1;
			break;
		}
	return flag;
} 
//��ʼ����ͼ
void InitMap(int num)
{
	int i, j;
	my_x = my_y = 1;
	if(num % 2 == 0)//��֤����Χ��Χǽ���� 
	{
		count++;
	}
	for(i = 0;i < count;i++)//��ʼ��1 
	{
		for(j = 0;j < count;j++)
		{
			map[i][j] = wall;
		}
	}
	for(i = 1;i < count-1;i++)//��ʼ��2 
	{
		for(j = 1;j <count-1;j++)
		{
			if(i%2 != 0 && j%2 == 1)
			{
				map[i][j] = empty;
			}
		}
	}
	for(i = 0;i < count;i++)//��ӡ��ʼ����ͼ 
	{
		for(j = 0;j <count;j++)
		{
			print(i,j);
		}
	}
	
	//�Ѷ��ж�
	if(level == 0)
	{
		create2(my_x,my_y);//������� 
	} 
	else
	{
		create2(my_x,my_y);//������� 
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
//��꺯�� 
void pos(int x,int y)
{
	HANDLE hOutput;//������� 
	COORD pos;//COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//���ر�׼�����롢����������豸�ľ����Ҳ���ǻ�����롢���/�������Ļ�������ľ��
	SetConsoleCursorPosition(hOutput, pos);
	//�ο���https://blog.csdn.net/weixin_54880923/article/details 
}
//������
int Update(int id) 
{
	//���ж��Ǹ������Ƿ��ǿյ�  �������յ�
	if(map[my_x + dir[id][0]][my_y + dir[id][1]] == empty)//����ǿյأ����¼���
	{
		map[my_x][my_y] = empty;//�Լ�ԭ���ĵط���ɿյ�
		map[my_x + dir[id][0]][my_y + dir[id][1]] = self;//�Լ�ȥ���Ǹ��ط�����Լ�
		my_x += dir[id][0];
		my_y += dir[id][1];
		return 2;
	}
	else if(map[my_x + dir[id][0]][my_y + dir[id][1]] == end)//�յ��� 
	{
		return 1;
	}
	return 0;//�����������
}
//���к��� 
int Operat()
{
	int id = 1;//�������滹�����Լ���
	int flag = 0;//���ڽ����ƶ����״̬
	if(id == 0)//���� 
	{
		Resort(1,1);
	}	
	while (id)//������1  �ͱ�ʾ����Լ�����
	{
		flag = 0;
		switch (getch())//���հ�������
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
		if (flag == 2)//���߳ɹ��ˣ�������Ŀǰ��λ�ú���Χ�ĸ�����
			print(my_x,my_y);
		else if (flag == 1)
		{
			//ͨ����
			if (level == N - 1)
			{
				MessageBox(0, "ͨ�سɹ�","��ϲ", 0);//ģ̬�� 
				return 1;
			}
			else
			{
				MessageBox(0, "��һ��", "��ϲ", 0);
				level++;
				InitMap(count);
			}
		}

	}
	return 0;
}
//��ӡ����
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
			else if(map[x + dir[i][0]][y + dir[i][1]] == 7)//��������Թ��㷨�����Ϊ7�����ɿյش�����
			{
				printf("%s",info[1]);
			}	
		}
	}
} 
//�˵�ѡ��
void menu()
{
	printf("\n");
	printf("\n-------------------------------------------------------------------------------��ӭ������Ϸ---------------------------------------------------------------------------------------------\n");
	printf("������ʾ����ʹ�� w,d,a,s ������Ϸ\n");
	printf("�������ͼ��С(0 ~ 100):");
	scanf("%d",&count);
	printf("��������Ϸ�Ѷ�(1,2):");
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
				printf("	(�Τ�~��)	�����أ��ִ��ˣ���������Ϸ\n"); 
				printf("��������:");
				printf("\n");
			}else
			{
				printf("	o(T��To)	������,�������\n"); 
				printf("��������:");
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

//������
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























 

