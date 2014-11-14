#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define GameScreen_Height 10
#define GameScreen_Width  20
int GameScreen[GameScreen_Height][GameScreen_Width]={}; //������Ϸ��Ļ
 char key;//�����û�����
struct people
{
int x;
int y;
};
struct box
{
int x ;
int y ;
}gameBox[4];
struct goal
{
int x;
int y;
}gameGoal[4];
static people gamer;//�������
char control;//���尴��
void drawWall();//��ǽ
void refreshScreen();//����
void printfMassage();//�����Ϸ����
void drawScreen(int *x);//��ӡ��Ļ
void CheckBoxGamerStatus();//���ȫ������ ��ҵ�״̬ һ���ص��͸���ʾ
void gamerMove();//����ƶ���ʱ��ˢ��
void initGamer();//��ʼ����Ϸ���λ��
void refreshGamer();//����Ϸ��Ҽ�����Ϸ
char getDirection();//��ȡ�û���ǰ����
void gameControl(char x);//�û��ƶ��¼�
bool detectionWin();//���ʤ������
void CheckBoxGamerStatus();
void useMap(int x);
void useMap1();
void useMap2();
void initGameScreen();
//void putBoxStatus(); //���Է���  �������λ��
//void putGamerStatus();//���Է��� �������λ��
//void putGoalStatus();//���Է���  ���Ŀ�ĵ�λ��
/*
0    �յ�
1 �� ��
2 �� Ŀ�ĵ�
3 �� ����
4 �� ǽ��
5 ��  �˺�Ŀ�ĵ��ص�
6 �� ���Ӻ�Ŀ�ĵ��ص�
*/
int main()
{
	printfMassage();
	system("pause");
	refreshScreen();
	int  map = 1; //������Ϸ�ؿ� ��Ϊ3ʱ�޵�ͼ ��Ϸ����
	useMap(map); //ʹ�õ�ͼ
	drawScreen(*GameScreen);
	while((control = getch())!='r'){
	gameControl(control);
	refreshScreen();
	drawScreen(*GameScreen);
	if(detectionWin()) {  map++,useMap(map);}
	if(map > 3) break;
	//putBoxStatus();
	//putGamerStatus();
	//putGoalStatus();
	}
	printf("��ͨ���ˣ��밴������˳���Ϸ��");
	system("pause");
}
void drawWall()//����ǽ��
{   //��ǽ�� (0,0) --(0,19)
//��ǽ�� (9,0) --(9,19)
//��ǽ�� (1,0) --(8,0)
//��ǽ�� (1,19) --(8,19)
int a=0;
for(a;a<GameScreen_Width;a++)
{
GameScreen[0][a]=4;
}//�ϱ�
for(a=0;a<GameScreen_Width;a++)
{
GameScreen[GameScreen_Height-1][a]=4;
}//�±�
for(a=1;a<GameScreen_Height-1;a++)
{
GameScreen[a][0]=4;
}//���
for(a=1;a<GameScreen_Height-1;a++)
{
GameScreen[a][GameScreen_Width-1] = 4;
}//�ұ�
}
void refreshScreen()//��Ļˢ��
{
system("cls");       //ˢ����Ļ
					//�������Ļ
}
void drawScreen(int *x)
{
int a ;
CheckBoxGamerStatus();
for(a=0;a<GameScreen_Height*GameScreen_Width;a++)
{


	if(a%20==0) printf("\n");
	 switch(*x)
		{
		 case 0:printf("  ");break;
		 case 1:printf("��");break;
		 case 2:printf("��");break;
		 case 3:printf("��");break;
		 case 4:printf("��");break;
		 case 5:printf("��");break;
		 case 6:printf("��");break;
	}
  x++;
}
printf("\n");
}//��ӡ��Ļ
void initGamer()
{
gamer.x = 5;
gamer.y = 5;
GameScreen[gamer.x][gamer.y] =	1;
}//��ʼ�����λ��
void refreshGamer()
{
GameScreen[gamer.x][gamer.y] = 1;
}
char getDirection()
{
 return control;
}

void useMap(int x)//����
{
	switch(x)
	{
	case 1:useMap1();break;
	case 2:useMap2();break;
	}
}
void useMap1() //��ͼ1
{
	initGameScreen();
	drawWall();
	initGamer();
	int a = 3;
	int b =9;
for(int x = 0 ; x < 4 ; x++)
{
	gameBox[x].x = a;
	gameBox[x].y = b+=2;
	GameScreen[a][b] = 3;
}
//��������
	b = 9;
	a =5;
for(int y = 0 ; y < 4 ; y++)
{
	gameGoal[y].x = a ;
	gameGoal[y].y = b+=2;
	GameScreen[a][b]= 2;
}
//����Ŀ���


}
void useMap2() //��ͼ2
{
	initGameScreen();
	drawWall();
//	initGamer();
	 int a  = 3;
	 int b = 14;
	for(int x = 0 ; x < 4 ; x++)
	{
	gameBox[x].x = a;
	gameBox[x].y = b;
	GameScreen[a][14] = 3;
	a++;
	}//��������
	int y ;
	a = 1;
	for( y = 0 ; y < 2 ; y++)
	{
	gameGoal[y].x= a+=2;
	gameGoal[y].y=16;
	GameScreen[a][16]= 2;
	}
	a = 4;
	b = 13;
	for( y = 2 ; y < 4 ; y++)
	{
	gameGoal[y].x= a;
	gameGoal[y].y= b+=2;
	GameScreen[a][b]= 2;
	}
	//����Ŀ���
	GameScreen[3][15]=4;
	GameScreen[3][17]=4;
	GameScreen[5][17]=4;
	GameScreen[5][15]=4;
	//����ʯͷ
	initGamer();
}
bool detectionWin()
{
	int flag=0;
	for(int i = 0 ; i <4; i++)
	{
		for(int x = 0 ; x <4 ;x++ )
		{
			if(gameBox[i].x==gameGoal[x].x)
				if(gameBox[i].y==gameGoal[x].y)
				{
				flag++;
				}
		}

	}
	//����һ��
	if(flag <= 3)return false;
	else true;
	//��ȡĿ�ĵص����� ���Ƚ�Screen��ֵ�Ƿ�Ϊ�ص�ֵ
	//��������Ƿ�ȫ���źã�
}
void initGameScreen()
{
int a,b;
for(a=0;a<GameScreen_Height;a++)
{
for(b=0;b<GameScreen_Width;b++)
{
	GameScreen[a][b]=0;
}     //��ʼ����Ļ
}
drawWall();//��ǽ
}
void gamerMove()
{
refreshGamer();
//����ƶ� �ͽ���ˢ��λ��
}
void printfMassage()
{
	printf("��Ϸͨ����������ǰ���е�Ŀ�ĵض�������\n");
	printf("�� ������ҵ�ǰλ�� \n �� ����Ŀ�ĵ� \n �� ���� ���� \n �� ���� ǽ�� \n �� �����˺�Ŀ�ĵ��ص� \n����� ���Ӻ�Ŀ�ĵ��ص�\n");
}
void gameControl(char x)
{
	int i = 0;
	//��ȡ��Ұ����Ժ� �����ƶ�
	switch(x)
	{
	case 'w':
		switch(GameScreen[gamer.x-1][gamer.y]){
		case 0:	GameScreen[gamer.x][gamer.y]=0,gamer.x-=1;break;	//��  ���ƶ�
		case 2: GameScreen[gamer.x][gamer.y]=0,gamer.x-=1;break;
		case 3:	{																//���� �ҳ�����
		for(i = 0 ; i < 4 ; i++)
		{
				if(gameBox[i].x==gamer.x-1)
				{
					if(gameBox[i].y==gamer.y)  break;
				}   //�˳�ѭ������ʱ��i������ײ��box���±�
		}
		switch(GameScreen[gameBox[i].x-1][gameBox[i].y])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿգ�
		{
		case 0:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x-=1,gameBox[i].x-=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
		case 2:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x-=1,gameBox[i].x-=1;}; break; 	 //Ŀ�ĵ�
		case 4:	refreshGamer();	break;	 //ǽ
		case 6:	refreshGamer();	break;
		}} ; break;
		case 4:refreshGamer();break;	   			//��ǰ����ǽ
		case 5:gamer.x-=1;										//Ŀ�ĵ�
		case 6:{																//���� �ҳ�����
		for(i = 0 ; i < 4 ; i++)
		{
				if(gameBox[i].x==gamer.x-1)
				{
					if(gameBox[i].y==gamer.y)  break;
				}   //�˳�ѭ������ʱ��i������ײ��box���±�
		}
		switch(GameScreen[gameBox[i].x-1][gameBox[i].y])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿգ�
		{
		case 0:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x-=1,gameBox[i].x-=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
		case 2:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x-=1,gameBox[i].x-=1;}; break; 	 //Ŀ�ĵ�
		case 4:	refreshGamer();	break;	 //ǽ
		case 6:	refreshGamer();	break;
		}} ; break;                                              //ǰ��Ϊ�����ӵ�Ŀ�ĵ� �������ǰ����ײ ������
		};break;
	//Ŀ�ĵ�
		/*
		��ǰ�������
		��      ǽ   ����	Ŀ�ĵ�
		��  	��	  ��	 ��
		��ǰ���� �������
		ǽ      Ŀ�ĵ�	  ��
		����     ����     ����
		��        ��	  ��
		*/
		//�ƶ�������յؾ��ߣ� ���ʯͷ�Ͳ��ߣ���������Ӿ��ж��ĸ����ӣ�Ȼ������ͬ����ļ�ֵ
		//���� �ҳ�Ҫ��ײ�����ӣ���������ӵ���ͬ����Ϊ�ջ���ΪĿ�ĵػ���Ϊʯͷ4
		//�����ʯͷ��ֹͣ�������Ŀ�ĵأ����غ�
				//�� �ж�Ϊ�յ���ֱ���ƶ��� ��ˢ�����������Ϊ������㲻Ϊ�յļ���
	case 's':switch(GameScreen[gamer.x+1][gamer.y]){
		case 0:	GameScreen[gamer.x][gamer.y]=0,gamer.x+=1;break;	//��  ���ƶ�
		case 2: GameScreen[gamer.x][gamer.y]=0,gamer.x+=1;break;
		case 3:	{																//���� �ҳ�����
		for(i = 0 ; i < 4 ; i++)
		{
				if(gameBox[i].x==gamer.x+1)
				if(gameBox[i].y==gamer.y)  break;    //�˳�ѭ������ʱ��i������ײ��box���±�
		}
		switch(GameScreen[gameBox[i].x+1][gameBox[i].y])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿգ�
		{
		case 0:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x+=1,gameBox[i].x+=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
		case 2:{ GameScreen[gameBox[i].x+1][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x+=1,gameBox[i].x+=1;}; break; 	 //Ŀ�ĵ�
		case 4:	refreshGamer()/*,refreshBox(gameBox[i])*/;	break;	 //ǽ
		case 6:	refreshGamer();	break;
		}} ; break;
		case 4:refreshGamer();break;	   			//��ǰ����ǽ
		case 5:gamer.x+=1;	//Ŀ�ĵ�
		case 6:{																//���� �ҳ�����
		for(i = 0 ; i < 4 ; i++)
		{
				if(gameBox[i].x==gamer.x+1)
				if(gameBox[i].y==gamer.y)  break;    //�˳�ѭ������ʱ��i������ײ��box���±�
		}
		switch(GameScreen[gameBox[i].x+1][gameBox[i].y])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿգ�
		{
		case 0:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x+=1,gameBox[i].x+=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
		case 2:{ GameScreen[gameBox[i].x+1][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.x+=1,gameBox[i].x+=1;}; break; 	 //Ŀ�ĵ�
		case 4:	refreshGamer();	break;	 //ǽ
		case 6:	refreshGamer();	break;
		}} ; break;

		};break; 			//��
	case 'a':switch(GameScreen[gamer.x][gamer.y-1]){
		case 0:	GameScreen[gamer.x][gamer.y]=0,gamer.y-=1;break;	//��  ���ƶ�
		case 2: GameScreen[gamer.x][gamer.y]=0,gamer.y-=1;break;
		case 3:	{																//���� �ҳ�����
		for(i = 0; i < 4 ; i++)
		{
				if(gameBox[i].x==gamer.x)
				if(gameBox[i].y==gamer.y-1)  break;    //�˳�ѭ������ʱ��i������ײ��box���±�
		}
		switch(GameScreen[gameBox[i].x][gameBox[i].y-1])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿգ�
		{
		case 0:{ GameScreen[gamer.x][gamer.y]=0,GameScreen[gameBox[i].x][gameBox[i].y]=0,gamer.y-=1,gameBox[i].y-=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
		case 2:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.y-=1,gameBox[i].y-=1;}; break; 	 //Ŀ�ĵ�
		case 4:	refreshGamer();	break;	 //ǽ
		case 6:	refreshGamer();	break;
		}} ; break;
		case 4:refreshGamer();break;	//��ǰ����ǽ
		case 5:gamer.y-=1;				//Ŀ�ĵ�
		case 6:{						//���� �ҳ�����
		for(i = 0; i < 4 ; i++)
		{
				if(gameBox[i].x==gamer.x)
				if(gameBox[i].y==gamer.y-1)  break;    //�˳�ѭ������ʱ��i������ײ��box���±�
		}
		switch(GameScreen[gameBox[i].x][gameBox[i].y-1])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿգ�
		{
		case 0:{ GameScreen[gamer.x][gamer.y]=0,GameScreen[gameBox[i].x][gameBox[i].y]=0,gamer.y-=1,gameBox[i].y-=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
		case 2:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.y-=1,gameBox[i].y-=1;}; break; 	 //Ŀ�ĵ�
		case 4:	refreshGamer();	break;	 //ǽ
		case 6:	refreshGamer();	break;
		}} ; break;

		};break; 			//��
		case 'd':switch(GameScreen[gamer.x][gamer.y+1]){
				case 0:	GameScreen[gamer.x][gamer.y]=0,gamer.y+=1;break;	//��  ���ƶ�
				case 2: GameScreen[gamer.x][gamer.y]=0,gamer.y+=1;break;      //Ŀ�ĵ�
				case 3:	{																//���� �ҳ�����
				for(i = 0 ; i < 4 ; i++)
				{
						if(gameBox[i].x==gamer.x)
						if(gameBox[i].y==gamer.y+1)  break;    //�˳�ѭ������ʱ��i������ײ��box���±�
				}
						switch(GameScreen[gameBox[i].x][gameBox[i].y+1])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿ� ǰ���Ǻ�Ŀ�ĵ��غϵ����ӣ�
						{
							case 0:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.y+=1,gameBox[i].y+=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
						case 2:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.y+=1,gameBox[i].y+=1;}; break; 	 //Ŀ�ĵ�
						case 4:	refreshGamer();	break;	 //ǽ
						case 6:	refreshGamer();	break;
						}} ; break;
				case 4:refreshGamer();break;	   			//��ǰ����ǽ
				case 5:gamer.y+=1;break; //Ŀ�ĵ�
				case 6:{																//���� �ҳ�����
		for(i = 0 ; i < 4 ; i++)
		{
				if(gameBox[i].x==gamer.x)
				if(gameBox[i].y==gamer.y+1)  break;    //�˳�ѭ������ʱ��i������ײ��box���±�
		}
		switch(GameScreen[gameBox[i].x][gameBox[i].y+1])//�ҳ���ײ���Ӻ��ж�������� ������ ǰ����ǽ��ǰ����Ŀ�ĵ� ǰ���ǿ� ǰ���Ǻ�Ŀ�ĵ��غϵ����ӣ�
		{
		case 0:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.y+=1,gameBox[i].y+=1;}; break;  	  //дһ�����������ȫͼ���� �� ��Ŀ�ĵ��ص����������е������滻				     //�� ���ƶ� �����ƶ�
		case 2:{ GameScreen[gameBox[i].x][gameBox[i].y]=0,GameScreen[gamer.x][gamer.y]=0,gamer.y+=1,gameBox[i].y+=1;}; break; 	 //Ŀ�ĵ�
		case 4:	refreshGamer();	break;	 //ǽ
		case 6:	refreshGamer();	break;
		}} ;} break;

}
}
void CheckBoxGamerStatus()
{
	 //������ӡ���ҡ�Ŀ�ĵ����������غ����� ��Һ����Ӳ������غ�
	GameScreen[gamer.x][gamer.y] = 1;
	for(int a=0;a<4;a++)
	{
		GameScreen[gameBox[a].x][gameBox[a].y] = 3;
	}
	for(int a=0;a<4;a++)
	{
		GameScreen[gameGoal[a].x][gameGoal[a].y] = 2;
	}
	for(int i = 0 ; i < 4 ;i++)
	{
		if(gamer.x ==gameGoal[i].x)
		{
			if(gamer.y == gameGoal[i].y)
			{
				GameScreen[gamer.x][gamer.y] = 5;
				break;
				//����ѭ��
			}
		}  //��Һ�����X�غ� ���ж�Y ��YҲ�غ� ����ʾ�غϵ�״̬
		else if(GameScreen[gameGoal[i].x][gameGoal[i].y]!=5) GameScreen[gameGoal[i].x][gameGoal[i].y] = 2;              //���� ������� ��������
	}
	int i = 0 ;
	int f = 0;
	for( i = 0 ; i < 4 ; i++)
	{
		for( f = 0 ; f < 4 ; f++)
		{
			if(gameGoal[i].x ==gameBox[f].x)
			{
				if(gameGoal[i].y==gameBox[f].y)
				{
					GameScreen[gameGoal[i].x][gameGoal[i].y]= 6;
				}
			}
			else {
				if(GameScreen[gameGoal[i].x][gameGoal[i].y]!=6)GameScreen[gameGoal[i].x][gameGoal[i].y]=2;
				if(GameScreen[gameBox[f].x][gameBox[f].y]!=6)GameScreen[gameBox[f].x][gameBox[f].y]=3;
		}
	}

	}
}
void putBoxStatus()
{
	for(int x = 0 ; x < 4 ; x++)
	{
		printf("Box %d  x = %d y= %d \n",x,gameBox[x].x,gameBox[x].y);
	}//������ �������λ��
}
void putGamerStatus()
{
	printf("gamer x = %d  y =  %d  \n",gamer.x,gamer.y);
}
void putGoalStatus()
{
	for(int a = 0 ; a < 4 ;a++)
	{
		printf("Goal %d  x = %d  y=%d \n",a,gameGoal[a].x,gameGoal[a].y);
	}
}
