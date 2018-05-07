class Main {
  public static void main(String[] args) {
    Caneta o1 = new Caneta();
    o1.modelo = "FABER";
    o1.status();
    
    o1.cor = "AZUL";
    o1.status();
    
    //o1.ponta = 0.5; ERRO: ponta é privada
    o1.carga = 90; //PROTEGIDA, só que dá pra usar
    //o1.tampado = true; ERRO: tampado é privado
    o1.status();
    
    o1.tampar(); //CONSIGO TROCAR O STATUS DE tampado PELO MÉTODO, JÁ QUE ELE É PRIVADO E SÓ PODE SER MODIFICADO POR MÉTODOS DA CLASSE
    o1.rabiscar();
    o1.status();
  }
}