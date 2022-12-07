char str[MAX_LEN + 1], recover[MAX_LEN + 1];
    char *token;
    strcpy(str, homework);

    token = strtok(str, " \n");
    while (token != NULL) {
        int cat = 0;
        unsigned long len = strlen(token);

        if (len < 1 || len > 21)   
            cat = 1;

        for (int i = 0; i < len - 1; i++) { 
            if (isalpha(token[i]) == 0) {
                cat = 1;
                break;
            }
        }
        int end = token[len - 1];
        if (!(end == '.' || end == ',' || end == '!' || end == '?' || isalpha(end)))  //檢查字彙結尾是否為規定的標點符號或字母
            cat = 1;

        if (cat == 0) 
        {   
            strcat(recover, token);
            strcat(recover, " ");
        }
        token = strtok(NULL, " \n");
    }