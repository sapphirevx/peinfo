#ifndef LIBPEINFO_CONSTANTS_H
#define LIBPEINFO_CONSTANTS_H

#include <cstdint>

namespace constants {
// The value at this offset has the offset of the PE Header signature
constexpr std::uint8_t stub_signature_offset = 0x3c;

// Magic Numbers
constexpr std::uint32_t image_file_pe32 = 0x10b;
constexpr std::uint32_t image_file_rom = 0x107;
constexpr std::uint32_t image_file_pe32e = 0x20b;
// End Magic Numbers

constexpr std::uint32_t image_default_base_dll = 0x10000000;
constexpr std::uint32_t image_default_base_cxe = 0x00010000;
// This is the default for Windows NT, Windows 2000, Windows XP, Windows 95,
// Windows 98 and Windows Me
constexpr std::uint32_t base_image_default_nt = 0x00400000;

enum machine_type {
  unknown = 0x0,
  Matsushita_AM33 = 0x1d3,
  x64 = 0x8664,
  ARM_little_endian = 0x1c0,
  ARM64_little_endian = 0xaa64,
  ARM_Thumb_2_little_endian = 0x1cd,
  EFI_byte_code = 0xebc,
  x86 = 0x14c,
  Intel_Itanium = 0x200,
  Mitsubishi_M32R_little_endian = 0x9041,
  MIPS16 = 0x266,
  MIPS_with_FPU = 0x366,
  MIPS16_with_FPU = 0x466,
  Power_PC_little_endian = 0x1f0,
  Power_PC_with_floating_point_support = 0x1f1,
  MIPS_little_endian = 0x166,
  RISCV_32bit = 0x5032,
  RISCV_64bit = 0x5064,
  RISCV_128bit = 0x5128,
  Hitachi_SH3 = 0x1a2,
  Hitachi_SH3_DSP = 0x1a3,
  Hitachi_SH4 = 0x1a6,
  Hitachi_SH5 = 0x1a8,
  Thumb = 0x1c2,
  MIPS_little_endian_WCE_v2 = 0x169
};

constexpr std::uint32_t image_file_relocs_stripped = 0x0001;
constexpr std::uint32_t image_file_executable_image = 0x0002;
constexpr std::uint32_t image_file_line_nums_stripped = 0x0004;
constexpr std::uint32_t image_file_local_syms_stripped = 0x0008;
constexpr std::uint32_t image_file_aggressive_ws_trim = 0x0010;
constexpr std::uint32_t image_file_large_address_aware = 0x0020;
constexpr std::uint32_t image_file_reserved_for_future = 0x0040;
constexpr std::uint32_t image_file_bytes_reversed_lo = 0x0080;
constexpr std::uint32_t image_file_32bit_machine = 0x0100;
constexpr std::uint32_t image_file_debug_stripped = 0x0200;
constexpr std::uint32_t image_file_removable_run_from_swap = 0x0400;
constexpr std::uint32_t image_file_net_run_from_swap = 0x0800;
constexpr std::uint32_t image_file_system = 0x1000;
constexpr std::uint32_t image_file_dll = 0x2000;
constexpr std::uint32_t image_file_up_system_only = 0x4000;
constexpr std::uint32_t image_file_bytes_reversed_hi = 0x8000;

constexpr std::uint32_t image_dll_characteristics_reserved1 = 0x0001;
constexpr std::uint32_t image_dll_characteristics_reserved2 = 0x0002;
constexpr std::uint32_t image_dll_characteristics_reserved3 = 0x0004;
constexpr std::uint32_t image_dll_characteristics_reserved4 = 0x000;

constexpr std::uint32_t image_dll_characteristics_high_entropy_va =
	0x0020;// Image can handle high entropy 64-bit virtual address space.
constexpr std::uint32_t image_dll_characteristics_dynamic_base =
	0x0040;// DLL can be relocated at load time.
constexpr std::uint32_t image_dll_characteristics_force_integrity =
	0x0080;// Code integrity checks are enforced.
constexpr std::uint32_t image_dll_characteristics_nx_compat =
	0x0100;// Image is NX compatible.
constexpr std::uint32_t image_dll_characteristics_no_isolation = 0x0200;
constexpr std::uint32_t image_dll_characteristics_no_seh =
	0x0400;// No structured exception handling.
constexpr std::uint32_t image_dll_characteristics_no_bind =
	0x0800;// Do not bind image.
constexpr std::uint32_t image_dll_characteristics_appcontainer =
	0x1000;// Image must be executed in an app container.
constexpr std::uint32_t image_dll_characteristics_wdm_driver =
	0x2000;// WDM Driver.
constexpr std::uint32_t image_dll_characteristics_guard_cf =
	0x4000;// Image supports control flow guard.
constexpr std::uint32_t image_dll_characteristics_terminal_server_aware =
	0x8000;// Terminal server aware

constexpr std::uint32_t image_scn_type_no_pad = 0x00000008;
constexpr std::uint32_t image_scn_cnt_code = 0x00000020;
constexpr std::uint32_t image_scn_cnt_initialized_data = 0x00000040;
constexpr std::uint32_t image_scn_cnt_uninitialized_data = 0x00000080;
constexpr std::uint32_t image_scn_lnk_other = 0x00000100;
constexpr std::uint32_t image_scn_lnk_info = 0x00000200;
constexpr std::uint32_t image_scn_lnk_remove = 0x00000800;
constexpr std::uint32_t image_scn_lnk_comdat = 0x00001000;
constexpr std::uint32_t image_scn_gprel = 0x00008000;

constexpr std::uint32_t image_scn_align_1bytes = 0x00100000;
constexpr std::uint32_t image_scn_align_2bytes = 0x00200000;
constexpr std::uint32_t image_scn_align_4bytes = 0x00300000;
constexpr std::uint32_t image_scn_align_8bytes = 0x00400000;
constexpr std::uint32_t image_scn_align_16bytes = 0x00500000;
constexpr std::uint32_t image_scn_align_32bytes = 0x00600000;
constexpr std::uint32_t image_scn_align_64bytes = 0x00700000;
constexpr std::uint32_t image_scn_align_128bytes = 0x00800000;
constexpr std::uint32_t image_scn_align_256bytes = 0x00900000;
constexpr std::uint32_t image_scn_align_512bytes = 0x00A00000;
constexpr std::uint32_t image_scn_align_1024bytes = 0x00B00000;
constexpr std::uint32_t image_scn_align_2048bytes = 0x00C00000;
constexpr std::uint32_t image_scn_align_4096bytes = 0x00D00000;
constexpr std::uint32_t image_scn_align_8192bytes = 0x00E00000;

constexpr std::uint32_t image_scn_lnk_nreloc_ovfl =
	0x01000000;// section contains extended relocations.
constexpr std::uint32_t image_scn_mem_discardable =
	0x02000000;// Section can be discarded as needed.
constexpr std::uint32_t image_scn_mem_not_cached =
	0x04000000;// Section can't be cached.
constexpr std::uint32_t image_scn_mem_not_paged =
	0x08000000;// Section can't be paged.
constexpr std::uint32_t image_scn_mem_shared =
	0x10000000;// Section can be shared in memory.
constexpr std::uint32_t image_scn_mem_execute =
	0x20000000;                                         // Section can be executed as code.
constexpr std::uint32_t image_scn_mem_read = 0x40000000;// Section can be read.
constexpr std::uint32_t image_scn_mem_write =
	0x80000000;// Section can be written to.

namespace win_subsystem {
constexpr std::uint32_t image_subsystem_unknown = 0;
constexpr std::uint32_t image_subsystem_native = 1;
constexpr std::uint32_t image_subsystem_windows_gui = 2;
constexpr std::uint32_t image_subsystem_windows_cui = 3;
constexpr std::uint32_t image_subsystem_os2_cui = 5;
constexpr std::uint32_t image_subsystem_posix_cui = 7;
constexpr std::uint32_t image_subsystem_native_windows = 8;
constexpr std::uint32_t image_subsystem_windows_ce_gui = 9;
constexpr std::uint32_t image_subsystem_efi_application = 10;
constexpr std::uint32_t image_subsystem_efi_boot_service_driver = 11;
constexpr std::uint32_t image_subsystem_efi_runtime_driver = 12;
constexpr std::uint32_t image_subsystem_efi_rom = 13;
constexpr std::uint32_t image_subsystem_xbox = 14;
constexpr std::uint32_t image_subsystem_windows_boot_application = 16;
}// namespace win_subsystem

}// namespace constants
#endif// LIBPEINFO_CONSTANTS_H
