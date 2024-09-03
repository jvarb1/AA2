struct placa{
  char letras[4];
  char codigo[5];
};

typedef struct placa Placa;

Placa* criarPlaca(char letra[4], char codigo[5]);

void imprimirPlaca(Placa *plc);  


void destruirPlaca(Placa *plc);

Placa* atualizarPlaca(Placa *plc, char letra[4], char codigo[5]); 