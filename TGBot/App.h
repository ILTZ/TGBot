#ifndef APP_H
#define APP_H

#include "EBroadcaster.h"
#include "MyBot.h"
#include "ConfigReader.h"
#include "AppState.h"

namespace APP
{
	class App
	{
	private:
		AppState		state;

	public:
		App() noexcept				= default;

	public:
		App(const App&)				= delete;
		App(App&&)					= delete;

		App& operator=(const App&)	= delete;
		App& operator=(App&&)		= delete;

	public:
		int		Start();

	private:
		std::unique_ptr<MyBot>			createBot(CONFIG_READER::ConfigReader& _reder)			const;
		std::unique_ptr<EBroadcaster>	createBroadcaster(CONFIG_READER::ConfigReader& _reder)	const;

		const bool prepareBroadcaster(EBroadcaster& _bc, MyBot& _bot)	const;
		const bool botPrepare(MyBot& _bot)								const;
	};
}



#endif





