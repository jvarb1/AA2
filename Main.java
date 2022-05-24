import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Main {

  static final int[] NUM_THREADS = { 1, 2, 4, 8, 16, 32 };
  static final int NUM_EXEC = 5;

  public static void main(String[] args) throws InterruptedException {
    Scanner scanner = new Scanner(System.in);

    System.out.print("####Cálculo de π usando threads####\n");
    
    int numTerms = 1000000;

    for (int thread = 0; thread < NUM_THREADS.length; thread++) {
      Result[] results = new Result[NUM_EXEC];
      int numThreads = NUM_THREADS[thread];
      System.out.printf("\n\n #CALCULO DE PI UTILIZANDO %d THREADS# \n\n", numThreads);

      for (int i = 0; i < NUM_EXEC; i++) {
        long start = System.nanoTime();

        CalcPiThread[] threads = new CalcPiThread[numThreads];
        int numTermsPerThread = numTerms / numThreads;
        int numberOfTermsProcessed = 0;

        for (int j = 0; j < numThreads; j++) {
          threads[j] = new CalcPiThread(numberOfTermsProcessed, numTermsPerThread);
          threads[j].start();
          numberOfTermsProcessed += numTermsPerThread;
        }

        double pi = 0;
        for (int j = 0; j < numThreads; j++) {
          threads[j].join();
          pi += threads[j].getPartialValueOfPi(); 
        }

        double runtime = (double) TimeUnit.NANOSECONDS.toMillis(System.nanoTime() - start);

        results[i] = new Result(pi, runtime);
      }

      double averageRuntime = getAverageRuntime(results);
      double standardDeviation = getStandardDeviation(results, averageRuntime);

      System.out.println("\n##TEMPO DE EXECUÇÃO##:");
      for (int i = 0; i < NUM_EXEC; i++) {
        results[i].showResult();
      }

      System.out.printf("\nmédia do tempo de execução: %.2f ms\n", averageRuntime);
      System.out.printf("\ndesvio padrão do tempo de execução: %.2f ms\n", standardDeviation);
    }
  }

  private static class CalcPiThread extends Thread {
    private double partialPi;
    private int numberOfTermsProcessed;
    private int numberOfTermsToProcess;

    CalcPiThread(int numberOfTermsProcessed, int numTerms) {
      this.numberOfTermsProcessed = numberOfTermsProcessed;
      this.numberOfTermsToProcess = numTerms;
      this.partialPi = 0;
    }

    @Override
    public void run() {
      for (int currentTerm = this.numberOfTermsProcessed; currentTerm < (this.numberOfTermsProcessed
          + this.numberOfTermsToProcess); currentTerm++) {
        partialPi += Math.pow(-1, currentTerm) / (2 * currentTerm + 1);
      }

      partialPi *= 4;
    }

    public double getPartialValueOfPi() {
      return this.partialPi;
    }
  }

  private static double getStandardDeviation(Result[] results, double averageRuntime) {
    double deviation = 0;
    for (Result result : results) {
      double aux = result.getRuntime() - averageRuntime;
      deviation += Math.pow(aux, 2) / results.length;
    }
    return Math.sqrt(deviation);
  }

  private static double getAverageRuntime(Result[] results) {
    double sum = 0;
    for (Result result : results) {
      sum += result.getRuntime();
    }
    return sum / results.length;
  }
}
