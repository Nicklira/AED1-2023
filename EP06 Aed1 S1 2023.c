#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* determine_link_reaction(const char* name) {
    int i;
    int length = strlen(name);
    char lowercase_name[length + 1];
    strcpy(lowercase_name, name);

    // Convert the name to lowercase
    for (i = 0; i < length; i++) {
        lowercase_name[i] = tolower(lowercase_name[i]);
    }

    // Check if "zelda" is present in the name
    if (strstr(lowercase_name, "zelda") != NULL) {
        return "Link Bolado";
    } else {
        return "Link Tranquilo";
    }
}

int main() {
    char name[100000];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the trailing newline character

    const char* result = determine_link_reaction(name);
    printf("%s\n", result);

    return 0;
}
