#ifndef PEINFO_STANDARD_FIELDS_H
#define PEINFO_STANDARD_FIELDS_H

#include <cstdint>

struct StandardFields {
  std::uint16_t magic;
  std::uint8_t major_linker_version;
  std::uint8_t minor_linker_version;
  std::uint32_t size_of_code;
  std::uint32_t size_of_uninitialized_data;
  std::uint32_t address_of_entry_point;
  std::uint32_t base_of_code;
  std::uint32_t base_of_data;
};

#endif // PEINFO_STANDARD_FIELDS_H
