

//��ͼ��IMAGR &img;  ���� loadimage(&img,"ͼƬ·��"��int w,int h)  ��ͼƬ putimage(int x,int t,&img����


#include<stdio.h>
#include<graphics.h>
#include<conio.h>

#define WIDTH 640
#define HEIGHT 480
#define N 4
#define L 40   //���ӵı߳�
IMAGE img;
IMAGE img2;
int map[N][N];

MOUSEMSG msg;         //����һ���洢�����Ϣ�ı���
//�������̽ṹ��
struct Grid
{
	int up;
	int down;
	int left;
	int right;
	int map[N][N];
}grid;




//׼������
void welcome()
{
	initgraph(WIDTH, HEIGHT,1);   //��������
	//��ӡһЩ˵������
	loadimage(&img, "1609502573915.jpg",WIDTH,HEIGHT);    //��ͼ
	putimage(0, 0, &img);
	settextcolor(YELLOW);
	setbkmode(1);  //ȥ���ֵĺڵ�
	settextstyle(40, 0, "����");      //(int w,int h,"��������")
	outtextxy(270,60,"�����Ϸ");    //��ָ��λ�ô�ӡ����
	settextcolor(BLUE);
	outtextxy(400, 400, "���ߣ�ף��");
	//��ëǮ��Ч
	int c = 255;
	settextstyle(20, 0, "����");
	while (!_kbhit()) {                  //�����û�а���
		settextcolor(RGB(80, c, 0));    //���ñ���������ɫ
		c -= 3;
		if (c < 0) {
			c = 255;
		}
		Sleep(10);   //�ӳ�
		outtextxy(230,430, "�����������");
	}
	_getch();
	cleardevice();
}

void initDATE()
{
	//�Ҵ�������
	int mx, my;
	mx = WIDTH / 2;
	my = HEIGHT / 2;

	grid.up = my - N / 2 * L;
	grid.down = my + N / 2 * L;
	grid.left = mx - N / 2 * L;
	grid.right = mx + N / 2 * L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid.map[i][j] = 1;
		}
	}
}

void show()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", grid.map[i][j]);
		}
		printf("\n");
	}
}

void drawmap()
{
	loadimage(&img2, "1609502573923.jpg", WIDTH, HEIGHT);
	putimage(0, 0, &img2);
	//������
	for (int x = grid.left; x <= grid.right; x+=L) {
		line(x, grid.up,x, grid.down);
	}
	//������
	for (int y = grid.up; y <= grid.down; y+=L) {
		line(grid.left,y, grid.right, y);
	}
	//�������
	for (int x = 20; x > 10; x--) {
		setlinecolor(RGB(80, 255 / 10 * (x - 10), 100));
		rectangle(grid.left - x, grid.up - x, grid.right + x, grid.down + x);
	}
}

//��꽻��
void ctrGame()
{
	if (MouseHit) {                //�����û�������Ϣ
		msg = GetMouseMsg();     //�û�ʵ�ʲ����洢������
		if (msg.uMsg == WM_LBUTTONDOWN)   //����û��������
		{
			if()
		}
	
	}
}
int main()
{
	welcome();
	initDATE();
	drawmap();
	while (1) {

	}
	closegraph();
	return 0;
}


