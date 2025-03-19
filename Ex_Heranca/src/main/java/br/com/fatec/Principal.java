/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package br.com.fatec;

import java.util.Scanner;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Principal {
    
    public static Medicamento criarMed() {
        Scanner sc = new Scanner(System.in);
        String desc, princAtivo;
        boolean tarja;
        float preco;
        int cod;
        
        System.out.print("Medicamento:\n- Descricao: ");
        desc = sc.nextLine();
        System.out.print("- Principal Ativo: ");
        princAtivo = sc.nextLine();
        System.out.print("- Preco: ");
        preco = sc.nextFloat();
        System.out.print("- Tarja Preta: ");
        tarja = sc.nextBoolean();
        System.out.print("- Codigo: ");
        cod = sc.nextInt();
        Medicamento med = new Medicamento(desc, preco, princAtivo, tarja);
        med.setCodigo(cod);
        
        return med;
    }
            
    public static Higiene criarHig() {
        Scanner sc = new Scanner(System.in);
        String desc, uso;
        float prec;
        int cod;
        
        System.out.print("Higiene:\n- Descricao: ");
        desc = sc.nextLine();
        System.out.print("- Uso: ");
        uso = sc.nextLine();
        System.out.print("- Preco: ");
        prec = sc.nextFloat();
        System.out.print("- Codigo: ");
        cod = sc.nextInt();
        Higiene hig = new Higiene(desc, prec, uso);
        hig.setCodigo(cod);
        
        return hig;
    }
    
    public static void infoMed(Medicamento med) {
        System.out.println("Medicamento:");
        System.out.println("- Codigo: " + med.getCodigo());
        System.out.println("- Descricao: " + med.getDescricao());
        System.out.println("- Preco: " + med.getPreco());
        System.out.println("- Principal Ativo: " + med.getPrincAtivo());
        System.out.println("- Tarja Preta: " + med.isTarjaPreta());
    }
    
    public static void infoHig(Higiene hig) {
        System.out.println("Higiene:");
        System.out.println("- Codigo: " + hig.getCodigo());
        System.out.println("- Descricao: " + hig.getDescricao());
        System.out.println("- Preco: " + hig.getPreco());
        System.out.println("- Uso: " + hig.getUso());
    }
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        
        Produto p1 = new Medicamento("Buscopan", 24.69f, "Dipirona", false);
        p1.setCodigo(0);
        Produto p2 = new Higiene("Escova de Dente", 4.99f, "Dental");
        p2.setCodigo(1);
        
        Produto p3 = criarMed();
        Produto p4 = criarHig();
        
        infoMed((Medicamento)p1);
        infoMed((Medicamento)p3);
        infoHig((Higiene)p2);
        infoHig((Higiene)p4);
        
        
        
    }
}
