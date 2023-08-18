//
//  Generated file. Do not edit.
//

// clang-format off

#include "generated_plugin_registrant.h"

#include <flash_plugin/flash_plugin.h>

void fl_register_plugins(FlPluginRegistry* registry) {
  g_autoptr(FlPluginRegistrar) flash_plugin_registrar =
      fl_plugin_registry_get_registrar_for_plugin(registry, "FlashPlugin");
  flash_plugin_register_with_registrar(flash_plugin_registrar);
}
