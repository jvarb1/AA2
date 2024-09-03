#include "placa.h"

struct veiculo {
  Placa placa;
  char ano[5];
  char fabricante[]; 
  
};  

typedef struct veiculo Veiculo;

veiculo* criarVeiculo(Placa placa, char ano[5], char fabricante[]);



void imprimirVeiculo(Veiculo *vhc);

veiculo* atualizarVeiculo(Veiculo *vhc, Placa placa, char ano[5], char fabricante[]);