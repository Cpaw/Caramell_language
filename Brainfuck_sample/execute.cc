#include <stdio.h>
#include <vector>
#define MEMSIZE 30000
#define pb push_back

#define GT '>'
#define LT '<'
#define PLUS '+'
#define MINUS '-'
#define COMMA ','
#define DOT '.'
#define LBRACKET '['
#define RBRACKET ']'
  
int usage();
void memory_dump(int* m);

int main(int argc, char** argv){

  int i;
  int c;
  int parens;
  FILE *fp;
  int memory[MEMSIZE] = {0};
  int* mptr = memory;
  std::vector<int> vcode;
  
  if(argc != 2)
    return usage();

  if((fp = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Cannot open %s", argv[1]);
    return -1;
  }

  while((c = fgetc(fp)) != EOF)
    vcode.pb(c);
  
  for(int i = 0; i < vcode.size(); i++) {
    
    switch (vcode[i]) {
      
    case GT:
      mptr++;
      break;
      
    case LT:
      mptr--;
      break;

    case PLUS:
      (*mptr)++;
      break;
      
    case MINUS:
      (*mptr)--;
      break;
      
    case DOT:
      putchar(*mptr);
      break;
      
    case COMMA:
      *mptr = getchar();
      break;
      
    case LBRACKET:
      if(!*mptr) {
	i++;
	for(; parens != 0 || vcode[i] != RBRACKET; i++) {
	  if(vcode[i] == LBRACKET)
	    parens++;
	  if(vcode[i] == RBRACKET)
	    parens--;
	}
      }
      break;
      
    case RBRACKET:
      
      if(*mptr) {
	i--;
	for(; parens != 0 || vcode[i] != LBRACKET; i--) {
	  if(vcode[i] == RBRACKET)
	    parens++;
	  if(vcode[i] == LBRACKET)
	    parens--;
	}
	i--;
      }
      break;
      
    default:
      break;
    }
  }
  
  fclose(fp);
  return 0;
}

int usage() {
  fprintf(stderr, "Usage: cpaw <source file>\n");
  return -1;
}

void memory_dump(int* m) {
  printf("\ndump memory\n");
  while(*m) {
    printf("[%d]", *m);
    ++m;
  }
}
