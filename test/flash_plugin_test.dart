import 'package:flutter_test/flutter_test.dart';
import 'package:flash_plugin/flash_plugin.dart';
import 'package:flash_plugin/flash_plugin_platform_interface.dart';
import 'package:flash_plugin/flash_plugin_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockFlashPluginPlatform
    with MockPlatformInterfaceMixin
    implements FlashPluginPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final FlashPluginPlatform initialPlatform = FlashPluginPlatform.instance;

  test('$MethodChannelFlashPlugin is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelFlashPlugin>());
  });

  test('getPlatformVersion', () async {
    FlashPlugin flashPlugin = FlashPlugin();
    MockFlashPluginPlatform fakePlatform = MockFlashPluginPlatform();
    FlashPluginPlatform.instance = fakePlatform;

    expect(await flashPlugin.getPlatformVersion(), '42');
  });
}
