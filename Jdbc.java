import java.sql.*;
class Jdbc
{
    public static void main(String arg[]) throws Exception
    {
        Connection con=null;
        Statement stmt=null;
        ResultSet rs=null;

       try
       {
           Class.forName("com.mysql.jdbc.Driver");
           System.out.println("Class loaded SUCCESSFULLY..");

            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/Demo?serverTimezone=UTC","root","");
           System.out.println("CONNECTION ESTABLISHED ...");

            stmt = con.createStatement();
           System.out.println("Statement object created SUCCESSFULLY..");

            rs = stmt.executeQuery("select *from Subject where marks<65");
           System.out.println("Query executed SUCCESSFULLY..");

           System.out.println("Data from Subject table");
           while(rs.next())
           {
            System.out.println(rs.getInt(1));
            System.out.println(rs.getString(2));
            System.out.println(rs.getInt(3));
           }
        }
       catch(Exception e)
       {
             System.out.println("Exception occurred !!!");
               System.out.println(e);
                // System.out.println(e.printlnStackTrace());
       }
       finally
       {
           rs.close();
           stmt.close();
           con.close();
           System.out.println("Finally block executed.");
       }
    }
}