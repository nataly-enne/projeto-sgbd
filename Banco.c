/*################################################################
  #                      PROJETO ITP 2018.2                      #
  #           Autora: Nátaly Enne da Costa Gonçalo               #
  #                                                              #
  ################################################################
*/
#include "lib/itpFuncoes.c"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  BD_carregar();
 
  printf("#######################################\n");
  printf("#                                     #\n");
  printf("# BEM VINDO AO GERENCIADOR DE BANCOS! #\n");
  printf("#                                     #\n");
  printf("#######################################\n");
  menuBanco();

  return 0;

}
