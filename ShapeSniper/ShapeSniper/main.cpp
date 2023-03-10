#include <iostream>
#include <glut.h>
#include "ObjectTypes.h"

#define WIDTH 600
#define HIEGHT 600

PhysicalWorld wrld = PhysicalWorld();

void System_Of_Axes()
{
	glColor3f(1.0, 1.0, 1.0);             /* void glColor3f float red , float green , float blue );   */

	glBegin(GL_LINES);                  /* axis X  */
	glVertex3f(100, 0, 0);
	glVertex3f(-100, 0, 0);
	glEnd();

	glBegin(GL_LINES);                  /* axis Y  */
	glVertex3f(0, 100, 0);
	glVertex3f(0, -100, 0);
	glEnd();

	glBegin(GL_LINES);                  /* axis z  */
	glVertex3f(0, 0, 100);
	glVertex3f(0, 0, -100);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glutPostRedisplay();

	wrld.drawWorld();

	//TODO: Draw Overlay

	//draws the white axis
	//System_Of_Axes();

	glutSwapBuffers();
	glFlush();
}

void init()
{
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1000, 1000, -1000, 1000, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void dtGenerator(int sec)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, dtGenerator, sec + 1000 / 60); //60 fps
	wrld.Step(1.0 / 6.0);
}

void mouse(int button, int state, int x, int y)
{
	float xm, ym;
	std::vector<Object*> objects = wrld.getObjects();
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		xm = -1000 + (float)x * 1000 / WIDTH * 2;
		ym = 1000 - (float)y * 1000 / HIEGHT * 2;
		std::cout << "xPixel = " << x << " | yPixel = " << y << std::endl;
		std::cout << "xM = " << xm << " | yM = " << ym << std::endl;
		for (Object* obj : objects)
		{
			if (obj->Position.x - xm < 100 && obj->Position.x - xm > -100 && obj->Position.y - ym < 100 && obj->Position.y - ym > -100)
				obj->Shot = true;
		}
	}
}

void initializeGame()
{
	vector3* pos = new vector3();
	vector3* vel = new vector3();

	wrld.clearObjects();
	
	generatePosVel(pos, vel);

	wrld.AddObject(new Rectangle(
			*pos,			//axis
			*vel,			//Velocity
			vector3(),		//Force
			0.000001,		//Mass
			BLUE,			//color
			100, 100, 100	//width, hieght, depth
	));

	generatePosVel(pos, vel);

	wrld.AddObject(new HalfSphere(
		*pos,		//axis
		*vel,		//Velocity
		vector3(0, 0, 0),	//Force
		0.1,				//Mass
		BLUE,				//color
		80
	));

	generatePosVel(pos, vel);

	wrld.AddObject(new Rectangle(
		*pos,		//axis
		*vel,		//Velocity
		vector3(),		//Force
		0.000001,		//Mass
		RED,			//color
		100, 100, 100	//width, hieght, depth
	));
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q': case 'Q': exit(0); break;
	case 'r': case 'R': initializeGame();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WIDTH, HIEGHT);
	glutCreateWindow("Program");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	init();

	initializeGame();
	
	glutTimerFunc(0, dtGenerator, 0);

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

	return 0;
}
