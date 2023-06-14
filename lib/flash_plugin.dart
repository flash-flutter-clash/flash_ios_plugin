
import 'flash_plugin_platform_interface.dart';

class FlashPlugin {
  Future<String?> getPlatformVersion() {
    return FlashPluginPlatform.instance.getPlatformVersion();
  }
}
