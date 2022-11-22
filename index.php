<html>
<head>
	<meta name="viewport" content="width=device-width"/>
	<title>Raspberry Pi Controlando lâmpada</title>
</head>
<body>
	<center><h1>Controle Lâmpada usando Raspberry Pi WebServer</h1>
	<form method="get" action="index.php">	
	<input type="submit" style="font-size: 14pt" value="OFF" name="off">
	<input type="submit" style="font-size:14pt" value="ON" name="on">
    </form>
   </center>

<?php
  shell_exec("/usr/local/bin/gpio -g mode 27 out");
  if(iseet($_GET['off']))
  {
  	echo "Lâmpada Ligada";
  	shell_exec("/usr/local/bin/gpio -g write 27 0");
  }
  else if(isset($_GET['on']))
  {
  	echo "Lâmpada Desligada"
  	shell_exec("/usr/local/bin/gpio -g write 27 1");
  }

?>
</body>
</html>