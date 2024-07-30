/*
	author: Shahriar Raj
	last modified: December 19, 2020
*/
# include "iGraphics.h"
# include "gl.h"
# include <math.h>
# include <MMSystem.h>
# include <Windows.h>

double dy0=650, dy_e, t=0, g_e=9.8, basket_x=675, basket_y=0, c=0, xm[4]={1230,1235,1285,1280}, ym[4]={660,660,690,690};

int hen_n, up=5, low=0, egg_c, score=0, mi, sec=0, pause_time=0, startmenu=0, time_counter=1, index=0, startmenu_state=0, hm=0, gover=0, music_on=1, win=0;

char egg[4][30] = {"brown_egg.bmp","golden_egg.bmp","blue_egg.bmp","shit.bmp"}, hen[30] = {"hen.bmp"}, bg[30] = {"background.bmp"}, basket[30] = {"basket.bmp"}, up_arrow[10] = {"up.bmp"},
     down_arrow[10] = {"down.bmp"}, submit[30]= {"submit.bmp"}, pause[30]={"pause.bmp"}, resume[30]={"resume.bmp"}, exit_[30]={"exit.bmp"}, exit2[30]={"exit2.bmp"}, menu[30]={"home.bmp"},
     instructions[30] = {"instructions.bmp"}, counter[10] = {"1 minute"}, high_score[5][30] = {"high_score1.txt","high_score2.txt","high_score3.txt","high_score4.txt","high_score5.txt"},
     high_name[5][30] = {"high_name1.txt","high_name2.txt","high_name3.txt","high_name4.txt","high_name5.txt"}, hall[30] = {"hall.bmp"}, board[30] = {"board.bmp"}, gameover[30]={"gameover.bmp"},
     music_icon[30] = {"music.bmp"}, tim[20], p[50], hon_nam[30], sound[30] = {"music.wav"};


typedef struct _hon
{
    char name[30];
    int sc;
}hon;

FILE *fp, *fname, *fs;

void highscore();
void w_l();
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
    iClear();
	if(!startmenu){
        iShowBMP(0,0,gameover);
        iSetColor(242, 148, 19);
        iFilledRectangle(550,600,200,90);
        iFilledRectangle(550,470,200,90);
        iFilledRectangle(550,340,200,90);
        iFilledRectangle(550,210,200,90);
        iFilledRectangle(550,80,200,90);
        iSetColor(255,255,255);
        iRectangle(550,600,200,90);
        iRectangle(550,470,200,90);                                                                 // Start Menu
        iRectangle(550,340,200,90);
        iRectangle(550,210,200,90);
        iRectangle(550,80,200,90);
        iSetColor(0, 0, 0);
        iText(600,510,"NEW GAME",GLUT_BITMAP_HELVETICA_18);
        iText(600,640,"CONTINUE",GLUT_BITMAP_HELVETICA_18);
        iText(585,380,"HALL OF FAME",GLUT_BITMAP_HELVETICA_18);
        iText(580,250,"INSTRUCTIONS",GLUT_BITMAP_HELVETICA_18);
        iText(630,120,"EXIT",GLUT_BITMAP_HELVETICA_18);
	}
	if(startmenu == 1){
        iShowBMP(0,0,bg);
        iShowBMP2(hen_n*200+100,dy_e,egg[egg_c],0);
        iShowBMP2(hen_n*200+50,650,hen,0);
        iSetColor(0,0,0);
        iFilledRectangle(0,650,1300,3);
        iShowBMP2(basket_x,basket_y,basket,0);
        //iLine(basket_x+15)
        iSetColor( 0, 0, 0);
        iText(50,700,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);                                            // Game Page
        if(score<0)
            iText(140,700,"-",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(160,700,p,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1050,700,"TIME : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1150,700,tim,GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(1040,690,180,40);
        iRectangle(40,690,180,40);
        iShowBMP2(1230,730,pause,0);
        iShowBMP2(20,730,exit2,0);
        if(pause_time)
        {
            iSetColor(0,0,0);
            iFilledRectangle(570,150,250,500);
            iSetColor(255,255,255);
            iRectangle(570,150,250,500);
            iRectangle(580,160,230,480);
            iSetColor(255, 0, 0);
            iText(650,600,"PAUSED",GLUT_BITMAP_TIMES_ROMAN_24);                                           // Pause Menu on the game page
            iShowBMP2(650,500,resume,0);
            iShowBMP2(650,350,menu,0);
            iShowBMP2(650,200,exit_,0);
        }
	}
	if(startmenu == 2){
        iShowBMP(0,0,gameover);
        iSetColor(255, 0, 0);
        if(win)
            iText(430,550,"CONGRATS! YOU WON!! YOU ARE IN THE TOP TEN HIGH SCORERS",GLUT_BITMAP_HELVETICA_18);
        else
            iText(450,550,"YOU LOST! YOU ARE NOT IN THE TOP TEN HIGH SCORERS",GLUT_BITMAP_HELVETICA_18);
        iSetColor(255, 255, 255);
        iFilledRectangle(635,440,320,30);
        iSetColor(255,0 , 0);
        iText(600,700,"Gameover",GLUT_BITMAP_TIMES_ROMAN_24);                                              // Gameover Page
        iText(600,600,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
        if(score<0)
            iText(680,600,"-",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(700,600,p,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(390,450,"ENTER YOUR NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(635,440,320,30);
        iText(650,450,hon_nam,GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP2(600,200,submit,0);
	}
	if(startmenu == 3){
        iShowBMP(0,0,bg);
        iShowBMP2(860,375,up_arrow,0);
        iShowBMP2(860,350,down_arrow,0);
        iSetColor(0,0,0);
        iFilledRectangle(650,350,200,50);                                                                // Duration Select Page
        iFilledRectangle(490,350,150,50);
        iFilledRectangle(10,730,100,50);
        iSetColor(255, 255, 255);
        iRectangle(10,730,100,50);
        iRectangle(650,350,200,50);
        iSetColor( 255, 255, 255);
        iText(500,365,"DURATION : ",GLUT_BITMAP_HELVETICA_18);
        iShowBMP2(600,250,submit,0);
        iSetColor( 255, 255, 0);
        counter[0] = time_counter + '0';
        iText(700,365,counter,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,750,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(startmenu == 4){
        iShowBMP(0,0,instructions);
        iSetColor(0,0,0);
        iFilledRectangle(10,730,100,50);
        iSetColor(255,255,255);
        iText(25,750,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);                                                // Instruction Page
        iRectangle(10,730,100,50);
        if(startmenu_state == 0){
            iSetColor(130,130,130);
            iFilledRectangle(90,545,140,20);
            iFilledRectangle(90,395,100,20);
            iFilledRectangle(90,335,80,20);
            iSetColor(0,0,0);
            iFilledRectangle(490,640,120,40);                                                         // gameplay Page on Instruction Page
            iSetColor(255,255,0);
            iRectangle(490,640,120,40);
            iText(500,650,"GAMEPLAY",GLUT_BITMAP_HELVETICA_18);
            iText(700,650,"CONTROLS",GLUT_BITMAP_HELVETICA_18);
            iText(100,600,"There is a basket. And you have to catch eggs with it. For each egg you catch your score will increase. And for each shit ",GLUT_BITMAP_9_BY_15);
            iText(100,580,"you catch your score will decrease. ",GLUT_BITMAP_9_BY_15);
            iText(100,550,"SCORE SYSTEM: ",GLUT_BITMAP_9_BY_15);
            iText(100,520,"1. Brown egg        = +1 points",GLUT_BITMAP_9_BY_15);
            iShowBMP2(230,510,egg[0],0);
            iText(100,490,"2. Blue egg         = +5 points",GLUT_BITMAP_9_BY_15);
            iShowBMP2(230,480,egg[2],0);
            iText(100,460,"3. Golden egg       = +10 points",GLUT_BITMAP_9_BY_15);
            iShowBMP2(230,450,egg[1],0);
            iText(100,430,"4. Shit             = -10 points",GLUT_BITMAP_9_BY_15);
            iShowBMP2(230,415,egg[3],0);
            iText(100,400,"DURATION:",GLUT_BITMAP_9_BY_15);
            iText(100,370,"You can select duration from 1 to 5 minutes. ",GLUT_BITMAP_9_BY_15);
            iText(100,340,"RESULT:",GLUT_BITMAP_9_BY_15);
            iText(100,310,"If you can get into top 10 highscorers in the selected duration, you win. Otherwise you lose. ",GLUT_BITMAP_9_BY_15);
        }
        if(startmenu_state == 1){
            iSetColor(130,130,130);
            iFilledRectangle(108,565,22,20);
            iFilledRectangle(108,535,22,20);
            iFilledRectangle(90,595,180,20);
            iFilledRectangle(90,475,150,20);
            iSetColor(0,0,0);
            iFilledRectangle(690,640,120,40);                                                              // Controls Page on Instruction Page
            iSetColor(255,255,0);
            iRectangle(690,640,120,40);
            iText(500,650,"GAMEPLAY",GLUT_BITMAP_HELVETICA_18);
            iText(700,650,"CONTROLS",GLUT_BITMAP_HELVETICA_18);
            iText(100,600,"KEYBOARD CONTROLS: ",GLUT_BITMAP_9_BY_15);
            iText(100,570,"\"<-\" Left Arrow  : Move the basket to left",GLUT_BITMAP_9_BY_15);
            iText(100,540,"\"->\" Right Arrow : Move the basket to right",GLUT_BITMAP_9_BY_15);
            iText(100,510,"  m : Music On/Off",GLUT_BITMAP_9_BY_15);
            iText(100,480,"MOUSE CONTROLS: ",GLUT_BITMAP_9_BY_15);
            iText(100,450,"You can also hold the basket with mouse left key and drag the basket sideways.  ",GLUT_BITMAP_9_BY_15);

        }
	}
	if(startmenu == 5){
        iShowBMP(0,0,instructions);
        iShowBMP2(575,650,hall,0);
        iShowBMP(400,100,board);
        iSetColor(69, 51, 170);
        iFilledRectangle(hm*200+140,590,120,40);
        iSetColor(0,0,0);
        iFilledRectangle(10,730,100,50);                                                                // Hall of fame Page
        iSetColor(255,255,255);
        iRectangle(hm*200+140,590,120,40);
        iRectangle(10,730,100,50);
        iText(150,600,"1 MINUTE",GLUT_BITMAP_HELVETICA_18);
        iText(350,600,"2 MINUTES",GLUT_BITMAP_HELVETICA_18);
        iText(550,600,"3 MINUTES",GLUT_BITMAP_HELVETICA_18);
        iText(750,600,"4 MINUTES",GLUT_BITMAP_HELVETICA_18);
        iText(950,600,"5 MINUTES",GLUT_BITMAP_HELVETICA_18);
        iText(25,750,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0, 0, 0);
        hon hi;
        int nhscore=0,mhscore[10],phscore;
        char hscore[10]={0};
        fs = fopen(high_score[hm],"r");
        fname = fopen(high_name[hm],"r");
        for(int i=0;i<10;i++){
            fgets(hi.name,25,fname);
            int z = strlen(hi.name);
            hi.name[z-1] = '\0';
            iText(475,490-i*35,hi.name,GLUT_BITMAP_HELVETICA_18);
        }
        for(int j=0;j<10;j++){
            phscore = 0;
            fscanf(fs,"%d",&hi.sc);
            int tscore = hi.sc;
            if(tscore == 0){
                hscore[phscore] = '0';
                hscore[phscore+1] = '\0';
                iText(750,490-j*35,hscore,GLUT_BITMAP_HELVETICA_18);
            }
            else if(tscore > 0)
            {
                for(nhscore=0; tscore!=0; nhscore++)
                {
                    mhscore[nhscore] = tscore%10;
                    tscore = tscore/10;
                }
                for(nhscore=nhscore-1; nhscore>=0; nhscore--)
                {
                    hscore[phscore] =  mhscore[nhscore] + '0';
                    phscore++;
                }
                hscore[phscore] = '\0';
                iText(750,490-j*35,hscore,GLUT_BITMAP_HELVETICA_18);
            }
            else
            {
                tscore = tscore*(-1);
                for(nhscore=0; tscore!=0; nhscore++)
                {
                    mhscore[nhscore] = tscore%10;
                    tscore = tscore/10;
                }
                for(nhscore=nhscore-1; nhscore>=0; nhscore--)
                {
                    hscore[phscore] =  mhscore[nhscore] + '0';
                    phscore++;
                }
                hscore[phscore] = '\0';
                iText(750,490-j*35,hscore,GLUT_BITMAP_HELVETICA_18);
                iText(740,490-j*35,"-",GLUT_BITMAP_HELVETICA_18);
            }
        }
        fclose(fs);
        fclose(fname);
	}
	if(startmenu == 6){
        iShowBMP(0,0,gameover);
        iSetColor(130,130,130);
        iFilledRectangle(340,390,150,40);
        iFilledRectangle(790,390,160,40);
        iSetColor(255,255,255);
        iRectangle(340,390,150,40);
        iRectangle(790,390,160,40);                                                                                             // This Page is shown if There is no previous saved game
        iText(180,500,"THERE IS NO PREVIOUS SAVED FILE TO CONTINUE . LAST GAME WAS FINISHED.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(350,400,"NEW GAME",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(800,400,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
	}
    iShowBMP2(1230,650,music_icon,0);
    if(!music_on){
        iSetColor(0,0,0);
        iFilledPolygon(xm,ym,4);
    }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse iShowBMP(0,0,bg);pointer is.
*/
void iMouseMove(int mx, int my)
{
       if(my<300 && mx>=basket_x && mx<=basket_x+150 && mx>=75 && mx<=1225 && startmenu==1 && !pause_time)
            basket_x = mx-75;                                                                                                   // Mouse drag for basket
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
        if(mx>1230 && mx<1280 && my>650 && my<700){
            if(music_on){
                music_on = 0;
                PlaySound(0,0,0);
            }
            else{                                                                                                                   // Toggle Music
                music_on = 1;
                PlaySound(sound, NULL, SND_ASYNC);
            }
        }
        if(!startmenu){
            if(mx>550 && mx<750 && my>600 && my<690){
                pause_time=1;
                fp = fopen("continue.txt","r");
                fscanf(fp,"%lf%lf%lf%lf",&dy_e,&t,&basket_x,&c);
                fscanf(fp,"%d%d%d%d%d%d%d%d",&hen_n,&egg_c,&score,&mi,&sec,&startmenu,&time_counter,&gover);                        // Continue Button
                fclose(fp);
                if(gover)
                    startmenu = 6;
            }
            if(mx>550 && mx<750 && my>470 && my<560){
                startmenu = 3;
                dy0=650;t=0;g_e=9.8;basket_x=675;basket_y=0;c=0;gover=0;win=0;
                up = 5;low= 0;score=0;mi;sec=0;pause_time=0;time_counter=1;
            }                                                                                                                       //New game
            if(mx>550 && mx<750 && my>340 && my<430){
                startmenu = 5;
            }                                                                                                                      // Instructions
            if(mx>550 && mx<750 && my>210 && my<300){
                startmenu = 4;                                                                                                     // Hall of fame
                startmenu_state = 0;
            }
            if(mx>550 && mx<750 && my>80 &&my<170){
                exit(0);                                                                                                            // Exit
            }
        }
        if(startmenu == 1){
            if(mx>1230 && mx<1280 && my>730 && my<780 && !pause_time){
                pause_time=1;
               // fp = fopen("continue.txt","w");
                //fprintf(fp,"%lf\n%lf\n%lf\n%lf\n",dy_e,t,basket_x,c);
                //fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d",hen_n,egg_c,score,mi,sec,startmenu,time_counter);                      Pause menu
                //fclose(fp);
            }
            if(mx>20 && mx<700 && my>730 && my<780 && !pause_time){
                //fp = fopen("continue.txt","w");
                //fprintf(fp,"%lf\n%lf\n%lf\n%lf\n",dy_e,t,basket_x,c);
                //fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d",hen_n,egg_c,score,mi,sec,startmenu,time_counter);
                //fclose(fp);                                                                                                     Exit from Gamepage
                exit(0);
            }
            if(mx>650 && mx<725 && my>500 && my<575 && pause_time){
                pause_time=0;                                                                                                      // Resume
            }
            if(mx>650 && mx<725 && my>350 && my<425 && pause_time){
                startmenu = 0;                                                                                                     // Main menu
            }
            if(mx>650 && mx<725 && my>200 && my<275 && pause_time){
                exit(0);                                                                                                           // Exit
            }

        }
        if(startmenu == 2){
            if(mx>600 && mx<750 && my>200 && my<250){
                highscore();
                startmenu = 0;                                                                                                     // Name submit
                index = 0;
                hon_nam[index] = '\0';
            }
        }
        if(startmenu == 3){
            if(mx>860 && mx<885 && my>375 &&my<400 && time_counter<5)
                time_counter++;                                                                                                   //time increase
            if(mx>860 && mx<885 && my>350 && my<375 && time_counter>1)
                time_counter--;                                                                                                   //time decrease
            if(mx>10 && mx<110 && my>730 && my<780)
                startmenu=0;                                                                                                      //Main menu back
            if(mx>600 && mx<750 && my>250 && my<300)
                startmenu=1;                                                                                                      //Game Page
            mi = time_counter;
        }
        if(startmenu == 4){
            if(mx>10 && mx<110 && my>730 && my<780)
                startmenu=0;
            if(mx>490 && mx<610 && my>640 && my<680 )
                startmenu_state=0;                                                                                               // Instructions Page Control
            if(mx>690 && mx<810 && my>640 && my<680 )
                startmenu_state=1;
        }
        if(startmenu == 5){
            if(mx>140 && mx<250 && my>590 && my<630)
                hm = 0;
            if(mx>340 && mx<450 && my>590 && my<630)
                hm = 1;
            if(mx>540 && mx<650 && my>590 && my<630)                                                                             // Hall Of Frame Control
                hm = 2;
            if(mx>740 && mx<850 && my>590 && my<630)
                hm = 3;
            if(mx>940 && mx<1050 && my>590 && my<630)
                hm = 4;
            if(mx>10 && mx<110 && my>730 && my<780)
                startmenu=0;
        }
        if(startmenu == 6){
            if(mx>340 && mx<490 && my>390 && my<430){
                startmenu = 3;
                dy0=650;t=0;g_e=9.8;basket_x=675;basket_y=0;c=0;gover=0;win=0;
                up = 5;low= 0;score=0;mi;sec=0;pause_time=0;time_counter=1;
            }
            if(mx>790 && mx<950 && my>390 && my<430)
                startmenu = 0;
        }
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(startmenu == 3){
        if(key == (char)13 ){
            startmenu=1;
            mi=time_counter;                                                                //   time submission by enter
        }
    }
    if(startmenu == 2){
        if(index < 20)
        {
            if(key == (char)13 )
            {
                highscore();
                startmenu = 0;                                                         // Gameover name writing
                index = 0;
                hon_nam[index] = '\0';
            }
            else if(key == '\b' && index!=0 )
            {
                index--;
                hon_nam[index] = '\0';
            }
            else
            {
                hon_nam[index] = key;
                index++;
                hon_nam[index] = '\0';
            }
        }
    }
    if( key == 'm' && startmenu != 2){
        if(music_on){
            music_on = 0;
            PlaySound(0,0,0);                                                       // toggle music with keyboard 'm'
        }
        else{
            music_on = 1;
            PlaySound(sound, NULL, SND_ASYNC);
        }
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
    if(startmenu==1 && !pause_time)
    {
        if(key == GLUT_KEY_LEFT && basket_x>= 25 )
        {
            basket_x-=25;
        }
        if(key == GLUT_KEY_RIGHT && basket_x < 1150 )                                   // Basket move with keys
        {
            basket_x+=25;
        }
    }
    if(startmenu ==3 ){
        if(key == GLUT_KEY_UP && time_counter<5 )
        {
            time_counter++;
        }
        if(key == GLUT_KEY_DOWN && time_counter>1 )                               // time change in duration Page
        {
            time_counter--;
        }
    }

	//place your codes for other keys here
}

void catch_(){
    if(startmenu==1 && !pause_time)
    {
        t+=0.2;
        if(dy_e<=0)
        {
            srand(time(0));
            egg_c = (rand()%(3-0+1))+0;                                                     // egg dropping
            hen_n = (rand()%(up-low+1))+low;
            t=0;
            c=0;
        }
        dy_e=dy0-(0.5*g_e*t*t);
        if(hen_n*200+100>=(basket_x+10)&&hen_n*200+100<=(basket_x+130)&&basket_y<=dy_e&&(basket_y+80)>=dy_e&&!c)
        {
            if(!egg_c)
                score+=1;
            else if(egg_c==1)
                score+=10;                                                              // score updating
            else if(egg_c==2)
                score+=5;
            else
                score-=10;
            c=1;
           // printf("%d\n",score);
        }
    }
}

void save(){
    if(startmenu==2){
        gover = 1;
        fp = fopen("continue.txt","w");
        fprintf(fp,"%lf\n%lf\n%lf\n%lf\n",dy_e,t,basket_x,c);
        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",hen_n,egg_c,score,mi,sec,startmenu,time_counter,gover);                                     // Game save
        fclose(fp);
    }
   else if(startmenu==1 && !pause_time){
        fp = fopen("continue.txt","w");
        fprintf(fp,"%lf\n%lf\n%lf\n%lf\n",dy_e,t,basket_x,c);
        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",hen_n,egg_c,score,mi,sec,startmenu,time_counter,gover);
        fclose(fp);
   }
}

void scor_(){
    if(startmenu==1 && !pause_time)
    {
        int mscore[10],n=0;
        int iscore,d,r;
        d=score;
        if(d==0)
        {
            p[n]='0';
            p[n+1]='\0';
        }
        else if(d>0)                                                                                                                           // showing score on menu
        {
            for(iscore=0; d!=0; iscore++)
            {
                r = d%10;
                d = d/10;
                mscore[iscore] = r;
            }
            for(int j=iscore-1; j>=0; j--)
            {
                p[n] = mscore[j] + '0';
                n++;
            }
            p[n]='\0';
        }
        else
        {
            d = d*(-1);
            for(iscore=0; d!=0; iscore++)
            {
                r = d%10;
                d = d/10;
                mscore[iscore] = r;
            }
            for(int j=iscore-1; j>=0; j--)
            {
                p[n] = mscore[j] + '0';
                n++;
            }
            p[n]='\0';
        }
    }
}

void timer(){
    if(startmenu==1 && !pause_time){
        if(mi==-1&&sec==59){
            startmenu = 2;
            w_l();
        }
        tim[0] = mi/10 + '0';
        tim[1] = mi%10 + '0';
        tim[2] = ':';
        tim[3] = sec/10 + '0';
        tim[4] = sec%10 + '0';
        tim[5] = '\0';                                                                                              // Timer
        if(sec==0){
            mi=mi-1;
            sec=60;
        }
        sec--;
    }
}

void highscore(){
    fs = fopen(high_score[time_counter-1],"r");
    fname = fopen(high_name[time_counter-1],"r");
    hon X[12];
    int i=0,_max,n=0,j,r=0;
    while(!feof(fs)){
        fscanf(fs,"%d",&X[i].sc);
        fgets(X[i].name,25,fname);
        i++;
        n++;
    }
    strcpy(X[i].name,hon_nam);
    int z = strlen(X[i].name);
    X[i].name[z] = '\n';
    X[i].name[z+1] = '\0';
    X[i].sc = score;
    n++;
    for(i=n;i>0;i--){
        _max=0;                                                                                 // updating high scores
        for(j=0;j<i;j++){
            if(X[j].sc<X[_max].sc)
                _max=j;
        }
        hon t = X[_max];
        X[_max] = X[i-1];
        X[i-1] = t;
    }
    fclose(fs);
    fclose(fname);
    fs = fopen(high_score[time_counter-1],"w");
    fname = fopen(high_name[time_counter-1],"w");
    if(n>10)
        n=10;
    for(i=0;i<n;i++){
        fprintf(fs,"%d",X[i].sc);
        if(i!=n-1)
            fprintf(fs,"\n");
    }
    for(i=0;i<n;i++){
        fprintf(fname,"%s",X[i].name);
    }
    fclose(fname);
    fclose(fs);
}

void w_l(){
    fs = fopen(high_score[time_counter-1],"r");
    hon X[12];
    int i=0,n=0;
    while(!feof(fs)){                                                                                       //win or lose
        fscanf(fs,"%d",&X[i].sc);
        fgets(X[i].name,25,fname);
        i++;
        n++;
    }
    for(i=0;i<n;i++){
        if(score>=X[i].sc){
            win = 1;
            break;
        }
    }
    fclose(fs);
}

int main()
{
//DWORD dwError = GetLastError();
//place your own initialization codes here.
    srand(time(0));
    egg_c = (rand()%(2-0+1))+0;
    hen_n = (rand()%(up-low+1))+low;
	iSetTimer(20, catch_);
	iSetTimer(20, scor_);
	iSetTimer(20, save);
	iSetTimer(1000,timer);
	if(music_on){
        PlaySound(sound, NULL, SND_ASYNC);
	}
	iInitialize(1300, 800, "Catch the egg");
	return 0;
}

