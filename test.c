#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}
Location *parse_url(char *url)
{
    Location *a;
    a->protocol = "";
    a->host = "";
    a->pathname = "";
    a->search = "";
    a->hash = "";
    a->port = 0;
    int found_host = 0, found_protocol = 0, found_port = 0, found_pathname = 0, found_search = 0, found_hash = 0, temp, i;
    temp = 0;
    char test[100];
    printf("%lu\n", strlen(url));
    for (i = 0; i < strlen(url); i++)
    {
        printf("%d %d %c\n", temp, i, url[i]);
        if (url[i + 1] == '/' && url[i + 2] == '/' && url[i] == ':' && found_protocol == 0)
        {
            found_protocol = 1;
            i += 3;
            temp = 0;
            a->protocol = "test";
        }
        // else if ((url[i] == '/' || url[i] == ':') && found_host == 0)
        // {
        //     found_host = 1;
        //     i++;
        //     temp = 0;
        // }

        if (found_protocol == 0)
        {
            test[temp] = url[i];
            temp++;
        }
        // else if (found_host == 0)
        // {
        //     printf("test%d %d %ctest\n", temp, i, url[i]);
        //     a->host[temp] = url[i];
        //     temp++;
        //     printf("test%d %d %ctest\n", temp, i, url[i]);
        // }
    }
    // for (int i = 0; i < strlen(url); i++)
    // {
    //     printf("%c", a->protocol[i]);
    // }
     printf("\n");
    return a;
}