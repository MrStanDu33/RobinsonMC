<?php
     date_default_timezone_set('Europe/Paris');
     $date = date('d/m/Y');
     $heure = date('H:m:s');

     $host = "localhost";
     $user = "root";
     $password = null;
     $db = "website";

     try
     {
          $connection = new PDO('mysql:host='.$host.';dbname='.$db.'; charset=utf8', $user, $password, array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8'));
     }
     catch (PDOException $e)
     {
          echo 'UNABLE TO ACCESS THE DATABASE, PLEASE CONTACT AN ADMINISTRATOR';
     }
?>
