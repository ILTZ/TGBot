#include "BCPrep.h"

BCPrep::BCPrep() noexcept
{
}

std::vector<eb::MessageListener> BCPrep::defineOnAnyMessage(const TgBot::Bot& _b) const noexcept
{
	std::vector<eb::MessageListener> ml;

	//echo
	ml.emplace_back([&_b](TgBot::Message::Ptr message) {
		printf("User wrote %s\n", message->text.c_str());
		if (StringTools::startsWith(message->text, "/start")	||
			StringTools::startsWith(message->text, "/info")		||
			StringTools::startsWith(message->text, "/help"))
		{
			return;
		}

		_b.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
		});



	return ml;
}

std::unordered_map<std::string, eb::MessageListener> BCPrep::defineOnCommands(const TgBot::Bot& _b) const noexcept
{
	std::unordered_map<std::string, eb::MessageListener> um;

	um["start"] = [&_b](TgBot::Message::Ptr message) {
		_b.getApi().sendMessage(message->chat->id, "Hi!");
		};

	um["info"] = [&_b](TgBot::Message::Ptr message) {
		_b.getApi().sendMessage(message->chat->id, "Its info about this bot");
	};

	um["help"] = [&_b](TgBot::Message::Ptr message) {
		_b.getApi().sendMessage(message->chat->id, "This is help section of this bot");
	};

	um["phone"] = [&_b](TgBot::Message::Ptr message) {

	
	};

	return um;
}

std::vector<eb::MessageListener> BCPrep::defineOnUnknownCommands() const noexcept
{
	std::vector<eb::MessageListener> uc;

	return uc;
}

std::vector<eb::MessageListener> BCPrep::defineOnNonCommands() const noexcept
{
	std::vector<eb::MessageListener> nc;


	return nc;
}

std::vector<eb::InlineQueryListener> BCPrep::defineInlineQuery() const noexcept
{
	std::vector<eb::InlineQueryListener> iql;


	return iql;
}

std::vector<eb::ChosenInlineResultListener> BCPrep::defineChousenInline() const noexcept
{
	std::vector<eb::ChosenInlineResultListener> cilr;


	return cilr;
}

std::vector<eb::CallbackQueryListener> BCPrep::defineCallbackQuery() const noexcept
{
	std::vector<eb::CallbackQueryListener> cql;


	return cql;
}
