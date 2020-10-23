#include <webkitgtk-4.0/webkit2/webkit2.h>
#include <json-glib-1.0/json-glib/json-glib.h>

#define SETTINGS_PATH "/usr/share/onion-nav/settings.json"
extern GtkWidget *webview;

struct _settings{

  char *home_link;
  char *links_dir_path;

}settings;


int settings_desative_javascript();

WebKitSettings *settings_nav_load_settings(char *path);

extern void nav_log(char *path);
