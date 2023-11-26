# AutoCAD ObjectARX Application - Hello World

## Overview

This ObjectARX application defines a custom command, "MYCOMMAND," that displays the message "Hello <Name> in the world of AutoCAD" when the user enters the command in the AutoCAD command line.

## Initialization

1. **Unlock and Register as MDI Aware:**
   - The application is unlocked and registered as MDI (Multiple Document Interface) aware.

2. **Print Initialization Message:**
   - Prints a message to the AutoCAD command line, indicating that the application has been loaded.

3. **Register New Modal Command:**
   - Registers a new modal command named "MYCOMMAND" in the "MyGroup" group.
   - Associates the command with the `MyCommand` function in the `CProject3App` class.

## Custom Command - MyCommand

The `MyCommand` function defines the behavior of the custom command "MYCOMMAND." When executed, it prints the message "Hello in the World of AutoCAD" to the AutoCAD command line.

## Unload

1. **Print Unload Message:**
   - Prints a message to the AutoCAD command line, indicating that the application is being unloaded.

## Usage

1. **Build and Load:**
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the project and load the resulting DLL in AutoCAD.

2. **Run the Command:**
   - In AutoCAD, enter the custom command "MYCOMMAND" in the AutoCAD command line.

3. **View Results:**
   - The command will print the message "Hello in the World of AutoCAD" to the AutoCAD command line.
