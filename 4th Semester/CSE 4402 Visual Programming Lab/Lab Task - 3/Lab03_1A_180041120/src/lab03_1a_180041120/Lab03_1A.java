package lab03_1a_180041120;
import java.util.*;
public class Lab03_1A
{
    public static void main(String[] args)
    {
        Calendar c = new Calendar();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a date in the format MMM-DD-YYYY:");
        String d = sc.nextLine(); //example: input may be given as OCT-13-2020
        c.setDate(d);
        if(c.isValidDate())
        {
            System.out.println("Leap year: " + c.isLeapYear());
            System.out.println("Day: " + c.dayOfWeek()); //Sunday/Monday/...
            System.out.println("Next date: " + c.nextDate());
            System.out.println("Previous date: " + c.previousDate());
        }
        else
        {
            System.out.println("Not a valid date.");
        }
    }
}
    
    
