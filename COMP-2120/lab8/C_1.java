package com.trace;

public class C_1 {
    public static void main(String[] args) {
            B_1 b[] = new B_1[3];
            b[0] = new B_1();
            b[1] = new B_1(4);
            A_1 a = new B_1(5);
            b[2] = (B_1)(a);        
            
            System.out.println(b[0].b);
            b[1].b = b[0].b + 5 * b[2].b;

                    System.out.println(b[0]+"\n"+b[1]);
                    System.out.println(b[2]+"\n"+a);
    }
}