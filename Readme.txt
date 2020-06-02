In this project the usere have 3 modes
1) The user can use the data from the file name Data_File.txt which consist 
of priority and process brust time
command: press "f"
2) The user can use generate random process and random priority
command: press "r"
3) The user can manually enter the burst time and the priority
command: press "m"

The user will be able to create up to 10 process. I decided to limit the number
of process so that it will be easier to understand and analize how the scheduling
works

For the Quantum time: Its better to set the Quantum between 20-50. Setting too 
short quantum time causes to many process switches and setting too many will
cause poor response to short interactive request.

****IF THE FILE DOESNOT OPEN*****
This could happen due to the change of location
Go to properties of the file and copy the path of the file and paste it 
here in the code
ifstream infile( file path )



