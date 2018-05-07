class Main {
  public static void main(String[] args) {
    Caneta o1 = new Caneta();
    //o1.setModelo("FABER");
    //o1.setPonta(12);
    o1.construct("FABER", 12, "AZUL", true);
    //o1.getPonta();
    o1.status();
  }
}