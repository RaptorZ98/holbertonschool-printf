<h1 align = "center"> Printf project </h1>

<h2>Description.</h2>

The printf function is used to print a string of characters and give a specific format to the text. When using this function, you must provide a character string that contains both the text to be printed and the desired formatting. In addition to formatting, the printf function can accept other parameters, such as integers, text strings, characters, hexadecimal integer, format specifier, among others.

<h2>Function</h2>

<table>
<tr>
<td>Character</td>
<td>Meaning</td>
</tr>
<tr>
<td>c</td>
<td>Write a simple character</td>
</tr>
<tr>
<td>s</td>
<td>Type a string of characters</td>
</tr>
<tr>
<td>'%'</td>
<td>prints a percentage</td>
</tr>
<tr>
<td>d</td>
<td>Write a signed decimal integer</td>
</tr>
<tr>
<td>i</td>
<td>print integer</td>
</tr>
<tr>
  <td>b</td>
<td>prints a numbers in binary</td>
  </tr>
  <tr>
    <td>u</td>
    <td>Writes an unsigned decimal integer</td>
  </tr>
  <tr>
  <td>o</td>
  <td>Writes an octal integer, without a leading zero</td>
  </tr>
  <tr>
    <td>x</td>
    <td>It is a specifier to print a value in hexadecimal format in lowercase.</td>
  </tr>
  <tr>
    <td>X</td>
    <td>Is a specifier to print a value in hexadecimal format in uppercase letters.</td>
  </tr>
  <tr>
    <td>S</td>
    <td>Generates an array of characters and replaces any character that cannot be printed with its hexadecimal representation</td>
  </tr>
  <tr>
  <td>p</td>
  <td>indicates that the next argument in the argument list is a pointer and that its memory address is to be displayed in hexadecimal format./td>
  </tr>
  <tr>
    <td>r</td>
    <td>prints a string but in reverse</td>
  </tr>
  <tr>
  <td>R</td>
  <td>prints the string but with rot13'ed</td>
</table>

<h2>Printf procedure</h2>

<p>This function accepts an array of characters along with other arguments to print, and then processes the array of characters. During the process, each character is checked and a decision is made on how to handle it. The function returns the number of characters printed.

While traversing the character array, the function checks if the current character is a percent sign (%). If it is not, it simply prints the current character and adds one to the counter. If the character is a percent sign, the function checks if the next character is also a percent sign. If it is, it just prints a percent sign and adds one to the counter. If the next character is not a percent sign, the function calls another function to make a decision on how to handle the character following the percent sign.

The code looks for a match between the available formatting functions (the printf functions) and the character following the percent sign. If it finds a match, the corresponding function is called to print the given arguments. If there is no match, it simply prints the percent sign and the next character. Each formatting function also returns the number of characters printed, which are added to the main counter.

The function continues to process the formatting array until it encounters a null character, which indicates the end of the array.</p>

<h2>Flowcharts</h2>

[![Printf.png](https://i.postimg.cc/PfpDg93Y/Printf.png)](https://postimg.cc/grprRSP2)

<h2>Contents of the folders</h2>
<table>
<tr>
<td>Files</td>
<td>Description</td>
</tr>
<tr>
<td>_printf.c</td>
<td>Such a folder contains the main function, which parses the string to identify formatting options, calls other functions (read_format) to process the arguments and finally prints the output string to the console.</td>
  </tr>
<tr>
  <td>read_form.c</td>
  <td>Such a folder contains two functions, "read_format" and "read_porcent".
the first function is in charge of reading the format and processing it to print the corresponding values. if the current character is a '%' the function "read_porcent" is called to process the corresponding conversion.
The second function searches for the corresponding conversion type in a list of options and calls the corresponding function to process the variable argument. If no corresponding conversion is found, a generic function is called to print the character '%' and any other characters following it.</td>
  </tr>
  <tr>
  <td>main.h</td>
  <td>this file defines the "printf" function that supports a set of print formats and provides auxiliary functions such as "get_num", "check_buff", among others that are used to read, format and store the function arguments.  In addition, the file defines two structures, "Buff" and "les", which are used to store and manage the data.</td>
  </tr>
  <tr>
  <td>buffer_functions.c</td>
  <td>this file contains two functions, "check_buff" and "add_buff", which operate on a structure called Buff.
The "check_buff" function checks if the buffer is full and the "add_buff" function adds the character 'a' to the buffer at the current position pos, and then increases pos by 1.</td>
  </tr>
  <tr>
  <td>conversions.c</td>
  <td>This file defines some functions that convert an unsigned number to a string representation. In particular, the functions "get_u", "get_o", "get_x", "get_X," and "get_b". are defined, each of which converts the number into a different format: unsigned decimal (get_u), octal (get_o), lowercase hexadecimal (get_x), uppercase hexadecimal (get_X) and converts an unsigned integer into its binary representation and adds it to the buffer (get_b).</td>
  </tr>
  <tr>
  <td>aux_fuctions.c</td>
  <td>This file contains functions for manipulating strings and appending text to a buffer. The "get_letter" function is used to get a letter from a numeric value and an additional parameter. The other two functions "print_nill" is used to print the word "nil" if the passed value is null and print_assi for assigned numbers.</td>
  </tr>
  <tr>
  <td>mandatory_functions.c</td>
  <td>The file contains functions and a variable list of arguments, and produces a string from them.
It consists of three functions: "get_c", "get_s" and "get_d". The 'get_c' function adds a character to the buffer structure. The 'get_s' function adds a string to the buffer structure and the 'get_d' function adds an integer to the buffer structure.</td>
  </tr>
  <tr>
  <td>percentage_behaviour.c</td>
  <td>Such a file contains three functions, the first function, "get_per", simply adds the character '%' to the buffer and checks if it is full. The second function, "get_white", adds a blank space to the buffer and also checks if it is full. The third function, "get_param", adds a '%' character and the character corresponding to the "i" position of the string "format" to the buffer and then checks if it is full.</td>
  </tr>
  <tr>
  <td>str_conversions.c</td>
  <td>This file contains two functions "str_rev" and "rot_print", both functions accept a list of parameters and a buffer structure.
The first one inverts a text string and adds it to the buff output buffer and the second one encodes a text string in the format "rot13" and adds it to the buff output buffer.</td>
  </tr>
  <tr>
    <td>more_conversions.c</td>
    <td>Such a file contains three functions, the "get_p" function converts a memory address value to its hexadecimal representation, the "get_hex" function is used to print a character string in hexadecimal format and the "make_hex" function converts a numeric value to its hexadecimal representation.</td>
  </table>

  <h2>Authors</h2>
<h4><a href="https://github.com/RaptorZ98"target="_blank">Federico Heuer</a></h4>
<h4><a href="https://github.com/20Emi"target="_blank">Emily Sánchez</a></h4>
