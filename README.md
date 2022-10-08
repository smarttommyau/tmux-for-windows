# Tmux for windows using wsl support

# Pre-request
- WSL

# Setup WSL

Install a new distro, alpine is recommended.\
Follow the basic instruction on installing it.[Official guide](https://learn.microsoft.com/en-us/windows/wsl/install)\
Then install tmux.\
Alpine : apk update&&apk add tmux\
Debian/Ubuntu: apt install tmux

Add new file ~/.profile with this code to automatically run powershell in tmux sessions
```
if [ -n "$TMUX" ]; then
        pwsh.exe
fi
```
# Installation
## Download our program
[Download](https://github.com/smarttommyau/tmux-for-windows/releases/tag/Release)
## Setup our program
Add the path you download our program to environment path. [Article about this](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/)\
> ***!!!!*** Remember to restart the terminal after added to environment path.
## Setup config
Add or edit file ***tmux.conf*** with your favourite editor on the ***same folder of our program***.
```
distro: alpine //your distro name
```
> currently only one parms is required and used
# Enjoy
