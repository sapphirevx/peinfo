#ifndef PEINFO_SECTION_HEADER_H
#define PEINFO_SECTION_HEADER_H

#include <cstdint>

struct SectionHeader {
  char name[8]; // An 8-byte null-padded UTF-8 encoded string. Not null
                // terminated if string is exactly 8 characters.
  std::uint32_t virtual_size; // Total size of section when loaded into memory.
  std::uint32_t virtual_address;  //
  std::uint32_t size_of_raw_data; //
  void *pointer_to_raw_data;
  void *pointer_to_relocation;
  void *pointer_to_line_numbers;
  std::uint16_t num_relocations;
  std::uint16_t num_line_numbers;
  std::uint32_t characteristics;
};
#endif // PEINFO_SECTION_HEADER_H
