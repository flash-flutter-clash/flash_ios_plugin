import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'flash_plugin_method_channel.dart';

abstract class FlashPluginPlatform extends PlatformInterface {
  /// Constructs a FlashPluginPlatform.
  FlashPluginPlatform() : super(token: _token);

  static final Object _token = Object();

  static FlashPluginPlatform _instance = MethodChannelFlashPlugin();

  /// The default instance of [FlashPluginPlatform] to use.
  ///
  /// Defaults to [MethodChannelFlashPlugin].
  static FlashPluginPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [FlashPluginPlatform] when
  /// they register themselves.
  static set instance(FlashPluginPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
