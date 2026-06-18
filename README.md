# C GPA Calculator

A GPA calculator utility written in C as part of my C learning journey.
It allows you to compute your semester GPA from manually entered courses,
prints a formatted result to the terminal, and optionally saves it to a file.

## Features

- Dynamic course entry — enter as many courses as you have (1–12)
- Input validation:
- Rejects non-numeric input for course count and units
- Enforces valid unit range (0–5)
- Enforces 6-character course code format (e.g. MTH102)
- Accepts both uppercase and lowercase grades, normalized automatically
- Flags invalid grades without crashing
- GPA calculation using the 5-point grading scale
- Class of degree classification using real Nigerian university bands:
- First Class (4.50 – 5.00)
- Second Class Upper (3.50 – 4.49)
- Second Class Lower (2.40 – 3.49)
- Third Class (1.50 – 2.39)
- Pass (1.00 – 1.49)
- Optional export of full results table to `output.txt`

## How to Compile and Run

```bash
clang main.c course.c classification.c -o program
./program
```

## File Structure

```bash
main.c              → Program entry point, user input, and output
course.h / course.c → Course struct definition and GPA calculation logic
classification.h / classification.c → Class of degree logic
```

## Author
Emmanuel Oramulu — [@EMMANUEL ORAMULU ](https://x.com/Meet_OEO)
Written @OEO Labs | All rights reserved.