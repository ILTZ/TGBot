#include "App.h"

#include "BCPrep.h"

App::App() noexcept :
	pause{false}, appIsWork{true}
{
	

}

App::App(const char* _token) noexcept :
	pause{ false }, appIsWork{ true }
{
	bot = std::make_unique<MyBot>(_token);
	broadcaster = std::make_unique<EBroadcaster>();

}

int App::Start()
{
	while (appIsWork)
	{
		preparatior();

		TgBot::EventHandler handler(*broadcaster.get()->Get());
		TgBot::TgLongPoll pool(&bot.get()->Get()->getApi(), &handler, 0, 0, nullptr);
		while (!pause)
		{
			std::cout << "LongPoll started..." << std::endl;
			pool.start();
		}
	}
	return 0;
}

bool App::Pause()
{
	return false;
}

void App::preparatior()
{
	if (broadcaster.get() && bot.get())
	{
		std::unique_ptr<BCPrep> prep = std::make_unique<BCPrep>();

		broadcaster->SetMessageHandlers(prep->defineOnAnyMessage(*bot.get()->Get()));
		broadcaster->SetCommandHandlers(prep->defineOnCommands(*bot.get()->Get()));
	}
}
