/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.fatec;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Medicamento extends Produto {
    private String princAtivo;
    private boolean tarjaPreta;
    
    public Medicamento(String descricao, float preco) {
        super(descricao, preco);
    }
    
    public Medicamento(String descricao, float preco, String princAtivo, boolean tarjaPreta) {
        this(descricao, preco);
        this.princAtivo = princAtivo;
        this.tarjaPreta = tarjaPreta;
    }
    
    public void aumento(float valor) {
        super.setPreco((super.getPreco() + valor) * 1.1f);
    }

    public String getPrincAtivo() {
        return princAtivo;
    }

    public void setPrincAtivo(String princAtivo) {
        this.princAtivo = princAtivo;
    }

    public boolean isTarjaPreta() {
        return tarjaPreta;
    }

    public void setTarjaPreta(boolean tarjaPreta) {
        this.tarjaPreta = tarjaPreta;
    }
    
}
