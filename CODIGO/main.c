#include <locale.h>
#include <stdio.h>
// Victor Lucas Tornelli 08/05/2023.
// Matheus Atantes Coimbra 13/12/2023
/*
O objetivo do programa é a gestão de estoque e registro de vendas diárias. O
programa deve permitir apenas a venda de produtos em estoque, registrar as
vendas do dia, gerar um relatório de meias em estoque e um relatório de vendas
do dia com o lucro obtido.
*/

float Produtos[5][4]; // Matriz Globalizada de estoque
float Relatorio[4];   // Matriz Globalizada para armazenagem de dados relevantes
const char *categorias[] = {"Infantis Lisas", "Infantis Estampadas",
                            "Adultas Lisas", "Adultas Estampadas"};

// Função para Inicializar o Programa
int inicializarEstoque() {
  for (int i = 0; i < 4; i++) {
    
    printf("Forneça a quantidade de Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[0][i]);

    printf("Forneça a preço das Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[1][i]);

    printf("Forneça a custo de produção de Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[2][i]);

    printf("\n\n");
  }
}

// função para Imprimir o Valores do Dia
int relatorioVendasELucro() {}

// Função para Imprimir o Estoque
int relatorioEstoque() {}

// Função que realiza Alteração no Estoque
int registraVenda(int quantidadeDaVenda) {}

// Função para escolha de produto
int vendaProduto() {
  printf("\nEntre com o tipo de meia vendida!\n");
  printf("(1)-Infantil Lisa == %.0f | (2)-Infantil Estampada == %.0f | (3)-Adulta Lisa == %.0f | (4)-Adulta Estampada == %.0f |\n" ,Produtos[0][0], Produtos[1][0], Produtos[2][0], Produtos[3][0]);

  int opcaoVenda;
  scanf("%d",&opcaoVenda);

  if (opcaoVenda > 4 && opcaoVenda < 1) {
    printf("\nProduto não encontrado!\n");
  }
  else {
    for(int rep = 0; rep < 4; rep++) {
      if (opcaoVenda == rep) {
        if (Produtos[0][rep] > 0) {
          printf("\nDigite a quantidade de produtos vendida: ");

          int quantidadeDaVenda;
          scanf("%d",&quantidadeDaVenda);

          if (Produtos[0][rep] >= quantidadeDaVenda) {
            Relatorio[0]=rep;
            registraVenda(quantidadeDaVenda);
          }
          else if (Produtos[0][rep] < quantidadeDaVenda) {
          printf("\nNão a produtos suficientes no estoque!\n");
          }
        }

        else if (Produtos[0][rep] <= 0) {
          printf("\nNão a mais produtos no estoque!\n");
        }
      }
    }
  }
}

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
    printf("--> ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:;
      vendaProduto();
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
