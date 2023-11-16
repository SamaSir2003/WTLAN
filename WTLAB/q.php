<!-- Create a login in page that takes username and password to login
use validation on it, after login create a form
taking register number ,name, age, email, phone number, subject
and a submit button to save the given data in database
in form of asynchronous data and show  the cookie, the form should have
validation on each input, E-mail validation,
phone number should be 10 number only and it should start with 7,8,9 only
and there should not be same data in database.
the validation process should be done while entering the data not after submitting it -->


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    if (isset($_POST['name']) && isset($_POST['pwd'])) {
        if ($_POST['pwd'] === $_POST['cpwd']) {
            setcookie("loginname", $_POST["name"]);
            setcookie("loginpwd", $_POST["pwd"]);

            header('Location: qq.php');
        }
    }
    ?>
    <form action="" method="post">
        <label for="name">Name</label>
        <input type="text" name="name" id="name">
        <br>
        <label for="pwd">Password</label>
        <input type="password" name="pwd" id="pwd">
        <br>
        <label for="cpwd">Confirm Password</label>
        <input type="password" name="cpwd" id="cpwd">
        <br>
        <button type="submit">Submit</button>
    </form>
</body>

</html>
