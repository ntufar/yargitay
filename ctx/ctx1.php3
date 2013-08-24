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

$query1="select ctxseq.nextval from dual";
$sonuc=ora_parse($cur, $query1);
$sonuc=ora_exec($cur);
ora_fetch($cur);
$idno=ora_getcolumn($cur, 0);

$query1="begin :count := ctx_query.count_hits('ctxkarar','".$text."',TRUE);end;";
$sonuc=ora_parse($cur, $query1);
$sonuc=ora_bind($cur, "cnt", ":count" , 10, 2);
$sonuc=ora_exec($cur);
/*ora_fetch($cur);*/
/*$count=ora_getcolumn($cur, 0);*/

printf($cnt." dosya bulunmuþtur");


$query1="begin ctx_query.contains('ctxkarar','".$text."','ctx_temp',1,".$idno.");end;";
$query2="select 
                ctx_temp.TEXTKEY, ctx_temp.SCORE, karar.daireno,
		karar.esasno, karar.kararno
                from ctx_temp, karar WHERE ctx_temp.CONID=".$idno." and
		ctx_temp.textkey = karar.id order by ctx_temp.score desc";


$sonuc=ora_parse($cur, $query1);
$sonuc=ora_exec($cur);

/*------------------------------------------
$query1="begin ctx_query.highlight(cspec => 'ctxkarar', textkey => ".$idno.", query => '".$text."',id=>".$idno."
,hightab => 'highlight_ascii',mutab   => 'mu_ascii');end;";
$sonuc=ora_parse($cur, $query1);
$sonuc=ora_exec($cur);
 
------------------------------------------*/


$sonuc=ora_parse($cur, $query2);
$sonuc=ora_exec($cur);
$i=0;

printf("<table>");
printf("<tr><td><b>%%</td><td><b>Daire</b></td>
<td><b>Esas numarasý</b></td><td><b>Karar numarasý</b></td></tr>");
while($kes=ora_fetch($cur)) {
	$textkey=ora_getcolumn($cur, 0);
	$score=ora_getcolumn($cur, 1);
	$daireno=ora_getcolumn($cur, 2);
	$esasno=ora_getcolumn($cur, 3);
	$kararno=ora_getcolumn($cur, 4);
        printf("<tr><td><a href=\"ctx2.php3?mtn=".$textkey."\">".$score."
        </td><td>".$daireno."</td><td>".$esasno."</td><td>".$kararno."</td></tr></a>");
	
	/*printf("<a href=\"ctx2.php3?mtn=".$textkey."\">".$score."</a> ");*/

	

	


	$i++;
}
printf("</table>" );
if($i==0)
	printf("Bu kelime içeren karar bulunmamýþtýr");

?>

<?
/*$query1="delete from ctx_temp where conid=".$idno;
$sonuc=ora_parse($cur, $query1);
$sonuc=ora_exec($cur);
$sonuc=Ora_Commit($id);*/
ora_close($cur);
ora_logoff($id);
include "kurumf.inc";
?>

