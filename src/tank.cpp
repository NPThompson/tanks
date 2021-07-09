#include<tank.h>
#include<object.h>
#include<math.h>



Tank::Tank ()
{
	position = point(50,50);
	speedMax = 2;
	turnRate = 0.1;
	speed = 0;
}



point Tank::getPosition ()
{
	return position;
}
	
	
	
void Tank::update (int frames)
{
	position += polarToCartesian (trackHeading, speed);
	
	speed = speedControl * speedMax;
	
	turretHeading += turretTurnControl * turnRate + trackTurnControl * turnRate;
;
	
	trackHeading  += trackTurnControl * turnRate;

	trackTurnControl = stepConverge (trackTurnControl, 0.3);	
	turretTurnControl = stepConverge (turretTurnControl, 0.3);
	speedControl = stepConverge (speedControl, 0.05);	

}
	


void Tank::move (float controlIntensity)	
{
	speedControl = signum(controlIntensity);	
}


float Tank::getTrackHeading ()
{
	return trackHeading;
}



float Tank::getTurretHeading ()
{
	return turretHeading;
}



void Tank::turnTrack (float controlIntensity)
{
	trackTurnControl = signum(controlIntensity);
}



void Tank::turnTurret (float controlIntensity)
{
	turretTurnControl = signum(controlIntensity);
}
