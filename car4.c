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
#define seconds 18
#define memend	3000

int seeds;
int VID;
int ii;
void screens(n);
int getptr();
void backs(address,count,color);
int fillbyte(color);
void rect(rectx,recty,rectx1,recty1,color);
void randomize(seed);
int random(max);
int peek(address);
int getkey();
void sleep(i);
int gettimer();
void hline(hlinex,hliney,hlinex1,hliney1,color);


int main(){
	int e;
	int ee;
	int xx;
	int yy;
	int n;
	int nn;
	int x=10;
	int y=10;
	int x1=200;
	int y1=25;
	int color=2;
	int unsigned size=(320/4)*220; 
	char c[80];
	screens(cga);
	backs(VIDEO,(int)size,fillbyte(cyan));
	x=(320/2);
	xx=-10;
	e=2;
	y1=52;
	while(n!=27){
		hline(0,47,319,47,fillbyte(red));
		for (n=0;n<150;n++){
			hline(x-n,n+47,x+n,n+47,fillbyte(red));
		}
		ee=e/3;
		rect(x-(ee/2),y1,x+(ee/2),y1+ee,fillbyte(black));
		sleep(seconds/4);
		for (n=0;n<150;n++){
			hline(x-n,n+47,x+n,n+47,fillbyte(cyan));
		}
		y1=y1+2;
		e=e+2;
		if (y1>25+140-ee){
			y1=52;
			e=2;
		}
		n=getkey();
		nn=n >> 8;
		n=n & 255;
		if (x>30 && nn=='K') x=x-8;
		if (x<300 && nn=='M') x=x+8;


	}

	
	
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




void randomize(seed)
int seed;
{
	seeds=(seed/64)+0x100;
}


int random(max)
int max;
{	
	int i=0x7fff/max;
	int ii;
	ii=peek(seeds) & 0x7fff;
	ii=ii/i;
	seeds=seeds+2;
	if(seeds>memend)seeds=0x100;	
	return ii;
}

int peek(address)
int address;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = address;

	asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0x2E,0x8B,0x1E,0x80,0x00,0x2E,0x8B,0x07,0x2E,0xA3,0x80,0x00,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	return *(c + 0);


}


int getkey()
{
	int *c;
	c = (int * ) varn;

		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0xB4,0x01,0xCD,0x16,0x75,0x09,0xB8,0x00,0x00,0x2E,0xA3,0x80,0x00,0xEB,0x09,0x90,0xB4,0x00,0xCD,0x16,0x2E,0xA3,0x80,0x00,0x90,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	return *(c + 0);	
}



void sleep(i)
int i;
{
	int t1;
	int t2;
	t1=gettimer();
	t1=t1+i;
	t2=gettimer();
	while(t1<t2){
		t2=gettimer();
	}
	while(t1>t2){
		t2=gettimer();
	}
}

int gettimer()
{
	int *c;
	c = (int * ) varn;

		asm	"db 0x1E,0x06,0x50,0x53,0x51,0x52,0x56,0x57,0xB4,0x00,0xCD,0x1A,0x2E,0x89,0x16,0x80,0x00,0x5F,0x5E,0x5A,0x59,0x5B,0x58,0x07,0x1F";
	return *(c + 0) & 0x7fff;	
}


void hline(hlinex,hliney,hlinex1,hliney1,color)
int hlinex;
int hliney;
int hlinex1;
int hliney1;
int color;
{
	int ir;
	int xx;
	int yy;
	int xx1;
	int yy1;
	int xxx;
	int yyy;
	int xxa;
	int parity;
	int *c;
	c = (int * ) varn;
	xx=hlinex;
	yy=hliney;
	xx1=hlinex1;
	yy1=hliney1;
	if (xx>319)xx=319;
	if (xx1>319)xx1=319;
	if (yy>199)yy=199;
	if (yy1>199)yy1=199;
	if (xx<0)xx=0;
	if (xx1<0)xx1=0;
	if (yy<0)yy=0;
	if (yy1<0)yy1=0;
	parity=yy & 1;
	if(parity==1)parity=0x200;
	xx=xx/4;
	yy=yy/2;
	xx1=xx1/4;
	yy1=yy1/2;

	if (xx<=xx1 && yy==yy1){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		xxx=yy*80+xx;
		*(c + 0)=VIDEO+parity;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=color;
	}
	if (xx<=xx1 && yy==yy1){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x16,0x86,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}
}

