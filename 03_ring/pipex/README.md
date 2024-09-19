[**Results in this milestone**](https://github.com/zikocult/Cursus42/tree/main/03_ring)

This project will let me discover in detail a UNIX mechanism that I already know by using it in my program.

I'm currently working in the bonus part, I will avoid this part until I finished it.

The project will be executed as:

```bash
./pipex file1 cmd1 cmd2 file2
```

For this the program need 4 arguments:

- File1 and File2 are **file names**.
- Cmd1 and Cmd2 are **shell commands** whith their parameters.

It must behave exactlly the same as the shell command below:

``` bash
$> < file1 cmd1 | cmd2 > file2
```

