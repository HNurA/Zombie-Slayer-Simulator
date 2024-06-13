[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/4OjENvBl)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=14943699&assignment_repo_type=AssignmentRepo)
# sysprog24-lab9: Zombie Slayer Simulator


# Learning Objectives



* Concurrency


# Introduction

You along, with a few of your friends, are cleaning out a zombie invasion.  You only have 3 weapons though (3 people can kill zombies).  

After analyzing the situation, you have come up with an amazing plan.  

You want to secure a large room that has multiple doors to the street. Zombies move slowly, so it’s easy to control them in general.  Each of your friends controls one door (doormen).  They let in individual zombies, keeping count of how many have entered. ** You and 2** of your friends (there are only 3 weapons, 3 zombie slayers) stand in the center and eliminate the zombies that have entered as fast as you can, keeping track of how many each of you have removed.

You don’t want too many zombies in the room for obvious reasons.  All of you die if there are more than 100 zombies in the room at any point in time.  You and your friends are safe if you can kill 100 zombies in total before getting killed. The only way to achieve this goal is to find a room with just enough doors to the street. 

The objective of this hw is to write code to find the maximum number of doors (door men) that would allow you and your two friends to kill 100 zombies before you get killed. 


# Details

Simulate the zombie cleaning activity as a multi-threaded program. You should have multiple threads, 3 representing you and 2 of your friends (3 slayers) and one for each friend controlling a door (doorMan).  



* <strong><code>void zombieEntered()</code>:</strong> Keeps track of number of zombies entered.
* <strong><code>void zombieKilled()</code>:</strong> Keeps track of number of zombies killed.
* <strong><code>int tooManyZombiesInTheRoom()</code>:</strong> Returns <code>true</code> if the number of zombies in the room are greater than or equal to 100.
* <strong><code>int killed100Zombies()</code>: </strong>Returns <code>true</code> if more than 100 zombies have been killed.
* <strong><code>int zombiesExist()</code>;</strong> Returns <code>true</code> if there is at least one zombie in the room.
* <strong><code>int getKilledCount()</code>;</strong> Returns the number of zombies killed.
* <strong><code>int getInTheRoomCount()</code>;</strong> Returns the number of zombies in the room.

Since multiple threads access these functions, you want the counts to be consistent. You do not want any thread to get an inconsistent view of the data being accessed.



* <strong><code>void *doorMan(void *);</code></strong>

Each DoorMan thread lets in a zombie with a 50% chance <strong>every 2ms</strong>, keeping track of the number of zombies admitted (by calling the corresponding functions from the ZombieCounter). The DoorMan thread terminates if there are too many zombies (more than 100 zombies) in the room at any time or if the Slayer has killed more than 100 zombies. 



* <strong><code>void *slayer(void *);</code></strong>

The Slayer kills a zombie <strong>every 2ms</strong> (but he/she has to check first to see if there is a zombie) keeping track of the number of zombies killed (by calling corresponding function). The Slayer thread terminates if  there are too many zombies (more than 100 zombies) in the room at any time or if 100 or more zombies are killed.



* **``int main();``**

The main function creates <code>n</code> <code>doorMan</code></strong> threads (<strong>n</strong> is taken in as a command line argument) and <strong>3</strong> <strong><code>slayer</code></strong> thread.  When all the threads complete their execution, 



* the main thread checks and prints if you have killed 100 zombies or have been killed by the zombies. 
* And prints the number of zombies each thread has killed. 


### Optimal number for the doormen

Run the program several times. Vary the number of doormen each time. Find the largest number of door men for which you successfully eliminate 100 zombies without getting killed.

**Submission**

Submit zombie.c


# **Grading**

DoorMan: ~18%

Slayer: ~24%

Simulator (main): ~24%

The rest 34%
