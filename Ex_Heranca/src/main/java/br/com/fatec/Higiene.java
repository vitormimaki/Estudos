/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.fatec;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Higiene extends Produto{
    private String uso;

    public Higiene(String descricao, float preco) {
        super(descricao, preco);
    }
    
    public Higiene(String descricao, float preco, String uso) {
        this(descricao, preco);
        this.uso = uso;
    }
    
    public String getUso() {
        return uso;
    }

    public void setUso(String uso) {
        this.uso = uso;
    }
    
}
