#ifndef APP_H
#define APP_H

#include "MyBot.h"
#include "EBroadcaster.h"

class App
{
private:
	MyBot			bot;
	EBroadcaster	broadcaster;


public:
	App()						= delete;
	App(const char* _token)		noexcept;
	App(const App&)				= delete;
	App(App&&)					= delete;

public:
	App& operator=(const App&)	= delete;
	App& operator=(App&&)		= delete;

public:
	int		Start();
	bool	Pause();


private:
	bool pause		= false;
	bool appIsWork	= true;

	// Load in broadcaster handlers
	void broadcasterPrep();
};


#endif





