#include "BotPrep.h"

BotPrep::BotPrep() noexcept
{

}

std::vector<TgBot::BotCommand::Ptr> BotPrep::defineBotCommands() const
{
	using bc = TgBot::BotCommand;
	using tgCommand = TgBot::BotCommand::Ptr;
	std::vector<tgCommand> bcArr;


	tgCommand ptr(new bc);
	ptr->command = "info";
	ptr->description = "Some info about bot";
	bcArr.push_back(ptr);

	ptr = tgCommand(new bc);
	ptr->command = "help";
	ptr->description = "Some help about navigation";
	bcArr.push_back(ptr);
	


	return bcArr;
}
