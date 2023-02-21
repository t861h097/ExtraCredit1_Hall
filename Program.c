
#include <stdio.h>

int programmers[5][5] = {{3,1,2,4,5}, {4,3,1,5,2}, {2,5,4,1,3}, {4,5,2,1,3}, {3,2,1,5,4}};
int departments[5][5] = {{1,5,3,2,4}, {1,3,4,2,5}, {3,4,2,5,1}, {3,1,2,4,5}, {4,3,1,2,5}};
int department_match[5];

int duplicate_check(int programmer, int department_one, int department_two) {
    int department_one_preference, department_two_preference;
    for (int i = 0; i < 5; i++) {
        if (programmers[programmer - 1][i] == department_one + 1) {
            department_one_preference = i;
        } else if (programmers[programmer - 1][i] == department_two + 1) {
            department_two_preference = i;
        }
    }
    if (department_one_preference < department_two_preference) {
        department_match[department_one] = programmer;
    } else if (department_one_preference > department_two_preference) {
        department_match[department_two] = programmer;
    }
}

int programmer_available(int programmer) {
    int available = 1;
    for (int j = 0; j < 5; j++) {
        if (department_match[j] == programmer) {
            available = 0;
        }
    }
    return available;
}

int preference_check(int i) {
    for (int j = 0; j < 5; j++) {
        if (programmer_available(departments[j][i]) == 1) {
            int duplicate = 5;
            for (int k = 0; k < 5; k++) {
                if ((departments[j][i] == departments[k][i]) && (j != k)) {
                    duplicate = k;
                }
            }
            if ((duplicate == 5) && (department_match[j] == 0)) {
                department_match[j] = departments[j][i];
            } else {
                duplicate_check(departments[j][i], j, duplicate);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 5; i++) {
        preference_check(i);
    }
    for (int j = 0; j < 5; j++) {
        printf("Department #%d will get Programmer #%d\n", j + 1, department_match[j]);
    }
}
