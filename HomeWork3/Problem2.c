#include <stdio.h>
#include <string.h>

struct command_t{
  char operation;
  int argument1;
  int argument2;
  int res;
};

int exec_cmd(struct command_t *cmd){
  char term;

  if(scanf("%d%c", &cmd->argument1, &term) != 2) {
    return -3;
  }else{
    scanf("%c", &cmd->operation);
    if (cmd->operation == '+' || cmd->operation == '-' || cmd->operation == '/'
      || cmd->operation == '*' || cmd->operation == '%') {
        if(scanf("%d%c", &cmd->argument2, &term) != 2) {
          return -3;
        }else{
          if (cmd->argument2 == 0 && cmd->operation == '/') {
            return -5;
          }
          return 0;
        }
    }else {
      return -1;
    }
  }
}

void exec_handler(int returnningnumber){
  switch(returnningnumber){

    case -1: printf("operation not supported");
    break;
    case -2: printf("invalid command argument count");
    break;
    case -3: printf("invalid command arguments");
    break;
    case -4: printf("invalid input");
    break;
    case -5: printf("invalid arithmetic operation");
    break;
    case 42: printf("the answer to life, the universe and everything else");
    break;

  }
}

int checkresult(int res){
  if(res == 42){
    exec_handler(42);
    return -1;
  }
  else
    return 0;
}

void execoperation(struct command_t *cmd){
  switch(cmd->operation){
    case '+':
      if(checkresult(cmd->res = cmd->argument1 + cmd->argument2) == 0){
        printf("%d\n", cmd->res);
      }
    break;
    case '-':
    if(checkresult(cmd->res = cmd->argument1 - cmd->argument2) == 0){
      printf("%d\n", cmd->res);
    }
    break;
    case '*':
    if(checkresult(cmd->res = cmd->argument1 * cmd->argument2) == 0){
      printf("%d\n", cmd->res);
    }
    break;
    case '/':
    if(checkresult(cmd->res = cmd->argument1 / cmd->argument2) == 0){
      printf("%d\n", cmd->res);
    }
    break;
    case '!':
      printf("%d\n", ! cmd->argument1);
    break;
    case '%':
    if(checkresult(cmd->res = cmd->argument1 % cmd->argument2) == 0){
      printf("%d\n", cmd->res);
    }
    break;
  }
}

int main(){
    struct command_t command;
    int returningvalue = exec_cmd(&command);
    if (returningvalue == 0) {
      execoperation(&command);
    }else{
      exec_handler(returningvalue);
    }

  return 0;
}
