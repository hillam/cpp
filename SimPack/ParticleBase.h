#ifndef PARTICLE_BASE_H
#define PARTICLE_BASE_H

#include <gtkmm/drawingarea.h>
#include "TimeKeeper.h"

class ParticleBase : public TimeKeeper
{
public:
    ParticleBase(int x, int y, int w, int h)
      : m_x(x), m_y(y), m_w(w), m_h(h) {};
    
    virtual ~ParticleBase() {};
    
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getW() const { return m_w; }
    int getH() const { return m_h; }

    int setX(int x) { m_x = x; }
    int setY(int y) { m_y = y; }
    int setW(int w) { m_w = w; }
    int setH(int h) { m_h = h; }

    virtual void draw(int win_height, int win_width, 
  		const Cairo::RefPtr<Cairo::Context>& cr) const = 0;
    virtual void tick(long t) = 0;

private:
  int m_x;
  int m_y;
  int m_w;
  int m_h;
};

#endif