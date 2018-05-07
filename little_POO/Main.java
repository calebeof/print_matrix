class Main {
  public static void main (String[] args){
    Caneta o1 = new Caneta();
    o1.modelo = "BIC";
    o1.cor = "VERDE";
    o1.ponta = 0.7;
    o1.carga = 100;
    o1.rabiscar();
    o1.tampar();
    o1.rabiscar();
    o1.status();
    
    Caneta o2 = new Caneta();
    o2.modelo = "FABER";
    o2.cor = "AZUL";
    o2.ponta = 0.5;
    o2.carga = 56;
    o2.destampar();
    o2.status();
  }
}