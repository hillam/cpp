#include "Splendido.h"
#include "ParticlePlayground.h"
#include "SimApp.h"
#include <iostream>
#include <climits>
#include <stdio.h>
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

	/*Glib::RefPtr<Gdk::Pixbuf> image = Gdk::Pixbuf::create_from_file("myimage.png"); 
	Gdk::Cairo::set_source_pixbuf(cr, image, x, y); 
	cr-‐‐>rectangle(110, 90, image-‐‐>get_width(), image-‐‐>get_height()); 
	cr-‐‐>fill(); */

	//cr->set_line_width(1.0);
	Glib::RefPtr<Gdk::Pixbuf> image1 = Gdk::Pixbuf::create_from_file("flame.png");
	Glib::RefPtr<Gdk::Pixbuf> image2 = Gdk::Pixbuf::create_from_file("snowflake.png");

	// CHANGE IMAGE //
	if(m_type == fire)
		Gdk::Cairo::set_source_pixbuf(cr,image1,xpix,ypix);
	else
		Gdk::Cairo::set_source_pixbuf(cr,image2,xpix,ypix);

	//cr->arc(xpix, ypix, wpix / 2.0, 0.0, 2.0 * M_PI);
	//cr->fill_preserve();
	//cr->stroke();

	cr->rectangle(xpix,ypix,image1->get_width(),image1->get_height());
	cr->fill();

	cr->restore();
}

void Splendido::tick(long t)
{
	//check for collision
	collide();

	//10% chance to increase velovity by 1m/s
	if(rand()%10 == 0)
		accelerate();

	double deltaX = ((getVX() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());
	double deltaY = ((getVY() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());

	setX(getX() + deltaX);
	setY(getY() + deltaY);
}

void Splendido::collide(){
	Splendido* close = closest();

	//if collision occurred
	if(close != this && distance(close) < getW() / SimApp::getMetersPerPixel()){
		if(m_type == fire){
			close->dead = true;
			if(close->m_type == fire)
				dead = true;
		}
	}
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

void Splendido::accelerate(){
	double mag = magnitude();

	//printf("%f\n",mag);

	setVX((mag + 1) * cos(m_angle));
	setVY((mag + 1) * sin(m_angle));

	//printf("%f\n",magnitude());
}

double Splendido::magnitude(){
	double vx = getVX();
	double vy = getVY();
	return sqrt((pow(vx,2))+(pow(vy,2)));
}
