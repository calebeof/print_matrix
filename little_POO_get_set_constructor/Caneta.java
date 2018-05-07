class Caneta {
  private String modelo;
  private double ponta;
  private String cor;
  private boolean tampado;
  
  public void construct(String modelo, double ponta, String cor, boolean tampado){
    this.setModelo(modelo);
    this.setPonta(ponta);
    this.setCor(cor);
    this.setTampado(tampado);
  }
  public void status (){
    System.out.println("INFORMAÇÕES: ");
    System.out.println("Modelo = "+this.getModelo());
    System.out.println("Ponta = "+this.getPonta());
    System.out.println("Cor = "+this.getCor());
    System.out.println("Tampado = "+this.getTampado());
  }
  public String getModelo (){
    return this.modelo;
  }
  public String setModelo(String M){
    return this.modelo = M;
  }
  public double getPonta(){
    return this.ponta;
  }
  public double setPonta(double P){
    return this.ponta = P;
  }
  public String getCor(){
    return this.cor;
  }
  public String setCor(String C){
    return this.cor = C;
  }
  public boolean getTampado(){
    return this.tampado;
  }
  public boolean setTampado(boolean T){
    return this.tampado = T;
  }
}