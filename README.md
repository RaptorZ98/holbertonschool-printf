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
<td>Writes a signed decimal, octal or hexadecimal integer</td>
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
    <td>Writes a hexadecimal integer without the prefix 0x</td>
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
  <td>Used to print pointer type data</td>
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
<td>_printf</td>
<td>g</td>
