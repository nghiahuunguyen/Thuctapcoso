#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#define MAX 100
#define INPUT "points.inp"
#include <stdbool.h>
#define ROUND(a) ((int)(a+0.5))
#include<Math.h>

// Khai bao protype
void CUI_init();
void mouse();
void keyboard();
int is_run=0;
void drawPolygon();
void drawCircle();
void drawEllipse();

// khai bao bien cuc bo
int sodinh;//sodinh(so phan tu can sap xep)
FILE *fp; //file
int enable_mouse=1;

struct toado{
	int x;
	int y;
};
struct toado td[MAX]; //moi td la 1 kieu toado(x,y,value)



void printpoints(struct toado m[MAX], int size){
	for(int i=0;i<size;i++){
		printf("%d %d\n",m[i].x,m[i].y);
	}
}

//ve 
void CUI_init(){
	setcolor(WHITE);
	setlinestyle(0,1,3);//setlinestyle(int linestyle, unsigned pattern, int thickness)
	rectangle(10,5,550,310);
	//load file button
	rectangle(580,10,680,50);
	settextstyle(2,0,7);
	outtextxy(590,20,"Load file\n");
	//Keyboard button y=y+60 for top and bottom
	rectangle(580,70,680,110);
	settextstyle(2,0,7);
	outtextxy(590,80,"Keyboard\n");
	//Reset button y=y+60 for top and bottom
	rectangle(580,130,680,170);
	settextstyle(2,0,7);
	outtextxy(590,140,"Reset\n");
	//polygon button y=y+60 for top and bottom
	rectangle(580,190,680,230);
	settextstyle(2,0,7);
	outtextxy(590,200,"Exit\n");
	//polygon 
	rectangle(20,320,110,360);
	settextstyle(2,0,7);
	outtextxy(30,330,"Polygon\n");
	//polygon button x=x+210 
	rectangle(220,320,310,360);
	settextstyle(2,0,7);
	outtextxy(230,330,"Round\n");
	//Exit button x=x+210 
	rectangle(420,320,510,360);
	settextstyle(2,0,7);
	outtextxy(430,330,"Elip\n");
}

//using mouse to select functions loadfile, keyboard, ...
void mouse(){
    //int maxx, maxy;
    int x_mouse, y_mouse;
     while (1) {
        //su kien mouse click
        if (ismouseclick(WM_LBUTTONDOWN)) {
            //Vi tri cua x_mouse, y_mouse khi click
            getmouseclick(WM_LBUTTONDOWN, x_mouse, y_mouse);
            //in ra toa do cua mouse
            //printf("\n(%d,%d)", x_mouse, y_mouse);			
       }
		//check for buttons y=y+60
		if(x_mouse>580 && x_mouse<680 && y_mouse>10 && y_mouse<50){//load file button
			printf("Read form file...");
			//read from file
			//readfile();
		}
		//check for keyboard
		if(x_mouse>580 && x_mouse<680 && y_mouse>70 && y_mouse<110){//load file button
			printf("Doc du lieu tu ban phim...\n");
			keyboard();
			drawCircle();
			is_run=1;
			
		}
        //check for reset
		if(x_mouse>580 && x_mouse<680 && y_mouse>130 && y_mouse<170){//load file button
			printf("Reset...");
			//reset();
		}
		
        // Check for right mouse button click to exit the loop
        if (ismouseclick(WM_RBUTTONDOWN)) {
            getmouseclick(WM_RBUTTONDOWN, x_mouse, y_mouse);
            printf("\nExiting...");
            break;
        }
        delay(100); // Delay to control the loop speed
    }
}

// xu li
//keyboard();
void keyboard(){
//	//read data from keyboard
//	fp=fopen(INPUT,"r");
//	if(fp==NULL){
//		printf("Find not found");
//		return;
//	}
	//else
	//doc dong dau tien cua tap tin
	printf("Nhap so dinh: ");
    scanf("%d", &sodinh);
    printf("Nhap vecto\n");
    for (int i = 0; i < sodinh; i++) {
        printf("Vecto %d: ", i + 1);
        scanf("%d %d", &td[i].x, &td[i].y);
    }
    printpoints(td,sodinh);
	printf("Finished!\n");
	fclose(fp);
}

//vehinhdagia
void drawPolygon(){
	if (sodinh < 3) {
        printf("So dinh khong hop le\n");
        return;
    }

    setcolor(YELLOW);

    for (int i = 0; i < sodinh - 1; i++) {
        line(td[i].x, td[i].y, td[i + 1].x, td[i + 1].y);
    }

    line(td[sodinh - 1].x, td[sodinh - 1].y, td[0].x, td[0].y);
}
//ve hinh tron
void drawCircle() {
	if (sodinh != 2) {
        printf("So dinh khong hop le\n");
        return;
    }

    setcolor(GREEN);
    int r = sqrt(pow(td[1].x - td[0].x, 2) + pow(td[1].y - td[0].y, 2));
    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y) {
        putpixel(td[0].x + x, td[0].y + y, GREEN);
        putpixel(td[0].x - x, td[0].y + y, GREEN);
        putpixel(td[0].x - x, td[0].y - y, GREEN);
        putpixel(td[0].x + x, td[0].y - y, GREEN);
        putpixel(td[0].x + y, td[0].y + x, GREEN);
        putpixel(td[0].x - y, td[0].y + x, GREEN);
        putpixel(td[0].x + y, td[0].y - x, GREEN);
        putpixel(td[0].x - y, td[0].y - x, GREEN);

        if (p <= 0) {
            p += 2 * x + 3;
        } else {
            y--;
            p += 2 * (x - y) + 5;
        }

        x++;
    }
}

// Vehinhellip
void drawEllipse() {
    if (sodinh != 2) {
        printf("so dinh khong hop le\n");
        return;
    }
    setcolor(RED);
    int a = abs(td[1].x - td[0].x);
    int b = abs(td[1].y - td[0].y);
    int x = 0;
    int y = b;
    int p = pow(b, 2) - pow(a, 2) * b + pow(a, 2) / 4;
    while (2 * pow(b, 2) * x < 2 * pow(a, 2) * y) {
        putpixel(td[0].x + x, td[0].y + y, RED);
        putpixel(td[0].x - x, td[0].y + y, RED);
        putpixel(td[0].x - x, td[0].y - y, RED);
        putpixel(td[0].x + x, td[0].y - y, RED);
        if (p < 0) {
            x++;
            p += 2 * pow(b, 2) * x + pow(b, 2);
        } else {
            x++;
            y--;
            p += 2 * pow(b, 2) * x - 2 * pow(a, 2) * y + pow(b, 2);
        }
    }
    p = pow(b, 2) * pow((x + 0.5), 2) + pow(a, 2) * pow((y - 1), 2) - pow(a, 2) * pow(b, 2);

    while (y >= 0) {
        putpixel(td[0].x + x, td[0].y + y, RED);
        putpixel(td[0].x - x, td[0].y + y, RED);
        putpixel(td[0].x - x, td[0].y - y, RED);
        putpixel(td[0].x + x, td[0].y - y, RED);

        if (p > 0) {
            y--;
            p -= 2 * pow(a, 2) * y + pow(a, 2);
        } else {
            x++;
            y--;
            p += 2 * pow(b, 2) * x - 2 * pow(a, 2) * y + pow(a, 2);
        }
    }
    printpoints(td,sodinh);
}


int main(){
	//doc file
	//readfile();
	//draw int interface
	initwindow(700,400);// width 700px heght=400px
	CUI_init();
	//dung chuot
	mouse();
	getch();
}
