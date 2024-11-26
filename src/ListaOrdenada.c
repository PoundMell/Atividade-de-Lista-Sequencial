#include "ListaOrdenada.h"
#include <stdlib.h>

bool resize(LISTA* l, int novaCapacidade) { // Nova função
  if (novaCapacidade < l->nroElem) return false; // Caso seja menor que o número de elementos
  REGISTRO* novoArray = (REGISTRO*)realloc(l->A, novaCapacidade * sizeof(REGISTRO));
  if (novoArray == NULL) return false; // Caso dê falha na realocação
  l->A = novoArray;
  l->capacidade = novaCapacidade;
  return true;
}

void inicializarLista(LISTA* l) {
  l->capacidade = 50; // Capacidade inicial
  l->nroElem = 0;
  l->A = (REGISTRO*)malloc(l->capacidade * sizeof(REGISTRO)); // Primeira alocação
}

int tamanhoEmBytes(LISTA* l) {
  return sizeof(LISTA) + (l->capacidade * sizeof(REGISTRO)); // Agora o retorno depende do tamanho dinâmico
}

void reinicializarLista(LISTA* l) {
  free(l->A); // Libera a memória
  inicializarLista(l); // Recria a lista com capacidade inicial
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  // Redimensiona para o dobro da capacidade se estiver cheia
  if (l->nroElem >= l->capacidade) {
    resize(l, l->capacidade * 2); 
  }
  int pos = l->nroElem;
  while (pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  // Se o número de elementos cair para 25% da capacidade, reduz a capacidade
  if (l->nroElem <= l->capacidade / 4) {
    resize(l, l->capacidade / 2);
  }
  return true;
}

// Abaixo, os métodos seguem iguais


/* Exibição da lista sequencial */
void exibirLista(LISTA* l){
  int i;
  printf("Lista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave);
  printf("\"\n");
} /* exibirLista */ 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  return l->nroElem;
} /* tamanho */

/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE primeiroElem(LISTA* l){
  if(l->nroElem > 0) return l->A[0].chave;
  else return ERRO; // lista vazia
} /* primeiroElem */

/* Retornar a chave do ultimo elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE ultimoElem(LISTA* l) {
  if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
  else return ERRO; // lista vazia
} /* ultimoElem */

/* Retornar a chave do elemento que está na posição n da LISTA. Lembre-se que as posicoes do
   arranjo A vao de 0 a l->capacidade-1  */
TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} /* enesimoElem */

/* Busca sequencial em lista ordenada ou não SEM SENTINELA */
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroElem){
    if(ch == l->A[i].chave) return i; // achou
    else i++;
  }
  return ERRO; // não achou
} /* buscaSequencial */

/* Busca sequencial em lista COM SENTINELA (vetor criado com l->capacidade+1 posições) */
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave != ch) i++;
  if (i > l->nroElem -1) return ERRO; // não achou
  else return i;
} /* buscaSentinela */

/* Busca sequencial em lista COM SENTINELA (vetor criado com l->capacidade+1 posições) 
   considerando o arranjo ordenado */
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave < ch) i++;
  if (i == l->nroElem || l->A[i].chave != ch) return ERRO; // não achou
  else return i;
} /* buscaSentinela */

/* Busca binaria em lista ordenada */
int buscaBinaria(LISTA* l, TIPOCHAVE ch){
  int esq, dir, meio;
  esq = 0;
  dir = l->nroElem-1;
  while(esq <= dir) {
    meio = ((esq + dir) / 2);
    if(l->A[meio].chave == ch) return meio; // achou
    else {
      if(l->A[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return ERRO;
} /* buscaBinaria */


/* Exclusão do elemento cuja chave seja igual a ch */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos == ERRO) return false; // não existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemLista */


/* Exclusão do elemento cuja chave seja igual a ch em lista ordenada*/
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaBinaria(l,ch);
  if(pos == ERRO) return false; // não existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemListaOrd */


// bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
//   if(l->nroElem >= l->capacidade) return false; // lista cheia
//   int pos = l->nroElem;
//   while(pos > 0 && l->A[pos-1].chave > reg.chave) {
//     l->A[pos] = l->A[pos-1];
//     pos--;
//   }
//   l->A[pos] = reg;
//   l->nroElem++;
//   return true;
// } /* inserirElemListaOrd */

/* Inserção em lista ordenada usando busca binária sem duplicação */
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= l->capacidade) return false; // lista cheia
  int pos;
  pos = buscaBinaria(l,reg.chave);
  if(pos != ERRO) return false; // elemento já existe
  pos = l->nroElem-1;
  while(pos>0 && l->A[pos].chave > reg.chave) {
    l->A[pos+1] = l->A[pos];
    pos--;
  }
  l->A[pos+1] = reg;
  l->nroElem++;
  return true;
} /* inserirElemListaOrd */
