#include "App.h"

#include "BCPrep.h"
#include "BotPrep.h"

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
		broadcasterPrep();

		TgBot::EventHandler handler(*broadcaster.get()->Get());
		TgBot::TgLongPoll pool(&bot.get()->Get()->getApi(), &handler, 100, 10, nullptr);
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
	if (broadcaster.get() && bot.get())
	{
		// Broadcaster prep {
		std::unique_ptr<BCPrep> prep = std::make_unique<BCPrep>();
		broadcaster->SetMessageHandlers(prep->defineOnAnyMessage(*bot.get()->Get()));
		broadcaster->SetCommandHandlers(prep->defineOnCommands(*bot.get()->Get()));
		// Broadcaster prep }

		// Bot prep {
		std::unique_ptr<BotPrep> bPrep = std::make_unique<BotPrep>();
		bot.get()->Get()->getApi().setMyCommands(bPrep->defineBotCommands());
		// Bot prep }

	}
}
