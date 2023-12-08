#include <stdio.h>
// Victor Lucas Tornelli 08/05/2023
/*
O objetivo do programa é a gestão de estoque e registro de vendas diárias. O
programa deve permitir apenas a venda de produtos em estoque, registrar as
vendas do dia, gerar um relatório de meias em estoque e um relatório de vendas
do dia com o lucro obtido.
*/

float Produtos[4][5]; // Matriz Globalizada de estoque
float Produtos[4][5]; // Matriz Globalizada para armazenagem de dados relevantes

// Função para Inicializar o Programa
int inicializarEstoque() {}
// Função para escolha de produto
int vendaProduto() {}
// Função que realiza Alteração no Estoque
int registraVenda() {}
// Função para Imprimir o Estoque
int relatorioEstoque() {}
// função para Imprimir o Valores do Dia
int relatorioVendasELucro() {}
// Função Principal
int main(void) {

  printf("Bem Vindo ao Gestor de Vendas!\n");
  inicializarEstoque();

  int opcao = 0;
  while (opcao != 6) { // laço de repetição para possibilitar varias ações
    printf("Oque Gostaria de Fazer?\n");
    printf("1 - Vender Produto\n");
    printf("2 - Registrar Venda\n");
    printf("3 - Imprimir Relatorio de Estoque\n");
    printf("4 - Imprimir Relatorio de Vendas e Lucro\n");
    printf("5 - Imprimir Ambos os Relatorios\n");
    printf("6 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:;
    case 2:;
    case 3:;
    case 4:;
    case 5:;
    case 6:;
    default:;
    }
  }

  return 0;
}
