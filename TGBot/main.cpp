#include <tgbot/tgbot.h>
#include <stdio.h>

#include <soci/soci.h>

#include <tgbot/EventBroadcaster.h>
#include <tgbot/EventHandler.h>
#include <tgbot/Api.h>

namespace ConstDatas
{
    const char* TOKEN = "5690128645:AAFsUIswYq3BrDgjZm9wpIh_sfWYTDL4LJQ";
}


using namespace TgBot;

class A
{
public:

    void foo() { std::cout << "Fooo\n"; }
    void boo() { std::cout << "Boo\n"; }

private:
    
    template<typename T>
    void add(A* a, void(A::* _func)(), std::vector<int>& _vec)
    {
        (a->*_func)(_vec);
        std::cout << "Add w vec\n";
    }
};


void addInArr(A* obj, void(A::*func)())
{
    (obj->*func)();
    std::cout << "Add in dir func\n";
}



int main()
{

    A a;
    addInArr(&a, &A::foo);
    addInArr(&a, &A::boo);





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