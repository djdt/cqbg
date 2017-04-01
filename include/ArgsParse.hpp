#ifndef _ARGS_PARSE_H_
#define _ARGS_PARSE_H_

#include <string>
#include <vector>

struct ArgsParseOption
{
	private:
		const std::string long_opt;
		const char short_opt;
		std::vector<std::string> values;

	public:
		ArgsParseOption(const std::string& _long_opt, const char _short_opt)
			:long_opt(_long_opt), short_opt(_short_opt) {}
};

class ArgsParse
{
	private:
		std::vector<std::pair<char, std::string>> _options;
		std::vector<std::pair<std::string, std::vector<std::string>>> _parsed;

		ArgsParseOption* ParseShortOpts(const std::string& opts);

	public:
		ArgsParse();

		void AddOption(const std::string& long_opt, const char short_opt = 0);

		bool Parse(const std::vector<std::string>& args);
		bool Parse(int32_t argc, const char* argv[]);
};

#endif /* ifndef _ARGS_PARSE_H_ */
