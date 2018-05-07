class Caneta{
  public String modelo;
  public String cor;
  private double ponta;
  protected int carga;
  private boolean tampado;
  
  public void status (){
    System.out.println("Modelo = " + this.modelo);
    System.out.println("Cor = " + this.cor);
    System.out.println("Ponta = "+this.ponta);
    System.out.println("Carga = "+this.carga);
    System.out.println("Tampado = "+this.tampado);
  }
  
  public void rabiscar(){
    if (!this.tampado)
      System.out.println("ERRO!");
    else
      System.out.println("rabiscaro");
  }
  
  public void tampar (){
    this.tampado = true;
  }
  
  public void destampar (){
    this.tampado = false;
  }
}