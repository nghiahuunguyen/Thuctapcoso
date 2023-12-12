#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#define MAX 100
#define INPUT "Polygon.inp"
#define INPUT "Cricle.inp"
#define INPUT "Polygon.inp"
#define INPUT "Elip.inp"
#include <stdbool.h>
#include<Math.h>

// Khai bao protype
void CUI_init();
void mouse();
void keyboard();
int is_run=0;
void readfilePolygon();
void readfileCircle();
void drawPolygon();
void drawCircle();
void drawEllipse();
void readfileElip();
void reset();
void exit();

// khai bao bien cuc bo
int sodinh;//sodinh(so phan tu can sap xep)
FILE *fp; //file
int enable_mouse=1;
bool isPolygonClicked = false; 
bool isCricleClicked = false;
bool isElipClicked = false;
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
	outtextxy(230,330,"Cricle\n");
	//Exit button x=x+210 
	rectangle(420,320,510,360);
	settextstyle(2,0,7);
	outtextxy(430,330,"Elip\n");
}

//using mouse to select functions loadfile, keyboard, ...
void mouse(){
    int x_mouse, y_mouse;
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x_mouse, y_mouse);

            if (x_mouse > 580 && x_mouse < 680 && y_mouse > 10 && y_mouse < 50) { // Nút "Load file"                
                if (isPolygonClicked) { // Neu dã bam nút "Polygon"
                	printf("Lay toa do tu file...\n");
                    readfilePolygon();
					drawPolygon();
                }
				else if (isCricleClicked){
					printf("Lay toa do tu file...\n");
					readfileCircle();
                	drawCircle();
				}
				else if(isElipClicked){
					printf("Lay toa do tu file...\n");
					readfileElip();
                	drawEllipse ();
				} 
				else {
			        printf("Chua chon hinh. Vui long chon lai.\n");
			    }
            } 
            // Nút "Keyboard"
			if (x_mouse > 580 && x_mouse < 680 && y_mouse > 70 && y_mouse < 110) { 
                if (isPolygonClicked) { // Neu dã bam nút "Polygon"
	                printf("Nhap du lieu ban phim...\n");
	                keyboard();
                    drawPolygon();
                } 
				else if (isCricleClicked){
					printf("Nhap du lieu ban phim...\n");
                	keyboard();
                	drawCircle();
				}
				else if(isElipClicked){
					printf("Nhap du lieu ban phim...\n");
                	keyboard();
                	drawEllipse ();
				}
				else {
			        printf("Chua chon hinh. Vui long chon lai.\n");
			    }				
            } 
            // Nút "Reset"
			if (x_mouse > 580 && x_mouse < 680 && y_mouse > 130 && y_mouse < 170) { 
                printf("Reset...\n");
                reset();
            } 
            // Nút "Exit"
            if (x_mouse > 580 && x_mouse < 680 && y_mouse > 190 && y_mouse < 230) {
                exit();
            }
            // Nút "Polygon"
			if (x_mouse > 20 && x_mouse < 110 && y_mouse > 320 && y_mouse < 360) { 
                printf("Ve da giac\n");
                printf("Chon du lieu file hay ban phim\n");
                isPolygonClicked = true;
            } 
            // Nút "Cricle"
			if (x_mouse > 220 && x_mouse < 310 && y_mouse > 320 && y_mouse < 360) { 
                printf("Ve hinh tron\n");
                printf("Chon du lieu file hay ban phim\n");
                isCricleClicked = true;
            }
            // Nút "Elip"
			if (x_mouse > 420 && x_mouse < 510 && y_mouse > 320 && y_mouse < 360) { 
                printf("Ve hinh elip.\n");
                printf("Chon du lieu file hay ban phim\n");
                isElipClicked = true;
            }
        }
        delay(100);
    }
}

// xu li

//read file
void readfilePolygon(){
	fp=fopen("Polygon.inp","r");
	if (fp==NULL){
		printf("File not found\n");
		return;
	}
	//else
	//doc dong dau tien cua tap tin
	fscanf(fp,"%d",&sodinh);
	printf("So dinh: %d\n",sodinh);
	//doc lan luot tung phan tu moi phan tu co 2 tham so toado_x,toado_y
	printf("Toa do\n");
	for(int i=0;i<sodinh;i++){
		fscanf(fp,"%d %d",&td[i].x,&td[i].y);
	}
	//inacacdiem
	printpoints(td,sodinh);
	fclose(fp);
}
void readfileCircle(){
	fp=fopen("Cricle.inp","r");
	if (fp==NULL){
		printf("File not found");
		return;
	}
	//else
	//doc dong dau tien cua tap tin
	fscanf(fp,"%d",&sodinh);
	printf("So dinh: %d\n",sodinh);
	//doc lan luot tung phan tu moi phan tu co 2 tham so toado_x,toado_y
	printf("Toa do\n");
	for(int i=0;i<sodinh;i++){
		fscanf(fp,"%d %d",&td[i].x,&td[i].y);
	}
	//inacacdiem
	printpoints(td,sodinh);
	fclose(fp);
}
void readfileElip(){
	fp=fopen("Elip.inp","r");
	if (fp==NULL){
		printf("File not found");
		return;
	}
	//else
	//doc dong dau tien cua tap tin
	fscanf(fp,"%d",&sodinh);
	printf("So dinh: %d\n",sodinh);
	//doc lan luot tung phan tu moi phan tu co 2 tham so toado_x,toado_y
	printf("Toa do\n");
	for(int i=0;i<sodinh;i++){
		fscanf(fp,"%d %d",&td[i].x,&td[i].y);
	}
	//inacacdiem
	printpoints(td,sodinh);
	fclose(fp);
}

//keyboard();
void keyboard(){
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

//reset
void reset(){
	isPolygonClicked = false;
    isCricleClicked = false;
    isElipClicked = false;
     sodinh = 0;
    cleardevice();
    CUI_init();
}

//exit
void exit(){ 
    exit(0);
}

int main(){
	initwindow(700,400);// width 700px heght=400px
	CUI_init();
	//dung chuot
	mouse();
	getch();
}
