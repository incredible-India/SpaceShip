void earth();
void stars();
void moon();
void rocket();
void satellite();
void solar()
{
	extern float rocketVibrate,satelliteTranslate,stlteY;
	extern float EarthAndMoonRotation,satelliteRotate;
	extern int launch;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glLoadIdentity();
		
		glPushMatrix();
		stars();
		glPopMatrix();
		
			glPushMatrix();
		glColor3f(1,1,1);
		
			moon();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0,0,1);
		
			earth();
		glPopMatrix();
		/**************/

		
		
		//rocket
			glPushMatrix();
		glLoadIdentity();
		
		glTranslatef(-0.3,0.0,0);
		glTranslatef(rocketVibrate,0,0);
		rocket();
	
			glPopMatrix();
	
			//satellite
				glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	
	if(launch == 0)
		{
			glTranslatef(-1.0,0.4,0);
		glRotatef(90,0,0,1);
		}
	if(launch)
	{
	glLoadIdentity();
		glTranslatef(satelliteTranslate,stlteY,0);
		
		glRotatef(satelliteRotate,0,0,1);
	
	}
	satellite();
	glPopMatrix();
		
		glutSwapBuffers();
}


void earth()
{
	extern float EarthAndMoonRotation;
		GLfloat pos[] = {1,1,1,1};
	GLfloat col[] = {1,1,1,1};
	GLfloat col2[] = {1,1,1,1};

	glLoadIdentity();
	
			glLightfv(GL_LIGHT0,GL_POSITION,pos);
		
			glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
			glLightfv(GL_LIGHT0,GL_SPECULAR,col2);
			glVertex3f(1,0,0);
			glTranslatef(0.2,-0.5,0);
			glRotatef(EarthAndMoonRotation,0,1,1);
 			glutSolidSphere(0.7,100 ,10);
	
}

void moon()

{
	extern float EarthAndMoonRotation;
	extern float moonx,moonz;
		GLfloat pos[] = {1,1,1,1};
	GLfloat col[] = {1,1,1,1};
	GLfloat col2[] = {1,1,1,1};

	glLoadIdentity();
	
			glLightfv(GL_LIGHT0,GL_POSITION,pos);
		
			glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
			glLightfv(GL_LIGHT0,GL_SPECULAR,col2);
			glVertex3f(1,0,0);
			glTranslatef(-0.3,0.5,0);
			glTranslatef(moonx,-1.2,moonz);
			glRotatef(EarthAndMoonRotation,0,1,1);
 			glutSolidSphere(0.2,24 ,10);
}



void satellite()
{
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(0.45,0.13,-1.5);

	glutSolidCube(0.2);
	glPopMatrix();
	
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex3f(0.32,0.15,0);
	glVertex3f(0.57,0.15,0);

	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);
	
	glVertex3f(0.3,0.2,0);
	glVertex3f(0.0,0.2,0);
	glVertex3f(0.0,0.1,0);
	glVertex3f(0.3,0.1,0);
	glVertex3f(0.3,0.2,0);
	
	glEnd();
	
	glColor3f(1,1,1);
		glBegin(GL_LINE_STRIP);
	
	glVertex3f(0.6,0.2,0);
	glVertex3f(0.9,0.2,0);
	glVertex3f(0.9,0.1,0);
	glVertex3f(0.6,0.1,0);
	glVertex3f(0.6,0.2,0);
	
	glEnd();
}
void rocket()
{
	extern float yDir;
	//right trianle
	glBegin(GL_TRIANGLES);
	
		
glColor3f (1, 0.4, 0.2);
	glVertex2f(-0.5,0.4);
	
	
	glVertex2f(-0.7,0.8);

	glVertex2f(-0.7,0.4);
	
	glEnd();
	
	
		//left trianle
		
	glBegin(GL_TRIANGLES);
	glColor3f (1, 0.4, 0.2);
	glVertex2f(-1.0,0.4);
	glVertex2f(-1.0,0.8);
	glVertex2f(-1.2,0.4);
	
	glEnd();
	
	
	//body
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	
	glVertex2f(-0.7,1.4);
	glVertex2f(-1.0,1.4);
	glVertex2f(-1.0,0.5);
	glVertex2f(-0.7,0.5);
	glEnd();
	
	
		//flame
		
	glBegin(GL_TRIANGLES);
		glColor3f(0,0,1);
	glVertex2f(-0.7,0.5);
		glColor3f(0,0,1);
	glVertex2f(-1.0,0.5);
		glColor3f(0,0,0);
		
	glVertex2f(-0.85,0.0);
	
	glEnd();
	
	//top
	glBegin(GL_TRIANGLES);
		glColor3f(1,0,1);
	glVertex2f(-0.7,1.4);
		glColor3f(0,1,1);
	glVertex2f(-0.85,1.7);
		glColor3f(0,0,0);
		
	glVertex2f(-1.0,1.4);
	
	glEnd();

	glColor3f(0,1,0);
	glRasterPos3f(-0.86,1.29,1);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'I');
	
	glColor3f(0,1,0);
	glRasterPos3f(-0.87,1.19,1);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
	
	
	glColor3f(0,1,0);
	glRasterPos3f(-0.88,1.09,1);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
	
	
	glColor3f(0,1,0);
	glRasterPos3f(-0.88,0.99,1);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'O');
	
//	India flag orange strip
	glLineWidth(9);
	
	glColor3f(1, 0.4, 0.2);

	glBegin(GL_LINES);

	glVertex3f(-1.0,0.7,1);

	glVertex3f(-0.7,0.7,1);

	glEnd();
	//green strip
		glLineWidth(9);
	glColor3f (0.2, 1, 0.2);
	glBegin(GL_LINES);

	glVertex3f(-1.0,0.6,1);

	glVertex3f(-0.7,0.6,1);

	glEnd();
////top left trianle
//
//	glBegin(GL_TRIANGLES);
//	
//			glColor3f (1, 0.4, 0.2);
//	glVertex2f(-1.0,1.4);
//	
//	glVertex2f(-1.2,1.1);
//			
//	glVertex2f(-1.0,1.1);
//	
//	glEnd();
//	
//	
//	//top Right trianle
//
//	glBegin(GL_TRIANGLES);
//	
//			glColor3f (1, 0.4, 0.2);
//	glVertex2f(-0.7,1.4);
//	
//	glVertex2f(-0.7,1.1);
//			
//	glVertex2f(-0.5,1.1);
//	
//	glEnd();
}
//stars 
void stars()
{
	
	extern float xDir,yDir;
	extern int starSize;
	glLoadIdentity();
	
	glTranslatef(xDir,yDir,0.0);
	
	glPointSize(4);
	glBegin(GL_POINTS);
	
	glVertex2f(0.1,0.3);
	glVertex2f(-1.9,0.3);
	glVertex2f(-2.0,-0.3);
	glVertex2f(0.6,-0.5);
	glVertex2f(1.1,1.3);
	glVertex2f(0.1,-1.3);
	glVertex2f(0.1,-1.6);
	glVertex2f(-0.7,-0.3);
	glVertex2f(1.4,-2.0);
	glVertex2f(-1.7,1.9);
	glColor3f(0.0,0,1);
	glVertex2f(-1.6,1.5);
	glColor3f(0.0,0,1);
	glVertex2f(-2.0,-1.7);
	glColor3f(0.0,0,1);
	glVertex2f(-2,2.0);
	glColor3f(0.0,0,1);
	glVertex2f(-0.7,1.5);
	glColor3f(0.0,0,1);
	glVertex2f(-0.1,-0.5);
	glColor3f(0.4,1,0.7);
	glVertex2f(-0.8,2.0);
	glColor3f(0.4,1,0.7);
	glVertex2f(-1.5,5.3);
	glVertex2f(1.1,-0.3);
	glColor3f(0.0,0,1);
	glVertex2f(0.1,-0.3);
	glVertex2f(-0.1,0.3);
	glVertex2f(-0.1,-0.3);
	glVertex2f(-1.9,-0.3);
	glColor3f(0,1,0.7);
	glVertex2f(2.1,1.9);
	glVertex2f(0.7,0.8);
	glColor3f(0,1,0.7);
	glVertex2f(0.5,0.3);
	glVertex2f(0.5,0.5);
	glVertex2f(1,20);
	glColor3f(0,1,0.7);
	glVertex2f(0,0);
	glColor3f(0,1,0.7);
	glVertex2f(0.1,1.3);
	glColor3f(0,1,0.7);
	glVertex2f(1.1,3.3);
		glColor3f(0.4,1,0.7);
	glVertex2f(2.1,1.3);
	glColor3f(0.4,1,0.7);
	glVertex2f(-0.7,1.3);
	glColor3f(0.4,1,0.7);
	glVertex2f(-1.7,0.3);
	glColor3f(0.4,1,0.7);
	glVertex2f(-1.9,-1.3);
	glVertex2f(-1.7,1.3);
	glVertex2f(-1.1,1.1);
	glColor3f(0.4,1,0.7);
	glColor3f(1,0,0);
	glVertex2f(-0.6,-0.3);
	glColor3f(0.4,1,0.7);
		glColor3f(1,0,0);
	glVertex2f(-0.7,-1.5);
	glVertex2f(-2,-1.6);
	glVertex2f(-0.6,-1.7);
		glColor3f(1,0,0);
	glVertex2f(-0.4,1.3);
	glVertex2f(-1.7,2.1);
		glColor3f(1,0,0);
	glVertex2f(-1.9,1.3);
	glVertex2f(-1.2,1.2);
	glVertex2f(-0.2,1.2);
		glColor3f(1,0,0);
	glVertex2f(0.7,-1.9);
	
	glVertex2f(-0.7,-1.9);
	glVertex2f(-0.1,-1.9);
	glVertex2f(-0.2,-1.9);
	glVertex2f(-0.3,-1.9);
	glVertex2f(-0.4,-1.9);
	glVertex2f(-0.5,-1.9);
	glVertex2f(-0.6,-0.9);
	glVertex2f(-0.7,-1.5);
	glVertex2f(-0.8,-1.4);
	glVertex2f(-0.9,-1.3);
	glVertex2f(-1.1,-1.2);
	glVertex2f(-1.2,1.9);
	glVertex2f(-1.3,1.0);
	glVertex2f(-1.4,1.5);
	glVertex2f(-1.5,1.4);
	glVertex2f(-1.6,1.3);
	glVertex2f(-1.7,-1.2);
	glVertex2f(-1.8,-1.0);
	

	glEnd();
}

