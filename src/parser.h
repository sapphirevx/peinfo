#ifndef LIBPEINFO_PARSER_H
#define LIBPEINFO_PARSER_H

#include <cstdint>
#include <ios>
#include <iostream>
#include <ranges>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include "constants.h"
#include "pe_header.h"
#include "util.h"

struct PEParser {
  PEParser() = delete;

  static PEHeader parse(const std::vector<char> &src);

  [[nodiscard]] static std::vector<char> buffer(const std::vector<char> &src);
  [[nodiscard]] static inline std::size_t find_offset(const std::vector<char> &src);

  static std::size_t find_pattern(const std::vector<char> &src, const char pattern[], std::size_t pattern_size);
};

/***
 *
 * @tparam T container type
 * @param src Source container
 * @param offset
 * @return
 */
inline std::size_t PEParser::find_offset(const std::vector<char> &src) {
  const std::size_t magic_pattern_size = 4;
  const char magic_pattern[magic_pattern_size] = {'\x50', '\x45', '\x00', '\x00'};
  return find_pattern(src, magic_pattern, magic_pattern_size);
}

std::vector<char> PEParser::buffer(const std::vector<char> &src) {
  std::size_t magic_offset = find_offset(src);

  if (!magic_offset)
	return {};

  auto iter = src.begin() + magic_offset;
  auto iter_end = iter + sizeof(PEHeader);

  return {iter, iter_end};
}

/**
 * @param src source container to parse from
 * @return an empty PEHeader on error. Otherwise return a properly filled out PEHeader.
 */
PEHeader PEParser::parse(const std::vector<char> &src) {
  std::vector<char> buf = buffer(src);

  if (buf.empty()) {
	std::cout << "PEParser::parse: invalid offset\n";
	return PEHeader{};
  }

  auto magic = read_bytes<std::uint32_t>(buf, constants::magic_offset);
  if (magic != constants::magic) {
	std::cout << "PEParser::parse: bad magic value\n";
	return PEHeader{};
  }

  auto machine_type = read_bytes<std::uint16_t>(buf, constants::machine_offset);
  auto number_of_sections = read_bytes<std::uint16_t>(buf, constants::number_of_sections_offset);
  auto size_of_optional_header = read_bytes<std::uint16_t>(buf, constants::size_of_optional_header_offset);
  auto characteristics = read_bytes<std::uint16_t>(buf, constants::characteristics_offset);
  auto timedate_stamp = read_bytes<std::uint32_t>(buf, constants::timedate_stamp_offset);
  auto ptr_to_symbol_table = read_bytes<std::uint32_t>(buf, constants::ptr_to_symbol_table_offset);
  auto number_of_symbols = read_bytes<std::uint32_t>(buf, constants::number_of_symbols_offset);

  return PEHeader{
	  magic,
	  machine_type,
	  number_of_sections,
	  size_of_optional_header,
	  characteristics,
	  timedate_stamp,
	  ptr_to_symbol_table,
	  number_of_symbols};
}

std::size_t PEParser::find_pattern(const std::vector<char> &src, const char pattern[], std::size_t pattern_size) {
  for (std::size_t position = 0; (position + pattern_size) < src.size(); position += pattern_size) {
	bool equals = true;
	for (std::uint32_t j = 0; j < pattern_size; ++j) {
	  if (src[position + j] != pattern[j]) {
		equals = false;
		break;
	  }
	}
	if (equals)
	  return position;
  }

  return 0;
}

#endif// LIBPEINFO_PARSER_H
