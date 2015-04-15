#include "Splendido.h"
#include "ParticlePlayground.h"
#include "SimApp.h"
#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

//for finding relative distance
int taxicab(int x1,int y1,int x2,int y2){
	return abs(x1-x2) + abs(y1-y2);
}

void Splendido::draw(int win_height, int win_width, 
  const Cairo::RefPtr<Cairo::Context>& cr)
{
    win_width = win_width * SimApp::getMetersPerPixel();
    win_height =  win_height * SimApp::getMetersPerPixel();

    if(getX() > win_width)
        setX(0);
    else if(getX() < 0)
        setX(win_width);
    if(getY() > win_height)
        setY(0);
    else if(getY() < 0)
        setY(win_height);
    
    double xpix = getX() / SimApp::getMetersPerPixel();
    double ypix = getY() / SimApp::getMetersPerPixel();
    double wpix = getW() / SimApp::getMetersPerPixel();
    double hpix = getH() / SimApp::getMetersPerPixel();

    cr->save();

    cr->set_line_width(1.0);

    if(rogue)
    	cr->set_source_rgba(0.0, 0.8, 0.0, 0.6);
    else if(happy)
    	cr->set_source_rgba(0.8, 0.0, 0.0, 0.6);
    else 
    	cr->set_source_rgba(0.0, 0.0, 0.8, 0.6);

    cr->arc(xpix, ypix, wpix / 2.0, 0.0, 2.0 * M_PI);

    cr->fill_preserve();
    cr->stroke();

    cr->restore();
}

void Splendido::tick(long t)
{
	if(!rogue)
		happy = avoid();

	double deltaX = ((getVX() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());
	double deltaY = ((getVY() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());

	setX(getX() + deltaX);
	setY(getY() + deltaY);
}

/*
	LOGIC:  If my next step isn't going to take me further away from the closest
			Particle within 50 meters of myself turn around.
*/
bool Splendido::avoid(){
	Splendido* close = closest();
	int x1pix = getX();
	int y1pix = getY();
	int x2pix = close->getX();
	int y2pix = close->getY();

	double dis = Splendido::distance(close);

	// Extra:	If a rogue collides with me, I 'go rogue'. //
	/*if(dis * SimApp::getMetersPerPixel() < getW() * SimApp::getMetersPerPixel() 
			&& close->isRogue())
		toggleRogue();
	else*/ if(taxicab(x1pix,y1pix,x2pix,y2pix) > taxicab(x1pix+m_vX,y1pix+m_vY,x2pix,y2pix)
			&& dis * SimApp::getMetersPerPixel() < 50)
		reverse();

	//convert dis from pix to meters and compare to 50 meters
	return dis * SimApp::getMetersPerPixel() > 50;
}

Splendido* Splendido::closest(){
	Splendido* close = m_particles[0];
	int dis = INT_MAX;
	for(int i(0);i<m_particles.size();i++){
		int x1pix = getX() / SimApp::getMetersPerPixel();
		int y1pix = getY() / SimApp::getMetersPerPixel();
		int x2pix = m_particles[i]->getX() / SimApp::getMetersPerPixel();
		int y2pix = m_particles[i]->getY() / SimApp::getMetersPerPixel();
		if(taxicab(x1pix,y1pix,x2pix,y2pix) < dis && m_particles[i] != this){
			dis = taxicab(x1pix,y1pix,x2pix,y2pix);
			close = m_particles[i];
		}
	}
	return close;
}

double Splendido::distance(Splendido* s){
	int x1pix = getX() / SimApp::getMetersPerPixel();
	int y1pix = getY() / SimApp::getMetersPerPixel();
	int x2pix = s->getX() / SimApp::getMetersPerPixel();
	int y2pix = s->getY() / SimApp::getMetersPerPixel();
	return sqrt((pow(x1pix-x2pix,2))+(pow(y1pix-y2pix,2)));
}

void Splendido::reverse(){
	//printf("reverse\n");
	setVX(m_vX * -1);
	setVY(m_vY * -1);
}