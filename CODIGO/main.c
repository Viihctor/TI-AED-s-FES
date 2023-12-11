#include <locale.h>
#include <stdio.h>
// Victor Lucas Tornelli 08/05/2023.
/*
O objetivo do programa é a gestão de estoque e registro de vendas diárias. O
programa deve permitir apenas a venda de produtos em estoque, registrar as
vendas do dia, gerar um relatório de meias em estoque e um relatório de vendas
do dia com o lucro obtido.
*/

float Produtos[4][5]; // Matriz Globalizada de estoque
float Relatorio[4];   // Matriz Globalizada para armazenagem de dados relevantes
const char *categorias[] = {"Infantis Lisas", "Infantis Estampadas",
                            "Adultas Lisas", "Adultas Estampadas"};
// Função para Inicializar o Programa
int inicializarEstoque() {
  for (int i = 0; i < 4; i++) {
    
    printf("Forneça a quantidade de Meias %s: \n", categorias[i]);
    scanf("%f", &Produtos[i][0]);

    printf("Forneça a preço das Meias %s: \n", categorias[i]);
    scanf("%f", &Produtos[i][1]);

    printf("Forneça a custo de produção de Meias %s: \n", categorias[i]);
    scanf("%f", &Produtos[i][2]);

    printf("\n");
  }
}

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
  setlocale(LC_ALL, "Portuguese");

  printf("Bem Vindo ao Gestor de Vendas!\n");
  inicializarEstoque();

  int opcao = 0;
  while (opcao != 5) { // laço de repetição para possibilitar varias ações
    printf("Oque Gostaria de Fazer?\n");
    printf("1 - Vender Produto\n");
    printf("2 - Imprimir Relatorio de Estoque\n");
    printf("3 - Imprimir Relatorio de Vendas e Lucro\n");
    printf("4 - Imprimir Ambos os Relatorios\n");
    printf("5 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:;
      break;
    case 2:;
      break;
    case 3:;
      break;
    case 4:;
      break;
    case 5:
      printf("Encerrando Sistema!\n");
      break;
      break;
    default:
      printf("Escolha uma alternativa valida!\n");
      break;
    }
  }

  return 0;
}
