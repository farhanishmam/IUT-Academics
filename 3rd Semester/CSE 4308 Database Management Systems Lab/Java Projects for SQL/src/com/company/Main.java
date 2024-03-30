package com.company;
import java.sql.*;

public class Main {

    public static void main ( String [] args )
    {
        String username = "system";
        String password = "aply3737";
        String url = "jdbc:oracle:thin:@localhost:1521/farhan";
        String[] sqlQuery= new String[4];
        sqlQuery[0] = "SELECT COUNT(DISTINCT(A_ID))AS \"Total Number of Accounts\" FROM TRANSACTIONS";
        sqlQuery[1] = "SELECT COUNT(DEB.A_ID) AS \"Total CIP\" FROM" +
                "(SELECT A_ID,SUM(AMOUNT) AS DEBIT FROM TRANSACTIONS WHERE Type = 0 GROUP BY A_ID) DEB, " +
                "(SELECT A_ID,SUM(AMOUNT) AS CREDIT FROM TRANSACTIONS WHERE Type = 1 GROUP BY A_ID) CRED " +
                "WHERE (DEB.A_ID = CRED.A_ID) AND (DEB.DEBIT - CRED.CREDIT>1000000) AND (DEB.DEBIT + CRED.CREDIT>5000000)";

        sqlQuery[2] = "SELECT COUNT(DEB.A_ID) AS \"Total VIP\" FROM " +
                "(SELECT A_ID,SUM(AMOUNT) AS DEBIT FROM TRANSACTIONS WHERE Type = 0 GROUP BY A_ID) DEB, " +
                "(SELECT A_ID,SUM(AMOUNT) AS CREDIT FROM TRANSACTIONS WHERE Type = 1 GROUP BY A_ID) CRED " +
                "WHERE (DEB.A_ID = CRED.A_ID) AND (DEB.DEBIT - CRED.CREDIT BETWEEN 500000 AND 900000) " +
                "AND (DEB.DEBIT + CRED.CREDIT BETWEEN 3500000 AND 4500000)";
        sqlQuery[3] = "SELECT COUNT(DEB.A_ID) AS \"Total Ordinary Persons\" FROM" +
                "(SELECT A_ID,SUM(AMOUNT) AS DEBIT FROM TRANSACTIONS WHERE Type = 0 GROUP BY A_ID) DEB," +
                "(SELECT A_ID,SUM(AMOUNT) AS CREDIT FROM TRANSACTIONS WHERE Type = 1 GROUP BY A_ID) CRED " +
                "WHERE (DEB.A_ID = CRED.A_ID) AND (DEB.DEBIT - CRED.CREDIT<40000) AND (DEB.DEBIT + CRED.CREDIT <3000000)";
        //Declaring variables
        int total; //Stores Total Number of Accounts
        int total_cip; //Stores Total Number of CIP
        int total_vip; //Stores Total Number of VIP
        int total_ordinary; //Stores Total Number of Ordinary Person
        try
        {

            Class.forName("oracle.jdbc.driver.OracleDriver");
            Connection con = DriverManager.getConnection(url, username, password);
            Statement statement = con.createStatement();
            System.out.println("Connection to database successful");
            ResultSet result = statement.executeQuery("SELECT *FROM transactions");
            ResultSetMetaData result_meta = result.getMetaData();
            while(result.next())
            {
                if(result.getInt(1)==11) break;
                System.out.println(result_meta.getColumnTypeName(1)+":"+result.getInt(1)+" "+result.getInt("A_ID"));
            }


            /*
            ResultSet result = statement.executeQuery(sqlQuery[0]); //Executes an sql query from the query array
            result.next();
            total =result.getInt (1); //1 is the column index of each result class
            System.out.println ("Total Number of Accounts: " + total);

            result = statement.executeQuery(sqlQuery[1]);
            result.next();
            total_cip = result.getInt (1); //1 is the column index of each result class
            System.out.println ("CIP count: " + total_cip);

            result = statement.executeQuery(sqlQuery[2]);
            result.next();
            total_vip = result.getInt (1); //1 is the column index of each result class
            System.out.println ("VIP count: " + total_vip);

            result = statement.executeQuery(sqlQuery[3]);
            result.next();
            total_ordinary = result.getInt (1); //1 is the column index of each result class
            System.out.println ("Ordinary count: " + total_ordinary);



            //Number of uncatergorized persons can be found by subtracting categorized persons from total no. of persons
            System.out.println ("Uncategorized: " + (total - total_cip - total_vip - total_ordinary) );
            */
            //Close the connection object
            con.close();
            statement.close();
            result.close();
        }
        catch(SQLException e)
        {
            System.out.println(" Error while connecting to database . Exception code : " + e);
        }
        catch(ClassNotFoundException e )
        {
            System.out.println(" Failed to register driver . Exception code : " + e);
        }
    }
}
