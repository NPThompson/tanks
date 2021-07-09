#include<object.h>



class Tank : public Object
{
	public:
		Tank ();
		
		virtual void update (int);
		
		// controls
		void turnTrack (float controlIntensity);
		void turnTurret (float controlIntensity);

		void move (float controlIntensity);
		
		// read state
		float getTrackHeading ();
		float getTurretHeading ();
		
		point getPosition ();
		
	private:
		// state:
		
		// tracks Heading is absolute, turret Heading is relative to tracks
		// In radians, same as trig: 0 is right, pi/2 is up
		float trackHeading, turretHeading, speed;
		point position;
		
		// attributes:
		
		float acceleration, turnRate, speedMax;

		// controls:
		
		// 0.0 is no turn, -1.0 is max turn counterclockwise, 1.0 is max turn clockwise
		// values greater in magnitude than 1.0 are treated as having magnitude 1.0
		float trackTurnControl, turretTurnControl, speedControl;
};