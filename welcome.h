void stars();
void sphere();
void solar();
void welcomeWindow();


int i;
int flag =1;
int angle=0;






void sphere()
{
	
	GLfloat pos[] = {0,0,1,1};
	GLfloat col[] = {1,1,1,1};
	GLfloat col2[] = {1,1,1,1};

	glLoadIdentity();
	
			glLightfv(GL_LIGHT0,GL_POSITION,pos);
		
			glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
			glLightfv(GL_LIGHT0,GL_SPECULAR,col2);
			glVertex3f(1,0,0);
			glTranslatef(-1,-1.2,0);
			glRotatef(angle,0,1,1);
 			glutSolidSphere(0.3,24 ,10);
 			
}
void timer(int time)
{
	extern int animate;
	extern float EarthAndMoonRotation,satelliteTranslate,stlteY;
	extern int starSize;
	extern float xDir,yDir,satelliteRotate;
	extern float moonx,moonz;
	extern float rocketVibrate;
	extern int launch;
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);

		angle +=1.5;
	if(angle>=360)
		angle =angle-360;
		
		
	//space for the animation and dynamic view
	if(animate)
	{

	EarthAndMoonRotation +=1.5;
	if(EarthAndMoonRotation>=360)
		EarthAndMoonRotation =EarthAndMoonRotation-360;	
		
	xDir +=0.01;
	if(xDir >2)
		xDir =-2;
		
	yDir +=0.01;
	if(yDir >2)
		yDir =-2;
	

		moonx +=0.01;
	if(moonx >2)
		moonx -=0.01;
	if(moonx < -2)
		moonx +=0.01;	
	moonz +=0.01;
	if(moonz >2)
		moonz -=0.01;	
	if(moonz < -2)
		moonz +=0.01;
	
	//rocket moving
//	rocketVibrate +=0.1;
//	if(rocketVibrate >= 0.5)
//		rocketVibrate -=0.1;
	if(launch)
	{
		
			satelliteRotate +=0.18;
				if(satelliteRotate > 90)
					{
						
							satelliteTranslate +=0.006;
         					stlteY +=0.004 ;
					if(satelliteTranslate > 1.0)
					{
						if(satelliteRotate > 360)
							satelliteRotate = satelliteRotate -360;
						satelliteTranslate =1.0;
			
				
			}
					}
	
		if(stlteY > 0.9)
			stlteY=0.9;
		
	}
}
}


void welcomeWindow()
{
	extern int i;
	

     GLfloat col[] = {1,1,1,1};
     GLfloat col2[] = {0.9,0.6,0,1};
	char wel[] = "SpaceShip Programe";
	char msg[] = "Himanshu Kumar Sharma";
	char msg1[] = "1SP19CS035";
	char key[] = "Press 'X' Key To Start";
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


glRasterPos3f(-1.5,-1,0);

    	glLoadIdentity();


	glMaterialfv(GL_FRONT,GL_DIFFUSE,col2);
	glRasterPos3f(-0.7,0.7,0);
		for(i=0;i<strlen(wel);i++)
	{	glColor3f(0,1,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,wel[i]);
	}


//	glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
	glRasterPos3f(-0.7,0.4,0);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,col);
	for(i=0;i<strlen(msg);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg[i]);
	}
		glColor3f(1,0.6,0.4);
		glRasterPos3f(-0.7,0.2,0);
		for(i=0;i<strlen(msg1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,msg1[i]);
	}

		glColor3f(1,1,1);
//			glMaterialfv(GL_FRONT,GL_DIFFUSE,col);
		glRasterPos3f(-0.7,-0.2,0);
		for(i=0;i<strlen(key);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,key[i]);
	}
	glLoadIdentity();
	glBegin(GL_QUADS);
	
	glColor3f(1,0.3,0.9);
	glVertex2f(2,2);
		glColor3f(0,0,0);
	glVertex2f(-2,2);
	
glColor3f(0,0,0);
	glVertex2f(-2,-2);
		glColor3f(0,0,0);
		
	glVertex2f(2,-2);
	
	glEnd();
	glColor3f(1,1,1);
	sphere();

	glutSwapBuffers();
}
