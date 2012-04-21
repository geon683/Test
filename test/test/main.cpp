#include <conio.h>
#include <iostream>
#include <string>
#include <glut.h>

using namespace std;

bool* keyStates = new bool[256];
bool* keySpecialStates = new bool[256];
int checker = 1;
int hardMode = 1;// activate hardmode

class ClawMachine
{
	private:

	float clawx, clawz, 
	prizex[8], prizey[8], prizez[8], 
	lowering, lowering2, 
	rotator,
	counter1; 

	bool clawWorking;
	bool clawDown;
	bool clawUp;
	bool clawGrab;
	bool clawRight;
	bool clawLeft;//activates claw to move left
	bool clawBack;//activates claw to move back
	bool clawForward;
	bool clawRelease;
	bool prizePick[8];
	bool prizeDrop[8];
	bool prizeAlive[8];

	public:
	
	ClawMachine()
	{
		clawx = 1, clawz = 2.5;
		prizex[0] = -1, prizey[0] = -8, prizez[0] = 2.5;
		prizex[1] = 1, prizey[1] = -8, prizez[1] = 2.5;
		prizex[2] = -3, prizey[2] = -8, prizez[2] = 2.5;
		prizex[3] = 3, prizey[3] = -8, prizez[3] = 2.5;
		prizex[4] = -1, prizey[4] = -8, prizez[4] = -2.5;
		prizex[5] = 1, prizey[5] = -8, prizez[5] = -2.5;
		prizex[6] = -3, prizey[6] = -8, prizez[6] = -2.5;
		prizex[7] = 3, prizey[7] = -8, prizez[7] = -2.5;
		lowering = 0, lowering2 = 0, rotator = -30; 

		clawWorking = false;
		clawDown = true;
		clawUp = false;
		clawGrab = false;
		clawRight = false;
		clawForward = false;
		clawRelease = false;

		for(int counter = 0; counter < 8; counter++)
		{
			prizePick[counter] = false;
			prizeDrop[counter] = false;
			prizeAlive[counter] = true;
		}

	}

	void moveclaw()
	{
		clawx = 1;
		clawz = 2.5;
	}



	void clawR()
	{
		clawx +=0.25;
	}

	void clawL()
	{

		clawx -=0.25;
	}

	void clawF()
	{
		clawz -=0.25;
	}

	void clawB()
	{
		clawz +=0.25;
	}




	void clawAnimation()
	{
		
		if(clawWorking)
		{
		
			if(lowering > 1)              
			{
				clawDown = false;
				clawGrab = true;
			}
		

			if(rotator > -20 && lowering > 1)//added "lowering > 1"
			{
				for(int counter = 0; counter < 8; counter++)
					if(prizex[counter] == clawx && prizez[counter] == clawz)
						prizePick[counter] = true;

				clawGrab = false;
				clawUp = true;
			}

			if(lowering < 0)
			{
				clawRight = true;
				clawUp = false;
			}


			if(clawx > 6)
			{
				clawRight = false;
				clawForward = true;
			}

			if(clawz > 5)
			{
				clawForward = false;
				clawRelease = true;
			}

			if(rotator < -30)
			{
				clawRelease = false;

				
				if(prizePick[0] && prizeAlive[0]) //added "prizeAlive[0-7]" to fix claw animation bug
				{
					prizeDrop[0] = true;

					if(prizey[0] < -8)
					{
						prizePick[0] = false;
						prizeDrop[0] = false;
						prizeAlive[0] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30;
						checker = 1;
					}
				}

				else if(prizePick[1] && prizeAlive[1])
				{
					prizeDrop[1] = true;

					if(prizey[1] < -8)
					{
						prizePick[1] = false;
						prizeDrop[1] = false;
						prizeAlive[1] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30; 
						checker = 1;
					}
				}

				else if(prizePick[2] && prizeAlive[2])
				{
					prizeDrop[2] = true;

					if(prizey[2] < -8)
					{
						prizePick[2] = false;
						prizeDrop[2] = false;
						prizeAlive[2] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30;
						checker = 1;
					}
				}


				else if(prizePick[3] && prizeAlive[3])
				{
					prizeDrop[3] = true;

					if(prizey[3] < -8)
					{
						prizePick[3] = false;
						prizeDrop[3] = false;
						prizeAlive[3] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30;
						checker = 1;
					}
				}

				else if(prizePick[4] && prizeAlive[4])
				{
					prizeDrop[4] = true;

					if(prizey[4] < -8)
					{
						prizePick[4] = false;
						prizeDrop[4] = false;
						prizeAlive[4] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30; 
						checker = 1;
					}
				}

				else if(prizePick[5] && prizeAlive[5])
				{
					prizeDrop[5] = true;

					if(prizey[5] < -8)
					{
						prizePick[5] = false;
						prizeDrop[5] = false;
						prizeAlive[5] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30;
						checker = 1;
					}
				}


				else if(prizePick[6] && prizeAlive[6])
				{
					prizeDrop[6] = true;

					if(prizey[6] < -8)
					{
						prizePick[6] = false;
						prizeDrop[6] = false;
						prizeAlive[6] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30;
						checker = 1;
					}
				}

				else if(prizePick[7] && prizeAlive[7])
				{
					prizeDrop[7] = true;

					if(prizey[7] < -8)
					{
						prizePick[7] = false;
						prizeDrop[7] = false;
						prizeAlive[7] = false;
						clawLeft = true;
						lowering = 0;
						lowering2 = 0;
						rotator = -30;
						checker = 1;
					}
				}


				else
				{
				clawLeft = true;
				lowering = 0;
				lowering2 = 0;
				rotator = -30;
				checker = 1;
				}
				
			}

			if(clawx < 1 && !clawRight && !clawForward && !clawDown && !clawGrab && !clawRelease && !clawUp)
			{
				clawLeft = false;
				clawBack = true;
			}

			if(clawz < 2.5 && !clawRight && !clawForward && !clawDown && !clawGrab && !clawRelease && !clawUp)
			{
				clawBack = false;
				clawDown = true;
				clawWorking = false;
				clawx = 1;
				clawz = 2.5; 
			}
			




	for(int counter = 0; counter < 8; counter++)
	{
		if(prizePick[counter])
		{

			if(prizeDrop[counter])
			{
				prizey[counter] -= 0.1;
			}
			else
			{
				prizex[counter] = clawx;
				prizey[counter] = -2.6-lowering2;
				prizez[counter] = clawz;
			}
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

		if(clawLeft)
			clawx -= 0.1;

		if(clawForward)
			clawz += 0.1;

		if(clawBack)
			clawz -= 0.1;
		}
	}

	void clawAnimation2()
	{
		if(!clawWorking)
		{
			if(clawRight)
			{
				clawx += 0.25;
				counter1 += 0.25;
			}

			if(clawLeft)
			{
				clawx -= 0.25;
				counter1 += 0.25;
			}
			if(clawForward)
			{
				clawz += 0.25;
				counter1 += 0.25;
			}

			if(clawBack)
			{
				clawz -= 0.25;
				counter1 += 0.25;
			}

			if(clawLeft || clawRight)
				if(counter1 == 2)
				{
					clawRight = false;
					clawLeft = false;
					counter1 = 0;
				}

			if(clawForward || clawBack)
				if(counter1 == 5)
				{
					clawForward = false;
					clawBack = false;
					counter1 = 0;
				}
		}


		
	}

	void claw()
	{
		float White [4] = { 1, 1, 1, 1};
		float Gray [4] = { .6, .6, .6, 1};
		float GrayL [4] = { .99, .99, .99, 1};
		float GrayD [4] = { .3, .3, .3, 1};
		float Sakura [4] = { 0.8, 0.7, 0.7, 1};
		float TicklePink [4] = { 1.78, .34, .34, 1};

		if(!clawWorking)
		{
			if(clawz>=2.5)
				clawz=2.5;
			if(clawz<=-2.5)
				clawz=-2.5;

			if(clawx>=3)
				clawx=3;
			if(clawx<=-3)
				clawx=-3;
		}


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

	}

	bool prize()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[0])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				
				if(prizeAlive[0])
					glTranslatef(prizex[0], prizey[0], prizez[0]);
				else
				{
					prizex[0] = -1, prizey[0] = -8, prizez[0] = 2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[0])
		return true;

	}

	bool prize2()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[1])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				
				if(prizeAlive[1])
					glTranslatef(prizex[1], prizey[1], prizez[1]);
				else
				{
					prizex[1] = 1, prizey[1] = -8, prizez[1] = 2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[1])
		return true;

	}

	bool prize3()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[2])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				

		
				if(prizeAlive[2])
					glTranslatef(prizex[2], prizey[2], prizez[2]);
				else
				{
					prizex[2] = -3, prizey[2] = -8, prizez[2] = 2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[2])
		return true;
	}

	bool prize4()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[3])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				

		
				if(prizeAlive[3])
					glTranslatef(prizex[3], prizey[3], prizez[3]);
				else
				{
					prizex[3] = 3, prizey[3] = -8, prizez[3] = 2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[3])
		return true;
	}

	bool prize5()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[4])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				

		
				if(prizeAlive[4])
					glTranslatef(prizex[4], prizey[4], prizez[4]);
				else
				{
					prizex[4] = -1, prizey[4] = -8, prizez[4] = -2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[4])
		return true;
	}

	bool prize6()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[5])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				

		
				if(prizeAlive[5])
					glTranslatef(prizex[5], prizey[5], prizez[5]);
				else
				{
					prizex[5] = 1, prizey[5] = -8, prizez[5] = -2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[5])
		return true;
	}

	bool prize7()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[6])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				

		
				if(prizeAlive[6])
					glTranslatef(prizex[6], prizey[6], prizez[6]);
				else
				{
					prizex[6] = -3, prizey[6] = -8, prizez[6] = -2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[6])
		return true;
	}

	bool prize8()
	{
		float Gray [4] = { .6, .6, .6, 1};

		glPushMatrix();
			glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Gray);

				if(prizeAlive[7])
					glScalef(1.0, 1.0, 1.0);
				else
					glScalef(0.0, 0.0, 0.0);
				

		
				if(prizeAlive[7])
					glTranslatef(prizex[7], prizey[7], prizez[7]);
				else
				{
					prizex[7] = 3, prizey[7] = -8, prizez[7] = -2.5;
				}
						
				glPushMatrix();
					glScalef(1.5,1,1.5);
					glutSolidCube(1);
				glPopMatrix();

			glPopAttrib;
		glPopMatrix();


	if(prizeAlive[7])
		return true;
	}
	

	bool setClawWorking(bool input)
	{
		clawWorking = input;

		return clawWorking;
	}

	void setClawRight()
	{
		clawRight = true;
	}

	void setClawLeft()
	{
		clawLeft= true;
	}

	void setClawForward()
	{
		clawForward = true;
	}

	void setClawBack()
	{
		clawBack = true;
	}

	void replenishPrize()
	{
		for(int counter = 0; counter < 8; counter++)
			prizeAlive[counter] = true;
	}

	void replenishPrize2()
	{
		for(int counter = 0; counter < 8; counter++)
			prizeAlive[counter] = false;
	}
	
};


//bool for light
bool Light=true;
bool prizeAlive[8] = {true, true, true, true, true, true, true, true};

//contains the angle control variables
float Angle = 10.0;
float Angle2 = 0.0;
float clawx = 0, clawz = 0;

//contains all the color I used
float White [4] = { 1, 1, 1, 1};
float Gray [4] = { .6, .6, .6, 1};
float GrayL [4] = { .99, .99, .99, 1};
float GrayD [4] = { .3, .3, .3, 1};
float Sakura [4] = { 0.8, 0.7, 0.7, 1};
float TicklePink [4] = { 1.78, .34, .34, 1};


ClawMachine object;



void keyPressed(unsigned char key, int x, int y)
{
    /* avoid thrashing this procedure. Uncomment the line if using gcc */

    //usleep(100);

    /* If escape is pressed, kill everything. */

	keyStates[key] = true;

	switch(key)
	{
	case 'w':
		Angle+=2;
		break;

	case 's':
		Angle-=2;
		break;
	
	case 'a':
		Angle2-=2;
		break;

	case 'd':
		Angle2+=2;
		break;

	case 'r':
		if(checker == 1)
		{
		object.replenishPrize();
		object.moveclaw();
		}
		break;

	case 'e':
		if(checker == 1)
		object.replenishPrize2();
		break;

	case ' ':
		checker = 0;
		object.setClawWorking(true);
		break;

	case 'o':
		hardMode = 0;
		object.moveclaw();
		break;

	case 'p':
		hardMode = 1;
		break;



	}
}

void keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}

void specialKeyPressed(int key, int x, int y)
{
	keySpecialStates[key] = true;
}

void specialKeyUp(int key, int x, int y)
{
	keySpecialStates[key] = false;

	if(hardMode == 0)
	{
		switch(key)
		{

				case GLUT_KEY_UP:
					{
						if(checker == 1)
							object.setClawBack();
					}
					break;

				case GLUT_KEY_DOWN:
					{
						if(checker == 1)
							object.setClawForward();
					}
					break;
	
				case GLUT_KEY_LEFT:
					{
						if(checker == 1)
							object.setClawLeft();
					}
					break;

				case GLUT_KEY_RIGHT:
					{
						if(checker == 1)
							object.setClawRight();
					}
					break;
		
		}
	}
}

void keyOperations()
{

	if(hardMode == 1)
	{
		if(keySpecialStates[GLUT_KEY_UP] == true)
		{
			if(checker == 1)
				object.clawF();
		}
		if(keySpecialStates[GLUT_KEY_DOWN] == true)
		{
			if(checker == 1)
				object.clawB();
		}
		if(keySpecialStates[GLUT_KEY_LEFT] == true)
		{
			if(checker == 1)
				object.clawL();
		}
		if(keySpecialStates[GLUT_KEY_RIGHT] == true)
		{
			if(checker == 1)
				object.clawR();
		}
	}
}

void GameScene()
{
	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glPushMatrix();

		glTranslatef(0, 1.0f, -10.0f);
		glRotatef(Angle, 1, 0, 0);
		glRotatef(Angle2, 0, 1, 0);

	object.clawAnimation();
	object.clawAnimation2();
	object.claw();

	if(prizeAlive[0])
		prizeAlive[0] = object.prize();

	if(prizeAlive[1])
		prizeAlive[1] = object.prize2();
	
	if(prizeAlive[2])
		prizeAlive[2] = object.prize3();

	if(prizeAlive[3])
		prizeAlive[3] = object.prize4();

	if(prizeAlive[4])
		prizeAlive[4] = object.prize5();

	if(prizeAlive[5])
		prizeAlive[5] = object.prize6();
	
	if(prizeAlive[6])
		prizeAlive[6] = object.prize7();

	if(prizeAlive[7])
		prizeAlive[7] = object.prize8();

//CRANE CASE
/////////////////////////////////////////////////////////////////////////////

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
				glScalef(15,.5,15);
				glutSolidCube(1);
				

			glPopAttrib;
		glPopMatrix();

	

		for(float counter = 0; counter <= 360; counter += 90)
		{

			glPushMatrix();
				glRotatef(45, 0.0f, 1.0f, 0.0f);
				glRotatef(counter, 0.0f, 1.0f, 0.0f);

				glTranslatef( 0.0f, -4.0f, -6.0f);
				glRotatef(45, 0.0f, 1.0f, 0.0f);

				glPushAttrib(GL_LIGHTING | GL_CURRENT_BIT);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, GrayL);

				glScalef(0.5, 9, 0.5);
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

	glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyUp);
	glutSpecialFunc(&specialKeyPressed);
	glutSpecialUpFunc(&specialKeyUp);

	/* Lighting */
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_NORMALIZE);


	glutMainLoop();

	return 0;
}



