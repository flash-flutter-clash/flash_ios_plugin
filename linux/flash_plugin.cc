#include "include/flash_plugin/flash_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>

#include "flash_plugin_private.h"

#define FLASH_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), flash_plugin_get_type(), \
                              FlashPlugin))

struct _FlashPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(FlashPlugin, flash_plugin, g_object_get_type())

// Called when a method call is received from Flutter.
static void flash_plugin_handle_method_call(
    FlashPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  const gchar* method = fl_method_call_get_name(method_call);

  if (strcmp(method, "getPlatformVersion") == 0) {
    response = get_platform_version();
  } else {
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  fl_method_call_respond(method_call, response, nullptr);
}

FlMethodResponse* get_platform_version() {
  struct utsname uname_data = {};
  uname(&uname_data);
  g_autofree gchar *version = g_strdup_printf("Linux %s", uname_data.version);
  g_autoptr(FlValue) result = fl_value_new_string(version);
  return FL_METHOD_RESPONSE(fl_method_success_response_new(result));
}

static void flash_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(flash_plugin_parent_class)->dispose(object);
}

static void flash_plugin_class_init(FlashPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = flash_plugin_dispose;
}

static void flash_plugin_init(FlashPlugin* self) {}

static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  FlashPlugin* plugin = FLASH_PLUGIN(user_data);
  flash_plugin_handle_method_call(plugin, method_call);
}

void flash_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  FlashPlugin* plugin = FLASH_PLUGIN(
      g_object_new(flash_plugin_get_type(), nullptr));

  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar),
                            "flash_plugin",
                            FL_METHOD_CODEC(codec));
  fl_method_channel_set_method_call_handler(channel, method_call_cb,
                                            g_object_ref(plugin),
                                            g_object_unref);

  g_object_unref(plugin);
}
