#include <stdio.h>

int main() {
  // atribuição das variaveis
  int k, a, b, c;
  int posicaolista = 0; // Inicia em 0 a posição inicial na lista
  int passinhos = 0;    // Inicia em 0 a contagem dos passinhos dados

  printf("Insira Quatro Numeros inteiros:\n ");
  scanf("%d %d %d %d", &k, &a, &b, &c);

  int L[1000]; // Vetor com 1000 inteiros
  L[0] = k;    // O primeiro valor é o k.

  for(int i = 1; i<1000; i++){
   L[i] = ((L[i-1] * a) % b) + c;
  }
  
  while (1) { // Como não sabemos quantos passos serão dados, ficará em um loop
  // infinito até alguma condição quebrar esse loop.

    int s = L[posicaolista]; // O valor

    if (s == 0) { // Se o jogador cair em um zero acaba o jogo
      printf("Acabou!!! Parou na posicao %d depois de dar %d passinhos!\n\n", posicaolista, passinhos);
      break;
    } //certo

    if (s > 0) {
      L[posicaolista]--;                   
      posicaolista = (posicaolista + s) % 1000; // Calcula a nova posicao
      passinhos = passinhos + s;
      
    } else {
       L[posicaolista]++; // Acrescenta uma uma unidade do valor
      posicaolista = (posicaolista + s + 1000) % 1000;
      passinhos = passinhos - s;
    }
  }

  return 0;
}
