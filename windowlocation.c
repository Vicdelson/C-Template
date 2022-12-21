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
    // Temporary buffer for storing the URL
    char buf[500];
    strcpy(buf, url);

    // Split the URL into its individual components
    char *protocol = strtok(buf, "://");
    char *host = strtok(NULL, "/");
    char *pathname = strtok(NULL, "?");
    char *search = strtok(NULL, "#");
    char *hash = strtok(NULL, "\0");

    // Check if there is a port number specified in the hostname
    char *port_str = strstr(host, ":");
    int port = 0;
    if (port_str)
    {
        // If there is a port number, extract it and convert it to an integer
        *port_str = '\0';
        port_str++;
        port = atoi(port_str);
    }

    // Create a new Location object and initialize its fields with the extracted values
    Location *l = (Location*) malloc(sizeof(Location));
    l->protocol = protocol;
    l->host = host;
    l->pathname = pathname;
    l->search = search;
    l->hash = hash;
    l->port = port;

    return l;
}