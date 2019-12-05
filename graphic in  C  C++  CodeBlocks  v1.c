/*

Graphic in C, C++, CodeBlocks v1.c


Graphic in C, C++, CodeBlocks:

Note also that initgraph() and the other graphic functions belonged to the
ancient Turbo-C/C++ compilers for MS-DOS. Using those nowadays via WinBGIm
is not the best choice to learn graphics programming.

Graphics-Library for C/C++ in CodeBlocks

How to use graphics in CodeBlocks?

https://www.google.com/search?q=how+to+use+graphics+in+codeblocks&rlz=1C1PRFC_enRS707RS707&oq=how+to+graphics+in+c+codebloks&aqs=chrome.2.69i57j0l5.27373j1j7&sourceid=chrome&ie=UTF-8

https://medium.com/@sagarganiga468/use-graphics-h-in-code-blocks-fe6ae3d8d4c2

https://github.com/SagarGaniga/Graphics-Library

https://codeload.github.com/SagarGaniga/Graphics-Library/zip/master

https://www.codeproject.com/Questions/1255636/Using-graphics-h-in-codeblocks

https://github.com/SagarGaniga/computer-graphics

Graphics-Library
Download required libraries from
https://github.com/SagarGaniga/Graphics-Library

It is a tradition to use Turbo C for graphic in C/CPP.
But it's also a pain in the neck.

Here we are using Code::Blocks IDE, which will ease out our work.

Steps to run graphic code in CodeBlocks

1. Install Code::Blocks
Make sure you have installed Code::Blocks IDE on your machine.
If you don't have this IDE or have any issue with compiler download and install it from here.
http://sourceforge.net/projects/codeblocks/files/Binaries/16.01/Windows/codeblocks-16.01mingw-setup.exe

2. Download the required header files
We need few files to be included in the lib folder of Code::Blocks.
Download the files from here
https://github.com/SagarGaniga/Graphics-Library

3. Include graphics.h and winbgim.h
Copy and Paste the graphics.h and winbgim.h files into include folder of Code::Blocks directory.
Path: C:\Program Files (x86)\CodeBlocks\MinGW\include

4. Include libbgi.a
Copy and paste libbgi.a file in the lib folder of Code:Blocks
Path: C:\Program Files (x86)\CodeBlocks\MinGW\lib

5. Add Link Libraries in Linker Setting
In the Code::Blocks application go to, Settings > Compiler
In the Global Compiler setting, click on the Linker Settings
In Link Libraries, Add and browse to C:\Program Files (x86)\CodeBlocks\MinGW\lib\ and select libbgi.a.
Paste this in the Other Linker Option tab of Linker Settings (i.e. on the right-hand side)
-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

Save the setting and restart the application

To test the setting copy paste any computer graphics code from
https://github.com/SagarGaniga/computer-graphics

Note:
Save code in cpp extension !

Don’t forget to include graphics.h

Enjoy Computer Graphics :)

https://www.codeproject.com/Questions/1255636/Using-graphics-h-in-codeblocks
I am getting warning: Deprecated conversion from string constant to char Pass NULL instead of an empty string. The reason you got this warning (it is a warning and not an error) is that you pass a string literal which is const by definition but the function parameter is not const (char *).
Note also that initgraph() and the other graphic functions belonged to the
ancient Turbo-C/C++ compilers for MS-DOS. Using those nowadays via WinBGIm is
not the best choice to learn graphics programming.

*/

#include<stdio.h>
#include<graphics.h>

int main(void)
{
   int gd=0,gm;

   initgraph(&gd,&gm,NULL);

   circle(100,80,30);

   getch();
   closegraph();
}
