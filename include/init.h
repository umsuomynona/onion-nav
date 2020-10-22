#include <webkitgtk-4.0/webkit2/webkit2.h>

#define HOME "http://quosl6t6c64mnn7d.onion/"

int nav_init();

GtkWidget *webview;

GtkWidget *url_entry;

extern void resposta(WebKitDownload *download);

extern void home_redirect(GtkButton *botao, gpointer null);

extern void frente_web(GtkButton *button, gpointer null);

extern void voltar_web(GtkButton *button, gpointer null);

extern void nova_url(GtkEntry *search_entry, gpointer null);
