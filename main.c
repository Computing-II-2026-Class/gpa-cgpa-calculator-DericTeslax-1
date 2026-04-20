/*
Name: MUTYABA DERICK 
Registration Number: 25/U/BIE/01399/PE
*/

#include <stdio.h>

int main(void) {

// Function to get grade and grade point
void getGradeAndPoint(float score, char *grade, int *point) {
    if (score >= 80 && score <= 100) {
        *grade = 'A';
        *point = 5;
    } else if (score >= 70 && score <= 79) {
        *grade = 'B';
        *point = 4;
    } else if (score >= 60 && score <= 69) {
        *grade = 'C';
        *point = 3;
    } else if (score >= 50 && score <= 59) {
        *grade = 'D';
        *point = 2;
    } else if (score >= 0 && score <= 49) {
        *grade = 'F';
        *point = 0;
    } else {
        *grade = 'X';  // Invalid
        *point = -1;
    }
}
    float scores[16];
    char grades[16];
    int points[16];
    int credits[16] = {4,3,3,3,3,3,2,3,   // Semester I
                       4,3,3,3,3,3,3,3};  // Semester II

    char *courseCodes[16] = {
        "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104",
        "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108",
        "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
        "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"
    };

    // Read 16 scores
    for (int i = 0; i < 16; i++) {
        if (scanf("%f", &scores[i]) != 1) {
            printf("Invalid score entered\n");
            return 0;
        }
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 0;
        }
    }

    // Calculate grades and points
    for (int i = 0; i < 16; i++) {
        getGradeAndPoint(scores[i], &grades[i], &points[i]);
    }

    // Calculate Semester I GPA
    float sem1_total = 0.0;
    int sem1_credits = 0;
    for (int i = 0; i < 8; i++) {
        sem1_total += points[i] * credits[i];
        sem1_credits += credits[i];
    }
    float gpa1 = sem1_total / sem1_credits;

    // Calculate Semester II GPA
    float sem2_total = 0.0;
    int sem2_credits = 0;
    for (int i = 8; i < 16; i++) {
        sem2_total += points[i] * credits[i];
        sem2_credits += credits[i];
    }
    float gpa2 = sem2_total / sem2_credits;

    // Calculate CGPA (Year One)
    float year_total = sem1_total + sem2_total;
    int total_credits = sem1_credits + sem2_credits;
    float cgpa = year_total / total_credits;

    // Print Full Academic Report
    printf("\n=== YEAR ONE ACADEMIC REPORT ===\n\n");

    printf("Semester I:\n");
    for (int i = 0; i < 8; i++) {
        float weighted = points[i] * credits[i];
        printf("%s | Score: %.0f | Grade: %c | GP: %d | Credits: %d | Weighted: %.2f\n",
               courseCodes[i], scores[i], grades[i], points[i], credits[i], weighted);
    }

    printf("\nSemester II:\n");
    for (int i = 8; i < 16; i++) {
        float weighted = points[i] * credits[i];
        printf("%s | Score: %.0f | Grade: %c | GP: %d | Credits: %d | Weighted: %.2f\n",
               courseCodes[i], scores[i], grades[i], points[i], credits[i], weighted);
    }

    // Print Summary (Exact format required for autograding)
    printf("\nSemester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);

    // Determine Classification
    char classification[30];
    if (cgpa >= 4.40 && cgpa <= 5.00)
        sprintf(classification, "First Class");
    else if (cgpa >= 3.60 && cgpa <= 4.39)
        sprintf(classification, "Second Class Upper");
    else if (cgpa >= 2.80 && cgpa <= 3.59)
        sprintf(classification, "Second Class Lower");
    else if (cgpa >= 2.00 && cgpa <= 2.79)
        sprintf(classification, "Pass");
    else
        sprintf(classification, "Fail");

    printf("Classification: %s\n", classification);
   
    return 0;
}
