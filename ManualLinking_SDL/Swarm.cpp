#include "Swarm.h"


Swarm::Swarm()
{
	m_pParticle = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
	delete[] m_pParticle;
}

void Swarm::update(int elapsed)
{
	int interval = elapsed - m_lastTime;
	for (size_t i = 0; i < NPARTICLES; i++)
	{
		m_pParticle[i].update(interval);
	}
	m_lastTime = elapsed;
}
