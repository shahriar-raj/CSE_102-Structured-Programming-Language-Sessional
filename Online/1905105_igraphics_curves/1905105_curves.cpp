/*
	author: Shahriar Raj
	last modified: November 1, 2020
*/
# include "iGraphics.h"
# include "gl.h"
# include <math.h>

double a, bsum, dx=0, dy=300, b[10], d[10], amp=40, freq=1, x=0, y_s[10], y_c[10], y_sum, k=2, r=5;
int s=1, c=0, f1=0, i, j, n_sin=2, n_cos=1, ball=1, t[20]={0};
char image[50]={"1905105_cover.bmp"};
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();
	if(f1){                                                           // if f1=1 then it will come into this page. f1 is for toggling between home and main screen
        for(a=0;a<=1000&&s;a+=0.5){                                   // this loop is for drawing the graphs and line . Here "a" is for the x coordinates and "b" is for the y coordinates
            bsum=0;
            iSetColor(123, 91, 173);                                  // "s" variable is used  for hiding or showing the graphs
            iLine(0,dy,1000,dy);
            for(i=1;i<=n_sin;i++){
                b[i] = dy+ amp*sin(freq*i*0.5*((a+dx)*(3.1416/90)));  //this loop is for drawing sine graphs
                iSetColor(0, 255, 255);
                iPoint(a, b[i], .1);
                bsum+=b[i];
            }
            for(i=1;i<=n_cos;i++){
                d[i] = dy+ amp*cos(freq*i*0.5*((a+dx)*(3.1416/90))); // this loop is for drawing cosine graphs
                iSetColor(255, 255, 0);
                iPoint(a, d[i], .1);
                bsum+=d[i];
            }
            bsum-=(dy*(n_sin+n_cos-1));                             // this draws the combination of all curves
            iSetColor(255, 255, 255);
            iPoint(a, bsum,.1);
        }
        if(ball){                                                   // "ball" variable is used for showing or hiding all the tracers
            for(i=1;i<=n_sin;i++){                                  // this loop is for drawing the tracers along the sine graphs
                if(!t[i-1]){
                    iSetColor(200+i, 255-40*i, 200-20*i);
                    iFilledCircle(x, y_s[i], r,100);
                }
            }
            for(i=1;i<=n_cos;i++){                                  // this loop is for drawing  the tracers along the cosine graphs
                if(!t[4+i]){
                    iSetColor(200+i, 200-20*i, 255-40*i);
                    iFilledCircle(x, y_c[i], r,100);
                }
            }
            if(!t[10]){
                iSetColor(123, 0, 255);                             // this draws the tracer along the combination of all curves
                iFilledCircle(x, y_sum, r,100);
            }
        }
        iSetColor(123, 91, 173);
        iText(10, 10, "Press p/P for pause, r/R for resume, END for exit.");
        iSetColor(0,255,255);
        iText(650,580,"Active Sine graphs  :                (0-4)");
        for(i=0;i<n_sin;i++){                                       // this loop shows the number of active sine graphs
                iSetColor(0,255,255);
                iText(820+20*i,580," * ");
        }
        iSetColor(255,255,0);
        iText(650,560,"Active Cosine graphs:                (5-9)");
        for(i=0;i<n_cos;i++){                                       // this loop shows the number of active cosine graphs
                iSetColor(255,255,0);
                iText(820+20*i,560," * ");
        }
        iSetColor(255,255,255);
        iText(650,540,"Combination graph is numbered as DOT ( . )");

	}
	else{
        iShowBMP(0,0, image);                                               // inserts image
        iSetColor(255, 255, 0);
        iText(50, 500, "Toggle Help/Main Page : F1",GLUT_BITMAP_9_BY_15);   // Controls on the Home Page
        iText(50, 475, "Toggle Curve Show/Hide: S/s",GLUT_BITMAP_9_BY_15);  // Font: GLUT_BITMAP_9_BY_15
        iText(50, 450, "Pause Animation       : P/p",GLUT_BITMAP_9_BY_15);
        iText(50, 425, "Resume Animation      : R/r",GLUT_BITMAP_9_BY_15);
        iText(50, 400, "Increase Amplitude    : a",GLUT_BITMAP_9_BY_15);
        iText(50, 375, "Decrease Amplitude    : A",GLUT_BITMAP_9_BY_15);
        iText(50, 350, "Increase Frequency    : f",GLUT_BITMAP_9_BY_15);
        iSetColor(0, 255, 255);
        iText(50, 325, "Decrease Frequency    : F",GLUT_BITMAP_9_BY_15);
        iText(50, 300, "Increase Speed        : +",GLUT_BITMAP_9_BY_15);
        iText(50, 275, "Decrease Speed        : -",GLUT_BITMAP_9_BY_15);
        iText(50, 250, "Reverse The Tracers   : Q/q",GLUT_BITMAP_9_BY_15);
        iText(50, 225, "Toggle All The Tracers",GLUT_BITMAP_9_BY_15);
        iText(50, 200, "Show/Hide             : B/b",GLUT_BITMAP_9_BY_15);
        iText(50, 175, "Increase Tracer's Size: I",GLUT_BITMAP_9_BY_15);
        iSetColor(0, 255, 255);
        iText(700, 500, "Decrease Tracer's Size: i",GLUT_BITMAP_9_BY_15);
        iText(700, 475, "Add 1 Sine Curve    : Left Mouse",GLUT_BITMAP_9_BY_15);
        iText(700, 450, "Add 1 Cosine Curve  : Right Mouse",GLUT_BITMAP_9_BY_15);
        iText(700, 425, "Erase 1 Sine Curve  : e",GLUT_BITMAP_9_BY_15);
        iText(700, 400, "Erase 1 Cosine Curve: E",GLUT_BITMAP_9_BY_15);
        iText(700, 375, "Increase Phase Diff : Right Arrow",GLUT_BITMAP_9_BY_15);
        iText(700, 350, "Decrease Phase Diff : Left Arrow",GLUT_BITMAP_9_BY_15);
        iSetColor(255, 255, 0);
        iText(700, 325, "Toggle Sine Curve   ",GLUT_BITMAP_9_BY_15);
        iText(700, 300, "Tracer Show/Hide    : 0-4",GLUT_BITMAP_9_BY_15);
        iText(700, 275, "Toggle Cosine Curve ",GLUT_BITMAP_9_BY_15);
        iText(700, 250, "Tracer Show/Hide    : 5-9",GLUT_BITMAP_9_BY_15);
        iText(700, 225, "Toggle Combination Curve",GLUT_BITMAP_9_BY_15);
        iText(700, 200, "Tracer Show/Hide    : . (DOT)",GLUT_BITMAP_9_BY_15);
        iText(700, 175, "Exit                : END",GLUT_BITMAP_9_BY_15);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && n_sin<5)
	{
		//place your codes here                                             // the left mouse button click adds one sine curve
		n_sin++;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && n_cos<5)
	{
		//place your codes here                                             // the right mouse button click adds one cosine curve
		n_cos++;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'f' && freq<5)
	{
		freq+=.1;
	}
	if(key == 'F' && freq>0.1)                                              // f/F for increasing and decreasing frequency ("freq") by 0.1
	{
		freq-=.1;
	}
	if(key == 'a' && amp<300)
	{
		amp+=1;
    }
    if(key == 'A' && amp>0)                                                // a/A for increasing  and decreasing amplitude ("amp") by 1
	{
		amp-=1;
    }
	if(key == 's'|| key == 'S')
    {
        s = !s;
    }
	if(key == 'p'|| key == 'P')
    {
        iPauseTimer(0);
    }
	if(key == 'r'|| key == 'R')
    {
        iResumeTimer(0);
    }
	if(key == '+' && k<7)
    {
        k+=.2;
    }
	if(key == '-' && k>0.4)                                                   // "k" variable is used for controlling the speed of the tracers
    {
        k-=.2;
    }
    if(key == 'q'|| key == 'Q')                                               // "c" variable is used for reversing the tracers
    {
        c=!c;
    }
    if(key == 'e' && n_sin>0)
    {
        n_sin--;
    }
    if(key == 'E' && n_cos>0)
    {
        n_cos--;
    }
    if(key == 'b' || key == 'B')                                              // "ball" variable is used for showing or hiding all the tracers
    {
        ball=!ball;
    }
    if(key == 'i' && r>3)
    {
        r-=0.5;
    }
    if(key == 'I' && r<7)
    {
        r+=0.5;
    }
    if(key == '0')
    {
        t[0]=!t[0];
    }
    if(key == '1')
    {
        t[1]=!t[1];
    }
    if(key == '2')
    {
        t[2]=!t[2];
    }
    if(key == '3')
    {
        t[3]=!t[3];
    }
    if(key == '4')
    {
        t[4]=!t[4];
    }
    if(key == '5')                                                          // "t[]" array is used to show or hide individual tracer
    {
        t[5]=!t[5];
    }
    if(key == '6')
    {
        t[6]=!t[6];
    }
    if(key == '7')
    {
        t[7]=!t[7];
    }
    if(key == '8')
    {
        t[8]=!t[8];
    }
    if(key == '9')
    {
        t[9]=!t[9];
    }
    if(key == '.')
    {
        t[10]=!t[10];
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
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_RIGHT)
	{
		dx+=5;                                                                                  // right and left arrow are used for phase difference. it increases or decreases the "dx" variable
	}
	if(key == GLUT_KEY_LEFT)
	{
		dx-=5;
	}
	if(key == GLUT_KEY_F1)
	{
		f1=!f1;
	}
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
void tracers()
{
    y_sum=0;
    for(i=1;i<=n_sin;i++){                                                                     // tracers animation is controlled by this "tracers" function
        y_s[i] = dy+ amp*sin(freq*i*0.5*((x+dx)*(3.1416/90)));
        y_sum+=y_s[i];
    }
    for(i=1;i<=n_cos;i++){
        y_c[i] = dy+ amp*cos(freq*i*0.5*((x+dx)*(3.1416/90)));
        y_sum+=y_c[i];
    }
    y_sum-=(dy*(n_sin+n_cos-1));
    if(x>=1000)                                                                               // "c" variable is used for tracers direction (from left to right/ right to left)
    c=1;
    else if(x<=0)
    c=0;
    c==0?x+=k:x-=k;                                                                           // "k" variable is used for controlling the tracer's speed
}
int main()
{
//    PlaySound((LPCSTR) "C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3", NULL, SND_FILENAME | SND_ASYNC);
//    DWORD dwError = GetLastError();

	//place your own initialization codes here.
	iSetTimer(5, tracers);
	iInitialize(1000, 600, "Curves");                                                       // width = "1000 px" height = "600 px"

	return 0;
}

