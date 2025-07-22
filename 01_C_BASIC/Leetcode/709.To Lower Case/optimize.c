char* toLowerCaseBitwise(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            s[i] |= 0x20;  // 0x20 = 32 = 0010 0000 (binary)
        }
    }
    return s;
}