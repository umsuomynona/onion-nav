#include <onion-nav.h>

int main(int argc, char *argv[]){

  gtk_init(&argc,&argv);

  if(nav_init()){
    return 1;
  }

  gtk_main();
  
  return 0;
}
