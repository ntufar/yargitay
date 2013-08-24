import java.sql.*;
import java.math.*;
import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;


/**
 * This is a simple example of an HTTP Servlet.  It responds to the GET
 * and HEAD methods of the HTTP protocol.
 */
public class EmsalKanun extends HttpServlet
{ 
    /**
     * Handle the GET and HEAD methods by building a simple web page.
     * HEAD is just like GET, except that the server returns only the
     * headers (including content length) not the body we write.
     */
	static boolean initialized = false;
	static boolean erroroninit = false;
	SQLWarning warning;
        Connection conn = null;
	CallableStatement hitcount;

	daireler_t dairelist = new daireler_t();



	public void init(ServletConfig config) throws ServletException {
		Statement stmt = null;

		if(initialized == true){
			return;
		}else{
			initialized = true;
		}
		super.init(config);
		//log("abracadabra \t");
		try{
			DriverManager.registerDriver(new oracle.jdbc.driver.OracleDriver());
			Properties prop = new Properties();
			prop.put("charSet","iso-8859-9");
			if(conn == null){
               		 conn = DriverManager.getConnection ("jdbc:oracle:oci8:@y1",
                		"sorgu","sorgu");

			stmt = conn.createStatement ();
			stmt.executeUpdate("alter session set NLS_LANGUAGE=turkish");
			stmt.executeUpdate("alter session set NLS_TERRITORY=turkey");
			stmt.close();
			//hitcount.registerOutParameter(2,java.sql.Types.VARCHAR); 
			}
			 } catch (SQLException e){
            			erroroninit=true;
            			while(e != null) {
                			log("DriverManager.getConnection: SQLException: " + e.getSQLState() + '\t' +
                    			e.getMessage() + '\t' +
                    			e.getErrorCode() + '\t');
                			e = e.getNextException();
            			}
				throw new UnavailableException (this,
					"Baðlatý kurulamadý");
        		} catch (Exception e) {
	    			e.printStackTrace();
			}


/*------------------------------------------------------------------*/
        dairelist.adddaire("1c",   "1. Ceza dairesi");
        dairelist.adddaire("2c",   "2. Ceza dairesi");
        dairelist.adddaire("3c",   "3. Ceza dairesi");
        dairelist.adddaire("4c",   "4. Ceza dairesi");
        dairelist.adddaire("5c",   "5. Ceza dairesi");
        dairelist.adddaire("6c",   "6. Ceza dairesi");
        dairelist.adddaire("7c",   "7. Ceza dairesi");
        dairelist.adddaire("8c",   "8. Ceza dairesi");
        dairelist.adddaire("9c",   "9. Ceza dairesi");
        dairelist.adddaire("10c",  "10. Ceza dairesi");
        dairelist.adddaire("11c",  "11. Ceza dairesi");
        dairelist.adddaire("1h",   "1. Hukuk dairesi");
        dairelist.adddaire("2h",   "2. Hukuk dairesi");
        dairelist.adddaire("3h",   "3. Hukuk dairesi");
        dairelist.adddaire("4h",   "4. Hukuk dairesi");
        dairelist.adddaire("5h",   "5. Hukuk dairesi");
        dairelist.adddaire("6h",   "6. Hukuk dairesi");
        dairelist.adddaire("7h",   "7. Hukuk dairesi");
        dairelist.adddaire("8h",   "8. Hukuk dairesi");
        dairelist.adddaire("9h",   "9. Hukuk dairesi");
        dairelist.adddaire("10h",  "10. Hukuk dairesi");
        dairelist.adddaire("11h",  "11. Hukuk dairesi");
        dairelist.adddaire("12h",  "12. Hukuk dairesi");
        dairelist.adddaire("13h",  "13. Hukuk dairesi");
        dairelist.adddaire("14h",  "14. Hukuk dairesi");
        dairelist.adddaire("15h",  "15. Hukuk dairesi");
        dairelist.adddaire("16h",  "16. Hukuk dairesi");
        dairelist.adddaire("17h",  "17. Hukuk dairesi");
        dairelist.adddaire("18h",  "18. Hukuk dairesi");
        dairelist.adddaire("19h",  "19. Hukuk dairesi");
        dairelist.adddaire("20h",  "20. Hukuk dairesi");
        dairelist.adddaire("21h",  "21. Hukuk dairesi");
        dairelist.adddaire("cgk",  "Ceza Genel Kurulu");
        dairelist.adddaire("hgk",  "Hukuk Genel Kurulu");
       	dairelist.adddaire("yik",  "Ýçtihadý Birleþtirme Kurulu");
/*------------------------------------------------------------------*/
	}



    public void destroy() {
	log("Destroying");
        try {
	if(conn != null){
            conn.close();
	}
        } catch (SQLException e) {
            while(e != null) {
		log("destroy.close.all: SQLException: " + e.getSQLState() + '\t' +
		    e.getMessage() + '\t' +
		    e.getErrorCode() + '\t');
		e = e.getNextException();
            }
        } catch (Exception e) {
	    e.printStackTrace();
	}
    }





    public void doGet (HttpServletRequest request,
                       HttpServletResponse response) 
        throws ServletException, IOException
        {
		Statement stmt = null;
		ResultSet rset = null;
		Statement ksstmt = null;
		ResultSet ksrset = null;
		String query = new String(""); 
		String ksquery = new String(""); 
		String adim = "";
		String daire = "";
		String kanun = "";
		String esasno = "";
		String madde = "";
		int i;




		//log(request.getCharacterEncoding());
            PrintWriter out;
            // set content type and other response header fields first
            response.setContentType("text/html");
            // then write the data of the response
		response.setContentType("text/html; charset=iso-8859-9");
            out = response.getWriter();
            out.println("<HTML><HEAD>");
            out.println("<TITLE>Kanun Sorgu Sonucu</TITLE>");
            out.println("</HEAD>");
	out.println("<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-9\">");
	out.println("<BODY bgcolor=\"#FFFFFF\">");
	out.println("<center><a href=\"http://www.yargitay.gov.tr/\">"+
			"<img src=\"http://www.yargitay.gov.tr/images/bas.JPG\""+
			" width=\"298\" height=\"77\"></a>");
            out.println("<h1><font size=\"+3\" color=\"#6699FF\">"+
			"Kanun Sorgu Sonuçlarý</font></h1> </center> <hr>");
            

		if(erroroninit == true){
			out.println("Veritabaný þu an bakýmda. Lütfen sonra deneyin");
		}
		Enumeration values = request.getParameterNames();
		adim = "abracadabra";
		while(values.hasMoreElements()) {
			String name = (String)values.nextElement();
			if(name.compareTo("adim") == 0){
				adim = request.getParameterValues("adim")[0];
			}
			if(name.compareTo("daire") == 0){
				daire = request.getParameterValues("daire")[0];
			}
			if(name.compareTo("kanun") == 0){
				kanun = request.getParameterValues("kanun")[0];
			}
			if(name.compareTo("esasno") == 0){
				esasno = request.getParameterValues("esasno")[0];
			}
			if(name.compareTo("madde") == 0){
				madde = request.getParameterValues("madde")[0];
			}
		}
		if(adim.compareTo("abracadabra") == 0 || adim.compareTo("0") == 0){
			doadim1(out, daire);
		}
		if(adim.compareTo("2") == 0){
			doadim2(out, daire, kanun);
		}
		if(adim.compareTo("3") == 0){
			doadim3(out, daire, madde, kanun);
		}
		if(adim.compareTo("4") == 0){
			doadim4(out, daire, esasno);
		}


            out.println("</BODY></HTML>");
            out.close();
        }

	private void doadim1(PrintWriter out, String daire){
		String query1 = new String(" SELECT kanun, count(kanun), kanunno FROM emsal.kanun WHERE daireno=?"+
			" GROUP BY kanun, kanunno ORDER BY kanun" );
		Statement stmt = null;
		ResultSet rset = null;
		PreparedStatement kavramlar;
		int i;
		String kisadaire = new String("");

		out.println("<FORM method=get ACTION=\"EmsalKanun\">");
		out.println("<SELECT NAME=daire>");
		dairelist.tostart();
		while(!dairelist.isend()){
			if(daire.equals(dairelist.getuzun())){
				out.println("<OPTION selected>" + dairelist.getuzun());
				kisadaire = dairelist.getkisa();
			}
			else out.println("<OPTION>" + dairelist.getuzun());
			dairelist.tonext();
		}
		out.println("</SELECT>");
		out.println("<INPUT TYPE=submit VALUE=Ara>");
		out.println("</FORM>");
		out.println("<strong>Daire:</strong> " + daire);
		try {
			kavramlar = conn.prepareStatement(query1);
			kavramlar.clearParameters();
			kavramlar.setString(1,kisadaire);
			rset = kavramlar.executeQuery();
			out.println("<TABLE>");
			out.println("<TR><TD><strong>Adet</strong></TD><TD>"+
				"<strong>Kanun numarasý</strong></TD><TD><strong>Kanun</strong></TD></TR>");
			while(rset.next()){
				out.println("<TR><TD>" + rset.getString(2) + 
						"</TD><TD>"+rset.getString(3)+
						"</TD><TD><A HREF=\"EmsalKanun?"+
						"adim=2&daire="	+ java.net.URLEncoder.encode(daire) + 
						"&kanun=" + java.net.URLEncoder.encode(rset.getString(1))+"\">" +
						rset.getString(1) + "</TD></TR>");
			}
			out.println("</TABLE>");


		} catch (SQLException e){
            		while(e != null) {
				log("adim1: SQLException: " + e.getSQLState() + '\t' +
		    			e.getMessage() + '\t' +
		    			e.getErrorCode() + '\t');
					e = e.getNextException();
            		}
            			//out.println(e.toString());
        	} catch (Exception e) {
	    		e.printStackTrace();
		}
	}


	private void doadim2(PrintWriter out, String daire, String kanun){
		String query1 = null;
		Statement stmt = null;
		ResultSet rset = null;
		PreparedStatement kavramlar;
		int i;
		String kisadaire = new String("");

		dairelist.tostart();
		while(!dairelist.isend()){
			if(daire.equals(dairelist.getuzun())){
				kisadaire = dairelist.getkisa();
			}
			dairelist.tonext();
		}
		query1 = new String(" SELECT madde, count(madde) FROM emsal.kanun WHERE daireno='"+kisadaire+
			"' AND kanun = '"+kanun+"' GROUP BY madde ORDER BY madde");
		//log(query1);
		out.println("<strong>Daire:</strong> " +  iso1to9(daire)+"<br>");
		out.println("<strong>Kanun:</strong> " +  iso1to9(kanun)+"<br>");
		try {
			kavramlar = conn.prepareStatement(iso1to9(query1));
			//kavramlar.clearParameters();
			//kavramlar.setString(1,kisadaire);
			//kavramlar.setString(2,kanun);
			rset = kavramlar.executeQuery();
			out.println("<TABLE>");
			out.println("<TR><TD><strong>Adet</strong></TD><TD><strong>Madde</strong></TD></TR>");
			while(rset.next()){
				out.println("<TR><TD>" + rset.getString(2) + 
						"</TD><TD><A HREF=\"EmsalKanun?"+
						"adim=3&daire="	+ java.net.URLEncoder.encode(daire) + 
						"&madde=" + java.net.URLEncoder.encode(rset.getString(1)) + 
						"&kanun=" + java.net.URLEncoder.encode(iso1to9(kanun))+"\">" +
						rset.getString(1) + "</TD></TR>");
			}
			out.println("</TABLE>");


		} catch (SQLException e){
            		while(e != null) {
				log("adim1: SQLException: " + e.getSQLState() + '\t' +
		    			e.getMessage() + '\t' +
		    			e.getErrorCode() + '\t');
					e = e.getNextException();
            		}
            			//out.println(e.toString());
        	} catch (Exception e) {
	    		e.printStackTrace();
		}
	}





	private void doadim3(PrintWriter out, String daire, String madde, String kanun){
		String query2 = null;
		String kisadaire = new String("");
		PreparedStatement kavramlar;
		Statement kavramlar2;
		ResultSet rset = null;

		out.println("<strong>Daire:</strong> " + iso1to9(daire) + "<br>");
		out.println("<strong>Kavram:</strong> " + iso1to9(kanun) + " <br>");

		dairelist.tostart();
		while(!dairelist.isend()){
			if(daire.equals(dairelist.getuzun())){
				kisadaire = dairelist.getkisa();
			}
			dairelist.tonext();
		}
		query2 = new String("SELECT  esasno, daireno FROM emsal.kanun WHERE daireno = '"+kisadaire + 
						"' and kanun = '"+kanun+"' and madde = '"+madde+"' ORDER BY daireno");

		try {
			//kavramlar = conn.prepareStatement(iso9to9(query1));
			//kavramlar.clearParameters();
			//kavramlar.setObject(1,kavram.trim()+"%" );
			//log(kavram);
			//log(iso9to9(kavram+"%"));
			//kavramlar.setObject(2,kisadaire.trim() +"%");
			//rset = kavramlar.executeQuery();
			//log("adim3: "+query2);
			kavramlar = conn.prepareStatement(iso1to9(query2));
			rset = kavramlar.executeQuery();
			out.println("<TABLE>");
			out.println("<TR><TD><strong>Daire</strong></TD><TD><strong>Esas sýra numarasý</strong></TD></TR>");

			while(rset.next()){
				out.println("<TR><TD>" + daire + "</TD><TD>" +
					"<A HREF=\"EmsalKanun?adim=4&daire=" + java.net.URLEncoder.encode(daire) +
					"&esasno=" + rset.getString(1) + "\">" + rset.getString(1) + "</A></TD></TR>");
			}
			out.println("</TABLE>");
		} catch (SQLException e){
            		while(e != null) {
				log("adim1: SQLException: " + e.getSQLState() + '\t' +
		    			e.getMessage() + '\t' +
		    			e.getErrorCode() + '\t');
					e = e.getNextException();
            		}
            			//out.println(e.toString());
        	} catch (Exception e) {
	    		e.printStackTrace();
		}
	}


	private void doadim4(PrintWriter out, String daire, String esasno){
		Statement stmt = null;
		ResultSet rset = null;
		String b = new String("");
		String kisadaire = null;

		dairelist.tostart();
		while(!dairelist.isend()){
			if(daire.equals(dairelist.getuzun())){
				kisadaire = dairelist.getkisa();
			}
			dairelist.tonext();
		}
		try{
			stmt = conn.createStatement();
			oracle.jdbc.driver.OracleStatement ostmt =
				(oracle.jdbc.driver.OracleStatement)stmt;
			ostmt.defineColumnType (1, Types.LONGVARCHAR);
			b = "select metin from emsal.karar where daireno='"+kisadaire+"' and esasno='"+esasno+"'";
			//log(b);
			rset = ostmt.executeQuery(b);
			rset.next ();
			htmljustify(out,rset.getString(1));
			rset.close();
			stmt.close();

		} catch (SQLException e){
            		while(e != null) {
				log("adim4: SQLException: " + e.getSQLState() + "(1)" +
		    			e.getMessage() + "(2)" +
		    			e.getErrorCode() + "(3)");
					e = e.getNextException();
            		}
            			//out.println(e.toString());
        	} catch (Exception e) {
	    		e.printStackTrace();
		}

		//out.println("Adim 2 mtn= " + mtn);
	}




	private void htmljustify(PrintWriter out, String buff){
		int x=buff.length();
		for(int i = 0; i <x;i++){
			if(buff.charAt(i)=='\n')out.print("<p ALIGN=\"JUSTIFY\">");
			else if(buff.charAt(i)==' ' && i < x-1 && buff.charAt(i+1)==' ')
					out.print("&nbsp;");
			else{
				if(i<x-1)
					out.print(buff.substring(i,i+1));
			}
		}
	}



	public void main(){}


	private String iso1to9(String str)
	{
		byte er[];
		try{
                        er = str.getBytes("ISO8859_1");
                        str = new String(er, "ISO8859_9");
		}catch(Exception e){
			log("Character encoding!!!");
		}
		return str;
	}
	private String iso9to9(String str)
	{
		byte er[];
		try{
                        er = str.getBytes("ISO8859_9");
                        str = new String(er, "ISO8859_9");
		}catch(Exception e){
			log("Character encoding!!!");
		}
		return str;
	}
	private String iso9toUTF8(String str)
	{
		byte er[];
		try{
                        er = str.getBytes("ISO8859_9");
                        str = new String(er, "UTF8");
		}catch(Exception e){
			log("Character encoding!!!");
		}
		return str;
	}
	private String iso1toUTF8(String str)
	{
		byte er[];
		try{
                        er = str.getBytes("ISO8859_1");
                        str = new String(er, "UTF8");
		}catch(Exception e){
			log("Character encoding!!!");
		}
		return str;
	}
	private String isoUTF8to9(String str)
	{
		byte er[];
		try{
                        er = str.getBytes("UTF8");
                        str = new String(er, "ISO8859_9");
		}catch(Exception e){
			log("Character encoding!!!");
		}
		return str;
	}

}
 



class daireler_t{
        String   code[];
        String   name[];
	int	counter = 0;
	int	end = 0;
	
	public daireler_t(){
		code = new String[50];
		name = new String[50];

	}

	public void adddaire(String kisa, String uzun){
		code[counter]=new String(kisa);
		name[counter]=new String(uzun);
		end = ++counter;
	}
	public String getkisa(){
		return code[counter];
	}
	public String getuzun(){
		return name[counter];
	}
	public void tostart(){
		counter = 0;
	}
	public void tonext(){
		if(counter != end) counter++;
	}
	public boolean isend(){
		if(counter == end) return true;
		return false;
	}
}
