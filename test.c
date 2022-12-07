//Check if back is punctuated or not
    if(length < 1 || length > 21)
    {
            cat = false;
        }
        if((token[length - 1] == '.' || token[length - 1] == ',' || token[length - 1] == '!' || token[length - 1] == '?') && length > 1)
        {
            cat = true;
        } else if(!isalpha(token[length-1]))
        { //If not Check if last is any non-alphabetic char
            cat = false;
        } else if((token[length - 1] == '.' || token[length - 1] == ',' || token[length - 1] == '!' || token[length - 1] == '?') && length == 1)
        {
            cat = false;
        }