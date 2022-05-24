public class Calc {
  private double pi;
  private double runtime;

  Calc(double pi, double runtime) {
    this.pi = pi;
    this.runtime = runtime;
  }

  public double getPi() {
    return this.pi;
  }

  public double getRuntime() {
    return this.runtime;
  }

  public void showCalc() {
    System.out.println(this.pi + " - " + this.runtime + " ms");
  }
}
