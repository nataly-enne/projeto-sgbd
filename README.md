# ITPProjetoSGBD
É um projeto implementado para a unidade III das disciplinas Introdução às Técnicas de Programação e Práticas de Técnicas de Programação, ministradas pelo Mestre André Luiz da Silva Solino no Instituto Metrópole Digital, na Universidade Federal do Rio Grande do Norte.

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
  
  <h3>5. Apagar valor de uma tabela</h3>
  <li>
    O usuário informará o nome da tabela e a chave primária a ser apagada.
  </li>
  
  <h3>6. Apagar uma tabela</h3>
  <li> O usuário fornecerá o nome da tabela a ser apagada.

 </ul>
 
 #### Para compilar é necessário estar no diretório do projeto.
 #### Em seguida, no terminal, basta digitar:
 
 <pre><code> gcc -o exe Banco.c</code></pre>

#### Para executar o programa, escreva a seguinte linha de código:

<pre><code>./exe</code></pre>


### Colaboradores
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/SrtaEnne">
        <img src="https://avatars3.githubusercontent.com/u/26802307?s=400&v=4" width="100px;" alt="Nátaly Enne"/>
        <br />
        <sub><b>Nátaly Enne</b></sub>
      </a><br />
      <a href="https://github.com/SrtaEnne/projeto-sgdb/commits?author=SrtaEnne" title="Code">💻</a>
    </td>
    <td align="center">
      <a href="https://github.com/neves768">
        <img src="https://avatars2.githubusercontent.com/u/5482004?s=400&v=4" width="100px;" alt="Christopher Neves"/>
        <br />
        <sub><b>Christopher Neves</b></sub>
      </a><br />
      <a href="https://github.com/SrtaEnne/projeto-sgdb/commits?author=neves768" title="Code">💻</a>
    </td>
  </tr>
</table>


