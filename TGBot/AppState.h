#ifndef APP_STATE_H
#define APP_STATE_H

#include <mutex>

namespace APP
{
	enum class States
	{
		LAUNCH_APP	= 0,
		PREPARE		= 1,
		START		= 2,
		WORKING		= 3,
		PAUSE		= 4,
	};


	class AppState
	{
	private:
		States curentState;

	private:
		mutable std::mutex defMutex;

	public:
		AppState()	noexcept;

	public:
		AppState(const AppState&)				= delete;
		AppState(AppState&&)					= delete;

		AppState& operator=(const AppState&)	= delete;
		AppState& operator=(AppState&&)			= delete;

	public:
		const States GetState() const;
		void SetState(States _state);

	public:
		const bool IsPoolWorking() const;

	};
}



#endif

