#ifndef SIMPLE_PARTICLE_H
#define SIMPLE_PARTICLE_H

#include "ParticleBase.h"
#include <gtkmm/drawingarea.h>

class SimpleParticle : public ParticleBase
{
public:
    SimpleParticle(int x, int y, int w, int h)
      : ParticleBase(x, y, w, h) {};
    virtual ~SimpleParticle() {};
    virtual void draw(int win_height, int win_width, 
  		const Cairo::RefPtr<Cairo::Context>& cr) const;
    virtual void tick(long t);
};

#endif