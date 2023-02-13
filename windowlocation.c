Location *parse_url(char *url)
{
	/* Temporary buffer for storing the URL
    char buf[500];
    strcpy(buf, url);*/
    char *buf=url;

	// Split the URL into its individual components
	/*char *protocol = strtok(buf, "://");
    char *host = strtok(NULL, "/");
    char *pathname = strtok(NULL, "?");
    char *search = strtok(NULL, "#");
    char *hash = strtok(NULL, "\0");

	Create a new Location object and initialize its fields with the extracted values
    Location *l = (Location*) malloc(sizeof(Location));
    l->protocol = protocol;
    l->host = host;
    l->pathname = pathname;
    l->search = search;
    l->hash = hash;
    l->port = port;*/

	//different method
	/*int found_host = 0, found_protocol = 0, found_port = 0,
	found_pathname = 0, found_search = 0, found_hash = 0, temp, i;*/
    Location *l=realloc(NULL,sizeof(*l));
    l->protocol=calloc(100,sizeof(char));
    l->host=calloc(100,sizeof(char));
    l->pathname=calloc(100,sizeof(char));
    l->search=calloc(100,sizeof(char));
    l->hash=calloc(100,sizeof(char));
    l->port=0;

    int port_str = 0 , port_str2 = 1;
	
	// Check if there is a port number specified in the hostname
    /*char *port_str = strstr(host, ":");
    int port = 0;
    if (port_str)
    {
        // If there is a port number, extract it and convert it to an integer
        *port_str = '\0';
        port_str++;
        port = atoi(port_str);
    }*/

    while(*buf!=':')
	{
        l->protocol[port_str] =* buf;
        port_str++;
        *buf++;
    }

    l->protocol[port_str+1] = '\0';

    buf += 3;

    for(port_str = 0;*buf != '\0' && *buf != '\n';buf++)
	{
        if(port_str2 == 1)
		{
            if(*buf == ':')
			{
				l->host[port_str] = '\0';
				port_str = 0;
				port_str2 = 2;
			}
			else if(*buf == '/')
			{
				l->host[port_str] = '\0';
				port_str = 0;
				port_str2 = 3;
			}
			else if(*buf == '?')
			{
				l->pathname[port_str] = '\0';
				port_str = 0;
			    port_str2 = 4;
		    }
			else if(*buf == '#')
			{
			    l->pathname[port_str] = '\0';
			    port_str = 0;
			    port_str2 = 5;
		    }
			else
			{
			    l->host[port_str] = *buf;
			    port_str++;
		    }
        }
		else if(port_str2 == 2)
		{
            if(*buf == '/')
			{
				port_str2 = 3;
			}
			else if(*buf == '?')
			{
			    port_str2 = 4;
		    }
			else if(*buf == '#')
			{
			    port_str2 = 5;
		    }
			else
			{
	    		l->port *= 10;
	    		l->port += (*buf-'0');
		   	}
        }
		else if(port_str2 == 3)
		{
            if(*buf == '?')
			{
			    l->pathname[port_str] = '\0';
			   	port_str = 0;
	    		port_str2 = 4;
		    }
			else if(*buf == '#')
			{
			 	l->pathname[port_str] = '\0';
			  	port_str = 0;
			  	port_str2 = 5;
			}
			else
			{
		    	l->pathname[port_str] = *buf;
	        	port_str++;
		    }
        }
		else if(port_str2 == 4)
		{
            if(*buf=='#')
			{
			    l->search[port_str] = '\0';
			    port_str = 0;
			    port_str2 = 5;
			}
			else
			{
				l->search[port_str] =* buf;
			   	port_str++;
		    }
        }
		else
		{
            if(*buf == '?')
			{
			    l->hash[port_str] = '\0';
			    port_str = 0;
			    port_str2 = 4;
			}
			else
			{
			    l->hash[port_str] =* buf;
				port_str++;
		    }
        }
    }
    return l;
}