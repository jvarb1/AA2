import java.util.Scanner;

public class ProgramaEstudante {
  
  public static void main(String[]args){
    Scanner scanner = newScanner (System.in)
    Estudante estudante = null;

    while (true){
      System.out.println("escolha a opção desejada:");
      System.out.println("1-matricular estudante");
      System.out.println("2-calcular média");
      System.out.println("3-pesquisar matricula");
      System.out.println("4-pesquisar endereço");
      System.out.println("0-sair");

      int opcao=scanner.nextInt();
      scanner.next.Line();

      switch (opcao){
        case 1:
         System.out.println("Digite o nome do estudante:");
         String nome = scanner.next.Line();
         System.out.println("Digite a matricula do estudante:");
         String matricula = scanner.next.Line();
         System.out.println("Digite o endereço do estudante:");
         String endereco = scanner.next.Line();
         estudante = new Estudante(nome, matricula, endereco);
         System.out.println("Estudante matriculado!");
         break;

        case 2:
          if (estudante !=null){
            System.out.println("A média do estudante é:" + 
            estudante.calcularMedia()); 
            if (estudante.calcularMedia()>=6.0){
              System.out.println("aprovado!");
            }else{
              System.out.println("reprovado!");
            }else{
            System.out.println("criar estudante primeiro");
            }
          break;
          }

      case 3:
        if(estudante !=null){
        System.out.println("n° da matrícula: "+estudante.getMatricula());
        }else{
        System.out.println("Crie um novo estudante!");
        }
        break;

      case 4:
        if(estudante !=null){
        System.out.println("endereço: "+endereco.getEndereco());
        }else{
        
        }
         
      }
    }
  }
}