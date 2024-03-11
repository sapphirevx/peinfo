#ifndef PEINFO_SRC_UTIL_H
#define PEINFO_SRC_UTIL_H

#include <cstdint>
#include <string>
#include <vector>

/**
 * @tparam  ret_type return type
 * @tparam  src_type source container type
 * @param   src source container
 * @param   offset
 * @return
 */
template<typename ret_type>
ret_type read_bytes(const std::vector<char> &src, std::size_t offset) {
  ret_type ret = 0;

  for (std::size_t i = 0; i < sizeof(ret_type); ++i) {
	ret += src[offset + i] << (8 * i);
  }

  return ret;
}

std::string find_arg(char *argv[], uint32_t argc, const std::string &query) {
  for (std::size_t i = 0; i < argc; ++i) {
	std::string arg(argv[i]);
	if (arg == query && (i + 1 < argc)) {
	  return {argv[i + 1]};
	}
  }

  return "";
}
#endif//PEINFO_SRC_UTIL_H
