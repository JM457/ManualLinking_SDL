#pragma once
struct Particle
{
	double m_x;
	double m_y;
	
	double m_theta;
	double m_speed;

	double m_xvel;
	double m_yvel;

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

