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

  	m_app = Gtk::Application::create(argc, argv,
      "SimPack");

 	m_window.set_default_size(w, h);
 	m_window.set_title(title.c_str());
 
	cout << "Sim Window Created" << endl;

	m_window.add(m_playground);

	// units for x,y,w,h are in meters...
	for(int i(0);i<100;i++)
		m_playground.add(new Splendido(rand()%500, rand()%600, 10, 10, 
			rand()%40 - 20, rand()%40 - 20));

   	m_playground.show();
 	
 	win = this;
 	g_timeout_add(s_secPerTick*1000,handleTime,NULL);
 	
 	m_app->run(m_window);
}



