#include "App.h"


namespace ConstData
{
    const char* TOKEN = "5690128645:AAFsUIswYq3BrDgjZm9wpIh_sfWYTDL4LJQ";
}





int main()
{
    App app(ConstData::TOKEN);

    app.Start();

    /*std::string token = ("5690128645:AAFsUIswYq3BrDgjZm9wpIh_sfWYTDL4LJQ");
    TgBot::Bot bot(token);

    EventBroadcaster eb;
    eb.onAnyMessage([&bot](TgBot::Message::Ptr message) {
        printf("User wrote %s\n", message->text.c_str());
        if (StringTools::startsWith(message->text, "/start")) {
            return;
        }
        bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
        });
    EventHandler handler(eb);

    eb.onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hi!");
        });

    try {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        const Api* api = &bot.getApi();
        TgLongPoll pool(api, &handler, 100, 10, nullptr);
        
        while (true) {
            printf("Long poll started\n");
            pool.start();
        }
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
    }*/
    return 0;

}