#include "include/flash_plugin/flash_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "flash_plugin.h"

void FlashPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  flash_plugin::FlashPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
