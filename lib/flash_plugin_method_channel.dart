import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'flash_plugin_platform_interface.dart';

/// An implementation of [FlashPluginPlatform] that uses method channels.
class MethodChannelFlashPlugin extends FlashPluginPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('flash_plugin');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
