#include "App.h"


namespace ConstData
{
    const char* TOKEN = "TOKEN";
}

#include <tgbot/tgbot.h>

using namespace std;
using namespace TgBot;



int main()
{
    try
    {
        App app(ConstData::TOKEN);
        return app.Start();
    }
    catch (TgBot::TgException& ex)
    {
        printf("TgError: %s\n", ex.what());
    }
    catch (std::exception& ex)
    {
        printf("StlError: %s\n", ex.what());
    }
    catch (...)
    {
        printf("Unknown exception...%s\n");
    }


    return 0;

}
