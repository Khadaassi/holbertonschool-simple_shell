![image](https://camo.githubusercontent.com/53e388ccefde9c9b8cf54cac98852e1000a2b2a861a10fe8c755ffe1ffe0fd64/68747470733a2f2f6170706c792e686f6c626572746f6e7363686f6f6c2e636f6d2f686f6c626572746f6e2d6c6f676f2e706e67)

# Simple Shell

### Introduction
This repository is a [Holberton School](https://www.holbertonschool.com/) Project. The school project consisted in writing a shell like sh (Bourne Shell) by Stephen Bourne  , in **C**, using a limited number of standard library functions.

The goal in this project was to make us understand how a shell works. To single out some items: what is the *environment*, the difference between *functions* and *system calls*, how to create *processes* using `execve`...  

## Usage 
In order to run this program, 

Clone This Repo

`` git clone https://github.com/Khadaassi/holbertonschool-simple_shell ``

compile it with  

`gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`.  
You can then run it by typing `./hsh` in that same directory.  

### How to use it
In order to use this shell, in a terminal, first run the program:    
`prompt$ ./hsh`  
It wil then display a simple prompt and wait for commands.  
`$ `   
A command will be of the type `$ command`  
This shell can handle two types of commands: builtins and normal program.
##### List of built-ins

Switch to the specified directory (path).
* env  
Displays the environment variable
* exit [exitstatus]  
Exit from the program with exitstatus value. 0 by default.  
##### Command
Basicly Every Program in `$PATH`
It Support Single Word like `ls` 

It Handle Path `ls /tmp`

it Handle Options Like `ls -l`

it Handle All Three Togther Like `ls -l /var `

it Handle Command Path Also Like `/bin/ls` And All The Option And Path Like `/bin/ls -l /var`

it Handle Comments **#** 
## Examples Command
**Example 1**
```
Username@your-regular-prompt:~$ ./hsh
$ pwd
/home/username/
$ exit
Username@your-regular-prompt:~$
```
**Example 2**
```
Username@your-regular-prompt:~$ ./hsh
$ ls -l /tmp 
total 60
drwxr-xr-x 2 root   root    4096 Dec  8 04:31 build-features-src
drwxr-xr-x 1 root   root    4096 Dec  8 04:31 dev-container-features
drwxr-xr-x 2 vscode vscode  4096 Dec 22 08:36 devcontainers-af4a5850-be4f-4b35-a05e-60442e0adab71703234170191
srwxr-xr-x 1 vscode vscode     0 Dec 22 08:52 git-graph-askpass-IbIv3BCvJRRyIIZFQxEfDaihrb1aUOqI.sock
srwxr-xr-x 1 vscode vscode     0 Dec 22 08:36 vscode-git-ae6383ccd7.sock
srwxr-xr-x 1 vscode vscode     0 Dec 22 09:32 vscode-ipc-0b2ff3ca-fe4d-495c-bbe3-05487e99f5dd.sock
srwxr-xr-x 1 vscode vscode     0 Dec 22 08:36 vscode-ipc-1c2d5719-35a0-4f13-bbdd-c16e96019e1f.sock
srwxr-xr-x 1 vscode vscode     0 Dec 22 09:34 vscode-ipc-b3ebef13-b23d-492e-a7b0-e38601b488ce.sock
srwxr-xr-x 1 vscode vscode     0 Dec 22 08:36 vscode-ipc-c1ad2bb3-dc88-4462-967a-293068cfd376.sock
-rw-r--r-- 1 vscode vscode  2071 Dec 22 08:36 vscode-remote-containers-be8bcfda-2464-4bf3-8e93-684e9a58b35d.js
srwxr-xr-x 1 vscode vscode     0 Dec 22 08:36 vscode-remote-containers-ipc-be8bcfda-2464-4bf3-8e93-684e9a58b35d.sock
-rw-r--r-- 1 vscode vscode 42296 Dec 22 08:36 vscode-remote-containers-server-be8bcfda-2464-4bf3-8e93-684e9a58b35d.js
srwxr-xr-x 1 vscode vscode     0 Dec 22 08:36 vscode-ssh-auth-be8bcfda-2464-4bf3-8e93-684e9a58b35d.sock
$ exit
Username@your-regular-prompt:~$
```
### Exemples Builtin

**case env and exit**
```
Username@your-regular-prompt:~$ ./hsh
SHELL=/bin/bash
COLORTERM=truecolor
TERM_PROGRAM_VERSION=1.85.1
HOSTNAME=b387a11db55c
SSH_AUTH_SOCK=/tmp/vscode-ssh-auth-be8bcfda-2464-4bf3-8e93-684e9a58b35d.sock
REMOTE_CONTAINERS_IPC=/tmp/vscode-remote-containers-ipc-be8bcfda-2464-4bf3-8e93-684e9a58b35d.sock
PWD=/workspaces/holbertonschool-simple_shell
VSCODE_GIT_ASKPASS_NODE=/vscode/vscode-server/bin/linux-x64/0ee08df0cf4527e40edc9aa28f4b5bd38bbff2b2/node
HOME=/home/vscode
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
REMOTE_CONTAINERS=true
GIT_ASKPASS=/vscode/vscode-server/bin/linux-x64/0ee08df0cf4527e40edc9aa28f4b5bd38bbff2b2/extensions/git/dist/askpass.sh
VSCODE_GIT_ASKPASS_EXTRA_ARGS=
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
REMOTE_CONTAINERS_SOCKETS=["/tmp/vscode-ssh-auth-be8bcfda-2464-4bf3-8e93-684e9a58b35d.sock"]
LESSOPEN=| /usr/bin/lesspipe %s
USER=vscode
VSCODE_GIT_IPC_HANDLE=/tmp/vscode-git-ae6383ccd7.sock
SHLVL=2
GIT_EDITOR=code --wait
PROMPT_DIRTRIM=4
VSCODE_GIT_ASKPASS_MAIN=/vscode/vscode-server/bin/linux-x64/0ee08df0cf4527e40edc9aa28f4b5bd38bbff2b2/extensions/git/dist/askpass-main.js
BROWSER=/vscode/vscode-server/bin/linux-x64/0ee08df0cf4527e40edc9aa28f4b5bd38bbff2b2/bin/helpers/browser.sh
PATH=/vscode/vscode-server/bin/linux-x64/0ee08df0cf4527e40edc9aa28f4b5bd38bbff2b2/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/home/vscode/.local/bin
TERM_PROGRAM=vscode
VSCODE_IPC_HOOK_CLI=/tmp/vscode-ipc-b3ebef13-b23d-492e-a7b0-e38601b488ce.sock
$ exit
Username@your-regular-prompt:~$ 

```
### List of functions and system calls we could use
List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    fork (man 2 fork)
    free (man 3 free)
    fstat (man 2 fstat)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    kill (man 2 kill)
    lstat (man 2 lstat)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (man 2 stat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
    _exit (man 2 _exit)

For More Info About It Check The Man Page by
```
Username@your-regular-prompt:~$ man ./man_1_simple_shell
```
Project Done in 12 Days

## Authors
* Khadija Aassi [Khadaassi](https://github.com/Khadaassi)
* Nathan Vertueux [Nathan9722](https://github.com/Nathan9722)
