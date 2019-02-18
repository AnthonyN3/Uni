package com.trace;

class C_2
{
        private A_2[] a;
        public C_2()
        {
                a = new A_2[2];
                a[0] = new A_2();
                a[1] = new A_2(3);
        }

        public String toString()
        {
                return java.util.Arrays.toString(a); // format: [n1, n2]
        }

        public static void main(String args[])
        {
        		C_2 c= new C_2();
                System.out.println(c);
        }
}