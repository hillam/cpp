#include "SimpleParticle.h"
#include <iostream>

using namespace std;

void SimpleParticle::draw(int win_height, int win_width, 
  const Cairo::RefPtr<Cairo::Context>& cr) const
{
  cr->save();

  cr->set_line_width(1.0);

  cr->set_source_rgba(0.0, 0.0, 0.8, 0.6);
  cr->arc(getX(), getY(), getW() / 2.0, 0.0, 2.0 * M_PI);
  cr->fill_preserve();
  cr->stroke();

  cr->restore();
}

void SimpleParticle::tick(long t)
{
}
