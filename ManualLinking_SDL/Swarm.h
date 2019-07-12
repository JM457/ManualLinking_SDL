#pragma once
#include"Particle.h"
class Swarm {
public:
	const static int NPARTICLES=5000;

private:
	Particle* m_pParticle;

public:
	Swarm();
	virtual ~Swarm();
	const Particle* const getParticle() { return m_pParticle; };
};

