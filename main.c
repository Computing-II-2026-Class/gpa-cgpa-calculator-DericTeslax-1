/*
Name: MUTYABA DERICK 
Registration Number: 25/U/BIE/01399/PE
*/

#include <stdio.h>

int main(void) {
    /* Declare variables here */
    const char *sem1_codes[] = {"TEMB1101","TEMB1102","TEMB1103","TEMB1104",
                                "TEMB1105","TEMB1106","TEMB1107","TEMB1108"};
    const int sem1_credits[] = {4,3,3,3,3,3,2,3};

    const char *sem2_codes[] = {"TEMB1201","TEMB1202","TEMB1203","TEMB1204",
                                "TEMB1205","TEMB1206","TEMB1207","TEMB1208"};
    const int sem2_credits[] = {4,3,3,3,3,3,3,3};

    int scores[16];
    int i;

    /* Read 16 scores (no prompts) */
    for (i = 0; i < 16; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            printf("Invalid score entered\n");
            return 1;
        }
    }

    /* Validate input range */
    for (i = 0; i < 16; i++) {
        if (scores[i] < 0 || scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
        }
    }

    /* Determine grades and grade points + Compute Semester I GPA */
    double sem1_weighted = 0.0;
    int sem1_total_credits = 0;

    printf("Course Code  Score  Grade  Grade Pt  Credit  Weighted\n");

    for (i = 0; i < 8; i++) {
        int score = scores[i];
        double gp;
        char grade;

        switch (score / 10) {
            case 10: case 9: case 8: gp = 5.0; grade = 'A'; break;
            case 7: gp = 4.0; grade = 'B'; break;
            case 6: gp = 3.0; grade = 'C'; break;
            case 5: gp = 2.0; grade = 'D'; break;
            default: gp = 0.0; grade = 'F'; break;
        }

        double weighted = gp * sem1_credits[i];
        sem1_weighted += weighted;
        sem1_total_credits += sem1_credits[i];

        printf("%-11s %5d     %c      %.1f      %2d      %6.1f\n",
               sem1_codes[i], score, grade, gp, sem1_credits[i], weighted);
    }

    double sem1_gpa = sem1_weighted / sem1_total_credits;
    printf("\nSemester I GPA: %.2f\n", sem1_gpa);

    /* Compute Semester II GPA */
    double sem2_weighted = 0.0;
    int sem2_total_credits = 0;

    printf("\nCourse Code  Score  Grade  Grade Pt  Credit  Weighted\n");

    for (i = 0; i < 8; i++) {
        int score = scores[8 + i];
        double gp;
        char grade;

        switch (score / 10) {
            case 10: case 9: case 8: gp = 5.0; grade = 'A'; break;
            case 7: gp = 4.0; grade = 'B'; break;
            case 6: gp = 3.0; grade = 'C'; break;
            case 5: gp = 2.0; grade = 'D'; break;
            default: gp = 0.0; grade = 'F'; break;
        }

        double weighted = gp * sem2_credits[i];
        sem2_weighted += weighted;
        sem2_total_credits += sem2_credits[i];

        printf("%-11s %5d     %c      %.1f      %2d      %6.1f\n",
               sem2_codes[i], score, grade, gp, sem2_credits[i], weighted);
    }

    double sem2_gpa = sem2_weighted / sem2_total_credits;
    printf("\nSemester II GPA: %.2f\n", sem2_gpa);

    /* Compute CGPA */
    double cgpa = (sem1_weighted + sem2_weighted) / (sem1_total_credits + sem2_total_credits);
    printf("\nCGPA: %.2f\n", cgpa);

    /* Determine classification */
    if (cgpa >= 4.40) printf("Classification: First Class\n");
    else if (cgpa >= 3.60) printf("Classification: Second Class Upper\n");
    else if (cgpa >= 2.80) printf("Classification: Second Class Lower\n");
    else if (cgpa >= 2.00) printf("Classification: Pass\n");
    else printf("Classification: Fail\n");

    /* Display full academic report */

    return 0;
}
