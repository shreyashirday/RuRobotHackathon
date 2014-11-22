#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "decepticon/decepticon.hpp"

using namespace cv;

int main() {
  Decepticon d;
  
  //////////////////////////
  // PLACE YOUR CODE HERE //
  //////////////////////////
  
  return 0;
}

public int turnsMade = 0;
public bool hasBall = false;

void turnLeft(Decepticon d, int speedToTurnAt)
{
turnsMade++;
d->left_speed = -speedToTurnAt;
d->right_speed = speedToTurnAt;
d.sendToArduino();
}

void turnRight(Decepticon d, int speedToTurnAt)
{
turnsMade--;
d->left_speed = speedToTurnAt;
d->right_speed = -speedToTurnAt;
d.sendToArduino();
}

void getBall(Decepticon d)
{
	if(d->left_speed > 0 || d -> right_speed > 0)
{
d::stop();
}
  
if(!hasBall && d->claw_pos < 90)
{
d::open();
}
else
{
d::close();
hasBall = true;
}
}

void releaseBall(Decepticon d)
{
	if(d->left_speed > 0 || d -> right_speed > 0)
{
d::stop();
}
  
if(hasBall && d->claw_pos < 90)
{
d::open();
hasBall = false;
}
}

void move(Decepticon d)
{
	//see if a ball is visible
		
		//if false, we either are about to grab the ball or already have it 
		if(hasBall)
		{
			//go back home
			d.backward();
			//we'll hit a wall to stop, then drop off the ball
			
			
			//drop off the ball
			while(turnsMade != 0)
			{
				//turn right until we're at 0 degrees rotated again
				if(turnsMade > 0) d.turnRight();
				//turn left until we're at 0 degrees rotated again
				if(turnsMade < 0) d.turnLeft();
				
				//drop off ball
				d.releaseBall(); //not implemented yet
			}
		}
		//otherwise, grab the ball
		else{
			d.getBall();
		}
	
	
	//else, turn left until a ball is visible
	turnLeft();
}

