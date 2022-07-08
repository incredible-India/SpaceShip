#include <stdio.h>
#include <GL/glut.h>
#include<string.h>
#include<time.h>
//user define header files
#include"./basic.h"
#include"./welcome.h" //welcome screen functions are there
#include"./space.h" //main programe
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//display function

//creating stars
void start();
void keyboard(unsigned char,int,int);
void solar();


//variables
GLint animate,launch=0;//for the static and dynamic view with the launch satellite

GLfloat rocketVibrate,satelliteTranslate=-1.0 ,satelliteRotate=90,stlteY=0.4;//rocket will translate in at x-axis
GLfloat xDir,yDir; //for stars translation
GLfloat moonx,moonz;//for the moon translation
GLfloat EarthAndMoonRotation=0;//this is for the rotation and translation of the moon and earth
void start()
{
	if(flag==1)
	welcomeWindow()	;
	else
	solar();
}



void keyboard(unsigned char key,int x,int y)
{
	extern int flag;
	if(key == 'X' || key=='x')
		flag=2;
		glutPostRedisplay();
		
		
}

void Menu(int option)
{
	if(option == 1)
	{
	
		animate =0;
		launch = 0;
	}else if(option == 2)
	{
			animate = 1;
		launch = 0;
		 
	}else if(option == 3)
	{
			animate=1;
		launch = 1;
	}else
	{
			animate =0;
		launch = 0;
	}
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

	glutDisplayFunc(start);
	glutTimerFunc(1000,timer,0);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    glutCreateMenu(Menu); // menu items
    glutAddMenuEntry("Static View",1);
    glutAddMenuEntry("Dynamic View",2);
 	glutAddMenuEntry("Launch Satellite",3);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
	glutMainLoop();
	return 0;
}
