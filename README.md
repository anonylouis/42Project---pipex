# 42Project---pipex

## Utilisation

The goal of this project is to reproduce how the shell execute a simple command line.

- ```./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile```  
should have the same comportment as  
```< infile cmd1 | cmd 2 | cmd3 | ... | cmdn > outfile```

- If "here_doc" is the first parameter then  
```./pipex here_doc LIMITER cmd1 cmd2 cmd3 ... cmdn outfile```  
should have the same comportment as  
```<< LIMITER cmd1 | cmd 2 | cmd3 | ... | cmdn >> outfile```

[*en.subject.pdf*](https://github.com/anonylouis/42Project---pipex/blob/main/en.subject.pdf) is the original subject of the project from 42 Paris.

## Example

Some tricky commands you can try :
- `< /dev/stdin cat | cat | ls > /dev/stdout`
- `< /dev/stdin sleep 2 | sleep 2 > /dev/stdout`
- `< /dev/urandom cat | head -5 > /dev/stdout`
- `< Makefile cat | wc -c -l -w > /dev/stdout`
