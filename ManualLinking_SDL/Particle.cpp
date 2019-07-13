#include "Particle.h"
#include<cstdlib>
Particle::Particle()
{
	m_x = (2.0 * rand() / RAND_MAX) - 1;
	m_y = (2.0 * rand() / RAND_MAX) - 1;
}

Particle::~Particle()
{
}

void Particle::update()
{
	const double speed = 0.001;
	m_x += speed;
	m_y += speed;
}
