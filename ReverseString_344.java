/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 344. Reverse String
~ Link      : https://leetcode.com/problems/reverse-string/
*/

import java.util.Scanner;

public class ReverseString_344 {
    public void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }


    public static void main(String[] args)
     {
         Scanner sc = new Scanner(System.in);
         String str = sc.nextLine();
         char[] ch = str.toCharArray();
         ReverseString_344 o = new ReverseString_344();
         o.reverseString(ch);
         System.out.print(ch);
     }
}
