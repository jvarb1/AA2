public class Estudante{
  private String nome;
  private String matricula;
  private String endereco;
  private double nota1;
  private double nota2;
  private double nota3;
  private double nota4;

public Estudante(String nome, String matricula, String endereco){
  this.nome=nome;
  this.matricula=matricula;
  this.endereco=endereco;
  this.nota1=0.0;
  this.nota2=0.0;
  this.nota3=0.0;
  this.nota4=0.0;
}

public String getNome(){
  return nome;
}
public void setNome(String novoNome){
  nome=novoNome;
}
public double getNota1(){
  return nota1;
}
public void setNota1 (double novaNota){
  nota1=novaNota;
}
public double getNota2(){
  return nota2;
}
public void setNota2 (double novaNota){
  nota2=novaNota;
}
public double getNota3(){
  return nota3;
}
public void setNota3 (double novaNota){
  nota3=novaNota;
}
public double getNota4(){
  return nota4;
}
public void setNota4 (double novaNota){
  nota4=novaNota;
}

public double CalcularMedia(){
  return (nota1+nota2+nota3+nota4)/4;
}

public string getMatricula(){
  return matricula;
}

public string getEndereco(){
  return endereco;
}
}