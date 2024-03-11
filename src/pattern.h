#ifndef PEINFO_SRC_PATTERN_H
#define PEINFO_SRC_PATTERN_H

#include <cstddef>
#include <cstdint>
#include <vector>

class Pattern {
  const std::vector<std::uint16_t> _pattern;
  const std::size_t _size;

public:
  Pattern() : _size{0} {}
  explicit Pattern(const size_t size) : _size{size} {}
};

#endif//PEINFO_SRC_PATTERN_H
