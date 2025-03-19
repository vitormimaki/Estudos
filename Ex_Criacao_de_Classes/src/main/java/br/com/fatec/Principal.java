/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package br.com.fatec;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Principal {

    public static void main(String[] args) {
        Carro c1 = new Carro();
        
        c1.setProprietario("Mimaki");
        c1.setAno_modelo(2024);
        c1.setValor(45250.0f);
        c1.setMarchaAtual(1);
        c1.setVelocidadeAtual(34);
        c1.setLigado(true);
        
        System.out.println(c1.status());
        
        c1.acelerar();
        c1.ligarDesligar();
        
        System.out.println("--------------------------------------------------");
        System.out.println(c1.status());
        
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.frear();
        c1.ligarDesligar();
        
        System.out.println("--------------------------------------------------");
        System.out.println(c1.status());
    }
}
