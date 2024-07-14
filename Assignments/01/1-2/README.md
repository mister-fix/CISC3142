# Instructions

Write a C++ program to do the following:

- Load up an array of names from the files `names.data`
  - Assigns integer id's to each name, starting at 1001, and in the order in which they are read from the fiel (so the first name would assigned 1001, the second 1002, etc.).
    - We don't have classes yet, so use *parallel arrays*, i.e., two arrays of the same capacity, the first contianing the names, the second with the corresponding id.
- Sort the arrays by name.
- Write the sorted data to the file `results.data`, each name / id pair on a separate line

**Sample Test Run #1**
For example if the file `names.data` contains:

```plaintext
Langsam
Tenenbaum
Arnow
Weiss
Cox
```

upon program termination, the console output should be:

```plaintext
5 records processed
```

the file `results.data` should contain:

```plaintext
Arnow 1003
Cox 1005
Langsam 1001
Tenenbaum 1002
Weiss 1004
```

and the exit code should be 0.

**Sample Test Run #2**
If the file `names.data` did not exist, the console output should be:

```plaintext
*** Exception *** input file names.data not found
```

and exit code should be 1.

**Sample Test Run #3**
If the file `names.data` contains more than 50 names, the console output should be:

```plaintext
*** Exception *** array capacity exceeded
```

and the exit code should be 1.

*Additional Notes:*
*names.data should not be modified*
*Regarding your code's standard output, COdeLab will check for case errors and will check whitespace (tabs, spaces, newlines) exactly except that it will ignore trailing whitepsace.*