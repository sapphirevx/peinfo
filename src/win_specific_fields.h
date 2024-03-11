#ifndef PEINFO_WIN_SPECIFIC_FIELDS_H
#define PEINFO_WIN_SPECIFIC_FIELDS_H

#include <cstdint>

struct WinSpecificFields {
  std::uint16_t magic;                  // 0x010b = PE32, 0x020b = PE32+
  std::uint64_t image_base;             // Preferred address of first byte of image when
										// loaded into memory; Multiple of 64k.
  std::uint32_t section_alignment;      // Alignment in bytes of sections when they
										// are loaded in memory; >= file_alignment.
  std::uint32_t file_alignment;         // Alignment factor in bytes that is used to align the raw
										// data of sections; 2^x >= 512 && <= 64k
  std::uint16_t major_system_version;   // The major version of the required
										// operating system.
  std::uint16_t minor_system_version;   // The minor version of the required
										// operating system.
  std::uint16_t major_image_version;    // The major version number of the image.
  std::uint16_t minor_image_version;    // The minor version number of the image.
  std::uint16_t major_subsystem_version;// The major version number of the subsystem.
  std::uint16_t minor_subsystem_version;// The major version number of the subsystem.
  std::uint32_t win32_version_value;    // Reserved. Must be 0
  std::uint32_t size_of_image;          // The size in bytes of the image as it is loaded
										// into memory, including all headers.
  std::uint32_t size_of_headers;        // Combined size of MS-DOS stub, PE_Header
										// Header and section headers rounded up to a
										// multiple of file_alignment;
  std::uint32_t checksum;               // The image file checksum
  std::uint16_t subsystem;              // The subsystem required to run this image
  std::uint16_t dll_characteristics;
  /*
   * Size of the stack reserve. Only size_of_stack_commit is committed.
   * The rest is made available one page at a time until reserve size is
   * reached.
   */
  std::uint64_t size_of_stack_reserve;
  std::uint64_t size_of_stack_commit;// Size of the stack to commit.

  /*
   * Size of heap space to reserve. Only size_of_heap_commit is committed.
   * The rest is made available one page at a time until reserve size is
   * reached.
   */
  std::uint64_t size_of_heap_reserve;
  std::uint64_t size_of_heap_commit;// Size of heap space to commit.

  std::uint32_t loader_flags;           // Reserved. Must be 0.
  std::uint32_t number_of_rva_and_sizes;// The number of data directory entries in the remainder of the optional header.
};
#endif// PEINFO_WIN_SPECIFIC_FIELDS_H
