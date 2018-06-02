import javax.xml.bind.SchemaOutputResolver;

public class Lutador {
    private String nome;
    private String pais;
    private int idade;
    private double altura;
    private double peso;
    private String categoria;
    private int vitorias;
    private int derrotas;
    private int empates;

    public Lutador(String nome, String pais, int idade, double altura, double peso, int vitorias, int derrotas, int empates) {
        this.setNome(nome);
        this.setPais(pais);
        this.setIdade(idade);
        this.setAltura(altura);
        this.setPeso(peso);
        this.setVitorias(vitorias);
        this.setDerrotas(derrotas);
        this.setEmpates(empates);
    }
    public void ganharLuta(){
        this.setVitorias(getVitorias()+1);
    }
    public void perderLuta(){
        this.setDerrotas(getDerrotas()+1);
    }
    public void empatarLuta(){
        this.setEmpates(getEmpates()+1);
    }
    public void apresentar(){
        System.out.println("Lutador = " + this.getNome());
        System.out.println("Origem = " + this.getPais());
        System.out.println(this.getIdade() + " anos");
        System.out.println(this.getAltura() + " metros de altura");
        System.out.println("Pesando " + this.getPeso());
        System.out.println("Ganhou: " + this.getVitorias());
        System.out.println("Perdeu: " + this.getPeso());
        System.out.println("Empatou: " + this.getEmpates());
    }

    public String getNome() {
        return nome;
    }

    private void setNome(String nome) {
        this.nome = nome;
    }

    public String getPais() {
        return pais;
    }

    private void setPais(String pais) {
        this.pais = pais;
    }

    public int getIdade() {
        return idade;
    }

    private void setIdade(int idade) {
        this.idade = idade;
    }

    public double getAltura() {
        return altura;
    }

    private void setAltura(double altura) {
        this.altura = altura;
    }

    public double getPeso() {
        return peso;
    }

    private void setPeso(double peso) {
        this.peso = peso;
        this.setCategoria();
    }

    public String getCategoria() {
        return categoria;
    }

    private void setCategoria() {
        if (this.peso<52.2)
            this.categoria = "Inválido";
        else if (this.peso<=70.3)
            this.categoria = "Leve";
        else if (this.peso<=83.9)
            this.categoria = "Médio";
        else if (this.peso<=120.2)
            this.categoria = "Pesado";
        else
            this.categoria = "Inválido";
    }

    public int getVitorias() {
        return vitorias;
    }

    private void setVitorias(int vitorias) {
        this.vitorias = vitorias;
    }

    public int getDerrotas() {
        return derrotas;
    }

    private void setDerrotas(int derrotas) {
        this.derrotas = derrotas;
    }

    public int getEmpates() {
        return empates;
    }

    private void setEmpates(int empates) {
        this.empates = empates;
    }
}
