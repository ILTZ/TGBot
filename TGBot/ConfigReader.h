#ifndef CONFIGR_H
#define CONFIGR_H

#include <nlohmann/json.hpp>
#include <string>
#include <optional>

namespace CONFIG_READER
{
	

	class ConfigReader
	{
	private:

	public:
		ConfigReader()									noexcept;
		ConfigReader(const ConfigReader&)				= delete;
		ConfigReader(ConfigReader&&)					= delete;

		ConfigReader& operator=(const ConfigReader&)	= delete;
		ConfigReader& operator-(ConfigReader&&)			= delete;

		const std::optional<std::string> GetToken() const;

	private:
		nlohmann::json openFile(const char* _pathToFile) const;

		template <typename T>
		void extractValue(
			const nlohmann::json& _file, 
			const char* _key, 
			const char* _path, 
			T& _destValue) const;


	};
	template<typename T>
	inline void ConfigReader::extractValue(
		const nlohmann::json& _file, 
		const char* _key, 
		const char* _path, 
		T& _destValue) const
	{
		
		_destValue = static_cast<T>(_file[_key]);
	}
}

#endif

