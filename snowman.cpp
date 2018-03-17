#include <stdio.h>
#include <math.h>
#include <random>
#include <windows.h>
#include <mmsystem.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <glut.h>
#pragma comment(lib, "winmm.lib")

void snowMan(int, int);
void powerUp(int);
void background(float, float);
void display();
void obstacles(int, int);
void SpecialKeys(int, int, int);
void anim(void);
void hitObstacle();
void Timer(int value);
void print(int, int, char*);
void destination();

int x = 0;
int y = 0;
float scene1 = 0.0f;
float scene2 = 800.0f;
int obstacleY = 0;
int obstacleY1 = 0;
int obstacleY2 = 0;
int lives = 0;
int shape = 0;
int count = 0;
int powerY = 0;
float tar = 0.03;
float xm = 0.0f;
float xo = 0.0f;
float xo1 = 0.0f;
float xo2 = 0.0f;
int timer = 0;
float snowmanXpos = x + 370+80;
float snowmanXposl = x + 140 + 80;
float snowmanYposh = y +340;
float snowmanYposl = y + 170;
bool over;
bool win;
bool s;

void main(int argc, char** argr) {

	srand(time(0));
	glutInit(&argc, argr);
	PlaySound(TEXT("song.wav"), NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Snow Man");
	glutDisplayFunc(display);
	glutSpecialFunc(SpecialKeys);
	glutTimerFunc(0, Timer, 0);
	glutIdleFunc(anim);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glLineWidth(9.0);
	gluOrtho2D(0, 800, 0, 800);
	glutMainLoop();
}
void display()
{
	if (!over & !win) {
		glClear(GL_COLOR_BUFFER_BIT);
		background(scene1, scene2);
		powerUp(powerY);
		obstacles(obstacleY, 0);
		obstacles(obstacleY, 1);
		obstacles(obstacleY, 2);
		snowMan(x, y);
		destination();
		//PlaySound(TEXT("Before I Go - Yanni.mp3"), NULL, SND_ASYNC);
	}
		//if (over) print(400, 400, "Game over");
		//if (win) print(400, 400, "win");
	
		//PlaySound(TEXT("song.wav"), NULL, SND_ASYNC);
	//PlaySound(TEXT("song.wav"), NULL, SND_FILENAME | SND_ASYNC);

		glFlush();

}
void background(float scene1, float scene2)
{
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.2f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(800.0f, 0.0f, 0.0f);
	glVertex3f(800.0f, 800.0f, 0.0f);
	glVertex3f(0.0f, 800.0f, 0.0f);
	glEnd();
	//scene 1
	glPushMatrix();
	glTranslated(scene1, 0, 0);

	glPushMatrix();
	glTranslated(300, 0, 0);
	glScaled(2, 5, 1);
	glColor3f(0.9, 0.9, 1);
	GLUquadric *moun = gluNewQuadric();
	gluDisk(moun, 0, 60, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslated(500, 0, 0);
	glScaled(2, 7, 1);
	glColor3f(0.9, 0.9, 1);
	GLUquadric *mountain1 = gluNewQuadric();
	gluDisk(mountain1, 0, 50,100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslated(100, 0, 0);
	glScaled(2, 5, 1);
	glColor3f(0.9, 0.9, 1);
	GLUquadric *body = gluNewQuadric();
	gluDisk(body, 0, 50, 100, 100);
	glPopMatrix();

	glPopMatrix();

	//scene 2
	glPushMatrix();
	glTranslated(scene2, 0, 0);

	glPushMatrix();
	glTranslated(800, 0, 0);

	glPushMatrix();
	glTranslated(200, 0, 0);
	glScaled(2, 7, 1);
	glColor3f(0.9, 0.8, 1);
	GLUquadric *scen2moun = gluNewQuadric();
	gluDisk(scen2moun, 0, 100, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslated(400, 0, 0);
	glScaled(2, 5, 1);
	glColor3f(0.8, 0.8, 9);
	GLUquadric *scen2moun1 = gluNewQuadric();
	gluDisk(scen2moun1, 0, 80, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslated(600, 0, 0);
	glScaled(2, 3, 1);
	glColor3f(0.8, 0.8, 0.9);
	GLUquadric *scen2moun2 = gluNewQuadric();
	gluDisk(scen2moun2, 0, 100, 100, 100);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

}

void snowMan(int x, int y)
{
	//translated due to keys
	glPushMatrix();
	glTranslated(x, y, 0);

	//translated to centre shwia
	glPushMatrix();
	glTranslated(80, 50, 0);
	glPushMatrix();
	//body
	glTranslated(250, 200, 0);
	glScaled(3, 2.5, 1);
	glColor3f(1, 1, 1);
	GLUquadric *body = gluNewQuadric();
	gluDisk(body, 0, 20, 100, 100);
	glPopMatrix();
	//head
	glPushMatrix();
	glTranslated(250, 270, 0);
	glScaled(3, 2, 1);
	glColor3f(1, 1, 1);
	GLUquadric *head = gluNewQuadric();
	gluDisk(head, 0, 10, 100, 100);
	glPopMatrix();
	//eyes
	glPushMatrix();
	glTranslated(270, 270, 0);
	glColor3f(0, 0, 0);
	GLUquadric *eye = gluNewQuadric();
	gluDisk(eye, 3, 6, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslated(255, 270, 0);
	GLUquadric *eyer = gluNewQuadric();
	gluDisk(eyer, 3, 6, 100, 100);
	glPopMatrix();

	// nose
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor3f(0.93f, 0.463f, 0.0f);
	glVertex3f(288.0f, 260.0f, 0.0f);
	glVertex3f(288.0f, 252.0f, 0.0f);
	glVertex3f(255.0f, 260.5f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslated(288, 257, 0);
	GLUquadric *nose = gluNewQuadric();
	gluDisk(nose, 0, 3.5, 120, 93.5);
	glPopMatrix();


	// hands and legs
	glBegin(GL_LINES);
	glColor3f(0.545f, 0.271f, 0.075f);
	//left hand 
	glVertex3f(200.0f, 225.0f, 0.0f);
	glVertex3f(140.0f, 200.0f, 0.0f);
	//right hand
	glVertex3f(300.0f, 225.0f, 0.0f);
	glVertex3f(370.0f, 200.0f, 0.0f);
	// left leg
	glVertex3f(235.0f, 120.0f, 0.0f);
	glVertex3f(235.0f, 155.0f, 0.0f);
	// left leg
	glVertex3f(265.0f, 120.0f, 0.0f);
	glVertex3f(265.0f, 155.0f, 0.0f);
	glEnd();

	glPopMatrix();
	glPopMatrix();

	//glFlush();
}

void powerUp(int powY)
{

	glPushMatrix();
	glTranslated(xm, 0, 0);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(750.0f, powY - 20.0f, 0.0f);
	glVertex3f(750.0f, powY, 0.0f);
	glVertex3f(670.0f, powY - 10.0f, 0.0f);
	glEnd();

	glPushMatrix();
	glTranslated(750, powY - 10.0, 0);
	GLUquadric *body = gluNewQuadric();
	gluDisk(body, 0, 10, 600, 110);
	glPopMatrix();
	glPopMatrix();

	//glFlush();
}

void obstacles(int oby, int shape)
{
	//wood
	if (shape == 1)
	{
		glPushMatrix();
		glTranslated(xo, 0, 0);
		glBegin(GL_LINES);
		glColor3f(0.545f, 0.271f, 0.075f);
		glVertex3f(795.0f, obstacleY - 50.0, 0.0f);
		glVertex3f(750.0f, obstacleY, 0.0f);
		glEnd();
		glPopMatrix();
		//glFlush();
	}
	// ice ball
	else {
		if (shape == 0)
		{
			glPushMatrix();
			glTranslated(xo1, 0, 0);
			glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			glTranslated(750, obstacleY1, 0);
			GLUquadric *nose = gluNewQuadric();
			gluDisk(nose, 0, 30, 100, 100);
			glPopMatrix();
			glPopMatrix();
			//glFlush();
		}

		// ice ball
		else {
			if (shape == 2)
			{
				glPushMatrix();
				glTranslated(xo2, 0, 0);
				glPushMatrix();
				glColor3f(1.0f, 1.0f, 1.0f);
				glTranslated(750, obstacleY2, 0);
				GLUquadric *ball = gluNewQuadric();
				gluDisk(ball, 0, 20, 40, 10);
				glPopMatrix();
				glPopMatrix();
				//glFlush();
			}
		}
	}
}

void SpecialKeys(int key, int f, int l)
{
	if (key == GLUT_KEY_UP && y<430)
		y += 6;

	if (key == GLUT_KEY_DOWN&& y>-100)
		y -= 6;
	glutPostRedisplay();
}


void anim()
{
	
	if (scene1<-800.0f&& scene2 == -800.0f)  scene1 = 800.0f;
	else scene1 -= 2;
	if (scene2<-800.0f && scene1 == -800.0f)scene2 = 0.0f;
	else scene2 -= 2;
	glutPostRedisplay();
}

void hitObstacle()
{
	if (x>=-100)
	{
		x -= 50;
		xo = 0.0f;
		xo1 = 0.0f;
		xo2 = 0.0f;
		//xm = -800;	
	}
	else {
		over = true;
	print(400, 400, "Game Over");
	     }
	glutPostRedisplay();

}

void hitPowerup()
{
	if (x<150)
	{
		x += 50;
		xm = -800;
		xo = 0.0f;
		xo1 = 0.0f;
		xo2 = 0.0f;
	}
	/*else
	{
		win = true;
		print(400, 400, "win");
	}*/
	glutPostRedisplay();
}

void Timer(int value) {

	if (timer % 400 == 0)
	{
		obstacleY = rand() % 780 + 10;
		xo = 0.0f;
	}
	if (timer % 350 == 0)

	{
		obstacleY1 = rand() % 780 + 10;
		xo1 = 0.0f;
	}
	if (timer % 300 == 0)
	{
		obstacleY2 = rand() % 780 + 10;
		xo2 = 0.0f;
	}
		
	if (timer % 600 == 0)
	{
		powerY = rand() % 780 + 10;
		xm = 0.0f;
	}

	obstacleY += 8 * sin(((int)xo + 380) / 18);
	obstacleY1 += 8 * sin(((int)xo1 + 420) / 20);
	obstacleY2 += 8 * cos(((int)xo2 + 400) / 22);

	if (xo <= 0) xo = xo - 4; else xo = 0.0f;
	if (xo1 <= 0) xo1 = xo1 - 4; else xo1 = 0.0f;
	if (xo2 <= 0) xo2 = xo2 - 4; else xo2 = 0.0f;
	if (xm <= 0)xm = xm - 4; else xm = 0.0f;
	//wood
	if((x + 370 + 80)>= 750+xo && (x + 140 + 80) <= 800 + xo && (y + 340 )>=obstacleY &&(y + 170) <=obstacleY-50)
	{
		//hitObstacle();
		if (x > -200)
		{
			x -= 100;
			xo = 0.0f;
			xo1 = 0.0f;
			xo2 = 0.0f;
			obstacleY = 1234;
			PlaySound(TEXT("bad.wav"), NULL, SND_ASYNC);
			s = true;
			//xm = -800;	
		}
		else
		{
			over = true;
			print(400, 400, "Game Over");

		}
	}
	if ((x + 370 + 80) >= 750 + xo1 && (x + 140 + 80) <= 800 + xo1&& (y + 340) >= obstacleY1 && (y + 170) <= obstacleY1 - 50)
	{
		//hitObstacle();
		if (x > -200)
		{
			x -= 100;
			xo = 0.0f;
			xo1 = 0.0f;
			xo2 = 0.0f;
			obstacleY1 = 1234;
			PlaySound(TEXT("bad.wav"), NULL, SND_ASYNC);
			s = true;
			//xm = -800;
		}
		else
		{
			over = true;
			print(400, 400, "Game Over");
		}
	}
	if ((x + 370 + 80) >= 750 + xo2 && (x + 140 + 80) <= 800 + xo2 && (y + 340) >= obstacleY2 && (y + 170) <= obstacleY2 - 50)
	{
		//hitObstacle();
		if (x > -200)
		{
			x -= 100;
			xo = 0.0f;
			xo1 = 0.0f;
			xo2 = 0.0f;
			obstacleY2 = 1234;
			PlaySound(TEXT("bad.wav"), NULL, SND_ASYNC);
			s = true;
			//xm = -800;
		}
		else
		{
			over = true;
			print(400, 400, "Game Over");
		}
	}

	if ((x + 370 + 80) >= 750 + xm && (x + 140 + 80) <= 700 + xm&& (y + 340) >= powerY && (y + 170) <= powerY - 20)
	{
		//hitPowerup();
		if (x<400)
		{
			x += 100;
			xm =0;
			powerY = 12345;
			xo = 0.0f;
			xo1 = 0.0f;
			xo2 = 0.0f;
			PlaySound(TEXT("power.wav"), NULL, SND_ASYNC);
			s = true;
		}
		else
		{
		win = true;
		print(400, 400, "win");
		}
	}

	if (s&&timer % 250 == 0){
		s = false;
		PlaySound(TEXT("song.wav"), NULL, SND_ASYNC|SND_LOOP|SND_NOSTOP);
	}
	timer++;
	glutPostRedisplay();
	// recall the Timer function after 20 seconds (20,000 milliseconds)
	glutTimerFunc(20, Timer, 0);
}
void print(int x, int y, char *string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void destination()
{
	glPushMatrix();
	glTranslated(600, 50, 0);
	glScaled(0.5, 0.5, 1);
	glPushMatrix();
	//body
	glTranslated(250, 200, 0);
	glScaled(3, 2.5, 1);
	glColor3f(0.8, 0.8, 0.6);
	GLUquadric *body = gluNewQuadric();
	gluDisk(body, 0, 20, 100, 100);
	glPopMatrix();
	//head
	glPushMatrix();
	glTranslated(250, 270, 0);
	glScaled(3, 2, 1);
	glColor3f(1, 1, 1);
	GLUquadric *head = gluNewQuadric();
	gluDisk(head, 0, 10, 100, 100);
	glPopMatrix();
	//eyes
	glPushMatrix();
	glTranslated(270, 270, 0);
	glColor3f(0, 0, 0);
	GLUquadric *eye = gluNewQuadric();
	gluDisk(eye, 3, 6, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslated(255, 270, 0);
	GLUquadric *eyer = gluNewQuadric();
	gluDisk(eyer, 3, 6, 100, 100);
	glPopMatrix();

	// nose
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor3f(0.93f, 0.463f, 0.0f);
	glVertex3f(288.0f, 260.0f, 0.0f);
	glVertex3f(288.0f, 252.0f, 0.0f);
	glVertex3f(255.0f, 260.5f, 0.0f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslated(288, 257, 0);
	GLUquadric *nose = gluNewQuadric();
	gluDisk(nose, 0, 3.5, 120, 93.5);
	glPopMatrix();


	// hands and legs
	glBegin(GL_LINES);
	glColor3f(0.545f, 0.271f, 0.075f);
	//left hand 
	glVertex3f(200.0f, 225.0f, 0.0f);
	glVertex3f(140.0f, 200.0f, 0.0f);
	//right hand
	glVertex3f(300.0f, 225.0f, 0.0f);
	glVertex3f(370.0f, 200.0f, 0.0f);
	// left leg
	glVertex3f(235.0f, 120.0f, 0.0f);
	glVertex3f(235.0f, 155.0f, 0.0f);
	// left leg
	glVertex3f(265.0f, 120.0f, 0.0f);
	glVertex3f(265.0f, 155.0f, 0.0f);
	glEnd();

	glPopMatrix();
}