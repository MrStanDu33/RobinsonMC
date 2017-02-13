<?php
include('include/init.php');

     if ($_POST)
     {
          $pseudo   = $_POST['pseudo'];
          $password = md5($_POST['password']);

          $req_nbrMembre = $connection->prepare('SELECT * FROM member WHERE pseudo=:pseudo AND password=:password');
          $req_nbrMembre->execute(array(
               'pseudo'  => $pseudo,
               'password'=> $password
          ));
          $nbrMembre = $req_nbrMembre->rowcount();
          if ($nbrMembre>0)
          {
               echo ('Bienvenue '.$pseudo.' !');
          }
     }

?>


<form method="post">
     Pseudo : <input type="text" name="pseudo"><br>
     Mot De Passe : <input type="password" name="password"><br>
     <input type="submit" value="Connectez-vous">
</form>
