

//贴图：IMAGR &img;  加载 loadimage(&img,"图片路径"，int w,int h)  用图片 putimage(int x,int t,&img）；


#include<stdio.h>
#include<graphics.h>
#include<conio.h>

#define WIDTH 640
#define HEIGHT 480
#define N 4
#define L 40   //棋子的边长
IMAGE img;
IMAGE img2;
int map[N][N];

MOUSEMSG msg;         //定义一个存储鼠标消息的变量
//定义棋盘结构体
struct Grid
{
	int up;
	int down;
	int left;
	int right;
	int map[N][N];
}grid;




//准备界面
void welcome()
{
	initgraph(WIDTH, HEIGHT,1);   //创建窗口
	//打印一些说明文字
	loadimage(&img, "1609502573915.jpg",WIDTH,HEIGHT);    //贴图
	putimage(0, 0, &img);
	settextcolor(YELLOW);
	setbkmode(1);  //去除字的黑底
	settextstyle(40, 0, "楷体");      //(int w,int h,"字体名字")
	outtextxy(270,60,"点灯游戏");    //在指定位置打印文字
	settextcolor(BLUE);
	outtextxy(400, 400, "作者：祝光");
	//五毛钱特效
	int c = 255;
	settextstyle(20, 0, "黑体");
	while (!_kbhit()) {                  //检测有没有按键
		settextcolor(RGB(80, c, 0));    //采用变量设置颜色
		c -= 3;
		if (c < 0) {
			c = 255;
		}
		Sleep(10);   //延迟
		outtextxy(230,430, "按任意键继续");
	}
	_getch();
	cleardevice();
}

void initDATE()
{
	//找窗口中心
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
	//画竖线
	for (int x = grid.left; x <= grid.right; x+=L) {
		line(x, grid.up,x, grid.down);
	}
	//画横线
	for (int y = grid.up; y <= grid.down; y+=L) {
		line(grid.left,y, grid.right, y);
	}
	//提升格调
	for (int x = 20; x > 10; x--) {
		setlinecolor(RGB(80, 255 / 10 * (x - 10), 100));
		rectangle(grid.left - x, grid.up - x, grid.right + x, grid.down + x);
	}
}

//鼠标交互
void ctrGame()
{
	if (MouseHit) {                //检测有没有鼠标消息
		msg = GetMouseMsg();     //用户实际操作存储进变量
		if (msg.uMsg == WM_LBUTTONDOWN)   //如果用户按下左键
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


