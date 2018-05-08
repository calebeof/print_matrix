public class Controle implements Controlador{
  private int volume;
  private boolean ligado;
  private boolean tocando;
  
  //Métodos Especiais
  public Controle(){ //CONSTRUTOR
    this.volume = 50;
    this.ligado = false;
    this.tocando = false;
  }
  private int getVolume(){
    return this.volume;
  }
  private int setVolume(int V){
    return this.volume = V;
  }
  private boolean isLigado(){
    return this.ligado;
  }
  private boolean setLigado(boolean L){
    return this.ligado = L;
  }
  private boolean isTocando(){
    return this.tocando;
  }
  private boolean setTocando (boolean T){
    return this.tocando = T;
  }
  //Métodos Abstratos
  @Override
  public void ligar(){
    this.setLigado(true);
  }
  @Override 
  public void desligar(){
    this.setLigado(false);
  }
  @Override
  public void abrirMenu(){
    if(this.isLigado()){
      System.out.println("-------MENU-------");
      System.out.println("Está ligado? "+this.isLigado());
      System.out.println("Está tocando? "+ this.isTocando());
      System.out.println("Volume: " + this.getVolume());
      for (int i=0; i<=this.getVolume(); i+=10){
        System.out.print("|");
      }
      System.out.println("");
    }else{
      System.out.println("Impossível abrir menu");
    }
}
  @Override
  public void fecharMenu(){
    System.out.println("Fechando o menu...");
  }
  @Override
  public void maisVolume(){
    if (this.isLigado()){
      this.setVolume(this.getVolume()+1);
    }else{
      System.out.println("Impossível aumentar volume");
    }
  }
  @Override
  public void menosVolume(){
    if (this.isLigado()){
      this.setVolume(this.getVolume()-1);
    }else{
      System.out.println("Impossível diminuir volume");
    }
  }
  @Override
  public void ligarMudo(){
    if (this.isLigado() && this.getVolume()>0){
      this.setVolume(0);
    }else{
      System.out.println("Impossível mutar");
    }
  }
  @Override
  public void desligarMudo(){
    if (this.isLigado() && this.getVolume()==0){
      this.setVolume(50);
    }else{
      System.out.println("Impossível desligar o mudo");
    }
  }
  @Override
  public void play(){
    if (this.isLigado() && !this.isTocando()){
      this.setTocando(true);
    }else{
      System.out.println("Impossível executar");
    }
  }
  @Override
  public void pause(){
    if (this.isLigado() && this.isTocando()){
      this.setTocando(false);
    }else{
      System.out.println("Impossível pausar");
    }
  }
}