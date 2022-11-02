#include "App.h"

#include "BCPrep.h"
#include "BotPrep.h"


#include "SmartPointer.h"


using namespace APP;

int App::Start()
{
	SmartPointer::SmartPointer<CONFIG_READER::ConfigReader> reader = new CONFIG_READER::ConfigReader();

	auto bot = createBot(*reader);
	auto bc = createBroadcaster(*reader);
	
	if (!prepareBroadcaster(*bc, *bot) || !botPrepare(*bot))
		return 1;
	
	TgBot::TgLongPoll pool(&bot->Get().getApi(), &bc->GetEventHandler(), 100, 10, nullptr);

	state.SetState(APP::States::WORKING);
	while (state.IsPoolWorking())
	{
		std::cout << "LongPoll started..." << std::endl;
		pool.start();
	}
	
	return 0;
}




std::unique_ptr<MyBot> App::createBot(CONFIG_READER::ConfigReader& _reder) const
{

	return std::make_unique<MyBot>(_reder.GetToken().value().c_str());
}

std::unique_ptr<EBroadcaster> APP::App::createBroadcaster(CONFIG_READER::ConfigReader& _reder) const
{

	return std::make_unique<EBroadcaster>();
}

const bool APP::App::prepareBroadcaster(EBroadcaster& _bc, MyBot& _bot) const
{
	SmartPointer::SmartPointer<BCPrep> bcPrep = new BCPrep();

	_bc.SetMessageHandlers(bcPrep->defineOnAnyMessage(_bot.Get()));
	_bc.SetCommandHandlers(bcPrep->defineOnCommands(_bot.Get()));

	return true;
}

const bool APP::App::botPrepare(MyBot& _bot) const
{
	SmartPointer::SmartPointer<BotPrep> botPrep = new BotPrep();

	_bot.Get().getApi().setMyCommands(botPrep->defineBotCommands());

	return true;
}
