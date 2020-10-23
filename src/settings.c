#include <settings.h>

int settings_desative_javascript(){
  WebKitSettings *settings = webkit_web_view_get_settings (WEBKIT_WEB_VIEW(webview));
  webkit_settings_set_enable_javascript (settings, FALSE);
}

 WebKitSettings *settings_nav_load_settings(char *path){
  JsonParser *parser = json_parser_new();
  WebKitSettings *settings;
  GError *error = NULL;
  if(!json_parser_load_from_file(parser,path,&error)){
    if(error){
      nav_log(error->message);
    }else{
      nav_log(PARSER_ERRO);
    }
    return NULL;
  }
  settings = webkit_settings_new();

  return settings;
}
