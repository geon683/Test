#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <glut.h>



//bool for light
bool Light=true;

//contains all my special check on variables
int FLight = 0, Switch = 0;

//contains my counter and/or loop variables
float x, y, z;
float clawx = 0, clawz = 0;
float prizex = 0, prizey = -8, prizez = 0;
float lowering = 0, lowering2 = 0, rotator = -30; 

bool clawWorking = false;
bool clawDown = true;
bool clawUp = false;
bool clawGrab = false;
bool clawRight = false;
bool clawForward = false;
bool clawRelease = false;
bool prizePick = false;
bool prizeDrop = false;

//contains the angle control variables
float Angle = 10.0;
float AngleV = 0.0;


//contains all the color I used
float White [4] = { 1, 1, 1, 1};
float Gray [4] = { .6, .6, .6, 1};
float GrayL [4] = { .99, .99, .99, 1};
float GrayD [4] = { .3, .3, .3, 1};
float Sakura [4] = { 0.8, 0.7, 0.7, 1};
float TicklePink [4] = { 1.78, .34, .34, 1};


void GameScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if(clawWorking)
	{
		
		if(lowering > 1)              
		{
			clawDown = false;
			clawGrab = true;
		}
		

		if(rotator > -20)
		{
			if(prizex == clawx)
				prizePick = true;

			clawGrab = false;
			clawUp = true;
		}

		if(lowering < 0)
		{
			clawUp = false;
			clawRight = true;
		}


		if(clawx > 5)
		{
			clawRight = false;
			clawForward = true;
		}

		if(clawz > 3)
		{
			clawForward = false;
			clawRelease = true;
		}

		if(rotator < -30)
		{
			clawRelease = false;
			if(prizePick)
			{
				prizeDrop = true;
				if(prizey < -8)
				{
					prizePick = false;
					prizeDrop = false;
					clawDown = true;
					clawWorking = false;
					lowering = 0;
					lowering2 = 0;
					rotator = -30;

				}
			}
			else
			{
			clawDown = true;
			clawWorking = false;
			lowering = 0;
			lowering2 = 0;
			rotator = -30;
			}

		}
		





		if(prizePick)
		{
			

			if(prizeDrop)
			{
				prizey -= 0.1;
			}
			else
			{
				prizex = clawx;
				prizey = -2.6-lowering2;
				prizez = clawz;

			}
		}

		


			if(clawDown)
			{
				lowering += 0.01;
				lowering2 += 0.053;
			}
			else if(clawUp)
			{
				lowering -= 0.01;
				lowering2 -= 0.053;
			}
			


		if(clawGrab)
			rotator += 1;

		if(clawRelease)
			rotator -= 1;


		if(clawRight)
			clawx += 0.1;

		if(clawForward)
			clawz += 0.1;
	}

	



	



	glPushMatrix();

		////Wall
		//	glPushMatrix();
		//		glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
		//		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, White);
		//			glScalef ( 90, 90, .05);
		//			glTranslatef( 0, 0, -700);
		//			glutSolidCube(1);
		//		glPopAttrib;
		//	glPopMatrix();
 
		glTranslatef(0, 1.0f, -10.0f);
		glRotatef(Angle, 1, 0, 0);


//
//         00000000000       0000000000              00000          000000       0000     0000000000000        00           00
//        0000000000000      000000000000         00000 00000       0000000      0000     00000000000         00     0000    00
//       0000                000       000       00000   00000      0000 000     0000     00000              00    00000000   00
//       000                 000        000      0000     0000      0000  000    0000     0000               00   0000        00
//       000                 000        000     0000       0000     0000   000   0000     0000               00   000         00
//       000                 000       000      0000       0000     0000   0000  0000     0000               00   000         00
//       000                 000000000000       000000000000000     0000    000  0000     0000000000         00   0000        00
//       0000                000      0000      0000       0000     0000    0000 0000     0000               00    00000000   00
//        0000000000000      000       0000     0000       0000     0000     000 0000     00000000000         00     0000    00
//         00000000000       000        000     0000       0000     0000      0000000     0000000000000        00           00 
//

		glPushMatrix();

			glTranslatef(clawx, -3.0f, clawz);

			glPushMatrix();
				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);
									
				glTranslatef( 0, 3.7, 0);

						glPushMatrix();
							glScalef(1,.7,1);
							glRotatef(90, 1, 0, 0);
							glutSolidCube(1);
						glPopMatrix();

				glPopAttrib;
			glPopMatrix();
			
			glPushMatrix();
				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GrayD);
									
					glTranslatef( 0, 3.8, 0);

					glPushMatrix();
						glScalef(1,.06,1);
						glRotatef(90, 1, 0, 0);
						glutSolidCube(1.1);
					glPopMatrix();

				glPopAttrib;
			glPopMatrix();
			
			glPushMatrix();
				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GrayD);
									
					glTranslatef( 0, 3.5, 0);

					glPushMatrix();
						glScalef(1,.06,1);
						glRotatef(90, 1, 0, 0);
						glutSolidCube(1.1);
					glPopMatrix();

				glPopAttrib;
			glPopMatrix();

			glPushMatrix();
				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GrayD);
					
					glTranslatef( 0, 3.5, 0);
						
						
					glScalef(1,.3 + lowering, 1);
						

					for(float counter= -.5; counter >= -5 ; counter-= .5 )
					{
						glPushMatrix();
							glTranslatef( 0, counter, 0);
							glRotatef(90, 1, 0, 0);
								glutSolidSphere(.3, 50, 50);
						glPopMatrix();

					}

					for(float counter = -.25; counter >= -5 ; counter-= .5 )
					{
						glPushMatrix();
							glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
							glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, White);
									
								glPushMatrix();
									glTranslatef( 0, counter, 0);
									glScalef(1,1,1);
									glRotatef(90, 1, 0, 0);
									glutSolidTorus(.1, .15, 40, 40);
								glPopMatrix();
					
							glPopAttrib;
						glPopMatrix();
					}


				glPopAttrib;
			glPopMatrix();



			glPushMatrix();
				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);
									
					glTranslatef( 0, 1.9 - lowering2, 0);
						
					glPushMatrix();
						glScalef(1,3,1);
						glRotatef(90, 1, 0, 0);
						glutSolidCube(.2);
					glPopMatrix();

				glPopAttrib;
			glPopMatrix();
            
            
            
			glPushMatrix();
				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);
									
					glTranslatef( 0, 1.7 - lowering2, 0);
						
					glPushMatrix();
						glScalef(1.5,1,1.5);
						glutSolidCube(.2);
					glPopMatrix();

				glPopAttrib;
			glPopMatrix();


			
			
			
			

			for(float counter=0; counter <=360; counter +=90)
			{
                        				
    			glRotatef(counter, 0, 1, 0);
                         
    			glPushMatrix();
    				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
    				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

    					glTranslatef( 0, 1.7 - lowering2, .15);
    						
    					glScalef(1.5,1.5,1.5);
    						
    					glPushMatrix();
    						glScalef(.5,1,3);
    						glutSolidCube(.1);
    					glPopMatrix();
    
    				glPopAttrib;
    			glPopMatrix();
    				
    			glPushMatrix();
    				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
    				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GrayD);
    					
    					     					
    					glTranslatef( 0, 1.65 - lowering2, .15);
    						
    					glRotatef(rotator, 1, 0, 0);
    						
    					glScalef(1.5,1.5,1.5);
    						
    						
    					glPushMatrix();
    					glRotatef(-40, 1, 0, 0);
    						glTranslatef( .05, -.35, .1);
    						glScalef(.5,6,1);
    						glutSolidCube(.1);
    					glPopMatrix();
    						
    					glPushMatrix();
    					glRotatef(-40, 1, 0, 0);
    						glTranslatef( -.05, -.35, .1);
    						glScalef(.5,6,1);
    						glutSolidCube(.1);
    					glPopMatrix();
    						
    					glPushMatrix();	
    						glTranslatef( 0, -.5, .45);
    						glScalef(.5,3,1);
    						glutSolidCube(.1);
    					glPopMatrix();
    						
    					glPushMatrix();	
    						glTranslatef( 0, -.85, .268); 
    						glRotatef(40, 1, 0, 0);
    						glScalef(.5,6,1);
    						glutSolidCube(.1);
    					glPopMatrix();
    
    				glPopAttrib;
    			glPopMatrix();				
				
			
            }

		glPopMatrix();

	
		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);
									
				glTranslatef(prizex, prizey, prizez);
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();

	///////////////////////////////////////////////////////////////////////////// crane case

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GrayL);
				
				glTranslatef(0, -8.5, 0);
				glScalef(9.5,.1,9.5);
				glutSolidCube(1);
				
			glPopAttrib;
		glPopMatrix();

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, TicklePink);
				
				glTranslatef(0, -8.8, 0);
				glScalef(10,.5,10);
				glutSolidCube(1);
				

			glPopAttrib;
		glPopMatrix();


		for(x=0; x <= 360; x+=90)
		{

			glPushMatrix();
				glRotatef(45, 0.0f, 1.0f, 0.0f);
				glRotatef(x, 0.0f, 1.0f, 0.0f);

				glTranslatef( 0.0f, -8.0f, -4.0f);
				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GrayL);

				glutSolidCube(1);

				glPopAttrib;
			glPopMatrix();
		}
				if (Light)
				{
				  glEnable(GL_LIGHT0);
				  glEnable(GL_LIGHTING);
	  			  glEnable(GL_NORMALIZE);
				}
				else
				{
				  glDisable(GL_LIGHT0);
				  glDisable(GL_LIGHTING);
	  			  glDisable(GL_NORMALIZE);
				}

	glPopMatrix();
	
	glutSwapBuffers();
}

/* controls the camera */
void ResizeWindow(int w, int h)
{
	float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0,0,w,h);

	gluPerspective(30.0, ratio, 1, 2000); 

	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

	gluLookAt(0, 10.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}

void Keys (unsigned char key, int x, int y)
{
	//contains all the keys to control the program
	switch(key)
	{
	//case 'r':
	//	{
	//		if (lowering>=.01)              
	//		{
	//			lowering-=.01;
	//			lowering2-=.053;
 
	//		} 
	//	}
	//	break;

	//case 'f':
	//	{
	//		if (lowering<=1)              
	//		{
	//			lowering+=.01;
	//			lowering2+=.053;
 
	//		}  
	//	}
	//	break;  
	//case 'q':
	//	{
	//		if (rotator>=-30)              
	//		{
	//			rotator-=1;  
  
	//		}                                              
	//	}
	//	break;
	//case 'e':
	//	{
	//		if (rotator<=-20)              
	//		{
	//			rotator+=1;;  
 
	//		}
	//	}
	//	break;

	//controls the camera to go around, counter-clockwise
	case 't':
		Angle-=2;
		break;
	//controls the camera to go around, clockwise
	case 'g':
		Angle+=2;
		break;

	case 'w':
		clawz-=0.5;
		break;
	case 's':
		clawz+=0.5;
		break;

	case 'a':
		clawx-=0.5;
		break;
	case 'd':
		clawx+=0.5;
		break;

	case 'c':
		clawWorking=true;
		break;

	}		
}

int main(int argc, char**argv)
{
	
	/* OpenGL Setup*/

	glutInit(&argc, argv); // arg is short for arguments
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	/* Setup drawing window */

	glutInitWindowPosition(50,50);
	glutInitWindowSize(1000,700);
	glutCreateWindow("Crane Game");


	/* glutReshapeFunc(ResizeWindow); */
	glutReshapeFunc(ResizeWindow);

	/* glutDisplayFunc(GameScene); */
	glutDisplayFunc(GameScene);
	
	glutIdleFunc(GameScene);
	glEnable(GL_DEPTH_TEST);

	glutKeyboardFunc(Keys);

	/* Lighting */
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_NORMALIZE);


	glutMainLoop();

	return 0;
}
