# AutoCAD ObjectARX Application - List Objects

## Overview

This ObjectARX application defines a function called `listObjects` that retrieves and displays the class names of all objects in the current space of the AutoCAD drawing. The class names are printed to the AutoCAD Text Window.

## Functionality

The `listObjects` function performs the following steps:

1. **Get the Current Database:**
   - Retrieves the current drawing's database by obtaining a pointer to it.

2. **Get the Current Space Object:**
   - Retrieves the current space object, usually Model Space or Paper Space.

3. **Iterate Through Objects:**
   - Iterates through each object in the current space.

4. **Display Class Names:**
   - For each object, it gets the entity and displays its class name.

5. **Close Entities:**
   - Closes each entity after retrieving and displaying its class name.

6. **Close Current Space Object:**
   - Closes the current space object.

7. **Delete Block Iterator:**
   - Deletes the block iterator object from memory.

8. **Display in AutoCAD Text Window:**
   - Displays the AutoCAD Text Window with the printed class names.

## Usage

1. **Build and Load:**
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the project and load the resulting DLL in AutoCAD.

2. **Run the Command:**
   - In AutoCAD, enter the custom command associated with the `listObjects` function (e.g., "LISTOBJECTS").

3. **View Results:**
   - The function will print the class names of all objects in the current space to the AutoCAD Text Window.
