import java.sql.*;
import java.math.*;
import java.io.*;
import java.util.*;
import java.util.Date.*;
import javax.servlet.*;
import javax.servlet.http.*;


/**
 * This is a simple example of an HTTP Servlet.  It responds to the GET
 * and HEAD methods of the HTTP protocol.
 */
public class CezaSorgu extends HttpServlet
{ 
    /**
     * Handle the GET and HEAD methods by building a simple web page.
     * HEAD is just like GET, except that the server returns only the
     * headers (including content length) not the body we write.
     */
	long kararsonucu = 0;
	static boolean initialized = false;
	static boolean erroroninit = false;
	SQLWarning warning;
        Connection conn = null;
	Locale trlocale = new Locale("tr","TR", "POSIX");

	private void doconnect(){
		Statement stmt = null;
		try{
			DriverManager.registerDriver(new oracle.jdbc.driver.OracleDriver());
			Properties prop = new Properties();
			prop.put("charSet","iso-8859-9");
			if(conn == null){
               		 conn = DriverManager.getConnection ("jdbc:oracle:oci8:@y1",
                		"sorgu","sorgu");
			}
			stmt = conn.createStatement ();
			stmt.executeUpdate("alter session set NLS_LANGUAGE=turkish");
			stmt.executeUpdate("alter session set NLS_TERRITORY=turkey");
			//stmt.executeUpdate("alter session set NLS_LANG=TURKISH_TURKEY.WE8ISO8859P9");
			stmt.close();
			 } catch (SQLException e){
            			erroroninit=true;
            			while(e != null) {
                			log("SQLException: " + e.getSQLState() + '\t' +
                    			e.getMessage() + '\t' +
                    			e.getErrorCode() + '\t');
                			e = e.getNextException();
            			}
        		} catch (Exception e) {
	    			e.printStackTrace();
			}
	}

	public void init(ServletConfig config) throws ServletException {

		if(initialized == true){
			return;
		}else{
			initialized = true;
		}
		super.init(config);
		//log(trlocale.getCountry());
		//log(trlocale.getCountry());
		//log(trlocale.toString());
		//log("abracadabra \t");
		doconnect();
	}



    public void destroy() {
        try {
	if(conn != null){
            conn.close();
	}
        } catch (SQLException e) {
            while(e != null) {
		log("SQLException: " + e.getSQLState() + '\t' +
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
	PreparedStatement pstmt = null;
	Statement stmt = null;
	ResultSet rset = null;
	Statement ksstmt = null;
	ResultSet ksrset = null;



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
	String tebligTarih = new String();
	String tebligMasa = new String();
	String tebligNo = new String();
	String esasNo = new String();
	String kararNo = new String();
	String gonderenMahkeme = new String();
	String sucunTuru = new String();
	String temyizEden = new String();
	String tutuklu = new String();
	boolean yeni = false;










		String ksquery = new String(""); 
		int i;


		//log(request.getCharacterEncoding());

            PrintWriter out;
            // set content type and other response header fields first
            response.setContentType("text/html");
            // then write the data of the response
		response.setContentType("text/html; charset=iso-8859-9");
            out = response.getWriter();
            out.println("<HTML><HEAD>");
            out.println("<TITLE>Ceza Sorgu Sonucu</TITLE>");
            out.println("</HEAD>");
	out.println("<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-9\">");
	out.println("<BODY bgcolor=\"#FFFFFF\">");
	out.println("<center><a href=\"http://www.yargitay.gov.tr/\">"+
			"<img src=\"http://www.yargitay.gov.tr/images/bas.JPG\""+
			" width=\"298\" height=\"77\"></a>");
            out.println("<h1><font size=\"+3\" color=\"#6699FF\">"+
			"Ceza Sorgu Sonuçlarý</font></h1> </center> <hr>");
            

		if(erroroninit == true){
			out.println("Veritabaný þu an bakýmda. Lütfen sonra deneyin");
		}
	HttpSession session = request.getSession(true);
	
/*
	Integer ival = (Integer) session.getValue("CezaSorgu.counter");
		if (ival==null)
			ival = new Integer(1);
		else 
			ival = new Integer(ival.intValue() + 1);
	session.putValue("CezaSorgu.counter", ival);
	out.println(ival);
*/
 

	//log(request.getRequestedSessionId());
	//if(request.isRequestedSessionIdFromUrl()==true)log("from url");
	//if(request.isRequestedSessionIdFromCookie()==true)log("from cookie");
	 ksdaireNo = "";
	 ksesasSiraYil = "";
	 kskararsonucu = "";
	 kskarartarihi = "";
	 kskararnumarasi = "";
	 ksgonderilistarihi = "";

	 daireNo = "";
	 esasSiraYil = "";
	 esasSiraNo = "";
	 geldigiTarih = "";
	 tebligTarih = "";
	 tebligMasa = "";
	 tebligNo = "";
	 esasNo = "";
	 kararNo = "";
	 gonderenMahkeme = "";
	 sucunTuru = "";
	 temyizEden = "";
	 tutuklu = "";
	 kararsonucu = 0;
         boolean waswhere = false;
	 byte a[]={0,0,0,0,0,0};
         String result = new String("");
	 String query = new String("");

		Enumeration values = request.getParameterNames();

		while(values.hasMoreElements()) {
			String name = (String)values.nextElement();
			if(name.compareTo("daireno") == 0) {
				daireNo		= request.getParameterValues("daireno")[0];
			}
			if(name.compareTo("esassirayil") == 0) {
				esasSiraYil	= request.getParameterValues("esassirayil")[0];
			}
			if(name.compareTo("esassirano") == 0) {
				esasSiraNo	= request.getParameterValues("esassirano")[0];
			}
			if(name.compareTo("geldigitarih") == 0) {
				geldigiTarih	= request.getParameterValues("geldigitarih")[0];
			}
			if(name.compareTo("tebligtarih") == 0) {
				tebligTarih	= request.getParameterValues("tebligtarih")[0];
			}
			if(name.compareTo("tebligmasa") == 0) {
				tebligMasa	= request.getParameterValues("tebligmasa")[0];
			}
			if(name.compareTo("tebligno") == 0) {
				tebligNo	= request.getParameterValues("tebligno")[0];
			}
			if(name.compareTo("esasno") == 0) {
				esasNo		= request.getParameterValues("esasno")[0];
			}
			if(name.compareTo("kararno") == 0) {
				kararNo		= request.getParameterValues("kararno")[0];
			}
			if(name.compareTo("gonderenmahkeme") == 0) {
				gonderenMahkeme	= request.getParameterValues("gonderenmahkeme")[0];
			}
			if(name.compareTo("sucunturu") == 0) {
				sucunTuru	= request.getParameterValues("sucunturu")[0];
			}
			if(name.compareTo("temyizeden") == 0) {
				temyizEden	= request.getParameterValues("temyizeden")[0];
			}
			if(name.compareTo("tutuklu") == 0) {
				tutuklu		= request.getParameterValues("tutuklu")[0];
			}
			if(name.compareTo("yeni") == 0) {
				yeni		= true;
			}
		}
		HttpSessionContext sctx = session.getSessionContext();
		Enumeration values1 = sctx.getIds();
		while(values1.hasMoreElements()) {
			String ss = (String)values1.nextElement();
			HttpSession s1 = sctx.getSession(ss);
			long tm = s1.getLastAccessedTime();
			java.util.Date  now = new java.util.Date();
			//log("Sessions: "+ss+"\t"+tm+"\t"+now.getTime()+"\t"+(now.getTime()-tm));
			if(now.getTime()-tm > 3600000){
				/* Destroing session */
				stmt = (Statement)s1.getValue("CezaSorgu.stmt");
				rset = (ResultSet)s1.getValue("CezaSorgu.rset");
				try{
					rset.close();
					stmt.close();
				} catch (SQLException e){
            				while(e != null) {
						log("SQLException: " + e.getSQLState() + '\t' +
		    				e.getMessage() + '\t' +
		    				e.getErrorCode() + '\t');
						e = e.getNextException();
            				}
        			} catch (Exception e) {
	    				e.printStackTrace();
				}
				s1.invalidate();
				log("Session "+ss+" timed out and destroyed");
			}
				
		}


//---------------------------------*****************
                if(daireNo.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "daireno like '"+daireNo+"%'";
                }
                if(esasSiraYil.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "esassirayil like '"+esasSiraYil+"%'";
                }
                if(esasSiraNo.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "esassirano ="+esasSiraNo;
                }
                if(geldigiTarih.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "geldigitarih = '"+geldigiTarih+"'";
                }
                if(tebligTarih.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "tebligtarih = '"+tebligTarih+"'";
                }
                if(tebligMasa.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "tebligmasa like '"+tebligMasa+"%'";
                }
                if(tebligNo.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "tebligno ="+tebligNo;
                }
                if(esasNo.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "esasno ="+esasNo;
                }
                if(kararNo.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "kararno ="+kararNo;
                }
                if(gonderenMahkeme.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        //result += "gonderenmahkeme like '"+gonderenMahkeme+"%'";
                        result += "gonderenmahkeme like '"+gonderenMahkeme.toLowerCase(trlocale)+"%'";
			//log(gonderenMahkeme.toLowerCase(trlocale));
                }
                if(sucunTuru.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "sucunturu like '"+sucunTuru+"%'";
                }
                if(temyizEden.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "temyizeden like '"+temyizEden+"%'";
                }
                if(tutuklu.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "tutuklu like '"+tutuklu+"%'";
                }
//---------------------------------*****************
		
		query = "select " +
                "daireno, esassirayil, esassirano, to_char(geldigitarih, 'DD/MM/YYYY')," +
                "to_char(tebligtarih,'DD/MM/YYYY'), tebligmasa, tebligno, esasno," +
                "kararno, gonderenmahkeme, sucunturu," +
                "temyizeden, tutuklu, kararsonucu " +
                "from ceza.gelendosya " + result + " order by giristarihi desc"; //sanilize(result);
		query=sanilize(query);
		//query = format(query);
		//log(query);
		//log(System.getProperty("file.encoding"));
		//System.setProperty("file.encoding", "8859_1");
		

	 ksdaireNo = "";
	 ksesasSiraYil = "";
	 kskararsonucu = "";
	 kskarartarihi = "";
	 kskararnumarasi = "";
	 ksgonderilistarihi = "";

	 daireNo = "";
	 esasSiraYil = "";
	 esasSiraNo = "";
	 geldigiTarih = "";
	 tebligTarih = "";
	 tebligMasa = "";
	 tebligNo = "";
	 esasNo = "";
	 kararNo = "";
	 gonderenMahkeme = "";
	 sucunTuru = "";
	 temyizEden = "";
	 tutuklu = "";
	 kararsonucu = 0;

		//out.println(query);


		try{
			if(yeni == true){
				if(!session.isNew()){
					stmt = (Statement)session.getValue("CezaSorgu.stmt");
					rset = (ResultSet)session.getValue("CezaSorgu.rset");
					if(rset != null)rset.close();
					if(stmt != null)stmt.close();
				}
				stmt = conn.createStatement ();
				rset = stmt.executeQuery (query);
			}else{
				if(session.isNew()){
					out.println("Isteðiniz zamanaþamýna uðramýþtýr.<br>"+
						"Lütfen <a href=\"http://www.yargitay.gov.tr/cevrak.html\">sorgu sayfasýna</a>"+
						" gidip yineden çalýþtýrýn");
					return;
				}
				stmt = (Statement)session.getValue("CezaSorgu.stmt");
				rset = (ResultSet)session.getValue("CezaSorgu.rset");
			}
			pstmt = conn.prepareStatement(
					"SELECT karsonucu, TO_CHAR(karartarihi,'DD/MM/YYYY')"+
					",kararnumarasi,TO_CHAR(gonderilistarihi,'DD/MM/YYYY')"+
					" FROM ceza.kararsonucu WHERE "+
					"id = ? ") ;
		} catch (SQLException e){
            		while(e != null) {
				log("SQLException: " + e.getSQLState() + '\t' +
		    			e.getMessage() + '\t' +
		    			e.getErrorCode() + '\t');
					e = e.getNextException();
            			//out.println("qqqqqqqqqqqqqq"+e.toString());
            		}
        	} catch (Exception e) {
	    		e.printStackTrace();
            	//	out.println("qqqqqqqqqqqqqq"+e.toString());
		}
        	if (warning != null) {
                          out.println("\n---Warning---\n");
                          while (warning != null) {
                                  out.println("Message: "
                                                    + warning.getMessage());
                                  out.println("SQLState: "
                                                     + warning.getSQLState());
                                  out.print("Vendor error code: ");
                                  out.println(warning.getErrorCode());
                                  out.println("");
                                  warning = warning.getNextWarning();
                          }
                  }

//--------------------------------
	boolean dummy = false;
	for(i=0;i<1;i++){
			try{
				dummy = rset.next();
			} catch (SQLException e){
            			while(e != null) {
					log("SQLException: " + e.getSQLState() + '\t' +
		    				e.getMessage() + '\t' +
		    				e.getErrorCode() + '\t');
						e = e.getNextException();
            			}
            				//out.println(e.toString());
        		} catch (Exception e) {
	    			e.printStackTrace();
			}
                	if(dummy){
				try{
                        	daireNo=(rset.getString(1));
                        	esasSiraYil=(rset.getString(2));
                        	esasSiraNo=(rset.getString(3));
                        	geldigiTarih=(rset.getString(4));
                        	tebligTarih=(rset.getString(5));
                        	tebligMasa=(rset.getString(6));
				if(rset.wasNull()){
					tebligMasa = "";
				}
                        	tebligNo=(rset.getString(7));
                        	esasNo=(rset.getString(8));
                        	kararNo=(rset.getString(9));
                        	gonderenMahkeme=(rset.getString(10));
                        	sucunTuru=(rset.getString(11));
                        	temyizEden=(rset.getString(12));
                        	tutuklu=(rset.getString(13));
				if(rset.wasNull()){
					tutuklu = "";
				}
				kararsonucu=(rset.getLong(14));
				} catch (SQLException e){
            				while(e != null) {
						log("SQLException: " + e.getSQLState() + '\t' +
		    					e.getMessage() + '\t' +
		    					e.getErrorCode() + '\t');
							e = e.getNextException();
            				}
            					//out.println(e.toString());
        			} catch (Exception e) {
	    				e.printStackTrace();
				}

				//out.println("holario: "+ esasSiraNo);
				out.println("<table>"+
				"<tr><td><td><b>Daire Numarasý  </b></td><td>" + daireNo + "</td></tr>" +
				"<tr><td><td><b>Esas Sýra Yýl   </b></td><td>" + esasSiraYil + "</td></tr>" +
				"<tr><td><td><b>Esas Sýra No    </b></td><td>" + esasSiraNo + "</td></tr>" +
				"<tr><td><td><b>Geldiði Tarih   </b></td><td>" + geldigiTarih + "</td></tr>" +
				"<tr><td><td><b>Teblið Tarihi   </b></td><td>" + tebligTarih + "</td></tr>" +
				"<tr><td><td><b>Teblið Masasý   </b></td><td>" + tebligMasa + "</td></tr>" +
				"<tr><td><td><b>Teblið Numarasý </b></td><td>" + tebligNo + "</td></tr>" +
				"<tr><td><td><b>Esas No         </b></td><td>" + esasNo + "</td></tr>" +
				"<tr><td><td><b>Karar No        </b></td><td>" + kararNo + "</td></tr>" +
				"<tr><td><td><b>Gönderen mahkeme</b></td><td>" + gonderenMahkeme+ "</td></tr>" +
				"<tr><td><td><b>Sucun türü      </b></td><td>" + sucunTuru + "</td></tr>" +
				"<tr><td><td><b>Temyiz eden     </b></td><td>" + temyizEden + "</td></tr>" +
				"<tr><td><td><b>Tutuklu         </b></td><td>" + tutuklu + "</td></tr>" +
				"</table>");
				out.println("------------ Karar sonucu -------------<br>");
				if(kararsonucu == 0){
					out.println("<b>Bu dosya sonuca baðlanmamýþtýr</b>");
				}else{
					//out.println("kararsonucu="+kararsonucu);
					ksquery = "SELECT karsonucu, TO_CHAR(karartarihi,'DD/MM/YYYY')"+
						",kararnumarasi,TO_CHAR(gonderilistarihi,'DD/MM/YYYY')"+
						" FROM ceza.kararsonucu WHERE "+
						"id ="+kararsonucu ;
					//out.println("ksquety="+ksquery);
					try{
						//ksstmt = conn.createStatement ();
						//ksrset = ksstmt.executeQuery (ksquery);
						pstmt.clearParameters();
						pstmt.setLong(1,kararsonucu);
						ksrset = pstmt.executeQuery();
						ksrset.next();
						warning = stmt.getWarnings();
					} catch (SQLException e){
            					while(e != null) {
							log("SQLException: " + e.getSQLState() + '\t' +
		    					e.getMessage() + '\t' +
		    					e.getErrorCode() + '\t');
							e = e.getNextException();
            						//out.println("qqqqqqqqqqqqqq"+e.toString());
            				}
        				} catch (Exception e) {
	    					e.printStackTrace();
            					//	out.println("qqqqqqqqqqqqqq"+e.toString());
					}

					try{
					out.println("<table>"+
					"<tr><td><td><b>Karar</b></td><td>" + ksrset.getString(1) + "</td></tr>"+
					"<tr><td><td><b>Karar tarihi</b></td><td>" + ksrset.getString(2) + "</td></tr>"+
					"<tr><td><td><b>Karar numarasi</b></td><td>" + ksrset.getString(3) + "</td></tr>"+
					"<tr><td><td><b>Gönderiliþ tarihi</b></td><td>" + ksrset.getString(4) + "</td></tr>"+
					"</table>");
                				ksrset.close();
                				//ksstmt.close();
                			} catch (SQLException e){
                        			while(e != null) {
                                			log("SQLException: " + e.getSQLState() + '\t' +
                                        		e.getMessage() + '\t' +
                                        		e.getErrorCode() + '\t');
                                        		e = e.getNextException();
                        		}
                                			//out.println(e.toString());
                			} catch (Exception e) {
                        			e.printStackTrace();
                			}
				}
				out.println("<hr>");
				continue;
                	}else {break;}
	}
	if(i==0){
		if(yeni==true){
			out.println("Hiçbir dosya bulunamamýþtýr");
		}else{
			out.println("Son kayýt");
			out.println("<br> <a href=\"http://www.yargitay.gov.tr/cevrak.html\">sorgu sayfasý</a>");
		}
	}
	if(i==1){
		//out.println("Sorgu 20'den fazla sonuç getirmiþtir. Sorgu alaný daraltýn "+
		//	"ve yineden deneyin");
		out.println("<a href=\""+response.encodeUrl(request.getServletPath())+"\">Sonraki kayýt</a>");
		session.putValue("CezaSorgu.stmt", stmt);
		session.putValue("CezaSorgu.rset", rset);
	}else{


		try{
		rset.close();
		stmt.close(); 
		pstmt.close(); 
		} catch (SQLException e){
            		while(e != null) {
				log("SQLException: " + e.getSQLState() + '\t' +
		    			e.getMessage() + '\t' +
		    			e.getErrorCode() + '\t');
					e = e.getNextException();
            		}
            			//out.println(e.toString());
        	} catch (Exception e) {
	    		e.printStackTrace();
		}
	}
            out.println("</BODY></HTML>");
            out.close();
        }



	public void main(){}





/*

        String constructwhere(){



                return result;
        }
*/




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
	private String sanilize99(String str)
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
	private String sanilize91(String str)
	{
		byte er[];
		try{
                        er = str.getBytes("ISO8859_9");
                        str = new String(er, "ISO8859_1");
		}catch(Exception e){
			log("Character encoding!!!");
		}
		return str;
	}







}
 
