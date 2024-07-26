#include <stdio.h>

int pref[20][20];
int assigned[20];
int n;

int isAssigned(int topic) {
    for (int i = 0; i < n; i++) {
        if (assigned[i] == topic) {
            return 1;
        }
    }
    return 0;
}

int assignTopics(int student) {
    if (student == n) {
        return 1;
    }
    int count = 0;
    for (int topic = 0; topic < n; topic++) {
        if (pref[student][topic] == 1 && !isAssigned(topic)) {
            assigned[student] = topic;
            count += assignTopics(student + 1);
            assigned[student] = -1;
        }
    }
    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &pref[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            assigned[i] = -1;
        }
        printf("%d\n", assignTopics(0));
    }
    return 0;
}
