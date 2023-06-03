#include <string>
#include "Game.h"

#define WIDTH 800
#define HIEGHT 800

Game game = Game();


/*
* This function draws a string
* Input: font, string, position, color of string, size of text
* Ouput: none
*/
void draw_string(void* font, const char* str, const vector3 pos, const vector3 color, const float size);
/*
* This function displays the screen
* Input: none
* Output: none
*/
void display();
/*
* This function initializes the the cords
* Input: none
* Output: none
*/
void init();
/*
* This function runs 60 times per second
* Input: none
* Output: none
*/
void dtGenerator(const int sec);
/*
* This function handles with mouse clicks
* Input: button, state, x and y cords
* Output: none
*/
void mouse(const int button, const int state, const int x, const int y);
/*
* This function handles with keyboard presses
* Input: button, state, x and y cords
* Output: none
*/
void keyboard(const unsigned char key, const int x, const int y);

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

	glutTimerFunc(0, dtGenerator, 0);

	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

void draw_string(void* font, const char* str, const vector3 pos, const vector3 color, const float size)
{
	glPushMatrix();
	glTranslatef(pos._x, pos._y, pos._z);
	glScalef(size, size, size);
	glColor3f(color._x, color._y, color._z);
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

	glEnable(GL_DEPTH_TEST); // Enable depth testing
	glEnable(GL_LIGHTING); // Enable lighting
	glEnable(GL_LIGHT0); // Enable light source 0
	glEnable(GL_COLOR_MATERIAL); // Enable coloring of materials

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

	game.drawWorld();

	glDisable(GL_LIGHTING);

	//TODO: Draw Overlay
	draw_string(GLUT_STROKE_ROMAN, "xxxxx", vector3(-1000, 850, 0), vector3(1, 1, 1), 1);
	draw_string(GLUT_STROKE_ROMAN, std::string(game.getMiss(), 'x').c_str(), vector3(-1000, 850, 1), RED, 1);
	
	draw_string(GLUT_STROKE_ROMAN, "Objects Shot: ", vector3(-1000, 750, 0), vector3(1, 1, 1), 0.5);
	draw_string(GLUT_STROKE_ROMAN, std::to_string(game.getShot()).c_str(), vector3(-570, 750, 0), vector3(1, 1, 1), 0.5);

	draw_string(GLUT_STROKE_ROMAN, "Top Score: ", vector3(-1000, 650, 0), vector3(1, 1, 1), 0.5);
	draw_string(GLUT_STROKE_ROMAN, std::to_string(game.getMax()).c_str(), vector3(-635, 650, 0), vector3(1, 1, 1), 0.5);

	glutSwapBuffers();
	glFlush();
}


void init()
{
	glClearColor(0.2, 0.2, 0.2, 1.0); //color of background
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1000, 1000, -1000, 1000, -1000, 1000); //1000 to each way x, y, z
	glMatrixMode(GL_MODELVIEW);
}


void dtGenerator(const int sec)
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, dtGenerator, sec + 1000 / 60); //60 fps
	game.step(1.0 / 6.0);
}


void mouse(const int button, const int state, const int x, const int y)
{
	float xm, ym;
	std::vector<Object*> objects = game.getObjects();
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		xm = -1000 + x * 1000 / WIDTH * 2; //calculate cords x
		ym = 1000 - y * 1000 / HIEGHT * 2; //calculate cords y
		//std::cout << "xPixel = " << x << " | yPixel = " << y << std::endl;
		//std::cout << "xM = " << xm << " | yM = " << ym << std::endl;
		for (Object* obj : objects)
		{
			if (obj->_pos._x - xm < 100 && obj->_pos._x - xm > -100 && obj->_pos._y - ym < 100 && obj->_pos._y - ym > -100)
				obj->_shot = true;
		}
	}
}


void keyboard(const unsigned char key, const int x, const int y)
{
	switch (key)
	{
	case 27: game.end(); exit(0); break;		//escape
	case 32: game.end(); game.start(); break;	//space
	}
}
