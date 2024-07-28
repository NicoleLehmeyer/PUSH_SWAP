# PUSH_SWAP

<p>
  <b><a href="https://github.com/NicoleLehmeyer/PUSH_SWAP/blob/main/subject/PUSHSWAP_SUBJECT.pdf">'push_swap'</a> is a 42 project which requires creating a project which calculates and displays on stdout, the smallest list of instructions (allowed pushswap operations used to manipulate the stacks), which sorts integers received as arguments, across 2 stacks.</b><br><br>
  <b>pushswap Grade: 100%</b>
  <br>
  <br>
  <br>
  <b>Requirements:</b><br><br>
  The program must sort a list of integers in ascending order, using the allowed 'moves' to organise the integers across two stacks, 'stack a' and 'stack b'.<br><br>
  The integers to be sorted must be firstly placed in 'stack a', with the first argument at the top of the stack.<br><br>
  The sort is to be completed within the maximum number of operations:<br>
  - Sort 3 values in <= 3 operations<br>
  - Sort 5 values in <= 12 operations<br>
  - Sort 100 values in <= 700 operations (for 100% project validation)<br>
  - Sort 500 values in <= 5500 operations (for 100% project validation)<br><br>
  The allowed operations are as follows:<br>
  - <code>sa</code> <code>(swap a)</code>: Swap top 2 elements in stack <code>a</code><br>
  - <code>sb (swap b)</code>: <br>
  - <code>ss</code>: <code>sa</code> & <code>sb</code> simultaneously<br>
  - <code>pa</code>: <br>

  Across<br><br>
  May only use 2 signals - SIGUSR1 & SIGUSR2.<br><br>
  The client must send the string to the server, and the server must print this string... quickly.<br><br>
  Use of <a href="https://github.com/NicoleLehmeyer/LIBFT">libft</a> is permitted.<br><br>
  Use of one global variable is allowed. Program must be written in C, and <a href="https://github.com/NicoleLehmeyer/LIBFT/blob/main/subject/norme.pdf">Norminette</a> (42 organisational syntax) compliant, without seg fault/bus error/double free etc.
  <br>
  <br>
  <br>
  <b>Method:</b><br><br>
  1.  Client converts the inputted characters to bits, sending them to the server using SIGUSR1 if bit is a 1, or SIGUSR2 if bit is 0, for 8 bits (equiv. to char)<br><br>
  2.  Server receives signals, storing the bits in variable 'g_store' until until 8 bits been received. This is then printed in the output in the server's main function.<br><br>
  <br>
</p>

## Run Program:

Create executables: ```make```

Run server in one terminal: ```./server```

Run client in another terminal: ```./client <server_PID> <string__to_send>```
<p>
  <br>
</p>

---
<p align="center">
Made by NicoleLehmeyer: nlehmeye@student.42adel.org.au | LinkedIn: <a href="https://www.linkedin.com/in/nicole-lehmeyer/">nicole-lehmeyer</a> | Discord: <a href="https://discordapp.com/users/1107446949344448543/">nicole.lehmeyer</a>
</p>

<p align="center">
  <img src="https://github.com/NicoleLehmeyer/NicoleLehmeyer/blob/main/images/coder_hampster.png" alt="hampster" style="width:100px;"/>
</p>
