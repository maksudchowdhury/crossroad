#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include "iGraphics.h"
char playername[100];
char score[10], prescore[10],gameoverscore[10];
int width=1200,height=800,i=0;
int carnumber=8;
long double cpx[8]={0,20,-200,-20,5,-30,0,-10};
long double cpy[8]={30,120,215,320,419,520,610,700};
char car_location[8][50]={"sources\\car1.bmp","sources\\car2.bmp","sources\\car3.bmp","sources\\car4.bmp","sources\\car5.bmp","sources\\car6.bmp","sources\\car7.bmp","sources\\car8.bmp"};
char human[4][50]={"sources\\hup.bmp","sources\\hdown.bmp","sources\\hleft.bmp","sources\\hright.bmp"};
char human_life[6][50] = { "sources\\life0.bmp","sources\\life1.bmp", "sources\\life2.bmp", "sources\\life3.bmp","sources\\life4.bmp","sources\\life5.bmp" };
double humanx = 500, humany = 0, human_speed = 20;
int direction = 0, life_value = 5;
int speed=40;
int countup = 0, countdown = 0, countall, perscore = 3, negpoint = 0, prevscore = 0,gameoverscr=0;
/*
	function iDraw() is called again and again by the system.

	*/

void iDraw() {
	//place your drawing codes here

	iClear();
    iShowBMP(0,0,"sources\\road.bmp");
    iShowBMP2(humanx,humany,human[direction],0);
    for(i=0;i<carnumber;i++){
        iShowBMP2(cpx[i],cpy[i],car_location[i],0);
        speed=rand()%20+10;
        cpx[i]=cpx[i]+speed;
    }
    iShowBMP(1000,0,"sources\\menu side.bmp");
	iShowBMP2(1033, 405, human_life[life_value], 0);
    iText(1048,750,playername,GLUT_BITMAP_TIMES_ROMAN_24);

    for(i=0;i<carnumber;i++){
        if(cpx[i]>=1000){
        cpx[i]=0;
        }

    }

    if (humanx<0){
        humanx=0;//human
    }
    if(humanx>width-230){
        humanx=width-230;
    }
    if (humany<0){
        humany=0;
    }
    if(humany>height-30){
        humany=height-30;
    }
    if(humany==0 && countup>countdown){
        iSetColor(0,255,0);
        iFilledRectangle(0,0,1200,800);
        countdown++;
    }
    if(humany==height-30 && countup==countdown){
        iSetColor(0,255,0);
        iFilledRectangle(0,0,1200,800);
        countup++;
    }
    
    for(i=0;i<carnumber;i++){
        if(humanx>=cpx[i]&&humanx<=cpx[i]+100 && humany+20>=cpy[i]&&humany<=cpy[i]+50){
			life_value--;
			humanx = rand() % 1000;
            iSetColor(255,0,0);
            iFilledRectangle(0,0,1200,800);
            if(countup==countdown){
                humany=0;
				negpoint = negpoint - perscore;

            }
            if(countup>countdown){
				negpoint = negpoint - perscore;
                humany=800;
				
            }

        }

    }
	countall = (countdown + countup)*perscore+negpoint;
    _itoa_s(countall,score,10);
    iSetColor(255,255,255);
    iText(1020,700,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1100,700,score,GLUT_BITMAP_TIMES_ROMAN_24);
	_itoa_s(prevscore, prescore, 10);
	iText(1020, 200, "Previous Score", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1090, 170, prescore, GLUT_BITMAP_TIMES_ROMAN_24);
	if (life_value == 1){
		gameoverscr = countall-perscore;
	}
	if (life_value<1){
		life_value = 0;
		_itoa_s(gameoverscr, gameoverscore, 10);
		iShowBMP(0, 0, "sources\\gameover.bmp");
		iText(600, 278, gameoverscore, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {

	//place your codes here


}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
    printf("x = %d, y= %d\n",mx,my);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here

	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	if(key=='s'){
        printf("  %d",countall);
	}
	if(key=='r'){
		prevscore = gameoverscr;
		countdown = 0, countup = 0, negpoint = 0, humany = 0;
		life_value = 5;

	}


	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
    if (key == GLUT_KEY_UP) {
        direction=0;
        humany=humany+human_speed;
    }
	if (key == GLUT_KEY_DOWN) {
	    direction=1;
	    humany=humany-human_speed;
	}
	if (key == GLUT_KEY_LEFT) {
	    direction=2;
	    humanx=humanx-human_speed;
	}
	if (key == GLUT_KEY_RIGHT) {
	    direction=3;
	    humanx=humanx+human_speed;
	}
}


int main() {
	//place your own initialization codes here.
    system ("mode con: cols=50 lines=10");
    printf("\t\tEnter Player's Name\n\n\t\t\t");
	scanf("%s", &playername);
	iInitialize(width,height, "CSE103 PROJECT-- MAKSUD");

	return 0;
}
