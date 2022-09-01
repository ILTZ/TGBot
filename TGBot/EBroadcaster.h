#ifndef EBROAD_H
#define EBROAD_H

#include <tgbot/EventBroadcaster.h>

#include <unordered_map>
#include <vector>
#include <memory>
#include <string>


using listeners = TgBot::EventBroadcaster::MessageListener;

class EBroadcaster
{
private:
	std::unique_ptr<TgBot::EventBroadcaster> bc;

public:
	EBroadcaster();
	EBroadcaster(const EBroadcaster&)				= delete;
	EBroadcaster(EBroadcaster&&)					= delete;

public:
	EBroadcaster& operator=(const EBroadcaster&)	= delete;
	EBroadcaster& operator=(EBroadcaster&&)			= delete;

public:
	TgBot::EventBroadcaster* Get() const;

	bool SetMessageHandlers(const std::vector <listeners> &_listenersArr);
	bool SetCommandHandlers(const std::unordered_map <std::string, listeners>& _commandSArr);
	bool SetUncnownCommandHandlers(const std::vector<listeners>& _uCommands);
	bool SetNonCommandHandlers(const std::vector<listeners>& _nonCommands);
	bool SetInliniQueryHandlers(const std::vector<TgBot::EventBroadcaster::InlineQueryListener>& _iqList);
	bool SetChousenInliniResultListenersHandlers(const std::vector<TgBot::EventBroadcaster::ChosenInlineResultListener>& _ocirList);
	bool SetCallbackQueryHandlers(const std::vector<TgBot::EventBroadcaster::CallbackQueryListener>& _cqList);


private:
	template<typename T>
	bool addHandlers(TgBot::EventBroadcaster* _bc, 
		void(TgBot::EventBroadcaster::* _func)(const T&), const std::vector<T>& _arr);

};


#endif

template<typename T>
inline bool EBroadcaster::addHandlers(TgBot::EventBroadcaster* _bc, 
	void(TgBot::EventBroadcaster::* _func)(const T&), const std::vector<T>& _arr)
{
	if (_bc)
	{
		for (auto& el : _arr)
		{
			(_bc->*_func)(el);
		}
		return true;
	}

	return false;
}
