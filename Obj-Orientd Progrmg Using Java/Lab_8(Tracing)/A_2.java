package com.trace;

class A_2
{
        private static int c=0;
        private int a=2;

        public A_2()
        {
                a=++c;
                System.out.println("c="+c);
        }

        public A_2(int a)
        {
                this();
                ++this.a;
                System.out.println("a="+a);
        }

        public String toString()
        {
                return "a="+a;
        }
}