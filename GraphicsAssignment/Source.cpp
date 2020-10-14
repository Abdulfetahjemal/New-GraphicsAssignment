#include<stdio.h>
#include<iostream>
#include<GL/glut.h>

#define KEY_ESC 27  
#define HOME 1
#define TILE_1 2
#define TILE_2 3
#define TILE_3 4
using namespace std;
void mouseMotion(int x, int y);

int fullscreen = 0;
int mouseDown = 0;

float xrot = 100.0f;
float yrot = -100.0f;

float xdiff = 100.0f;
float ydiff = 100.0f;

float tra_x = 0.0f;
float tra_y = 0.0f;
float tra_z = 0.0f;


float grow_shrink = 70.0f;
float resize_f = 1.0f;


void tile_2() {
	glColor3f(0.0f, 0.0f, 0.0f);
	// top - lst line 
	glBegin(GL_TRIANGLES);

	glVertex3f(-0.4f, 1.0f, 0.6f);
	glVertex3f(-0.3f, 1.0f, 0.5f);
	glVertex3f(-0.4f, 1.0f, 0.4f);
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex3f(-0.3f, 1.0f, 0.5f);
	glVertex3f(-0.2f, 1.0f, 0.6f);
	glVertex3f(-0.2f, 1.0f, 0.4f);
	glEnd();


	// middle - 2nd line 
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.6f, 1.0f, 0.4f);
	glVertex3f(-0.4f, 1.0f, 0.4f);
	glVertex3f(-0.5f, 1.0f, 0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, 1.0f, 0.3f);
	glVertex3f(-0.6f, 1.0f, 0.2f);
	glVertex3f(-0.4f, 1.0f, 0.2f);

	glEnd();
	// Middle square
	glBegin(GL_POLYGON);
	glVertex3f(-0.4f, 1.0f, 0.4f);
	glVertex3f(-0.2f, 1.0f, 0.4f);
	glVertex3f(-0.2f, 1.0f, 0.2f);
	glVertex3f(-0.4f, 1.0f, 0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.2f, 1.0f, 0.4f);
	glVertex3f(0.0f, 1.0f, 0.4f);
	glVertex3f(-0.1f, 1.0f, 0.3f);
	glEnd();


	glBegin(GL_TRIANGLES);
	glVertex3f(-0.1f, 1.0f, 0.3f);
	glVertex3f(-0.2f, 1.0f, 0.2f);
	glVertex3f(0.0f, 1.0f, 0.2f);

	glEnd();

	// 3rd line 

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.4f, 1.0f, 0.0f);
	glVertex3f(-0.4f, 1.0f, 0.2f);
	glVertex3f(-0.3f, 1.0f, 0.1f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.3f, 1.0f, 0.1f);
	glVertex3f(-0.2f, 1.0f, 0.2f);
	glVertex3f(-0.2f, 1.0f, 0.0f);


	glEnd();
}

void tile_1() {

	//left rectangle

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.9f, 1.0f, -1.0f);
	glVertex3f(0.1f, 1.0f, -1.0f);
	glVertex3f(0.1f, 1.0f, -0.9f);
	glVertex3f(0.9f, 1.0f, -0.9f);
	glEnd();

	//bottom rectangle

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 1.0f, -0.9f);
	glVertex3f(0.0f, 1.0f, -0.9f);
	glVertex3f(0.0f, 1.0f, -0.1f);
	glVertex3f(0.1f, 1.0f, -0.1f);
	glEnd();

	//right rectangle

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 1.0f, -0.1f);
	glVertex3f(0.1f, 1.0f, -0.0f);
	glVertex3f(0.9f, 1.0f, -0.0f);
	glVertex3f(0.9f, 1.0f, -0.1f);
	glEnd();

	//top rectangle
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, -0.9f);
	glVertex3f(0.9f, 1.0f, -0.9f);
	glVertex3f(0.9f, 1.0f, -0.1f);
	glVertex3f(1.0f, 1.0f, -0.1f);
	glEnd();


	///interior triangles


	///==>left top

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.8f, 1.0f, -0.9f);
	glVertex3f(0.8f, 1.0f, -0.8f);
	glVertex3f(0.9f, 1.0f, -0.8f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.8f, 1.0f, -0.8f);
	glVertex3f(0.8f, 1.0f, -0.6f);
	glVertex3f(0.9f, 1.0f, -0.7f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.7f, 1.0f, -0.9f);
	glVertex3f(0.6f, 1.0f, -0.8f);
	glVertex3f(0.8f, 1.0f, -0.8f);
	glEnd();


	////===> left bottom

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 1.0f, -0.9f);
	glVertex3f(0.1f, 1.0f, -0.8f);
	glVertex3f(0.2f, 1.0f, -0.8f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 1.0f, -0.8f);
	glVertex3f(0.1f, 1.0f, -0.7f);
	glVertex3f(0.2f, 1.0f, -0.6f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.3f, 1.0f, -0.9f);
	glVertex3f(0.2f, 1.0f, -0.8f);
	glVertex3f(0.4f, 1.0f, -0.8f);
	glEnd();


	////===> right bottom

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 1.0f, -0.1f);
	glVertex3f(0.1f, 1.0f, -0.2f);
	glVertex3f(0.2f, 1.0f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 1.0f, -0.2f);
	glVertex3f(0.1f, 1.0f, -0.3f);
	glVertex3f(0.2f, 1.0f, -0.4f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.3f, 1.0f, -0.1f);
	glVertex3f(0.2f, 1.0f, -0.2f);
	glVertex3f(0.4f, 1.0f, -0.2f);
	glEnd();



	///==>left top

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.8f, 1.0f, -0.1f);
	glVertex3f(0.8f, 1.0f, -0.2f);
	glVertex3f(0.9f, 1.0f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.8f, 1.0f, -0.2f);
	glVertex3f(0.8f, 1.0f, -0.4f);
	glVertex3f(0.9f, 1.0f, -0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.7f, 1.0f, -0.1f);
	glVertex3f(0.6f, 1.0f, -0.2f);
	glVertex3f(0.8f, 1.0f, -0.2f);
	glEnd();


	//inner rectangles

	//left rectangle

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.6f, 1.0f, -0.7f);
	glVertex3f(0.4f, 1.0f, -0.7f);
	glVertex3f(0.4f, 1.0f, -0.6f);
	glVertex3f(0.6f, 1.0f, -0.6f);
	glEnd();

	//bottom rectangle

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.4f, 1.0f, -0.6f);
	glVertex3f(0.3f, 1.0f, -0.6f);
	glVertex3f(0.3f, 1.0f, -0.4f);
	glVertex3f(0.4f, 1.0f, -0.4f);
	glEnd();

	//right rectangle

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.6f, 1.0f, -0.4f);
	glVertex3f(0.4f, 1.0f, -0.4f);
	glVertex3f(0.4f, 1.0f, -0.3f);
	glVertex3f(0.6f, 1.0f, -0.3f);
	glEnd();

	//top rectangle
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.7f, 1.0f, -0.6f);
	glVertex3f(0.6f, 1.0f, -0.6f);
	glVertex3f(0.6f, 1.0f, -0.4f);
	glVertex3f(0.7f, 1.0f, -0.4f);
	glEnd();


	/// inner diamond

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 1.0f, -0.6f);
	glVertex3f(0.4f, 1.0f, -0.5f);
	glVertex3f(0.5f, 1.0f, -0.4f);
	glVertex3f(0.6f, 1.0f, -0.5f);
	glEnd();







}
void tile_3() {

	glColor3f(0, 0, 0);
	// Top line
	glBegin(GL_POLYGON);

	glVertex3f(-0.3f, 1.0f, 0.6f);
	glVertex3f(-0.45f, 1.0f, 0.6f);

	glVertex3f(-0.6f, 1.0f, 0.45f);
	glVertex3f(-0.6f, 1.0f, 0.3f);

	glEnd();
	// Top right triangle
	glBegin(GL_TRIANGLES);


	glVertex3f(-0.4f, 1.0f, 0.5f);
	glVertex3f(-0.3f, 1.0f, 0.4f);

	glVertex3f(-0.4f, 1.0f, 0.4f);
	glEnd();


	// bottom left triangle
	glBegin(GL_TRIANGLES);


	glVertex3f(-0.4f, 1.0f, 0.4f);
	glVertex3f(-0.5f, 1.0f, 0.4f);
	glVertex3f(-0.4f, 1.0f, 0.3f);
	glEnd();



	// bottom right triangle
	glBegin(GL_TRIANGLES);


	glVertex3f(-0.3f, 1.0f, 0.4f);
	glVertex3f(-0.3f, 1.0f, 0.3f);
	glVertex3f(-0.4f, 1.0f, 0.3f);
	glEnd();



}

void drawBG(float bgWidth)
{


	glTranslatef(tra_x, tra_y, tra_z);
	glBegin(GL_QUADS);
	// Draw BG 
	glColor3f(1.0f, 1.0f, 1.0f);     // White

	glVertex3f(bgWidth, 1.0f - 0.001, -bgWidth);
	glVertex3f(-bgWidth, 1.0f - 0.001, -bgWidth);
	glVertex3f(-bgWidth, 1.0f - 0.001, bgWidth);
	glVertex3f(bgWidth, 1.0f - 0.001, bgWidth);




	// Bottom face (y = -1.0f)
	glColor3f(0.8f, 0.8f, 0.8f);  // Orange
	glVertex3f(bgWidth, 0.95f, bgWidth);
	glVertex3f(-bgWidth, 0.95f, bgWidth);
	glVertex3f(-bgWidth, 0.95f, -bgWidth);
	glVertex3f(bgWidth, 0.95f, -bgWidth);



	// Front face  (z = 1.0f)

	glVertex3f(bgWidth, 1.0f, bgWidth);
	glVertex3f(-bgWidth, 1.0f, bgWidth);
	glVertex3f(-bgWidth, 0.95f, bgWidth);
	glVertex3f(bgWidth, 0.95f, bgWidth);

	// Back face (z = -1.0f)

	glVertex3f(bgWidth, 0.95f, -bgWidth);
	glVertex3f(-bgWidth, 0.95f, -bgWidth);
	glVertex3f(-bgWidth, 1.0f, -bgWidth);
	glVertex3f(bgWidth, 1.0f, -bgWidth);


	// Left face (x = -1.0f)

	glVertex3f(-bgWidth, 1.0f, bgWidth);
	glVertex3f(-bgWidth, 1.0f, -bgWidth);
	glVertex3f(-bgWidth, 0.95f, -bgWidth);
	glVertex3f(-bgWidth, 0.95f, bgWidth);

	// Right face (x = 1.0f)

	glVertex3f(bgWidth, 1.0f, -bgWidth);
	glVertex3f(bgWidth, 1.0f, bgWidth);
	glVertex3f(bgWidth, 0.95f, bgWidth);
	glVertex3f(bgWidth, 0.95f, -bgWidth);
	glEnd();



}

void drawTile_2_main() {
	drawBG(0.6);

	glBegin(GL_LINES);
	glPointSize(3.0);
	glVertex3d(0.0f, 1.0f, 0.6f);
	glVertex3d(0.0f, 1.0f, -0.6f);
	glEnd();

	glBegin(GL_LINES);
	glPointSize(3.0);
	glVertex3d(0.6f, 1.0f, 0.0f);
	glVertex3d(-0.6f, 1.0f, 0.0f);
	glEnd();



	tile_2();
	glTranslatef(0.6f, 0.0f, 0.0f);
	tile_2();
	glTranslatef(0.0f, 0.0f, -0.6f);
	tile_2();
	glTranslatef(-0.6f, 0.0f, 0.0f);
	tile_2();







	glFlush();

}

void draw2thquadant_top() {
	tile_3();
	glRotatef(90, 0.0f, -0.1f, 0.0f);
	glTranslatef(0.6f, 0.0f, 0.0f);
	tile_3();

}

void draw2thquadrant() {
	draw2thquadant_top();
	glRotatef(90, 0.0f, -0.1f, 0.0f);
	glTranslatef(0.6f, 0.0f, 0.0f);
	draw2thquadant_top();
}

void drawTile_3_main() {

	drawBG(0.6);
	draw2thquadrant();
	glTranslatef(0.6f, 0.0f, 0.0f);
	draw2thquadrant();
	glTranslatef(-0.6f, 0.0f, 0.0f);
	draw2thquadrant();
	glTranslatef(0.6f, 0.0f, 0.0f);
	draw2thquadrant();
	glFlush();

}
void drawTile_1_main() {
	drawBG(1.0);
	tile_1();
	glTranslatef(0.0f, 0.0f, 1.0f);
	tile_1();
	glTranslatef(-1.0f, 0.0f, 0.0f);
	tile_1();
	glTranslatef(0.0f, 0.0f, -1.0f);
	tile_1();
	glFlush();

}

int init(void)
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	return 1;
}

void display(void)
{
	glutMotionFunc(mouseMotion);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	drawTile_1_main();

	glFlush();
	glutSwapBuffers();
}

void display2(void)
{
	glutMotionFunc(mouseMotion);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	drawTile_2_main();

	glFlush();
	glutSwapBuffers();
}

void display3(void)
{
	glutMotionFunc(mouseMotion);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	drawTile_3_main();

	glFlush();
	glutSwapBuffers();
}
void displayText(float x, float y, int r, int g, int b, const char* string) {
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2i(x, y);
	for (int i = 0; i < j; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}

	glEnd();


}
void empFunction(int x, int y) {

}
void display_home() {
	glutMotionFunc(empFunction);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	//glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	//glRotatef(yrot, 0.0f, 1.0f, 0.0f);

	displayText(-1.0f, 1.0, 0, 0, 0, "HiLCoE School of Computer Science and Technology");
	displayText(-1.0f, 0.0, 0, 0, 0, "***********[Right Click to open menu]*************");
	displayText(-1.0f, -1.0, 0, 0, 0, " [U] Rotate clockwise,  [W,S,A,D] Move tile ");


	//displayText(0, 0.0, 0, 0, 0, "By - Abdulfetah Jemal");


	// Flush drawing command buffer to make drawing happen as soon as possible.
	glFlush();


	glFlush();
	glutSwapBuffers();
}
void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(grow_shrink, resize_f * w / h, resize_f, (float)(100 * resize_f));

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(1);
		break;



	case 'w':
	case 'W':
		tra_x += 0.1f;
		break;
	case 's':
	case 'S':
		tra_x -= 0.1f;
		break;
	case 'a':
	case 'A':
		tra_z -= 0.1f;
		break;
	case 'd':
	case 'D':
		tra_z += 0.1f;
		break;
	case 'u':
	case 'U':
		xrot += 1.0f;
		yrot += 1.0f;
		xdiff += 1.0f;
		ydiff += 1.0f;
		break;

	case 'y':
	case 'Y':
		xrot -= 1.0f;
		yrot -= 1.0f;
		xdiff += 1.0f;
		ydiff += 1.0f;
		break;

	
	
	case 'Z':
	case 'z':
		grow_shrink--;
		resize(800, 800);

		break;
	case 'X':
	case 'x':
		grow_shrink++;
		resize(800, 800);

		break;

	}


	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		fullscreen = !fullscreen;

		if (fullscreen)
			glutFullScreen();
		else
		{
			glutReshapeWindow(800, 800);
			glutPositionWindow(50, 50);
		}
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = 1;

		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = 0;
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}


void processMenuEvents(int option) {

	switch (option) {
	case HOME:
		glutDisplayFunc(display_home); break;
	case TILE_1:
		glutDisplayFunc(display); break;
	case TILE_2:
		glutDisplayFunc(display2); break;
	case TILE_3:
		glutDisplayFunc(display3); break;
	}
	keyboard('w', 0, 0);
	keyboard('s', 0, 0);
}
void createGLUTMenus() {

	int menu;

	menu = glutCreateMenu(processMenuEvents);

	//add entries to our menu
	glutAddMenuEntry("Home", HOME);
	glutAddMenuEntry("Tile 1", TILE_1);
	glutAddMenuEntry("Tile 2", TILE_2);
	glutAddMenuEntry("Tile 3", TILE_3);

	// attach the menu to the right button
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 800);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("Graphics Assignment - Abdulfetah Jemal Omer (A) - FI1692");

	glutDisplayFunc(display_home);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(resize);

	createGLUTMenus();
	if (!init())
		return 1;

	glutMainLoop();

	return 0;
}