#include <stdio.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//display function
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glutSwapBuffers();
}

//init Function
void init()
{
	//glClearColor(0.0,0.0,0.0,1.0); //black color background
	
	glEnable(GL_DEPTH_TEST);
}
//reshape function
void reshape(int w ,int h)
{
	glViewport(0,0,w,h);
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	
	glFrustum(-1,1,-1,1,1,10);
	
	glMatrixMode(GL_MODELVIEW);
	
	
}
//main function
int main(int argc, char** argv) {
	
	//initialisation of glut api
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	//intialising the window size and window position
	glutInitWindowPosition(100,100);
	glutInitWindowSize(900,900);
	glutCreateWindow("SpaceShip Program..");
	
	//register callbacks
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();
	return 0;
}
