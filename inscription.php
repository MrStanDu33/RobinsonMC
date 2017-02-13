<?php
     include('include/init.php');

     if ($_POST)
     {
          $pseudo   = htmlspecialchars($_POST['pseudo'], ENT_QUOTES);
          $password = md5($_POST['password']);
          $mail     = htmlspecialchars($_POST['email'], ENT_QUOTES);
          $session  = md5(rand());
          $addMembre= $connection->prepare('INSERT INTO member SET pseudo=:pseudo, password=:password, email=:email, session=:session');
          $addMembre->execute(array(
               'pseudo'  => $pseudo,
               'password'=> $password,
               'email'   => $mail,
               'session' => $session
          ));
     }
?>

<form method="post">
     Pseudo : <input type="text" name="pseudo"><br>
     Mot De Passe : <input type="password" name="password"><br>
     Adresse Mail : <input type="text" name="email"><br>
     <input type="submit" value="Inscrivez-vous">
</form>
