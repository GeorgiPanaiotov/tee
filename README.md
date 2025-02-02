# tee
tee clone for Linux from scratch\

Gets input from the terminal and outputs to the terminal and to a file.
## Basic usage
### `echo "Hello World" | teeClone helloworld.txt` will write Hello World to helloworld.txt and output it to the terminal.
Currently there is no -a (append) option so it always overwrites the file. If no file exists, one gets created
