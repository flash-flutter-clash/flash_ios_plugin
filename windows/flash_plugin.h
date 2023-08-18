#ifndef FLUTTER_PLUGIN_FLASH_PLUGIN_H_
#define FLUTTER_PLUGIN_FLASH_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace flash_plugin {

class FlashPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  FlashPlugin();

  virtual ~FlashPlugin();

  // Disallow copy and assign.
  FlashPlugin(const FlashPlugin&) = delete;
  FlashPlugin& operator=(const FlashPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace flash_plugin

#endif  // FLUTTER_PLUGIN_FLASH_PLUGIN_H_
