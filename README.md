[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/7nq6K2Kr)
# GPA and CGPA Calculator

## Course
Computing II

## Assignment Type
Individual Assignment

## Topic
Variables, constants, operators, expressions, selection statements (`if`, `if...else`, `switch`)

---

## Background
Kyambogo university uses **Grade Point Average (GPA)** to measure a student’s academic performance in a semester and **Cumulative Grade Point Average (CGPA)** to measure performance across semesters.

In this assignment, you will write **one C program** that calculates:

- Semester I GPA  
- Semester II GPA  
- Overall Year One CGPA  
- Final academic classification  

using the actual Year One TEMB course structure and **credit units** given below.

---

## Course Structure

### Year One, Semester I

| Course Code | Course Name | Credit Units |
|---|---|---:|
| TEMB 1101 | Fundamentals of Engineering Mathematics | 4 |
| TEMB 1102 | Biochemistry and Medical Physics | 3 |
| TEMB 1103 | Electrical Engineering Science | 3 |
| TEMB 1104 | Mechanics I | 3 |
| TEMB 1105 | Computing I | 3 |
| TEMB 1106 | Mechanical Drawing | 3 |
| TEMB 1107 | Engineering Profession | 2 |
| TEMB 1108 | Functional Anatomy and Physiology I | 3 |

### Year One, Semester II

| Course Code | Course Name | Credit Units |
|---|---|---:|
| TEMB 1201 | Further Engineering Mathematics | 4 |
| TEMB 1202 | Computing II | 3 |
| TEMB 1203 | Mechatronics Drawing | 3 |
| TEMB 1204 | Fluid Mechanics | 3 |
| TEMB 1205 | Thermodynamics | 3 |
| TEMB 1206 | Workshop Practice | 3 |
| TEMB 1207 | Functional Anatomy and Physiology II | 3 |
| TEMB 1208 | Electronics I | 3 |

---

## Grading Scale

| Score Range | Grade | Grade Point |
|---|---|---:|
| 80–100 | A | 5 |
| 70–79 | B | 4 |
| 60–69 | C | 3 |
| 50–59 | D | 2 |
| 0–49 | F | 0 |

---

## Classification

| CGPA Range | Classification |
|---|---|
| 4.40 – 5.00 | First Class |
| 3.60 – 4.39 | Second Class Upper |
| 2.80 – 3.59 | Second Class Lower |
| 2.00 – 2.79 | Pass |
| Below 2.00 | Fail |

---

## Your Task

Write **one C program** in `main.c` that:

1. Accepts the score for each of the 8 courses in Semester I  
2. Accepts the score for each of the 8 courses in Semester II  
3. Determines the **grade** and **grade point** for each course  
4. Calculates:
   - Semester I GPA  
   - Semester II GPA  
   - Overall CGPA for Year One  
5. Displays a **full academic report**  
6. Displays the final academic classification  

> You are expected to determine the correct method for calculating GPA and CGPA using the course scores, grade points, and credit units.

---

## Student Identification (Required)

At the very top of your `main.c` file, you must include your:

- Full Name  
- Registration Number  

as comments.

### Example

```c
/*
Name: John Doe
Registration Number: 23/U/12345
*/
```

Programs without this information may lose marks.

---

## Input Format

Your program should read **16 scores** in this exact order:

### Semester I
1. TEMB 1101  
2. TEMB 1102  
3. TEMB 1103  
4. TEMB 1104  
5. TEMB 1105  
6. TEMB 1106  
7. TEMB 1107  
8. TEMB 1108  

### Semester II
9. TEMB 1201  
10. TEMB 1202  
11. TEMB 1203  
12. TEMB 1204  
13. TEMB 1205  
14. TEMB 1206  
15. TEMB 1207  
16. TEMB 1208  

You may display prompts, but your program must still correctly read all inputs.

---

## Output Format

Your program should display a **full academic report**.

The report should include, for each course:

- Course code  
- Score  
- Grade  
- Grade point  
- Credit unit  
- Weighted contribution  

It must also clearly display:

- Semester I GPA  
- Semester II GPA  
- CGPA  
- Classification  

### Required Summary Output

Your output **must include these lines exactly**:

```text
Semester I GPA: XX.XX
Semester II GPA: XX.XX
CGPA: XX.XX
Classification: XXXXX
```

These labels must appear exactly as written for autograding.

---

## Invalid Input Rule

If any score entered is outside the range **0–100**, print:

```text
Invalid score entered
```

and terminate the program.

---

## Technical Requirements

- Use **one file**: `main.c`  
- Use selection statements of your choice (e.g.`if...else`, `switch`, etc) 
- Display GPA and CGPA to **2 decimal places**  
- Code must compile with:

```bash
gcc main.c -o main
```

---

## Submission Files

Your repository must contain:

- `main.c`

---

## Mark Allocation

| Item | Marks |
|---|---:|
| Student identification present | 10 |
| Program compiles | 10 |
| Invalid input handling | 10 |
| Correct results for test cases | 70 |
| **Total** | **100** |

---

## Important Note

For autograding to work correctly, your output must include these labels exactly:

- `Semester I GPA:`  
- `Semester II GPA:`  
- `CGPA:`  
- `Classification:`  
