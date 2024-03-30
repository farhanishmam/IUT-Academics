package lab03_1a_180041120;


public class Calendar 
{
    int day;
    int month;
    int year;
    public void Calendar()
    {
        day = 1;
        month = 1;
        year = 1970;
    }
    public void setMonth(String month_s)
    {
        //this can also be done using switch but I prefer if-else since I make
        //silly mistakes when using switch
        if(month_s.equals("JAN")) month = 1;
        else if(month_s.equals("FEB")) month = 2;
        else if(month_s.equals( "MAR")) month = 3;
        else if(month_s.equals( "APR")) month = 4;
        else if(month_s.equals( "MAY")) month = 5;
        else if(month_s.equals( "JUN")) month = 6;
        else if(month_s.equals( "JUL")) month = 7;
        else if(month_s.equals( "AUG")) month = 8;
        else if(month_s.equals( "SEP")) month = 9;
        else if(month_s.equals( "OCT")) month = 10;
        else if(month_s.equals( "NOV")) month = 11;
        else if(month_s.equals( "DEC")) month = 12;
        else month = 0;
    }
    public void setDate(String s)
    {
        String month_s = "";
        for(int i=0;i<3;i++)
        {
            month_s += s.charAt(i);
        }
        month_s = month_s.toUpperCase();
        setMonth(month_s);
        
        int d1,d2;
        d1 = s.charAt(4)-'0';
        d2 = s.charAt(5)-'0';
        day = d1*10 + d2;
             
        int y1,y2,y3,y4;
        y1 = s.charAt(7)-'0';
        y2 = s.charAt(8)-'0';
        y3 = s.charAt(9)-'0';
        y4 = s.charAt(10)-'0';
        year = y1*1000+y2*100+y3*10+y4;
    }
    public boolean isValidYear()
    {
        if(year>0 && year<10000) return true;
        else return false;
    }
    public boolean isLeapYear()
    {
        if(year%4!=0) return false;
        else if(year%400==0) return true;
        else if(year%100==0) return false;
        else return true;
    }
    public boolean isValidMonth()
    {
        if(month>0 && month<13) return true;
        else return false;
    }
    public boolean isValidDay()
    {
        int[] monthdays = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(isValidMonth())
        {
            if(day>0 && day<=monthdays[month])
            {
                return true;
            }
            if(isLeapYear() && day>0 && month == 2 && day<=29)
            {
                return true;
            }
        }
        return false;        
    }
    public boolean isValidDate()
    {
        if(isValidDay() && isValidMonth() && isValidYear()) return true;
        else return false;
    }
    public String displayString(int d, int m, int y)
    {
        String output = "";
        String month_s = "";
        if(m==1) month_s = "JAN";
        else if(m==2) month_s = "FEB";
        else if(m==3) month_s = "MAR";
        else if(m==4) month_s = "APR";
        else if(m==5) month_s = "MAY";
        else if(m==6) month_s = "JUN";
        else if(m==7) month_s = "JUL";
        else if(m==8) month_s = "AUG";
        else if(m==9) month_s = "SEP";
        else if(m==10) month_s = "OCT";
        else if(m==11) month_s = "NOV";
        else if(m==12) month_s = "DEC";
        output += month_s;
        output += "-";
        output += Integer.toString(d);
        output += "-";
        output += Integer.toString(y);
        return output;
    }
    public String nextDate()
    {
        int[] monthdays = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int[] leapdays = {0,31,29,31,30,31,30,31,31,30,31,30,31};
        int d,m,y;
        y = year;
        if((day+1>monthdays[month])||(isLeapYear()&&(day+1>leapdays[month])))
        {
            m = month + 1;
            if(month + 1>12)
            {
                m = 1;
                y++;
            }
            d = 1;
        }
        else
        {
            m = month;
            d = day + 1;
        }
        return displayString(d,m,y);
    }
    public String previousDate()
    {
        int[] monthdays = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int[] leapdays = {0,31,29,31,30,31,30,31,31,30,31,30,31};
        int d,m,y;
        if(day == 1 && month == 1)
        {
           d = 31;
           m = 12;
           y = year - 1;            
        }
        else if(day==1)
        {
            if(isLeapYear())
            {
                y = year;
                m = month-1;
                d = leapdays[m];
            }
            else 
            {
                y = year;
                m = month-1;
                d = monthdays[m];
            }
        }
        else
        {
            y = year;
            m = month;
            d = day-1;
        }
        return displayString(d,m,y);
        
    }
    public String dayOfWeek()
    {
        //we use Zellar's Rule
        int D, m, k, C;
        
        k = day;
        //month is counter from March i.e. March = 1
        m = month - 2;
        if(m==0) m = 12;
        else if(m==-1) m = 11;
        D = year%100;
        if(m==11 || m==12)
        {
            D--;
            if(D<0) D = 99;
        }
        C = year/100;
        int f = k + ((13*m-1)/5) + D + (D/4) + (C/4) - 2*C;
        f= f%7;
        if(f<0) f = f+7;
        if(f==0) return "Sunday";
        else if(f==1) return "Monday";
        else if(f==2) return "Tuesday";
        else if(f==3) return "Wednesday";
        else if(f==4) return "Thursday";
        else if(f==5) return "Friday";
        else if(f==6) return "Saturday";
        else return "";    
    }
    
}
