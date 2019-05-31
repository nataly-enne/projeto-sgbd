#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
################################################################
#                      Funçőes do Banco                        #
################################################################
*/

// Variáveis Globais
char nomeTabela[30];
char nomeColuna[30];


typedef struct {
    char nome[30];
    int quantColunas;
    int tipos[30];
    char colunas[20][30];
    char linhas[20][20][30];
}BD_tabela;

struct bancoDados {
    BD_tabela tabelas[20];
};

struct bancoDados ITPDB;

void BD_salvar(){
    FILE *arquivo = fopen("data/database.itp", "w");
    if (arquivo == NULL){
        fprintf(stderr, "Erro ao carregar a DB\n");
        exit(1);
    }
    // escrever a estrutura no arquivo
    fwrite(&ITPDB, sizeof(struct bancoDados), 1, arquivo);

    if(fwrite == 0) printf("Erro ao salvar\n");
    fclose (arquivo);

}

void BD_carregar(){
    FILE *arquivo = fopen ("data/database.itp", "r");

    if (arquivo == NULL) return;

    // carregar dados do arquivo e os insere na variável ITPDB
    fread(&ITPDB, sizeof(struct bancoDados), 1, arquivo);
    fclose (arquivo);
}
// verificar se o valor que o usuário colocar da chave primária já é existente
int verificarChavePrimaria(int indexTabela, char *valor){
    for(int i = 0; i < 20; i++){
        if(strcmp(ITPDB.tabelas[indexTabela].linhas[i][0], valor) == 0) return 1;
    }
    return 0;
}

// verificar se o nome da coluna já é existente
int verificarNomeColuna(int indexTabela, char *nomeColuna){
    for(int i = 0; i < 20; i++){
        if(strcmp(ITPDB.tabelas[indexTabela].colunas[i], nomeColuna) == 0) return 1;
    }
    return 0;
}

// verificar se o nome da tabela já é existente
int verificarNomeTabela(char * nomeTabela){
    for(int i = 0; i < 10; i++){
        if(strcmp(ITPDB.tabelas[i].nome, nomeTabela) == 0) return i;
    }
    return -1;
}

// pegar proximo espaço vazio do banco | pegar próxima tabela/linha vazia (array)
int pegarSlotVazio(){ // obter a index do próximo espaço livre
    for(int i = 0; i < 10; i++){
        if(ITPDB.tabelas[i].quantColunas == 0) return i;
    }
    return 0;
}

int pegarProxLinhaVazia(int indexTabela){
    for(int i = 0; i < 10; i++){
        if(strlen(ITPDB.tabelas[indexTabela].linhas[i][0]) == 0) return i;
    }
    return 19;
}

char * tipos[] = {"INT", "CHAR", "FLOAT", "DOUBLE", "STRING"};
char * tipoVariavel(int tipo){
    return tipos[tipo-1] ? tipos[tipo-1] : "Desconhecido";
}

int detectarTipos(char * string, int tipoEsperado){
    int tiposDetectados[5];
    tiposDetectados[4] = 1; // string
    if(strlen(string) == 1) tiposDetectados[1] = 1; // char
    if(strtof(string, NULL) != 0 && strchr(string, '.')) tiposDetectados[2] = 1; // float
    if(strtod(string, NULL) != 0 && strchr(string, '.')) tiposDetectados[3] = 1; // double
    if(strtol(string, NULL, 10) != 0 && tiposDetectados[2] != 1 && tiposDetectados[3] != 1) tiposDetectados[0] = 1; // int
    // uma entrada pode ser string e int ao mesmo tempo ou char e int ou float e double, por isso é retornado uma array.
    return tiposDetectados[tipoEsperado-1];
}

/*
################################################################
#                      Funçőes do Menu                         #
################################################################
*/

void criarTabela(){
    int quantColunas, tipo, indexTabela = pegarSlotVazio();

    printf("Digite o nome da tabela: ");
    scanf("%s", nomeTabela);

    while(verificarNomeTabela(nomeTabela) != -1){
        printf("Nome de tabela já existente!\n");
        printf("Digite o nome da tabela: ");
        scanf("%s", nomeTabela);
    }
    strcpy(ITPDB.tabelas[indexTabela].nome, nomeTabela);
    printf("Digite a quantidade de colunas: ");
    scanf("%i", &ITPDB.tabelas[indexTabela].quantColunas);

    // não deixa colocar quantidade de colunas desejadas menores que 1
    while(ITPDB.tabelas[indexTabela].quantColunas < 1){
        printf("O número mínimo é 1! Insira novamente: ");
        scanf("%i", &ITPDB.tabelas[indexTabela].quantColunas);
    }

    printf("Digite o nome da chave primaria: ");
    scanf("%s", nomeColuna);
    strcpy(ITPDB.tabelas[indexTabela].colunas[0], nomeColuna);
    ITPDB.tabelas[indexTabela].tipos[0] = 1;

    fflush(stdin); //apagar o buffer do teclado

    for (int i = 1; i < ITPDB.tabelas[indexTabela].quantColunas; i++) {
        printf("Digite o nome da coluna %i: ", i);
        scanf("%s", nomeColuna);

        while(verificarNomeColuna(indexTabela, nomeColuna) == 1){
            printf("Nome de coluna já existente!\n");
            printf("Digite o nome da tabela: ");
            scanf("%s", nomeColuna);
        }
        strcpy(ITPDB.tabelas[indexTabela].colunas[i], nomeColuna);

        printf("Digite o número referente ao tipo da coluna:\n"
               "1-INT\n"
               "2-CHAR\n"
               "3-FLOAT\n"
               "4-DOUBLE\n"
               "5-STRING\n");
        scanf("%d", &tipo);
        while(tipo < 1 || tipo > 5){
            printf("Seleção inválida! Digite novamente: ");
            scanf("%d", &tipo);
        }
        ITPDB.tabelas[indexTabela].tipos[i] = tipo;
    }
    printf("\nTabela criada!");
    BD_salvar(); // força o salvamento da DB
}

void apagarTabela(){
    BD_salvar();
    BD_tabela conjuntoVazio;
    int indexTabela = -1;

    while(indexTabela == -1){
        printf("Digite o nome da tabela: ");
        scanf("%s", nomeTabela);

        while(verificarNomeTabela(nomeTabela) == -1){
            printf("Nome de tabela inexistente!\n");
            printf("Digite o nome da tabela: ");
            scanf("%s", nomeTabela);
        }
        indexTabela = verificarNomeTabela(nomeTabela); // ele sai do while quando é diferente de -1
    }
    memset(&ITPDB.tabelas[indexTabela], 0, sizeof(conjuntoVazio)); // substituindo os dados da tabela por NULL
    printf("Tabela apagada!");
}

void listarTabelas(){
    printf("Listando tabelas...\n");
    printf("=== Tabelas ===\n");
    for(int i = 0; i < 10; i++){
        if(strlen(ITPDB.tabelas[i].nome) != 0) printf("| %s |\n", ITPDB.tabelas[i].nome);
		// se existir o nome da tabela no DB ele imprime, senăo ele năo faz nada.
    }
    BD_salvar();
}

void listarDadosTabela(){
    BD_salvar();

    int indexTabela = -1; //só pra entrar no WHILE

    printf("== Listando valores ==\n");

    while(indexTabela == -1){
        printf("Digite o nome da tabela: ");
        scanf("%s", nomeTabela);
        indexTabela = verificarNomeTabela(nomeTabela);
    }
    printf("Colunas: ");
    for(int i = 0; i < ITPDB.tabelas[indexTabela].quantColunas; i++){
        if(ITPDB.tabelas[indexTabela].colunas[i]){
            if(i == 0) printf("%s* (INT) | ", ITPDB.tabelas[indexTabela].colunas[i]);
            else printf("%s (%s) | ", ITPDB.tabelas[indexTabela].colunas[i], tipoVariavel(ITPDB.tabelas[indexTabela].tipos[i]));
        }
    }

    for(int i = 0; i < 20; i++){ // linhas
        if(strlen(ITPDB.tabelas[indexTabela].linhas[i][0]) != 0) printf("\nLinha %i: ", i);
        for(int j = 0; j < ITPDB.tabelas[indexTabela].quantColunas; j++){ // colunas
            if(strlen(ITPDB.tabelas[indexTabela].linhas[i][0]) != 0) printf("%s | ", ITPDB.tabelas[indexTabela].linhas[i][j]);
        }
    }
}

void inserirLinhasColuna(){
    BD_salvar();

    char * valorColuna = malloc(20);
    int indexTabela = -1, linhasQuant = 1;

    while(indexTabela == -1){
        printf("\nDigite o nome da tabela: ");
        scanf("%s", nomeTabela);
        indexTabela = verificarNomeTabela(nomeTabela); // atribui o valor da index da tabela
    }
    int linhaLivre = pegarProxLinhaVazia(indexTabela);
    printf("Quantas linhas deseja inserir? ");
    scanf("%i", &linhasQuant);

    while(linhasQuant < 1){
        printf("O número mínimo é 1! Insira novamente: ");
        scanf("%i", &linhasQuant);
    }
    for(int i = linhaLivre; i < linhaLivre+linhasQuant; i++){
        printf("=== Linha %i ===\n", i);
        for(int j = 0; j < ITPDB.tabelas[indexTabela].quantColunas; j++){
            printf("Digite os dados da coluna %s (%s)- ", ITPDB.tabelas[indexTabela].colunas[j], tipoVariavel(ITPDB.tabelas[indexTabela].tipos[j]));
            scanf("%s", valorColuna);
            while(detectarTipos(valorColuna, ITPDB.tabelas[indexTabela].tipos[j]) != 1){
                printf("Você inseriu um valor com tipo inválido! Esperado: %s\nInsira novamente:", tipoVariavel(ITPDB.tabelas[indexTabela].tipos[j]));
                scanf("%s", valorColuna);
            }
            if(j == 0){
                while(verificarChavePrimaria(indexTabela, valorColuna) == 1){
                    printf("Valor existente! Insira outro valor: ");
                    scanf("%s", valorColuna);
                }
            }
            strcpy(ITPDB.tabelas[indexTabela].linhas[i][j], valorColuna);
        }
    }
    printf("\nLinha(s) inserida(s) com sucesso!");
}

void apagarLinhaTabela(){
    BD_salvar();

    int indexTabela = -1;
    char *primary = malloc(20);

    while(indexTabela == -1){
        printf("\nDigite o nome da tabela: ");
        scanf("%s", nomeTabela);

        while(verificarNomeTabela(nomeTabela) == -1){
            printf("Nome de tabela inexistente!\n");
            printf("Digite o nome da tabela: ");
            scanf("%s", nomeTabela);
        }
        indexTabela = verificarNomeTabela(nomeTabela);
    }
    printf("Digite o valor de %s para apagar: ", ITPDB.tabelas[indexTabela].colunas[0]);
    scanf("%s", primary);
    for(int i = 0; i < 20; i++){
        if(strcmp(ITPDB.tabelas[indexTabela].linhas[i][0], primary) == 0){
            memset(&ITPDB.tabelas[indexTabela].linhas[i], 0, sizeof(20 * 20 * 30));
            break;
        }
    }
}

void opcoesMenu(){
  printf("\n ___________________________________\n");
  printf(
      "\n| 1- Criar Tabela                   |"
      "\n| 2- Listar Tabelas                 |"
      "\n| 3- Adicionar valor a tabela       |"
      "\n| 4- Listar Dados da tabela         |"
      "\n| 5- Apagar valor da tabela         |"
      "\n| 6- Apagar tabela                  |"
      "\n| 0- Sair                           |");
  printf("\n ___________________________________\n\n");

}

void menuBanco() {
  int op = 1;
  while (op != 0) {
    fflush(stdin);

    opcoesMenu();

    printf("\nEscolha: ");
    scanf("%d", &op);

    fflush(stdin);
    switch (op) {
    case 1:
      criarTabela();
      break;
    case 2:
      listarTabelas();
      break;
    case 3:
      inserirLinhasColuna();
      break;
    case 4:
      listarDadosTabela();
      break;
    case 5:
      apagarLinhaTabela();
      break;
    case 6:
      apagarTabela();
      break;
    case 0:
      printf("Até a próxima!\n");
      BD_salvar();
      break;
    default:
      printf("Opçăo inválida! Selecione uma das opçőes:\n");
      opcoesMenu();
      break;
    }
  }
}
