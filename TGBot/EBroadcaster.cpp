#include "EBroadcaster.h"

EBroadcaster::EBroadcaster()
{
	handler = new TgBot::EventHandler(bc);
}

TgBot::EventBroadcaster& EBroadcaster::Get()
{
	return bc;
}

TgBot::EventHandler& EBroadcaster::GetEventHandler()
{
	return *handler;
}

bool EBroadcaster::SetMessageHandlers(const std::vector<TgBot::EventBroadcaster::MessageListener>& _listenersArr)
{
	if (addHandlers(&bc, &TgBot::EventBroadcaster::onAnyMessage, _listenersArr))
		return true;

	return false;
}

bool EBroadcaster::SetCommandHandlers(const std::unordered_map<std::string, TgBot::EventBroadcaster::MessageListener>& _commandSArr)
{

	for (const auto& el : _commandSArr)
	{
		bc.onCommand(el.first, el.second);
	}

	return true;
}

bool EBroadcaster::SetUncnownCommandHandlers(const std::vector<listeners>& _uCommands)
{
	if (addHandlers(&bc, &TgBot::EventBroadcaster::onUnknownCommand, _uCommands))
		return true;


	return false;
}

bool EBroadcaster::SetNonCommandHandlers(const std::vector<listeners>& _nonCommands)
{
	if (addHandlers(&bc, &TgBot::EventBroadcaster::onNonCommandMessage, _nonCommands))
		return true;

	return false;
}

bool EBroadcaster::SetInliniQueryHandlers(const std::vector<TgBot::EventBroadcaster::InlineQueryListener>& _iqList)
{
	if (addHandlers(&bc, &TgBot::EventBroadcaster::onInlineQuery, _iqList))
		return true;

	return false;
}

bool EBroadcaster::SetChousenInliniResultListenersHandlers(const std::vector<TgBot::EventBroadcaster::ChosenInlineResultListener>& _ocirList)
{
	if (addHandlers(&bc, &TgBot::EventBroadcaster::onChosenInlineResult, _ocirList))
		return true;

	return false;
}

bool EBroadcaster::SetCallbackQueryHandlers(const std::vector<TgBot::EventBroadcaster::CallbackQueryListener>& _cqList)
{
	if (addHandlers(&bc, &TgBot::EventBroadcaster::onCallbackQuery, _cqList))
		return true;

	return false;
}
