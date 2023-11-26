# AutoLISP Library - Mathematical and Alert Functions using AutoLISP

## Overview

This AutoLISP library enhances AutoLISP capabilities in AutoCAD by providing additional mathematical functions and an extended alert function.

## Constants and Macros

1. **Pi Constant:**
   - Defines a constant named `PI` representing the mathematical value of pi.

2. **Array Element Count Macro:**
   - Provides a macro to calculate the number of elements in an array.

## Function Definitions

The library includes several functions:

1. **Mathematical Functions:**
   - Tangent function
   - Conversion functions for degrees to radians and radians to degrees.

## AutoLISP Integration

1. **Function Table:**
   - Organizes functions in a table for easy use in AutoLISP commands.

2. **Loading Functions into AutoCAD:**
   - Provides functions to load the mathematical functions into AutoCAD for use in AutoLISP.

3. **Execution from AutoLISP:**
   - Enables the execution of functions from AutoLISP by calling them.

## Extended Alert Function

1. **Customizable Message Boxes:**
   - Introduces an extended alert function that allows showing customizable message boxes.
   - Options include message, caption, buttons, and icons.

## Usage

1. **Load the Library:**
   - Load the AutoLISP library into AutoCAD using the "APPLOAD" command.

2. **Use Mathematical Functions:**
   - Utilize the provided mathematical functions in your AutoLISP commands.

3. **Display Customizable Alerts:**
   - Use the extended alert function to display customizable message boxes.

## Example

```autocad
Command: (load "AutoLISPLibrary")
Command: (setq result (tangent 45))
Alert: (extended-alert "Hello AutoCAD!" :caption "Custom Alert" :buttons '(:ok :cancel) :icon :warning)
