#ifndef PEINFO_PE_HEADER_H
#define PEINFO_PE_HEADER_H

#include "characteristics.h"

struct PEHeader {
  uint32_t magic;
  uint16_t machine;                // Number that identifies the type of target machine.
  uint16_t number_of_sections;     // Indicates the size of the section table which
								   // immediately follows the headers.
  uint16_t size_of_optional_header;// Image only. Should be 0 for an object file.
  uint16_t characteristics;        // Indicates the attributes of the file.
  uint32_t time_date_stamp;        // Indicates when the file was created.
  uint32_t pointer_to_symbol_table;// File offset of COFF symbol table or 0 if
								   // COFF symbol table is not present.
  uint32_t number_of_symbols;      // Number of entries in the symbol table. Should
								   // be 0 for an image.

  [[nodiscard]] inline bool valid() const;

  [[nodiscard]] inline bool characteristic(Characteristic characteristic) const;
};

namespace constants {
constexpr uint32_t magic = 0x00004550;
constexpr uint32_t magic_offset = 0;
constexpr uint32_t machine_offset = magic_offset + sizeof(PEHeader::magic);
constexpr uint32_t number_of_sections_offset =
	machine_offset + sizeof(PEHeader::machine);
constexpr uint32_t timedate_stamp_offset =
	number_of_sections_offset + sizeof(PEHeader::number_of_sections);
constexpr uint32_t ptr_to_symbol_table_offset =
	timedate_stamp_offset + sizeof(PEHeader::time_date_stamp);
constexpr uint32_t number_of_symbols_offset =
	ptr_to_symbol_table_offset + sizeof(PEHeader::pointer_to_symbol_table);
constexpr uint32_t size_of_optional_header_offset =
	number_of_symbols_offset + sizeof(PEHeader::number_of_symbols);
constexpr uint32_t characteristics_offset =
	size_of_optional_header_offset + sizeof(PEHeader::size_of_optional_header);
}// namespace constants

/**
 * @return true if PE_Header::magic == pe.magic
 */
bool PEHeader::valid() const { return magic == constants::magic; }

bool PEHeader::characteristic(const Characteristic characteristic) const {
  return ((characteristics & static_cast<std::uint16_t>(characteristic)) == static_cast<std::uint16_t>(characteristic));
}

#endif// PEINFO_PE_HEADER_H
