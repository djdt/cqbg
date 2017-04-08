#include "Parsei3status.hpp"

#include <fstream>

void parsei3StatusConfig(const std::string& infile, const std::string& outfile,
		const std::vector<std::string>& colors)
{
	std::ifstream ifs(infile, std::ios::in);
	std::ofstream ofs(outfile, std::ios::out);

	std::string line;
	while (std::getline(ifs, line)) {
		for (size_t i = 0; i < colors.size(); ++i) {
			size_t name_pos = 0, search_pos = 0;
			while ((name_pos = line.find("{" + base_16_eighties_names[i] + "}", search_pos)) != std::string::npos) {
				line.replace(name_pos, 2 + base_16_eighties_names[i].size(),
						colors[i]);
			}
		}
		ofs << line << "\n";
	}

	ifs.close();
	ofs.close();
}
