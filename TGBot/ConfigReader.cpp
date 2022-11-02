#include "ConfigReader.h"

#include <fstream>

namespace CONFIG_READER
{
	namespace Constants
	{
		namespace ConstPaths
		{
			std::string pathToConfigs = ".\\Configs\\Configs.json";
		}

		namespace ConstKeyes
		{
			std::string token = "TOKEN";
		}
	}


	ConfigReader::ConfigReader() noexcept
	{

	}

	const std::optional<std::string> ConfigReader::GetToken() const
	{
		auto file = openFile(Constants::ConstPaths::pathToConfigs.c_str());

		std::string token;
		extractValue(file, Constants::ConstKeyes::token.c_str(), Constants::ConstPaths::pathToConfigs.c_str(), token);

		return token;
	}

	nlohmann::json ConfigReader::openFile(const char* _pathToFile) const
	{
		std::ifstream f;
		f.open(_pathToFile);

		nlohmann::json jFile;
		jFile = nlohmann::json::parse(f);

		f.close();

		return jFile;
	}
}

