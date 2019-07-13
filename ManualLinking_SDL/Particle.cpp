#include "Particle.h"
#include<cstdlib>
#include <SDL_stdinc.h>

Particle::Particle():m_x(0),m_y(0)
{
	m_theta = (2.0 * M_PI * rand())/ RAND_MAX ; // random value of theta in polat cord 0-2pi
	m_speed = (0.001 * rand()) / RAND_MAX;
}

Particle::~Particle()
{
}

void Particle::update()
{
	m_xvel = m_speed * cos(m_theta);
	m_yvel = m_speed * sin(m_theta);
	m_x += m_xvel;
	m_y += m_yvel;
}
