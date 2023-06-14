import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:flash_plugin/flash_plugin_method_channel.dart';

void main() {
  MethodChannelFlashPlugin platform = MethodChannelFlashPlugin();
  const MethodChannel channel = MethodChannel('flash_plugin');

  TestWidgetsFlutterBinding.ensureInitialized();

  setUp(() {
    channel.setMockMethodCallHandler((MethodCall methodCall) async {
      return '42';
    });
  });

  tearDown(() {
    channel.setMockMethodCallHandler(null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.getPlatformVersion(), '42');
  });
}
