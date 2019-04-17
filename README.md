# ITPProjetoSGBD
É um projeto implementado para a III unidade das disciplinas Introdução às Técnicas de Programação e Praticas de Técnicas de Programação, ministradas pelo Mestre André Luiz da Silva Solino no Instituto Metrópole Digital na Faculdade Federal do Rio Grande do Norte.

# What is it?
O projeto consiste em implementar um Sistema de Gerenciamento de Banco de Dados simplificado baseado no modelo relacional.

### O SGBD ITP (nome dado ao SGBD simplificado) é capaz de realizar as seguintes operações:

<ul>

<h3>1. Criar um tabela</h3> 
  <li>
     Os tipos de dados para as colunas são dos tipos primitivos em C (char, int, float e double) e strings;
  </li>
  <li>
    Os valores são armazenados em bytes;
  </li>
  <li>
    Na criação da tabela é solicitado um nome de coluna para ser a chave primária e a chave primária é obrigatoriamente do tipo inteiro sem sinal.
  </li>
  
  <h3>2. Listar todas as tabelas</h3>
  <li>
    Mostra para o usuário as tabelas existentes.
  </li>
  
  <h3>3. Criar uma nova linha na tabela</h3>
  <li>
    O usuário informa o nome da tabela;
  </li>
  <li>
    O sistema solicita os valores de cada uma das colunas;
  </li>
  <li>
    O sistema verifica a chave primária - em uma tabela deve existir um e apenas um valor de chave primária. Se o usuário informar uma chave que já existe, sistema emite uma mensagem de erro e não inserie o registro.
  </li>
  
  <h3>4. Listar todos os dados de uma tabela</h3>
  <li>
    O usuário informa qual a tabela para serem listados os dados;
  </li>
  <li>
    Os dados são obtidos a partir do arquivo que armazena as tabelas.
  </li>
  <h3>5. Pesquisar valor em uma tabela</h3>
  <li>Não foi desenvolvido.</li>
  
  <h3>6. Apagar valor de uma tabela</h3>
  <li>
    O usuário informaa o nome da tabela e a chave primária a ser apagada.
  </li>
  
  <h3>7. Apagar uma tabela</h3>
  <li> O usuário fornecerá o nome da tabela a ser apagada.

 </ul>
 



