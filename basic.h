//init Function
void init()
{
	glClearColor(0.0,0.0,0.0,1.0); //black color background

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	glEnable(GL_COLOR_MATERIAL);
}
//reshape function
void reshape(int w ,int h)
{
	glViewport(0,0,w,h);
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();

	glOrtho(-2,2,-2,2,-2,2);
//	glFrustum(-1,1,-1,1,1,10);
	
	glMatrixMode(GL_MODELVIEW);
	
	
}


