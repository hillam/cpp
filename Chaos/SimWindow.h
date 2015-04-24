#ifndef SIMWINDOW_H
#define SIMWINDOW_H

#include <gtkmm.h>
#include <string>
#include "ParticlePlayground.h"
#include "TimeKeeper.h"

using namespace std;

class SimWindow : public Gtk::Application, public TimeKeeper
{
public:
	SimWindow(int argc, char *argv[], string title, int w, int h);
	virtual ~SimWindow();
	virtual void tick(long t);

private:
	ParticlePlayground m_playground;
	Glib::RefPtr<Gtk::Application> m_app;
	Gtk::Window m_window;
};

#endif
