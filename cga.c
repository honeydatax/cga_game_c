// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
#define cga 4
#define VIDEO 0xB800
#define stdout 0 
#define lpt 2 
#define com1 3 
#define black 0
#define cyan 1
#define red 2
#define white 3
int VID;
int ii;
void screens(n);
int getptr();
void backs(address,count,color);
int fillbyte(color);
void rect(rectx,recty,rectx1,recty1,color);

int main(){
	int n;
	int x=10;
	int y=10;
	int x1=200;
	int y1=150;
	int color=2;
	int unsigned size=(320/4)*220; 
	char c[80];
	screens(cga);
	backs(VIDEO,(int)size,fillbyte(white));
	rect(8,8,320-8,200-8,fillbyte(red));
	rect(16,16,320-16,200-16,fillbyte(cyan));
	
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}



void screens(n)
int n;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = n;


	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8A,0x04,0xB4,0x00,0xCD,0x10,0x5E,0x1F";
}



int getptr()
{
	int *c;
	c = (int * ) varn;

	asm	"db 0x8C,0xC8,0x2E,0xA3,0x80,0x0";
	return *(c + 0);
}

void backs(address,count,color)
int address;
int count;
int color;
{
	int *c;
	c = (int * ) varn;
	*(c + 0)=address;
	*(c + 1)=count;
	*(c + 2)=color;
	asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	
}




void rect(rectx,recty,rectx1,recty1,color)
int rectx;
int recty;
int rectx1;
int recty1;
int color;
{
	int r;
	int ir;
	int xx;
	int yy;
	int nx;
	int ny;
	int xx1;
	int yy1;
	int xxx;
	int yyy;
	int xxa;
	int *c;
	int gg=0;
	c = (int * ) varn;
	xx=rectx;
	yy=recty;
	xx1=rectx1;
	yy1=recty1;
	if (xx>319)xx=319;
	if (xx1>319)xx1=319;
	if (yy>219)yy=219;
	if (yy1>219)yy1=219;
	if (xx<0)xx=0;
	if (xx1<0)xx1=0;
	if (yy<0)yy=0;
	if (yy1<0)yy1=0;
	yy=yy/2;
	yy1=yy1/2;
	xx=xx/4;
	xx1=xx1/4;
	if (xx<=xx1 && yy<=yy1){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=yy*80+xx;
		nx=80-xxa;
		*(c + 0)=VIDEO;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=color;
	}	
	if (xx<=xx1 && yy<=yy1){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x36,0x86,0x00,0x8B";
		asm "db 0x16,0x8A,0x00,0x8B,0x1E,0x88,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00";
		asm "db 0x50,0x07,0x88,0xD0,0x31,0xD2,0x51,0x90,0x59,0x51,0x90,0xFC,0xF3,0xAA";
		asm "db 0xF8,0x01,0xF7,0x4B,0x39,0xD3,0x75,0xF1,0x58,0x07,0x1F";
	}
			
	xx=rectx;
	yy=recty;
	xx1=rectx1;
	yy1=recty1;
	if (xx>319)xx=319;
	if (xx1>319)xx1=319;
	if (yy>219)yy=219;
	if (yy1>219)yy1=219;
	if (xx<0)xx=0;
	if (xx1<0)xx1=0;
	if (yy<0)yy=0;
	if (yy1<0)yy1=0;
	yy=yy/2;
	yy1=yy1/2;
	xx=xx/4;
	xx1=xx1/4;
	if (xx<=xx1 && yy<=yy1){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		if (yyy<1)yyy=1;
		xxx=(yy*80+xx);
		nx=80-xxa;
		*(c + 0)=VIDEO+0x200;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=color;
	}	
	if (xx<=xx1 && yy<=yy1){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x36,0x86,0x00,0x8B";
		asm "db 0x16,0x8A,0x00,0x8B,0x1E,0x88,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00";
		asm "db 0x50,0x07,0x88,0xD0,0x31,0xD2,0x51,0x90,0x59,0x51,0x90,0xFC,0xF3,0xAA";
		asm "db 0xF8,0x01,0xF7,0x4B,0x39,0xD3,0x75,0xF1,0x58,0x07,0x1F";
	}		
	
}



int fillbyte(color)
int color;
{
	int colors;
	colors=color << 6 | color << 4 | color << 2 | color;
	return colors;
}
