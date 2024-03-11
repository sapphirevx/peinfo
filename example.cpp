#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

#include "src/parser.h"
#include "util.h"

void print_header(const PEHeader &header) {
  std::cout << "--------PE header--------\n"
			<< "magic: " << header.magic << '\n'
			<< "# of sections: " << header.number_of_sections << '\n'
			<< "timestamp: " << header.time_date_stamp << '\n'
			<< "symbol table ptr: " << header.pointer_to_symbol_table << '\n'
			<< "# of symbols: " << header.number_of_symbols << '\n'
			<< "Optional header size: " << header.size_of_optional_header << '\n'
			<< "Characteristics: " << header.characteristics << '\n'
			<< "--------PE header--------" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
	std::cout << "usage: example <filename>" << std::endl;
	return -1;
  }

  std::cout.setf(std::ios::hex | std::ios::showbase, std::ios::basefield);

  std::string filename = find_arg(argv, argc, "-f");
  std::filesystem::path path{filename};
  std::ifstream filestream(path, std::ifstream::binary);

  if (filestream.good()) {
	std::uintmax_t length = std::filesystem::file_size(path);

	std::vector<char> buffer(length);

	// Read the contents of the file into the buffer
	filestream.read(buffer.data(), static_cast<std::streamsize>(length));

	filestream.close();

	PEHeader header = PEParser::parse(buffer);
	if (!header.valid()) {
	  std::cout << "Invalid PE header" << std::endl;
	  return -1;
	}

	std::cout << "Is executable: "
			  << header.characteristic(Characteristic::executable_image)
			  << '\n';

	print_header(header);
  }
  return 0;
}
