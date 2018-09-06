

#include <cstdlib>                      // standard definitions
#include <iostream>                     // C++ I/O
#include <cstdio>                       // C I/O (for sprintf) 
#include <cmath>                        // standard definitions
#include <Windows.h>
#include <MMSystem.h>

#include <GL/glut.h>                    // GLUT
#include <GL/glu.h>                     // GLU
#include <GL/gl.h>                      // OpenGL
#include <process.h>


using namespace std;                    // make std accessible

//-----------------------------------------------------------------------
// Global data
//-----------------------------------------------------------------------

//GLint TIMER_DELAY = 10000;                      // timer delay (10 seconds)
GLint TIMER_DELAY = 10;
int sure_koyun=0;
GLfloat RED_RGB[] = {1.0, 0.0, 0.0};            // drawing colors
GLfloat BLUE_RGB[] = {0.0, 0.0, 1.0};
int mx=0;
int my=0;
int m1;
int m2;


double kopek_a=0.0;
double kopek_b=1.0;

double kurt_a1=0.1;
double kurt_b1=0.6;
double kurt_hizi=0.3;
double kurt_a2=0.4;
double kurt_b2=0.7;

int kontrol=0;
double yer_degisikligi = 0.01; 
double kuzu1_x = 0.05; double kuzu1_y = 0.05; 
double kuzu2_x = 0.25; double kuzu2_y = 0.95; 
double kuzu3_x = 0.45; double kuzu3_y = 0.25; 
double kuzu4_x = 0.65; double kuzu4_y = 0.65; 
double kuzu5_x = 0.85; double kuzu5_y = 0.45; 
double kuzu6_x = 0.95; double kuzu6_y = 0.85;

double rasgele1_x = 0.05; double rasgele1_y = 0.05; 
double rasgele2_x = 0.25; double rasgele2_y = 0.95; 
double rasgele3_x = 0.45; double rasgele3_y = 0.25; 
double rasgele4_x = 0.65; double rasgele4_y = 0.65; 
double rasgele5_x = 0.85; double rasgele5_y = 0.45; 
double rasgele6_x = 0.95; double rasgele6_y = 0.85;

double koyun_hizi_1=0.2;
double koyun_hizi_2=0.2;
double koyun_hizi_3=0.2;
double koyun_hizi_4=0.2;
double koyun_hizi_5=0.2;
double koyun_hizi_6=0.2;

double kuzu_koordinat[6][2];

int koyun_yak=50;
int ses_yak=200;
double gunes= 0.98;
double renk= 0.5;

int dizi[10000][2] = {0};
int sayac=0;
int sayac2=0;
double zaman_tut=0.0;

bool mouseleftdown = false;
bool kopek_hav = false;

GLvoid *font_style = GLUT_BITMAP_HELVETICA_18;

//-----------------------------------------------------------------------
//  Global variables
//-----------------------------------------------------------------------
static bool isReversed = false;                 // draw reversed colors?



void myReshape(int w, int h) {
    glViewport (0, 0, w, h);    // update the viewport
    m1=w;
	m2=h;
	glMatrixMode(GL_PROJECTION);                // update projection
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);             // map unit square to viewport
    glMatrixMode(GL_MODELVIEW);
    //glutPostRedisplay();                        // request redisplay
}

unsigned __stdcall dog(void *data)
{
    PlaySound(TEXT("D:/dog1.wav"), NULL, SND_FILENAME);	
    return 0;
}

unsigned __stdcall sheep(void *data)
{
    PlaySound(TEXT("D:/sheep1.wav"), NULL, SND_FILENAME);
    return 0;
}
                                                // draw diamond and rectangle
void drawObjects() {


		sure_koyun +=TIMER_DELAY;
		
		if(fmod((double)sure_koyun,2000.0) == 0.0)
		{
			_beginthreadex(NULL, 0, sheep, NULL, 0, NULL);
		}

		
	
		glBegin(GL_POLYGON);        // ahýr
		glColor3d(0.1,0.4,0.1);	
		glVertex2d(0.6, 0.5);		
        glVertex2d(0.6, 1.0);
		glVertex2d(1.0, 1.0);
        glVertex2d(1.0, 0.5);        
        glEnd();
		

		if(gunes > 0.02)gunes-=(double)1/(7500);
		else exit(0);
		glPointSize(30);		// güneþ
	    glBegin(GL_POINTS);		
		glColor3d(1,renk,0);
		if(gunes<0.5)renk-=(double)1/(1875);
		else renk+=(double)1/(1875);
		glVertex2d(gunes , 0.98);
		glEnd();

		glColor3d(0,0,0);		
		glRasterPos2d (gunes-0.01 , 0.98-0.01);
		glutBitmapCharacter(font_style,'G');
		
		int kuzu_sayac=6;
		for(int w=0 ; w<6;w++)
		if(kuzu_koordinat[w][0]==-2)
			--kuzu_sayac;

		cout<< kuzu_sayac<<endl;

		glColor3d(0,0,0);		
		glRasterPos2d (0.05 , 0.97);
		glutBitmapCharacter(font_style,'K');
		glRasterPos2d (0.07 , 0.97);
		glutBitmapCharacter(font_style,'A');
		glRasterPos2d (0.09 , 0.97);
		glutBitmapCharacter(font_style,'L');
		glRasterPos2d (0.11 , 0.97);
		glutBitmapCharacter(font_style,'A');
		glRasterPos2d (0.13 , 0.97);
		glutBitmapCharacter(font_style,'N');
		glRasterPos2d (0.15 , 0.97);
		glutBitmapCharacter(font_style,':');
		if(kuzu_sayac == 0)
		{
			glRasterPos2d (0.17, 0.97);
			glutBitmapCharacter(font_style,'0');
		}
		if(kuzu_sayac == 1)
		{
			glRasterPos2d (0.17, 0.97);
			glutBitmapCharacter(font_style,'1');
		}
		if(kuzu_sayac == 2)
		{
			glRasterPos2d (0.17, 0.97);
			glutBitmapCharacter(font_style,'2');
		}
		if(kuzu_sayac == 3)
		{
			glRasterPos2d (0.17, 0.97);
			glutBitmapCharacter(font_style,'3');
		}
		if(kuzu_sayac == 4)
		{
			glRasterPos2d (0.17, 0.97);
			glutBitmapCharacter(font_style,'4');
		}
		if(kuzu_sayac == 5)
		{
			glRasterPos2d (0.17, 0.97);
			glutBitmapCharacter(font_style,'5');
		}
		if(kuzu_sayac == 6)
		{
			glRasterPos2d (0.17, 0.97);
			glutBitmapCharacter(font_style,'6');
		}
		


		glPointSize(50);		// hav hav butonu
	    glBegin(GL_POINTS);		
		glColor3d(0.6,0.6,0.6);		
		glVertex2d((double)(m1-30)/m1 , 1-(double)(m2-30)/m2);
		glEnd();
		glColor3d(0,0,0);		
		glRasterPos2d ((double)(m1-30)/m1-0.01 , 1-(double)(m2-30)/m2-0.01);
		glutBitmapCharacter(font_style,'H');
																										//kuzular

		if(kuzu1_x >= 0.95 || kuzu1_x <= 0.05 || kuzu1_y >= 0.95 || kuzu1_y <= 0.05 )					//kuzu1
		{
			rasgele1_x = ( rand() % 11 ) * 0.1;
			rasgele1_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_1 = 0.1;
		}

		if(fabs(rasgele1_x-kuzu1_x) < (double)3/m1  &&  fabs(rasgele1_y-kuzu1_y) < (double)3/m1)		
		{
			rasgele1_x = ( rand() % 11 ) * 0.1;
			rasgele1_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_1 = 0.1;
		}

		if(fabs(kopek_a-kuzu1_x) < (double)koyun_yak/m1  &&  fabs(kopek_b-kuzu1_y) < (double)koyun_yak/m2)
		{
			rasgele1_x = (kuzu1_x-kopek_a) + kuzu1_x;
			rasgele1_y = (kuzu1_y-kopek_b) + kuzu1_y;
			koyun_hizi_1 = 1;
		}

		if(   (   fabs(kopek_a-kuzu1_x) < (double)ses_yak/m1  &&  fabs(kopek_b-kuzu1_y) < (double)ses_yak/m2   )  &&  kopek_hav  )
		{
			rasgele1_x = (kuzu1_x-kopek_a) + kuzu1_x;
			rasgele1_y = (kuzu1_y-kopek_b) + kuzu1_y;
			koyun_hizi_1 = 1;
			/*kopek_hav=false;*/
		}
		

		if(kuzu1_x < rasgele1_x)
		{
			kuzu1_x += (double)koyun_hizi_1/m1;
		}
		if(kuzu1_x > rasgele1_x)
		{
			kuzu1_x -= (double)koyun_hizi_1/m1;
		}
		
		if(kuzu1_y < rasgele1_y)
		{
			kuzu1_y += (double)koyun_hizi_1/m2;
		}
		if(kuzu1_y > rasgele1_y)
		{
			kuzu1_y -= (double)koyun_hizi_1/m2;
		}

		if(kuzu2_x >= 0.95 || kuzu2_x <= 0.05 || kuzu2_y >= 0.95 || kuzu2_y <= 0.05 )					//kuzu2
		{
			rasgele2_x = ( rand() % 11 ) * 0.1;
			rasgele2_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_2 = 0.1;
		}

		if(fabs(rasgele2_x-kuzu2_x) < (double)3/m1  &&  fabs(rasgele2_y-kuzu2_y) < (double)3/m1)	
		{
			rasgele2_x = ( rand() % 11 ) * 0.1;
			rasgele2_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_2 = 0.1;
		}

		if(fabs(kopek_a-kuzu2_x) < (double)koyun_yak/m1  &&  fabs(kopek_b-kuzu2_y) < (double)koyun_yak/m2)
		{
			rasgele2_x = (kuzu2_x-kopek_a) + kuzu2_x;
			rasgele2_y = (kuzu2_y-kopek_b) + kuzu2_y;
			koyun_hizi_2 = 1;
		}

		if(   (fabs(kopek_a-kuzu2_x) < (double)ses_yak/m1  &&  fabs(kopek_b-kuzu2_y) < (double)ses_yak/m2   )   && kopek_hav)
		{
			rasgele2_x = (kuzu2_x-kopek_a) + kuzu2_x;
			rasgele2_y = (kuzu2_y-kopek_b) + kuzu2_y;
			koyun_hizi_2 = 1;
			//kopek_hav=false;
		}
		
		if(kuzu2_x < rasgele2_x)
		{
			kuzu2_x += (double)koyun_hizi_2/m1;
		}
		if(kuzu2_x > rasgele2_x)
		{
			kuzu2_x -= (double)koyun_hizi_2/m1;
		}
		
		if(kuzu2_y < rasgele2_y)
		{
			kuzu2_y += (double)koyun_hizi_2/m2;
		}
		if(kuzu2_y > rasgele2_y)
		{
			kuzu2_y -= (double)koyun_hizi_2/m2;
		}

		if(kuzu3_x >= 0.95 || kuzu3_x <= 0.05 || kuzu3_y >= 0.95 || kuzu3_y <= 0.05 )					//kuzu3
		{
			rasgele3_x = ( rand() % 11 ) * 0.1;
			rasgele3_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_3 = 0.1;
		}

		if(fabs(rasgele3_x-kuzu3_x) < (double)3/m1  &&  fabs(rasgele3_y-kuzu3_y) < (double)3/m1)	
		{
			rasgele3_x = ( rand() % 11 ) * 0.1;
			rasgele3_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_3 = 0.1;
		}

		if(fabs(kopek_a-kuzu3_x) < (double)koyun_yak/m1  &&  fabs(kopek_b-kuzu3_y) < (double)koyun_yak/m2)
		{
			rasgele3_x = (kuzu3_x-kopek_a) + kuzu3_x;
			rasgele3_y = (kuzu3_y-kopek_b) + kuzu3_y;
			koyun_hizi_3 = 1;
		}

		if(  (   fabs(kopek_a-kuzu3_x) < (double)ses_yak/m1  &&  fabs(kopek_b-kuzu3_y) < (double)ses_yak/m2   )  &&  kopek_hav)
		{
			rasgele3_x = (kuzu3_x-kopek_a) + kuzu3_x;
			rasgele3_y = (kuzu3_y-kopek_b) + kuzu3_y;
			koyun_hizi_3 = 1;
			//kopek_hav = false;
		}

		if(kuzu3_x < rasgele3_x)
		{
			kuzu3_x += (double)koyun_hizi_3/m1;
		}
		if(kuzu3_x > rasgele3_x)
		{
			kuzu3_x -= (double)koyun_hizi_3/m1;
		}
		
		if(kuzu3_y < rasgele3_y)
		{
			kuzu3_y += (double)koyun_hizi_3/m2;
		}
		if(kuzu3_y > rasgele3_y)
		{
			kuzu3_y -= (double)koyun_hizi_3/m2;
		}

		if(kuzu4_x >= 0.95 || kuzu4_x <= 0.05 || kuzu4_y >= 0.95 || kuzu4_y <= 0.05 )					//kuzu4
		{
			rasgele4_x = ( rand() % 11 ) * 0.1;
			rasgele4_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_4 = 0.1;
		}

		if(fabs(rasgele4_x-kuzu4_x) < (double)3/m1  &&  fabs(rasgele4_y-kuzu4_y) < (double)3/m1)		
		{
			rasgele4_x = ( rand() % 11 ) * 0.1;
			rasgele4_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_4 = 0.1;
		}

		if(fabs(kopek_a-kuzu4_x) < (double)koyun_yak/m1  &&  fabs(kopek_b-kuzu4_y) < (double)koyun_yak/m2)
		{
			rasgele4_x = (kuzu4_x-kopek_a) + kuzu4_x;
			rasgele4_y = (kuzu4_y-kopek_b) + kuzu4_y;
			koyun_hizi_4 = 1;
		}
		if(  (  fabs(kopek_a-kuzu4_x) < (double)ses_yak/m1  &&  fabs(kopek_b-kuzu4_y) < (double)ses_yak/m2   )   &&   kopek_hav)
		{
			rasgele4_x = (kuzu4_x-kopek_a) + kuzu4_x;
			rasgele4_y = (kuzu4_y-kopek_b) + kuzu4_y;
			koyun_hizi_4 = 1;
			//kopek_hav = false;
		}

		if(kuzu4_x < rasgele4_x)
		{
			kuzu4_x += (double)koyun_hizi_4/m1;
		}
		if(kuzu4_x > rasgele4_x)
		{
			kuzu4_x -= (double)koyun_hizi_4/m1;
		}
		
		if(kuzu4_y < rasgele4_y)
		{
			kuzu4_y += (double)koyun_hizi_4/m2;
		}
		if(kuzu4_y > rasgele4_y)
		{
			kuzu4_y -= (double)koyun_hizi_4/m2;
		}

		if(kuzu5_x >= 0.95 || kuzu5_x <= 0.05 || kuzu5_y >= 0.95 || kuzu5_y <= 0.05 )					//kuzu5
		{
			rasgele5_x = ( rand() % 11 ) * 0.1;
			rasgele5_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_5 = 0.1;
		}

		if(fabs(rasgele5_x-kuzu5_x) < (double)3/m1  &&  fabs(rasgele5_y-kuzu5_y) < (double)3/m1)		
		{
			rasgele5_x = ( rand() % 11 ) * 0.1;
			rasgele5_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_5 = 0.1;
		}

		if(fabs(kopek_a-kuzu5_x) < (double)koyun_yak/m1  &&  fabs(kopek_b-kuzu5_y) < (double)koyun_yak/m2)
		{
			rasgele5_x = (kuzu5_x-kopek_a) + kuzu5_x;
			rasgele5_y = (kuzu5_y-kopek_b) + kuzu5_y;
			koyun_hizi_5 = 1;
		}

		if(  (  fabs(kopek_a-kuzu5_x) < (double)ses_yak/m1  &&  fabs(kopek_b-kuzu5_y) < (double)ses_yak/m2  )   &&   kopek_hav)
		{
			rasgele5_x = (kuzu5_x-kopek_a) + kuzu5_x;
			rasgele5_y = (kuzu5_y-kopek_b) + kuzu5_y;
			koyun_hizi_5 = 1;
			//kopek_hav= false;
		}

		if(kuzu5_x < rasgele5_x)
		{
			kuzu5_x += (double)koyun_hizi_5/m1;
		}
		if(kuzu5_x > rasgele5_x)
		{
			kuzu5_x -= (double)koyun_hizi_5/m1;
		}
		
		if(kuzu5_y < rasgele5_y)
		{
			kuzu5_y += (double)koyun_hizi_5/m2;
		}
		if(kuzu5_y > rasgele5_y)
		{
			kuzu5_y -= (double)koyun_hizi_5/m2;
		}

		if(kuzu6_x >= 0.95 || kuzu6_x <= 0.05 || kuzu6_y >= 0.95 || kuzu6_y <= 0.05 )					//kuzu6
		{
			rasgele6_x = ( rand() % 11 ) * 0.1;
			rasgele6_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_6 = 0.1;
		}

		if(fabs(rasgele6_x-kuzu6_x) < (double)3/m1  &&  fabs(rasgele6_y-kuzu6_y) < (double)3/m1)
		{
			rasgele6_x = ( rand() % 11 ) * 0.1;
			rasgele6_y = ( rand() % 11 ) * 0.1;
			koyun_hizi_6 = 0.1;
		}

		if(fabs(kopek_a-kuzu6_x) < (double)koyun_yak/m1  &&  fabs(kopek_b-kuzu6_y) < (double)koyun_yak/m2)
		{
			rasgele6_x = (kuzu6_x-kopek_a) + kuzu6_x;
			rasgele6_y = (kuzu6_y-kopek_b) + kuzu6_y;
			koyun_hizi_6 = 1;
		}

		if(   (  fabs(kopek_a-kuzu6_x) < (double)ses_yak/m1  &&  fabs(kopek_b-kuzu6_y) < (double)ses_yak/m2   )  &&  kopek_hav)
		{
			rasgele6_x = (kuzu6_x-kopek_a) + kuzu6_x;
			rasgele6_y = (kuzu6_y-kopek_b) + kuzu6_y;
			koyun_hizi_6 = 1;
			//kopek_hav = false;
		}

		if(kuzu6_x < rasgele6_x)
		{
			kuzu6_x += (double)koyun_hizi_6/m1;
		}
		if(kuzu6_x > rasgele6_x)
		{
			kuzu6_x -= (double)koyun_hizi_6/m1;
		}
		
		if(kuzu6_y < rasgele6_y)
		{
			kuzu6_y += (double)koyun_hizi_6/m2;
		}
		if(kuzu6_y > rasgele6_y)
		{
			kuzu6_y -= (double)koyun_hizi_6/m2;
		}

		kopek_hav = false;

		glPointSize(20); 
		glBegin(GL_POINTS); 
		glColor3d(1.0,1.0,1.0);
		if(kuzu_koordinat[0][0] != -2)
		{
		glVertex2d(kuzu1_x,kuzu1_y);
		}
		if(kuzu_koordinat[1][0] != -2)
		{
		glVertex2d(kuzu2_x,kuzu2_y); 
		}		 
		if(kuzu_koordinat[2][0] != -2)
		{
		glVertex2d(kuzu3_x,kuzu3_y); 
		}
		if(kuzu_koordinat[3][0] != -2)
		{
		glVertex2d(kuzu4_x,kuzu4_y);
		}
		if(kuzu_koordinat[4][0] != -2)
		{
		glVertex2d(kuzu5_x,kuzu5_y);
		}
		if(kuzu_koordinat[5][0] != -2)
		{
		glVertex2d(kuzu6_x,kuzu6_y); 
		}
		glEnd();

		if(kuzu_koordinat[0][0] != -2){
			kuzu_koordinat[0][0] = kuzu1_x; kuzu_koordinat[0][1] = kuzu1_y;
		}
		if(kuzu_koordinat[1][0] != -2){
		kuzu_koordinat[1][0] = kuzu2_x; kuzu_koordinat[1][1] = kuzu2_y;
		}
		if(kuzu_koordinat[2][0] != -2){
		kuzu_koordinat[2][0] = kuzu3_x; kuzu_koordinat[2][1] = kuzu3_y;
		}
		if(kuzu_koordinat[3][0] != -2){
		kuzu_koordinat[3][0] = kuzu4_x; kuzu_koordinat[3][1] = kuzu4_y;
		}
		if(kuzu_koordinat[4][0] != -2){
		kuzu_koordinat[4][0] = kuzu5_x; kuzu_koordinat[4][1] = kuzu5_y;
		}
		if(kuzu_koordinat[5][0] != -2){
		kuzu_koordinat[5][0] = kuzu6_x; kuzu_koordinat[5][1] = kuzu6_y;
		}

		glColor3d(0,0,0);	
		if(kuzu_koordinat[0][0] != -2)
		{
		glRasterPos2d (kuzu1_x-0.01 , kuzu1_y-0.01);
		glutBitmapCharacter(font_style,'S');
		}
		if(kuzu_koordinat[1][0] != -2)
		{
		glRasterPos2d (kuzu2_x-0.01 , kuzu2_y-0.01);
		glutBitmapCharacter(font_style,'S');
		}
		if(kuzu_koordinat[2][0] != -2)
		{
		glRasterPos2d (kuzu3_x-0.01 , kuzu3_y-0.01);
		glutBitmapCharacter(font_style,'S');
		}
		if(kuzu_koordinat[3][0] != -2)
		{
		glRasterPos2d (kuzu4_x-0.01 , kuzu4_y-0.01);
		glutBitmapCharacter(font_style,'S');
		}
		if(kuzu_koordinat[4][0] != -2)
		{
		glRasterPos2d (kuzu5_x-0.01 , kuzu5_y-0.01);
		glutBitmapCharacter(font_style,'S');
		}
		if(kuzu_koordinat[5][0] != -2)
		{
		glRasterPos2d (kuzu6_x-0.01 , kuzu6_y-0.01);
		glutBitmapCharacter(font_style,'S');
		}																	//kuzu bitir



	for(int i=sayac2 ; i<sayac-1 ; i++){		// kopeg yörünge
		glLineWidth(3);
		glBegin(GL_LINE_STRIP);
		glColor3d(1.0,1.0,1.0);
		glVertex2d((double)dizi[i][0]/m1 , 1-(double)dizi[i][1]/m2);
		glVertex2d((double)dizi[i+1][0]/m1 , 1-(double)dizi[i+1][1]/m2);
		glEnd();
	}

	glPointSize(50);
	glBegin(GL_POINTS);
	glColor3d(0.0,0.0,0.0);
	glVertex2d(kopek_a , kopek_b);	
    glEnd();
	glColor3d(1,1,1);
	glRasterPos2d (kopek_a-0.01 , kopek_b-0.01);
	glutBitmapCharacter(font_style,'D');

																			// kurt1
	int i1=0;
	int en_yakin1=-1;
	double uzaklik1=1;
	for(i1=0;i1<6;i1++)
	{
		if(kuzu_koordinat[i1][0] != -2)
		{

		if(kuzu_koordinat[i1][0] < 0.6 || kuzu_koordinat[i1][1] < 0.5)
		{
		if( uzaklik1 >  sqrt(   pow( kurt_a1-kuzu_koordinat[i1][0] , 2 ) + pow( kurt_b1-kuzu_koordinat[i1][1] , 2 )   )   )
		{
			uzaklik1=sqrt(   pow( kurt_a1-kuzu_koordinat[i1][0] , 2 ) + pow( kurt_b1-kuzu_koordinat[i1][1] , 2 )   );
			en_yakin1= i1 ;
		}
		}
		}
	}
				
	if(en_yakin1 != -1)
	{
		if(kurt_a1 < kuzu_koordinat[en_yakin1][0])
		{
			kurt_a1 += (double)(kurt_hizi)/m1;
		}
		if(kurt_a1 > kuzu_koordinat[en_yakin1][0])
		{
			kurt_a1 -= (double)(kurt_hizi)/m1;
		}
		
		if(kurt_b1 < kuzu_koordinat[en_yakin1][1])
		{
			kurt_b1 += (double)(kurt_hizi)/m2;
		}
		if(kurt_b1 > kuzu_koordinat[en_yakin1][1])
		{
			kurt_b1 -= (double)(kurt_hizi)/m2;
		}


		if(fabs(kurt_a1 - kuzu_koordinat[en_yakin1][0]) < (double)3/m1 && fabs(kurt_b1 - kuzu_koordinat[en_yakin1][1]) < (double)3/m1)
		{
			kuzu_koordinat[en_yakin1][0]=-2;
		}
	}

	glPointSize(50);									
	glBegin(GL_POINTS);		
	glColor3d(1,0,0);		
	glVertex2d(kurt_a1 , kurt_b1);
	glEnd();
	glColor3d(0,0,0);		
	glRasterPos2d (kurt_a1-0.01 , kurt_b1-0.01);
	glutBitmapCharacter(font_style,'W');
	
																// kurt2

	int i2=0;
	int en_yakin2=-1;
	double uzaklik2=1;
	for(i2=0;i2<6;i2++)
	{
		if(en_yakin1 != i2)
		{
			if(kuzu_koordinat[i1][0] != -2)
			{
			if(kuzu_koordinat[i2][0] < 0.6 || kuzu_koordinat[i2][1] < 0.5)
			{
			if( uzaklik2 >  sqrt(   pow( kurt_a2-kuzu_koordinat[i2][0] , 2 ) + pow( kurt_b2-kuzu_koordinat[i2][1] , 2 )   )   )
			{			
			uzaklik2=sqrt(   pow( kurt_a2-kuzu_koordinat[i2][0] , 2 ) + pow( kurt_b2-kuzu_koordinat[i2][1] , 2 )   );
			en_yakin2 = i2;	
			}
			}
			}
		}
	}

	if(en_yakin2 != -1)
	{
		if(kurt_a2 < kuzu_koordinat[en_yakin2][0])
		{
			kurt_a2 += (double)(kurt_hizi)/m1;
		}
		if(kurt_a2 > kuzu_koordinat[en_yakin2][0])
		{
			kurt_a2 -= (double)(kurt_hizi)/m1;
		}
		
		if(kurt_b2 < kuzu_koordinat[en_yakin2][1])
		{
			kurt_b2 += (double)(kurt_hizi)/m2;
		}
		if(kurt_b2 > kuzu_koordinat[en_yakin2][1])
		{
			kurt_b2 -= (double)(kurt_hizi)/m2;
		}

		if(fabs(kurt_a2 - kuzu_koordinat[en_yakin2][0]) < (double)3/m1 && fabs(kurt_b2 - kuzu_koordinat[en_yakin2][1]) < (double)3/m1)
		{
			kuzu_koordinat[en_yakin2][0]=-2;
		}
	}

	glPointSize(50);									
	glBegin(GL_POINTS);		
	glColor3d(1,0,0);		
	glVertex2d(kurt_a2 , kurt_b2);
	glEnd();
	glColor3d(0,0,0);		
	glRasterPos2d (kurt_a2-0.01 , kurt_b2-0.01);
	glutBitmapCharacter(font_style,'W');
	

	if(!mouseleftdown)
	{
	glPointSize(50);
	glBegin(GL_POINTS);
	glColor3d(0.0,0.0,0.0);	
	
	if(fabs(   ((double)dizi[sayac2][0]/m1) - kopek_a     ) < (double)3/m1   &&   fabs(  (1-(double)dizi[sayac2][1]/m2) - kopek_b   )  <(double)3/m2  ){
		if(sayac2<sayac-1){
		++sayac2;
		}
	}else {

         if((double)dizi[sayac2][0]/m1 > kopek_a){
		 kopek_a+=(double)3/m1;
		 }
		 if((double)dizi[sayac2][0]/m1 < kopek_a){
		 kopek_a-=(double)3/m1;
		 }
		 if(1-(double)dizi[sayac2][1]/m2 > kopek_b){
		 kopek_b+=(double)3/m2;
		 }
		 if(1-(double)dizi[sayac2][1]/m2 < kopek_b){
		 kopek_b-=(double)3/m2;
		 }
	}
			glVertex2d(kopek_a , kopek_b);	
			glEnd();
			glColor3d(1,1,1);
			glRasterPos2d (kopek_a-0.01 , kopek_b-0.01);
			glutBitmapCharacter(font_style,'D');
	}


}



void myDisplay(void) {                          // display callback
    /*cout << "MyDisplay called" << endl;*/
    glClearColor(0.1,0.7,0.1, 1.0);           // background is gray
    glClear(GL_COLOR_BUFFER_BIT);               // clear the window
                                // draw the objects
        drawObjects();
    
    glutSwapBuffers();                          // swap buffers
}

void myTimer(int id) {							// timer callback
               
    glutPostRedisplay();                        // request redraw
    glutTimerFunc(TIMER_DELAY, myTimer, 0);     // reset timer for 10 seconds

}



void myMouse(int b, int s, int x, int y) {      // mouse click callback
    
	mouseleftdown=false;
	if (s == GLUT_DOWN) {

		
        if (b == GLUT_LEFT_BUTTON) {
			
			mx=x;
			my=y;

			if(fabs(kopek_a*m1-x) < 30 && fabs((1-kopek_b)*m2-y) < 30 ){
			if( x < (m1-70)  ||  y < (m2-70) ){
			
				dizi[sayac][0] = x;
				dizi[sayac][1] = y;
				++sayac;
			
		
			mouseleftdown=true;
			}
			}
			else {
			mouseleftdown=false;
			}

			if( x > (m1-70)  &&  y > (m2-70) )
			{
				kopek_hav = true;			
				_beginthreadex(NULL, 0, dog, NULL, 0, NULL);
			
			}
			else {
				kopek_hav=false;
			}
        }
    }
}



void motion(int x, int y)
{

   if (mouseleftdown){


   mx = x;
   my = y;
   if( x < (m1-70)  ||  y < (m2-70) ){
	
		dizi[sayac][0] = x;
		dizi[sayac][1] = y;
		++sayac;
	  
   }
   }
}
                                                // keyboard callback
void myKeyboard(unsigned char c, int x, int y) {
    switch (c) {                                // c is the key that is hit
        case 'q':                               // 'q' means quit
            exit(0);
            break;
        default:
            cout << "Hit q to quit.  All other characters ignored" << endl;
            break;
    }
}


int main(int argc, char** argv)
{


    glutInit(&argc, argv);                      // OpenGL initializations
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);// double buffering and RGB
    glutInitWindowSize(800, 600);               // create a 400x400 window
    glutInitWindowPosition(0, 0);               // ...in the upper left
    glutCreateWindow(argv[0]);                  // create the window

    glutDisplayFunc(myDisplay);                 // setup callbacks
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
	glutMotionFunc(motion);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(TIMER_DELAY, myTimer, 0);
    glutMainLoop();                             // start it running
    return 0;                                   // ANSI C expects this
}
