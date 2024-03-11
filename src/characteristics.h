#ifndef PEINFO_CHARACTERISTICS_H
#define PEINFO_CHARACTERISTICS_H

#include "constants.h"

enum class Characteristic {
  relocs_stripped = constants::image_file_relocs_stripped,
  executable_image = constants::image_file_executable_image,
  line_nums_stripped = constants::image_file_line_nums_stripped,
  local_syms_stripped = constants::image_file_local_syms_stripped,
  aggressive_ws_trim = constants::image_file_aggressive_ws_trim,
  large_address_aware = constants::image_file_large_address_aware,
  reserved_for_future = constants::image_file_reserved_for_future,
  bytes_reversed_lo = constants::image_file_bytes_reversed_lo,
  machine_32bit = constants::image_file_32bit_machine,
  debug_stripped = constants::image_file_debug_stripped,
  removable_run_from_swap = constants::image_file_removable_run_from_swap,
  net_run_from_swap = constants::image_file_net_run_from_swap,
  system = constants::image_file_system,
  dll = constants::image_file_dll,
  up_system_only = constants::image_file_up_system_only,
  bytes_reversed_hi = constants::image_file_bytes_reversed_hi,
};

enum class DLL_Characteristic {
  high_entropy_va = constants::image_dll_characteristics_high_entropy_va,
  dynamic_base = constants::image_dll_characteristics_dynamic_base,
  force_integrity = constants::image_dll_characteristics_force_integrity,
  nx_compat = constants::image_dll_characteristics_nx_compat,
  no_isolation = constants::image_dll_characteristics_no_isolation,
  no_seh = constants::image_dll_characteristics_no_seh,
  no_bind = constants::image_dll_characteristics_no_bind,
  appcontainer = constants::image_dll_characteristics_appcontainer,
  wdm_driver = constants::image_dll_characteristics_wdm_driver,
  guard_cf = constants::image_dll_characteristics_guard_cf,
  terminal_server_aware =
      constants::image_dll_characteristics_terminal_server_aware,
};
#endif // PEINFO_CHARACTERISTICS_H
