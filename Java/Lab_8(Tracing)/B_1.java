package com.trace;

public class B_1 extends A_1 {
    public int b;
    public B_1(){
            super(0);
            b=0;
    }
    public B_1(int b){
            this();
            a+=b;
    }
    public String toString(){
            a++;
            b+=a;
            return super.toString() + "b:"+b;
    }
}
