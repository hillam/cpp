#include "SimApp.h"
#include "SimpleParticle.h"
#include "Splendido.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

long t = 0;
SimApp * win = NULL;

const int TOTAL_PARTICLES = 100;
const int NUM_ROGUES = 1;

int handleTime(void *)
{
	t++;
	win->tick(t);
	return TRUE;
}

double SimApp::s_secPerTick = 0.1;
double SimApp::s_metersPerPixel = 1.0;

SimApp::SimApp(int argc, char *argv[], string title, int w, int h)
	: m_playground(), m_window(), m_app()
{
	srand(time(NULL));

  	m_app = Gtk::Application::create(argc, argv, "SimPack");

 	m_window.set_default_size(w, h);
 	m_window.set_title(title.c_str());
 
	cout << "Sim Window Created" << endl;

	m_window.add(m_playground);

	// units for x,y,w,h are in meters...
	for(int i(0);i<TOTAL_PARTICLES;i++)
		m_playground.add(new Splendido(m_playground.getParticles(),rand()%501, rand()%601, 10, 10, 
			rand()%41 - 20, rand()%41 - 20));

	for(int i(0);i<NUM_ROGUES;i++)
		((Splendido*)m_playground.getParticles()[i])->toggleRogue();

   	m_playground.show();
 	
 	win = this;
 	g_timeout_add(s_secPerTick*1000,handleTime,NULL);
 	
 	m_app->run(m_window);
}



