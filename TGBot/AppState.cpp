#include "AppState.h"

using namespace APP;

APP::AppState::AppState() noexcept :
    curentState{States::LAUNCH_APP}
{
}

const States APP::AppState::GetState() const
{
    std::lock_guard<std::mutex> lk(defMutex);

    return curentState;
}

void APP::AppState::SetState(States _state)
{
    std::lock_guard<std::mutex> lk(defMutex);

    curentState = _state;
}

const bool APP::AppState::IsPoolWorking() const
{
    std::lock_guard<std::mutex> lk(defMutex);

    return (curentState == States::WORKING ? true : false);
}
