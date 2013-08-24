<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 3.2//EN">
<?
include "kurumh.inc";
?>

<?
putenv("ORACLE_SID=yargitay");
putenv("ORACLE_HOME=/u01/oracle/product/8.0.5");
putenv("LD_LIBRARY_PATH=/u01/oracle/product/8.0.5/lib");
putenv("NLS_LANG=TURKISH_TURKEY.WE8ISO8859P9");

@$id = ora_logon("emsal@y1", "emsal");
if($id == 0){
	exit("Veritabaný bakýmda. Sonra deneyin.");
}	

$cur=ora_open($id);

$query="select 
                metin
                from karar where id= ".$mtn;


$sonuc=ora_parse($cur, $query);
$sonuc=ora_exec($cur);
$i=0;

while($kes=ora_fetch($cur)) {
	$metin=ora_getcolumn($cur, 0);
        /*printf("<pre>".$metin."</pre>"  );*/

	
	/*$nm = explode("\n",*/
	for($i=0;$i<strlen($metin);$i++){
		if(substr($metin,$i,1)=="\n")
			/*printf("<p align=\"justify\">");*/
			printf("<p>");
		else if(substr($metin,$i,1)==" " && substr($metin,$i+1,1)==" ")
				printf("&nbsp;");
		else
			printf(substr($metin,$i,1));
	}
		

	
	echo "<hr>";


	if($i++>20)break;
}
?>

<?
ora_close($cur);
ora_logoff($id);
include "kurumf.inc";
?>

