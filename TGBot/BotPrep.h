#ifndef BOTPREP_H
#define BOTPREP_H

#include <tgbot/Bot.h>


class BotPrep
{
private:


public:
	BotPrep()							noexcept;
	BotPrep(const BotPrep&)				= delete;
	BotPrep(BotPrep&&)					= delete;

public:
	BotPrep& operator=(const BotPrep&)	= delete;
	BotPrep& operator=(BotPrep&&)		= delete;

public:
	std::vector<TgBot::BotCommand::Ptr> defineBotCommands() const;

private:

};


#endif


