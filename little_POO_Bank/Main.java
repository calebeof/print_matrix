class Main {
  public static void main(String[] args) {
    Bank o1 = new Bank();
    o1.constructor();
    //o1.status();
    o1.abrirConta("CP");
    o1.status();
    o1.depositar(150);
    o1.depositar(130);
    o1.status();
  }
}