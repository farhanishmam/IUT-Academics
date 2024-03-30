/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab01_1a_180041120;
import java.util.Scanner;

public class Lab01_1A 
{
    static boolean check_palin (String str)
    {
        str = str.toLowerCase();
        String reverse = "";
        for (int i = str.length() - 1 ; i >= 0 ; i--)
        {
            reverse = reverse + str.charAt(i);
        }
        if(str.equals(reverse)) return true;
        else return false;
    }
    static String putaster(String str)
    {
        String str_out = "";
        for(int i=0;i<str.length();i++)
        {
            if(i%2==0)
            {
                str_out = str_out + str.charAt(i);
            }
            else 
            {
                str_out = str_out + str.charAt(i) + '*';
            }
        }
        return str_out;
    }
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        if(check_palin(str))
        {
            System.out.println("It is a palindrome.");
        }
        else System.out.println("It is NOT a palindrome.");
        System.out.println(putaster(str));
    }
}