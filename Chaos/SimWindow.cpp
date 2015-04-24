#include "SimWindow.h"
#include "SimpleParticle.h"
#include <iostream>
#include <string>

using namespace std;

long t = 0;
SimWindow * win = NULL;

int handleTime(void *)
{
	t++;
	win->tick(t);
	return TRUE;
}

SimWindow::SimWindow(int argc, char *argv[], string title, int w, int h) 
	: m_playground(), m_window(), m_app()
{
  	m_app = Gtk::Application::create(argc, argv,
      "SimPack");

 	m_window.set_default_size(200, 200);
 	m_window.set_title(title.c_str());
 
	cout << "Sim Window Created" << endl;

	m_window.add(m_playground);
	m_playground.add(new SimpleParticle(50, 50, 50, 50));
	m_playground.add(new SimpleParticle(100, 150, 10, 10));
	m_playground.add(new SimpleParticle(90, 80, 10, 10));
	m_playground.add(new SimpleParticle(125, 20, 10, 10));
   	m_playground.show();
 	
 	win = this;
 	g_timeout_add(100,handleTime,NULL);
 	
 	m_app->run(m_window);
}

SimWindow::~SimWindow()
{
	cout << "Sim Window Destroyed" << endl;
}

void SimWindow::tick(long t)
{
	m_playground.tick(t);
}

