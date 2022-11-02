#include "App.h"
#include <Windows.h>

int main()
{
    try
    {
        APP::App app;
        return app.Start();
    }
    catch (TgBot::TgException& ex)
    {
        MessageBoxA(nullptr, ex.what(), "ERROR", MB_OK | MB_ICONERROR);
    }
    catch (std::exception& ex)
    {
        MessageBoxA(nullptr, ex.what(), "ERROR", MB_OK | MB_ICONERROR);
    }
    catch (...)
    {
        MessageBoxA(nullptr, "Unknown exception...", "ERROR", MB_OK | MB_ICONERROR);
    }


    return 0;
}