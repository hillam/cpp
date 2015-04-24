#ifndef SPLENDIDO_H
#define SPLENDIDO_H

#include "ParticleBase.h"
#include "ParticlePlayground.h"
#include <gtkmm/drawingarea.h>
#include <stdlib.h>
#include <time.h>

enum type {fire,ice};

class Splendido : public ParticleBase
{
public:
	Splendido(vector<ParticleBase*>& p, double x, double y, double w, double h, 
			double vX, double vY)
			: ParticleBase(x, y, w, h), m_vX(vX), m_vY(vY), 
			m_particles((vector<Splendido*>&) p) {
		//srand(time(NULL));
		rogue = false;
		if(rand() % 2 == 1)
			m_type = fire;
		else
			m_type = ice;
	};
	virtual void draw(int win_height, int win_width, 
		const Cairo::RefPtr<Cairo::Context>& cr);
	virtual ~Splendido() {};
	virtual void tick(long t);

	double getVX() { return m_vX; }
	double getVY() { return m_vY; }
	bool isDead() { return dead; }
	bool isRogue() { return rogue; }
	void setVX(double vx) { m_vX = vx; }
	void setVY(double vy) { m_vY = vy; }

private:
	double m_vX;
	double m_vY;
	type m_type;
	bool dead;
	bool rogue;
	vector<Splendido*>& m_particles;

	void collide();
	Splendido* closest();
	double distance(Splendido* pb);
	int dotProduct(Splendido* pb);
	void reverse();
};

#endif