 #!/bin/bash

 while [ 1 ]
 do

     echo "Wakeup [yes/no]?“
     read resp

        if [ $resp = "yes" ]
        then
              exit
        fi
 done

 echo “Out of while loop”
 echo “Terminating shell script”