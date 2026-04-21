/*
Name: MUTYABA DERICK 
Registration Number: 25/U/BIE/01399/PE
*/

#include <stdio.h>

int main(void) {
   /* Declare variables here */
    int scores[16];
    int credits_sem1[8] = {4, 3, 3, 3, 3, 3, 2, 3};
    int credits_sem2[8] = {4, 3, 3, 3, 3, 3, 3, 3};
    char *codes_sem1[8] = {"TEMB1101", "TEMB1102", "TEMB1103", "TEMB1104",
                           "TEMB1105", "TEMB1106", "TEMB1107", "TEMB1108"};
    char *codes_sem2[8] = {"TEMB1201", "TEMB1202", "TEMB1203", "TEMB1204",
                           "TEMB1205", "TEMB1206", "TEMB1207", "TEMB1208"};
    int grade_points[16];
    char grades[16];
    int weighted[16];
    int total_credits_sem1 = 0, total_credits_sem2 = 0;
    int total_weighted_sem1 = 0, total_weighted_sem2 = 0;
    float gpa_sem1, gpa_sem2, cgpa;
    int i, tens;
    
    /* Read 16 scores */
    printf("Enter scores for Semester I:\n");
    for (i = 0; i < 8; i++) {
        printf("%s: ", codes_sem1[i]);
        scanf("%d", &scores[i]);
    }
    printf("Enter scores for Semester II:\n");
    for (i = 8; i < 16; i++) {
        printf("%s: ", codes_sem2[i-8]);
        scanf("%d", &scores[i]);
    }
    
    /* Validate input */
    for (i = 0; i < 16; i++) {
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }
    
    /* Determine grades and grade points */
    for (i = 0; i < 16; i++) {
        tens = scores[i] / 10;
        switch (tens) {
            case 10:
            case 9:
            case 8:
                grade_points[i] = 5;
                grades[i] = 'A';
                break;
            case 7:
                grade_points[i] = 4;
                grades[i] = 'B';
                break;
            case 6:
                grade_points[i] = 3;
                grades[i] = 'C';
                break;
            case 5:
                grade_points[i] = 2;
                grades[i] = 'D';
                break;
            default:
                grade_points[i] = 0;
                grades[i] = 'F';
                break;
        }
    }
    
    /* Compute Semester I GPA */
    for (i = 0; i < 8; i++) {
        weighted[i] = grade_points[i] * credits_sem1[i];
        total_credits_sem1 += credits_sem1[i];
        total_weighted_sem1 += weighted[i];
    }
    gpa_sem1 = (float)total_weighted_sem1 / total_credits_sem1;
    
    /* Compute Semester II GPA */
    for (i = 8; i < 16; i++) {
        weighted[i] = grade_points[i] * credits_sem2[i-8];
        total_credits_sem2 += credits_sem2[i-8];
        total_weighted_sem2 += weighted[i];
    }
    gpa_sem2 = (float)total_weighted_sem2 / total_credits_sem2;
    
    /* Compute CGPA */
    cgpa = (float)(total_weighted_sem1 + total_weighted_sem2) / (total_credits_sem1 + total_credits_sem2);
    
    /* Determine classification */
    char *classification;
    if (cgpa >= 4.40)
        classification = "First Class";
    else if (cgpa >= 3.60)
        classification = "Second Class Upper";
    else if (cgpa >= 2.80)
        classification = "Second Class Lower";
    else if (cgpa >= 2.00)
        classification = "Pass";
    else
        classification = "Fail";
    
    /* Display full academic report */
    printf("\n==================================================\n");
    printf("               ACADEMIC REPORT\n");
    printf("==================================================\n\n");
    
    printf("SEMESTER I\n");
    printf("--------------------------------------------------\n");
    printf("%-12s %-6s %-5s %-10s %-5s %-10s\n", 
           "Course", "Score", "Grade", "Grade Point", "Credits", "Weighted");
    printf("--------------------------------------------------\n");
    for (i = 0; i < 8; i++) {
        printf("%-12s %-6d %-5c %-10d %-5d %-10d\n",
               codes_sem1[i], scores[i], grades[i], grade_points[i],
               credits_sem1[i], weighted[i]);
    }
    printf("--------------------------------------------------\n");
    printf("Semester I GPA: %.2f\n\n", gpa_sem1);
    
    printf("SEMESTER II\n");
    printf("--------------------------------------------------\n");
    printf("%-12s %-6s %-5s %-10s %-5s %-10s\n",
           "Course", "Score", "Grade", "Grade Point", "Credits", "Weighted");
    printf("--------------------------------------------------\n");
    for (i = 8; i < 16; i++) {
        printf("%-12s %-6d %-5c %-10d %-5d %-10d\n",
               codes_sem2[i-8], scores[i], grades[i], grade_points[i],
               credits_sem2[i-8], weighted[i]);
    }
    printf("--------------------------------------------------\n");
    printf("Semester II GPA: %.2f\n\n", gpa_sem2);
    
    printf("Semester I GPA: %.2f\n", gpa_sem1);
    printf("Semester II GPA: %.2f\n", gpa_sem2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);
   
    return 0;
}
