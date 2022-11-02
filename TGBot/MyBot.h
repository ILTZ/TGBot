#ifndef MYBOT_H
#define MYBOT_H

#include <tgbot/tgbot.h>
#include <memory>

class MyBot
{
private:
	TgBot::Bot myBot;

public:
	MyBot(const char* _token);
	MyBot(const MyBot&)				= delete;
	MyBot(MyBot&&)					= delete;

public:
	MyBot& operator=(const MyBot&)	= delete;
	MyBot& operator=(MyBot&&)		= delete;

public:
	TgBot::Bot& Get();

	TgBot::Bot* operator*();

};



#endif 





