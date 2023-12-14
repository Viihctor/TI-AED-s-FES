#include <locale.h>
#include <stdio.h>
// Victor Lucas Tornelli 12/12/2023.
// Matheus Atantes Coimbra 13/12/2023
/*
O objetivo do programa é a gestão de estoque e registro de vendas diárias. O
programa deve permitir apenas a venda de produtos em estoque, registrar as
vendas do dia, gerar um relatório de meias em estoque e um relatório de vendas
do dia com o lucro obtido.
*/

int quantidade=0, preco=1, custo=2, venda=3;
float Produtos[4][4]; // Matriz Globalizada de estoque
float Relatorio[4];   // Matriz Globalizada para armazenagem de dados relevantes
const char *categorias[] = {"Infantis Lisas", "Infantis Estampadas",
                            "Adultas Lisas", "Adultas Estampadas"};

// Função para Inicializar o Programa
int inicializarEstoque() {
  int i;
  for (i = 0; i < 4; i++) {
    
    printf("Forneça a quantidade de Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[i][quantidade]);

    printf("Forneça a preço das Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[i][preco]);

    printf("Forneça a custo de produção de Meias %s:\n--> ", categorias[i]);
    scanf("%f", &Produtos[i][custo]);

    printf("\n\n");
  }

  // Formatação dos Relatorios
  for(i = 0; i < 4; i++) {
    Relatorio[i]=0;
    Produtos[i][venda]=0;
  }
}

// função para Imprimir o Valores do Dia
int relatorioVendasELucro() {
  int x;
  printf("\nRelatorio:\n");
  for(x = 0; x < 4; x++) {
    printf("%.0f Vendas de %s = R$%.2f\n", Produtos[x][venda], categorias[x], Produtos[x][preco]*Produtos[x][venda]);
  }
  printf("\nArrecadação Bruta = R$%.2f\n", Relatorio[1]);
  printf("Custo Total de Produção = R$%.2f\n", Relatorio[2]);
  printf("\nLucro Liquido = R$%.2f\n", Relatorio[3]);

  printf("\n");
}

// Função para Imprimir o Estoque
int relatorioEstoque() {
  printf("\nEstoque:\n");
  printf("Infantil Lisa = %.0f\nInfantil Estampada = %.0f\nAdulta Lisa = %.0f\nAdulta Estampada = %.0f\n" ,Produtos[0][quantidade], Produtos[1][quantidade], Produtos[2][quantidade], Produtos[3][quantidade]);

  printf("\n");
}

// Função que realiza Alteração no Estoque + Relatorio
int registraVenda(float quantidadeDaVenda,int rep) {
  rep = rep-1;
  // Redução de Estoque Especifica
  Produtos[rep][quantidade] -= quantidadeDaVenda;
  // Quantidade de Venda Especifica
  Produtos[rep][venda] += quantidadeDaVenda;
  // Quantidade de Venda Totais
  Relatorio[0] += quantidadeDaVenda;
  // Lucro Bruto
  Relatorio[1] += quantidadeDaVenda*Produtos[rep][preco];
  // Custo Total
  for(rep = 0; rep < 4; rep++) {
    Relatorio[2] += Produtos[rep][quantidade]*Produtos[rep][custo];
  }
  // Lucro Liquido
  Relatorio[3] = Relatorio[1]-Relatorio[2];

  printf("\n");
}

// Função para escolha de produto
int vendaProduto() {
  printf("\nEntre com o tipo de meia vendida!\n");
  printf("(1)-Infantil Lisa == %.0f | (2)-Infantil Estampada == %.0f | (3)-Adulta Lisa == %.0f | (4)-Adulta Estampada == %.0f |\n" ,Produtos[0][quantidade], Produtos[1][quantidade], Produtos[2][quantidade], Produtos[3][quantidade]);

  int opcaoVenda;
  scanf("%d",&opcaoVenda);

  int rep;
  if (opcaoVenda >= 1 && opcaoVenda <= 4) {
    for(rep = 0; rep < 4; rep++) {
      if (opcaoVenda == rep) {
        if (Produtos[rep][quantidade] > 0) {
          printf("\nDigite a quantidade de produtos vendida: ");

          float quantidadeDaVenda;
          scanf("%f",&quantidadeDaVenda);

          if (Produtos[rep][quantidade] >= quantidadeDaVenda) {
            registraVenda(quantidadeDaVenda, rep);
          }
          else if (Produtos[rep][quantidade] < quantidadeDaVenda) {
          printf("\nNão a produtos suficientes no estoque!\n\n");
          }
        }

        else if (Produtos[rep][quantidade] <= 0) {
          printf("\nNão a mais produtos no estoque!\n\n");
        }
      }
    }
  }

  else {
    printf("\nProduto não encontrado!\n\n");
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

  return 0;
}
