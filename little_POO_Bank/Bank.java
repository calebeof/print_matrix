public class Bank {
  public int numConta;
  protected String tipo;
  private String dono; 
  private double saldo;
  private boolean status;
  
  public void status(){
    System.out.println ("Número da conta = "+this.getNumConta());
    System.out.println("Tipo da conta = "+this.getTipo());
    System.out.println("Dono da conta = "+this.getDono());
    System.out.println("Saldo da conta = "+this.getSaldo());
    System.out.println("Status da conta = "+this.getStatus());
  }
  
  public void constructor (int num, String tipo, String dono){
    this.setNumConta(num);
    this.setTipo(tipo);
    this.setDono(dono);
    this.setSaldo(0);
    this.setStatus(false);
  }
  
  public void abrirConta(String tipo){
    setStatus(!this.getStatus());
    setTipo(tipo);
    if (this.getTipo()=="CC")
      setSaldo(50);
    else
      setSaldo(150);
  }
  
  public void fecharConta(){
    if (getSaldo()!=0){
      System.out.println("Você não pode fechar a conta!");
    }else{
      System.out.println("Conta fechada!");
      setStatus(false);
    }
  }
  
  public void depositar (double dinheiro){
    if (this.getStatus()){
      setSaldo(this.getSaldo()+dinheiro);
    }else{
      System.out.println("Sua conta não está aberta!");
    }
  }
  
  public void sacar (double dinheiro){
    if (this.getStatus()==true && this.getSaldo()>0){
      setSaldo(this.getSaldo()-dinheiro);
    }else{
      if (!this.getStatus())
        System.out.println("Sua conta não está aberta!");
      if (this.getSaldo()<=0)
        System.out.println("Seu saldo não é positivo!");
    }
  }
  
  public void pagarMensal(){
    if (this.getStatus){
      if (this.getTipo()=="CC"){
        setSaldo(this.getSaldo()-12);
      }else{
        setSaldo(this.getSaldo()-20);
      }
    }else{
      System.out.println("Impossível cobrar!");
    }
  }
  
  public int getNumConta(){
    return this.numConta;
  }
  public int setNumConta(int N){
    return this.numConta = N;
  }
  public String getTipo(){
    return this.tipo;
  }
  public String setTipo(String T){
    return this.tipo = T;
  }
  public String getDono (){
    return this.dono;
  }
  public String setDono(String D){
    return this.dono = D;
  }
  public double getSaldo(){
    return this.saldo;
  }
  public double setSaldo(double S){
    return this.saldo = S;
  }
  public boolean getStatus (){
    return this.status;
  }
  public boolean setStatus(boolean S){
    return this.status = S;
  }
}