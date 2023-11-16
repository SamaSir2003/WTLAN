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
    <h1>Welcome <?php echo $_COOKIE['loginname']; ?></h1>

    <?php
    $link = mysqli_connect('localhost', 'root', 'root', "a");

    if (isset($_POST['name'])) {
        setcookie("regd", $_POST["regd"]);
        setcookie("name", $_POST["name"]);
        setcookie("age", $_POST["age"]);
        setcookie("email", $_POST["email"]);
        setcookie("phone", $_POST["phone"]);
        setcookie("subject", $_POST["subject"]);

        mysqli_query($link, "INSERT INTO user VALUES({$_POST['regd']}, '{$_POST['name']}', {$_POST['age']}, '{$_POST['email']}', '{$_POST['phone']}', '{$_POST['subject']}')");
    }
    ?>

    <h1>MYSQL STATUS: <?php echo mysqli_get_host_info($link); ?></h1>

    <form action="" method="post">
        <label for="regd">Reg No</label>
        <input type="number" name="regd" id="regd" required>
        <br>
        <label for="name">Name</label>
        <input type="text" name="name" id="name" required>
        <br>
        <label for="age">Age</label>
        <input type="number" name="age" id="age" required>
        <br>
        <label for="email">Email</label>
        <input type="email" name="email" id="email" required>
        <br>
        <label for="phone">Phone</label>
        <input type="number" maxlength="10" required minlength="10" pattern="[789][0-9]{9}" name="phone" id="phone">
        <br>
        <label for="subject">Subject</label>
        <input type="text" name="subject" id="subject" required>
        <br>
        <button type="submit">Submit</button>
    </form>
</body>

</html>
