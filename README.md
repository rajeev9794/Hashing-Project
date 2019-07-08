# Hashing-Project
Input: CSV containing student records in the format

Registration,roll_no,name,remarks

Methodology:

1) Parse the input file to form records.
The components of the record will be:

a. Name (First Name, Last Name- Omit middle names)

b. Department

c. Year of Admission

d. Registration Number

e. Roll Number

f. Semester ( Year of Admission , Current Year)

From the records,

2) Create a hashtable that will store the record components of each student
alphabetically based on his/her first name.

3) Create a hashtable that will store the record components of each student
alphabetically based on his/her last name.

● The size of the hash table = The number of english alphabets=26.

● The key value will be the ASCII value of first / last name initial alphabet (e.g. for Subrata,
Key value: ASCII(S): 83)

● The hash function is given as Modulo 26.

Output: The distribution of the created hash tables
