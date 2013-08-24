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
public class HukukSorgu extends HttpServlet
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
                		"sorgu","sorgu");
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
		try{
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
	log("Destroyin HukukSorgu");
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
	PreparedStatement pstmt = null;
	Statement stmt = null;
	ResultSet rset = null;
	Statement ksstmt = null;
	ResultSet ksrset = null;

        boolean waswhere = false;
        String result="";

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
	long kararsonucu = 0;
	boolean yeni = false;

		String query = new String(""); 
		String ksquery = new String(""); 
		int i;
            PrintWriter out;
            // set content type and other response header fields first
            response.setContentType("text/html");
            // then write the data of the response
		response.setContentType("text/html; charset=iso-8859-9");
            out = response.getWriter();
            out.println("<HTML><HEAD>");
            out.println("<TITLE>Hukuk Sorgu Sonucu</TITLE>");
            out.println("</HEAD>");
	out.println("<META HTTP-EQUIV=\"Content-Type\" CONTENT=\"text/html; charset=iso-8859-9\">");
	out.println("<BODY bgcolor=\"#FFFFFF\">");
	out.println("<center><a href=\"http://www.yargitay.gov.tr/\">"+
			"<img src=\"http://www.yargitay.gov.tr/images/bas.JPG\""+
			" width=\"298\" height=\"77\"></a>");
            out.println("<h1><font size=\"+3\" color=\"#6699FF\">"+
			"Hukuk Sorgu Sonuçlarý</font></h1> </center> <hr>");
            

		if(erroroninit == true){
			out.println("Veritabaný þu an bakýmda. Lütfen sonra deneyin");
		}
	HttpSession session = request.getSession(true);


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
	 tarihi = "";
	 esasNo = "";
	 kararNo = "";
	 gonderenMahkeme = "";
	 temyizEden = "";
	 aleyhineTemyiz = "";
	 davaninTuru = "";
	 dusunceler = "";
	 gonderendaire = "";
	 kararsonucu = 0;















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
			if(name.compareTo("tarihi") == 0) {
				tarihi		= request.getParameterValues("tarihi")[0];
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
			if(name.compareTo("temyizeden") == 0) {
				temyizEden	= request.getParameterValues("temyizeden")[0];
			}
			if(name.compareTo("aleyhinetemyiz") == 0) {
				aleyhineTemyiz	= request.getParameterValues("aleyhinetemyiz")[0];
			}
			if(name.compareTo("davaninturu") == 0) {
				davaninTuru	= request.getParameterValues("davaninturu")[0];
			}
			if(name.compareTo("dusunceler") == 0) {
				dusunceler	= request.getParameterValues("dusunceler")[0];
			}
			if(name.compareTo("gonderendaire") == 0) {
				gonderendaire	= request.getParameterValues("gonderendaire")[0];
			}
			if(name.compareTo("yeni") == 0) {
				yeni	= true;
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
                if(tarihi.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "tarihi = '"+tarihi+"'";
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
                        result += "gonderenmahkeme like '"+gonderenMahkeme+"%'";
                }
                if(temyizEden.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "temyizeden like '"+temyizEden+"%'";
                }
                if(aleyhineTemyiz.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "aleyhinetemyiz like '"+aleyhineTemyiz+"%'";
                }
                if(davaninTuru.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "davaninturu like '"+davaninTuru+"%'";
                }
                if(dusunceler.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "dusunceler like '"+dusunceler+"%'";
                }
                if(gonderendaire.length()!=0){
                        if(!waswhere){result+=" where ";waswhere=true;}
                        else result +=" and ";
                        result += "gonderendaire like '"+gonderendaire+"%'";
                }
//---------------------------------*****************
		
		query += "select " +
                "DAIRENO, ESASSIRAYIL, ESASSIRANO, to_char(GELDIGITARIH, 'DD/MM/YYYY')," +
                "to_char(TARIHI,'DD/MM/YYYY'), ESASNO, KARARNO, GONDERENMAHKEME," +
                "TEMYIZEDEN, ALEYHINETEMYIZ, DAVANINTURU," +
                "DUSUNCELER, GONDERENDAIRE, KARARSONUCU " +
                "from hukuk.gelendosya " + result+ " order by giristarihi desc";
		
		query = sanilize(query);


		//out.println(query);


		//if(conn == null)init();
		try{
			if(yeni == true){
				if(!session.isNew()){
					stmt = (Statement)session.getValue("HukukSorgu.stmt");
					rset = (ResultSet)session.getValue("HukukSorgu.rset");
					if(rset != null)rset.close();
					if(stmt != null)stmt.close();
				}
				stmt = conn.createStatement ();
				rset = stmt.executeQuery (query);
			}else{
				if(session.isNew()){
					out.println("Isteðiniz zamanaþamýna uðramýþtýr.<br>"+
						"Lütfen <a href=\"http://www.yargitay.gov.tr/hevrak.html\">sorgu sayfasýna</a>"+
						" gidip yineden çalýþtýrýn");
					return;
				}
				stmt = (Statement)session.getValue("CezaSorgu.stmt");
				rset = (ResultSet)session.getValue("CezaSorgu.rset");
			}
			pstmt = conn.prepareStatement(
					"SELECT karsonucu, TO_CHAR(karartarihi,'DD/MM/YYYY')"+
					",kararnumarasi,TO_CHAR(gonderilistarihi,'DD/MM/YYYY')"+
					" FROM hukuk.kararsonucu WHERE "+
					"id = ? ");
		} catch (SQLException e){
            		while(e != null) {
				log("conn.createStatement & stmt.executeQuery :SQLException: " + e.getSQLState() + '\t' +
		    			e.getMessage() + '\t' +
		    			e.getErrorCode() + '\t');
				log(query);
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
					log("rset.next: SQLException: " + e.getSQLState() + '\t' +
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
                        	tarihi=(rset.getString(5));
                        	esasNo=(rset.getString(6));
                        	kararNo=(rset.getString(7));
                        	gonderenMahkeme=(rset.getString(8));
                        	temyizEden=(rset.getString(9));
                        	aleyhineTemyiz=(rset.getString(10));
                        	davaninTuru=(rset.getString(11));
                        	dusunceler=(rset.getString(12));
				if(rset.wasNull()){
					dusunceler = "";
				}
                        	gonderendaire=(rset.getString(13));
				if(rset.wasNull()){
					gonderendaire = "";
				}
				kararsonucu=(rset.getLong(14));
				} catch (SQLException e){
            				while(e != null) {
						log("rset.getString: SQLException: " + e.getSQLState() + '\t' +
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
        "<tr><td><td><b>Kayýt Tarihi    </b></td><td>" + geldigiTarih + "</td></tr>" +
        "<tr><td><td><b>Mahkeme Tarihi  </b></td><td>" + tarihi + "</td></tr>" +
        "<tr><td><td><b>Mahkeme Esas No.</b></td><td>" + esasNo + "</td></tr>" +
        "<tr><td><td><b>Mahkeme Karar No.</b></td><td>" + kararNo + "</td></tr>" +
        "<tr><td><td><b>Geldiði Mahkeme </b></td><td>" + gonderenMahkeme + "</td></tr>" +
        "<tr><td><td><b>Temyiz Eden     </b></td><td>" + temyizEden + "</td></tr>" +
        "<tr><td><td><b>Aleyhine Temyiz</b></td><td>" + aleyhineTemyiz  + "</td></tr>"  +
        "<tr><td><td><b>Davanýn Türü    </b></td><td>" + davaninTuru + "</td></tr>" +
        "<tr><td><td><b>Düþünceler      </b></td><td>" + dusunceler + "</td></tr>" +
        "<tr><td><td><b>Gönderen Daire  </b></td><td>" + gonderendaire + "</td></tr>" +
				"</table>");
				out.println("------------ Karar sonucu -------------<br>");
				if(kararsonucu == 0){
					out.println("<b>Bu dosya sonuca baðlanmamýþtýr</b>");
				}else{
					//out.println("kararsonucu="+kararsonucu);
					ksquery = "SELECT karsonucu, TO_CHAR(karartarihi,'DD/MM/YYYY')"+
						",kararnumarasi,TO_CHAR(gonderilistarihi,'DD/MM/YYYY')"+
						" FROM hukuk.kararsonucu WHERE "+
						"id ="+kararsonucu ;
					//out.println("ksquety="+ksquery);
					try{
        if(ksstmt != null){
            ksstmt.close();
        }
						//ksstmt = conn.createStatement ();
        if(ksrset != null){
            ksrset.close();
        }
						pstmt.clearParameters();
						pstmt.setLong(1,kararsonucu);
						ksrset = pstmt.executeQuery();
						boolean qw = ksrset.next();
						//if(qw)out.println("next");
						warning = stmt.getWarnings();
					} catch (SQLException e){
            					while(e != null) {
							log("conn.createStatement & ksstmt.executeQuery & ksrset.next: SQLException: " + e.getSQLState() + '\t' +
		    					e.getMessage() + '\t' +
		    					e.getErrorCode() + '\t');
							log(ksquery);
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
                				//ksrset.close();
						ksrset = null;
                				//ksstmt.close();
						//ksstmt = null;
                			} catch (SQLException e){
                        			while(e != null) {
                                			log("ksrset.close & ksstmt.close: SQLException: " + e.getSQLState() + '\t' +
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
		if(yeni == true){
			out.println("Hiçbir dosya bulunmamýþtýr");
		}else{
			out.println("Son kayýt");
			out.println("<br><a href=\"http://www.yargitay.gov.tr/hevrak.html\">sorgu sayfasý</a>");
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
		//rset.close();
		//rset = null;
		pstmt.close(); 
	stmt.close(); 
		stmt = null;
		} catch (SQLException e){
            		while(e != null) {
				log("stmt & rset close : SQLException: " + e.getSQLState() + '\t' +
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







}
 
