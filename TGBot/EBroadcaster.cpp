#include "EBroadcaster.h"

EBroadcaster::EBroadcaster()
{

	bc = std::make_unique<TgBot::EventBroadcaster>();
}

TgBot::EventBroadcaster* EBroadcaster::Get() const
{
	return bc.get();
}

bool EBroadcaster::SetMessageHandlers(const std::vector<TgBot::EventBroadcaster::MessageListener>& _listenersArr)
{
	/*if (bc.get())
	{
		for (const auto& el : _listenersArr)
		{
			bc->onAnyMessage(el);
		}
		return true;
	}*/	
	if (addHandlers(bc.get(), &TgBot::EventBroadcaster::onAnyMessage, _listenersArr))
		return true;

	return false;
}

bool EBroadcaster::SetCommandHandlers(const std::unordered_map<std::string, TgBot::EventBroadcaster::MessageListener>& _commandSArr)
{
	/*if (bc.get())
	{
		for (const auto& el : _commandSArr)
		{
			bc->onCommand(el.first, el.second);
		}
		return true;
	}*/

	return false;
}

bool EBroadcaster::SetUncnownCommandHandlers(const std::vector<listeners>& _uCommands)
{
	if (bc.get())
	{
		for (const auto& el : _uCommands)
		{
			bc->onUnknownCommand(el);
		}
		return true;
	}

	return false;
}

bool EBroadcaster::SetNonCommandHandlers(const std::vector<listeners>& _nonCommands)
{
	if (bc.get())
	{
		for (const auto& el : _nonCommands)
		{
			bc->onUnknownCommand(el);
		}
		return true;
	}

	return false;
}

bool EBroadcaster::SetInliniQueryHandlers(const std::vector<TgBot::EventBroadcaster::InlineQueryListener>& _iqList)
{
	return false;
}

bool EBroadcaster::SetChousenInliniResultListenersHandlers(const std::vector<TgBot::EventBroadcaster::ChosenInlineResultListener>& _ocirList)
{
	return false;
}

bool EBroadcaster::SetCallbackQueryHandlers(const std::vector<TgBot::EventBroadcaster::CallbackQueryListener>& _cqList)
{
	return false;
}
