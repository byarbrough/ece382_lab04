ece382_lab04
============

"An LCD Device Driver"

##Prelab

The prelab was primarily aimed at understanding and cooperating with the device: what are the max values of a data type, how does the compiler pass in information to Assembly, and how is that information manipulated?

The gollowing summarizes some of what was learned.

###Tables

_Data Types_

|    Size      |    Signed/ Unsigned    |    Type                  |    Min value                     |    Max value                     |
|--------------|------------------------|--------------------------|----------------------------------|----------------------------------|
|    8-bit     |    unsigned            |    unsigned char         |    0                             |    255                           |
|    8-bit     |    signed              |    char                  |    -128                          |    127                           |
|    16-bit    |    unsigned            |    unsigned short        |    0                             |    65,535                        |
|    16-bit    |    signed              |    short                 |    -32,768                       |    32,767                        |
|    32-bit    |    unsigned            |    unsigned long         |    0                             |    4,294,967,295                 |
|    32-bit    |    signed              |    long                  |    -2,147,483,648                |    2,147,483,647                 |
|    64-bit    |    unsigned            |    unsigned long long    |    0                             |    18,446,744,073,709,500,000    |
|    64-bit    |    signed              |    long long             |    -9,223,372,036,854,770,000    |    9,223,372,036,854,770,000     |

_Define Data Types for Bits_

|  Type  | Meaning                 | C typedef   declaration            |
|:------:|-------------------------|------------------------------------|
| int8   | unsigned   8-bit value  | typedef   unsigned char int8       |
| sint8  | signed   8-bit value    | typedef   char sint8               |
| int16  | unsigned   16-bit value | typedef   unsigned short int16;    |
| sint16 | signed   16-bit value   | typedef   short sint16             |
| int32  | unsigned   32-bit value | typedef   unsigned long int32      |
| sint32 | signed   32-bit value   | typedef   long sint32              |
| int64  | unsigned   64-bit value | typedef   unsigned long long int64 |
| sint64 | signed   64-bit value   | typedef   long long int64          |

_Calling/ Return Convention_

| Iteration | a  | b  | c  | d  | e  |
|:---------:|----|----|----|----|----|
| 1st       | 2  | 2  | 3  | 4  | 2  |
| 2nd       | 8  | 9  | 8  | 7  | 8  |
| 3rd       | 14 | 15 | 14 | 13 | 14 |
| 4th       | 20 | 21 | 20 | 19 | 20 |
| 5th       | 26 | 27 | 26 | 25 | 26 |

_Disassembly_

|           Parameter           | Value Sought |
|:-----------------------------:|--------------|
| Starting address of func      | 0xC2CC       |
| Ending address of func        | 0xC2D8       |
| Register holding w            | 12           |
| Register holding x            | 13           |
| Register holding y            | 14           |
| Register holding z            | 15           |
| Register holding return value | 12           |

###Questions

_What is the role of the extern directive in a .c file?_

The _extern_ keyword defines a variable once outside a function - this sets aside storage for it - so it has a larger scope. It then must be delcared within each fucntion that accesses it. In this context it tells the compiler that the function is defined outsied the program (in this case, the .asm file) and to leave an open reference.

_What is the role of the .global directive in an .asm file (used in lines 28-32)?_

The .global notation tells the assembler to leave a reference to this term, which the linker then uses to match the label with the C program.


##Lab Notebook

First and foremost, I want to begin with saying that I really enjoy C. Although some things are a little more tricky than with Java, it was realatively simple to transfer my knowledge of one program to the other. I recieved full A functionality on this lab as well as implemented some bonus functions. Tragically, just as I had the ivnert function working (by passing in a paramater to the Assembly file) my program generated an error with the debugger not finding a .out file. Neither the Instructor nor the interwebs could help me solve this issue. Up unitl that point everything had gone magnificently.

###Layout

Although the program itself actually exists in four files, I made many of the functions visible to each other. As a result, in [lab4.c](https://github.com/byarbrough/ece382_lab04/blob/master/lab4.c) main() would wait for a button push to select the program and then call the appropriate function. These functions were detailed in [implement04.c](https://github.com/byarbrough/ece382_lab04/blob/master/implement04.c) which was linked via the header file: [lab04.h](https://github.com/byarbrough/ece382_lab04/blob/master/lab04.h). Most importantly, because _lab4.c_ declared some functions, such as drawBlock() as external, they had to be foud in some other file. In this case, that was the assmebly file [nokia.asm](https://github.com/byarbrough/ece382_lab04/blob/master/nokia.asm).

Really this creates a lot of work for the compiler and linker, but they typically did a good job as all of the extern and .global labels matched. This creates a rather complicated structure, but this flowchar shows a very simplified version of what was going on.

![alt text](https://dl.dropboxusercontent.com/u/67954924/flowDiagram.jpg "Basic Flow Chart")

####Structures

It is also worth noting that I made use of severl structs and typedefs to construct the ball's characteristics. Also, I made the two colors enumerated. On top of being extremely elegant, doing it like this made changes easy to implement and track. I also think it made coding easier in the long run.

All of my friends were jealous.

###Testing

Testing the code was realatively straightforward since everything could be tested visually. To test the required functionality I first tried to color the entire screen and then erase it. Meanwhile (for the frist few times) I could use a breakpoint at the start of paint() to verify that the x and y coordinates changed. I then just played around and made cool, fun sketches.

For B functionality, it was much of the same: I just let it run.

A functionality requried my equisite reaction time, which of course was no issue. I played some pong! I reused much of the B functionality program which I already knew worked, so I simply had to make a paddle that moved and then test if the ball bounced when it hit the paddle.

####Problems

Of course, testing is never that easy. 

_Required_ 

Well, actually, my panit function worked on the first go. Because I am aweome.

_Bouncing Ball_

The second two took some more effort because I am not always awesome. One major problem I had was with bounce(). I typically pass coordinates as (x, y), but the assembly function requires r12 to be y and r13 to be x. This translates to (y, x) in C. Once I figured this error out things were pretty simple for bounce.

_Pong_

Having the bounce prgoram working - as well as my incredible design - made writing pong() simple. I just added a paddle and modified the conditions under which bounce() was called. I did have a decision to make about how the button was pressed and the paddle moved. I ended up allowing the user to hold down the button to move the paddle. This generates a somewhat jerky movement, but is better than completely pausing the game while the processor waits for the release. Because there is a delay before redrawing the screen, it isn't too ridiculously fast. An interupt might be better, but I was workign with what I had.

###Bonus Functionality

As I said before, I was having a lot of fun with this. The first bonus I did was actually to make testing easier on myself: when the program starts, the user can choose which game mode to play. UP for Paint, LEFT for Bounce, and DOWN for Pong. This meant that I did not have to comment out larger segments of code or debug different files. Furthermore it proved the versatility of my design.

The second functionality was because I am somewhat ADHD and thought that the ball was bouncing too slow. So I added that pressing UP speeds up the ball and DOWN slows it down. This was acomplished by dividing a delay time by the _speed_ paramater which was in turn changed by button presses.

Finally, I had the invert functinoality almost workign when the devestation previously mentioned set in. I had rewrittedn a piece of the Paint program to pass a parameter into assembly which set the design of the ball and the background. This was kind of cool beause I could do any symetric pattern. I had to do a little debugging with clearDisplay() to find out where exactly the data byte was passed to, but other than that it worked great! Unfortunately, before I could test it on Pong, I got the .out error. And I could not find anything on Google or from my instructor to remedey it. _I am almsot positive that my code works._

###Documentation
Seeing as the interwebs weren't as helpful as I would have liked... NONE.
