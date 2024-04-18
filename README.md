# **PUSH_SWAP**

"This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions."

## **_CONTENT_**

- [PUSH_SWAP_PROJECT](#PUSH_SWAP_PROJECT)
- [PUSH_SWAP_ALGORITHM](#PUSH_SWAP_ALGORITHM)
- [USAGE](#USAGE)


<details close>
  <summary><h3>PUSH_SWAP_PROJECT</h3></summary>

  :page_facing_up: [push_swap subject EN [PDF]](en.subject.pdf)
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.

You have at your disposal a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.

Sorting values is simple. To sort them the fastest way possible is less simple. Especially

because from one integers configuration to another, the most efficient sorting solution can

differ.


• You have 2 stacks named a and b.

• At the beginning:

◦ The stack a contains a random amount of negative and/or positive numbers

which cannot be duplicated.

◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the

following operations at your disposal:

  sa (swap a): Swap the first 2 elements at the top of stack a.


  sb (swap b): Swap the first 2 elements at the top of stack b.


  ss: sa and sb at the same time.

  
  pa (push a): Take the first element at the top of b and put it at the top of a.


  pb (push b): Take the first element at the top of a and put it at the top of b.


  ra (rotate a): Shift up all elements of stack a by 1. (The first element becomes the last one. "roates clockwise")


  rb (rotate b): Shift up all elements of stack b by 1.

      
  rr: ra and rb at the same time.

  
  rra (reverse rotate a): Shift down all elements of stack a by 1. (The last element becomes the first one. "rotates counterclockwise")

  
  rrb (reverse rotate b): Shift down all elements of stack b by 1.

  
  rrr: rra and rrb at the same time.

  
  In case of error, it must display "Error" followed by a ’\n’ on the standard error.

    Errors include for example: 
     # some arguments aren’t integers, 
     # some arguments are bigger than an integer
     # there are duplicates
</details>
<details close>
  <summary><h3>PUSH_SWAP_ALGORITHM</h3></summary>
 
  To complete this project I use the turk algorithm, after some research I saw that this algorithm uses the less movements to complete the task.

  https://medium.com/@ayogun/push-swap-c1f5d2d41e97
</details>

<details open>
  <summary><h3>USAGE</h3></summary>

1. Clone repository

 ```bash
    git clone git@github.com:mfortuna23/push_swap.git 
  ```

2. Go inside project directory and run `make`
 ```bash
    cd push_swap
    make
 ```
    
3. Execute the program and give the argumens that you want

```bash
    ./push_swap "5 9 3 7"
```
>> if you would like to know how many moves it took use "| wc -l"
```bash
    ./push_swap "5 9 3 7" | wc -l
```
![push_swap](https://github.com/mfortuna23/push_swap/assets/147384586/e1117b60-a060-458f-aaf3-8b89133c38a9)
the best random number calculator that I could find: https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php

</details>
