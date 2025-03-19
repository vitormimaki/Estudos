/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.fatec;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Carro {
    private String proprietario;
    private int ano_modelo;
    private float valor;
    private int marchaAtual;
    private int velocidadeAtual;
    private boolean ligado;

    
    public String getProprietario() {
        return proprietario;
    }

    public void setProprietario(String proprietario) {
        this.proprietario = proprietario;
    }

    public int getAno_modelo() {
        return ano_modelo;
    }

    public void setAno_modelo(int ano_modelo) {
        this.ano_modelo = ano_modelo;
    }

    public float getValor() {
        return valor;
    }

    public void setValor(float valor) {
        this.valor = valor;
    }

    public int getMarchaAtual() {
        return marchaAtual;
    }

    public void setMarchaAtual(int marchaAtual) {
        this.marchaAtual = marchaAtual;
    }

    public int getVelocidadeAtual() {
        return velocidadeAtual;
    }

    public void setVelocidadeAtual(int velocidadeAtual) {
        this.velocidadeAtual = velocidadeAtual;
    }

    public boolean isLigado() {
        return ligado;
    }

    public void setLigado(boolean ligado) {
        this.ligado = ligado;
    }
    
    
    
    public void ligarDesligar(){
        ligado = !ligado;
    }
    public int acelerar(){
        if((velocidadeAtual + 5) >= 100) {
            velocidadeAtual = 100;
        } else {
            velocidadeAtual += 5;
        }
        return velocidadeAtual;
    }
    public int frear(){
        if((velocidadeAtual - 5) <= 0) {
            velocidadeAtual = 0;
        } else {
            velocidadeAtual -= 5;
        }
        return velocidadeAtual;
    }
    public String status(){
        //String info = "Status:\n";
        
        //info += "Proprietario: " + proprietario;
        //info += "\nAno do Modelo: " + ano_modelo;
        //info += "\nValor: " + valor;
        //info += "\nMarcha Atual: " + marchaAtual;
        //info += "\nVelocidade Atual: " + velocidadeAtual;
        //info += "\nLigado: " + ligado;
        //return info;
        
        StringBuilder texto = new StringBuilder();
        
        texto.append("Status:\n");
        texto.append("Proprietario: " + proprietario);
        texto.append("\nAno do Modelo: " + ano_modelo);
        texto.append("\nValor: " + valor);
        texto.append("\nMarcha Atual: " + marchaAtual);
        texto.append("\nVelocidade Atual: " + velocidadeAtual);
        texto.append("\nLigado: " + ligado);
        return texto.toString();
    }
}
