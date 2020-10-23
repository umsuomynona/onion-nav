#include <webkitgtk-4.0/webkit2/webkit2.h>
#include <messages.h>


#define HOME "http://quosl6t6c64mnn7d.onion/"

#define TOR_PROXY_URI "socks5://127.0.0.1:9050"

#define SETTINGS_PATH "/usr/share/onion-nav/settings.json"

int nav_init();

GtkWidget *webview;

GtkWidget *url_entry;

extern int config_desative_javascript();

WebKitSettings *settings_nav_load_settings(char *path);

extern void resposta(WebKitDownload *download);

extern void home_redirect(GtkButton *botao, gpointer null);

extern void frente_web(GtkButton *button, gpointer null);

extern void voltar_web(GtkButton *button, gpointer null);

extern void nova_url(GtkEntry *search_entry, gpointer null);

extern void nav_log();
