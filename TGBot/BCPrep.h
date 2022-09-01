#ifndef BCPREP_H
#define BCPREP_H

#include <tgbot/EventBroadcaster.h>
#include <tgbot/Bot.h>

using eb = TgBot::EventBroadcaster;

class BCPrep
{
private:

public:
	BCPrep()							noexcept;
	BCPrep(const BCPrep&)				= delete;
	BCPrep(BCPrep&&)					= delete;

public:
	BCPrep& operator=(const BCPrep&)	= delete;
	BCPrep& operator=(BCPrep&&)			= delete;

public:
	std::vector<eb::MessageListener>						defineOnAnyMessage(const TgBot::Bot& _b)		const noexcept;
	std::unordered_map<std::string, eb::MessageListener>	defineOnCommands(const TgBot::Bot& _b)		const noexcept;
	std::vector<eb::MessageListener>						defineOnUnknownCommands()	const noexcept;
	std::vector<eb::MessageListener>						defineOnNonCommands()		const noexcept;
	std::vector<eb::InlineQueryListener>					defineInlineQuery()			const noexcept;
	std::vector<eb::ChosenInlineResultListener>				defineChousenInline()		const noexcept;
	std::vector<eb::CallbackQueryListener>					defineCallbackQuery()		const noexcept;
};

#endif

