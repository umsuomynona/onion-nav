#include <log.h>

void nav_log(char *path){
  GError *error = NULL;
  GTimeZone *tz = g_time_zone_new (NULL);
  GDateTime *agora = g_date_time_new_now (tz);

  if(!g_dir_open(LOG_DIR_PATH,0,&error)){
    g_printerr(CANT_OPEN_DIR);
    g_printerr("%s\n",strerror(errno));
    return ;
  }

  char *real_path = malloc( strlen(LOG_DIR_PATH) + strlen(LOG_FILENAME) + 10);
  sprintf(real_path,"%s%s",LOG_DIR_PATH,LOG_FILENAME);
  FILE *log_file = fopen(real_path,"a+");
  if(!log_file){
    g_printerr(CANT_CREATE_FILE);
    g_printerr("%s\n",strerror(errno));
    return ;
  }
  char *message;
  if(g_date_time_format(agora,"%d/%m/%Y %H:%M:%S"))
    message = malloc(strlen(g_date_time_format(agora,"%d/%m/%Y %H:%M:%S")) + strlen(path)+10);
  else
    message = malloc(strlen(path)+10);

  sprintf(message,"[%s] : %s\n",g_date_time_format(agora,"%d/%m/%Y %H:%M:%S"), path);
  g_print("%s\n",message);
  fprintf(log_file,"%s",message);
  fclose(log_file);
  return ;
}
