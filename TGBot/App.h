#ifndef APP_H
#define APP_H

#include "MyBot.h"
#include "EBroadcaster.h"

class App
{
private:
	std::unique_ptr<MyBot>			bot;
	std::unique_ptr<EBroadcaster>	broadcaster;


public:
	App()						noexcept;
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





