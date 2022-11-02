#include "MyBot.h"

MyBot::MyBot(const char* _token) :
	myBot{_token}
{
	
}

TgBot::Bot& MyBot::Get()
{
	return myBot;
}

TgBot::Bot* MyBot::operator*()
{
	return &myBot;
}





