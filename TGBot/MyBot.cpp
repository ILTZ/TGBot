#include "MyBot.h"

MyBot::MyBot(const char* _token)
{


	myBot = std::make_unique<TgBot::Bot>(_token);
}

TgBot::Bot* MyBot::Get() const
{
	return myBot.get();
}


