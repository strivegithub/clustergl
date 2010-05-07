#include "main.h"

unsigned char *textFileRead(const char *filename) 
	{
		FILE *fp;
		unsigned char *content = NULL;

		int count=0;

		if (filename != NULL) {

			fp = fopen(filename,"rt");

			if (fp != NULL) {
										      
        	      		fseek(fp, 0, SEEK_END);
        			count = ftell(fp);
        			rewind(fp);

				if (count > 0) {
					content = (unsigned char *)malloc(sizeof(unsigned char) * (count+1));
					count = fread(content,sizeof(char),count,fp);
					content[count] = '\0';
				}
				fclose(fp);
										
			}
		}
	
		return content;
	}


int main(int argc, char *argv[])
{
/* read in the file into memory */
unsigned char * fileContents = textFileRead("171.png");

/* set up multicast server */
Server* s = new Server();

/* send the file */
s->send(fileContents, 5108195);

/* close the connection */

return 0;
}