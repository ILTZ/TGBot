#include "App.h"

#include "BCPrep.h"
#include "BotPrep.h"

App::App(const char* _token) noexcept :
	pause{ false }, appIsWork{ true }, bot(_token), broadcaster()
{

}

int App::Start()
{
	while (appIsWork)
	{
		broadcasterPrep();

		TgBot::EventHandler handler(*broadcaster.Get());
		TgBot::TgLongPoll pool(&bot.Get()->getApi(), &handler, 100, 10, nullptr);
		while (!pause)
		{
			std::cout << "LongPoll started..." << std::endl;
			pool.start();
		}
	}
	return 1;
}

bool App::Pause()
{
	pause = true;

	return pause;
}

void App::broadcasterPrep()
{
	
	// Broadcaster prep {
	std::unique_ptr<BCPrep> prep = std::make_unique<BCPrep>();
	broadcaster.SetMessageHandlers(prep->defineOnAnyMessage(*bot.Get()));
	broadcaster.SetCommandHandlers(prep->defineOnCommands(*bot.Get()));
	// Broadcaster prep }

	// Bot prep {
	std::unique_ptr<BotPrep> bPrep = std::make_unique<BotPrep>();
	bot.Get()->getApi().setMyCommands(bPrep->defineBotCommands());
	// Bot prep }


}
