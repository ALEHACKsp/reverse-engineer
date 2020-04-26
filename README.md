# Reverse-engineering Basics
Reverse engineering is the reproduction of another person's product following detailed examination of its construction. In this guide, you will learn the very basics of it.

# First step
First, get IDA (Hex-Rays), located here: https://www.hex-rays.com/products/ida/. This will be the main piece of software that we use.
Next, get the program you want to crack. If you are a beginner, keep your program simple. Example: 
```c++
#include <Windows.h>
#include <iostream>
void main() {
	LPCSTR Password = "q9r03n9x4nqnxnnnar903";
	std::string upassword;
	std::cout << "Enter Password: ";
	std::cin >> upassword;
	if (upassword == Password) {
		MessageBoxA(0, "Correct!", 0, 0);
		exit(0);
	}
	else {
		MessageBoxA(0, "Incorrect!", 0, 0);
		exit(0);
	}
}
```

# Second step
After you obtain IDA and your executable, open up IDA in the arch that you compiled. In this case, we'll assume you compiled in x86. Open up IDA. Click "OK" through the splash screens until you get this:

![IDA Quick Start](https://media.discordapp.net/attachments/669029684524351499/704102284774080512/unknown.png)

Select "Go - Work on your own". Once you are done with that, you should be greated with this screen:

![IDA Drag Screen](https://media.discordapp.net/attachments/669029684524351499/704103154995822682/unknown.png?width=790&height=556)

Here, you want to drag n drop your executable. These are the settings that we will use:

![IDA Settings](https://media.discordapp.net/attachments/669029684524351499/704103471644672061/unknown.png)

If you get a message about the .pdb:
![IDA PDB](https://media.discordapp.net/attachments/669029684524351499/704103952060514334/unknown.png)

Just select no. We won't need it for now.

# Third step
You will now be on the disassembly screen. From here, we want to go into imports.

![IDA IMPORTS](https://media.discordapp.net/attachments/669029684524351499/704104685597884567/unknown.png?width=784&height=557)

Inside of imports, we want to search for our function. In this case, we will simply search up "cin"

![IDA SEARCH](https://media.discordapp.net/attachments/669029684524351499/704104995758276668/unknown.png?width=790&height=557)

Now, you should be in the idata section. Here, you want to move down one line to the extrn *(the pink)*. Right click on it and press Jump to Xref (Cross Reference) to operand.

![IDA IDATA](https://media.discordapp.net/attachments/669029684524351499/704105281696694412/unknown.png?width=790&height=557)

Hopefully you should have one cross reference. If you have more than one, you'll have to look through all of them, and it usually isn't the first one.

![IDA XREF](https://media.discordapp.net/attachments/669029684524351499/704105488283074610/unknown.png?width=786&height=556)

# Fourth step
Now we are on to the actual reverse engineering. Here is what you should see:

![IDA DISASM](https://media.discordapp.net/attachments/669029684524351499/704114164855210034/unknown.png?width=476&height=541)

Now, we want to select :
```
jz short loc_4188DA
```
We want to select this because this is the instruction that jumps to loc_4188DA, aka the incorrect operation.

![IDA ASM](https://media.discordapp.net/attachments/669029684524351499/704114802967970264/unknown.png?width=1145&height=612)

Now, we want to nop the instruction so that it won't jump at all. You could do other stuff instead of nop (No Operation), such as jumping to another function, but we won't do that here. Remember, you want to nop **twice** here. This is what it should look like:

![IDA ADDOUROWN](https://media.discordapp.net/attachments/669029684524351499/704115072062062672/unknown.png)

# Final step
Congratulations! You have reversed this simple program. Now, we want to apply our changes. We want to select patch once more, only this time we want to click apply patches.

![IDA PATCH](https://media.discordapp.net/attachments/669029684524351499/704115369224175746/unknown.png)

Just to be safe, create a backup if you messed up.

![IDA FINAL](https://media.discordapp.net/attachments/669029684524351499/704115560551678042/unknown.png)

And there you have it. Run the executable, type in some random stuff, and you should see that the message box tells you your password was correct!

![IDA YOU ARE DONE](https://media.discordapp.net/attachments/669029684524351499/704117150578901162/unknown.png)

This was a fairly simple tutorial. This tutorial alone wont make you a master, but I hope it got the ball rolling for your passion in reverse engineering.
