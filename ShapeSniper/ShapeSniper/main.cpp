#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <glut.h>
#include <crtdbg.h>
#include <string>
#include "ObjectTypes.h"

#define WIDTH 600
#define HIEGHT 600

PhysicalWorld wrld = PhysicalWorld();


void draw_string(void* font, const char* str, vector3 pos, vector3 color, float size);
void display();
void init();
void dtGenerator(int sec);
void mouse(int button, int state, int x, int y);
void initializeGame();
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
	_CrtDumpMemoryLeaks();
	return 0;
}

void draw_string(void* font, const char* str, vector3 pos, vector3 color, float size)
{
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glScalef(size, size, size);
	glColor3f(color.x, color.y, color.z);
	glLineWidth(2);
	while (*str)
	{
		glutStrokeCharacter(font, *str);
		str++;
	}
	glPopMatrix();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glutPostRedisplay();

	wrld.drawWorld();

	//TODO: Draw Overlay
	draw_string(GLUT_STROKE_ROMAN, std::string(wrld.getMiss(), 'x').c_str(), vector3(-1000, 850, 0), RED, 1);
	
	draw_string(GLUT_STROKE_ROMAN, "Objects Shot: ", vector3(-1000, 750, 0), vector3(1, 1, 1), 0.5);
	draw_string(GLUT_STROKE_ROMAN, std::to_string(wrld.getShot()).c_str(), vector3(-570, 750, 0), vector3(1, 1, 1), 0.5);

	draw_string(GLUT_STROKE_ROMAN, "Top Score: ", vector3(-1000, 650, 0), vector3(1, 1, 1), 0.5);
	draw_string(GLUT_STROKE_ROMAN, std::to_string(wrld.getMax()).c_str(), vector3(-635, 650, 0), vector3(1, 1, 1), 0.5);

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

	free(pos);
	free(vel);
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q': case 'Q': wrld.clearObjects(); _CrtDumpMemoryLeaks(); exit(0); break;
	case 'r': case 'R': initializeGame();
	}
}
