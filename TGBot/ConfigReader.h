#ifndef CONFIGR_H
#define CONFIGR_H

class ConfigReader
{
private:

public:
	ConfigReader()									noexcept;
	ConfigReader(const ConfigReader&)				= delete;
	ConfigReader(ConfigReader&&)					= delete;

	ConfigReader& operator=(const ConfigReader&)	= delete;
	ConfigReader& operator-(ConfigReader&&)			= delete;

	bool ReadConfigFile();

private:


};


#endif

