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

float Produtos[4][4]; // Matriz Globalizada de estoque
float Relatorio[4];   // Matriz Globalizada para armazenagem de dados relevantes
const char *categorias[] = {"Infantis Lisas", "Infantis Estampadas",
                            "Adultas Lisas", "Adultas Estampadas"};

// Função para Inicializar o Programa
int inicializarEstoque() {
  int i;
  for (i = 0; i < 4; i++) {
    
    printf("Forneça a quantidade de Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[i][0]);

    printf("Forneça a preço das Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[i][1]);

    printf("Forneça a custo de produção de Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[i][2]);

    printf("\n\n");
  }

  // Formatação dos Relatorios
  for(i = 0; i < 4; i++) {
    Relatorio[i]=0;
    Produtos[i][3]=0;
  }
}

// função para Imprimir o Valores do Dia
int relatorioVendasELucro() {
  int x;
  printf("\nRelatorio:\n");
  for(x = 0; x < 4; x++) {
    printf("%.0f Vendas de %s = R$%.2f\n", Produtos[3][x], categorias[x], Produtos[1][x]*Produtos[3][x]);
  }
  printf("Arrecadação Bruta = R$%.2f\n", Relatorio[1]);
  printf("Custo Total de Produção = R$%.2f\n", Relatorio[2]);
  printf("\nLucro Liquido = R$%.2f\n", Relatorio[3]);

  printf("\n");
}

// Função para Imprimir o Estoque
int relatorioEstoque() {
  printf("\nEstoque:\n");
  printf("Infantil Lisa = %.0f\nInfantil Estampada = %.0f\nAdulta Lisa = %.0f\nAdulta Estampada = %.0f\n" ,Produtos[0][0], Produtos[1][0], Produtos[2][0], Produtos[3][0]);

  printf("\n");
}

// Função que realiza Alteração no Estoque + Relatorio
int registraVenda(float quantidadeDaVenda,int rep) {
  int z;
  // Redução de Estoque Especifica
  Produtos[rep][0] = Produtos[rep][0]-quantidadeDaVenda;
  // Quantidade de Venda Especifica
  Produtos[rep][3] += quantidadeDaVenda;
  // Quantidade de Venda Totais
  Relatorio[0] += quantidadeDaVenda;
  // Lucro Bruto
  Relatorio[1] += quantidadeDaVenda*Produtos[1][rep];
  // Custo Total
  for(rep = 0; rep < 4; rep++) {
    Relatorio[2] += Produtos[rep][0]*Produtos[rep][2];
  }
  // Lucro Liquido
  Relatorio[3] = Relatorio[1]-Relatorio[2];

  printf("\n");
}

// Função para escolha de produto
int vendaProduto() {
  printf("\nEntre com o tipo de meia vendida!\n");
  printf("(1)-Infantil Lisa == %.0f | (2)-Infantil Estampada == %.0f | (3)-Adulta Lisa == %.0f | (4)-Adulta Estampada == %.0f |\n" ,Produtos[0][0], Produtos[1][0], Produtos[2][0], Produtos[3][0]);

  int opcaoVenda;
  scanf("%d",&opcaoVenda);

  if (opcaoVenda > 4 && opcaoVenda < 1) {
    printf("\nProduto não encontrado!\n\n");
  }
  else {
    for(int rep = 0; rep < 4; rep++) {
      if (opcaoVenda == rep) {
        if (Produtos[rep][0] > 0) {
          printf("\nDigite a quantidade de produtos vendida: ");

          float quantidadeDaVenda;
          scanf("%f",&quantidadeDaVenda);

          if (Produtos[rep][0] >= quantidadeDaVenda) {
            registraVenda(quantidadeDaVenda, rep);
          }
          else if (Produtos[rep][0] < quantidadeDaVenda) {
          printf("\nNão a produtos suficientes no estoque!\n\n");
          }
        }

        else if (Produtos[rep][0] <= 0) {
          printf("\nNão a mais produtos no estoque!\n\n");
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
      relatorioEstoque();
      break;
    case 3:;
      relatorioVendasELucro();
      break;
    case 4:;
      relatorioEstoque();
      relatorioVendasELucro();
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
