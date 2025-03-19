/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.fatec;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Universidade {
    private String sigla;
    private String nome;
    private Instituto instituto;
    
    public Universidade(Instituto instituto) {
        this.instituto = instituto;
    }
    
    public Universidade(Instituto instituto, String nome, String sigla) {
        this.nome = nome;
        this.sigla = sigla;
        this.instituto = instituto;
    }

    public String getSigla() {
        return sigla;
    }

    public void setSigla(String sigla) {
        this.sigla = sigla;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Instituto getInstituto() {
        return instituto;
    }

    public void setInstituto(Instituto instituto) {
        this.instituto = instituto;
    }
}
