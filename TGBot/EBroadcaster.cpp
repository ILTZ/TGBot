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
	if (addHandlers(bc.get(), &TgBot::EventBroadcaster::onAnyMessage, _listenersArr))
		return true;

	return false;
}

bool EBroadcaster::SetCommandHandlers(const std::unordered_map<std::string, TgBot::EventBroadcaster::MessageListener>& _commandSArr)
{
	if (bc.get())
	{
		for (const auto& el : _commandSArr)
		{
			bc->onCommand(el.first, el.second);
		}
		return true;
	}

	return false;
}

bool EBroadcaster::SetUncnownCommandHandlers(const std::vector<listeners>& _uCommands)
{
	if (addHandlers(bc.get(), &TgBot::EventBroadcaster::onUnknownCommand, _uCommands))
		return true;


	return false;
}

bool EBroadcaster::SetNonCommandHandlers(const std::vector<listeners>& _nonCommands)
{
	if (addHandlers(bc.get(), &TgBot::EventBroadcaster::onNonCommandMessage, _nonCommands))
		return true;

	return false;
}

bool EBroadcaster::SetInliniQueryHandlers(const std::vector<TgBot::EventBroadcaster::InlineQueryListener>& _iqList)
{
	if (addHandlers(bc.get(), &TgBot::EventBroadcaster::onInlineQuery, _iqList))
		return true;

	return false;
}

bool EBroadcaster::SetChousenInliniResultListenersHandlers(const std::vector<TgBot::EventBroadcaster::ChosenInlineResultListener>& _ocirList)
{
	if (addHandlers(bc.get(), &TgBot::EventBroadcaster::onChosenInlineResult, _ocirList))
		return true;

	return false;
}

bool EBroadcaster::SetCallbackQueryHandlers(const std::vector<TgBot::EventBroadcaster::CallbackQueryListener>& _cqList)
{
	if (addHandlers(bc.get(), &TgBot::EventBroadcaster::onCallbackQuery, _cqList))
		return true;

	return false;
}
