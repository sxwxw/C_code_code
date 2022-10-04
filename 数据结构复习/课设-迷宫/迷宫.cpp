#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>//ʱ�亯����ԭ���ļ� 

#define N 2 //�ؿ���Ŀ 
#define M N*50 //��ͼ��С 

int level = 0; //��Ϸ�Ѷȵȼ� 
int map[M+1][M+1] = {0}; 
int count; //��ͼ��С 
int my_x,my_y; //�ҵ�λ�� 
char str[2 * (M + 1)*(M + 1)] = {'\0'}; 

void Initalize(int count); //��ʼ����ͼ
void print(); //��ӡ����
void find(); //�ҵ��Լ� 
int move(); //�����ƶ�
int Up(); //����
int Down(); //���� 
int Left(); //���� 
int Right(); // ���� 
void menu(); //�˵�
int IsHaveighbor(int X_index,int Y_index); //�жϵ�ǰ���鴦�Ƿ����ھ�
void Creat_01(int X_index,int Y_index); //��һ�ִ������� 
void Creat_02(int X_index,int Y_index);

int main(void)
{
	int flag = 0;
	int s[100][100] = {0};
	srand((unsigned)time(NULL));//strand�������
	
	system("mode con cols=220 lines=100");//��ʾ���ڴ�С
//	system("color OA");//����̨����ɫ 
	menu();
	Initalize(count);
	while(1)
	{
		flag = move();
		if(flag == 1 || flag == -1)
		{
			return 0;
		}
	}
	system("pause");
	return 0;
} 

void menu()
{
	char select[10];
	printf("�ֱ���wasd���������ƶ�����ESC�˳���Ϸ\n");
	printf("�������ͼ��С��"); 
	scanf("%d",&count);
	printf("��������Ϸ�Ѷ� (1��2):");
	while(1)
	{
		scanf("%s",select);
		if(strlen(select)>1)
		{
			printf("�������룬���������룺"); 
		}
		else if(strlen(select) == 1)
		{
			if('1' == select[0])
			{
				level = 0;
				break;
			}
			else if('2' == select[0])
			{
				level = 1;
				break;
			}else
			{
				printf("�������룬���������룺"); 
			}
		}	
	} 
}

void Initalize(int num)
{
	int i,j;
	if(num % 2 == 0)//��С��ͼ��ֻ�������� 
	{
		count++;
	}
	for(i = 0;i < count;i++)//��ʼ�������ͼ 
	{
		for(j = 0;j < count;j++)
		{
			map[i][j] = 0;
		}
	}
	for(i = 0;i< M;i++)//��ʼ�������ͼ��ĵ�ͼ 
	{
		for(j = 0;j < M;j++)
		{
			if(i >= count || j >= count)
			{
				map[i][j] = -1;//��ʼ��Ϊ-1�����ٴ�ӡʱ�� 
			}
			else if((i != 0) && (j !=0) && (i != count-1) && (j != count-1) )
			{
				if(i % 2 != 0)
				{
					if(j % 2 ==1)
					{
						map[i][j] = 1;
					}
				}
			} 
		}	
	}
	if(level == 0)
	{
		Creat_01(1,1);
	}
	else if(level == 1)
	{
		map[1][1] = 5;
		map[1][2] = 6;
		map[1][2] = 6;
		Creat_02(1,1);
	}
	for(i=0;i<count;i++)
	{
		for(j=0;j<count;j++)
		{
			if(map[i][j]==5)
			{
				map[i][j] = 1;
			}
		}
	}
	map[1][1] = 3;
	map[count-2][count-2] = 4;
}

int IsHaveighbor(int X_index,int Y_index)
{
	int i, j, flag = 0;
	if(level == 0)
	{
		if((X_index >= 3 && map[X_index - 2][Y_index] == 1) || (X_index < count - 3 && map[X_index + 2][Y_index] == 1) || (Y_index >= 3 && map[X_index][Y_index - 2] == 1) || (Y_index < count - 3 && map[X_index][Y_index + 2] == 1))
		{
			return 1;
		}
		return 0;
	}
	else if(level ==1)
	{
		for (i = 0;i < count;i++)
		{
			for (j = 0;j < count;j++)
			{
				if (map[i][j] == 6)//��������ɫ����
				{
					flag++;
				}

			}
		}
		return flag;
	}
}

void Creat_01(int X_index,int Y_index)
{
	int rand_position, x, y, flag=0;
	x = X_index;
	y = Y_index;
	
	while(1)
	{
		flag = 0;
		flag = IsHaveighbor(X_index , Y_index);
		if(flag == 0)
		{
			return;
		}
		else
		{
			map[X_index][Y_index] = 5; //5���൱��½�� 
			x = X_index;
			y = Y_index;
			while(1)
			{
				rand_position = rand() % 4;//���һ������ 
				// =0,�ϣ� =1,�£�=2����=3���� 
				if(rand_position == 0 && X_index >=3 && map[X_index-2][Y_index]==1)
				{
					X_index = X_index - 2;
				}
				else if(rand_position == 1 && X_index < count - 3 && map[X_index+2][Y_index]==1)
				{
					X_index = X_index + 2;
				}
				else if(rand_position == 2 && Y_index >=3 && map[X_index][Y_index-2]==1)
				{
					Y_index = Y_index - 2;
				}
				else if(rand_position == 3 && Y_index < count - 3 && map[X_index][Y_index+2]==1)
				{
					Y_index = Y_index + 2;
				}
				else
				{
					continue;
				} 
				//���µ�;ɵ�֮���Ϊ��ɫ 
				map[(x + X_index)/2][(y + Y_index)/2] = 5;
				map[X_index][Y_index] = 5;
				Creat_01(X_index,Y_index);
				break;
			}
		}
	}
}

void Creat_02(int X_index,int Y_index)
{
	
}

void print()
{
	int i = 0, j = 0;
	str[0] = '\0';
	system("cls");
	for (i = 0;i < M;i++)
	{
		for (j = 0;j < M;j++)
		{
			if (map[i][j] == 0)
			{
				strcat(str, "��");
			}
			//printf("��");
			else if (map[i][j] == -1)
				break;
			else if (map[i][j] == 1)
			{
				strcat(str, "  ");
			}
			//printf("  ");
			else if (map[i][j] == 3)
			{
				strcat(str, "��");
			}
			//	printf("��");
			else if (map[i][j] == 4)
			{
				strcat(str, "��");
			}
			//	printf("��");
			else if (map[i][j] == 5)
			{
				strcat(str, "��");
			}
			//	printf("��");
			else if (map[i][j] == 6)
			{
				strcat(str, "��");
			}
			//	printf("��");
		}
		if (map[i][0] != -1)
			strcat(str, "\n");
		//printf("\n");
	}
	printf("%s", str);
}

int move(void)
{
	int flag = 0;
	print();
	while (1)
	{
		flag = 0;
		find();
		switch (getch())//���հ�������
		{
			case 'w':flag = Up();
			break;
			case 'a':flag = Left();
			break;
			case 's':flag = Down();
			break;
			case 'd':flag = Right();
			break;
			case 27:return -1;
		}
		if (flag == 2)
		{
			print();
		}	
		else if (flag == 1)
		{
			//ͨ����
			if (level == N - 1)
			{
				MessageBox(0, TEXT("��ϲ������������Ѷȣ�ʥ���ڿ���"), TEXT("��ϲ"), NULL);
				return 1;
			}
			else
			{
				MessageBox(0, TEXT("��ϲ��ͨ������һ�Ѷȣ����ȷ�������Ϸ�Ѷ�"), TEXT("��ϲ"), NULL);
				level++;
				Initalize(count);
				print();
			}
		}

	}
}

void find()
{
	int i, j;
	for (i = 0;i < count;i++)
		for (j = 0;j < count;j++)
		{
			if (map[i][j] == 3)
			{
				my_x = i;
				my_y = j;
			}
		}
}

int Up()
{
	if (my_x != 0)
	{
		if (map[my_x - 1][my_y] == 1)//����
		{
			map[my_x - 1][my_y] = 3;
			map[my_x][my_y] = 1;
			return 2;//���߳ɹ�
		}
		else if (map[my_x - 1][my_y] == 4)
		{
			return 1;
		}
	}
	return 0;	
}

int Down()
{
	if (my_x != count - 1)
	{
		if (map[my_x + 1][my_y] == 1)//����
		{
			map[my_x + 1][my_y] = 3;
			map[my_x][my_y] = 1;
			return 2;//���߳ɹ�
		}
		else if (map[my_x + 1][my_y] == 4)
		{
			return 1;
		}
	}
	return 0;
}

int Left()
{
	if (my_y != 0)
	{
		if (map[my_x][my_y - 1] == 1)//����
		{
			map[my_x][my_y - 1] = 3;
			map[my_x][my_y] = 1;
			return 2;//���߳ɹ�
		}
		else if (map[my_x][my_y - 1] == 4)
		{
			return 1;
		}
	}
	return 0;
}

int Right()
{
	if (my_y != count - 1)
	{
		if (map[my_x][my_y + 1] == 1)//����
		{
			map[my_x][my_y + 1] = 3;
			map[my_x][my_y] = 1;
			return 2;//���߳ɹ�
		}
		else if (map[my_x][my_y + 1] == 4)
		{
			return 1;
		}
	}
	return 0;
}







































