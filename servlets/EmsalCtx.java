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
public class EmsalCtx extends HttpServlet
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

	String ksdaireNo = new String();
	String ksesasSiraYil = new String();
	String kskararsonucu = new String();
	String kskarartarihi = new String();
	String kskararnumarasi = new String();
	String ksgonderilistarihi = new String();

	String daireNo = new String();
	String esasSiraYil = new String();
	String esasSiraNo = new String();
	String geldigiTarih = new String();
	String tarihi = new String();
	String esasNo = new String();
	String kararNo = new String();
	String gonderenMahkeme = new String();
	String temyizEden = new String();
	String aleyhineTemyiz = new String();
	String davaninTuru = new String();
	String dusunceler = new String();
	String gonderendaire = new String();
	String kararsonucu = new String();
	

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
			if(conn == null){
               		 conn = DriverManager.getConnection ("jdbc:oracle:oci8:@y1",
                		"emsal","emsal");
			}
                        stmt = conn.createStatement ();
                        stmt.executeUpdate("alter session set NLS_LANGUAGE=turkish");
                        stmt.executeUpdate("alter session set NLS_TERRITORY=turkey");
                        stmt.close();


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
		String text = "";
		String mtn = "";
		int i;



		//System.setLocale(new Locale("en", "US"));
		//request.setLocale(new Locale("en", "US"));

            PrintWriter out;
            // set content type and other response header fields first
            //response.setContentType("text/html");
            // then write the data of the response
		//log(request.getContentType());
		//log(request.getCharacterEncoding());
		//log(getCharacterEncoding());
		response.setContentType("text/html; charset=iso-8859-9");
            out = response.getWriter();

            out.println("<HTML><HEAD>");
            out.println("<TITLE>Emsal Sorgu Sonucu</TITLE>");
            out.println("</HEAD>");
	out.println("<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-9\">");
	out.println("<BODY bgcolor=\"#FFFFFF\">");
	out.println("<center><a href=\"http://www.yargitay.gov.tr/\">"+
			"<img src=\"http://www.yargitay.gov.tr/images/bas.JPG\""+
			" width=\"298\" height=\"77\"></a>");
            out.println("<h1><font size=\"+3\" color=\"#6699FF\">"+
			"Emsal Arama</font></h1> </center> <hr>");
            

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
			if(name.compareTo("text") == 0){
				text = request.getParameterValues("text")[0];
			}
			if(name.compareTo("mtn") == 0){
				mtn = request.getParameterValues("mtn")[0];
			}
		}
		if(adim.compareTo("abracadabra") == 0 || adim.compareTo("0") == 0){
			doadim1(out, text);
		}else{
			doadim2(out,mtn);
		}


            out.println("</BODY></HTML>");
            out.close();
        }

	private void doadim1(PrintWriter out, String text){
		String query1 = "asdf";
		long ctxid =  99999999;
		long ahcount = 99999999;
		Statement stmt = null;
		ResultSet rset = null;
		byte er[]={0};
		int i;
		String nx;


	PreparedStatement ctxseq;
	PreparedStatement ctxtabselect;
	CallableStatement hitcount;
	CallableStatement contains;

		text = sanilize(text);

		try {
			ctxseq =  conn.prepareStatement("select ctxseq.nextval from dual");
			hitcount = conn.prepareCall(
		"{ ? = call ctx_query.count_hits(?,?, TRUE) }");
			contains = conn.prepareCall(
		//"{ call ctx_query.contains( ?, ?, ?, ?, ?) }");
		"{ call ctx_query.contains( 'ctxkarar', ?, 'ctx_temp', 1, ?) }");
			ctxtabselect = conn.prepareStatement(
				"select "+
                		"ctx_temp.TEXTKEY, ctx_temp.SCORE, karar.daireno,"+
                		"karar.esasno, karar.kararno "+
                		"from ctx_temp, karar WHERE ctx_temp.CONID=? and " +
                		"ctx_temp.textkey = karar.id order by ctx_temp.score desc");

			rset = ctxseq.executeQuery();
			rset.next();
			ctxid = rset.getLong(1);
			rset.close();




			hitcount.clearParameters();
			hitcount.registerOutParameter(1,java.sql.Types.DECIMAL); 
			hitcount.setString(2,"ctxkarar");
			hitcount.setString(3,text);
			hitcount.executeQuery();
			ahcount = hitcount.getLong(1);
			hitcount.close();
			out.println(ahcount + " dosya bulunmuþtur <br>");
			//contains.setString(1,"ctxkarar");
			contains.setString(1,text);
			//contains.setString(3,"ctx_temp");
			//contains.setLong(4,1);
			contains.setLong(2,ctxid);
			contains.executeQuery();
			
			ctxtabselect.setLong(1,ctxid);
			rset = ctxtabselect.executeQuery();

			out.println("<table>");
			out.println("<tr><td><b>%</b></td><td><b>Daire</b></td>"+
"<td><b>Esas numarasý</b></td><td><b>Karar numarasý</b></td></tr>");
			while(rset.next()){
				out.println("<tr><td><a href=\"EmsalCtx?adim=2&mtn=" +
					rset.getString(1) +
					"\">"+
					rset.getLong(2)+
					"</td><td>"+
					rset.getString(3)+
					"</td><td>"+
					rset.getString(4)+"</td><td>"+
					rset.getString(5)+"</td></tr></a>");
			}
			out.println("</table>");
			ctxtabselect.close();

		} catch (SQLException e){
			out.println("</table>");
            		while(e != null) {
				log("adim1: SQLException: " + e.getSQLState() + '\t' +
		    			e.getMessage() + '\t' +
		    			e.getErrorCode() + '\t');
					e = e.getNextException();
            		}
			//log(text);
            			//out.println(e.toString());
        	} catch (Exception e) {
	    		e.printStackTrace();
		}
	}


	private void doadim2(PrintWriter out, String mtn){
		Statement stmt = null;
		ResultSet rset = null;
		String b = new String("");
		PreparedStatement metinselect;
		byte buff[] = new byte[1024*1024];
		long a;
		int i;
		try{
			java.io.InputStream fin = null;
			java.io.InputStreamReader finr = null;
			stmt = conn.createStatement();
			//metinselect = conn.prepareStatement(
			//	"select METIN from karar where id= ?");
			oracle.jdbc.driver.OracleStatement ostmt = 
  				(oracle.jdbc.driver.OracleStatement)stmt;
			ostmt.defineColumnType (1, Types.LONGVARCHAR);
			b = "select metin from karar where id="+mtn;
			rset = ostmt.executeQuery
         			(b);
			rset.next ();
			htmljustify(out,rset.getString(1));

/*
			metinselect.clearParameters();
			metinselect.setLong(1, lg.longValue());
			rset = metinselect.executeQuery();
			while(rset.next()){
				//b = rset.getString(1);
				//htmljustify(out,b);
				//out.println(b);
				//out.print(b);
				//try{
				//b = new String(rset.getString(1));
				//out.println(b);
				fin  = rset.getBinaryStream(1);
				//}catch(Exception e){
				//	log("getAsciiStream"+ e.getMessage());
				////}
				int c;
				while ((c = fin.read ()) != -1)out.write (c);
			}

			fin.close();
			rset.close();
			metinselect.close();
*/
			ostmt.close();
				
	
		
		} catch (SQLException e){
            		while(e != null) {
				log("adim2: SQLException: " + e.getSQLState() + "(1)" +
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




	private String sanilize(String str)
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









}
 
