#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"

Veiculo* criarVeiculo(Placa placa, char ano[5], char fabricante[]){
  Veiculo *v = (Veiculo*)malloc(sizeof(Veiculo));

  v -> placa = placa; 

  for(int i=0; i<4; i++){
    v -> ano[i] = ano[i];
  }

  (*v).ano[4] = '\0';

  int tamanho = strlen(fabricante);
  for(int i=0; i<tamanho; i++){
    v -> fabricante[i] = fabricante[i];
  }

  (*v).fabricante[tamanho] = '\0';
  return v;
}


void imprimirVeiculo(Veiculo *vc){
  printf("Fabricante do veículo: %s \n", (*vc).fabricante);
  printf("Ano do modelo: %s \n", (*vc).ano);
  printf("Placa: %s-%s \n", (*vc).placa.codigo,   (*vc).placa.letras);
}

Veiculo* atualizarVeiculo(Veiculo *vc, Placa placa, char ano[5], char fabricante[]){
  
  for(int i=0; i<4; i++){
    vc -> ano[i] = ano[i]; 
  }
  
  (*vc).ano[4] = '\0';

  int tamanho = strlen(fabricante);
  for(int i=0; i<tamanho; i++){
    vc -> fabricante[i] = fabricante[i];
  }

  (*vc).fabricante[tamanho] = '\0';

  vc -> placa = placa;

  return vc;
}