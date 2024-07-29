# PUSH_SWAP

<p>
  <b><a href="https://github.com/NicoleLehmeyer/PUSH_SWAP/blob/main/subject/PUSHSWAP_SUBJECT.pdf">'push_swap'</a> is a 42 project which requires creating a project which calculates and displays on stdout, the smallest list of instructions (allowed pushswap operations used to manipulate the stacks), which sorts integers received as arguments, across 2 stacks.</b><br><br>
  <b>pushswap Grade: 100%</b>
  <br>
  <br>
  <br>
  <b>Requirements:</b><br><br>
  The program must sort a list of integers in ascending order, using the allowed 'operations' to organise the integers across two stacks, <b>'stack a'</b> and <b>'stack b'</b>.<br><br>
  The integers to be sorted must be firstly placed in 'stack a', with the first argument at the top of the stack. 'stack b' begins empty.<br><br>
  <b>The sort is to be completed within the maximum number of operations:</b><br>
  - Sort 3 values in <= 3 operations<br>
  - Sort 5 values in <= 12 operations<br>
  - Sort 100 values in <= 700 operations (for 100% project validation)<br>
  - Sort 500 values in <= 5500 operations (for 100% project validation)<br><br>
  <b>The allowed operations are as follows:</b><br>
  - <code>sa</code>: <code>(swap a)</code> Swap top 2 elements in stack <code>a</code><br>
  - <code>sb</code>: <code>(swap b)</code> Swap top 2 elements in stack <code>a</code><br>
  - <code>ss</code>: <code>sa</code> & <code>sb</code> simultaneously<br>
  - <code>pa</code>: <code>(push a)</code> Move element at top of <code>b</code> and place on top of <code>a</code><br>
  - <code>pb</code>: <code>(push b)</code> Move element at top of <code>a</code> and place on top of <code>b</code><br>
  - <code>ra</code>: <code>(rotate a)</code> Shift up all elements in stack <code>a</code>. First element becomes the last.<br>
  - <code>rb</code>: <code>(rotate b)</code> Shift up all elements in stack <code>b</code>. First element becomes the last.<br>
  - <code>rr</code>: <code>ra</code> & <code>rb</code> simultaneously<br>
  - <code>rrb</code>: <code>(reverse rotate b)</code> Shift down all elements in stack <code>b</code>. Last element becomes the first.<br>
  - <code>rra</code>: <code>(reverse rotate a)</code> Shift down all elements in stack <code>a</code>. Last element becomes the first.<br>
  - <code>rrr</code>: <code>rra</code> & <code>rrb</code> simultaneously<br>
  <br>
  List of operations executed must display in the standard output, each seperated by a newline character.<br>


  Use of <a href="https://github.com/NicoleLehmeyer/LIBFT">libft</a> is permitted.<br><br>
  No global variables permitted.<br><br>
  Program must be written in C, and <a href="https://github.com/NicoleLehmeyer/LIBFT/blob/main/subject/norme.pdf">Norminette</a> (42 organisational syntax) compliant, without seg fault/bus error/double free etc.
  <br>
  <br>
  <br>
  <b>PushSwap Method:</b><br>
  1.  Process arguments: Return error if argument format is incorrect (ie. non-number, non-sign characters) or duplicates are present, handle '+' and '-', and handle if args are written in "", ie. "20 -3 80".<br>
  2.  Initialise stacks & fill 'stack a'<br>
  3.  PUSH SWAP SORT: (a) small sorts for 2 & 3 integers. (b) big sort (as written below) for < 3 integers<br>
  4.  Free stacks<br>
  <br>
  <b>Big Sort Method:</b><br>
  1.  Push all but 3 integers to 'stack b'<br>
  2.  Small sort on 'stack a' to create an ascending order<br>
  3.  For each integer in 'stack b', assign: (1) target position - position in 'stack a' with value of next lowest value, (2) cost - lowest number of moves to get 'stack b' integer to its target position in 'stack a'.<br>
  4.  Execute the sequence of operations for the 'stack b' integer with the 'cheapest' move number to get to its target position.<br>
  5.  Repeat until there are no values in 'stack b', then ra/rra (dependent on if smallest int is in top or bottom half of the stack) until the smallest value is at the top of the stack.<br>
  <br>
  <br>
</p>

## Run Program:

Create executables: ```make```

Run program: ```ARG="<integers seperated by ' ' character>; ./push_swap $ARG```

ie.: ```ARG=""54 32 0 67 88 -1234 51 567"; ./push_swap $ARG```

Run program with checker: ```ARG="<integers seperated by ' ' character>"; ./push_swap $ARG | ./checker_mac $ARG:```

ie. ```ARG="54 32 0 67 88 -1234 51 567"; ./push_swap $ARG | ./checker_mac $ARG```

My friend Nate created a fantastic push_swap checker, which can be used on my program with: ```./push_swap_tester.sh```

<p>
Check out Nate's github <a href="https://github.com/redback0">here</a>.
</p>

You may also specify number of integers to test with and how many times you wish to test: ```./push_swap_tester.sh <no. of integers> -r <no. of tests run>```

ie. ```./push_swap_tester.sh 100 -r 200``` (run program with 100 integers, 200 times)

<b>**Ensure to ```chmod 777``` 'checker_Mac' and 'push_swap_tester.sh'**</b>

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
