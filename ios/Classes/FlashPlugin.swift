import Flutter
import UIKit

public class FlashPlugin: NSObject, FlutterPlugin {
  public static func register(with registrar: FlutterPluginRegistrar) {
    let channel = FlutterMethodChannel(name: "FlashPlugin", binaryMessenger: registrar.messenger())
    let instance = FlashPlugin()
    registrar.addMethodCallDelegate(instance, channel: channel)
  }

  public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
      switch call.method{
      case "getPlatformVersion":
          result("iOS " + UIDevice.current.systemVersion)
      default:
          var params:Dictionary<String,Any> = Dictionary<String,Any>()
          params["call"] = call
          params["result"] = result

          NotificationCenter.default.post(name: NSNotification.Name.flashPluginFlutterMethodCallName, object: params)
          
      }
  }
}

public extension Notification.Name{
    static let flashPluginFlutterMethodCallName = Notification.Name("kflashPluginFlutterMethodCallName")

}
