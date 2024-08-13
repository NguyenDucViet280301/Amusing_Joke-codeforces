#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void count_characters(const char *str, int *count) {
    while (*str) {
        count[*str - 'A']++;
        str++;
    }
}

int main() {
    char guest[MAX_LENGTH + 1];
    char host[MAX_LENGTH + 1];
    char pile[MAX_LENGTH + 1];

    // Read input
    fgets(guest, sizeof(guest), stdin);
    fgets(host, sizeof(host), stdin);
    fgets(pile, sizeof(pile), stdin);

    // Remove newline characters if present
    guest[strcspn(guest, "\n")] = '\0';
    host[strcspn(host, "\n")] = '\0';
    pile[strcspn(pile, "\n")] = '\0';

    // Create arrays to count character occurrences
    int guest_host_count[26] = {0};
    int pile_count[26] = {0};

    // Count characters in guest and host names
    count_characters(guest, guest_host_count);
    count_characters(host, guest_host_count);

    // Count characters in pile
    count_characters(pile, pile_count);

    // Compare counts
    for (int i = 0; i < 26; i++) {
        if (guest_host_count[i] != pile_count[i]) {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
