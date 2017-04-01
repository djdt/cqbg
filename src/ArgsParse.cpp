#include "ArgsParse.hpp"

#include <iostream>

/* bool ArgsParse::ParseShortOpts(const std::string& opts) */
/* { */
/* 	for (const char c : opts) { */
/* 		bool found = false; */
/* 		for (auto o : _options) { */
/* 			if (o.first == c) { */
/* 				_parsed.push_back({o.second, {}}); */
/* 				found = true; */
/* 				break; */
/* 			} */
/* 		} */
/* 		if (!found) { */
/* 			std::cerr << "Short option not found! '" << c << "'." << std::endl; */
/* 			return false; */
/* 		} */
/* 	} */
/* 	return true; */
/* } */

/* ArgsParse::ArgsParse() */
/* { */

/* } */

/* void ArgsParse::AddOption(const std::string& long_opt, const char short_opt) */
/* { */
/* 	_options.push_back({short_opt, long_opt}); */
/* } */

/* bool ArgsParse::Parse(const std::vector<std::string>& args) */
/* { */
/* 	for (auto arg : args) { */
/* 		if (arg[0] == '-') { // Is option */
/* 			if (arg[1] == '-') { // Long option */
/* 				_parsed.push_back({arg, {}}); */
/* 			} else { // Short option */
/* 				ParseShortOpts(arg.substr(1)); */
/* 			} */
/* 		} else { // Value */
/* 			_parsed.back().second.push_back(arg); */
/* 		} */
/* 	} */
/* 	return true; */
/* } */

/* bool ArgsParse::Parse(int32_t argc, const char* argv[]) */
/* { */
/* 	std::vector<std::string> args; */
/* 	args.reserve(argc - 1); */
/* 	for (int32_t i = 1; i < argc; ++i) { */
/* 		args.push_back(argv[i]); */
/* 	} */
/* 	return this->Parse(args); */
/* } */
